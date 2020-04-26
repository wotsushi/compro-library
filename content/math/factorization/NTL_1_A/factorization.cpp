#include "../factorization.hpp"

int main()
{
    IN(ll, n);
    vi ans;
    for (auto [p, k] : factorization(n))
    {
        REP(i, k)
        {
            ans.push_back(p);
        }
    }
    SORT(ans);
    cout << n << ": ";
    JOUT(ALL(ans), " ", cout) << endl;
}