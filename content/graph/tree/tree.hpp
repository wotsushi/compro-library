#pragma once
#include "../graph/graph.hpp"

// begin
template <typename W>
struct tree
{
    using E = pair<ll, W>;
    ll r;
    vector<E> p;
    vector<vector<E>> c;
    vi d;

    tree(graph<W> g, ll r = 1) : r(r)
    {
        p.assign(g.e.size(), E(-2, 0));
        c.assign(g.e.size(), vector<E>());
        d.assign(g.e.size(), 0);
        queue<ll> q;
        p[r] = E(-1, 0);
        q.push(r);
        while (!q.empty())
        {
            ll i = q.front();
            q.pop();
            for (auto [j, w] : g[i])
            {
                if (p[j].first == -2)
                {
                    p[j] = E(i, w);
                    c[i].push_back(E(j, w));
                    d[j] = d[i] + 1;
                    q.push(j);
                }
            }
        }
    }

    E par(ll i)
    {
        return p[i];
    }

    ll depth(ll i)
    {
        return d[i];
    }

    vector<E> &operator[](int i)
    {
        return c[i];
    }
};

// end