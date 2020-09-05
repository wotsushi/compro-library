#include "../comb.hpp"

int main() {
  ll(n, k);
  comb comb(n + k);
  mint ans = comb.h(k, n);
  out(ans);
}