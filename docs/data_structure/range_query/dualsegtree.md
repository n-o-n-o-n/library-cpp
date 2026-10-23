---
title: Dualsegtree
documentation_of: //src/data_structure/range_query/dualsegtree.hpp
---

双対セグ木. 

## Constructor

```
dualsegtree<ActSet> seg(int n)
```

- 長さ $n$ の双対セグ木を作る
- `ActSet` を定義する必要がある
    - 内部で型 `S`, 単位元 `e`, 作用素の型 `F`, 合成 `comp`, 恒等写像 `id`, 作用 `map` を定義する必要がある
    - `e` は `S` の元であればなんでもいい
    - $\text{comp}(f, g)$ は $f\circ g$ が期待される
- $O(n)$

```
dualsegtree<ActSet> seg(vector<S> v)
```

- 配列 $v$ で初期化セグ木を作る
- 長さで初期化して $1$ つずつ `set` するよりも速い
- $O(n)$

## set

```
void set(int p, S x)
```

- $p$ 番目の要素を $x$ に変更する
- $O(\log n)$

## apply

```
void apply(int p, F f)
void apply(int l, int r, F f)
```

- $p$ 番目の要素 or 半開区間 $[l,r)$ に $f$ を作用させる
- どちらも $O(\log n)$

## get

```
S get(int p)
```

- $p$ 番目の要素を返す
- $O(\log n)$
