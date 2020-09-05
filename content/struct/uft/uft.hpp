#pragma once
#include "../../core/template/template.hpp"

// begin
struct uft {
  vi p;
  vi s;

  uft() {}

  uft(ll n) {
    p.assign(n + 1, 0);
    repi(i, n) { p[i] = i; }
    s.assign(n + 1, 1);
  }

  ll find(ll i) {
    if (p[i] == i) {
      return i;
    }
    p[i] = find(p[i]);
    return p[i];
  }

  void unite(ll i, ll j) {
    i = find(i);
    j = find(j);
    if (i == j) {
      return;
    }
    if (s[i] < s[j]) {
      p[i] = j;
    } else {
      p[j] = i;
    }
    s[j] += s[i];
    s[i] = s[j];
  }

  bool same(ll i, ll j) { return find(i) == find(j); }

  ll size(ll i) { return s[find(i)]; }
};
// end