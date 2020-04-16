#pragma once
#include "../../core/template/template.hpp"

// begin
struct mint
{
    ll a;

    mint(ll a = 0) : a((a % MOD + MOD) % MOD) {}
    mint pow(ll y)
    {
        ll exp = y;
        mint res = 1;
        mint p = a;
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
    mint pow(mint y)
    {
        return pow(y.a);
    }
    mint &operator+=(ll y)
    {
        a += y;
        if (a >= MOD)
        {
            a -= MOD;
        }
        return *this;
    }
    mint &operator+=(mint y)
    {
        *this += y.a;
        return *this;
    }
    mint &operator-=(ll y)
    {
        if (a < y)
        {
            a += MOD;
        }
        a -= y;
        return *this;
    }
    mint &operator-=(mint y)
    {
        *this -= y.a;
        return *this;
    }
    mint &operator*=(ll y)
    {
        if (y < 0)
        {
            y += MOD;
        }
        a = a * y % MOD;
        return *this;
    }
    mint &operator*=(mint y)
    {
        *this *= y.a;
        return *this;
    }
    mint &operator/=(ll y)
    {
        *this *= mint(y).pow(MOD - 2);
        return *this;
    }
    mint &operator/=(const mint y)
    {
        *this /= y.a;
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

mint operator+(const mint &x, const mint &y)
{
    return mint(x.a) += y;
}
mint operator+(const mint &x, const ll &y)
{
    return mint(x.a) += y;
}
mint operator+(const ll &x, mint &y)
{
    return mint(x) += y;
}
mint operator-(const mint &x, const mint &y)
{
    return mint(x.a) -= y;
}
mint operator-(const mint &x, const ll &y)
{
    return mint(x.a) -= y;
}
mint operator-(const ll &x, const mint &y)
{
    return mint(x) -= y;
}
mint operator*(const mint &x, const mint &y)
{
    return mint(x.a) *= y;
}
mint operator*(const mint &x, const ll &y)
{
    return mint(x.a) *= y;
}
mint operator*(const ll &x, const mint &y)
{
    return mint(x) *= y;
}
mint operator/(const mint &x, const mint &y)
{
    return mint(x.a) /= y;
}
mint operator/(const mint &x, const ll &y)
{
    return mint(x.a) /= y;
}
mint operator/(const ll &x, const mint &y)
{
    return mint(x) /= y;
}
bool operator==(const mint &x, const mint &y)
{
    return x.a == y.a;
}
bool operator==(const mint &x, const ll &y)
{
    return x.a == y;
}
bool operator==(const ll &x, mint &y)
{
    return x == y.a;
}
bool operator!=(const mint &x, const mint &y)
{
    return !(x == y);
}
bool operator!=(const mint &x, const ll &y)
{
    return !(x == y);
}
bool operator!=(const ll &x, mint &y)
{
    return !(x == y);
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

typedef vector<mint> vm;
// end
