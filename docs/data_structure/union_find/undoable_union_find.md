---
title: Undoable Union Find
documentation_of: //src/data_structure/union_find/undoable_union_find.hpp
---

undo 可能 union find.

## Constructor

```
undoable_union_find uf(int n)
```

- $n$ 頂点で初期化する

## leader

```
int leader(int u)
```

- $u$ が属する連結成分の代表元を返す
- $O(\log n)$

## same

```
bool same(int u, int v)
```

- $u$ と $v$ が同じ連結成分に属するかを判定する
- $O(\log n)$

## merge

```
void merge(int u, int v)
```

- 辺 $(u,v)$ を追加する
- すでに同じ連結成分でも, 後続の `undo` で取り消す操作として記録する
- $O(\log n)$

## size

```
int size(int u)
```

- $u$ が属する連結成分の要素数を返す
- $O(\log n)$

## undo

```
void undo()
```

- 直前の `merge` を取り消す
- 取り消せる `merge` が存在することが必要
- $O(1)$

## group

```
vector<int> group(int u)
```

- $u$ が属する連結成分の頂点を返す
- 返り値の先頭は $u$, 残りの順序は未定
- 返り値の要素数を $k$ として $O(k)$

## groups

```
vector<vector<int>> groups()
```

- 各連結成分の頂点を列挙する
- 連結成分の順序は代表元の昇順, 各連結成分内の頂点は昇順
- $O(n\log n)$
