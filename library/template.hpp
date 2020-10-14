#pragma once

#define G3(_1, _2, _3, F, ...) F
#define G4(_1, _2, _3, _4, F, ...) F
#define G5(_1, _2, _3, _4, _5, F, ...) F
#define G6(_1, _2, _3, _4, _5, _6, F, ...) F
#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

template <typename T>
using vec = vector<T>;
template <typename T>
using vec2 = vec<vec<T>>;
template <typename T>
using vec3 = vec<vec2<T>>;
template <typename T>
using vec4 = vec<vec3<T>>;
using vi = vec<ll>;
using vvi = vec2<ll>;
using ii = pair<ll, ll>;
using iii = tuple<ll, ll, ll>;
using vii = vec<ii>;
using vs = vec<string>;
using vb = vec<bool>;
/**
 * 昇順の優先度付きキューです
 */
template <typename T>
using pq = priority_queue<T, vector<T>, greater<T>>;
#define VEC1(T, n1) vec<T>(n1)
#define VEC2(T, n1, n2) vec2<T>(n1, VEC1(T, n2))
#define VEC3(T, n1, n2, n3) vec3<T>(n1, VEC2(T, n2, n3))
#define VEC4(T, n1, n2, n3, n4) vec4<T>(n1, VEC3(T, n2, n3, n4))
/**
 * vec(T, n_1, ..., n_k)で0埋めされたk次元(1 <= k <=
 * 4)のT型ベクトルを作成します。次元iの長さはn_iです
 */
#define vec(...) G5(__VA_ARGS__, VEC4, VEC3, VEC2, VEC1)(__VA_ARGS__)
#define VEC1V(T, n1, v) vec<T>(n1, v)
#define VEC2V(T, n1, n2, v) vec2<T>(n1, VEC1V(T, n2, v))
#define VEC3V(T, n1, n2, n3, v) vec3<T>(n1, VEC2V(T, n2, n3, v))
#define VEC4V(T, n1, n2, n3, n4, v) vec4<T>(n1, VEC3V(T, n2, n3, n4, v))
/**
 * vec(T, n_1, ..., n_k, x)で各値がxであるk次元(1 <= k <=
 * 4)のT型ベクトルを作成します。次元iの長さはn_iです
 */
#define vecv(...) G6(__VA_ARGS__, VEC4V, VEC3V, VEC2V, VEC1V)(__VA_ARGS__)
#define REP0(i, n) for (ll i = 0; i < (n); ++i)
#define REP(i, j, n) for (ll i = (j); i < (n); ++i)
/**
 * rep(i, n)はi = 0, 1, ..., n - 1に関するループブロックです。
 * rep(i, j, n)はi = j, j + 1, ..., n - 1に関するループブロックです
 */
#define rep(...) G3(__VA_ARGS__, REP, REP0)(__VA_ARGS__)
#define REP1(i, n) for (ll i = 1; i <= (n); ++i)
#define REPI(i, j, n) for (ll i = (j); i <= (n); ++i)
/**
 * repi(i, n)はi = 1, 2, ..., nに関するループブロックです。
 * rep(i, j, n)はi = j, j + 1, ..., nに関するループブロックです
 */
#define repi(...) G3(__VA_ARGS__, REPI, REP1)(__VA_ARGS__)
#define RREP0(i, n) for (ll i = (n)-1; i >= 0; --i)
#define RREP(i, j, n) for (ll i = (n)-1; i >= (j); --i)
/**
 * repの逆順であるループブロックです。つまり、
 * rrep(i, n)はi = n - 1, n - 2, ..., 0に関するループブロックです。
 * rrep(i, j, n)はi = n - 1, n - 2, ..., jに関するループブロックです
 */
#define rrep(...) G3(__VA_ARGS__, RREP, RREP0)(__VA_ARGS__)
#define RREP1(i, n) for (ll i = (n); i >= 1; --i)
#define RREPI(i, j, n) for (ll i = (n); i >= (j); --i)
/**
 * repiの逆順であるループブロックです。つまり、
 * rrepi(i, n)はi = n, n - 2, ..., 1に関するループブロックです。
 * rrepi(i, j, n)はi = n, n - 1, ..., jに関するループブロックです
 */
#define rrepi(...) G3(__VA_ARGS__, RREPI, RREP1)(__VA_ARGS__)
#define each(i, a) for (auto &i : (a))
/**
 * x = min(x, y)を適用します。値が更新されたか否かを返します
 *
 * @param x 更新対象の変数の参照
 * @param y 比較対象の値
 * @return y < x ならばtrue, そうでなければfalse
 */
template <typename T>
bool chmin(T &x, T y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}
/**
 * x = max(x, y)を適用します。値が更新されたか否かを返します
 *
 * @param x 更新対象の変数の参照
 * @param y 比較対象の値
 * @return y > x ならばtrue, そうでなければfalse
 */
template <typename T>
bool chmax(T &x, T y) {
  if (y > x) {
    x = y;
    return true;
  }
  return false;
}
#define ALL(a) (a).begin(), (a).end()
#define SORT(a) sort(ALL(a))
#define RSORT(a) \
  SORT(a);       \
  reverse(ALL(a))
#define IN1(T, a) \
  T a;            \
  cin >> a;
#define IN2(T, a, b) \
  T a, b;            \
  cin >> a >> b;
