#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define OUT(x) cout << (x) << endl;
#define OUTA(a, n) \
    REP(i, n) { cout << (a[i]) << (i == n - 1 ? "\n" : " "); }
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
    SORT(a);     \
    reverse(ALL(a))

const ll INF = 1e18;
const ll MOD = 1e9 + 7;

string precision(ll var_15, double var_x)
{
    ostringstream cout;
    // begin
    cout << fixed << setprecision(var_15) << var_x << endl;
    // end
    return cout.str();
}

int main()
{
    {
        string actual = precision(15, 3.14159265358979323846264338327950288419716939937510582097494459);
        string expected = "3.141592653589793\n";
        assert(actual == expected);
    }
    {
        string actual = precision(3, 3.14);
        string expected = "3.140\n";
        assert(actual == expected);
    }
}
