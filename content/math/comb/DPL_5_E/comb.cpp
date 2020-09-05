#include "../comb.hpp"

int main() {
  ll(n, k);
  comb comb(k);
  mint ans = comb.c(k, n);
  out(ans);
}