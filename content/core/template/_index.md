---
title: テンプレート
version: 2.4
prefix: $t
weight: 101
---

{{< meta >}}

テンプレートコードです。

## 説明

空ソースファイルを作成したら、とりあえずこのテンプレートを貼り付けます。

## 定数

### pq_asc
昇順優先度付きキューです。

#### 定義値
`priority_queue<T, vector<T>, greater<T>>`

### ll
整数です。

#### 定義値
`long long`

### vi
整数列です。

#### 定義値
`vector<ll>`

### ii
整数ペアです。

#### 定義値
`pair<ll, ll>`

### vvi
整数列の列です。

#### 定義値
`vector<vi>`

### vii
整数ペアの列です。

#### 定義値
`vector<ii>`

### vs
文字列の列です。

#### 定義値
`vector<string>`

### INF
十分に大きい整数として使います。例えば番兵として有用です。

#### 定義値
$10^{18}$

### MOD
数え上げ等で剰余をとる問題において頻繁に使われる素数です。

#### 定義値
$10^9 + 7$

## マクロ

### REP
0-indexedのforループです。

#### 引数
- $i \in Id$
- $n \in \mathbb{Z}$

### REP1
1-indexedのforループです。

#### 引数
- $i \in Id$
- $n \in \mathbb{Z}$

### FOR
for eachループです。

#### 引数
- $i \in Id$
- $a \in Container$

### CH
指定した変数にある値との演算結果を代入するマクロです。

#### 引数
- $f: X \times Y \rightarrow X$
- $x \in Ref$
- $y \in Ref$

s.t. $*x \in X, *y \in Y$

### IN
単一値を標準入力するマクロです。

#### 引数
- $T \subseteq \Omega$
- $x \in Id$

### AIN
列を標準入力するマクロです。

#### 引数
- $T \subseteq \Omega$
- $a \in Id$
- $n \in \mathbb{Z}_{\geq 0}$

### A2IN
2列を標準入力するマクロです。

#### 引数
- $T_1 \subseteq \Omega$
- $a \in Id$
- $T_2 \subseteq \Omega$
- $b \in Id$
- $n \in \mathbb{Z}_{\geq 0}$

### OUT
値を標準出力するマクロです。

#### 引数
- $x \in \mathbb{R} \cup \Sigma^{*}$

### FOUT
小数部を15桁標準出力するマクロです。

#### 引数
$x \in \mathbb{R}$

### JOUT
イテレータを指定した区切り文字で結合した文字列をストリームに出力する関数です。

#### 引数
- $s \in Iter$
- $e \in Iter$
- $sep \in \Sigma^{*}$
  - デフォルト値: `" "`

### YES
真偽値に応じた文字列をストリームに出力する関数です。

#### 引数
- $cond \in \\{0, 1\\}$
- $yes \in \Sigma^{*}$
  - デフォルト値: `"Yes"`
- $no \in \Sigma^{*}$
  - デフォルト値: `"No"`

### ALL
コレクションの先頭要素と末尾要素へのイテレータを取得するマクロです。

#### 引数
$a \in Container$

### SORT
`vector` を昇順ソートするマクロです。

#### 引数
$a \in \Omega^{*}$

### RSORT
`vector` を降順ソートするマクロです。

#### 引数
$a \in \Omega^{*}$

### DUMP
指定した変数の識別子と値を標準出力するマクロです。
デバッグで有用です。

#### 引数
$x \in Ref$

### DUMPA
指定したコレクションの識別子と各要素を標準出力するマクロです。
デバッグで有用です。

#### 引数
$a \in Ref$

s.t. $*a \in Container$

## 拡張
標準ライブラリを使えるようにするため `bits/stdc++.h` をインクルードしています。
さらに修飾子 `std::` を省略するため `using namespace std;` 宣言をしています。
デバッグを快適にするため、`vector` と `pair` に対する出力ストリームの演算子をオーバーロードしています。

{{< src >}}

{{< example >}}
