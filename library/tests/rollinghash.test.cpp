#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B"
#include "../rollinghash.hpp"

int main() {
  STR(T, P);
  rollinghash rht(T);
  rollinghash rhp(P);
  ll N = T.size();
  ll M = P.size();
  ii h = rhp.hash(0, M);
  rep(i, N - M + 1) {
    if (rht.hash(i, i + M) == h) {
      out(i);
    }
  }
}
