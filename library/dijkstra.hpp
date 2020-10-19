#pragma once
#include "graph.hpp"

/**
 * 指定した頂点から各頂点までの最短距離を返します
 * 計算量: O(ElogV)
 *
 * @param G 重み付きグラフ
 * @param s 最短距離を求める始点
 * @return dp[i]: sからiへの最短距離
 */
template <typename W>
vec<W> dijkstra(graph<W> &G, ll s) {
  using E = pair<W, ll>;
  vec<W> dp(G.n + 1, INF);
  pq<E> q;
  q.push({0, s});
  dp[s] = 0;
  while (!q.empty()) {
    auto [c, i] = q.top();
    q.pop();
    if (c > dp[i]) {
      continue;
    }
    for (auto [j, w] : G[i]) {
      if (c + w < dp[j]) {
        dp[j] = c + w;
        q.push({dp[j], j});
      }
    }
  }
  return dp;
}
