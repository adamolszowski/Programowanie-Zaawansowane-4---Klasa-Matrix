#pragma once

#include <memory>
#include <iostream>

class matrix {
private:
    int n;
    std::unique_ptr<int[]> data;

public:
    matrix(void);
    matrix(int n);
    matrix(int n, int* t);
    matrix(const matrix& m);
    ~matrix(void);

    matrix& alokuj(int n);
    matrix& wstaw(int x, int y, int wartosc);
    int pokaz(int x, int y);
    matrix& odwroc(void);
    matrix& losuj(void);
    matrix& losuj(int x);
    matrix& diagonalna(int* t);
    matrix& diagonalna_k(int k, int* t);
    matrix& kolumna(int x, int* t);
    matrix& wiersz(int x, int* t);
    matrix& przekatna(void);
    matrix& pod_przekatna(void);
    matrix& nad_przekatna(void);
    matrix& szachownica(void);

    matrix& operator+(matrix& m);
    matrix& operator*(matrix& m);

    matrix operator+(int a) const;
    matrix operator*(int a) const;
    matrix operator-(int a) const;

    friend matrix operator+(int a, const matrix& m);
    friend matrix operator*(int a, const matrix& m);
    friend matrix operator-(int a, const matrix& m);

    matrix& operator++(int);
    matrix& operator--(int);

    matrix& operator+=(int a);
    matrix& operator-=(int a);
    matrix& operator*=(int a);

    matrix& operator()(double value);

    friend std::ostream& operator<<(std::ostream& o, matrix& m);

    bool operator==(const matrix& m);
    bool operator>(const matrix& m);
    bool operator<(const matrix& m);
};


