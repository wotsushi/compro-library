#pragma once
#include "../../core/template/template.hpp"

// begin
template <typename W>
struct graph
{
    using E = pair<ll, W>;
    ll n;
    ll m;
    bool weighted;
    bool directed;
    vector<vector<E>> e;

    graph(ll n, ll m = 0, bool weighted = false, bool directed = false) : n(n), m(m), directed(directed), weighted(weighted)
    {
        e.assign(n + 1, vector<E>());
    }

    void add(ll i, ll j, W w = 1)
    {
        e[i].push_back(E(j, w));
        if (not directed)
        {
            e[j].push_back(E(i, w));
        }
        ++m;
    }

    vector<E> &operator[](int i)

    {
        return e[i];
    }
};

template <typename W>
istream &operator>>(istream &is, graph<W> &G)
{
    REP(i, G.m)
    {
        ll from, to, w;
        is >> from >> to;
        if (G.weighted)
        {
            is >> w;
            G.add(from, to, w);
        }
        else
        {
            G.add(from, to);
        }
        --G.m;
    }
    return is;
}

// end