#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../grid.hpp"

// begin
int main() {
  out("Hello World");
  ll H = 4;
  ll W = 3;
  vs A = vs({"ooo", "oxo", "xox", "xxx"});
  // 二次元グリッドAの各セルについて上下左右に隣接するoのセルの個数を数える
  {
    vvi actual = vec(ll, H, W);
    rep(i, H) {
      rep(j, W) {
        way4(i, j, H, W, [&](ll u, ll v) { actual[i][j] += A[u][v] == 'o'; });
      }
    }
    vvi expected =
        vvi({vi({2, 2, 2}), vi({1, 4, 1}), vi({2, 0, 2}), vi({0, 1, 0})});
    assert(actual == expected);
  }
  // 二次元グリッドAの各セルについて八方に隣接するoのセルの個数を数える
  {
    vvi actual = vec(ll, H, W);
    rep(i, H) {
      rep(j, W) {
        way8(i, j, H, W, [&](ll u, ll v) { actual[i][j] += A[u][v] == 'o'; });
      }
    }
    vvi expected =
        vvi({vi({2, 4, 2}), vi({3, 6, 3}), vi({2, 2, 2}), vi({1, 1, 1})});
    assert(actual == expected);
  }
}
// end
