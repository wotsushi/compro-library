#pragma once
#include "../../core/template/template.hpp"

// begin
struct mint
{
    ll a;

    mint(ll x = 0) : a((x % MOD + MOD) % MOD) {}
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
        if (a >= MOD)
        {
            a -= MOD;
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
            a += MOD;
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
        if (rhs < 0)
        {
            rhs += MOD;
        }
        a = a * rhs % MOD;
        return *this;
    }
    mint &operator*=(mint rhs)
    {
        *this *= rhs.a;
        return *this;
    }
    mint &operator/=(ll rhs)
    {
        *this *= mint(rhs).pow(MOD - 2);
        return *this;
    }
    mint &operator/=(const mint rhs)
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

mint operator+(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) += rhs;
}
mint operator+(const ll &lhs, mint &rhs)
{
    return mint(lhs) += rhs;
}
mint operator-(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) -= rhs;
}
mint operator-(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) -= rhs;
}
mint operator-(const ll &lhs, const mint &rhs)
{
    return mint(lhs) -= rhs;
}
mint operator*(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) *= rhs;
}
mint operator*(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) *= rhs;
}
mint operator*(const ll &lhs, const mint &rhs)
{
    return mint(lhs) *= rhs;
}
mint operator/(const mint &lhs, const mint &rhs)
{
    return mint(lhs.a) /= rhs;
}
mint operator/(const mint &lhs, const ll &rhs)
{
    return mint(lhs.a) /= rhs;
}
mint operator/(const ll &lhs, const mint &rhs)
{
    return mint(lhs) /= rhs;
}
istream &operator>>(istream &is, mint &i)
{
    is >> i.a;
    return is;
}
ostream &operator<<(ostream &os, const mint &i)
{
    os << i.a;
    return os;
}
// end
