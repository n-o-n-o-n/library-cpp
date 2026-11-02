---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/uf_merge_tree.hpp
    title: Union Find Merge Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/uf_merge_tree.test.cpp
    title: test/data_structure/union_find/uf_merge_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/union_find.test.cpp
    title: test/data_structure/union_find/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/misc/parallel_binary_search.test.cpp
    title: test/misc/parallel_binary_search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/data_structure/union_find/union_find.hpp\"\n\nstruct union_find\
    \ {\n    union_find(int n) : p(n, -1), cyc(n) {\n        iota(cyc.begin(), cyc.end(),\
    \ 0);\n    }\n    int leader(int u) {\n        assert(0 <= u && u < ssize(p));\n\
    \        return p[u] < 0 ? u : p[u] = leader(p[u]);\n    }\n    bool same(int\
    \ u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v\
    \ && v < ssize(p));\n        return leader(u) == leader(v);\n    }\n    int merge(int\
    \ u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v\
    \ && v < ssize(p));\n        u = leader(u);\n        v = leader(v);\n        if\
    \ (u == v) return u;\n        if (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n\
    \        p[v] = u;\n        swap(cyc[u], cyc[v]);\n        return u;\n    }\n\
    \    int size(int u) {\n        assert(0 <= u && u < ssize(p));\n        return\
    \ -p[leader(u)];\n    }\n    vector<int> group(int u) {\n        assert(0 <= u\
    \ && u < ssize(p));\n        vector<int> res = {u};\n        int v = cyc[u];\n\
    \        while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() {\n \
    \       int n = p.size();\n        vector<vector<int>> tmp(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            tmp[leader(i)].push_back(i);\n        }\n\
    \        vector<vector<int>> res;\n        for (auto v : tmp) {\n            if\
    \ (v.size()) res.push_back(v);\n        }\n        return res;\n    }\nprivate:\n\
    \    vector<int> p, cyc;\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\nstruct union_find {\n  \
    \  union_find(int n) : p(n, -1), cyc(n) {\n        iota(cyc.begin(), cyc.end(),\
    \ 0);\n    }\n    int leader(int u) {\n        assert(0 <= u && u < ssize(p));\n\
    \        return p[u] < 0 ? u : p[u] = leader(p[u]);\n    }\n    bool same(int\
    \ u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v\
    \ && v < ssize(p));\n        return leader(u) == leader(v);\n    }\n    int merge(int\
    \ u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v\
    \ && v < ssize(p));\n        u = leader(u);\n        v = leader(v);\n        if\
    \ (u == v) return u;\n        if (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n\
    \        p[v] = u;\n        swap(cyc[u], cyc[v]);\n        return u;\n    }\n\
    \    int size(int u) {\n        assert(0 <= u && u < ssize(p));\n        return\
    \ -p[leader(u)];\n    }\n    vector<int> group(int u) {\n        assert(0 <= u\
    \ && u < ssize(p));\n        vector<int> res = {u};\n        int v = cyc[u];\n\
    \        while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() {\n \
    \       int n = p.size();\n        vector<vector<int>> tmp(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            tmp[leader(i)].push_back(i);\n        }\n\
    \        vector<vector<int>> res;\n        for (auto v : tmp) {\n            if\
    \ (v.size()) res.push_back(v);\n        }\n        return res;\n    }\nprivate:\n\
    \    vector<int> p, cyc;\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/data_structure/union_find/union_find.hpp
  requiredBy:
  - src/data_structure/union_find/uf_merge_tree.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/union_find/union_find.test.cpp
  - test/data_structure/union_find/uf_merge_tree.test.cpp
  - test/misc/parallel_binary_search.test.cpp
documentation_of: src/data_structure/union_find/union_find.hpp
layout: document
title: Union Find
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
int merge(int u, int v)
```

- 辺 $(u,v)$ を追加する
- マージ後の連結成分の代表元を返す
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
