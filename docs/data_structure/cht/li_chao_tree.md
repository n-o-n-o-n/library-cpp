---
title: Li Chao Tree
documentation_of: //src/data_structure/cht/li_chao_tree.hpp
---

Li Chao Tree.

最小値クエリで使われる点の個数を $n$ とする.
`add_point` 以外の関数が呼ばれたタイミング (または `xs` を渡して宣言したとき) で $O(n\log n)$ で構築を行う.

## Constructor

```
li_chao_tree<T> lct
li_chao_tree<T> lct(vector<T> xs)
```

- 空の構造を作る, または `xs` をクエリの点集合として構築する
- `T` は座標と直線の値の型

## add_point

```
void add_point(T x)
```

- クエリで用いる $x$ を追加する
- `xs` を渡して構築した場合や, `add_point` 以外の関数を呼んでからは呼べない

## add_line

```
void add_line(T a, T b)
```

- 直線 $y=ax+b$ を追加する
- $O(\log n)$

## add_segment

```
void add_segment(T xl, T xr, T a, T b)
```

- $xl\leq x<xr$ 上に線分 $y=ax+b$ を追加する
- $O(\log^2 n)$

## get_min

```
T get_min(T x)
```

- $x$ における直線の値の最小値を返す
- $x$ は `xs`, または `add_point` で追加した点に含まれる必要がある
- 対象となる直線がない場合は `numeric_limits<T>::max()` を返す
- $O(\log n)$