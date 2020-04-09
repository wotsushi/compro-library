#include "segt.hpp"

int main()
{
    segt<ll> rmq(7, INF, [](ll x, ll y) { return min(x, y); });
    rmq.update(0, 2);
    rmq.update(1, 7);
    rmq.update(2, 1);
    rmq.update(3, 8);
    rmq.update(4, 2);
    rmq.update(5, 8);
    rmq.update(6, 1);
    {
        ll actual = rmq.query(0, 1);
        ll expected = 2;
        assert(actual == expected);
    }
    {
        ll actual = rmq.query(0, 2);
        ll expected = 2;
        assert(actual == expected);
    }
    {
        ll actual = rmq.query(1, 4);
        ll expected = 1;
        assert(actual == expected);
    }
    {
        ll actual = rmq.query(3, 5);
        ll expected = 2;
        assert(actual == expected);
    }
    {
        ll actual = rmq.query(0, 8);
        ll expected = 1;
        assert(actual == expected);
    }
}