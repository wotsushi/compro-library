#include "../segt.hpp"

int main()
{
    ll n, q;
    cin >> n >> q;
    vi com(q), x(q), y(q);
    REP(i, q)
    {
        cin >> com[i] >> x[i] >> y[i];
    }

    segt<ll> rmq(n, (1LL << 31) - 1, [](ll x, ll y) { return min(x, y); });
    REP(i, q)
    {
        if (com[i] == 0)
        {
            rmq.update(x[i], y[i]);
        }
        else
        {
            OUT(rmq.query(x[i], y[i] + 1));
        }
    }
}