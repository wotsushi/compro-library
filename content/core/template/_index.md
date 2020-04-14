---
title: テンプレート
version: 1.2
prefix: $t
---

{{< meta >}}

テンプレートコードです。

## 説明

空ソースファイルを作成したら、とりあえずこのテンプレートを貼り付けます。

## 副作用
* 標準ライブラリを一括でインクルードするため、 `bits/stdc++.h` をインクルードしています
* いちいち `std` を書くのは面倒なので575しています

## API

### ll
`long long` 型（64bit整数）の短縮名です。

### vi
`vector<ll>` 型（64bit整数列）の短縮名です。

### ii
`pair<ll, ll>` 型（64bit整数のペア）の短縮名です。

### REP
0-indexedのforループのマクロです。

#### 引数
- $i$: ループ変数名
- $n$: ループ回数

#### 置換後のコード
`for (ll i = 0; i < n; ++i)`

### REP1
0-indexedのforループのマクロです。

#### 引数
- $i$: ループ変数名
- $n$: ループ回数

#### 置換後のコード
`for (ll i = 1; i <= n; ++i)`

### FOR
for eachループのマクロです。

#### 引数
- $i$: mutableな参照イテレータの名前
- $a$: ループ対象のコンテナ

#### 置換後のコード
`for (auto &i : a)`

### OUT
値を標準出力するマクロです。

#### 引数
$x$: 標準出力する値

#### 置換後のコード
`cout << x << endl;`

### OUTA
`vector` の各要素を空白区切りで標準出力するマクロです。

#### 引数
$a$: 各要素を空白区切りで標準出力する `vector`

#### 置換後のコード
`REP(i, a.size()) { cout << a[i] << (i == a.size() - 1 ? "\n" : " "); }`

### FOUT
小数部を必ず15桁標準出力するマクロです。

#### 引数
$x$: 標準出力する値

#### 置換後のコード
`cout << fixed << setprecision(15) << x << endl;`

### ALL
コレクションの先頭要素と末尾要素へのイテレータを取得するマクロです。

#### 引数
$a$: 先頭要素と末尾要素へのイテレータを取得するコレクション

#### 置換後のコード
`a.begin(), a.end()`

### SORT
`vector` を昇順ソートするマクロです。

#### 引数
$a$: 昇順ソートする `vector`

#### 置換後のコード
`sort(ALL(a))`

### RSORT
`vector` を降順ソートするマクロです。

#### 引数
$a$: 降順ソートする `vector`

#### 置換後のコード
`sort(ALL(a)); reverse(ALL(a))`

### INF
ll型の $10^{18}$ です。
64bit整数において、十分に大きい値として使います。例えば番兵として有用です

### MOD
ll型の $10^9 + 7$ です.
数え上げ等で剰余をとる問題において頻繁に使われる値です

{{< src >}}