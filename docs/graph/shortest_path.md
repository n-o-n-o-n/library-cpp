---
title: Shortest Path
documentation_of: //src/graph/shortest_path.hpp
---

非負辺重みの有向グラフの最短経路を求める.

内部でいい感じに BFS と Dijkstra を使い分ける.

## Constructor

```
shortest_path<T> G(int n)
shortest_path<T> G(const vector<vector<int>> &g)
shortest_path<T> G(const vector<vector<pair<int, T2>>> &g)
```

- `n` は頂点数
- `vector<vector<int>>` では各辺の重みを $1$ とする
- `vector<vector<pair<int, T2>>>` では `g[u]` の `(v, w)` を $u\rightarrow v$ の重み $w$ の辺とする

## add_edge

```
void add_edge(int u, int v, T w = 1)
```

- $u\rightarrow v$ の重み $w$ の辺を追加する
- $w \ge 0$

## table

```
vector<T> table(int s)
```

- $s$ から各頂点への最短距離を返す. 到達不能な頂点の値は `-1`

## dist

```
T dist(int s, int t)
```

- $s$ から $t$ への最短距離を返す
- 到達不能なら `-1` を返す

## path

```
vector<int> path(int s, int t)
```

- 最短路上の頂点列を $s$ から $t$ の順で返す
- 到達不能なら空の列を返す