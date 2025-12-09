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

matrix operator+(int a, const matrix& m)
{
    return m + a;
}

matrix operator*(int a, const matrix& m)
{
    return m * a;
}

matrix operator-(int a, const matrix& m)
{
    matrix result(m);

    for (int i = 0; i < result.n * result.n; ++i) {
        result.data[i] = a - result.data[i];
    }

    return result;
}

matrix& matrix::operator++(int)
{
    for (int i = 0; i < n * n; ++i) {
        data[i] += 1;
    }
    return *this;
}

matrix& matrix::operator--(int)
{
    for (int i = 0; i < n * n; ++i) {
        data[i] -= 1;
    }
    return *this;
}

matrix& matrix::operator+=(int a)
{
    for (int i = 0; i < n * n; ++i) {
        data[i] += a;
    }
    return *this;
}

matrix& matrix::operator-=(int a)
{
    for (int i = 0; i < n * n; ++i) {
        data[i] -= a;
    }
    return *this;
}

matrix& matrix::operator*=(int a)
{
    for (int i = 0; i < n * n; ++i) {
        data[i] *= a;
    }
    return *this;
}


matrix& matrix::operator()(double value)
{
    int add = static_cast<int>(std::floor(value));

    for (int i = 0; i < n * n; ++i) {
        data[i] += add;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, matrix& m)
{
    for (int i = 0; i < m.n; ++i) {
        for (int j = 0; j < m.n; ++j) {
            o << m.data[i * m.n + j] << " ";
        }
        o << '\n';
    }
    return o;
}

bool matrix::operator==(const matrix& m)
{
    if (n != m.n) return false;

    for (int i = 0; i < n * n; ++i) {
        if (data[i] != m.data[i])
            return false;
    }
    return true;
}

bool matrix::operator>(const matrix& m)
{
    if (n != m.n) return false;

    for (int i = 0; i < n * n; ++i) {
        if (data[i] <= m.data[i])
            return false;
    }
    return true;
}

bool matrix::operator<(const matrix& m)
{
    if (n != m.n) return false;

    for (int i = 0; i < n * n; ++i) {
        if (data[i] >= m.data[i])
            return false;
    }
    return true;
}