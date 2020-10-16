#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_D"
#include "../comb.hpp"

using mint = modint1000000007;

int main() {
  ll(n, k);
  comb<mint> comb(n + k);
  mint ans = comb.h(k, n);
  out(ans);
}
