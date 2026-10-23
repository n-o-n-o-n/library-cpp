---
title: Persistent Segtree
documentation_of: //src/data_structure/persistent_ds/persistent_segtree.hpp
---

永続セグ木.
初期状態の列番号は $0$.

## Constructor

```
persistent_segtree<Monoid> seg
persistent_segtree<Monoid> seg(int n)
persistent_segtree<Monoid> seg(vector<S> v)
```

- 長さ $n$ の永続セグ木を作る
- `Monoid` を定義する必要がある
    - 内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある

## reserve

```
void reserve(int q)
```

- クエリ数 $q$ に応じてメモリを確保する

## set

```
int set(int k, int p, S x)
```

- $k$ 番目の列における $p$ 番目の要素を $x$ に変更した新しい列を作り, その番号を返す
- $O(\log n)$

## get

```
S get(int k, int p)
```

- $k$ 番目の列の $p$ 番目の要素を返す
- $O(\log n)$

## prod

```
S prod(int k, int l, int r)
```

- $k$ 番目の列の区間 $[l,r)$ の総積を返す
- $O(\log n)$
