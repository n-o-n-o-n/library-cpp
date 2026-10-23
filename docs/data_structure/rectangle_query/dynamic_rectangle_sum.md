---
title: Dynamic Rectangle Sum
documentation_of: //src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp
---

$1$ 点更新矩形積クエリを解く.
クエリを全て先読みし, 最後に答えを求める.

## Constructor

```
dynamic_point_add_rectangle_sum<Abelian_Group, T = int> rs(int n = 0, int q = 0)
```

- `Abelian_Group` には型 `S`, 二項演算 `op`, 単位元 `e`, 逆元 `inv` が必要
- `T` は座標の型

## add_update_query

```
void add_update_query(T x, T y, S w)
```

- 点 $(x, y)$ に重み $w$ を加えるクエリを追加する

## add_sum_query

```
void add_sum_query(T xl, T yl, T xr, T yr)
```

- $x_l \leq x < x_r$, $y_l \leq y < y_r$ を満たす点の重みの総和を求めるクエリを追加する

## solve

```
vector<S> solve()
```

- クエリを追加した順に適用し, 各矩形和クエリの答えをその順に並べて返す
- 追加したクエリの総数を $k$ として $O(k \log^2 k)$
