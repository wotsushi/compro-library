#include "../dijkstra.hpp"
#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

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
