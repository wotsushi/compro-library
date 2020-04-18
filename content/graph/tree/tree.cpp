#include "tree.hpp"

int main()
{
    graph<ll> G(5, 4);
    G.add(1, 2);
    G.add(1, 3);
    G.add(2, 4);
    G.add(2, 5);
    tree<ll> T(G);
    {
        ii actual = T.par(2);
        ii expected = ii(1, 1);
        assert(actual == expected);
    }
    {
        auto [actual, _] = T.par(1);
        ll expected = -1;
        assert(actual == expected);
    }
    {
        ll actual = T.depth(4);
        ll expected = 2;
        assert(actual == expected);
    }
    {
        ll actual = T.depth(1);
        ll expected = 0;
        assert(actual == expected);
    }
    {
        vector<ii> actual = T[2];
        vector<ii> expected = {ii(4, 1), ii(5, 1)};
        assert(actual == expected);
    }
    {
        vector<ii> actual = T[5];
        vector<ii> expected = {};
        assert(actual == expected);
    }
}
