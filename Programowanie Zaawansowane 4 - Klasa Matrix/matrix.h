#pragma once

#include <memory>
#include <iostream>

/**
 * @brief Klasa reprezentujaca kwadratowa macierz liczb calkowitych (n x n).
 *
 * Macierz jest przechowywana w pamieci jako jednowymiarowa tablica (n*n)
 * w kolejnosci wierszami (row-major): element (i,j) ma indeks i * n + j.
 */
class matrix {
private:
    /**
     * @brief Rozmiar macierzy (liczba wierszy i kolumn).
     *
     * Macierz ma zawsze wymiar n x n.
     */
    int n;

    /**
     * @brief Wskaznik do dynamicznie alokowanej tablicy danych (n*n elementow).
     *
     * Pamiec jest zarzadzana przy uzyciu std::unique_ptr<int[]>.
     */
    std::unique_ptr<int[]> data;

public:
    /**
     * @brief Konstruktor domyslny.
     *
     * Tworzy obiekt bez alokacji pamieci (n = 0, data = nullptr).
     * Do utworzenia macierzy nalezy uzyc metody alokuj().
     */
    matrix(void);

    /**
     * @brief Konstruktor tworzacy macierz o rozmiarze n x n.
     *
     * Alokuje pamiec dla n*n elementow (bez inicjalizacji wartosci).
     *
     * @param n Rozmiar macierzy (liczba wierszy i kolumn).
     */
    matrix(int n);

    /**
     * @brief Konstruktor tworzacy macierz o rozmiarze n x n
     *        i kopiujacy dane z tablicy jednowymiarowej.
     *
     * Zaklada, ze tablica t ma co najmniej n*n elementow.
     * Element t[i*n + j] trafia do komorki (i, j).
     *
     * @param n Rozmiar macierzy (liczba wierszy i kolumn).
     * @param t Wskaznik do zewnetrznej tablicy int o rozmiarze co najmniej n*n.
     */
    matrix(int n, int* t);

    /**
     * @brief Konstruktor kopiujacy.
     *
     * Tworzy nowa macierz, kopiujac rozmiar i wszystkie elementy z innej macierzy.
     *
     * @param m Macierz zrodlowa do skopiowania.
     */
    matrix(const matrix& m);

    /**
     * @brief Destruktor.
     *
     * Zwlania pamiec zajmowana przez dane macierzy.
     * std::unique_ptr zajmuje sie zwolnieniem pamieci automatycznie.
     */
    ~matrix(void);

    /**
     * @brief Alokuje (lub realokuje) pamiec dla macierzy n x n.
     *
     * Jezeli macierz miala juz wczesniej przydzielona pamiec, zostaje ona zastapiona.
     *
     * @param n Nowy rozmiar macierzy.
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& alokuj(int n);

    /**
     * @brief Wstawia wartosc do komorki o wspolrzednych (x, y).
     *
     * @param x Indeks wiersza (0 <= x < n).
     * @param y Indeks kolumny (0 <= y < n).
     * @param wartosc Wartosc do wpisania w komorke (x, y).
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& wstaw(int x, int y, int wartosc);

    /**
     * @brief Zwraca wartosc z komorki o wspolrzednych (x, y).
     *
     * @param x Indeks wiersza (0 <= x < n).
     * @param y Indeks kolumny (0 <= y < n).
     * @return Wartosc elementu w komorce (x, y).
     */
    int pokaz(int x, int y);

    /**
     * @brief Transponuje macierz (zamienia wiersze z kolumnami).
     *
     * Po wywolaniu element (i, j) staje sie elementem (j, i).
     *
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& odwroc(void);

    /**
     * @brief Wypelnia cala macierz losowymi wartosciami z zakresu 0 9.
     *
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& losuj(void);

    /**
     * @brief Ustawia losowo x elementow macierzy wartosciami z zakresu 0 9.
     *
     * Pozostale elementy pozostaja bez zmian (w takiej wartosci, jaka mialy wczesniej).
     *
     * @param x Liczba elementow do wylosowania i ustawienia.
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& losuj(int x);

    /**
     * @brief Wpisuje na glownej przekatnej wartosci z tablicy t,
     *        a pozostale elementy zeruje.
     *
     * Zaklada, ze t ma co najmniej n elementow.
     *
     * @param t Wskaznik do tablicy z wartosciami przekatnej.
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& diagonalna(int* t);

    /**
     * @brief Wpisuje wartosci z tablicy t na przesunieta przekatna,
     *        pozostale elementy zeruje.
     *
     * Dla k > 0 przekatna jest przesunieta w gore (nad glowna przekatna),
     * dla k < 0 w dol (pod glowna przekatna).
     * Zaklada, ze t ma co najmniej n elementow.
     *
     * @param k Przesuniecie przekatnej (dodatnie, ujemne lub 0).
     * @param t Wskaznik do tablicy z wartosciami przekatnej.
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& diagonalna_k(int k, int* t);

    /**
     * @brief Wypelnia wybrana kolumne danymi z tablicy t.
     *
     * Zaklada, ze tablica t ma co najmniej n elementow.
     *
     * @param x Indeks kolumny (0 <= x < n).
     * @param t Wskaznik do tablicy z wartosciami dla kolumny.
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& kolumna(int x, int* t);

    /**
     * @brief Wypelnia wybrany wiersz danymi z tablicy t.
     *
     * Zaklada, ze tablica t ma co najmniej n elementow.
     *
     * @param x Indeks wiersza (0 <= x < n).
     * @param t Wskaznik do tablicy z wartosciami dla wiersza.
     * @return Referencja do bie  cego obiektu (this).
     */
    matrix& wiersz(int x, int* t);

