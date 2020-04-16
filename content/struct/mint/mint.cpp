#include "mint.hpp"

int main()
{
    {
        mint x;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    {
        mint x(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    {
        mint x(1e9 + 7);
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    {
        mint x(-1);
        ll actual = x.a;
        ll expected = 1e9 + 6;
        assert(actual == expected);
    }

    {
        mint x(1e9 + 6);
        x += 1;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    {
        mint x;
        x += mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    {
        mint x = mint(1) + mint(1);
        ll actual = x.a;
        ll expected = 2;
        assert(actual == expected);
    }
    {
        mint x = mint(1) + 1;
        ll actual = x.a;
        ll expected = 2;
        assert(actual == expected);
    }
    {
        mint x = 1 + mint(1);
        ll actual = x.a;
        ll expected = 2;
        assert(actual == expected);
    }

    {
        mint x;
        x -= 1;
        ll actual = x.a;
        ll expected = 1e9 + 6;
        assert(actual == expected);
    }
    {
        mint x(1);
        x -= mint(1);
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    {
        mint x = mint(1) - mint(1);
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    {
        mint x = mint(1) - 1;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    {
        mint x = 1 - mint(1);
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }

    {
        mint x(1);
        x *= -1;
        ll actual = x.a;
        ll expected = 1e9 + 6;
        assert(actual == expected);
    }
    {
        mint x(5e8 + 4);
        x *= mint(2);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    {
        mint x = mint(1) * mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    {
        mint x = mint(1) * 1;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    {
        mint x = 1 * mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }

    {
        mint x(2);
        x /= -2;
        ll actual = x.a;
        ll expected = 1e9 + 6;
        assert(actual == expected);
    }
    {
        mint x(1);
        x /= mint(2);
        ll actual = x.a;
        ll expected = 5e8 + 4;
        assert(actual == expected);
    }
    {
        mint x = mint(1) / mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    {
        mint x = mint(1) / 1;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    {
        mint x = 1 / mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }

    {
        mint x;
        x++;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    {
        mint x;
        ++x;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }

    {
        mint x(1);
        x--;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    {
        mint x(1);
        --x;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }

    {
        mint x(2);
        x = x.pow(3);
        ll actual = x.a;
        ll expected = 8;
        assert(actual == expected);
    }
    {
        mint x(2);
        x = x.pow(mint(0));
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }

    {
        mint x = 1;
        mint y = 1;
        assert(x == y);
    }
    {
        mint x = 1;
        mint y = 2;
        assert(x != y);
    }
    {
        mint x = 1;
        ll y = 1;
        assert(x == y);
    }
    {
        mint x = 1;
        ll y = 2;
        assert(x != y);
    }
    {
        ll x = 1;
        mint y = 1;
        assert(x == y);
    }
    {
        ll x = 1;
        mint y = 2;
        assert(x != y);
    }

    {
        mint x;
        string in = "1\n";
        istringstream is(in);
        is >> x;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }

    {
        mint x(1);
        ostringstream os;
        os << x << endl;
        string actual = os.str();
        string expected = "1\n";
        assert(actual == expected);
    }

    {
        vm actual = {1, 2, 3};
        vector<mint> expected = {1, 2, 3};
        assert(actual == expected);
    }
}