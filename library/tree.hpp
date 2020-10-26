#pragma once
#include "graph.hpp"

/**
 * 根付き木を表すデータ構造です。
 * 辺は重み付きでも構いません
 */
template <typename W>
struct tree {
  using E = pair<ll, W>;
  ll n;
  ll r;
  vector<E> p;
  vector<vector<E>> c;
  vi d;

  /**
   * グラフから根付き木を生成します。
   * 計算量: O(n)
   *
   * @param G 木を表すグラフ
   * @param r 根とする頂点
   */
  tree(graph<W> &G, ll r = 1) : n(G.n), r(r) {
    p.assign(G.n + 1, E(-2, 0));
    c.assign(G.n + 1, vector<E>());
    d.assign(G.n + 1, 0);
    queue<ll> q;
    p[r] = E(-1, 0);
    q.push(r);
    while (!q.empty()) {
      ll i = q.front();
      q.pop();
      for (auto [j, w] : G[i]) {
        if (p[j].first == -2) {
          p[j] = E(i, w);
          c[i].push_back(E(j, w));
          d[j] = d[i] + 1;
          q.push(j);
        }
      }
    }
  }

  /**
   * 指定した頂点の親を返します
   * 計算量: O(1)
   *
   * @param i 親を取得する頂点
   */
  E par(ll i) { return p[i]; }

  /**
   * 指定した頂点の深さを返します。根の深さを0とします。
   * 計算量: O(1)
   *
   * @param i 深さを取得する頂点
   */
  ll depth(ll i) { return d[i]; }

  vector<E> &operator[](int i) { return c[i]; }
};
