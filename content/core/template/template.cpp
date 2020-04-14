#include "template.hpp"

int main()
{
    // ll
    {
        ll actual = 12345678901;
        long long expected = 12345678901;
        assert(actual == expected);
    }
    // vi
    {
        vi actual{3, 1, 4};
        vector<ll> expected = {3, 1, 4};
        assert(actual == expected);
    }
    // ii
    {
        ii actual(1, 2);
        pair<ll, ll> expected = make_pair(1LL, 2LL);
        assert(actual == expected);
    }
    // REP
    {
        vector<ll> actual;
        REP(i, 3)
        {
            actual.push_back(i);
        }
        vector<ll> expected{0, 1, 2};
        assert(actual == expected);
    }
    // REP1
    {
        vector<ll> actual;
        REP1(i, 3)
        {
            actual.push_back(i);
        }
        vector<ll> expected{1, 2, 3};
        assert(actual == expected);
    }
    // FOR
    {
        vector<ll> actual(3);
        FOR(e, actual)
        {
            e = 3;
        }
        vector<ll> expected{3, 3, 3};
        assert(actual == expected);
    }
    // OUT
    {
        ostringstream cout;
        OUT(1);
        string actual = cout.str();
        string expected = "1\n";
        assert(actual == expected);
    }
    // OUTA
    {
        ostringstream cout;
        vi a{3, 1, 4};
        OUTA(a);
        string actual = cout.str();
        string expected = "3 1 4\n";
        assert(actual == expected);
    }
    // FOUT
    {
        ostringstream cout;
        FOUT(3.14159265358979323846264338327950288419716939937510582097494459);
        string actual = cout.str();
        string expected = "3.141592653589793\n";
        assert(actual == expected);
    }
    {
        ostringstream cout;
        FOUT(3.14);
        string actual = cout.str();
        string expected = "3.140000000000000\n";
        assert(actual == expected);
    }
    // ALL
    {
        vi a{1, 1, 2, 3, 5, 8};
        ll actual = *lower_bound(ALL(a), 4);
        ll expected = 5;
        assert(actual == expected);
    }
    // SORT
    {
        vi actual{3, 1, 4};
        SORT(actual);
        vi expected{1, 3, 4};
        assert(actual == expected);
    }
    // RSORT
    {
        vi actual{3, 1, 4};
        RSORT(actual);
        vi expected{4, 3, 1};
        assert(actual == expected);
    }
    // INF
    {
        assert(INF > 1e15);
        ll x = INF;
        // オーバーフローしないかテスト
        assert(2 * x > INF);
    }

    return 0;
}
// end
