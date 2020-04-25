#include "segt.hpp"

// begin
int main()
{
    // A = [2, 7, 1, 8, 2, 8, 1] とするRMQ
    segt<ll> rmq(7, INF, [](ll x, ll y) { return min(x, y); });
    rmq.update(0, 2);
    rmq.update(1, 7);
    rmq.update(2, 1);
    rmq.update(3, 8);
    rmq.update(4, 2);
    rmq.update(5, 8);
    rmq.update(6, 1);
    // rmq.query(0, 1) = A[0]
    {
        ll actual = rmq.query(0, 1);
        ll expected = 2;
        assert(actual == expected);
    }
    // rmq.query(0, 2) = min(A[0], A[1])
    {
        ll actual = rmq.query(0, 2);
        ll expected = 2;
        assert(actual == expected);
    }
    // rmq.query(1, 4) = min(A[1], A[2], A[3])
    {
        ll actual = rmq.query(1, 4);
        ll expected = 1;
        assert(actual == expected);
    }
    // rmq.query(3, 5) = min(A[3], A[4])
    {
        ll actual = rmq.query(3, 5);
        ll expected = 2;
        assert(actual == expected);
    }
    // rmq.query(0, 8) = min(A[0], A[1], ..., A[7])
    {
        ll actual = rmq.query(0, 8);
        ll expected = 1;
        assert(actual == expected);
    }
}
// end