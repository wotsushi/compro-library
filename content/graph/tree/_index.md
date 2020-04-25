---
title: 木
version: 0.1
prefix: $tree
---

{{< meta >}}

木を表すデータ構造です。

## 説明
木とは閉路を持たない連結なグラフです。
データ構造 `Tree` は指定した頂点を根とする木について、各頂点の親・子・深さをフレンドリーに取得できるAPIを提供しています。

木の辺に重みを持たせることができ、重みはジェネリックな型（ただし、0を元として含む必要がある）としています。
以降、指定された型を $W$ とします。

## API

### 状態空間
- $n' \in \mathbb{Z_{\geq 0}}$
- $r' \in \\{0, 1, \\ldots, n'\\}$
- $p' = (p_{0}', p_{1}', \ldots, p_{n'}') \in (\\{-2, -1, 0, 1, \\ldots, n'\\} \times W)^{n' + 1}$
- $c' = (c_{0}', c_{1}', \ldots, c_{n'}') \in ((\\{0, 1, \\ldots, n'\\} \times W)^{*})^{n' + 1}$
- $d' = (d_{0}', c_{1}', \ldots, c_{n'}') \in (\mathbb{Z}_{\geq 0})^{n' + 1}$

$n'$ は頂点の数を表します。
$r'$ は根である頂点を表します。
$p_i' = (j, w)$ は頂点 $i$ の親が $j$ であり、辺 $(j, i)$ の重みが $w$ であることを表します。
$c_i'$ は頂点 $i$ と $i$ の子を結ぶ重み付き辺の列を表します。
$d_i'$ は頂点 $r'$ の深さを0とするときの頂点 $i$ の深さを表します。

### コンストラクタ
グラフから木を生成します。

#### 引数
- $G = (n, m, w, d, E) \in$ [Graph]({{< ref "graph/graph/_index.md" >}})
- $r \in \\{0, 1, \\ldots, n\\}$
  - デフォルト値: 1

s.t. $G$ は閉路を持たない。

#### 初期状態
- $n' = n$
- $r' = r$
- $p_i'$: $T$ における $i$ の親 $j$ と辺 $(j, i)$ の重みのペア
- $c_i'$ $T$ における $i$ の子 $j$ と辺 $(i, j)$ の重みのペアの列
- $d'$ $T$ における $r$ の深さを0としたときの $i$ の深さ

s.t.
- $T$: $G$ を頂点 $r$ を根とみなしたときの木

#### 計算量
$O(n + m)$

### par
指定した頂点とその親を結ぶ辺を返します。

#### 引数
$i \in \\{0, 1, \ldots, n'\\}$

#### 戻り値
$p_i'$

#### 状態変化
なし

#### 計算量
$O(1)$

### depth

指定した頂点の深さを返します。

#### 引数
$i \in \\{0, 1, \ldots, n'\\}$

#### 戻り値
$d_i'$

#### 状態変化
なし

#### 計算量
$O(1)$

### []演算子
指定した頂点とその子を結ぶ辺のリストへの参照を返します。

#### 引数
$i \in \\{0, 1, \ldots, n'\\}$

#### 戻り値
$c_i'$

#### 状態変化
なし

#### 計算量
$O(1)$

{{< src >}}

{{< example >}}