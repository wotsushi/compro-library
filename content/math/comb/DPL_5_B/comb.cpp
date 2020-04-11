#include "../comb.hpp"

int main()
{
    ll n, k;
    cin >> n >> k;

    comb comb(k);
    mint ans = comb.p(k, n);
    OUT(ans);
}