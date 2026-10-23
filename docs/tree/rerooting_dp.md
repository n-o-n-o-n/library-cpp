---
title: Rerooting DP
documentation_of: //src/tree/rerooting_dp.hpp
---

全方位木 DP をする.
`Monoid` は可換であることが期待される.

## Constructor

```
rerooting_dp<Monoid> T(int n)
```

- $n$ 頂点の木を作る
- $O(n)$

## add_edge

```
void add_edge(int u, int v)
```

- 頂点 $u$ と $v$ の間に辺を追加する
- 辺番号は追加順に $0$ から割り当てられる
- ちょうど $n-1$ 回呼ばれる必要がある
- $O(1)$

## run

```
vector<S> run(apply_vertex, apply_edge)
```

- `apply_vertex(S x, int u)` は隣接する側から集約した値 $x$ に頂点 $u$ を加えた値を返す
- `apply_edge(S x, int i)` は値 $x$ を辺 $i$ の反対側へ渡す際の値を返す
- $O(n)$
