#pragma once
#include "../../core/template/template.hpp"
#include "../../struct/mint/mint.hpp"

// begin
struct comb
{
    vector<mint> f;
    vector<mint> f_inv;

    comb(ll m)
    {
        f.assign(m + 1, 1);
        f_inv.assign(m + 1, 1);
        REP1(i, m)
        {
            f[i] = f[i - 1] * i;
            f_inv[i] = f_inv[i - 1] / i;
        }
    }

    mint p(ll n, ll r)
    {
        if (n >= r)
        {
            return f[n] * f_inv[n - r];
        }
        return 0;
    }

    mint c(ll n, ll r)
    {
        if (n >= r)
        {
            return p(n, r) * f_inv[r];
        }
        return 0;
    }

    mint h(ll n, ll r)
    {
        return c(n + r - 1, r);
    }
};
// end