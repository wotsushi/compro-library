#pragma once
#include "../../core/template/template.hpp"

// begin
const ll RH_BASE[2] = {1007, 2009};
const ll RH_MOD[2] = {1000000007, 1000000009};

struct rollinghash
{
    vvi h;
    vvi p;

    rollinghash() {}

    rollinghash(const string &s)
    {
        ll n = s.size();
        h.assign(2, {});
        p.assign(2, {});
        REP(k, 2)
        {
            h[k].assign(n + 1, 0);
            p[k].assign(n + 1, 1);
            REP(i, n)
            {
                h[k][i + 1] = (RH_BASE[k] * h[k][i] + s[i]) % RH_MOD[k];
                p[k][i + 1] = (RH_BASE[k] * p[k][i]) % RH_MOD[k];
            }
        }
    }

    ii hash(ll i, ll j)
    {
        ll h0 = (h[0][j] - h[0][i] * p[0][j - i]) % RH_MOD[0];
        ll h1 = (h[1][j] - h[1][i] * p[1][j - i]) % RH_MOD[1];
        return {(h0 + RH_MOD[0]) % RH_MOD[0], (h1 + RH_MOD[1]) % RH_MOD[1]};
    }
};
// end
