#include <iostream>
#include "matrix.h"

using namespace std;

void separator(const string& tytul)
{
    cout << "\n================ " << tytul << " ================\n\n";
}

void subseparator(const string& tytul)
{
    cout << "\n====== " << tytul << " ======\n\n";
}

int main()
{
    const int N = 30;

    separator("Testowanie klasy matrix, macierz A o rozmiarach 30 x 30");
    cout << "Metody: alokuj, wstaw, pokaz, losuj, losuj cala macierz";

    matrix A;
    A.alokuj(N);

    cout << A << endl;

    subseparator("Wstawienie na pozycje x = 1, y = 2 wartosci 50");
    A.wstaw(1, 2, 50);
    cout << A << endl;

    subseparator("Odczyt elementu x = 1, y = 2");
    cout << A.pokaz(1, 2) << endl;

    subseparator("Wypelnienie macierzy 10 losowymi wartosciami");
    A.losuj(10);
    cout << A << endl;

    subseparator("Wypelnienie macierzy losowymi wartosciami");
    A.losuj();
    cout << A << endl;

    subseparator("Alokacja V2");

    matrix AA(35);
    AA.losuj();
    cout << AA << endl;

    AA.alokuj(32);
    cout << AA << endl;

    AA.alokuj(35);
    cout << AA << endl;

    separator("Testowanie klasy matrix, macierz B o rozmiarach 30 x 30");
    cout << "Konstruktor: konstruktor matrix(int n, int* t)";
    cout << "Tablica 1-wymiarowa t z wartosciami od 1 do 900\n";

    int t[N * N];
    for (int i = 0; i < N * N; i++)
    {
        t[i] = i + 1;
    }

    matrix B(N, t);

    cout << B << endl;

    subseparator("Transpozycja macierzy B");
    B.odwroc();
    cout << B << endl;

    separator("Testowanie klasy matrix, macierz C o rozmiarach 30 x 30");
    cout << "Konstruktor: konstruktor matrix(int n)";
    cout << "Metody: Diagonalna, diagonalna_k";
    cout << "Metody: przekatna, pod_przekatna, nad_przekatna";

    matrix C(30);
    cout << C << endl;

    subseparator("Wypelnienie macierzy C diagonalna z tabeli");
    int td[N];
    for (int i = 0; i < N; i++)
    {
        td[i] = i + 1;
    }
    C.diagonalna(td);

    cout << C << endl;

    subseparator("Wypelnienie macierzy C diagonalna_k z tabeli i k = 5");
    C.diagonalna_k(5, td);

    cout << C << endl;

    subseparator("Wypelnienie macierzy C przekatna");
    C.przekatna();
    cout << C << endl;

    subseparator("Wypelnienie macierzy C pod_przekatna");
    C.pod_przekatna();
    cout << C << endl;

    subseparator("Wypelnienie macierzy C nad_przekatna");
    C.nad_przekatna();
    cout << C << endl;

    separator("Testowanie klasy matrix, macierz D o rozmiarach 30 x 30");
    cout << "Konstruktor: konstruktor matrix(int n)";
    cout << "Metody: kolumna, wiersz, szachownica";

    matrix D(30);
    cout << D << endl;

    subseparator("Wypelnienie macierzy D kolumna 10 z tabeli");
    int tk[N];
    for (int i = 0; i < N; i++)
    {
        tk[i] = (i + 1) * 10;
    }
    D.kolumna(10, tk);

    cout << D << endl;

    subseparator("Wypelnienie macierzy D wiersz 15 z tabeli");
    D.wiersz(15, tk);
    cout << D << endl;

    subseparator("Wypelnienie macierzy D szachownica");
    D.szachownica();
    cout << D << endl;

    separator("Testowanie klasy matrix, operatory +, *");
    cout << "Konstruktor: matrix(matrix& m)";
    matrix E(30);
    E.szachownica();
    cout << "Macierz E:\n" << E << endl;
    matrix F = E;
    cout << "Macierz F (kopiowana z E):\n" << F << endl;

    subseparator("Dodawanie macierzy E + F");
    matrix G = E + F;
    cout << G << endl;

    subseparator("Mnozenie macierzy E * F");
    matrix H = E * F;
    cout << H << endl;

    separator("Testowanie operatorow A + int, A - int, A * int");
    cout << "Macierz I o rozmiarach 30 x 30, wartosci od 1 do 900\n";

    matrix I(N);
    int valI = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            I.wstaw(i, j, valI++);
        }
    }

    cout << "Macierz I:\n" << I << endl;

    subseparator("I + 5");
    matrix I_plus = I + 5;
    cout << I_plus << endl;

    subseparator("I - 3");
    matrix I_minus = I - 3;
    cout << I_minus << endl;

    subseparator("I * 2");
    matrix I_mul = I * 2;
    cout << I_mul << endl;

    subseparator("Sprawdzenie, ze I pozostala bez zmian");
    cout << I << endl;

    separator("Testowanie operatorow int + A, int - A, int * A");
    cout << "Macierz J o rozmiarach 30 x 30, wartosci od 1 do 900\n";

    matrix J(N);
    int valJ = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            J.wstaw(i, j, valJ++);
        }
    }

    cout << "Macierz J:\n" << J << endl;

    subseparator("5 + J");
    matrix J_add_left = 5 + J;
    cout << J_add_left << endl;

    subseparator("10 - J");
    matrix J_sub_left = 10 - J;
    cout << J_sub_left << endl;

    subseparator("2 * J");
    matrix J_mul_left = 2 * J;
    cout << J_mul_left << endl;

    separator("Testowanie operatorow ++, --, +=, -=, *=");
    cout << "Macierz K o rozmiarach 30 x 30, wszystkie elementy = 1\n";

    matrix K(N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            K.wstaw(i, j, 1);
        }
    }

    cout << "Macierz K (start):\n" << K << endl;

    subseparator("K++ (postinkrementacja, wszystkie +1)");
    K++;
    cout << K << endl;

    subseparator("K-- (postdekrementacja, wszystkie -1)");
    K--;
    cout << K << endl;

    subseparator("K += 5");
    K += 5;
    cout << K << endl;

    subseparator("K -= 2");
    K -= 2;
    cout << K << endl;

    subseparator("K *= 3");
    K *= 3;
    cout << K << endl;

    separator("Testowanie operatora () (dodawanie floor(value) do wszystkich elementow)");
    cout << "Macierz L o rozmiarach 30 x 30, wartosci od 0 do 899\n";

    matrix L(N);
    int valL = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            L.wstaw(i, j, valL++);
        }
    }

    cout << "Macierz L przed L(3.7):\n" << L << endl;

    subseparator("L(3.7) - dodanie floor(3.7) = 3 do wszystkich elementow");
    L(3.7);
    cout << L << endl;

    separator("Testowanie operatorow porownania ==, >, <");

    matrix P1(N);
    int valP = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            P1.wstaw(i, j, valP++);
        }
    }

    matrix P2 = P1;
    matrix P3 = P1 + 1;
    matrix P4 = P1 - 1;

    cout << "Macierz P1:\n" << P1 << endl;
    cout << "Macierz P2 (kopia P1):\n" << P2 << endl;
    cout << "Macierz P3 = P1 + 1:\n" << P3 << endl;
    cout << "Macierz P4 = P1 - 1:\n" << P4 << endl;

    cout << boolalpha;

    subseparator("Porownanie P1 == P2 (powinno byc true)");
    cout << (P1 == P2) << endl;

    subseparator("Porownanie P1 == P3 (powinno byc false)");
    cout << (P1 == P3) << endl;

    subseparator("Porownanie P3 > P1 (kazdy element P3 wiekszy od P1, powinno byc true)");
    cout << (P3 > P1) << endl;

    subseparator("Porownanie P1 < P3 (powinno byc true)");
    cout << (P1 < P3) << endl;

    subseparator("Porownanie P4 < P1 (powinno byc true)");
    cout << (P4 < P1) << endl;

    subseparator("Porownanie P1 > P3 (powinno byc false)");
    cout << (P1 > P3) << endl;

    return 0;
}
