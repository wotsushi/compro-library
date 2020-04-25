#include "mint.hpp"

// begin
int main()
{
    // デフォルト値は0
    {
        mint x;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    // 通常のllと同様に初期化できる
    {
        mint x = 1;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // 初期化時も剰余をとる
    {
        mint x = 1e9 + 7;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    // 負の値でも初期化できる
    {
        mint x(-1);
        ll actual = x.a;
        ll expected = 1e9 + 6;
        assert(actual == expected);
    }
    // mintにllを加算代入できる
    {
        mint x(1e9 + 6);
        x += 1;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    // mintにmintを加算代入できる
    {
        mint x;
        x += mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // mint同士で加算できる
    {
        mint x = mint(1) + mint(1);
        ll actual = x.a;
        ll expected = 2;
        assert(actual == expected);
    }
    // mintとllを加算できる
    {
        mint x = mint(1) + 1;
        ll actual = x.a;
        ll expected = 2;
        assert(actual == expected);
    }
    // llとmintを加算できる
    {
        mint x = 1 + mint(1);
        ll actual = x.a;
        ll expected = 2;
        assert(actual == expected);
    }
    // mintにllを減算代入できる
    {
        mint x;
        x -= 1;
        ll actual = x.a;
        ll expected = 1e9 + 6;
        assert(actual == expected);
    }
    // mintにmintを減算代入できる
    {
        mint x(1);
        x -= mint(1);
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    // mint同士を減算できる
    {
        mint x = mint(1) - mint(1);
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    // mintとllを減算できる
    {
        mint x = mint(1) - 1;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    // llとmintを減算できる
    {
        mint x = 1 - mint(1);
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    // mintにllを乗算代入できる
    {
        mint x(1);
        x *= -1;
        ll actual = x.a;
        ll expected = 1e9 + 6;
        assert(actual == expected);
    }
    // mintにmintを乗算代入できる
    {
        mint x(5e8 + 4);
        x *= mint(2);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // mint同士で乗算できる
    {
        mint x = mint(1) * mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // mintとllで乗算できる
    {
        mint x = mint(1) * 1;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // llとmintで乗算できる
    {
        mint x = 1 * mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // mintにllを除算代入できる
    {
        mint x(2);
        x /= -2;
        ll actual = x.a;
        ll expected = 1e9 + 6;
        assert(actual == expected);
    }
    // mintにmintを除算代入できる
    {
        mint x(1);
        x /= mint(2);
        ll actual = x.a;
        ll expected = 5e8 + 4;
        assert(actual == expected);
    }
    // mint同士で除算できる
    {
        mint x = mint(1) / mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // mintとllで除算できる
    {
        mint x = mint(1) / 1;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // llとmintで除算できる
    {
        mint x = 1 / mint(1);
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // mintを後置インクリメントできる
    {
        mint x;
        x++;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // mintを前置インクリメントできる
    {
        mint x;
        ++x;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // mintを後置デクリメントできる
    {
        mint x(1);
        x--;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    // mintを前置デクリメントできる
    {
        mint x(1);
        --x;
        ll actual = x.a;
        ll expected = 0;
        assert(actual == expected);
    }
    // mintのll乗を計算できる
    {
        mint x(2);
        x = x.pow(3);
        ll actual = x.a;
        ll expected = 8;
        assert(actual == expected);
    }
    // mintのmint乗を計算できる
    {
        mint x(2);
        x = x.pow(mint(0));
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // mint同士の同値比較
    {
        mint x = 1;
        mint y = 1;
        assert(x == y);
    }
    {
        mint x = 1;
        mint y = 2;
        assert(x != y);
    }
    // mintとllの同値比較
    {
        mint x = 1;
        ll y = 1;
        assert(x == y);
    }
    {
        mint x = 1;
        ll y = 2;
        assert(x != y);
    }
    {
        ll x = 1;
        mint y = 1;
        assert(x == y);
    }
    {
        ll x = 1;
        mint y = 2;
        assert(x != y);
    }
    // istringstream(cinなど)からmintに値を入力できる
    {
        mint x;
        string in = "1\n";
        istringstream is(in);
        is >> x;
        ll actual = x.a;
        ll expected = 1;
        assert(actual == expected);
    }
    // ostringstream(coutなど)にmintの値を出力できる
    {
        mint x(1);
        ostringstream os;
        os << x << endl;
        string actual = os.str();
        string expected = "1\n";
        assert(actual == expected);
    }
    // vm = vector<mint>
    {
        vm actual = {1, 2, 3};
        vector<mint> expected = {1, 2, 3};
        assert(actual == expected);
    }
}
// end