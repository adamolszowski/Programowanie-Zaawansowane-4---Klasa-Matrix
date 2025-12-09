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


matrix& matrix::diagonalna(int* t) {
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        data[i * n + i] = t[i];
    }
    return *this;
}

matrix& matrix::diagonalna_k(int k, int* t) {
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }

    if (k >= 0) {
        for (int i = 0; i < n - k; i++)
        {
            data[i * n + (i + k)] = t[i];
        }
    }
    else {
        for (int i = 0; i < n + k; i++)
        {
            data[(i - k) * n + i] = t[i];
        }
    }
    return *this;
}

matrix& matrix::kolumna(int x, int* t) {
    for (int i = 0; i < n; i++)
    {
        data[i * n + x] = t[i];
    }
    return *this;
}

matrix& matrix::wiersz(int x, int* t) {
    for (int i = 0; i < n; i++)
    {
        data[x * n + i] = t[i];
    }
    return *this;
}

matrix& matrix::przekatna(void) {
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        data[i * n + i] = 1;
    }
    return *this;
}

matrix& matrix::pod_przekatna(void) {
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }
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
    for (int i = 0; i < n * n; i++)
    {
        data[i] = 0;
    }
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