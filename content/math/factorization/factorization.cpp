#include "factorization.hpp"

int main()
{
    {
        map<ll, ll> actual = factorization(36);
        map<ll, ll> expected{{2, 2}, {3, 2}};
        assert(actual == expected);
    }
    {
        map<ll, ll> actual = factorization(5);
        map<ll, ll> expected{{5, 1}};
        assert(actual == expected);
    }
    {
        map<ll, ll> actual = factorization(1);
        map<ll, ll> expected;
        assert(actual == expected);
    }
}