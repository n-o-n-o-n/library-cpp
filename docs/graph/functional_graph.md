---
title: Functional Graph
documentation_of: //src/graph/functional_graph.hpp
---

各頂点の出次数がちょうど $1$ である有向グラフを扱う.

## Constructor

```
functional_graph G(int n)
functional_graph G(const vector<int> &a)
```

## add_edge

```
void add_edge(int u, int v)
```

- $u\rightarrow v$ の辺を張る
- $0,1,\dots,n-1$ がちょうど $1$ 回 $u$ として呼ばれる必要がある

## steps

```
int steps(int u, long long k)
```

- 頂点 $u$ から $k$ 回遷移した先を返す
    - $k \ge 0$ とし, $k=0$ なら $u$ を返す
- $O(\log k)$ (ただし, 前計算に $O(n\log k)$ かかる)

## table

```
vector<int> table(long long k)
```

- すべての頂点について $k$ 回遷移した先を返す. 返り値の $u$ 番目は `steps(u, k)` と等しい
    - $k \ge 0$ とし, $k=0$ なら $(0,1,\ldots,n-1)$ を返す
- $O(n\log k)$

## binary_search

```
pair<int, int> binary_search(int u, check)
```

- `check` は $\{0,1,\dots,n-1\}\to \text{bool}$ のラムダ式関数が想定される
- $f$ を 1 回の遷移とし, `check(f^k(u)) == true` となる最大の $k$ を求める
    - `check(u) == true` が必要
    - 返り値は `{k, f^k(u)}`
    - $k$ に最大値が存在すれば $n$ 以下なので, $n$ 回以内に `false` とならない場合は `{-1, -1}` を返す
- $O(\log n)$ (ただし, 前計算に $O(n\log n)$ かかる)
