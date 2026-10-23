---
title: Centroid Decomposition
documentation_of: //src/tree/centroid_decomposition.hpp
---

重心分解のライブラリ.

## Constructor

```
centroid_decomposition G(int n)
centroid_decomposition G(vector<vector<int>> g)
```

- 前者は $n$ 頂点の木を作り, `add_edge` で $n-1$ 本の辺を追加した時点で分解する
- 後者は無向木の隣接リスト `g` を受け取り, 構築時に分解する

## add_edge

```
void add_edge(int u, int v)
```

- 頂点 $u$ と $v$ の間に辺を追加する
- ちょうど $n-1$ 回呼ばれる必要がある
- 最後の追加時に $O(n\log n)$ で重心分解をする

## level, parent, sub_size

```
int level(int u)
int parent(int u)
int sub_size(int u)
```

- `level` は重心分解木における頂点 $u$ の深さを返す
- `parent` は重心分解木における親を返す(根では $-1$)
- `sub_size` は重心分解木における頂点 $u$ 部分木の大きさを返す
- いずれも $O(1)$

## level_vector, parent_vector, sub_size_vector

```
vector<int> level_vector()
vector<int> parent_vector()
vector<int> sub_size_vector()
```

- 各頂点に対する対応する値を頂点番号順に返す
- $O(n)$
