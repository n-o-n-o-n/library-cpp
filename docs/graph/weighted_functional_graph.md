---
title: Weighted Functional Graph
documentation_of: //src/graph/weighted_functional_graph.hpp
---

各頂点の出次数がちょうど $1$ である重み付き有向グラフを扱う.

`Monoid` は型 `S`, 演算 `op`, 単位元 `e` を持つ.
`edge=true` なら辺重み, `edge=false` なら頂点重みを扱う.
頂点重みの場合, 始点と終点の重みも含めて計算する.

重みは遷移順に合成する.

## Constructor

```
weighted_functional_graph<Monoid, edge> G(int n)
```

## add_edge

```
void add_edge(int u, int v, const S &x = Monoid::e())
```

- $u\rightarrow v$ の辺を張る. `edge=true` なら `x` はその辺の重み, `edge=false` なら頂点 $u$ の重みになる
- 各頂点をちょうど $1$ 回 `u` として指定する

## set_weight

```
void set_weight(int u, const S &x)
```

- `edge=false` のとき, 頂点 $u$ の重みを `x` に設定する

## steps

```
pair<int, S> steps(int u, long long k)
```

- $u$ から $k$ 回遷移した頂点と重みを返す
- $O(\log k)$ (ただし, 前計算に $O(n\log k)$ かかる)

## table

```
pair<vector<int>, vector<S>> table(long long k)
```

- すべての頂点について `steps(u, k)` を求める. 返り値の各ベクトルの $u$ 番目が, それぞれ到達頂点と集約値になる
- $O(n\log k)$

## binary_search

```
pair<long long, pair<int, S>> binary_search(int u, long long k, check)
```

- `check` は $S \to \text{bool}$ のラムダ式関数が想定される
- $0$ 回から $k$ 回までの遷移のうち, `check` が `true` となる最大の回数 $r$ を求める
    - 辺重みの場合 `check(e) == true` が必要
    - 頂点重みの場合 `check(w[u]) == true` が必要
    - 返り値は `{r, steps(u, r)}` で, $k$ 回遷移しても `true` なら `{k, steps(u, k)}` を返す
- $O(\log k)$ (ただし, 前計算に $O(n\log k)$ かかる)
