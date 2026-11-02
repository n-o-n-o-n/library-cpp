---
title: Foldable Union Find
documentation_of: //src/data_structure/union_find/foldable_union_find.hpp
---

各頂点の値を管理し, 連結成分ごとの総積を取得できる union find.

## Constructor

```
foldable_union_find<Abelian_Monoid> uf(int n)
```

- $n$ 頂点で初期化する. 各頂点の初期値は `e()`
- `Abelian_Monoid` には型 `S`, 可換な二項演算 `op`, 単位元 `e`, 逆元 `inv` が必要

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

## set

```
void set(int u, const S &x)
```

- 頂点 $u$ の値を $x$ に変更する
- ならし $O(\alpha(n))$

## prod

```
S prod(int u)
```

- $u$ が属する連結成分の頂点の値を `op` でまとめた結果を返す
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
