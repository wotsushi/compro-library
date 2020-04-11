#include "comb.hpp"

int main()
{
    {
        comb comb(5);
        mint actual = comb.p(5, 2);
        mint expected = 20;
        assert(actual.a == expected.a);
    }
    {
        comb comb(5);
        mint actual = comb.c(5, 2);
        mint expected = 10;
        assert(actual.a == expected.a);
    }
    {
        comb comb(6);
        mint actual = comb.h(5, 2);
        mint expected = 15;
        assert(actual.a == expected.a);
    }
}