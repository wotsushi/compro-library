#include "../comb.hpp"

int main()
{
    ll n, k;
    cin >> n >> k;

    comb comb(n + k);
    mint ans = comb.h(k, n);
    OUT(ans);
}