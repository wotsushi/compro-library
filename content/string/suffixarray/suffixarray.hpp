#pragma once
#include "../../core/template/template.hpp"

// begin
struct suffixarray
{
    using S = tuple<ll, ll, ll>;
    string s;
    vector<S> sa;

    suffixarray() {}

    suffixarray(const string &s) : s(s)
    {
        ll n = s.size();
        sa.assign(n + 1, {0, 0, 0});
        REP(i, n + 1)
        {
            get<0>(sa[i]) = i < n ? s[i] : 0;
            get<1>(sa[i]) = i + 1 < n ? s[i + 1] : 0;
            get<2>(sa[i]) = i;
        }

        for (ll k = 1; k <= n; k *= 2)
        {
            SORT(sa);
            vi p(n + 1);
            ll r = n;
            for (ll i = n; i >= 0; --i)
            {
                bool greater = i > 0 and (get<0>(sa[i]) > get<0>(sa[i - 1]) or get<0>(sa[i]) == get<0>(sa[i - 1]) and get<1>(sa[i]) > get<1>(sa[i - 1]));
                get<0>(sa[i]) = r;
                if (greater)
                {
                    --r;
                }
                p[get<2>(sa[i])] = i;
            }
            REP(i, n + 1)
            {
                get<1>(sa[i]) = get<0>(sa[p[min(n, get<2>(sa[i]) + 2 * k)]]);
            }
        }
    }

    string operator[](int i)
    {
        return s.substr(get<2>(sa[i]));
    }
};
// end
