#include "../rollinghash.hpp"

int main() {
  STR(T, P);
  rollinghash rht(T);
  rollinghash rhp(P);
  ll M = P.size();
  ii h = rhp.hash(0, M);
  rep(i, T.size() - M + 1) {
    if (rht.hash(i, i + M) == h) {
      out(i);
    }
  }
}