#define IN3(T, a, b, c) \
  T a, b, c;            \
  cin >> a >> b >> c;
#define IN4(T, a, b, c, d) \
  T a, b, c, d;            \
  cin >> a >> b >> c >> d;
/**
 * in(T, x_1, ..., x_n) で標準入力から受け取ったn(1 <= n <=
 * 4)個のT型の値を変数x_1, ..., x_nに格納します
 */
#define in(...) G5(__VA_ARGS__, IN4, IN3, IN2, IN1)(__VA_ARGS__)
/**
 * in(ll, x_1, ..., x_n) のショートハンドです。
 * つまり、ll(x_1, ..., x_n) で標準入力から受け取ったn(1 <= n <=
 * 4)個の整数を変数x_1, ..., x_nに格納します
 */
#define ll(...) in(ll, __VA_ARGS__)
/**
 * in(string, s_1, ..., s_n) のショートハンドです。
 * つまり、STR(s_1, ..., s_n) で標準入力から受け取ったn(1 <= n <=
 * 4)個の文字列を変数s_1, ..., s_nに格納します
 */
#define STR(...) in(string, __VA_ARGS__)
#define VIN1(T, a, n) \
  vec<T> a(n);        \
  each(i, a) cin >> i;
#define VIN2(T, a, b, n) \
  vec<T> a(n), b(n);     \
  rep(i, n) cin >> a[i] >> b[i];
#define VIN3(T, a, b, c, n) \
  vec<T> a(n), b(n), c(n);  \
  rep(i, n) cin >> a[i] >> b[i] >> c[i];
#define VIN4(T, a, b, c, d, n)   \
  vec<T> a(n), b(n), c(n), d(n); \
  rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
/**
 * vin(T, A_1, ..., A_n, N) で標準入力から受け取ったN個のT型のn-tupleの列をA_1,
 * ..., A_nに格納します
 */
#define vin(...) G6(__VA_ARGS__, VIN4, VIN3, VIN2, VIN1)(__VA_ARGS__)
/**
 * vin(ll, A_1, ..., A_n, N) のショートハンドです。
 * つまり、vll(A_1, ..., A_n,
 * N)で標準入力から受け取ったN個の整数のn-tupleの列をA_1, ..., A_nに格納します
 */
#define vll(...) vin(ll, __VA_ARGS__)
/**
 * vvll(a, n)で標準入力から受け取ったn*nの整数行列をaに格納します
 */
#define vvll(a, n)       \
  vvi a = vec(ll, n, n); \
  rep(i, n) rep(j, n) cin >> a[i][j];
#define out(x) cout << (x) << endl;
/**
 * xを小数点以下第15位まで標準出力します
 */
#define fout(x) cout << fixed << setprecision(15) << (x) << endl;
#define DUMP1(a) cout << #a << " = " << (a) << endl;
#define DUMP2(a, b) \
  cout << #a << " = " << (a) << ' ' << #b << " = " << (b) << endl;
#define DUMP3(a, b, c)                                                 \
  cout << #a << " = " << (a) << ' ' << #b << " = " << (b) << ' ' << #c \
       << " = " << (c) << endl;
#define DUMP4(a, b, c, d)                                              \
  cout << #a << " = " << (a) << ' ' << #b << " = " << (b) << ' ' << #c \
       << " = " << (c) << ' ' << #d << " = " << (d) << endl;
#define DUMP5(a, b, c, d, e)                                              \
  cout << #a << " = " << (a) << ' ' << #b << " = " << (b) << ' ' << #c    \
       << " = " << (c) << ' ' << #d << " = " << (d) << ' ' << #e << " = " \
       << (e) << endl;
/**
 * dump(x_1, ..., x_n)でx_1, ..., x_nをデバッグ出力します
 */
#define dump(...) \
  G5(__VA_ARGS__, DUMP5, DUMP4, DUMP3, DUMP2, DUMP1)(__VA_ARGS__)
/**
 * 指定したイテレータの各要素を指定した文字列で区切って標準出力します
 *
 * @param s 出力対象のイテレータの始端
 * @param e 出力対象のイテレータの終端
 * @param sep 区切り文字（デフォルト値: 半角空白）
 * @return 標準出力後のcout
 */
template <typename T>
ostream &jout(T s, T e, string sep = " ", ostream &os = cout) {
  if (s != e) {
    os << *s;
    ++s;
  }
  while (s != e) {
    os << sep << *s;
    ++s;
  }
  return os;
}
/**
 * 指定した値の真偽値に応じた文字列を標準出力します
 *
 * @param cond 出力対象のイテレータの始端
 * @param y condが真のときに出力する文字列
 * @param n condが偽のときに出力する文字列
 * @return 標準出力後のcout
 */
ostream &yes(bool cond, string y = "Yes", string n = "No", ostream &os = cout) {
  os << (cond ? y : n) << endl;
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T1, typename T2, typename T3>
ostream &operator<<(ostream &os, const tuple<T1, T2, T3> &t) {
  return os << '(' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t)
            << ')';
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  return jout(ALL(v), ", ", os << '[') << ']';
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &s) {
  return jout(ALL(s), ", ", os << '{') << '}';
}
template <typename K, typename V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  return jout(ALL(m), ", ", os << '{') << '}';
}
const ll INF = 1e18;
