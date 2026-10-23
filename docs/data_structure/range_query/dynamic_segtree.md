---
title: Segtree
documentation_of: //src/data_structure/range_query/dynamic_segtree.hpp
---

動的セグ木. 

## Constructor

```
dynamic_segtree<Monoid, T = int> seg(T n, int q = 0)
```

- 長さ $n$ のセグ木を作る
- `Monoid` を定義する必要がある
    - 内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある
- `T` は配列の大きさに応じて `int` か `long long` が想定される
- $q$ を指定すると `reserve` するので少し定数倍がよくなる
- $O(1)$

## set

```
void set(T p, S x)
```

- $p$ 番目の要素を $x$ に変更する
- $O(\log n)$

## get

```
S get(T p)
```

- $p$ 番目の要素を返す
- $O(\log n)$

## prod

```
S prod(T l, T r)
```

- 半開区間 $[l, r)$ に対する総積を計算する
- $O(\log n)$

## all_prod

```
S all_prod()
```

- 全体の総積を返す
- $O(1)$
