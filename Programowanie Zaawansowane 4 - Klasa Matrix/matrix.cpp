#include "matrix.h"
#include <cstdlib>
#include <ctime>
#include <cmath> 

using namespace std;

// ================== Konstruktory i destruktor ==================

matrix::matrix(void) : n(0), data(nullptr) {}
// konstruktor domyslny – brak pamieci, rozmiar 0

matrix::matrix(int n) : n(n), data(make_unique<int[]>(n* n)) {
    // konstruktor z rozmiarem n – alokujemy tablice n*n
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0; // ustawiamy wszystkie elementy na 0
    }
}

matrix::matrix(int n, int* t) : n(n), data(make_unique<int[]>(n* n)) {
    // konstruktor z rozmiarem i tablica t – kopiujemy wartosci z t
    for (int i = 0; i < n * n; i++)
    {
        data[i] = t[i];
    }
}

matrix::matrix(const matrix& m) : n(m.n), data(make_unique<int[]>(m.n* m.n)) {
    // konstruktor kopiujacy – przepisujemy rozmiar i wszystkie elementy
    for (int i = 0; i < n * n; i++)
    {
        data[i] = m.data[i];
    }
}

matrix::~matrix(void) = default;
// destruktor – nic nie robimy recznie, unique_ptr sam zwolni pamiec


// ================== Podstawowe metody ==================

matrix& matrix::alokuj(int n) {
    if (!data) {
        // pierwsza alokacja
        data = make_unique<int[]>(n * n);
    }
    else if (n > this->n) {
        // trzeba wiêcej pamiêci – realokujemy
        data = make_unique<int[]>(n * n);
    }
    // jeœli n <= this->n – nie robimy nic z data, tylko zmieniamy rozmiar logiczny
    this->n = n;
    return *this;
}



matrix& matrix::wstaw(int x, int y, int wartosc) {
    // sprawdzamy, czy (x, y) miesci sie w macierzy
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        // zapis do komorki (x, y)
        data[x * n + y] = wartosc;
    }
    else {
        cout << "Blad - nie ma takiej pozycji w macierzy";
    }

    return *this;
}

int matrix::pokaz(int x, int y) {
    // sprawdzamy, czy (x, y) miesci sie w macierzy
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        // odczyt z komorki (x, y)
        return data[x * n + y];
    }
    else {
        cout << "Blad - nie ma takiej pozycji w macierzy";
        return 0; // zwracamy 0 jako wartosc domyslna przy bledzie
    }
}

matrix& matrix::odwroc(void) {
    // transpozycja macierzy – zamiana elementow (i, j) z (j, i)
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) {
            swap(data[i * n + j], data[j * n + i]);
        }
    }
    return *this;
}


// ================== Losowanie ==================

matrix& matrix::losuj(void) {
    // inicjalizujemy generator liczb losowych
    srand(static_cast<unsigned>(time(nullptr)));

    // ustawiamy wszystkie elementy na losowe liczby 0–9
    for (int i = 0; i < n * n; i++)
    {
        data[i] = rand() % 10;
    }
    return *this;
}

matrix& matrix::losuj(int x) {
    // inicjalizujemy generator liczb losowych
    srand(static_cast<unsigned>(time(nullptr)));

    // losujemy x pozycji w macierzy i wpisujemy tam losowe liczby 0–9
    for (int i = 0; i < x; i++)
    {
        int row = rand() % n;   // losowy wiersz
        int col = rand() % n;   // losowa kolumna
        data[row * n + col] = rand() % 10;
    }
    return *this;
}


// ================== Specjalne uklady (diagonalne, kolumny, wiersze) ==================

matrix& matrix::diagonalna(int* t) {
    // najpierw zerujemy cala macierz
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }
    // potem wpisujemy wartosci z t na glownej przekatnej
    for (int i = 0; i < n; i++)
    {
        data[i * n + i] = t[i];
    }
    return *this;
}

matrix& matrix::diagonalna_k(int k, int* t) {
    // najpierw zerujemy cala macierz
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }

    if (k >= 0) {
        // przekatna przesunieta w gore o k
        for (int i = 0; i < n - k; i++)
        {
            data[i * n + (i + k)] = t[i];
        }
    }
    else {
        // k < 0 – przekatna przesunieta w dol (np. k = -1)
        for (int i = 0; i < n + k; i++)
        {
            // (i - k) przesuwa wiersz w dol
            data[(i - k) * n + i] = t[i];
        }
    }
    return *this;
}

matrix& matrix::kolumna(int x, int* t) {
    // wpisujemy do kolumny x wartosci z tablicy t
    for (int i = 0; i < n; i++)
    {
        data[i * n + x] = t[i];
    }
    return *this;
}

matrix& matrix::wiersz(int x, int* t) {
    // wpisujemy do wiersza x wartosci z tablicy t
    for (int i = 0; i < n; i++)
    {
        data[x * n + i] = t[i];
    }
    return *this;
}

matrix& matrix::przekatna(void) {
    // zerujemy cala macierz
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }
    // na glownej przekatnej wpisujemy 1
    for (int i = 0; i < n; i++)
    {
        data[i * n + i] = 1;
    }
    return *this;
}

