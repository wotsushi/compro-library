#include "matrix.hpp"

// begin
int main()
{
    // 各要素が0である2次の正方行列を生成
    {
        matrix<ll> actual(2);
        matrix<ll> expected({{0, 0}, {0, 0}});
        assert(actual == expected);
    }
    // 各要素が0である2*3の行列を生成
    {
        matrix<ll> actual(2, 3);
        matrix<ll> expected({{0, 0, 0}, {0, 0, 0}});
        assert(actual == expected);
    }
    // 行列を加算代入
    {
        matrix<ll> actual({{1, 2}, {3, 4}});
        actual += matrix<ll>({{5, 6}, {7, 8}});
        matrix<ll> expected({{6, 8}, {10, 12}});
        assert(actual == expected);
    }
    // 行列を減算代入
    {
        matrix<ll> actual({{6, 8}, {10, 12}});
        actual -= matrix<ll>({{5, 6}, {7, 8}});
        matrix<ll> expected({{1, 2}, {3, 4}});
        assert(actual == expected);
    }
    // 行列と実数の積を代入
    {
        matrix<ll> actual({{1, 2}, {3, 4}});
        actual *= 2;
        matrix<ll> expected({{2, 4}, {6, 8}});
        assert(actual == expected);
    }
    // 行列を乗算代入
    {
        matrix<ll> actual({{1, 2}, {3, 4}});
        actual *= matrix<ll>({{1, 1}, {1, 1}});
        matrix<ll> expected({{3, 3}, {7, 7}});
        assert(actual == expected);
    }
    // 行列と実数の商を代入
    {
        matrix<ll> actual({{2, 4}, {6, 8}});
        actual /= 2;
        matrix<ll> expected({{1, 2}, {3, 4}});
        assert(actual == expected);
    }
    // 0行目(0-indexed)のベクトルを取得
    {
        vi actual = matrix<ll>({{1, 2}, {3, 4}})[0];
        vi expected{1, 2};
        assert(actual == expected);
    }
    // 0行目(0-indexed)のベクトルを取得
    // 取得したベクトルは参照なので変更可能
    {
        matrix<ll> actual({{1, 2}, {3, 4}});
        actual[0][0] = 0;
        matrix<ll> expected({{0, 2}, {3, 4}});
        assert(actual == expected);
    }
    // 行列同士の和
    {
        auto actual = matrix<ll>({{1, 2}, {3, 4}}) + matrix<ll>({{5, 6}, {7, 8}});
        matrix<ll> expected({{6, 8}, {10, 12}});
        assert(actual == expected);
    }
    // 行列同士の差
    {
        auto actual = matrix<ll>({{6, 8}, {10, 12}}) - matrix<ll>({{5, 6}, {7, 8}});
        matrix<ll> expected({{1, 2}, {3, 4}});
        assert(actual == expected);
    }
    // 行列と実数の積
    {
        auto actual = matrix<ll>({{1, 2}, {3, 4}}) * 2LL;
        matrix<ll> expected({{2, 4}, {6, 8}});
        assert(actual == expected);
    }
    {
        auto actual = 2LL * matrix<ll>({{1, 2}, {3, 4}});
        matrix<ll> expected({{2, 4}, {6, 8}});
        assert(actual == expected);
    }
    // 行列同士の積
    {
        auto actual = matrix<ll>({{1, 2}, {3, 4}}) * matrix<ll>({{1, 1}, {1, 1}});
        matrix<ll> expected({{3, 3}, {7, 7}});
        assert(actual == expected);
    }
    // 行列同士の商
    {
        auto actual = matrix<ll>({{2, 4}, {6, 8}}) / 2LL;
        matrix<ll> expected({{1, 2}, {3, 4}});
        assert(actual == expected);
    }
    // 行列同士のべき乗
    {
        auto actual = matrix<ll>({{1, 1}, {1, 0}}).pow(5);
        matrix<ll> expected({{8, 5}, {5, 3}});
        assert(actual == expected);
    }
}
// end