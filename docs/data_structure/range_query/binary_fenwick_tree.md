---
title: Binary Fenwick Tree
documentation_of: //src/data_structure/range_query/binary_fenwick_tree.hpp
---

`01` 列を管理する Fenwick Tree.
ワードサイズを $w=64$, ワード数を $m=\lceil n/w\rceil$ とする.

## Constructor

```
binary_fenwick_tree fw(int n)
```

- 長さ $n$ の全要素が $0$ の列を作る
- $O(n)$

```
binary_fenwick_tree fw(vector<T> v)
```

- 配列 $v$ で初期化する
- $v_i$ が真と判定されるなら $1$, それ以外なら $0$ として扱う
- $O(n)$

## set

```
void set(int p)
```

- $p$ 番目を $1$ にする
- $O(\log m)$

## reset

```
void reset(int p)
```

- $p$ 番目を $0$ にする
- $O(\log m)$

## flip

```
void flip(int p)
```

- $p$ 番目の $0$ と $1$ を反転する
- $O(\log m)$

## test

```
bool test(int p)
```

- $p$ 番目が $1$ なら `true` を返す
- $O(1)$

## count

```
int count(int l, int r)
```

- 半開区間 $[l, r)$ にある $1$ の個数を返す
- $l$ と $r-1$ が同じワード内なら $O(1)$, それ以外は $O(\log m)$

## all

```
bool all(int l, int r)
```

- 半開区間 $[l, r)$ のすべての要素が $1$ なら `true` を返す
- $O(\log m)$

## any

```
bool any(int l, int r)
```

- 半開区間 $[l, r)$ に $1$ があれば `true` を返す
- $O(\log m)$

## none

```
bool none(int l, int r)
```

- 半開区間 $[l, r)$ に $1$ がなければ `true` を返す
- $O(\log m)$

## kth_element

```
int kth_element(int k)
```

- $1$ の位置を昇順に並べたときの $k$ 番目 (0-indexed) を返す
- 存在しない場合は $-1$ を返す
- $O(\log m)$

## next_element

```
int next_element(int p)
```

- $p$ 以上で最も左にある $1$ の位置を返す
- 存在しない場合は $-1$ を返す
- $O(\log m)$

## prev_element

```
int prev_element(int p)
```

- $p$ 以下で最も右にある $1$ の位置を返す
- 存在しない場合は $-1$ を返す
- $O(\log m)$
