---
title: Treap
documentation_of: //src/data_structure/bst/treap.hpp
---

色々できるデータ構造.

## Constructor

```
treap<T> tr
treap<T> tr(vector<T> v)
```

- 空の列, または $v$ を初期値とする列を作る
- `T` は要素の型

## size

```
int size()
```

- 列の要素数を返す
- $O(1)$

## insert

```
void insert(int p, T x)
```

- $p$ 番目の要素の前に $x$ を挿入する
- $0 \leq p \leq n$
- expected $O(\log n)$

## erase

```
void erase(int p)
void erase(int l, int r)
```

- $p$ 番目の要素, または区間 $[l,r)$ の要素を削除する
- expected $O(\log n)$

## reverse

```
void reverse(int l, int r)
```

- 区間 $[l,r)$ の要素の順序を反転する
- expected $O(\log n)$

## set

```
void set(int p, T x)
```

- $p$ 番目の要素を $x$ に変更する
- expected $O(\log n)$

## get

```
T get(int p)
```

- $p$ 番目の要素を返す
- expected $O(\log n)$

## shift

```
void shift(int k)
```

- 長さ $n$ の列を左へ $k$ 個循環シフトする
- 負の $k$ は右へのシフトを表し, $k$ は $n$ で割った余りとして扱う
- expected $O(\log n)$
