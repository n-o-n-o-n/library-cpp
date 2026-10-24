---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/weighted_union_find.test.cpp
    title: test/data_structure/union_find/weighted_union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/union_find/weighted_union_find.hpp\"\n\
    #include <cassert>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Abelian_Group>\nstruct weighted_union_find {\n    using S\
    \ = Abelian_Group::S;\n    weighted_union_find(int _n) : n(_n), p(n, -1), cyc(n),\
    \ d(n, Abelian_Group::e()) {\n        iota(cyc.begin(), cyc.end(), 0);\n    }\n\
    \    int leader(int u) {\n        assert(0 <= u && u < n);\n        if (p[u] <\
    \ 0) return u;\n        int r = leader(p[u]);\n        d[u] = Abelian_Group::op(d[u],\
    \ d[p[u]]);\n        return p[u] = r;\n    }\n    S weight(int u) {\n        assert(0\
    \ <= u && u < n);\n        leader(u);\n        return d[u];\n    }\n    bool same(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        return leader(u) == leader(v);\n    }\n    bool merge(int u, int\
    \ v, S w) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        if (same(u, v)) {\n            return diff(u, v) == w;\n        }\n \
    \       w = Abelian_Group::op(w, weight(u));\n        w = Abelian_Group::op(w,\
    \ Abelian_Group::inv(weight(v)));\n        u = leader(u);\n        v = leader(v);\n\
    \        assert(u != v);\n        if (p[u] > p[v]) {\n            swap(u, v);\n\
    \            w = Abelian_Group::inv(w);\n        }\n        p[u] += p[v];\n  \
    \      p[v] = u;\n        d[v] = w;\n        swap(cyc[u], cyc[v]);\n        return\
    \ true;\n    }\n    S diff(int u, int v) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        return Abelian_Group::op(Abelian_Group::inv(weight(u)),\
    \ weight(v));\n    }\n    int size(int u) {\n        assert(0 <= u && u < n);\n\
    \        return -p[leader(u)];\n    }\n    vector<int> group(int u) {\n      \
    \  assert(0 <= u && u < n);\n        vector<int> res = {u};\n        int v = cyc[u];\n\
    \        while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() {\n \
    \       vector<vector<int>> tmp(n);\n        for (int i = 0; i < n; i++) {\n \
    \           tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n\
    \        }\n        return res;\n    }\nprivate:\n    int n;\n    vector<int>\
    \ p, cyc;\n    vector<S> d;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename Abelian_Group>\nstruct weighted_union_find\
    \ {\n    using S = Abelian_Group::S;\n    weighted_union_find(int _n) : n(_n),\
    \ p(n, -1), cyc(n), d(n, Abelian_Group::e()) {\n        iota(cyc.begin(), cyc.end(),\
    \ 0);\n    }\n    int leader(int u) {\n        assert(0 <= u && u < n);\n    \
    \    if (p[u] < 0) return u;\n        int r = leader(p[u]);\n        d[u] = Abelian_Group::op(d[u],\
    \ d[p[u]]);\n        return p[u] = r;\n    }\n    S weight(int u) {\n        assert(0\
    \ <= u && u < n);\n        leader(u);\n        return d[u];\n    }\n    bool same(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        return leader(u) == leader(v);\n    }\n    bool merge(int u, int\
    \ v, S w) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        if (same(u, v)) {\n            return diff(u, v) == w;\n        }\n \
    \       w = Abelian_Group::op(w, weight(u));\n        w = Abelian_Group::op(w,\
    \ Abelian_Group::inv(weight(v)));\n        u = leader(u);\n        v = leader(v);\n\
    \        assert(u != v);\n        if (p[u] > p[v]) {\n            swap(u, v);\n\
    \            w = Abelian_Group::inv(w);\n        }\n        p[u] += p[v];\n  \
    \      p[v] = u;\n        d[v] = w;\n        swap(cyc[u], cyc[v]);\n        return\
    \ true;\n    }\n    S diff(int u, int v) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        return Abelian_Group::op(Abelian_Group::inv(weight(u)),\
    \ weight(v));\n    }\n    int size(int u) {\n        assert(0 <= u && u < n);\n\
    \        return -p[leader(u)];\n    }\n    vector<int> group(int u) {\n      \
    \  assert(0 <= u && u < n);\n        vector<int> res = {u};\n        int v = cyc[u];\n\
    \        while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() {\n \
    \       vector<vector<int>> tmp(n);\n        for (int i = 0; i < n; i++) {\n \
    \           tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n\
    \        }\n        return res;\n    }\nprivate:\n    int n;\n    vector<int>\
    \ p, cyc;\n    vector<S> d;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/union_find/weighted_union_find.hpp
  requiredBy: []
  timestamp: '2026-10-24 16:40:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/union_find/weighted_union_find.test.cpp
documentation_of: src/data_structure/union_find/weighted_union_find.hpp
layout: document
title: Weighted Union Find
---

重み付き union find.
各頂点 $u$ のポテンシャルを $a_u$ とする.

## Constructor

```
weighted_union_find<Abelian_Group> uf(int n)
```

- $n$ 頂点で初期化する
- `Abelian_Group` には型 `S`, 二項演算 `op`, 単位元 `e`, 逆元 `inv` が必要

## leader

```
int leader(int u)
```

- $u$ が属する連結成分の代表元を返す
- ならし $O(\alpha(n))$

## weight

```
S weight(int u)
```

- 代表元を $r$ として $a_u-a_r$ を返す
- 代表元が変わると返り値も変わりうる
- ならし $O(\alpha(n))$

## same

```
bool same(int u, int v)
```

- $u$ と $v$ が同じ連結成分に属するかを判定する
- ならし $O(\alpha(n))$

## merge

```
bool merge(int u, int v, S w)
```

- 辺 $(u,v)$ を追加し, $a_v-a_u=w$ という制約を課す
- 既存の制約と矛盾する場合は `false` を返し, この辺を追加しない
- 矛盾しない場合は `true` を返す
- ならし $O(\alpha(n))$

## diff

```
S diff(int u, int v)
```

- $a_v-a_u$ を返す
- `same(u, v)` が `true` であることが必要
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
- 連結成分の順序は代表元の昇順, 各連結成分内の頂点は昇順
- $O(n\alpha(n))$
