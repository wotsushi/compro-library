#pragma once
#include "template.hpp"

const vii GRID_WAY4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

/**
 * グリッド上を上下左右に移動した後に指定した処理を実行します。
 * グリッド場外に移動することはありません
 *
 * @param i 現在地の行番号
 * @param j 現在地の列番号
 * @param H グリッドの行数
 * @param W グリッドの列数
 * @param f (i, j)から上下左右に移動した後のセルを(u, v)としたときにf(u,
 * v)が実行される
 */
void way4(ll i, ll j, ll H, ll W, function<void(ll, ll)> f) {
  for (auto [di, dj] : GRID_WAY4) {
    ll u = i + di;
    ll v = j + dj;
    if (0 <= u and u < H and 0 <= v and v < W) {
      f(u, v);
    }
  }
}

/**
 * グリッド上を四方八方に移動した後に指定した処理を実行します。
 * グリッド場外に移動することはありません
 *
 * @param i 現在地の行番号
 * @param j 現在地の列番号
 * @param H グリッドの行数
 * @param W グリッドの列数
 * @param f (i, j)から四方八方に移動した後のセルを(u, v)としたときにf(u,
 * v)が実行される
 */
void way8(ll i, ll j, ll H, ll W, function<void(ll, ll)> f) {
  for (ll u = i - 1; u <= i + 1; ++u) {
    for (ll v = j - 1; v <= j + 1; ++v) {
      if (0 <= u and u < H and 0 <= v and v < W and (u != i or v != j)) {
        f(u, v);
      }
    }
  }
}
