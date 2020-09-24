#pragma once
#include "template.hpp"

vi compress(vi &A) {
  map<ll, ll> P;
  each(a, A) { P.insert({a, 0}); }
  ll p = 0;
  for (auto [k, _] : P) {
    P[k] = p;
    ++p;
  }
  vi B(A.size());
  rep(i, A.size()) { B[i] = P[A[i]]; }
  return B;
}
