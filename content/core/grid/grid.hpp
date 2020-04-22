#pragma once
#include "../template/template.hpp"

// begin
void way4(ll i, ll j, ll H, ll W, function<void(ll, ll)> f)
{
    for (auto [di, dj] : {ii(1, 0), ii(0, 1), ii(-1, 0), ii(0, -1)})
    {
        ll u = i + di;
        ll v = j + dj;
        if (0 <= u and u < H and 0 <= v and v < W)
        {
            f(u, v);
        }
    }
}

void way8(ll i, ll j, ll H, ll W, function<void(ll, ll)> f)
{
    for (ll u = i - 1; u <= i + 1; ++u)
    {
        for (ll v = j - 1; v <= j + 1; ++v)
        {
            if (0 <= u and u < H and 0 <= v and v < W and u != i or v != j)
            {
                f(u, v);
            }
        }
    }
}
// end