    /**
     * @brief Tworzy macierz jednostkowa.
     *
     * Na glownej przekatnej wpisuje wartosc 1, pozostale elementy ustawia na 0.
     *
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& przekatna(void);

    /**
     * @brief Ustawia wartosc 1 pod glowna przekatna, a pozostale elementy na 0.
     *
     * Elementy (i, j), gdzie i > j, otrzymuja wartosc 1.
     * Pozostale elementy (na przekatnej i nad nia) otrzymuja wartosc 0.
     *
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& pod_przekatna(void);

    /**
     * @brief Ustawia wartosc 1 nad glowna przekatna, a pozostale elementy na 0.
     *
     * Elementy (i, j), gdzie i < j, otrzymuja wartosc 1.
     * Pozostale elementy (na przekatnej i pod nia) otrzymuja wartosc 0.
     *
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& nad_przekatna(void);

    /**
     * @brief Wypelnia macierz wzorem "szachownicy" z zer i jedynek.
     *
     * Element (i, j) jest rowny 0, gdy (i + j) jest parzyste,
     * oraz 1, gdy (i + j) jest nieparzyste.
     *
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& szachownica(void);

    /**
     * @brief Dodaje do bie  cej macierzy inna macierz (operacja in-place).
     *
     * Kazdy element this(i,j) zostaje zastapiony suma this(i,j) + m(i,j).
     * Zaklada, ze obie macierze maja ten sam rozmiar.
     *
     * @param m Macierz, ktora jest dodawana.
     * @return Referencja do bie  cego obiektu (this).
     */
    matrix& operator+(matrix& m);

    /**
     * @brief Mnozy biezaca macierz przez inna macierz (operacja in-place).
     *
     * Realizuje standardowe mnozenie macierzy: this = this * m.
     * Zaklada zgodnosc rozmiarow (obie macierze n x n).
     *
     * @param m Macierz, przez ktora nast puje mnozenie.
     * @return Referencja do bie  cego obiektu (this).
     */
    matrix& operator*(matrix& m);

    /**
     * @brief Zwraca nowa macierz, bedaca wynikiem dodania liczby calkowitej
     *        do kazdego elementu macierzy.
     *
     * Macierz bie  ca nie jest modyfikowana.
     *
     * @param a Liczba, ktora zostanie dodana do wszystkich elementow macierzy.
     * @return Nowa macierz zawierajaca wynik operacji.
     */
    matrix operator+(int a) const;

    /**
     * @brief Zwraca nowa macierz, bedaca wynikiem pomnozenia kazdego elementu
     *        macierzy przez liczbe calkowita.
     *
     * Macierz bie  ca nie jest modyfikowana.
     *
     * @param a Liczba, przez ktora zostana pomnozone wszystkie elementy.
     * @return Nowa macierz zawierajaca wynik operacji.
     */
    matrix operator*(int a) const;

    /**
     * @brief Zwraca nowa macierz, bedaca wynikiem odjecia liczby calkowitej
     *        od kazdego elementu macierzy.
     *
     * Macierz bie  ca nie jest modyfikowana.
     *
     * @param a Liczba, ktora zostanie odjeta od wszystkich elementow macierzy.
     * @return Nowa macierz zawierajaca wynik operacji.
     */
    matrix operator-(int a) const;

    /**
     * @brief Dodaje liczbe calkowita do kazdego elementu macierzy (int + A).
     *
     * Tworzy nowa macierz, w ktorej kazdy element jest rowny a + m(i, j).
     *
     * @param a Liczba calkowita stojaca po lewej stronie operatora.
     * @param m Macierz stojaca po prawej stronie operatora.
     * @return Nowa macierz zawierajaca wynik operacji.
     */
    friend matrix operator+(int a, const matrix& m);

