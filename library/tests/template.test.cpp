#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../template.hpp"

// begin
int main() {
  out("Hello World");
  // ll
  {
    ll actual = 12345678901;
    long long expected = 12345678901;
    assert(actual == expected);
  }
  // vec
  {
    vec<double> actual{1.5, 2.5};
    vector<double> expected = {1.5, 2.5};
    assert(actual == expected);
  }
  // vec2
  {
    vec2<double> actual{{1.5, 2.5}, {3.5}};
    vector<vector<double>> expected{{1.5, 2.5}, {3.5}};
    assert(actual == expected);
  }
  // vec3
  {
    vec3<double> actual{{{1.5, 2.5}, {3.5}}, {{4.5}}};
    vector<vector<vector<double>>> expected{{{1.5, 2.5}, {3.5}}, {{4.5}}};
    assert(actual == expected);
  }
  // vec4
  {
    vec4<double> actual{{{{1.5, 2.5}, {3.5}}, {{4.5}}}, {{{5.5}}}};
    vector<vector<vector<vector<double>>>> expected{
        {{{1.5, 2.5}, {3.5}}, {{4.5}}}, {{{5.5}}}};
    assert(actual == expected);
  }
  // vi
  {
    vi actual{1, 2};
    vec<ll> expected{1, 2};
    assert(actual == expected);
  }
  // vvi
  {
    vvi actual{{1, 2}, {3}};
    vec2<ll> expected = {{1, 2}, {3}};
    assert(actual == expected);
  }
  // ii
  {
    ii actual{1, 2};
    pair<ll, ll> expected{1, 2};
    assert(actual == expected);
  }
  // iii
  {
    iii actual{1, 2, 3};
    tuple<ll, ll, ll> expected{1, 2, 3};
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
  // vb
  {
    vb actual{true, false};
    vector<bool> expected = {true, false};
    assert(actual == expected);
  }
  // pq
  {
    pq<ll> q;
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
  // vec
  {
    auto actual = vec(ll, 4);
    vector<ll> expected = {0, 0, 0, 0};
    assert(actual == expected);
  }
  {
    auto actual = vec(ll, 4, 3);
    vector<vector<ll>> expected{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    assert(actual == expected);
  }
  {
    auto actual = vec(ll, 4, 3, 2);
    vector<vector<vector<ll>>> expected{{{0, 0}, {0, 0}, {0, 0}},
                                        {{0, 0}, {0, 0}, {0, 0}},
                                        {{0, 0}, {0, 0}, {0, 0}},
                                        {{0, 0}, {0, 0}, {0, 0}}};
    assert(actual == expected);
  }
  {
    auto actual = vec(ll, 4, 3, 2, 1);
    vector<vector<vector<vector<ll>>>> expected{
        {{{0}, {0}}, {{0}, {0}}, {{0}, {0}}},
        {{{0}, {0}}, {{0}, {0}}, {{0}, {0}}},
        {{{0}, {0}}, {{0}, {0}}, {{0}, {0}}},
        {{{0}, {0}}, {{0}, {0}}, {{0}, {0}}}};
    assert(actual == expected);
  }
  // vecv
  {
    auto actual = vecv(ll, 4, -1);
    vector<ll> expected{-1, -1, -1, -1};
    assert(actual == expected);
  }
  {
    auto actual = vecv(ll, 4, 3, -1);
    vector<vector<ll>> expected{
        {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
    assert(actual == expected);
  }
  {
    auto actual = vecv(ll, 4, 3, 2, -1);
    vector<vector<vector<ll>>> expected{{{-1, -1}, {-1, -1}, {-1, -1}},
                                        {{-1, -1}, {-1, -1}, {-1, -1}},
                                        {{-1, -1}, {-1, -1}, {-1, -1}},
                                        {{-1, -1}, {-1, -1}, {-1, -1}}};
    assert(actual == expected);
  }
  {
    auto actual = vecv(ll, 4, 3, 2, 1, -1);
    vector<vector<vector<vector<ll>>>> expected{
        {{{-1}, {-1}}, {{-1}, {-1}}, {{-1}, {-1}}},
        {{{-1}, {-1}}, {{-1}, {-1}}, {{-1}, {-1}}},
        {{{-1}, {-1}}, {{-1}, {-1}}, {{-1}, {-1}}},
        {{{-1}, {-1}}, {{-1}, {-1}}, {{-1}, {-1}}}};
    assert(actual == expected);
  }
  // def
  {
    auto f = def([&](auto &&f, ll n) -> ll {
      if (n == 0) {
        return 1;
      } else {
        return n * f(n - 1);
      }
    });
    ll actual = f(3);
    ll expected = 6;
    assert(actual == expected);
  }
  // rep
  {
    vi actual;
    rep(i, 3) { actual.push_back(i); }
    vi expected{0, 1, 2};
    assert(actual == expected);
  }
  {
    vi actual;
    rep(i, 3, 5) { actual.push_back(i); }
    vi expected{3, 4};
    assert(actual == expected);
  }
  // repi
  {
    vi actual;
    repi(i, 3) { actual.push_back(i); }
    vi expected{1, 2, 3};
    assert(actual == expected);
  }
  {
    vi actual;
    repi(i, 3, 5) { actual.push_back(i); }
    vi expected{3, 4, 5};
    assert(actual == expected);
  }
  // rrep
  {
    vi actual;
    rrep(i, 3) { actual.push_back(i); }
    vi expected{2, 1, 0};
    assert(actual == expected);
  }
  {
    vi actual;
    rrep(i, 3, 5) { actual.push_back(i); }
    vi expected{4, 3};
    assert(actual == expected);
  }
  // rrepi
  {
    vi actual;
    rrepi(i, 3) { actual.push_back(i); }
    vi expected{3, 2, 1};
    assert(actual == expected);
  }
  {
    vi actual;
    rrepi(i, 3, 5) { actual.push_back(i); }
    vi expected{5, 4, 3};
    assert(actual == expected);
  }
  // each
  {
    vi actual(3);
    each(e, actual) { e = 3; }
    vi expected{3, 3, 3};
    assert(actual == expected);
  }
  // chmin
  {
    ll x = 2;
    bool actual = chmin(x, 1LL);
    ll expected_x = 1;
    bool expected = true;
    assert(x == expected_x);
    assert(actual == expected);
  }
  {
    ll x = 1;
    bool actual = chmin(x, 2LL);
    ll expected_x = 1;
    bool expected = false;
    assert(x == expected_x);
    assert(actual == expected);
  }
  // chmax
  {
    ll x = 1;
    bool actual = chmax(x, 2LL);
    ll expected_x = 2;
    bool expected = true;
    assert(x == expected_x);
    assert(actual == expected);
  }
  {
    ll x = 2;
    bool actual = chmax(x, 1LL);
    ll expected_x = 2;
    bool expected = false;
    assert(x == expected_x);
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
  // in
  {
    istringstream cin("1.5");
    in(double, a);
    double actual = a;
    double expected = 1.5;
    assert(actual == expected);
  }
  {
    istringstream cin("1.5 2.5");
    in(double, a, b);
    pair<double, double> actual{a, b};
    pair<double, double> expected{1.5, 2.5};
    assert(actual == expected);
  }
  {
    istringstream cin("1.5 2.5 3.5");
    in(double, a, b, c);
    tuple<double, double, double> actual{a, b, c};
    tuple<double, double, double> expected{1.5, 2.5, 3.5};
    assert(actual == expected);
  }
  {
    istringstream cin("1.5 2.5 3.5 4.5");
    in(double, a, b, c, d);
    tuple<double, double, double, double> actual{a, b, c, d};
    tuple<double, double, double, double> expected{1.5, 2.5, 3.5, 4.5};
    assert(actual == expected);
  }
  // ll
  {
    istringstream cin("1");
    ll(a);
    ll actual = a;
    ll expected = 1;
    assert(actual == expected);
  }
  {
    istringstream cin("1 2");
    ll(a, b);
    ii actual{a, b};
    ii expected{1, 2};
    assert(actual == expected);
  }
  {
    istringstream cin("1 2 3");
    ll(a, b, c);
    iii actual{a, b, c};
    iii expected{1, 2, 3};
    assert(actual == expected);
  }
  {
    istringstream cin("1 2 3 4");
    ll(a, b, c, d);
    tuple<ll, ll, ll, ll> actual{a, b, c, d};
    tuple<ll, ll, ll, ll> expected{1, 2, 3, 4};
    assert(actual == expected);
  }
  // STR
  {
    istringstream cin("foo");
    STR(a);
    string actual = a;
    string expected = "foo";
    assert(actual == expected);
  }
  // STR2
  {
    istringstream cin("foo bar");
    STR(a, b);
    pair<string, string> actual{a, b};
    pair<string, string> expected{"foo", "bar"};
    assert(actual == expected);
  }
  // STR3
  {
    istringstream cin("foo bar baz");
    STR(a, b, c);
    tuple<string, string, string> actual{a, b, c};
    tuple<string, string, string> expected{"foo", "bar", "baz"};
    assert(actual == expected);
  }
  // STR4
  {
    istringstream cin("foo bar baz qux");
    STR(a, b, c, d);
    tuple<string, string, string, string> actual{a, b, c, d};
    tuple<string, string, string, string> expected{"foo", "bar", "baz", "qux"};
    assert(actual == expected);
  }
  // vin
  {
    istringstream cin("1 2 3");
    ll N = 3;
    vin(ll, A, N);
    vi actual = A;
    vi expected{1, 2, 3};
    assert(actual == expected);
  }
  {
    istringstream cin("1 2\n3 4\n5 6");
    ll N = 3;
    vin(ll, A, B, N);
    vi actual1 = A;
    vi expected1{1, 3, 5};
    assert(actual1 == expected1);
    vi actual2 = B;
    vi expected2{2, 4, 6};
    assert(actual2 == expected2);
  }
  {
    istringstream cin("1 2 3\n4 5 6\n7 8 9");
    ll N = 3;
    vin(ll, A, B, C, N);
    vi actual1 = A;
    vi expected1{1, 4, 7};
    assert(actual1 == expected1);
    vi actual2 = B;
    vi expected2{2, 5, 8};
    assert(actual2 == expected2);
    vi actual3 = C;
    vi expected3{3, 6, 9};
    assert(actual3 == expected3);
  }
  {
    istringstream cin("1 2 3 4\n5 6 7 8\n9 10 11 12");
    ll N = 3;
    vin(ll, A, B, C, D, N);
    vi actual1 = A;
    vi expected1{1, 5, 9};
    assert(actual1 == expected1);
    vi actual2 = B;
    vi expected2{2, 6, 10};
    assert(actual2 == expected2);
    vi actual3 = C;
    vi expected3{3, 7, 11};
    assert(actual3 == expected3);
    vi actual4 = D;
    vi expected4{4, 8, 12};
    assert(actual4 == expected4);
  }
  // vll
  {
    istringstream cin("1 2 3");
    ll N = 3;
    vll(A, N);
    vi actual = A;
    vi expected{1, 2, 3};
    assert(actual == expected);
  }
  {
    istringstream cin("1 2\n3 4\n5 6");
    ll N = 3;
    vll(A, B, N);
    vi actual1 = A;
    vi expected1{1, 3, 5};
    assert(actual1 == expected1);
    vi actual2 = B;
    vi expected2{2, 4, 6};
    assert(actual2 == expected2);
  }
  // vvll
  {
    istringstream cin("1 2 3\n4 5 6\n7 8 9");
    ll N = 3;
    vvll(A, N);
    vvi actual = A;
    vvi expected{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    assert(actual == expected);
  }
  // out
  {
    ostringstream cout;
    out(1);
    string actual = cout.str();
    string expected = "1\n";
    assert(actual == expected);
  }
  // fout
  {
    ostringstream cout;
    fout(3.14159265358979323846264338327950288419716939937510582097494459);
    string actual = cout.str();
    string expected = "3.141592653589793\n";
    assert(actual == expected);
  }
  // jout
  {
    ostringstream cout;
    vi a{3, 1, 4};
    jout(ALL(a), " ", cout) << endl;
    string actual = cout.str();
    string expected = "3 1 4\n";
    assert(actual == expected);
  }
  {
    ostringstream cout;
    fout(3.14);
    string actual = cout.str();
    string expected = "3.140000000000000\n";
    assert(actual == expected);
  }
  // yes
  {
    ostringstream cout;
    yes(1 < 2, "Yes", "No", cout);
    string actual = cout.str();
    string expected = "Yes\n";
    assert(actual == expected);
  }
  {
    ostringstream cout;
    yes(2 < 1, "Yes", "No", cout);
    string actual = cout.str();
    string expected = "No\n";
    assert(actual == expected);
  }
  // dump
  {
    ostringstream cout;
    ll a = 1;
    dump(a);
    string actual = cout.str();
    string expected = "a = 1\n";
    assert(actual == expected);
  }
  {
    ostringstream cout;
    ll a = 1;
    ii b{2, 3};
    dump(a, b);
    string actual = cout.str();
    string expected = "a = 1 b = (2, 3)\n";
    assert(actual == expected);
  }
  {
    ostringstream cout;
    ll a = 1;
    ii b{2, 3};
    iii c{4, 5, 6};
    dump(a, b, c);
    string actual = cout.str();
    string expected = "a = 1 b = (2, 3) c = (4, 5, 6)\n";
    assert(actual == expected);
  }
  {
    ostringstream cout;
    ll a = 1;
    ii b{2, 3};
    iii c{4, 5, 6};
    vi d{7, 8, 9, 10};
    dump(a, b, c, d);
    string actual = cout.str();
    string expected = "a = 1 b = (2, 3) c = (4, 5, 6) d = [7, 8, 9, 10]\n";
    assert(actual == expected);
  }
  {
    ostringstream cout;
    ll a = 1;
    ii b{2, 3};
    iii c{4, 5, 6};
    vi d{7, 8, 9, 10};
    string e = "foo";
    dump(a, b, c, d, e);
    string actual = cout.str();
    string expected =
        "a = 1 b = (2, 3) c = (4, 5, 6) d = [7, 8, 9, 10] e = foo\n";
    assert(actual == expected);
  }
  {
    ostringstream cout;
    set<ll> S{1, 2, 3};
    dump(S);
    string actual = cout.str();
    string expected = "S = {1, 2, 3}\n";
    assert(actual == expected);
  }
  {
    ostringstream cout;
    map<string, ll> dp{{"foo", 3}, {"bar", 1}};
    dump(dp);
    string actual = cout.str();
    string expected = "dp = {(bar, 1), (foo, 3)}\n";
    assert(actual == expected);
  }
  {
    ostringstream cout;
    modint1000000007 x = 1;
    out(x);
    string actual = "1\n";
    string expected = "1\n";
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
