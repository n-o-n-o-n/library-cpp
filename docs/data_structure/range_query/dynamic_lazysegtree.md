---
title: Lazysegtree
documentation_of: //src/data_structure/range_query/dynamic_lazysegtree.hpp
---

動的遅延セグ木. 

## Constructor

```
lazysegtree<ActMonoid, T = int> seg(T n, int q = 0)
```

- 長さ $n$ の遅延セグ木を作る
- `ActMonoid` を定義する必要がある
    - 内部で型 `S`, 二項演算 `op`, 単位元 `e`, 作用素の型 `F`, 合成 `comp`, 恒等写像 `id`, 作用 `map`, `init` を定義する必要がある
    - $\text{comp}(f, g)$ は $f\circ g$ が期待される
- `S init(T l, T r)` は半開区間 $[l,r)$ の初期状態での総積を返す
- $q$ を指定すると `reserve` するので少し定数倍がよくなる
- $O(1)$

## set

```
void set(T p, S x)
```

- $p$ 番目の要素を $x$ に変更する
- $O(\log n)$

## apply

```
void apply(T l, T r, F f)
```

- 半開区間 $[l,r)$ に $f$ を作用させる
- どちらも $O(\log n)$

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
