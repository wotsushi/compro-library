#include "../comb.hpp"

int main()
{
    ll n, k;
    cin >> n >> k;

    comb comb(k);
    mint ans = comb.c(k, n);
    OUT(ans);
}