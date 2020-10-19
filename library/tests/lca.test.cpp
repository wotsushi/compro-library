#include "../lca.hpp"
#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

int main() {
  ll(n);
  vi k(n);
  vvi c(n);
  rep(i, n) {
    cin >> k[i];
    c[i] = vi(k[i]);
    rep(j, k[i]) { cin >> c[i][j]; }
  }
  graph<ll> G(n - 1);
  rep(i, n) {
    rep(j, k[i]) { G.add(i, c[i][j]); }
  }
  tree<ll> T(G, 0);
  lca lca(T);
  ll(q);
  rep(i, q) {
    ll(u, v);
    out(lca(u, v));
  }
}
