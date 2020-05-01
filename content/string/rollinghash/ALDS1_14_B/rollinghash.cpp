#include "../rollinghash.hpp"

int main()
{
    IN(string, T);
    IN(string, P);
    rollinghash rht(T);
    rollinghash rhp(P);
    ll M = P.size();
    ii h = rhp.hash(0, M);
    REP(i, T.size() - M + 1)
    {
        if (rht.hash(i, i + M) == h)
        {
            OUT(i);
        }
    }
}