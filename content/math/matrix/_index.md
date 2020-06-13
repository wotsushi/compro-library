---
title: 行列
version: 1.0
prefix: $matrix
weight: 303
---

{{< meta >}}

行列を表すデータ構造です。

## 説明

行列を表すデータ構造です。
以下の演算をサポートしています。
- 和
- 差
- 積
- べき乗

## データ構造

### ジェネリクス
$T \subseteq \mathbb{R}$

$T$ は行列の要素の型です。ほとんどの場合、 `long long`, `double`, [mint]({{< ref "struct/mint/_index.md" >}}) のいずれかを指定するでしょう。

### 状態空間
- $n' \in \mathbb{Z}_{+}$
- $m' \in \mathbb{Z}_{+}$
- $A' \in T^{n' \times m'}$

$n'$ は行数を、 $m'$ は列数を表します。
$A'$ は $n' \times m'$ 行列を表します。

### コンストラクタ
$n$ 次の正方行列として初期化します。各要素は0です。

#### 引数
$n \in \mathbb{Z}_{+}$

#### 初期状態
- $n' = n$
- $m' = n$
- $A_{1, 1}' = A_{1, 2}' = \cdots = A_{1, n}' = A_{2, 1}' = \cdots = A_{n, n}' = 0$

### コンストラクタ
$n \times m$ 次の行列として初期化します。各要素は0です。

#### 引数
- $n \in \mathbb{Z}_{+}$
- $m \in \mathbb{Z}_{+}$

#### 初期状態
- $n' = n$
- $m' = m$
- $A_{1, 1}' = A_{1, 2}' = \cdots = A_{1, m}' = A_{2, 1}' = \cdots = A_{n, m}' = 0$

#### 計算量
$O(nm)$

### コンストラクタ
指定した2次元ベクタに対応する行列を生成します。

#### 引数
$X = ((X_{1, 1}, \ldots, X_{1, m}), \ldots, (X_{n, 1}, \ldots, X_{n, m}))$

s.t. $\forall i, \forall j, X_{i, j} \in T$

#### 初期状態
- $n' = n$
- $m' = m$
- $A_{i, j}' = X_{i, j}$

#### 計算量
$O(nm)$

### 四則演算代入
行列同士の `+=`, `-=`, `*=` については行列の演算に基づいた結果を代入します。
実数との `*=`, `/=` については各要素に対してその実数との演算結果を代入します。
計算量は行列同士の積のみ $O({n'}^{3})$ で、それ以外は $O({n'}^2)$ です。

### pow
行列をべき乗した結果を返します。この行列は正方行列でなければなりません。

#### 引数
$k \in \mathbb{Z}_{\geq 0}$

#### 戻り値
${A'}^k$

#### 状態変化
なし

#### 計算量
$O(n'^3 \log{k})$

### 演算子[]
指定した行(0-indexed)に対応するベクタの参照を返します。

#### 引数
$i \in \\{0, 1, \ldots, n' - 1\\}$

#### 戻り値
$\\&(A_{i, 1}', \ldots, A_{i, m'}')$

#### 状態変化
なし

#### 計算量
$O(1)$

## 拡張
`+`, `-`, `*`, `/` 演算子を $T$ または `matrix<T>` 同士に適用できます。

{{< src >}}

{{< example >}}