#include "../factorization.hpp"

int main() {
  ll(n);
  vi ans;
  for (auto [p, k] : factorization(n)) {
    rep(i, k) { ans.push_back(p); }
  }
  SORT(ans);
  cout << n << ": ";
  jout(ALL(ans), " ", cout) << endl;
}