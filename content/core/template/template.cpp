#include "template.hpp"

// begin
int main()
{
    // pq_asc
    {
        pq_asc<ll> q;
        q.push(3);
        q.push(1);
        q.push(4);
        ll actual1 = q.top();
        q.pop();
        ll expected1 = 1;
        assert(actual1 == expected1);
        ll actual2 = q.top();
        q.pop();
        ll expected2 = 3;
        assert(actual2 == expected2);
        ll actual3 = q.top();
        q.pop();
        ll expected3 = 4;
        assert(actual3 == expected3);
    }
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
    // vvi
    {
        vvi actual{{1, 2, 3}, {4, 5}};
        vector<vi> expected = {{1, 2, 3}, {4, 5}};
        assert(actual == expected);
    }
    // ii
    {
        ii actual(1, 2);
        pair<ll, ll> expected = make_pair(1LL, 2LL);
        assert(actual == expected);
    }
    // vii
    {
        vii actual{{1, 2}, {3, 4}};
        vector<ii> expected = {{1, 2}, {3, 4}};
        assert(actual == expected);
    }
    // vs
    {
        vs actual{"foo", "bar"};
        vector<string> expected = {"foo", "bar"};
        assert(actual == expected);
    }
    // REP
    {
        vi actual;
        REP(i, 3)
        {
            actual.push_back(i);
        }
        vi expected{0, 1, 2};
        assert(actual == expected);
    }
    // REP1
    {
        vi actual;
        REP1(i, 3)
        {
            actual.push_back(i);
        }
        vi expected{1, 2, 3};
        assert(actual == expected);
    }
    // FOR
    {
        vi actual(3);
        FOR(e, actual)
        {
            e = 3;
        }
        vi expected{3, 3, 3};
        assert(actual == expected);
    }
    // CH
    {
        ll actual = 0;
        CH(max, actual, 3LL);
        ll expected = 3;
        assert(actual == expected);
    }
    // IN
    {
        istringstream cin("1");
        IN(ll, x);
        ll actual = x;
        ll expected = 1;
        assert(actual == expected);
    }
    // AIN
    {
        istringstream cin("1 2 3");
        ll N = 3;
        AIN(ll, A, N);
        vi actual = A;
        vi expected = {1, 2, 3};
        assert(actual == expected);
    }
    // A2IN
    {
        istringstream cin("1 a\n2 b\n3 c");
        ll N = 3;
        A2IN(ll, A, string, B, N);
        vi actual1 = A;
        vi expected1 = {1, 2, 3};
        assert(actual1 == expected1);
        vs actual2 = B;
        vs expected2 = {"a", "b", "c"};
        assert(actual2 == expected2);
    }
    // OUT
    {
        ostringstream cout;
        OUT(1);
        string actual = cout.str();
        string expected = "1\n";
        assert(actual == expected);
    }
    // JOUT
    {
        ostringstream cout;
        vi a{3, 1, 4};
        JOUT(ALL(a), cout) << endl;
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
    // YES
    {
        ostringstream cout;
        YES(1 < 2, "Yes", "No", cout);
        string actual = cout.str();
        string expected = "Yes\n";
        assert(actual == expected);
    }
    {
        ostringstream cout;
        YES(2 < 1, "Yes", "No", cout);
        string actual = cout.str();
        string expected = "No\n";
        assert(actual == expected);
    }
    // DUMP
    {
        ostringstream cout;
        ll x = 1;
        DUMP(x);
        string actual = cout.str();
        string expected = "x = 1\n";
        assert(actual == expected);
    }
    {
        ostringstream cout;
        ii p = ii(1, 2);
        DUMP(p);
        string actual = cout.str();
        string expected = "p = (1, 2)\n";
        assert(actual == expected);
    }
    {
        ostringstream cout;
        vi a = {1, 2, 3};
        DUMP(a);
        string actual = cout.str();
        string expected = "a = [1, 2, 3]\n";
        assert(actual == expected);
    }
    // DUMPA
    {
        ostringstream cout;
        vector<vi> dp = {{1, 2}, {3, 4}};
        DUMPA(dp);
        string actual = cout.str();
        string expected = "dp = {[1, 2], [3, 4]}\n";
        assert(actual == expected);
    }
    {
        ostringstream cout;
        map<string, ll> m = {{"a", 1}, {"b", 2}};
        DUMPA(m);
        string actual = cout.str();
        string expected = "m = {(a, 1), (b, 2)}\n";
        assert(actual == expected);
    }
    {
        ostringstream cout;
        set<ll> s = {1, 2, 3};
        DUMPA(s);
        string actual = cout.str();
        string expected = "s = {1, 2, 3}\n";
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
        // 2INFはオーバーフローはしない
        assert(2 * x > INF);
    }

    return 0;
}
// end
