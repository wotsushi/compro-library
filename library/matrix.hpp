#pragma once
#include "template.hpp"

/**
 * 行列を表すデータ構造です
 */
template <typename T>
struct matrix {
  ll n, m;
  vector<vector<T>> A;

  /**
   * n次の正方行列として初期化します。各要素の初期値は0です。
   * @param n 初期化する正方行列の次数
   */
  matrix(ll n) : n(n), m(n) { A.assign(n, vector<T>(n)); }

  /**
   * n*m次の行列として初期化します。各要素の初期値は0です。
   * @param n 初期化する行列の行数
   * @param m 初期化する行列の列数
   */
  matrix(ll n, ll m) : n(n), m(m) { A.assign(n, vector<T>(m)); }

  /**
   * 2次元のVectorに対応する行列を生成します
   * @param X 生成元の2次元Vector
   */
  matrix(vector<vector<T>> X) : A(X) {
    n = X.size();
    m = X[0].size();
  }

  /**
   * 行列累乗を返します
   * @param k 指数
   * @return この行列をk乗した行列
   */
  matrix pow(ll k) {
    matrix<T> res = matrix(n, n);
    rep(i, n) { res[i][i] = 1; }
    matrix P = A;
    while (k) {
      if (k & 1) {
        res *= P;
      }
      k >>= 1;
      P *= P;
    }
    return res;
  }
  matrix &operator+=(matrix<T> B) {
    rep(i, n) {
      rep(j, m) { A[i][j] += B[i][j]; }
    }
    return *this;
  }
  matrix &operator-=(matrix<T> B) {
    rep(i, n) {
      rep(j, m) { A[i][j] -= B[i][j]; }
    }
    return *this;
  }
  matrix &operator*=(T x) {
    rep(i, n) {
      rep(j, m) { A[i][j] *= x; }
    }
    return *this;
  }
  matrix &operator*=(matrix<T> B) {
    vector<vector<T>> X(n, vector<T>(m));
    rep(i, n) {
      rep(j, B.m) {
        rep(k, m) { X[i][j] += A[i][k] * B[k][j]; }
      }
    }
    A = X;
    return *this;
  }
  matrix &operator/=(T x) {
    rep(i, n) {
      rep(j, m) { A[i][j] /= x; }
    }
    return *this;
  }

  vector<T> &operator[](int i) { return A[i]; }
};

template <typename T>
matrix<T> operator+(const matrix<T> &A, const matrix<T> &B) {
  return matrix<T>(A.A) += B;
}
template <typename T>
matrix<T> operator-(const matrix<T> &A, const matrix<T> &B) {
  return matrix<T>(A.A) -= B;
}
template <typename T>
matrix<T> operator*(const matrix<T> &A, const T &x) {
  return matrix<T>(A.A) *= x;
}
template <typename T>
matrix<T> operator*(const T &x, const matrix<T> &A) {
  return matrix<T>(A.A) *= x;
}
template <typename T>
matrix<T> operator*(const matrix<T> &A, const matrix<T> &B) {
  return matrix<T>(A.A) *= B;
}
template <typename T>
matrix<T> operator/(const matrix<T> &A, const T &x) {
  return matrix<T>(A.A) /= x;
}
template <typename T>
bool operator==(const matrix<T> &x, const matrix<T> &y) {
  return x.A == y.A;
}
template <typename T>
bool operator!=(const matrix<T> &x, const matrix<T> &y) {
  return x.A != y.A;
}
