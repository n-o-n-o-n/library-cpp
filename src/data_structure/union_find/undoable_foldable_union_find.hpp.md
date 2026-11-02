---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/offline_dynamic_connectivity.hpp
    title: Offline Dynamic Connectivity
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/offline_dynamic_connectivity.test.cpp
    title: test/data_structure/union_find/offline_dynamic_connectivity.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/undoable_foldable_union_find.test.cpp
    title: test/data_structure/union_find/undoable_foldable_union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/union_find/undoable_foldable_union_find.hpp\"\
    \n#include <cassert>\n#include <iterator>\n#include <numeric>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Abelian_Monoid>\nstruct undoable_foldable_union_find {\n    using M = Abelian_Monoid;\n\
    \    using S = M::S;\n    undoable_foldable_union_find(int n) : p(n, -1), cyc(n),\
    \ a(n, M::e()), d(n, M::e()) {\n        iota(cyc.begin(), cyc.end(), 0);\n   \
    \ }\n    int leader(int u) const {\n        assert(0 <= u && u < ssize(p));\n\
    \        return p[u] < 0 ? u : leader(p[u]);\n    }\n    bool same(int u, int\
    \ v) const {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v &&\
    \ v < ssize(p));\n        return leader(u) == leader(v);\n    }\n    void merge(int\
    \ u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v\
    \ && v < ssize(p));\n        u = leader(u);\n        v = leader(v);\n        if\
    \ (p[u] > p[v]) swap(u, v);\n        his_type.push_back(false);\n        his_merge.emplace_back(u,\
    \ v, p[u], p[v], cyc[u], cyc[v], d[u]);\n        if (u == v) return;\n       \
    \ p[u] += p[v];\n        d[u] = M::op(d[u], d[v]);\n        p[v] = u;\n      \
    \  swap(cyc[u], cyc[v]);\n    }\n    int size(int u) const {\n        assert(0\
    \ <= u && u < ssize(p));\n        return -p[leader(u)];\n    }\n    void set(int\
    \ u, const S &x) {\n        assert(0 <= u && u < ssize(p));\n        int r = leader(u);\n\
    \        his_type.push_back(true);\n        his_set.emplace_back(u, r, a[u], d[r]);\n\
    \        d[r] = M::op(d[r], M::op(M::inv(a[u]), x));\n        a[u] = x;\n    }\n\
    \    S prod(int u) const {\n        assert(0 <= u && u < ssize(p));\n        return\
    \ d[leader(u)];\n    }\n    void undo() {\n        assert(!his_type.empty());\n\
    \        bool is_set = his_type.back();\n        his_type.pop_back();\n      \
    \  if (is_set) {\n            auto [u, r, val, fld] = his_set.back();\n      \
    \      his_set.pop_back();\n            a[u] = val;\n            d[r] = fld;\n\
    \        } else {\n            auto [u, v, pu, pv, cu, cv, fld] = his_merge.back();\n\
    \            his_merge.pop_back();\n            if (u == v) return;\n        \
    \    p[u] = pu;\n            p[v] = pv;\n            cyc[u] = cu;\n          \
    \  cyc[v] = cv;\n            d[u] = fld;\n        }\n    }\n    vector<int> group(int\
    \ u) const {\n        assert(0 <= u && u < ssize(p));\n        vector<int> res\
    \ = {u};\n        int v = cyc[u];\n        while (v != u) {\n            res.push_back(v);\n\
    \            v = cyc[v];\n        }\n        return res;\n    }\n    vector<vector<int>>\
    \ groups() const {\n        int n = p.size();\n        vector<vector<int>> tmp(n);\n\
    \        for (int i = 0; i < n; i++) tmp[leader(i)].push_back(i);\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) if (v.size()) res.push_back(v);\n        return\
    \ res;\n    }\nprivate:\n    vector<int> p, cyc;\n    vector<S> a, d;\n    vector<bool>\
    \ his_type;\n    vector<tuple<int, int, S, S>> his_set;\n    vector<tuple<int,\
    \ int, int, int, int, int, S>> his_merge;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <iterator>\n#include <numeric>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Abelian_Monoid>\nstruct undoable_foldable_union_find {\n \
    \   using M = Abelian_Monoid;\n    using S = M::S;\n    undoable_foldable_union_find(int\
    \ n) : p(n, -1), cyc(n), a(n, M::e()), d(n, M::e()) {\n        iota(cyc.begin(),\
    \ cyc.end(), 0);\n    }\n    int leader(int u) const {\n        assert(0 <= u\
    \ && u < ssize(p));\n        return p[u] < 0 ? u : leader(p[u]);\n    }\n    bool\
    \ same(int u, int v) const {\n        assert(0 <= u && u < ssize(p));\n      \
    \  assert(0 <= v && v < ssize(p));\n        return leader(u) == leader(v);\n \
    \   }\n    void merge(int u, int v) {\n        assert(0 <= u && u < ssize(p));\n\
    \        assert(0 <= v && v < ssize(p));\n        u = leader(u);\n        v =\
    \ leader(v);\n        if (p[u] > p[v]) swap(u, v);\n        his_type.push_back(false);\n\
    \        his_merge.emplace_back(u, v, p[u], p[v], cyc[u], cyc[v], d[u]);\n   \
    \     if (u == v) return;\n        p[u] += p[v];\n        d[u] = M::op(d[u], d[v]);\n\
    \        p[v] = u;\n        swap(cyc[u], cyc[v]);\n    }\n    int size(int u)\
    \ const {\n        assert(0 <= u && u < ssize(p));\n        return -p[leader(u)];\n\
    \    }\n    void set(int u, const S &x) {\n        assert(0 <= u && u < ssize(p));\n\
    \        int r = leader(u);\n        his_type.push_back(true);\n        his_set.emplace_back(u,\
    \ r, a[u], d[r]);\n        d[r] = M::op(d[r], M::op(M::inv(a[u]), x));\n     \
    \   a[u] = x;\n    }\n    S prod(int u) const {\n        assert(0 <= u && u <\
    \ ssize(p));\n        return d[leader(u)];\n    }\n    void undo() {\n       \
    \ assert(!his_type.empty());\n        bool is_set = his_type.back();\n       \
    \ his_type.pop_back();\n        if (is_set) {\n            auto [u, r, val, fld]\
    \ = his_set.back();\n            his_set.pop_back();\n            a[u] = val;\n\
    \            d[r] = fld;\n        } else {\n            auto [u, v, pu, pv, cu,\
    \ cv, fld] = his_merge.back();\n            his_merge.pop_back();\n          \
    \  if (u == v) return;\n            p[u] = pu;\n            p[v] = pv;\n     \
    \       cyc[u] = cu;\n            cyc[v] = cv;\n            d[u] = fld;\n    \
    \    }\n    }\n    vector<int> group(int u) const {\n        assert(0 <= u &&\
    \ u < ssize(p));\n        vector<int> res = {u};\n        int v = cyc[u];\n  \
    \      while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() const\
    \ {\n        int n = p.size();\n        vector<vector<int>> tmp(n);\n        for\
    \ (int i = 0; i < n; i++) tmp[leader(i)].push_back(i);\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) if (v.size()) res.push_back(v);\n        return\
    \ res;\n    }\nprivate:\n    vector<int> p, cyc;\n    vector<S> a, d;\n    vector<bool>\
    \ his_type;\n    vector<tuple<int, int, S, S>> his_set;\n    vector<tuple<int,\
    \ int, int, int, int, int, S>> his_merge;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/union_find/undoable_foldable_union_find.hpp
  requiredBy:
  - src/data_structure/union_find/offline_dynamic_connectivity.hpp
  timestamp: '2026-11-02 19:54:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/union_find/offline_dynamic_connectivity.test.cpp
  - test/data_structure/union_find/undoable_foldable_union_find.test.cpp
documentation_of: src/data_structure/union_find/undoable_foldable_union_find.hpp
layout: document
title: Undoable Foldable Union Find
---

各頂点の値を管理し, 連結成分ごとの総積を取得できる undo 可能 union find.

## Constructor

```
undoable_foldable_union_find<Abelian_Monoid> uf(int n)
```

- $n$ 頂点で初期化する. 各頂点の初期値は `e()`
- `Abelian_Monoid` には型 `S`, 可換な二項演算 `op`, 単位元 `e`, 逆元 `inv` が必要

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

## set

```
void set(int u, const S &x)
```

- 頂点 $u$ の値を $x$ に変更する
- $O(\log n)$

## prod

```
S prod(int u)
```

- $u$ が属する連結成分の頂点の値を `op` でまとめた結果を返す
- $O(\log n)$

## undo

```
void undo()
```

- 直前の `merge` または `set` を取り消す
- 取り消せる操作が存在することが必要
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
