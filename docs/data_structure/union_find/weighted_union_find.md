---
title: Weighted Union Find
documentation_of: //src/data_structure/union_find/weighted_union_find.hpp
---

重み付き union find.
各頂点 $u$ のポテンシャルを $a_u$ とする.

## Constructor

```
weighted_union_find<Abelian_Group> uf(int n)
```

- $n$ 頂点で初期化する
- `Abelian_Group` には型 `S`, 二項演算 `op`, 単位元 `e`, 逆元 `inv` が必要

## leader

```
int leader(int u)
```

- $u$ が属する連結成分の代表元を返す
- ならし $O(\alpha(n))$

## weight

```
S weight(int u)
```

- 代表元を $r$ として $a_u-a_r$ を返す
- 代表元が変わると返り値も変わりうる
- ならし $O(\alpha(n))$

## same

```
bool same(int u, int v)
```

- $u$ と $v$ が同じ連結成分に属するかを判定する
- ならし $O(\alpha(n))$

## merge

```
bool merge(int u, int v, S w)
```

- 辺 $(u,v)$ を追加し, $a_v-a_u=w$ という制約を課す
- 既存の制約と矛盾する場合は `false` を返し, この辺を追加しない
- 矛盾しない場合は `true` を返す
- ならし $O(\alpha(n))$

## diff

```
S diff(int u, int v)
```

- $a_v-a_u$ を返す
- `same(u, v)` が `true` であることが必要
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
- 連結成分の順序は代表元の昇順, 各連結成分内の頂点は昇順
- $O(n\alpha(n))$
