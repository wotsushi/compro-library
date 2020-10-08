#pragma once
#include "template.hpp"

/**
 * 座標圧縮した整数列を返します。圧縮後の整数には0, 1, ...が割り当てられます。
 * 圧縮前の整数列に負の値が含まれていても構いません。
 * 計算量: O(|A|log|A|)
 *
 * @param A 座標圧縮対象の整数列
 * @return 座標圧縮後の整数列
 */
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
