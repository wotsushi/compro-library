#pragma once
#include "../graph/graph.hpp"

// begin
template <typename W>
vi dijkstra(graph<W> &G, ll s)
{
    using E = pair<ll, W>;
    vi dp(G.n + 1, INF);
    pq_asc<E> q;
    q.push({0, s});
    dp[s] = 0;
    while (!q.empty())
    {
        auto [c, i] = q.top();
        q.pop();
        for (auto [j, w] : G[i])
        {
            if (c + w < dp[j])
            {
                dp[j] = c + w;
                q.push({dp[j], j});
            }
        }
    }
    return dp;
}

// end