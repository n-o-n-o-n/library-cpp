---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/centroid_decomposition.test.cpp
    title: test/tree/centroid_decomposition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/centroid_decomposition.hpp\"\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\nstruct centroid_decomposition {\n \
    \   centroid_decomposition() = default;\n    centroid_decomposition(int _n) :\
    \ n(_n), e(0), g(_n) {\n        if (n == 1) build();\n    }\n    centroid_decomposition(const\
    \ vector<vector<int>> &_g) : n(_g.size()), g(_g) {\n        build();\n    }\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        g[u].push_back(v);\n        g[v].push_back(u);\n\
    \        if (++e == n - 1) build();\n    }\n    vector<int> operator[](int u)\
    \ const { return g[u]; }\n    int level(int u) const { return lv[u]; }\n    int\
    \ sub_size(int u) const { return sub[u]; }\n    int parent(int u) const { return\
    \ par[u]; }\n    vector<int> level_vector() const { return lv; }\n    vector<int>\
    \ sub_size_vector() const { return sub; }\n    vector<int> parent_vector() const\
    \ { return par; }\nprivate:\n    int n, e;\n    vector<vector<int>> g;\n    vector<int>\
    \ sz, lv, sub, par;\n    int dfs_size(int u, int p) {\n        sz[u] = 1;\n  \
    \      for (int v : g[u]) {\n            if (v != p && lv[v] == -1) {\n      \
    \          sz[u] += dfs_size(v, u);\n            }\n        }\n        return\
    \ sz[u];\n    }\n    int dfs_centroid(int u, int p, int s) {\n        for (int\
    \ v : g[u]) {\n            if (v != p && lv[v] == -1 && sz[v] > s / 2) {\n   \
    \             return dfs_centroid(v, u, s);\n            }\n        }\n      \
    \  return u;\n    }\n    void decompose(int u, int p, int k) {\n        int s\
    \ = dfs_size(u, -1);\n        int c = dfs_centroid(u, -1, s);\n        lv[c] =\
    \ k;\n        sub[c] = s;\n        par[c] = p;\n        for (int v : g[c]) {\n\
    \            if (lv[v] == -1) {\n                decompose(v, c, k + 1);\n   \
    \         }\n        }\n    }\n    void build() {\n        sz = lv = sub = par\
    \ = vector<int>(n, -1);\n        decompose(0, -1, 0);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \nstruct centroid_decomposition {\n    centroid_decomposition() = default;\n \
    \   centroid_decomposition(int _n) : n(_n), e(0), g(_n) {\n        if (n == 1)\
    \ build();\n    }\n    centroid_decomposition(const vector<vector<int>> &_g) :\
    \ n(_g.size()), g(_g) {\n        build();\n    }\n    void add_edge(int u, int\
    \ v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n \
    \       g[u].push_back(v);\n        g[v].push_back(u);\n        if (++e == n -\
    \ 1) build();\n    }\n    vector<int> operator[](int u) const { return g[u]; }\n\
    \    int level(int u) const { return lv[u]; }\n    int sub_size(int u) const {\
    \ return sub[u]; }\n    int parent(int u) const { return par[u]; }\n    vector<int>\
    \ level_vector() const { return lv; }\n    vector<int> sub_size_vector() const\
    \ { return sub; }\n    vector<int> parent_vector() const { return par; }\nprivate:\n\
    \    int n, e;\n    vector<vector<int>> g;\n    vector<int> sz, lv, sub, par;\n\
    \    int dfs_size(int u, int p) {\n        sz[u] = 1;\n        for (int v : g[u])\
    \ {\n            if (v != p && lv[v] == -1) {\n                sz[u] += dfs_size(v,\
    \ u);\n            }\n        }\n        return sz[u];\n    }\n    int dfs_centroid(int\
    \ u, int p, int s) {\n        for (int v : g[u]) {\n            if (v != p &&\
    \ lv[v] == -1 && sz[v] > s / 2) {\n                return dfs_centroid(v, u, s);\n\
    \            }\n        }\n        return u;\n    }\n    void decompose(int u,\
    \ int p, int k) {\n        int s = dfs_size(u, -1);\n        int c = dfs_centroid(u,\
    \ -1, s);\n        lv[c] = k;\n        sub[c] = s;\n        par[c] = p;\n    \
    \    for (int v : g[c]) {\n            if (lv[v] == -1) {\n                decompose(v,\
    \ c, k + 1);\n            }\n        }\n    }\n    void build() {\n        sz\
    \ = lv = sub = par = vector<int>(n, -1);\n        decompose(0, -1, 0);\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/centroid_decomposition.test.cpp
documentation_of: src/tree/centroid_decomposition.hpp
layout: document
title: Centroid Decomposition
---

重心分解のライブラリ.

## Constructor

```
centroid_decomposition G(int n)
centroid_decomposition G(vector<vector<int>> g)
```

- 前者は $n$ 頂点の木を作り, `add_edge` で $n-1$ 本の辺を追加した時点で分解する
- 後者は無向木の隣接リスト `g` を受け取り, 構築時に分解する

## add_edge

```
void add_edge(int u, int v)
```

- 頂点 $u$ と $v$ の間に辺を追加する
- ちょうど $n-1$ 回呼ばれる必要がある
- 最後の追加時に $O(n\log n)$ で重心分解をする

## level, parent, sub_size

```
int level(int u)
int parent(int u)
int sub_size(int u)
```

- `level` は重心分解木における頂点 $u$ の深さを返す
- `parent` は重心分解木における親を返す(根では $-1$)
- `sub_size` は重心分解木における頂点 $u$ 部分木の大きさを返す
- いずれも $O(1)$

## level_vector, parent_vector, sub_size_vector

```
vector<int> level_vector()
vector<int> parent_vector()
vector<int> sub_size_vector()
```

- 各頂点に対する対応する値を頂点番号順に返す
- $O(n)$
