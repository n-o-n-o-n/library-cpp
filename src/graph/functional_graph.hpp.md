---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/functional_graph.test.cpp
    title: test/graph/functional_graph.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/graph/functional_graph.hpp\"\n\nstruct functional_graph {\n\
    \    functional_graph(int _n) : functional_graph(vector<int>(_n, -1)) {}\n   \
    \ functional_graph(const vector<int> &a) : n(a.size()), f(1, a) {}\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        assert(f[0][u] == -1);\n        f[0][u] = v;\n    }\n    int steps(int\
    \ u, long long k) {\n        assert(0 <= u && u < n);\n        doubling(k);\n\
    \        for (int i = 0; (1LL << i) <= k; i++) {\n            if (k >> i & 1)\
    \ u = f[i][u];\n        }\n        return u;\n    }\n    vector<int> table(long\
    \ long k) {\n        doubling(k);\n        vector<int> g(n);\n        iota(g.begin(),\
    \ g.end(), 0);\n        for (int i = 0; (1LL << i) <= k; i++) {\n            if\
    \ (k >> i & 1) {\n                for (int j = 0; j < n; j++) {\n            \
    \        g[j] = f[i][g[j]];\n                }\n            }\n        }\n   \
    \     return g;\n    }\n    template<typename C>\n    pair<int, int> binary_search(int\
    \ u, const C &check) {\n        assert(0 <= u && u < n);\n        assert(check(u));\n\
    \        doubling(n);\n        int log = 0;\n        while (n >> log) log++;\n\
    \        int r = 0;\n        for (log--; log >= 0; log--) {\n            int len\
    \ = 1 << log;\n            if (r > n - len) continue;\n            int v = f[log][u];\n\
    \            if (check(v)) u = v, r += len;\n        }\n        if (r == n) return\
    \ {-1, -1};\n        return make_pair(r, u);\n    }\nprivate:\n    int n;\n  \
    \  vector<vector<int>> f;\n    void doubling(long long k) {\n        while (1LL\
    \ << int(f.size()) <= k) {\n            vector<int> tf(n);\n            const\
    \ vector<int> &g = f.back();\n            for (int i = 0; i < n; i++) tf[i] =\
    \ g[g[i]];\n            f.push_back(tf);\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nstruct functional_graph {\n\
    \    functional_graph(int _n) : functional_graph(vector<int>(_n, -1)) {}\n   \
    \ functional_graph(const vector<int> &a) : n(a.size()), f(1, a) {}\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        assert(f[0][u] == -1);\n        f[0][u] = v;\n    }\n    int steps(int\
    \ u, long long k) {\n        assert(0 <= u && u < n);\n        doubling(k);\n\
    \        for (int i = 0; (1LL << i) <= k; i++) {\n            if (k >> i & 1)\
    \ u = f[i][u];\n        }\n        return u;\n    }\n    vector<int> table(long\
    \ long k) {\n        doubling(k);\n        vector<int> g(n);\n        iota(g.begin(),\
    \ g.end(), 0);\n        for (int i = 0; (1LL << i) <= k; i++) {\n            if\
    \ (k >> i & 1) {\n                for (int j = 0; j < n; j++) {\n            \
    \        g[j] = f[i][g[j]];\n                }\n            }\n        }\n   \
    \     return g;\n    }\n    template<typename C>\n    pair<int, int> binary_search(int\
    \ u, const C &check) {\n        assert(0 <= u && u < n);\n        assert(check(u));\n\
    \        doubling(n);\n        int log = 0;\n        while (n >> log) log++;\n\
    \        int r = 0;\n        for (log--; log >= 0; log--) {\n            int len\
    \ = 1 << log;\n            if (r > n - len) continue;\n            int v = f[log][u];\n\
    \            if (check(v)) u = v, r += len;\n        }\n        if (r == n) return\
    \ {-1, -1};\n        return make_pair(r, u);\n    }\nprivate:\n    int n;\n  \
    \  vector<vector<int>> f;\n    void doubling(long long k) {\n        while (1LL\
    \ << int(f.size()) <= k) {\n            vector<int> tf(n);\n            const\
    \ vector<int> &g = f.back();\n            for (int i = 0; i < n; i++) tf[i] =\
    \ g[g[i]];\n            f.push_back(tf);\n        }\n    }\n};\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/graph/functional_graph.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/functional_graph.test.cpp
documentation_of: src/graph/functional_graph.hpp
layout: document
title: Functional Graph
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
