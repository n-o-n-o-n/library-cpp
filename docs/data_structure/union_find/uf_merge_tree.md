---
title: Union Find Merge Tree
documentation_of: //src/data_structure/union_find/uf_merge_tree.hpp
---

union find のマージ過程を表す木を構築する.
元の頂点は $0,1,\dots,n-1$ 番の葉で, 異なる連結成分のマージごとに新しい親節点が作られる.

## Constructor

```
uf_merge_tree uf(int n)
```

- $n$ 頂点で初期化する
- $O(n)$

## merge

```
int merge(int u, int v)
```

- $u$ と $v$ が異なる連結成分なら, 両成分の木の根を子とする節点を作り, その番号を返す
    - 新しい節点の番号は $n,n+1,\dots$ の順に付く
- $u,v$ が同じ連結成分に属するなら何もせず, その成分の根の番号を返す
- ならし $O(\alpha(n))$

## parents

```
vector<int> parents() const
```

- 構築した森の各節点の親を返す. 返り値の $i$ 番目は節点 $i$ の親で, 根なら $-1$
- 返り値の長さは現在の節点数. 最大 $2n-1$
- $O(n)$
