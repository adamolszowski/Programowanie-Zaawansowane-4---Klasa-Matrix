#include "matrix.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

matrix& matrix::operator+(matrix& m)
{
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
    if (n != m.n) {
        std::cerr << "Blad: rozne rozmiary macierzy w operator* (matrix, matrix)\n";
        return *this;
    }

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

    data.swap(result);

    return *this;
}

matrix matrix::operator+(int a) const
{
    matrix result(*this);
    result += a;
    return result;
}

matrix matrix::operator-(int a) const
{
    matrix result(*this);
    result -= a;
    return result;
}

matrix matrix::operator*(int a) const
{
    matrix result(*this);
    result *= a;
    return result;
}