#include "factorization.hpp"

// begin
int main()
{
    // 36 = 2^2 * 3^2 なので {2: 2, 3: 2}
    {
        map<ll, ll> actual = factorization(36);
        map<ll, ll> expected{{2, 2}, {3, 2}};
        assert(actual == expected);
    }
    // 5 = 5^1 なので {5: 1}
    {
        map<ll, ll> actual = factorization(5);
        map<ll, ll> expected{{5, 1}};
        assert(actual == expected);
    }
    // 1以下の場合、空のmapとなる
    {
        map<ll, ll> actual = factorization(1);
        map<ll, ll> expected;
        assert(actual == expected);
    }
}
// end