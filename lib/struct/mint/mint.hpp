#pragma once

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll var_MOD = 1e9 + 7;

// begin
struct mint
{
    ll a;

    mint(ll x = 0) : a(x % var_MOD) {}
    mint pow(ll rhs)
    {
        ll exp = rhs;
        mint res = mint(1);
        mint p = mint(a);
        while (exp)
        {
            if (exp & 1)
            {
                res *= p;
            }
            exp >>= 1;
            p *= p;
        }
        return res;
    }
    mint pow(mint rhs)
    {
        return pow(rhs.a);
    }
    mint &operator+=(ll rhs)
    {
        a += rhs;
        if (a >= var_MOD)
        {
            a -= var_MOD;
        }
        return *this;
    }
    mint &operator+=(mint rhs)
    {
        *this += rhs.a;
        return *this;
    }
    mint &operator-=(ll rhs)
    {
        if (a < rhs)
        {
            a += var_MOD;
        }
        a -= rhs;
        return *this;
    }
    mint &operator-=(mint rhs)
    {
        *this -= rhs.a;
        return *this;
    }
    mint &operator*=(ll rhs)
    {
        a = a * rhs % var_MOD;
        return *this;
    }
    mint &operator*=(mint rhs)
    {
        *this *= rhs.a;
        return *this;
    }
    mint &operator/=(ll rhs)
    {
        *this *= mint(rhs).pow(var_MOD - 2);
        return *this;
    }
    mint &operator/=(mint rhs)
    {
        *this /= rhs.a;
        return *this;
    }
    mint &operator++()
    {
        *this += 1;
        return *this;
    }
    mint &operator++(int)
    {
        *this += 1;
        return *this;
    }
    mint &operator--()
    {
        *this -= 1;
        return *this;
    }
    mint &operator--(int)
    {
        *this -= 1;
        return *this;
    }
};

mint operator+(mint &lhs, mint &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(mint &lhs, ll &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(ll &lhs, mint &rhs)
{
    return mint(lhs) += rhs;
}
mint operator-(mint &lhs, mint &rhs)
{
    return mint(lhs.a) -= rhs;
}
mint operator-(mint &lhs, ll &rhs)
{
    return mint(lhs.a) -= rhs;
}
mint operator-(ll &lhs, mint &rhs)
{
    return mint(lhs) -= rhs;
}
mint operator*(mint &lhs, mint &rhs)
{
    return mint(lhs.a) *= rhs;
}
mint operator*(mint &lhs, ll &rhs)
{
    return mint(lhs.a) *= rhs;
}
mint operator*(ll &lhs, mint &rhs)
{
    return mint(lhs) *= rhs;
}
mint operator/(mint &lhs, mint &rhs)
{
    return mint(lhs.a) /= rhs;
}
mint operator/(mint &lhs, ll &rhs)
{
    return mint(lhs.a) /= rhs;
}
mint operator/(ll &lhs, mint &rhs)
{
    return mint(lhs) /= rhs;
}
ostream &operator<<(ostream &os, mint &i)
{
    os << i.a;
    return os;
}
// end
