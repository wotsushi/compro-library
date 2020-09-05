#include "../suffixarray.hpp"

int main() {
  STR(T);
  ll(Q);
  vin(string, P, Q);
  suffixarray sa(T);
  each(p, P) {
    ll ok = T.size() + 1;
    ll ng = 0;
    while (ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      if (sa[mid] >= p) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    yes(ok <= T.size() and sa[ok].substr(0, p.size()) == p, "1", "0");
  }
}