    /**
     * @brief Mnozy kazdy element macierzy przez liczbe calkowita (int * A).
     *
     * @param a Liczba calkowita stojaca po lewej stronie operatora.
     * @param m Macierz stojaca po prawej stronie operatora.
     * @return Nowa macierz zawierajaca wynik operacji.
     */
    friend matrix operator*(int a, const matrix& m);

    /**
     * @brief Odejmuje kazdy element macierzy od liczby calkowitej (int - A).
     *
     * Wynikowy element to a - m(i, j).
     *
     * @param a Liczba calkowita stojaca po lewej stronie operatora.
     * @param m Macierz stojaca po prawej stronie operatora.
     * @return Nowa macierz zawierajaca wynik operacji.
     */
    friend matrix operator-(int a, const matrix& m);

    /**
     * @brief Postinkrementacja macierzy (A++): dodaje 1 do kazdego elementu.
     *
     * Operacja wykonywana jest in-place na bie  cej macierzy.
     *
     * @param Brak wykorzystania (postinkrementacja wymaga parametru typu int).
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& operator++(int);

    /**
     * @brief Postdekrementacja macierzy (A--): odejmuje 1 od kazdego elementu.
     *
     * Operacja wykonywana jest in-place na bie  cej macierzy.
     *
     * @param Brak wykorzystania (postdekrementacja wymaga parametru typu int).
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& operator--(int);

    /**
     * @brief Dodaje liczbe calkowita do kazdego elementu macierzy (operator przypisania).
     *
     * @param a Liczba, ktora zostanie dodana do wszystkich elementow.
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& operator+=(int a);

    /**
     * @brief Odejmuje liczbe calkowita od kazdego elementu macierzy (operator przypisania).
     *
     * @param a Liczba, ktora zostanie odjeta od wszystkich elementow.
     * @return Referencja do biezacego obiektu (this).
     */
    matrix& operator-=(int a);

    /**
     * @brief Mnozy kazdy element macierzy przez liczbe calkowita (operator przypisania).
     *
     * @param a Liczba, przez ktora zostana pomnozone wszystkie elementy.
     * @return Referencja do bie  cego obiektu (this).
     */
    matrix& operator*=(int a);

    /**
     * @brief Dodaje czesc calkowita liczby zmiennoprzecinkowej do kazdego elementu macierzy.
     *
     * Wykorzystywana jest wartosc floor(value). Na przyklad dla value = 3.7
     * do kazdego elementu zostanie dodane 3.
     *
     * @param value Liczba zmiennoprzecinkowa, z ktorej brana jest czesc calkowita.
     * @return Referencja do bie  cego obiektu (this).
     */
    matrix& operator()(double value);

    /**
     * @brief Wypisuje zawartosc macierzy do strumienia wyjsciowego.
     *
     * Elementy sa wypisywane w postaci wierszy, kazdy wiersz w osobnej linii.
     *
     * @param o Strumien wyjsciowy (np. std::cout).
     * @param m Macierz, ktorej zawartosc ma zostac wypisana.
     * @return Referencja do strumienia wyjsciowego.
     */
    friend std::ostream& operator<<(std::ostream& o, matrix& m);

    /**
     * @brief Porownuje dwie macierze pod wzgledem rownosci elementow.
     *
     * Zwraca true, jezeli wszystkie odpowiadajace sobie elementy sa rowne
     * i rozmiary macierzy sa takie same.
     *
     * @param m Macierz porownywana z biezaca.
     * @return true, jezeli macierze sa identyczne; false w przeciwnym wypadku.
     */
    bool operator==(const matrix& m);

    /**
     * @brief Sprawdza, czy kazdy element biezacej macierzy jest wiekszy
     *        od odpowiadajacego mu elementu w macierzy m.
     *
     * Zwraca true tylko wtedy, gdy dla kazdego (i, j) zachodzi this(i, j) > m(i, j).
     *
     * @param m Macierz porownywana z bie  ca.
     * @return true, jezeli wszystkie elementy this sa wieksze; false w przeciwnym wypadku.
     */
    bool operator>(const matrix& m);

    /**
     * @brief Sprawdza, czy kazdy element biezacej macierzy jest mniejszy
     *        od odpowiadajacego mu elementu w macierzy m.
     *
     * Zwraca true tylko wtedy, gdy dla kazdego (i, j) zachodzi this(i, j) < m(i, j).
     *
     * @param m Macierz porownywana z biezaca.
     * @return true, jezeli wszystkie elementy this sa mniejsze; false w przeciwnym wypadku.
     */
    bool operator<(const matrix& m);
};
