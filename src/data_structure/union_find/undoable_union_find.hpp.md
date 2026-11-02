---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/undoable_union_find.test.cpp
    title: test/data_structure/union_find/undoable_union_find.test.cpp
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
    \ }\n#line 3 \"src/data_structure/union_find/undoable_union_find.hpp\"\n\nstruct\
    \ undoable_union_find {\n    undoable_union_find() = default;\n    undoable_union_find(int\
    \ n) : p(n, -1), cyc(n) {\n        iota(cyc.begin(), cyc.end(), 0);\n    }\n \
    \   int leader(int u) const {\n        assert(0 <= u && u < ssize(p));\n     \
    \   return p[u] < 0 ? u : leader(p[u]);\n    }\n    bool same(int u, int v) const\
    \ {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n\
    \        return leader(u) == leader(v);\n    }\n    void merge(int u, int v) {\n\
    \        assert(0 <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n\
    \        u = leader(u);\n        v = leader(v);\n        his.emplace(u, p[u],\
    \ cyc[u]);\n        his.emplace(v, p[v], cyc[v]);\n        if (u == v) return;\n\
    \        if (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n        p[v] = u;\n\
    \        swap(cyc[u], cyc[v]);\n    }\n    int size(int u) const {\n        assert(0\
    \ <= u && u < ssize(p));\n        return -p[leader(u)];\n    }\n    void undo()\
    \ {\n        assert(his.size());\n        for (auto _ : {0, 1}) {\n          \
    \  auto [u, pu, cu] = his.top();\n            his.pop();\n            p[u] = pu;\n\
    \            cyc[u] = cu;\n        }\n    }\n    vector<int> group(int u) const\
    \ {\n        vector<int> res = {u};\n        int v = cyc[u];\n        while (v\
    \ != u) {\n            res.push_back(v);\n            v = cyc[v];\n        }\n\
    \        return res;\n    }\n    vector<vector<int>> groups() const {\n      \
    \  int n = p.size();\n        vector<vector<int>> tmp(n);\n        for (int i\
    \ = 0; i < n; i++) {\n            tmp[leader(i)].push_back(i);\n        }\n  \
    \      vector<vector<int>> res;\n        for (auto v : tmp) {\n            if\
    \ (v.size()) res.push_back(v);\n        }\n        return res;\n    }\nprivate:\n\
    \    vector<int> p, cyc;\n    stack<tuple<int, int, int>> his;\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\nstruct undoable_union_find\
    \ {\n    undoable_union_find() = default;\n    undoable_union_find(int n) : p(n,\
    \ -1), cyc(n) {\n        iota(cyc.begin(), cyc.end(), 0);\n    }\n    int leader(int\
    \ u) const {\n        assert(0 <= u && u < ssize(p));\n        return p[u] < 0\
    \ ? u : leader(p[u]);\n    }\n    bool same(int u, int v) const {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        return\
    \ leader(u) == leader(v);\n    }\n    void merge(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        u =\
    \ leader(u);\n        v = leader(v);\n        his.emplace(u, p[u], cyc[u]);\n\
    \        his.emplace(v, p[v], cyc[v]);\n        if (u == v) return;\n        if\
    \ (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n        p[v] = u;\n      \
    \  swap(cyc[u], cyc[v]);\n    }\n    int size(int u) const {\n        assert(0\
    \ <= u && u < ssize(p));\n        return -p[leader(u)];\n    }\n    void undo()\
    \ {\n        assert(his.size());\n        for (auto _ : {0, 1}) {\n          \
    \  auto [u, pu, cu] = his.top();\n            his.pop();\n            p[u] = pu;\n\
    \            cyc[u] = cu;\n        }\n    }\n    vector<int> group(int u) const\
    \ {\n        vector<int> res = {u};\n        int v = cyc[u];\n        while (v\
    \ != u) {\n            res.push_back(v);\n            v = cyc[v];\n        }\n\
    \        return res;\n    }\n    vector<vector<int>> groups() const {\n      \
    \  int n = p.size();\n        vector<vector<int>> tmp(n);\n        for (int i\
    \ = 0; i < n; i++) {\n            tmp[leader(i)].push_back(i);\n        }\n  \
    \      vector<vector<int>> res;\n        for (auto v : tmp) {\n            if\
    \ (v.size()) res.push_back(v);\n        }\n        return res;\n    }\nprivate:\n\
    \    vector<int> p, cyc;\n    stack<tuple<int, int, int>> his;\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/data_structure/union_find/undoable_union_find.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/union_find/undoable_union_find.test.cpp
documentation_of: src/data_structure/union_find/undoable_union_find.hpp
layout: document
title: Undoable Union Find
---

undo 可能 union find.

## Constructor

```
undoable_union_find uf(int n)
```

- $n$ 頂点で初期化する

## leader

```
int leader(int u)
```

- $u$ が属する連結成分の代表元を返す
- $O(\log n)$

## same

```
bool same(int u, int v)
```

- $u$ と $v$ が同じ連結成分に属するかを判定する
- $O(\log n)$

## merge

```
void merge(int u, int v)
```

- 辺 $(u,v)$ を追加する
- すでに同じ連結成分でも, 後続の `undo` で取り消す操作として記録する
- $O(\log n)$

## size

```
int size(int u)
```

- $u$ が属する連結成分の要素数を返す
- $O(\log n)$

## undo

```
void undo()
```

- 直前の `merge` を取り消す
- 取り消せる `merge` が存在することが必要
- $O(1)$

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
- $O(n\log n)$
