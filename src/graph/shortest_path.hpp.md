---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path.test.cpp
    title: test/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/shortest_path_dial.test.cpp
    title: test/graph/shortest_path_dial.test.cpp
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
    \ }\n#line 3 \"src/graph/shortest_path.hpp\"\n\ntemplate<typename T = int>\nstruct\
    \ shortest_path {\n    shortest_path(int _n) : n(_n), r(-1), g(_n), wt(false),\
    \ dial(true) {}\n    shortest_path(const vector<vector<int>> &_g) : n(_g.size()),\
    \ r(-1), g(n), wt(false), dial(true) {\n        for (int u = 0; u < n; u++) {\n\
    \            g[u].reserve(_g[u].size());\n            for (int v : _g[u]) {\n\
    \                assert(0 <= v && v < n);\n                g[u].emplace_back(v,\
    \ 1);\n            }\n        }\n    }\n    template<typename T2>\n    shortest_path(const\
    \ vector<vector<pair<int, T2>>> &_g) : n(_g.size()), r(-1), g(n), wt(true), dial(true)\
    \ {\n        for (int u = 0; u < n; u++) {\n            g[u].reserve(_g[u].size());\n\
    \            for (auto [v, w] : _g[u]) {\n                assert(0 <= v && v <\
    \ n);\n                assert(w >= 0);\n                g[u].emplace_back(v, w);\n\
    \                dial = dial && (w <= k);\n            }\n        }\n    }\n \
    \   void add_edge(int u, int v, T w = 1) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        assert(w >= 0);\n        g[u].emplace_back(v,\
    \ w);\n        wt = wt || (w != 1);\n        dial = dial && (w <= k);\n      \
    \  r = -1;\n    }\n    vector<T> table(int s) {\n        assert(0 <= s && s <\
    \ n);\n        build(s);\n        return d;\n    }\n    vector<int> path(int s,\
    \ int t) {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n\
    \        build(s);\n        if (d[t] == -1) return {};\n        vector<int> res\
    \ = {t};\n        while (p[t] != -1) res.push_back(t = p[t]);\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n    T dist(int s, int t) {\n      \
    \  assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n        build(s);\n\
    \        return d[t];\n    }\nprivate:\n    static constexpr int k = 16;\n   \
    \ int n, r;\n    vector<vector<pair<int, T>>> g;\n    bool wt, dial;\n    vector<T>\
    \ d;\n    vector<int> p;\n    template<class P>\n    void upd(int u, T cur, P\
    \ push) {\n        for (auto [v, w] : g[u]) {\n            if (chmin(d[v], cur\
    \ + w)) {\n                p[v] = u;\n                push(v);\n            }\n\
    \        }\n    }\n    void build(int s) {\n        if (r == s) return;\n    \
    \    r = s;\n        d = vector<T>(n, inf<T>());\n        p = vector<int>(n, -1);\n\
    \        d[s] = 0;\n        if (!wt) {\n            queue<int> q;\n          \
    \  q.push(s);\n            while (!q.empty()) {\n                int u = q.front();\n\
    \                q.pop();\n                upd(u, d[u], [&] (int v) { q.push(v);\
    \ });\n            }\n        } else if (dial) {\n            array<queue<pair<T,\
    \ int>>, k + 1> qs;\n            qs[0].emplace(0, s);\n            int sz = 1;\n\
    \            T w = 0;\n            while (sz) {\n                auto &q = qs[w\
    \ % (k + 1)];\n                if (q.empty()) {\n                    w++;\n  \
    \                  continue;\n                }\n                auto [du, u]\
    \ = q.front();\n                q.pop();\n                sz--;\n            \
    \    if (du > d[u]) continue;\n                upd(u, du, [&] (int v) {\n    \
    \                qs[d[v] % (k + 1)].emplace(d[v], v);\n                    sz++;\n\
    \                });\n            }\n        } else {\n            priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<>> q;\n            q.emplace(0, s);\n  \
    \          while (!q.empty()) {\n                auto [du, u] = q.top();\n   \
    \             q.pop();\n                if (du > d[u]) continue;\n           \
    \     upd(u, du, [&] (int v) { q.emplace(d[v], v); });\n            }\n      \
    \  }\n        for (auto &e : d) {\n            if (e == inf<T>()) e = -1;\n  \
    \      }\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T = int>\n\
    struct shortest_path {\n    shortest_path(int _n) : n(_n), r(-1), g(_n), wt(false),\
    \ dial(true) {}\n    shortest_path(const vector<vector<int>> &_g) : n(_g.size()),\
    \ r(-1), g(n), wt(false), dial(true) {\n        for (int u = 0; u < n; u++) {\n\
    \            g[u].reserve(_g[u].size());\n            for (int v : _g[u]) {\n\
    \                assert(0 <= v && v < n);\n                g[u].emplace_back(v,\
    \ 1);\n            }\n        }\n    }\n    template<typename T2>\n    shortest_path(const\
    \ vector<vector<pair<int, T2>>> &_g) : n(_g.size()), r(-1), g(n), wt(true), dial(true)\
    \ {\n        for (int u = 0; u < n; u++) {\n            g[u].reserve(_g[u].size());\n\
    \            for (auto [v, w] : _g[u]) {\n                assert(0 <= v && v <\
    \ n);\n                assert(w >= 0);\n                g[u].emplace_back(v, w);\n\
    \                dial = dial && (w <= k);\n            }\n        }\n    }\n \
    \   void add_edge(int u, int v, T w = 1) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        assert(w >= 0);\n        g[u].emplace_back(v,\
    \ w);\n        wt = wt || (w != 1);\n        dial = dial && (w <= k);\n      \
    \  r = -1;\n    }\n    vector<T> table(int s) {\n        assert(0 <= s && s <\
    \ n);\n        build(s);\n        return d;\n    }\n    vector<int> path(int s,\
    \ int t) {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n\
    \        build(s);\n        if (d[t] == -1) return {};\n        vector<int> res\
    \ = {t};\n        while (p[t] != -1) res.push_back(t = p[t]);\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n    T dist(int s, int t) {\n      \
    \  assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n        build(s);\n\
    \        return d[t];\n    }\nprivate:\n    static constexpr int k = 16;\n   \
    \ int n, r;\n    vector<vector<pair<int, T>>> g;\n    bool wt, dial;\n    vector<T>\
    \ d;\n    vector<int> p;\n    template<class P>\n    void upd(int u, T cur, P\
    \ push) {\n        for (auto [v, w] : g[u]) {\n            if (chmin(d[v], cur\
    \ + w)) {\n                p[v] = u;\n                push(v);\n            }\n\
    \        }\n    }\n    void build(int s) {\n        if (r == s) return;\n    \
    \    r = s;\n        d = vector<T>(n, inf<T>());\n        p = vector<int>(n, -1);\n\
    \        d[s] = 0;\n        if (!wt) {\n            queue<int> q;\n          \
    \  q.push(s);\n            while (!q.empty()) {\n                int u = q.front();\n\
    \                q.pop();\n                upd(u, d[u], [&] (int v) { q.push(v);\
    \ });\n            }\n        } else if (dial) {\n            array<queue<pair<T,\
    \ int>>, k + 1> qs;\n            qs[0].emplace(0, s);\n            int sz = 1;\n\
    \            T w = 0;\n            while (sz) {\n                auto &q = qs[w\
    \ % (k + 1)];\n                if (q.empty()) {\n                    w++;\n  \
    \                  continue;\n                }\n                auto [du, u]\
    \ = q.front();\n                q.pop();\n                sz--;\n            \
    \    if (du > d[u]) continue;\n                upd(u, du, [&] (int v) {\n    \
    \                qs[d[v] % (k + 1)].emplace(d[v], v);\n                    sz++;\n\
    \                });\n            }\n        } else {\n            priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<>> q;\n            q.emplace(0, s);\n  \
    \          while (!q.empty()) {\n                auto [du, u] = q.top();\n   \
    \             q.pop();\n                if (du > d[u]) continue;\n           \
    \     upd(u, du, [&] (int v) { q.emplace(d[v], v); });\n            }\n      \
    \  }\n        for (auto &e : d) {\n            if (e == inf<T>()) e = -1;\n  \
    \      }\n    }\n};\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/graph/shortest_path.hpp
  requiredBy: []
  timestamp: '2026-11-11 23:04:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/shortest_path_dial.test.cpp
  - test/graph/shortest_path.test.cpp
documentation_of: src/graph/shortest_path.hpp
layout: document
title: Shortest Path
---

非負辺重みの有向グラフの最短経路を求める.

内部で BFS, Dial 法, Dijkstra を使い分ける.
使い分けは次のとおり:

- 全ての辺重みが $1$ であれば BFS
- そうでなく, 全ての辺重みが$16$ 以下であれば Dial 法
- そうでなければ Dijkstra

## Constructor

```
shortest_path<T> G(int n)
shortest_path<T> G(const vector<vector<int>> &g)
shortest_path<T> G(const vector<vector<pair<int, T2>>> &g)
```

- `n` は頂点数
- `vector<vector<int>>` では各辺の重みを $1$ とする
- `vector<vector<pair<int, T2>>>` では `g[u]` の `(v, w)` を $u\rightarrow v$ の重み $w$ の辺とする

## add_edge

```
void add_edge(int u, int v, T w = 1)
```

- $u\rightarrow v$ の重み $w$ の辺を追加する
- $w \ge 0$

## table

```
vector<T> table(int s)
```

- $s$ から各頂点への最短距離を返す. 到達不能な頂点の値は `-1`

## dist

```
T dist(int s, int t)
```

- $s$ から $t$ への最短距離を返す
- 到達不能なら `-1` を返す

## path

```
vector<int> path(int s, int t)
```

- 最短路上の頂点列を $s$ から $t$ の順で返す
- 到達不能なら空の列を返す