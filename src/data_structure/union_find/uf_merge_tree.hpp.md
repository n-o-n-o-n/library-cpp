---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/uf_merge_tree.test.cpp
    title: test/data_structure/union_find/uf_merge_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/union_find/uf_merge_tree.hpp\"\n#include\
    \ <cassert>\n#include <numeric>\n#include <vector>\n#line 3 \"src/data_structure/union_find/union_find.hpp\"\
    \n#include <iterator>\n#line 6 \"src/data_structure/union_find/union_find.hpp\"\
    \nusing namespace std;\n\nstruct union_find {\n    union_find(int n) : p(n, -1),\
    \ cyc(n) {\n        iota(cyc.begin(), cyc.end(), 0);\n    }\n    int leader(int\
    \ u) {\n        assert(0 <= u && u < ssize(p));\n        return p[u] < 0 ? u :\
    \ p[u] = leader(p[u]);\n    }\n    bool same(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        return\
    \ leader(u) == leader(v);\n    }\n    int merge(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        u =\
    \ leader(u);\n        v = leader(v);\n        if (u == v) return u;\n        if\
    \ (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n        p[v] = u;\n      \
    \  swap(cyc[u], cyc[v]);\n        return u;\n    }\n    int size(int u) {\n  \
    \      assert(0 <= u && u < ssize(p));\n        return -p[leader(u)];\n    }\n\
    \    vector<int> group(int u) {\n        assert(0 <= u && u < ssize(p));\n   \
    \     vector<int> res = {u};\n        int v = cyc[u];\n        while (v != u)\
    \ {\n            res.push_back(v);\n            v = cyc[v];\n        }\n     \
    \   return res;\n    }\n    vector<vector<int>> groups() {\n        int n = p.size();\n\
    \        vector<vector<int>> tmp(n);\n        for (int i = 0; i < n; i++) {\n\
    \            tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n\
    \        }\n        return res;\n    }\nprivate:\n    vector<int> p, cyc;\n};\n\
    #line 6 \"src/data_structure/union_find/uf_merge_tree.hpp\"\nusing namespace std;\n\
    \nstruct uf_merge_tree {\n    uf_merge_tree(int _n = 0) : n(_n), c(_n), par(2\
    \ * _n, -1), top(_n), uf(_n) {\n        iota(top.begin(), top.end(), 0);\n   \
    \ }\n    int merge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        u = uf.leader(u);\n        v = uf.leader(v);\n\
    \        if (u == v) return top[u];\n        int tu = top[u];\n        int tv\
    \ = top[v];\n        par[tu] = c;\n        par[tv] = c;\n        top[uf.merge(u,\
    \ v)] = c;\n        return c++;\n    }\n    vector<int> parents() const {\n  \
    \      return vector<int>(par.begin(), par.begin() + c);\n    }\nprivate:\n  \
    \  int n, c;\n    vector<int> par, top;\n    union_find uf;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    #include \"union_find.hpp\"\nusing namespace std;\n\nstruct uf_merge_tree {\n\
    \    uf_merge_tree(int _n = 0) : n(_n), c(_n), par(2 * _n, -1), top(_n), uf(_n)\
    \ {\n        iota(top.begin(), top.end(), 0);\n    }\n    int merge(int u, int\
    \ v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n \
    \       u = uf.leader(u);\n        v = uf.leader(v);\n        if (u == v) return\
    \ top[u];\n        int tu = top[u];\n        int tv = top[v];\n        par[tu]\
    \ = c;\n        par[tv] = c;\n        top[uf.merge(u, v)] = c;\n        return\
    \ c++;\n    }\n    vector<int> parents() const {\n        return vector<int>(par.begin(),\
    \ par.begin() + c);\n    }\nprivate:\n    int n, c;\n    vector<int> par, top;\n\
    \    union_find uf;\n};\n"
  dependsOn:
  - src/data_structure/union_find/union_find.hpp
  isVerificationFile: false
  path: src/data_structure/union_find/uf_merge_tree.hpp
  requiredBy: []
  timestamp: '2026-11-02 19:54:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/union_find/uf_merge_tree.test.cpp
documentation_of: src/data_structure/union_find/uf_merge_tree.hpp
layout: document
title: Union Find Merge Tree
---

union find のマージ過程を表す木を構築する.
元の頂点は $0,1,\dots,n-1$ 番の葉で, 異なる連結成分のマージごとに新しい親節点が作られる.

## Constructor

```
uf_merge_tree uf(int n)
```

- $n$ 頂点で初期化する
- $O(n)$

## merge

```
int merge(int u, int v)
```

- $u$ と $v$ が異なる連結成分なら, 両成分の木の根を子とする節点を作り, その番号を返す
    - 新しい節点の番号は $n,n+1,\dots$ の順に付く
- $u,v$ が同じ連結成分に属するなら何もせず, その成分の根の番号を返す
- ならし $O(\alpha(n))$

## parents

```
vector<int> parents() const
```

- 構築した森の各節点の親を返す. 返り値の $i$ 番目は節点 $i$ の親で, 根なら $-1$
- 返り値の長さは現在の節点数. 最大 $2n-1$
- $O(n)$
