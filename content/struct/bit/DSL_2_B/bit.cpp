#include "../bit.hpp"

int main()
{
    IN(ll, n);
    IN(ll, q);
    vi com(q), x(q), y(q);
    REP(i, q)
    {
        cin >> com[i] >> x[i] >> y[i];
    }
    bit<ll> bit(n + 1);
    REP(i, q)
    {
        if (com[i] == 0)
        {
            bit.add(x[i], y[i]);
        }
        else
        {
            OUT(bit.sum(y[i] + 1) - bit.sum(x[i]));
        }
    }
}
