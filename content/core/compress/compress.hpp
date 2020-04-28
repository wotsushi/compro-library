#pragma once
#include "../template/template.hpp"

// begin
vi compress(vi &A)
{
    map<ll, ll> P;
    FOR(a, A)
    {
        P.insert({a, 0});
    }
    ll p = 0;
    for (auto [k, _] : P)
    {
        P[k] = p;
        ++p;
    }
    vi B(A.size());
    REP(i, A.size())
    {
        B[i] = P[A[i]];
    }
    return B;
}
// end
