#include "lca.hpp"

// begin
int main()
{
    graph<ll> G(5, 4);
    G.add(1, 2);
    G.add(1, 3);
    G.add(2, 4);
    G.add(2, 5);
    tree<ll> T(G);
    lca lca(T);
    // 親が等しい頂点同士
    {
        ll actual = lca(4, 5);
        ll expected = 2;
        assert(actual == expected);
    }
    // j自身が共通祖先
    {
        ll actual = lca(4, 1);
        ll expected = 1;
        assert(actual == expected);
    }
    // 根が共通祖先
    {
        ll actual = lca(3, 5);
        ll expected = 1;
        assert(actual == expected);
    }
    // 同一頂点を指定することもできる
    {
        ll actual = lca(3, 3);
        ll expected = 3;
        assert(actual == expected);
    }
}
// end