#include "comb.hpp"

// begin
int main()
{
    // 5P2
    {
        comb comb(5);
        mint actual = comb.p(5, 2);
        mint expected = 20;
        assert(actual.a == expected.a);
    }
    // 5C2
    {
        comb comb(5);
        mint actual = comb.c(5, 2);
        mint expected = 10;
        assert(actual.a == expected.a);
    }
    // 5H2; combは6(=5+2-1)以上の値を指定する必要があるので注意
    {
        comb comb(6);
        mint actual = comb.h(5, 2);
        mint expected = 15;
        assert(actual.a == expected.a);
    }
}
// end