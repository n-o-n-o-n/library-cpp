---
title: Median Set
documentation_of: //src/data_structure/set/median_set.hpp
---

中央値を管理する multiset.
要素数が偶数のときは, 中央にある二つの値のうち小さい方を中央値とする.

管理する要素数を $n$ とする.

## Constructor

```
median_set<T1, T2> s
```

- 空の集合を作る
- `T1` は値の型, `T2` は総和の型

## insert

```
void insert(T1 x)
```

- 値 $x$ を一つ追加する
- $O(\log n)$

## erase

```
void erase(T1 x)
```

- 値 $x$ を一つ削除する
- $x$ が集合に存在することが必要
- $O(\log n)$

## median

```
T1 median()
```

- 集合の中央値を返す
- $n \ge 1$ が必要
- $O(1)$

## min_cost

```
T2 min_cost()
```

- 集合の値を $a_1, \ldots, a_n$ としたとき, $\min_x \sum_{i=1}^{n} |a_i-x|$ を返す
- $n \ge 1$ が必要
- $O(1)$
