---
title: Interval Set
documentation_of: //src/data_structure/set/interval_set.hpp
---

区間を set で管理するテクのライブラリ(set ver.).

管理する区間の個数を $n$, 操作で処理する区間数を $m$ とする.

## Constructor

```
interval_set<T> s
```

- 空の集合を作る
- `T` は整数
- $O(1)$

## insert

```
void insert(T l, T r)
void insert(T l, T r, add, del)
void insert(T k)
void insert(T k, add, del)
```

- $[l,r)$ または要素 $k$ を集合に加える
- 区間の挿入は $O(\log n+m)$, 1 要素の挿入は $O(\log n)$

## erase

```
void erase(T l, T r)
void erase(T l, T r, add, del)
void erase(T k)
void erase(T k, add, del)
```

- $[l,r)$ または要素 $k$ を集合から削除する
- 区間の削除は $O(\log n+m)$, 1 要素の削除は $O(\log n)$

## get

```
pair<T, T> get(T k)
```

- $k$ を含む区間の両端を返す
- 含まれない場合は `{numeric_limits<T>::max(), numeric_limits<T>::max()}` を返す
- $O(\log n)$

## mex

```
T mex(T k = 0)
```

- $k$ 以上で集合に含まれない最小の値を返す
- $O(\log n)$

## next_element

```
T next_element(T k)
```

- $k$ 以上で集合に含まれる最小の値を返す
- 存在しない場合は `numeric_limits<T>::min()` を返す
- $O(\log n)$

## prev_element

```
T prev_element(T k)
```

- $k$ 以下で集合に含まれる最大の値を返す
- 存在しない場合は `numeric_limits<T>::max()` を返す
- $O(\log n)$

## covered

```
bool covered(T l, T r)
bool covered(T k)
```

- $[l,r)$ または要素 $k$ がすべて集合に含まれるなら `true` を返す
- $O(\log n)$

## intersects

```
bool intersects(T l, T r)
```

- $[l,r)$ に集合の要素が一つでも含まれるなら `true` を返す
- 空区間に対しては `false` を返す
- $O(\log n)$

## empty

```
bool empty()
```

- 集合が空なら `true` を返す
- $O(1)$

## size

```
int size()
```

- 管理する区間の個数を返す
- $O(1)$

## intervals

```
vector<pair<T, T>> intervals(T l = numeric_limits<T>::min(), T r = numeric_limits<T>::max())
```

- 集合と $[l,r)$ の共通部分を区間ごとに昇順で返す
- $O(\log n+m)$

## clear

```
void clear()
```

- すべての区間を削除する
- $O(n)$
