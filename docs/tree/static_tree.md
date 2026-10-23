---
title: Static Tree
documentation_of: //src/tree/static_tree.hpp
---

静的な木の LCA, 距離, パス, 部分木などを扱う.
辺は単位重みを持つとする.

## Constructor

```
static_tree G(int n, int r = 0)
```

- $n$ 頂点の木を根 $r$ で初期化する
- $O(n)$

## add_edge

```
void add_edge(int u, int v)
```

- 頂点 $u$ と $v$ を辺で結ぶ
- ちょうど $n-1$ 回呼ばれる必要がある
- 通常は $O(1)$, 最後の追加時は $O(n)$

## read_edges

```
void read_edges(bool idx = 1)
```

- 標準入力から $n-1$ 本の辺を読み込み, 前処理を行う
- `idx = 1` なら入力を $1$-indexed, `idx = 0` なら $0$-indexed として扱う
- $O(n)$

## set_root

```
void set_root(int r)
```

- $n-1$ 本の辺を追加した後, 根を $r$ に変更して前処理をやり直す
- $O(n)$

## operator[]

```
vector<int> operator[](int u)
```

- 元の木で頂点 $u$ に隣接する頂点のリストを返す
- $O(1)$

## depth

```
int depth(int u)
```

- 現在の根から頂点 $u$ までの辺数を返す
- $O(1)$

## lca

```
int lca(int u, int v, int r = -1)
```

- 頂点 $u$ と $v$ の LCA を返す
- $r$ を指定した場合は, 木の根を $r$ とみなしたときの LCA を返す
- $r = -1$ の場合は現在の根を使う
- $O(1)$

## dist

```
int dist(int u, int v)
```

- 頂点 $u$ と $v$ の距離を辺数で返す
- $O(1)$

## jump

```
int jump(int u, int v, int k)
```

- $k \ge 0$ とし, パス $u$ から $v$ に沿って $u$ から $k$ 辺進んだ頂点を返す
- $k = 0$ なら $u$ を返し, $k$ が距離を超えると $-1$ を返す
- $O(\log n)$

## is_on_path

```
bool is_on_path(int w, int u, int v)
```

- 頂点 $w$ がパス $u$ から $v$ 上にあるかを返す
- 両端点もパス上に含む
- $O(1)$

## sub_size

```
int sub_size(int u, int r = -1)
```

- 木の根を $r$ とみなしたときの頂点 $u$ の部分木の頂点数を返す
- $r = -1$ の場合は現在の根を使う
- $O(1)$

## path

```
vector<int> path(int u, int v)
```

- パス $u$ から $v$ 上の頂点を順に返す
- 返り値には $u$ と $v$ も含む
- パスの頂点数を $k$ として $O(k)$

## auxiliary_tree

```
vector<pair<int, int>> auxiliary_tree(vector<int> vs)
```

- `vs` の頂点と必要な LCA からなる補助木の辺を返す
- 返り値は, 元の木の頂点番号で子と親を組にしたもの
- `vs` に含まれる頂点数を $k$ として $O(k\log k)$
