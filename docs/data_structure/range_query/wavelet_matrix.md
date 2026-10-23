---
title: Wavelet Matrix
documentation_of: //src/data_structure/range_query/wavelet_matrix.hpp
---

Wavelet Matrix.

`LOG` を $L$ とし, 登場する値は全て $0$ 以上 $2^L$ 未満とする.

`set` 以外の関数が最初に呼ばれた時とき, $O(nL)$ で構築を行う.
また, `prev_val` と `next_val` で存在しない場合の $-1$ を使うには, `T` を符号付き整数型にする必要がある.


## Constructor

```
wavelet_matrix<T, LOG> wm
wavelet_matrix<T, LOG> wm(int n)
wavelet_matrix<T, LOG> wm(vector<T> v)
```

- 空の列, 長さ $n$ の $0$ で初期化された列, または $v$ を初期値とする列を作る
- `T` は整数型, `LOG` は扱う値のビット数で, 省略時は `numeric_limits<T>::digits`

## set

```
void set(int p, T x)
```

- $p$ 番目の要素を $x$ に変更する
- 構築前に呼ぶ必要がある(`set` 以外の関数を呼ぶと自動で構築される)
- $O(1)$

## get

```
T get(int p)
```

- $p$ 番目の要素を返す
- $O(L)$

## range_kth_smallest

```
T range_kth_smallest(int l, int r, int k)
```

- $[l,r)$ の要素を昇順に並べたときの $k$ 番目 (0-indexed) の値を返す
- $0 \leq k < r-l$ が必要
- $O(L)$

## prev_val

```
T prev_val(int l, int r, T upper)
```

- $[l,r)$ に含まれる `upper` 未満の値の最大値を返す
- 存在しない場合は $-1$ を返す
- $O(L)$

## next_val

```
T next_val(int l, int r, T lower)
```

- $[l,r)$ に含まれる `lower` 以上の値の最小値を返す
- 存在しない場合は $-1$ を返す
- $O(L)$

## count

```
int count(int l, int r, T x)
```

- $[l,r)$ に含まれる $x$ の個数を返す
- $O(L)$

## range_freq

```
int range_freq(int l, int r, T lower, T upper)
```

- $[l,r)$ に含まれる `lower` 以上 `upper` 未満の値の個数を返す
- `lower` $\leq$ `upper` が必要
- $O(L)$

