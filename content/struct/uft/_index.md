---
title: UnionFind木
version: 1.0
prefix: $uft
---

{{< meta >}}

互いに素な動的集合を管理するデータ構造です。

## 説明
$n + 1$ 個の互いに素な集合 $\\{0\\}, \\{1\\}, \ldots, \\{n\\}$ に対して、以下の操作を提供するデータ構造です。
- 集合の合併
- 2つの要素が同一の集合に属すかの判定
- ある要素が属す集合の要素数の取得

## API
アッカーマン関数 $A$ について、関数 $A(x, x)$ の逆関数を $\alpha(x)$ で表すことにします
（$\alpha(x)$ は定数関数とみなして差し支えないほど緩やかに増加する関数です）

### 状態空間
- $n' \in \mathbb{N}$
- $\mathcal{S'}$: 以下を満たす集合族
  - $\bigcup_{S \in \mathcal{S'}} S = \\{0, 1, \ldots, n'\\}$
  - $\forall X, Y \in \mathcal{S'}, X \neq Y \Rightarrow X \cap Y = \emptyset$

$\mathcal{S'}$ は管理している動的集合の状態に対応します。
例えば、 $\mathcal{S'} = \\{ \\{1, 2, 3\\}, \\{4, 5\\}, \\{6\\} \\}$ ならば
$\\{1, 2, 3\\}$, $\\{4, 5\\}$, $\\{6\\}$ を管理している状態に対応します。

### コンストラクタ
$n + 1$ 個の互いに素な動的集合を初期化します。

#### 引数
$n \in \mathbb{N}$

#### 初期状態
- $n' = n$
- $\mathcal{S'} = \\{ \\{0\\}, \\{1\\}, \ldots, \\{n\\} \\}$

#### 計算量
$O(n)$

### unite
指定した2つの要素が属す集合を合併します。合併済みの場合は何もしません。

#### 引数
- $i \in \mathbb{N}_{n' + 1}$
- $j \in \mathbb{N}_{n' + 1}$

#### 戻り値
なし

#### 状態変化
$\mathcal{S'} \leftarrow \\{S \in \mathcal{S'} \mid S \not \ni i, j\\} \cup \\{X \cup Y\\}$
s.t. $i \in X \in \mathcal{S'}$, $j \in Y \in \mathcal{S'}$

#### 計算量
$O(\alpha(n'))$

### same
指定した2つの要素が同一の集合に属すか判定します。

#### 引数
- $i \in \mathbb{N}_{n' + 1}$
- $j \in \mathbb{N}_{n' + 1}$

#### 戻り値
$\exists S \in \mathcal{S'}, i, j \in S$

#### 状態変化
なし

#### 計算量
$O(\alpha(n'))$

### size
指定した要素が属す集合の要素数を返します。

#### 引数
$i \in \mathbb{N}_{n' + 1}$

#### 戻り値
$|X|$ s.t. $i \in X \in \mathcal{S'}$

#### 状態変化
なし

#### 計算量
$O(\alpha(n'))$

{{< src >}}
