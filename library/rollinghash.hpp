#pragma once
#include "template.hpp"

const ll RH_BASE[2] = {1007, 2009};
const ll RH_MOD[2] = {1000000007, 1000000009};

/**
 * 部分文字列のハッシュ値を高速に計算するデータ構造です
 */
struct rollinghash {
  vvi h;
  vvi p;

  /**
   * 指定した文字列Sの部分文字列のハッシュ値を高速計算できるように前処理します
   * 計算量: O(|S|)
   *
   * @param S 部分文字列のハッシュ値を高速計算できるようにする文字列
   */
  rollinghash(const string &S) {
    ll n = S.size();
    h.assign(2, {});
    p.assign(2, {});
    rep(k, 2) {
      h[k].assign(n + 1, 0);
      p[k].assign(n + 1, 1);
      rep(i, n) {
        h[k][i + 1] = (RH_BASE[k] * h[k][i] + S[i]) % RH_MOD[k];
        p[k][i + 1] = (RH_BASE[k] * p[k][i]) % RH_MOD[k];
      }
    }
  }

  /**
   * 部分文字列S[i:j]のハッシュ値を返します
   * 計算量: O(1)
   *
   * @param i ハッシュ値を計算する部分文字列の始端index(inclusive)
   * @param j ハッシュ値を計算する部分文字列の終端index(exclusive)
   * @return S[i:j]のハッシュ値
   */
  ii hash(ll i, ll j) {
    ll h0 = (h[0][j] - h[0][i] * p[0][j - i]) % RH_MOD[0];
    ll h1 = (h[1][j] - h[1][i] * p[1][j - i]) % RH_MOD[1];
    return {(h0 + RH_MOD[0]) % RH_MOD[0], (h1 + RH_MOD[1]) % RH_MOD[1]};
  }
};
