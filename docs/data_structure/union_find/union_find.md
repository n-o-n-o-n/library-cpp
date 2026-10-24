---
title: Union Find
documentation_of: //src/data_structure/union_find/union_find.hpp
---

union find.

## Constructor

```
union_find uf(int n)
```

- $n$ 頂点で初期化する

## leader

```
int leader(int u)
```

- $u$ が属する連結成分の代表元を返す
- ならし $O(\alpha(n))$

## same

```
bool same(int u, int v)
```

- $u$ と $v$ が同じ連結成分に属するかを判定する
- ならし $O(\alpha(n))$

## merge

```
void merge(int u, int v)
```

- 辺 $(u,v)$ を追加する
- ならし $O(\alpha(n))$

## size

```
int size(int u)
```

- $u$ が属する連結成分の要素数を返す
- ならし $O(\alpha(n))$

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
- 集合の順序は代表元の昇順, 集合内の頂点は昇順
- $O(n\alpha(n))$
