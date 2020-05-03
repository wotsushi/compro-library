#pragma once
#include "../../core/template/template.hpp"

// begin
template <typename T>
struct bit
{
    ll n;
    vector<T> a;

    bit() {}

    bit(ll n) : n(n)
    {
        a.assign(n + 1, 0);
    }

    void add(ll i, T x)
    {
        ++i;
        while (i <= n)
        {
            a[i] += x;
            i += i & -i;
        }
    }

    T sum(ll i)
    {
        T s = 0;
        while (i > 0)
        {
            s += a[i];
            i -= i & -i;
        }
        return s;
    }
};
// end
