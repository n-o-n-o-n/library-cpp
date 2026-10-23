---
title: Heavy Light Decomposition
documentation_of: //src/tree/hld.hpp
---

木に対するパスクエリを扱う.

以下の計算量は `SegTree` 内部での計算量を無視している(例えば, 通常のセグ木で `prod` を呼ぶと $O(\log^2 n)$).

## Constructor

```
heavy_light_decomposition<SegTree, edge, commutative> G(int n, int r = 0)
```

- $n$ 頂点の木を根 $r$ で初期化する
- `SegTree` は型 `M` と点更新, 点取得, 区間積を持つセグ木とする
- `edge` $=$ `false` は頂点に値を持ち, `edge` $=$ `true` は辺に値を持つ
- `commutative` $=$ `false` では非可換クエリを扱える

## add_edge

```
void add_edge(int u, int v, S w = M::e())
```

- $u$ と $v$ の間に辺を追加する
- `edge` $=$ `true` のとき, 辺の初期値に $w$ を使う
- ちょうど $n-1$ 回呼ばれる必要がある
- 最後の辺の追加時に構築され, $O(n)$
- それ以外の追加は $O(1)$

## lca

```
int lca(int u, int v)
```

- 頂点 $u$ と $v$ の LCA を返す
- $O(\log n)$

## set

```
void set(int u, S w)
void set(int u, int v, S w)
```

- 頂点 $u$ の形式では, その頂点の位置にある値を $w$ に設定する
- 辺 $(u, v)$ の形式では, 隣接する $u, v$ を結ぶ辺の値を $w$ に設定する
- $O(1)$

## get

```
S get(int u)
S get(int u, int v)
```

- 頂点 $u$ の形式では, その頂点の位置にある値を返す
- 辺 $(u, v)$ の形式では, 隣接する $u, v$ を結ぶ辺の値を返す
- $O(1)$

## apply, subtree_apply

```
void apply(int u, int v, f)
void subtree_apply(int u, f)
```

- `apply` はパス $u$ から $v$ に `f` を適用する
- `f` には区間更新を表すラムダ式などを渡す
- `subtree_apply` は根 $r$ に関する頂点 $u$ の部分木に `f` を適用する
- `edge` $=$ `true` では, パスと部分木に含まれる辺に適用する
- `SegTree` が区間 `apply` に対応する必要がある
- `apply` は $O(\log n)$, `subtree_apply` は $O(1)$

## prod, subtree_prod

```
S prod(int u, int v)
S subtree_prod(int u)
```

- `prod` はパス $u$ から $v$ の値の積を, その向きの順序で返す
- `subtree_prod` は根 $r$ に関する頂点 $u$ の部分木の値の積を返す
- `edge` $=$ `true` では対象となる辺の値の積を返す
- `prod` は $O(\log n)$, `subtree_prod` は $O(1)$

## binary_search

```
int binary_search(int u, int v, check)
```

- パス上の二分探索を行う
- 全体が条件を満たす場合は $v$ を返す
- `check(M::e())` は `true` である必要がある
- $O(\log n)$
