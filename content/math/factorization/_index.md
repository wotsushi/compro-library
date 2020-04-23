---
title: 素因数分解
version: 1.0
prefix: $pfact
---

{{< meta >}}

整数を素因数分解する関数です。

## 説明

指定した整数を素因数分解した結果を返す関数を提供します。

## API

### factorization
指定した整数を素因数分解した結果を返します。素因数分解した結果は `map` 型のオブジェクトとして返されます。
返される `map` のキーは素因数を、値はその素因数の個数を表します。

指定した整数が1以下の整数の場合は空の `map` を返します。

#### 引数
$x \in \mathbb{Z}$

#### 戻り値
$
\begin{cases}
\\{(p_1, a_1), \ldots, (p_n, a_n) \\} & n \geq 2 \\\\
\emptyset & otherwise
\end{cases}
$

s.t.
- $n, a_1, \ldots, a_n \in \mathbb{Z}_{+}$
- $p_1, \ldots, p_n \in \mathbb{P}$
- $\Pi_{i = 1}^{n} p_i^{a_i} = x$

#### 計算量
$O(\sqrt{x})$

{{< src >}}