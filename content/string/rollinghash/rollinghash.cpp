#include "rollinghash.hpp"

// begin
int main()
{
    rollinghash rh("abcabd");
    // 同じ文字列のハッシュ値は等しい
    {
        bool actual = rh.hash(0, 2) == rh.hash(3, 5);
        bool expected = true;
        assert(actual == expected);
    }
    // 異なる文字列のハッシュ値は異なる確率が十分に大きい
    {
        bool actual = rh.hash(0, 3) == rh.hash(3, 6);
        bool expected = false;
        assert(actual == expected);
    }
}
// end