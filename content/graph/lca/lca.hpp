#pragma once
#include "../tree/tree.hpp"

// begin
struct lca
{
    vvi p;
    vi d;
    ll m;

    lca() {}

    template <typename W>
    lca(tree<W> &T)
    {
        m = 1;
        ll n = T.n + 1;
        while (n > 1)
        {
            n >>= 1;
            ++m;
        }
        p.assign(T.n + 1, vi(m));
        REP(i, T.n + 1)
        {
            p[i][0] = T.par(i).first;
        }
        REP(j, m - 1)
        {
            REP(i, T.n + 1)
            {
                if (p[i][j] < 0)
                {
                    p[i][j + 1] = p[i][j];
                }
                else
                {
                    p[i][j + 1] = p[p[i][j]][j];
                }
            }
        }
        d.assign(T.n + 1, 0);
        REP(i, T.n + 1)
        {
            d[i] = T.depth(i);
        }
    }

    ll operator()(ll i, ll j)
    {
        if (d[i] > d[j])
        {
            swap(i, j);
        }
        REP(k, m)
        {
            if ((d[j] - d[i]) >> k & 1)
            {
                j = p[j][k];
            }
        }
        if (i == j)
        {
            return i;
        }
        for (ll k = m - 1; k >= 0; --k)
        {
            if (p[i][k] != p[j][k])
            {
                i = p[i][k];
                j = p[j][k];
            }
        }
        return p[i][0];
    }
};

// end