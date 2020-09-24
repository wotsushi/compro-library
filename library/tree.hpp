#pragma once
#include "graph.hpp"

template <typename W>
struct tree {
  using E = pair<ll, W>;
  ll n;
  ll r;
  vector<E> p;
  vector<vector<E>> c;
  vi d;

  tree() {}

  tree(graph<W> &G, ll r = 1) : n(G.n), r(r) {
    p.assign(G.n + 1, E(-2, 0));
    c.assign(G.n + 1, vector<E>());
    d.assign(G.n + 1, 0);
    queue<ll> q;
    p[r] = E(-1, 0);
    q.push(r);
    while (!q.empty()) {
      ll i = q.front();
      q.pop();
      for (auto [j, w] : G[i]) {
        if (p[j].first == -2) {
          p[j] = E(i, w);
          c[i].push_back(E(j, w));
          d[j] = d[i] + 1;
          q.push(j);
        }
      }
    }
  }

  E par(ll i) { return p[i]; }

  ll depth(ll i) { return d[i]; }

  vector<E> &operator[](int i) { return c[i]; }
};
