#pragma once
#include "../../core/template/template.hpp"

// begin
template <typename T>
struct segt
{
    using F = function<T(T, T)>;
    ll m;
    vector<T> a;
    T e;
    F f;

    segt(ll n, T e, F f) : e(e), f(f)
    {
        m = 1;
        while (m < n)
        {
            m <<= 1;
        }
        a.assign(2 * m, e);
    }

    void update(ll i, T x)
    {
        i += m;
        a[i] = x;
        while (i >>= 1)
        {
            a[i] = f(a[2 * i], a[2 * i + 1]);
        }
    }

    T query(ll i, ll j)
    {
        T l = e;
        T r = e;
        for (i += m, j += m; i < j; i >>= 1, j >>= 1)
        {
            if (i & 1)
            {
                l = f(l, a[i]);
                ++i;
            }
            if (j & 1)
            {
                --j;
                r = f(r, a[j]);
            }
        }
        return f(l, r);
    }
};
// end
