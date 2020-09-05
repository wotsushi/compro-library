#include "../dijkstra.hpp"

int main() {
  ll(V, E, r);
  graph<ll> G(V - 1, E, true, true);
  cin >> G;
  vi ans = dijkstra(G, r);
  each(d, ans) {
    if (d == INF) {
      out("INF");
    } else {
      out(d);
    }
  }
}