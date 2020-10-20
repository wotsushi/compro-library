#pragma once
#include "template.hpp"

/**
 * グラフを表すデータ構造です。
 * 重み付き／なしの有向／無向グラフを表現できます
 */
template <typename W>
struct graph {
  using E = pair<ll, W>;
  ll n;
  ll m;
  bool weighted;
  bool directed;
  vector<vector<E>> e;

  /**
   * 隣接リストを用いてグラフを作成します
   * 計算量: O(n)
   *
   * @param n 頂点数
   * @param m 辺数
   * @param weighted 重み付きならばtrue
   * @param directed 有向グラフならばtrue
   */
  graph(ll n, ll m = 0, bool weighted = false, bool directed = false)
      : n(n), m(m), directed(directed), weighted(weighted) {
    e.assign(n + 1, vector<E>());
  }

  /**
   * グラフに辺を追加します
   *
   * @param i 辺の端点（有向グラフの場合は始点）
   * @param j 辺の端点（有向グラフの場合は終点）
   * @param w 辺の重み（重み付きでないグラフならば1）
   */
  void add(ll i, ll j, W w = 1) {
    e[i].push_back(E(j, w));
    if (not directed) {
      e[j].push_back(E(i, w));
    }
    ++m;
  }

  vector<E> &operator[](int i) { return e[i]; }
};

template <typename W>
istream &operator>>(istream &is, graph<W> &G) {
  rep(i, G.m) {
    ll from, to, w;
    is >> from >> to;
    if (G.weighted) {
      is >> w;
      G.add(from, to, w);
    } else {
      G.add(from, to);
    }
    --G.m;
  }
  return is;
}
