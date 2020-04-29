#include "../lca.hpp"

// begin
int main()
{
    IN(ll, n);
    vi k(n);
    vvi c(n);
    REP(i, n)
    {
        cin >> k[i];
        c[i] = vi(k[i]);
        REP(j, k[i])
        {
            cin >> c[i][j];
        }
    }
    graph<ll> G(n - 1);
    REP(i, n)
    {
        REP(j, k[i])
        {
            G.add(i, c[i][j]);
        }
    }
    tree<ll> T(G, 0);
    lca lca(T);
    IN(ll, q);
    REP(i, q)
    {
        IN(ll, u);
        IN(ll, v);
        OUT(lca(u, v));
    }
}
// end