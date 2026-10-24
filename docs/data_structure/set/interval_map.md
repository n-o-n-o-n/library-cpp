---
title: Interval Map
documentation_of: //src/data_structure/set/interval_map.hpp
---

区間を set で管理するテクのライブラリ(map ver.).

管理する区間の個数を $n$, 操作で処理する区間数を $m$ とする.

## Constructor

```
interval_map<T, S> mp(S e = S())
```

- 空の写像を作る
- `T` は符号付きまたは符号なしの整数型, `S` は `==` が定義された型
- $O(1)$

## update

```
void update(T l, T r, S x)
void update(T l, T r, S x, add, del)
void update(T k, S x)
void update(T k, S x, add, del)
```

- $[l,r)$ または位置 $k$ の値を $x$ にする
- 区間の更新は $O(\log n+m)$, 1 要素の更新は $O(\log n)$

## get

```
tuple<T, T, S> get(T k)
```

- $k$ を含む区間があれば, その左端, 右端, 値を返す
- $k$ がどの区間にも含まれない場合は `{k, k + 1, e}` を返す
- $O(\log n)$

## operator[]

```
S operator[](T k)
```

- 位置 $k$ の値を返す
- どの区間にも含まれない場合は $e$ を返す
- $O(\log n)$

## mex

```
tuple<T, T, S> mex(T k)
```

- 右端が $k$ より大きい最初の区間の左端, 右端, 値を返す
- 存在しない場合は `{numeric_limits<T>::max(), numeric_limits<T>::max(), e}` を返す
- $O(\log n)$

## next_element

```
T next_element(T k)
```

- $k$ 以上で管理する区間に含まれる最小の位置を返す
- 存在しない場合は `numeric_limits<T>::min()` を返す
- $O(\log n)$

## prev_element

```
T prev_element(T k)
```

- $k$ 以下で管理する区間に含まれる最大の位置を返す
- 存在しない場合は `numeric_limits<T>::max()` を返す
- $O(\log n)$

## covered

```
bool covered(T l, T r)
bool covered(T k)
```

- $[l,r)$ または位置 $k$ が管理する区間で覆われているなら `true` を返す
- 空区間に対しては `true` を返す
- 区間版は $O(\log n+m)$, 1 要素版は $O(\log n)$

## intersects

```
bool intersects(T l, T r)
```

- $[l,r)$ と管理する区間が重なるなら `true` を返す
- $O(\log n)$

## empty

```
bool empty()
```

- 管理する区間がなければ `true` を返す
- $O(1)$

## size

```
int size()
```

- 管理する区間の個数を返す
- $O(1)$

## intervals

```
vector<tuple<T, T, S>> intervals(T l = numeric_limits<T>::min(), T r = numeric_limits<T>::max())
```

- 管理する区間と $[l,r)$ の共通部分を左端の昇順で返す
- $O(\log n+m)$

## clear

```
void clear()
```

- 管理するすべての区間を削除する
- $O(n)$
