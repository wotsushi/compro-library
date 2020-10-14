#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/ITP1/1/ITP1_1_A"
#include "../compress.hpp"

int main() {
  out("Hello World");
  // 圧縮後の列は0が最小値となる
  {
    vi A{2, 7, 1, 8, 2};
    vi actual = compress(A);
    vi expected{1, 2, 0, 3, 1};
    assert(actual == expected);
  }
  // 負の値が含まれていてもよい
  {
    vi A{-3, -1, -4, -1, 5};
    vi actual = compress(A);
    vi expected = vi{1, 2, 0, 2, 3};
    assert(actual == expected);
  }
}