matrix& matrix::pod_przekatna(void) {
    // zerujemy cala macierz
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }
    // wpisujemy 1 pod przekatna (i > j)
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            data[i * n + j] = 1;
        }
    }
    return *this;
}

matrix& matrix::nad_przekatna(void) {
    // zerujemy cala macierz
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }
    // wpisujemy 1 nad przekatna (i < j)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            data[i * n + j] = 1;
        }
    }
    return *this;
}

matrix& matrix::szachownica(void) {
    // wypelniamy macierz wzorem 0 / 1 jak szachownica
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i + j) % 2 == 0)
                data[i * n + j] = 0;
            else
                data[i * n + j] = 1;
        }
    }
    return *this;
}


// ================== Operatory macierz–macierz ==================

matrix& matrix::operator+(matrix& m)
{
    // dodawanie macierzy element po elemencie: this += m
    if (n != m.n) {
        std::cerr << "Blad: rozne rozmiary macierzy w operator+ (matrix, matrix)\n";
        return *this;
    }

    for (int i = 0; i < n * n; ++i) {
        data[i] += m.data[i];
    }

    return *this;
}

matrix& matrix::operator*(matrix& m)
{
    // mnozenie macierzy this * m (standardowy algorytm O(n^3))
    if (n != m.n) {
        std::cerr << "Blad: rozne rozmiary macierzy w operator* (matrix, matrix)\n";
        return *this;
    }

    // tablica na wynik mnozenia
    std::unique_ptr<int[]> result = std::make_unique<int[]>(n * n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += data[i * n + k] * m.data[k * n + j];
            }
            result[i * n + j] = sum;
        }
    }

    // podmieniamy stara tablice na nowy wynik
    data.swap(result);

    return *this;
}


// ================== Operatory macierz–int (po prawej) ==================

matrix matrix::operator+(int a) const
{
    matrix result(*this);  // kopia aktualnej macierzy
    result += a;           // korzystamy z operatora +=
    return result;         // zwracamy nowa macierz
}

matrix matrix::operator-(int a) const
{
    matrix result(*this);  // kopia
    result -= a;           // kazdy element -= a
    return result;
}

matrix matrix::operator*(int a) const
{
    matrix result(*this);  // kopia
    result *= a;           // kazdy element *= a
    return result;
}


// ================== Operatory int–macierz (po lewej) ==================

matrix operator+(int a, const matrix& m)
{
    // korzystamy z juz zdefiniowanego operatora m + a
    return m + a;
}

matrix operator*(int a, const matrix& m)
{
    // mnozenie jest przemienne: a * A = A * a
    return m * a;
}

matrix operator-(int a, const matrix& m)
{
    // tworzymy kopie macierzy i robimy (a - element)
    matrix result(m);

    for (int i = 0; i < result.n * result.n; ++i) {
        result.data[i] = a - result.data[i];
    }

    return result;
}


// ================== Operatory inkrementacji i przypisania ==================

matrix& matrix::operator++(int)
{
    // A++ – zwiekszamy kazdy element o 1
    for (int i = 0; i < n * n; ++i) {
        data[i] += 1;
    }
    return *this;
}

matrix& matrix::operator--(int)
{
    // A-- – zmniejszamy kazdy element o 1
    for (int i = 0; i < n * n; ++i) {
        data[i] -= 1;
    }
    return *this;
}

matrix& matrix::operator+=(int a)
{
    // kazdy element += a
    for (int i = 0; i < n * n; ++i) {
        data[i] += a;
    }
    return *this;
}

matrix& matrix::operator-=(int a)
{
    // kazdy element -= a
    for (int i = 0; i < n * n; ++i) {
        data[i] -= a;
    }
    return *this;
}

matrix& matrix::operator*=(int a)
{
    // kazdy element *= a
    for (int i = 0; i < n * n; ++i) {
        data[i] *= a;
    }
    return *this;
}


// ================== Operator () ==================

matrix& matrix::operator()(double value)
{
    // bierzemy czesc calkowita z value w dol (floor)
    int add = static_cast<int>(std::floor(value));

    // dodajemy ja do kazdego elementu
    for (int i = 0; i < n * n; ++i) {
        data[i] += add;
    }
    return *this;
}


// ================== Strumien wyjsciowy ==================

std::ostream& operator<<(std::ostream& o, matrix& m)
{
    // wypisujemy macierz w postaci n wierszy
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.n; ++j) {
            o << m.data[i * m.n + j] << " ";
        }
        o << '\n';
    }
    return o;
}


// ================== Operatory porownania ==================

bool matrix::operator==(const matrix& m)
{
    // jezeli rozmiary sa inne – nie sa rowne
    if (n != m.n) return false;

    // sprawdzamy kazdy element
    for (int i = 0; i < n * n; ++i) {
        if (data[i] != m.data[i])
            return false;
    }
    return true;
}

bool matrix::operator>(const matrix& m)
{
    if (n != m.n) return false;

    // true tylko wtedy, gdy kazdy element this > m
    for (int i = 0; i < n * n; ++i) {
        if (data[i] <= m.data[i])
            return false;
    }
    return true;
}

bool matrix::operator<(const matrix& m)
{
    if (n != m.n) return false;

    // true tylko wtedy, gdy kazdy element this < m
    for (int i = 0; i < n * n; ++i) {
        if (data[i] >= m.data[i])
            return false;
    }
    return true;
}
