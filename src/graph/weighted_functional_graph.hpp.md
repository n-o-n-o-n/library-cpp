---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/weighted_functional_graph.test.cpp
    title: test/graph/weighted_functional_graph.test.cpp
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
    \ }\n#line 3 \"src/graph/weighted_functional_graph.hpp\"\n\ntemplate<typename\
    \ Monoid, bool edge>\nstruct weighted_functional_graph {\n    using M = Monoid;\n\
    \    using S = typename Monoid::S;\n    weighted_functional_graph(int _n) : n(_n),\
    \ f(1, vector<int>(_n, -1)), d(1, vector<S>(_n, M::e())) {}\n    void add_edge(int\
    \ u, int v, const S &x = M::e()) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        assert(f[0][u] == -1);\n        f[0][u] =\
    \ v;\n        d[0][u] = x;\n    }\n    void set_weight(int u, const S &x) {\n\
    \        assert(0 <= u && u < n);\n        assert(!edge);\n        d[0][u] = x;\n\
    \    }\n    pair<int, S> steps(int u, long long k) {\n        assert(0 <= u &&\
    \ u < n);\n        assert(k >= 0);\n        doubling(k);\n        S x = edge ?\
    \ M::e() : d[0][u];\n        for (int i = 0; k >> i; i++) {\n            if (k\
    \ >> i & 1) {\n                int from = edge ? u : f[0][u];\n              \
    \  x = M::op(x, d[i][from]);\n                u = f[i][u];\n            }\n  \
    \      }\n        return {u, x};\n    }\n    pair<vector<int>, vector<S>> table(long\
    \ long k) {\n        assert(k >= 0);\n        doubling(k);\n        vector<int>\
    \ g(n);\n        vector<S> w(n, M::e());\n        iota(g.begin(), g.end(), 0);\n\
    \        if constexpr (!edge) w = d[0];\n        for (int i = 0; k >> i; i++)\
    \ {\n            if (k >> i & 1) {\n                for (int j = 0; j < n; j++)\
    \ {\n                    int from = edge ? g[j] : f[0][g[j]];\n              \
    \      w[j] = M::op(w[j], d[i][from]);\n                    g[j] = f[i][g[j]];\n\
    \                }\n            }\n        }\n        return {g, w};\n    }\n\
    \    template<typename C>\n    pair<long long, pair<int, S>> binary_search(int\
    \ u, long long k, const C &check) {\n        assert(0 <= u && u < n);\n      \
    \  assert(k >= 0);\n        S x = edge ? M::e() : d[0][u];\n        assert(check(x));\n\
    \        doubling(k);\n        int log = 0;\n        while (k >> log) log++;\n\
    \        long long r = 0;\n        for (log--; log >= 0; log--) {\n          \
    \  long long len = 1LL << log;\n            if (r > k - len) continue;\n     \
    \       int from = edge ? u : f[0][u];\n            S y = M::op(x, d[log][from]);\n\
    \            int v = f[log][u];\n            if (check(y)) {\n               \
    \ x = y;\n                u = v;\n                r += len;\n            }\n \
    \       }\n        return {r, {u, x}};\n    }\nprivate:\n    int n;\n    vector<vector<int>>\
    \ f;\n    vector<vector<S>> d;\n    void doubling(long long k) {\n        while\
    \ (k >> int(f.size())) {\n            vector<int> tf(n);\n            vector<S>\
    \ td(n, M::e());\n            const vector<int> &g = f.back();\n            const\
    \ vector<S> &h = d.back();\n            for (int i = 0; i < n; i++) tf[i] = g[g[i]],\
    \ td[i] = M::op(h[i], h[g[i]]);\n            f.push_back(tf);\n            d.push_back(td);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename Monoid, bool\
    \ edge>\nstruct weighted_functional_graph {\n    using M = Monoid;\n    using\
    \ S = typename Monoid::S;\n    weighted_functional_graph(int _n) : n(_n), f(1,\
    \ vector<int>(_n, -1)), d(1, vector<S>(_n, M::e())) {}\n    void add_edge(int\
    \ u, int v, const S &x = M::e()) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        assert(f[0][u] == -1);\n        f[0][u] =\
    \ v;\n        d[0][u] = x;\n    }\n    void set_weight(int u, const S &x) {\n\
    \        assert(0 <= u && u < n);\n        assert(!edge);\n        d[0][u] = x;\n\
    \    }\n    pair<int, S> steps(int u, long long k) {\n        assert(0 <= u &&\
    \ u < n);\n        assert(k >= 0);\n        doubling(k);\n        S x = edge ?\
    \ M::e() : d[0][u];\n        for (int i = 0; k >> i; i++) {\n            if (k\
    \ >> i & 1) {\n                int from = edge ? u : f[0][u];\n              \
    \  x = M::op(x, d[i][from]);\n                u = f[i][u];\n            }\n  \
    \      }\n        return {u, x};\n    }\n    pair<vector<int>, vector<S>> table(long\
    \ long k) {\n        assert(k >= 0);\n        doubling(k);\n        vector<int>\
    \ g(n);\n        vector<S> w(n, M::e());\n        iota(g.begin(), g.end(), 0);\n\
    \        if constexpr (!edge) w = d[0];\n        for (int i = 0; k >> i; i++)\
    \ {\n            if (k >> i & 1) {\n                for (int j = 0; j < n; j++)\
    \ {\n                    int from = edge ? g[j] : f[0][g[j]];\n              \
    \      w[j] = M::op(w[j], d[i][from]);\n                    g[j] = f[i][g[j]];\n\
    \                }\n            }\n        }\n        return {g, w};\n    }\n\
    \    template<typename C>\n    pair<long long, pair<int, S>> binary_search(int\
    \ u, long long k, const C &check) {\n        assert(0 <= u && u < n);\n      \
    \  assert(k >= 0);\n        S x = edge ? M::e() : d[0][u];\n        assert(check(x));\n\
    \        doubling(k);\n        int log = 0;\n        while (k >> log) log++;\n\
    \        long long r = 0;\n        for (log--; log >= 0; log--) {\n          \
    \  long long len = 1LL << log;\n            if (r > k - len) continue;\n     \
    \       int from = edge ? u : f[0][u];\n            S y = M::op(x, d[log][from]);\n\
    \            int v = f[log][u];\n            if (check(y)) {\n               \
    \ x = y;\n                u = v;\n                r += len;\n            }\n \
    \       }\n        return {r, {u, x}};\n    }\nprivate:\n    int n;\n    vector<vector<int>>\
    \ f;\n    vector<vector<S>> d;\n    void doubling(long long k) {\n        while\
    \ (k >> int(f.size())) {\n            vector<int> tf(n);\n            vector<S>\
    \ td(n, M::e());\n            const vector<int> &g = f.back();\n            const\
    \ vector<S> &h = d.back();\n            for (int i = 0; i < n; i++) tf[i] = g[g[i]],\
    \ td[i] = M::op(h[i], h[g[i]]);\n            f.push_back(tf);\n            d.push_back(td);\n\
    \        }\n    }\n};\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/graph/weighted_functional_graph.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/weighted_functional_graph.test.cpp
documentation_of: src/graph/weighted_functional_graph.hpp
layout: document
title: Weighted Functional Graph
---

各頂点の出次数がちょうど $1$ である重み付き有向グラフを扱う.

`Monoid` は型 `S`, 演算 `op`, 単位元 `e` を持つ.
`edge=true` なら辺重み, `edge=false` なら頂点重みを扱う.
頂点重みの場合, 始点と終点の重みも含めて計算する.

重みは遷移順に合成する.

## Constructor

```
weighted_functional_graph<Monoid, edge> G(int n)
```

## add_edge

```
void add_edge(int u, int v, const S &x = Monoid::e())
```

- $u\rightarrow v$ の辺を張る. `edge=true` なら `x` はその辺の重み, `edge=false` なら頂点 $u$ の重みになる
- 各頂点をちょうど $1$ 回 `u` として指定する

## set_weight

```
void set_weight(int u, const S &x)
```

- `edge=false` のとき, 頂点 $u$ の重みを `x` に設定する

## steps

```
pair<int, S> steps(int u, long long k)
```

- $u$ から $k$ 回遷移した頂点と重みを返す
- $O(\log k)$ (ただし, 前計算に $O(n\log k)$ かかる)

## table

```
pair<vector<int>, vector<S>> table(long long k)
```

- すべての頂点について `steps(u, k)` を求める. 返り値の各ベクトルの $u$ 番目が, それぞれ到達頂点と集約値になる
- $O(n\log k)$

## binary_search

```
pair<long long, pair<int, S>> binary_search(int u, long long k, check)
```

- `check` は $S \to \text{bool}$ のラムダ式関数が想定される
- $0$ 回から $k$ 回までの遷移のうち, `check` が `true` となる最大の回数 $r$ を求める
    - 辺重みの場合 `check(e) == true` が必要
    - 頂点重みの場合 `check(w[u]) == true` が必要
    - 返り値は `{r, steps(u, r)}` で, $k$ 回遷移しても `true` なら `{k, steps(u, k)}` を返す
- $O(\log k)$ (ただし, 前計算に $O(n\log k)$ かかる)
