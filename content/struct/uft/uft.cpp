#include "uft.hpp"

// begin
int main()
{
    // 集合族{{1, 2, 3}, {4, 5}, {6}}に対応する
    uft uft(6);
    uft.unite(1, 2);
    uft.unite(2, 3);
    uft.unite(4, 5);
    // 1, 2は同じ集合に属す
    {
        bool actual = uft.same(1, 2);
        bool expected = true;
        assert(actual == expected);
    }
    // 3, 1は同じ集合に属す
    {
        bool actual = uft.same(3, 1);
        bool expected = true;
        assert(actual == expected);
    }
    // 4, 5は同じ集合に属す
    {
        bool actual = uft.same(4, 5);
        bool expected = true;
        assert(actual == expected);
    }
    // 1, 4は異なる集合に属す
    {
        bool actual = uft.same(1, 4);
        bool expected = false;
        assert(actual == expected);
    }
    // 5, 6は異なる集合に属す
    {
        bool actual = uft.same(5, 6);
        bool expected = false;
        assert(actual == expected);
    }
    // 1が属す集合の要素数は3
    {
        ll actual = uft.size(1);
        ll expected = 3;
        assert(actual == expected);
    }
    // 2が属す集合の要素数は3
    {
        ll actual = uft.size(2);
        ll expected = 3;
        assert(actual == expected);
    }
    // 4が属す集合の要素数は2
    {
        ll actual = uft.size(4);
        ll expected = 2;
        assert(actual == expected);
    }
    // 6が属す集合の要素数は1
    {
        ll actual = uft.size(6);
        ll expected = 1;
        assert(actual == expected);
    }
}
// end
