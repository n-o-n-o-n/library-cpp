---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/foldable_union_find.test.cpp
    title: test/data_structure/union_find/foldable_union_find.test.cpp
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
    \ }\n#line 3 \"src/data_structure/union_find/foldable_union_find.hpp\"\n\ntemplate<typename\
    \ Abelian_Monoid>\nstruct foldable_union_find {\n    using M = Abelian_Monoid;\n\
    \    using S = M::S;\n    foldable_union_find(int n) : foldable_union_find(vector<S>(n,\
    \ M::e())) {}\n    foldable_union_find(const vector<S> &v) : p(v.size(), -1),\
    \ cyc(v.size()), a(v), d(v) {\n        iota(cyc.begin(), cyc.end(), 0);\n    }\n\
    \    int leader(int u) {\n        assert(0 <= u && u < ssize(p));\n        return\
    \ p[u] < 0 ? u : p[u] = leader(p[u]);\n    }\n    bool same(int u, int v) {\n\
    \        assert(0 <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n\
    \        return leader(u) == leader(v);\n    }\n    void merge(int u, int v) {\n\
    \        assert(0 <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n\
    \        u = leader(u);\n        v = leader(v);\n        if (u == v) return;\n\
    \        if (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n        d[u] = M::op(d[u],\
    \ d[v]);\n        p[v] = u;\n        swap(cyc[u], cyc[v]);\n    }\n    int size(int\
    \ u) {\n        assert(0 <= u && u < ssize(p));\n        return -p[leader(u)];\n\
    \    }\n    vector<int> group(int u) {\n        assert(0 <= u && u < ssize(p));\n\
    \        vector<int> res = {u};\n        int v = cyc[u];\n        while (v !=\
    \ u) {\n            res.push_back(v);\n            v = cyc[v];\n        }\n  \
    \      return res;\n    }\n    vector<vector<int>> groups() {\n        int n =\
    \ p.size();\n        vector<vector<int>> tmp(n);\n        for (int i = 0; i <\
    \ n; i++) {\n            tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n\
    \        }\n        return res;\n    }\n    void set(int u, const S &x) {\n  \
    \      assert(0 <= u && u < ssize(p));\n        S diff = M::op(M::inv(a[u]), x);\n\
    \        a[u] = x;\n        d[leader(u)] = M::op(d[leader(u)], diff);\n    }\n\
    \    S prod(int u) {\n        assert(0 <=u && u < ssize(p));\n        return d[leader(u)];\n\
    \    }\nprivate:\n    vector<int> p, cyc;\n    vector<S> a, d;\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\ntemplate<typename Abelian_Monoid>\n\
    struct foldable_union_find {\n    using M = Abelian_Monoid;\n    using S = M::S;\n\
    \    foldable_union_find(int n) : foldable_union_find(vector<S>(n, M::e())) {}\n\
    \    foldable_union_find(const vector<S> &v) : p(v.size(), -1), cyc(v.size()),\
    \ a(v), d(v) {\n        iota(cyc.begin(), cyc.end(), 0);\n    }\n    int leader(int\
    \ u) {\n        assert(0 <= u && u < ssize(p));\n        return p[u] < 0 ? u :\
    \ p[u] = leader(p[u]);\n    }\n    bool same(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        return\
    \ leader(u) == leader(v);\n    }\n    void merge(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        u =\
    \ leader(u);\n        v = leader(v);\n        if (u == v) return;\n        if\
    \ (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n        d[u] = M::op(d[u],\
    \ d[v]);\n        p[v] = u;\n        swap(cyc[u], cyc[v]);\n    }\n    int size(int\
    \ u) {\n        assert(0 <= u && u < ssize(p));\n        return -p[leader(u)];\n\
    \    }\n    vector<int> group(int u) {\n        assert(0 <= u && u < ssize(p));\n\
    \        vector<int> res = {u};\n        int v = cyc[u];\n        while (v !=\
    \ u) {\n            res.push_back(v);\n            v = cyc[v];\n        }\n  \
    \      return res;\n    }\n    vector<vector<int>> groups() {\n        int n =\
    \ p.size();\n        vector<vector<int>> tmp(n);\n        for (int i = 0; i <\
    \ n; i++) {\n            tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n\
    \        }\n        return res;\n    }\n    void set(int u, const S &x) {\n  \
    \      assert(0 <= u && u < ssize(p));\n        S diff = M::op(M::inv(a[u]), x);\n\
    \        a[u] = x;\n        d[leader(u)] = M::op(d[leader(u)], diff);\n    }\n\
    \    S prod(int u) {\n        assert(0 <=u && u < ssize(p));\n        return d[leader(u)];\n\
    \    }\nprivate:\n    vector<int> p, cyc;\n    vector<S> a, d;\n};\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/data_structure/union_find/foldable_union_find.hpp
  requiredBy: []
  timestamp: '2026-11-04 18:18:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/union_find/foldable_union_find.test.cpp
documentation_of: src/data_structure/union_find/foldable_union_find.hpp
layout: document
title: Foldable Union Find
---

各頂点の値を管理し, 連結成分ごとの総積を取得できる union find.

## Constructor

```
foldable_union_find<Abelian_Monoid> uf(int n)
foldable_union_find<Abelian_Monoid> uf(vector<S> v)
```

- $n$ 頂点で初期化する. 各頂点の初期値は `e()`
- `Abelian_Monoid` には型 `S`, 可換な二項演算 `op`, 単位元 `e`, 逆元 `inv` が必要
  - 配列で初期化し, `set` を呼ばない場合は `inv` が不要

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
void merge(int u, int v)
```

- 辺 $(u,v)$ を追加する
- ならし $O(\alpha(n))$

## size

```
int size(int u)
```

- $u$ が属する連結成分の要素数を返す
- ならし $O(\alpha(n))$

## set

```
void set(int u, const S &x)
```

- 頂点 $u$ の値を $x$ に変更する
- ならし $O(\alpha(n))$

## prod

```
S prod(int u)
```

- $u$ が属する連結成分の頂点の値を `op` でまとめた結果を返す
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
