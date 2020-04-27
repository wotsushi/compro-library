#include "../dijkstra.hpp"

int main()
{
    IN(ll, V);
    IN(ll, E);
    IN(ll, r);
    graph<ll> G(V - 1, E, true, true);
    cin >> G;
    vi ans = dijkstra(G, r);
    FOR(d, ans)
    {
        if (d == INF)
        {
            OUT("INF");
        }
        else
        {
            OUT(d);
        }
    }
}