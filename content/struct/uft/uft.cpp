#include "uft.hpp"

int main()
{
    uft uft(6);
    uft.unite(1, 2);
    uft.unite(2, 3);
    uft.unite(4, 5);
    {
        bool actual = uft.same(1, 2);
        bool expected = true;
        assert(actual == expected);
    }
    {
        bool actual = uft.same(3, 1);
        bool expected = true;
        assert(actual == expected);
    }
    {
        bool actual = uft.same(4, 5);
        bool expected = true;
        assert(actual == expected);
    }
    {
        bool actual = uft.same(1, 4);
        bool expected = false;
        assert(actual == expected);
    }
    {
        bool actual = uft.same(5, 6);
        bool expected = false;
        assert(actual == expected);
    }
    {
        ll actual = uft.size(1);
        ll expected = 3;
        assert(actual == expected);
    }
    {
        ll actual = uft.size(2);
        ll expected = 3;
        assert(actual == expected);
    }
    {
        ll actual = uft.size(4);
        ll expected = 2;
        assert(actual == expected);
    }
    {
        ll actual = uft.size(6);
        ll expected = 1;
        assert(actual == expected);
    }
}