#pragma once
#include "../../core/template/template.hpp"

// begin
map<ll, ll> factorization(ll x)
{
    map<ll, ll> res;
    for (ll i = 2; i * i <= x; ++i)
    {
        while (x % i == 0)
        {
            ++res[i];
            x /= i;
        }
    }
    if (x > 1)
    {
        ++res[x];
    }
    return res;
}
// end
