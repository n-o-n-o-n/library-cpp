---
title: Top K Set
documentation_of: //src/data_structure/set/top_k_set.hpp
---

多重集合の上位 $k$ 個の値とその総和を管理する.
比較関数が既定の `less<T1>` のときは小さい方から, `greater<T1>` のときは大きい方から数える.

管理する要素数を $n$ とする.

## Constructor

```
top_k_set<T1, T2, Compare> s(int k)
```

- 空の集合を作り, 管理する個数 $k$ を固定する
- `T1` は値の型, `T2` は総和の型
- `Compare` の既定は `less<T1>`

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
- $x$ が含まれない場合は何もしない
- $O(\log n)$

## kth_val

```
T1 kth_val()
```

- 比較順で $k$ 番目(1-indexed)の値を返す
- $n\geq k$ が必要
- $O(1)$

## sum

```
T2 sum()
```

- 比較順で先頭から $\min(k,n)$ 個の値の総和を返す
- $O(1)$
