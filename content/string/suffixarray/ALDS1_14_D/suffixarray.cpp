#include "../suffixarray.hpp"

int main()
{
    IN(string, T);
    IN(ll, Q);
    AIN(string, P, Q);
    suffixarray sa(T);
    FOR(p, P)
    {
        ll ok = T.size() + 1;
        ll ng = 0;
        while (ok - ng > 1)
        {
            ll mid = (ok + ng) / 2;
            if (sa[mid] >= p)
            {
                ok = mid;
            }
            else
            {
                ng = mid;
            }
        }
        YES(ok <= T.size() and sa[ok].substr(0, p.size()) == p, "1", "0");
    }
}