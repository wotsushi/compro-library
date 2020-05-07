---
title: Suffix Array
version: 1.0
prefix: $suffixarray
weight: 502
---

{{< meta >}}

指定した文字列のsuffix arrayを構築するデータ構造です。

## 説明
suffix arrayとは、ある文字列のsuffixを辞書順にソートした配列です。
例えば、 `agc` のsuffix arrayは (空文字, `ag`, `agc`, `c`) です。

文字列の長さを $n$ として、前処理に $O(n (\log{n})^2)$ の計算量を要しますが, suffix array の $i$ 番目の要素を $O(n)$ で求められます。

## データ構造

### ジェネリクス
このデータ構造はジェネリックではありません。

### 状態空間
$S' = (S_{1}', \ldots, S_{|S'|}') \in \Sigma^*$

$S'$ はsuffix arrayを求める文字列を表します。

### コンストラクタ
指定した文字列のsuffix arrayを構築します。

#### 引数
$S \in \Sigma^*$

#### 初期状態
$S' = S$

#### 計算量
$O(|S| (\log{|S|})^2)$

### 演算子[]
$i$ 番目(0-indexed)に小さいsuffixを返します。
なお0番目は空文字列です。

#### 引数
$i \in \\{0, 1, \ldots, |S'|\\}$

#### 戻り値
$(S_{k}', \ldots, S_{|S|}')$ s.t. $|\\{j \in \\{1, 2, \ldots, |S| + 1 \\} \mid (S_{j}', \ldots, S_{|S|}') < (S_{k}', \ldots, S_{|S|}') \\}| = i$

#### 状態変化
なし

#### 計算量
$O(|S'|)$

{{< src >}}

{{< example >}}
