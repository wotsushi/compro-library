---
title: グリッド
version: 0.1
prefix: $grid
---

{{< meta >}}

グリッドのイテレートを補助する関数です。

## 説明
グリッドの端にあるセルから隣接するセルに対してある処理を実行する際、グリッド外のセルに対しては処理をスキップする必要があります。
このスキップ処理を含めたイテレートに関するユーティリティ関数を提供します。

## マクロ

### way4
$H \times W$ 盤面の指定したセル $(i, j)$ の上下左右に隣接するセルに対して処理 $f$ を実行します。

#### 引数
- $i \in \\{0, 1, \ldots, H - 1\\}$
- $j \in \\{0, 1, \ldots, W - 1\\}$
- $H \in \mathbb{Z}_{+}$
- $W \in \mathbb{Z}_{+}$
- $f: \\{0, 1, \ldots, H - 1\\} \times \\{0, 1, \ldots, W - 1\\} \rightarrow \emptyset$

### way8
$H \times W$ 盤面の指定したセル $(i, j)$ の八方に隣接するセルに対して処理 $f$ を実行します。

#### 引数
- $i \in \\{0, 1, \ldots, H - 1\\}$
- $j \in \\{0, 1, \ldots, W - 1\\}$
- $H \in \mathbb{Z}_{+}$
- $W \in \mathbb{Z}_{+}$
- $f: \\{0, 1, \ldots, H - 1\\} \times \\{0, 1, \ldots, W - 1\\} \rightarrow \emptyset$

{{< src >}}

{{< example >}}
