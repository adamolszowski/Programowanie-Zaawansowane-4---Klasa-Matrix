#include "matrix.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

matrix::matrix(void) : n(0), data(nullptr) {}

matrix::matrix(int n) : n(n), data(make_unique<int[]>(n* n)) {
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }
}

matrix::matrix(int n, int* t) : n(n), data(make_unique<int[]>(n* n)) {
    for (int i = 0; i < n * n; i++)
    {
        data[i] = t[i];
    }
}

matrix::matrix(const matrix& m) : n(m.n), data(make_unique<int[]>(m.n* m.n)) {
    for (int i = 0; i < n * n; i++)
    {
        data[i] = m.data[i];
    }
}

matrix::~matrix(void) = default;

matrix& matrix::alokuj(int n) {
    if (!data) {
        data = make_unique<int[]>(n * n);
    }
    else if (n > this->n) {
        data = make_unique<int[]>(n * n);
    }
    this->n = n;
    return *this;
}

matrix& matrix::wstaw(int x, int y, int wartosc) {
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        data[x * n + y] = wartosc;
    }
    else {
        cout << "Blad - nie ma takiej pozycji w macierzy";
    }

    return *this;
}

int matrix::pokaz(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n)
    {
        return data[x * n + y];
    }
    else {
        cout << "Blad - nie ma takiej pozycji w macierzy";
        return 0;
    }
}

matrix& matrix::odwroc(void) {
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++) {
            swap(data[i * n + j], data[j * n + i]);
        }
    }
    return *this;
}

matrix& matrix::losuj(void) {
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < n * n; i++)
    {
        data[i] = rand() % 10;
    }
    return *this;
}

matrix& matrix::losuj(int x) {
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < x; i++)
    {
        int row = rand() % n;
        int col = rand() % n;
        data[row * n + col] = rand() % 10;
    }
    return *this;
}