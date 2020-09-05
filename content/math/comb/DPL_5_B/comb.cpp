#include "../comb.hpp"

int main() {
  ll(n, k);

  comb comb(k);
  mint ans = comb.p(k, n);
  out(ans);
}