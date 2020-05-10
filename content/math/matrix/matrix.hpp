#pragma once
#include "../../core/template/template.hpp"

// begin
template <typename T>
struct matrix
{
    ll n, m;
    vector<vector<T>> A;

    matrix() {}
    matrix(ll n) : n(n), m(n)
    {
        A.assign(n, vector<T>(n));
    }
    matrix(ll n, ll m) : n(n), m(m)
    {
        A.assign(n, vector<T>(m));
    }
    matrix(vector<vector<T>> X) : A(X)
    {
        n = X.size();
        m = X[0].size();
    }
    matrix pow(ll k)
    {
        matrix<T> res = matrix(n, n);
        REP(i, n)
        {
            res[i][i] = 1;
        }
        matrix P = A;
        while (k)
        {
            if (k & 1)
            {
                res *= P;
            }
            k >>= 1;
            P *= P;
        }
        return res;
    }
    matrix &operator+=(matrix<T> B)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                A[i][j] += B[i][j];
            }
        }
        return *this;
    }
    matrix &operator-=(matrix<T> B)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                A[i][j] -= B[i][j];
            }
        }
        return *this;
    }
    matrix &operator*=(T x)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                A[i][j] *= x;
            }
        }
        return *this;
    }
    matrix &operator*=(matrix<T> B)
    {
        vector<vector<T>> X(n, vector<T>(m));
        REP(i, n)
        {
            REP(j, B.m)
            {
                REP(k, m)
                {
                    X[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        A = X;
        return *this;
    }
    matrix &operator/=(T x)
    {
        REP(i, n)
        {
            REP(j, m)
            {
                A[i][j] /= x;
            }
        }
        return *this;
    }

    vector<T> &operator[](int i)
    {
        return A[i];
    }
};

template <typename T>
matrix<T> operator+(const matrix<T> &A, const matrix<T> &B)
{
    return matrix<T>(A.A) += B;
}
template <typename T>
matrix<T> operator-(const matrix<T> &A, const matrix<T> &B)
{
    return matrix<T>(A.A) -= B;
}
template <typename T>
matrix<T> operator*(const matrix<T> &A, const T &x)
{
    return matrix<T>(A.A) *= x;
}
template <typename T>
matrix<T> operator*(const T &x, const matrix<T> &A)
{
    return matrix<T>(A.A) *= x;
}
template <typename T>
matrix<T> operator*(const matrix<T> &A, const matrix<T> &B)
{
    return matrix<T>(A.A) *= B;
}
template <typename T>
matrix<T> operator/(const matrix<T> &A, const T &x)
{
    return matrix<T>(A.A) /= x;
}
template <typename T>
bool operator==(const matrix<T> &x, const matrix<T> &y)
{
    return x.A == y.A;
}
template <typename T>
bool operator!=(const matrix<T> &x, const matrix<T> &y)
{
    return x.A != y.A;
}

// end
