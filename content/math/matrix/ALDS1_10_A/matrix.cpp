#include "../matrix.hpp"

int main()
{
    IN(ll, n);
    matrix<ll> F({{1, 1}, {1, 0}});
    OUT(F.pow(n)[0][0]);
}