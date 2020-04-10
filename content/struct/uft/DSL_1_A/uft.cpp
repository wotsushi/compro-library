#include "../uft.hpp"

int main()
{
    ll n, q;
    cin >> n >> q;
    vi com(q), x(q), y(q);
    REP(i, q)
    {
        cin >> com[i] >> x[i] >> y[i];
    }

    uft uft(n - 1);
    REP(i, q)
    {
        if (com[i] == 0)
        {
            uft.unite(x[i], y[i]);
        }
        else
        {
            if (uft.same(x[i], y[i]))
            {
                OUT(1);
            }
            else
            {
                OUT(0);
            }
        }
    }
}