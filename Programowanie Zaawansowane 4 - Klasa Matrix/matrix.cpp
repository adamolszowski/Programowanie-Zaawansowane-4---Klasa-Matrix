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