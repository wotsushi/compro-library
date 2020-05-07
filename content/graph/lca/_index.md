---
title: LCA
version: 0.1
prefix: $lca
weight: 404
---

{{< meta >}}

根付き木の2頂点のLCAを求める関数オブジェクトです。

## 説明
根付き木の2頂点のLCAを求める関数オブジェクトです。
木の頂点数を $n$ として、前処理に $O(n \log{n})$ の計算量を要しますが, LCAを $O(\log{n})$ の計算量で求められます。

## データ構造

### ジェネリクス
このデータ構造はジェネリックではありません。

### 状態空間
- $T' = (n', r', p', c', d') \in$ [Tree]({{< ref "graph/tree/_index.md" >}})

$T'$ はLCAを求める対象の木を表します。

### コンストラクタ
指定した木のLCAを高速に求める前処理を行います。

#### 引数
- $T = (n, r, p, c, d) \in$ [Tree]({{< ref "graph/tree/_index.md" >}})

#### 初期状態
- $T' = T$

#### 計算量
$O(n\log{n})$

### 演算子()
指定した2頂点のLCAを返します。

#### 引数
- $i \in \\{0, 1, \ldots, n'\\}$
- $j \in \\{0, 1, \ldots, n'\\}$

#### 戻り値
頂点 $i$ と頂点 $j$ のLCA

#### 状態変化
なし

#### 計算量
$O(\log{n'})$

{{< src >}}

{{< example >}}