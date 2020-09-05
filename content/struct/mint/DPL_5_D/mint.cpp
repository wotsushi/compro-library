#include "../mint.hpp"

int main() {
  in(mint, n, k);
  mint ans(1);
  rep(i, k.a - 1) {
    ans *= n + k - 1 - i;
    ans /= i + 1;
  }
  out(ans);
}