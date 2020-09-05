#include "../uft.hpp"

int main() {
  ll(n, q);
  vll(com, x, y, q);
  uft uft(n - 1);
  rep(i, q) {
    if (com[i] == 0) {
      uft.unite(x[i], y[i]);
    } else {
      if (uft.same(x[i], y[i])) {
        out(1);
      } else {
        out(0);
      }
    }
  }
}