#include "../bit.hpp"

int main() {
  ll(n, q);
  vll(com, x, y, q);
  bit<ll> bit(n + 1);
  rep(i, q) {
    if (com[i] == 0) {
      bit.add(x[i], y[i]);
    } else {
      out(bit.sum(y[i] + 1) - bit.sum(x[i]));
    }
  }
}
