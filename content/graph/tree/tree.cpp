#include "tree.hpp"

// begin
int main()
{
    graph<ll> G(5, 4);
    G.add(1, 2);
    G.add(1, 3);
    G.add(2, 4);
    G.add(2, 5);
    // 第2引数を指定しない場合、頂点1を根とする木となる
    tree<ll> T(G);
    // 内部節点に対するpar
    {
        ii actual = T.par(2);
        ii expected = ii(1, 1);
        assert(actual == expected);
    }
    // 根に対するparは-1を返す
    {
        auto [actual, _] = T.par(1);
        ll expected = -1;
        assert(actual == expected);
    }
    // 内部接点に対するdepth
    {
        ll actual = T.depth(4);
        ll expected = 2;
        assert(actual == expected);
    }
    // 根に対するdepthは0となる
    {
        ll actual = T.depth(1);
        ll expected = 0;
        assert(actual == expected);
    }
    // T[2]は頂点2の子に対する辺の列を返す
    {
        vector<ii> actual = T[2];
        vector<ii> expected = {ii(4, 1), ii(5, 1)};
        assert(actual == expected);
    }
    // 葉iについてT[i]は空である
    {
        vector<ii> actual = T[5];
        vector<ii> expected = {};
        assert(actual == expected);
    }
}
// end