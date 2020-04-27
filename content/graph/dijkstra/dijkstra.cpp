#include "dijkstra.hpp"

// begin
int main()
{
    // 重み付き無向グラフの頂点1と頂点i(i > 2)間の最短距離を求める
    {
        graph<ll> G(4, 0, true);
        G.add(1, 2, 1);
        G.add(1, 3, 2);
        G.add(2, 4, 8);
        G.add(3, 4, 4);
        auto actual = dijkstra(G, 1);
        vi expected{INF, 0, 1, 2, 6};
        assert(actual == expected);
    }
    // 重み付き有向グラフの頂点1と頂点i(i > 2)間の最短距離を求める場合も同様に使える
    {
        graph<ll> G(4, 0, true, true);
        G.add(1, 2, 8);
        G.add(1, 3, 4);
        G.add(3, 4, 2);
        G.add(4, 2, 1);
        auto actual = dijkstra(G, 1);
        vi expected{INF, 0, 7, 4, 6};
        assert(actual == expected);
    }
}
// end