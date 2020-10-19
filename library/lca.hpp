#pragma once
#include "tree.hpp"

/**
 * ある根付き木のLCA(Lowest Common Ancestor)を効率的に求める構造体です
 */
struct lca {
  vvi p;
  vi d;
  ll m;

  /**
   * 指定した根付き木のLCAを高速に求めるデータ構造を返します
   * 計算量: O(NlogN)
   *
   * @param T LCAを高速に求められるようにする根付き木
   */
  template <typename W>
  lca(tree<W> &T) {
    m = 1;
    ll n = T.n + 1;
    while (n > 1) {
      n >>= 1;
      ++m;
    }
    p.assign(T.n + 1, vi(m));
    rep(i, T.n + 1) { p[i][0] = T.par(i).first; }
    rep(j, m - 1) {
      rep(i, T.n + 1) {
        if (p[i][j] < 0) {
          p[i][j + 1] = p[i][j];
        } else {
          p[i][j + 1] = p[p[i][j]][j];
        }
      }
    }
    d.assign(T.n + 1, 0);
    rep(i, T.n + 1) { d[i] = T.depth(i); }
  }

  /**
   * lca(i, j)でi, jのLCAが得られます。
   * 計算量: O(logN)
   *
   * @param i LCAを求める頂点
   * @param j LCAを求める頂点
   */
  ll operator()(ll i, ll j) {
    if (d[i] > d[j]) {
      swap(i, j);
    }
    rep(k, m) {
      if ((d[j] - d[i]) >> k & 1) {
        j = p[j][k];
      }
    }
    if (i == j) {
      return i;
    }
    for (ll k = m - 1; k >= 0; --k) {
      if (p[i][k] != p[j][k]) {
        i = p[i][k];
        j = p[j][k];
      }
    }
    return p[i][0];
  }
};
