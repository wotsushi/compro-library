#include "../segt.hpp"

int main() {
  ll(n, q);
  vll(com, x, y, q);
  segt<ll> rmq(n, (1LL << 31) - 1, [](ll x, ll y) { return min(x, y); });
  rep(i, q) {
    if (com[i] == 0) {
      rmq.update(x[i], y[i]);
    } else {
      out(rmq.query(x[i], y[i] + 1));
    }
  }
}