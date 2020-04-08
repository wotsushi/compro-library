#include "../mint.hpp"

int main()
{
    mint n, k;
    cin >> n >> k;

    mint ans(1);
    for (ll i = 0; i < k.a - 1; ++i)
    {
        ans *= n + k - 1 - i;
        ans /= i + 1;
    }

    cout << ans << endl;
}