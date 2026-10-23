---
title: Segtree
documentation_of: //src/data_structure/range_query/segtree.hpp
---

セグ木. 

## Constructor

```
segtree<Monoid> seg(int n)
segtree<Monoid> seg(vector<S> v)
```

- 長さ $n$ のセグ木を作る
- `Monoid` を定義する必要がある
    - 内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある
- 配列 $v$ で初期化すると, 長さで初期化して $1$ つずつ `set` するよりも速い

## set

```
void set(int p, S x)
```

- $p$ 番目の要素を $x$ に変更する
- $O(\log n)$

## apply

```
void apply(int p, S x)
```

- $p$ 番目の要素を $x \cdot a_p$ で置き換える
- $O(\log n)$

## get

```
S get(int p)
```

- $p$ 番目の要素を返す
- $O(1)$

## prod

```
S prod(int l, int r)
```

- 半開区間 $[l, r)$ に対する総積を計算する
- $O(\log n)$

## all_prod

```
S all_prod()
```

- 全体の総積を返す
- $O(1)$

## max_right

```
int max_right(int l, check)
```

- 右側へのセグ木上の二分探索を行う
- `check` には判定用のラムダ式を渡す
- $\text{check}(\text{prod}(l, r))$ が `true` となる $r$ の最大値が返る
- $\text{check}(e)$ が `true` である必要がある
- $O(\log n)$

## min_left

```
int min_left(int r, check)
```

- 左側へのセグ木上の二分探索を行う
- `check` には判定用のラムダ式を渡す
- $\text{check}(\text{prod}(l, r))$ が `true` となる $l$ の最小値が返る
- $\text{check}(e)$ が `true` である必要がある
- $O(\log n)$