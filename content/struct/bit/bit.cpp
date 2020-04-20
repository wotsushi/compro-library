#include "bit.hpp"

int main()
{
    bit<ll> bit(3);
    bit.add(0, 1);
    bit.add(1, 2);
    bit.add(2, 3);
    {
        ll actual = bit.sum(3);
        ll expected = 6;
        assert(actual == expected);
    }
    {
        ll actual = bit.sum(2);
        ll expected = 3;
        assert(actual == expected);
    }
    {
        ll actual = bit.sum(1);
        ll expected = 1;
        assert(actual == expected);
    }
    {
        ll actual = bit.sum(0);
        ll expected = 0;
        assert(actual == expected);
    }
    return 0;
}