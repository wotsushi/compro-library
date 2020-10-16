#pragma once
#include "template.hpp"

/**
 * 組合せを高速に数え上げるデータ構造です。
 * 数え上げ結果はmodintとして返します。
 */
template <typename M>
struct comb {
  vector<M> f;
  vector<M> f_inv;

  /**
   * 組合せの計算に必要となる階乗数とそれらの逆元を前計算します。
   * 計算量: O(m+log(MOD))
   *
   * @param m 計算する階乗数の個数。nCrのnの最大値を指定する
   */
  comb(ll m) {
    f.resize(m + 1);
    f[0] = 1;
    repi(i, m) { f[i] = f[i - 1] * i; }
    f_inv.resize(m + 1);
    f_inv[m] = f[m].inv();
    rrepi(i, m) { f_inv[i - 1] = f_inv[i] * i; }
  }

  /**
   * 順列の総数nPrを返します
   * 計算量: O(1)
   *
   * @param n 非負の整数
   * @param r 非負の整数
   * @return nPr. r > n ならば 0
   */
  M p(ll n, ll r) {
    if (n >= r) {
      return f[n] * f_inv[n - r];
    }
    return 0;
  }

  /**
   * 組合せの総数nCrを返します
   * 計算量: O(1)
   *
   * @param n 非負の整数
   * @param r 非負の整数
   * @return nCr. r > n ならば 0
   */
  M c(ll n, ll r) {
    if (n >= r) {
      return p(n, r) * f_inv[r];
    }
    return 0;
  }

  /**
   * 重複組合せの総数nHrを返します
   * 計算量: O(1)
   *
   * @param n 非負の整数
   * @param r 非負の整数
   * @return nHr
   */
  M h(ll n, ll r) { return c(n + r - 1, r); }
};
