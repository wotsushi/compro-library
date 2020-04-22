#include "grid.hpp"

int main()
{
    ll H = 4;
    ll W = 3;
    vs A = vs({"ooo", "oxo", "xox", "xxx"});
    {
        vvi actual = vvi(H, vi(W));
        REP(i, H)
        {
            REP(j, W)
            {
                way4(i, j, H, W, [&](ll u, ll v) {
                    actual[i][j] += A[u][v] == 'o';
                });
            }
        }
        vvi expected = vvi({vi({2, 2, 2}), vi({1, 4, 1}), vi({2, 0, 2}), vi({0, 1, 0})});
        assert(actual == expected);
    }
    {
        vvi actual = vvi(H, vi(W));
        REP(i, H)
        {
            REP(j, W)
            {
                way8(i, j, H, W, [&](ll u, ll v) {
                    actual[i][j] += A[u][v] == 'o';
                });
            }
        }
        vvi expected = vvi({vi({2, 4, 2}), vi({3, 6, 3}), vi({2, 2, 2}), vi({1, 1, 1})});
        assert(actual == expected);
    }
}