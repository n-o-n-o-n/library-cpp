---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/graph/offline_directed_reachability.hpp\"\n\nstruct offline_directed_reachability\
    \ {\n    offline_directed_reachability(int _n) : n(_n), q(0), g(_n), g_rev(_n),\
    \ qs(_n) {}\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        g[u].push_back(v);\n        g_rev[v].push_back(u);\n\
    \    }\n    void add_query(int u, int v) {\n        qs[u].emplace_back(v, q++);\n\
    \    }\n    vector<bool> solve() {\n        scc_build();\n        vector<vector<int>>\
    \ h(m);\n        for (int u = 0; u < n; u++) {\n            for (int v : g[u])\
    \ {\n                if (id[u] != id[v]) h[id[u]].push_back(id[v]);\n        \
    \    }\n        }\n        for (auto &e : h) {\n            sort(e.begin(), e.end());\n\
    \            e.erase(unique(e.begin(), e.end()), e.end());\n        }\n      \
    \  vector<vector<pair<int, int>>> qs2(m);\n        for (int i = 0; i < n; i++)\
    \ {\n            for (auto [j, k] : qs[i]) {\n                qs2[id[j]].emplace_back(id[i],\
    \ k);\n            }\n        }\n        vector<bool> res(q);\n        for (int\
    \ l = 0; l < m; l += w) {\n            int r = min(l + w, m);\n            vector<unsigned\
    \ long long> dp(m);\n            for (int i = m - 1; i >= 0; i--) {\n        \
    \        if (l <= i && i < r) dp[i] |= 1ULL << (i - l);\n                for (int\
    \ j : h[i]) dp[i] |= dp[j];\n            }\n            for (int i = l; i < r;\
    \ i++) {\n                for (auto [j, k] : qs2[i]) {\n                    res[k]\
    \ = dp[j] >> (i - l) & 1;\n                }\n            }\n        }\n     \
    \   return res;\n    }\nprivate:\n    static constexpr int w = 64;\n    int n,\
    \ q, m;\n    vector<vector<int>> g, g_rev;\n    vector<int> id, ord;\n    vector<bool>\
    \ vis;\n    vector<vector<pair<int, int>>> qs;\n    void dfs(int u) {\n      \
    \  if (vis[u]) return;\n        vis[u] = true;\n        for (int v : g[u]) dfs(v);\n\
    \        ord.push_back(u);\n    }\n    void sfd(int u, int k) {\n        if (id[u]\
    \ != -1) return;\n        id[u] = k;\n        for (int v : g_rev[u]) sfd(v, k);\n\
    \    }\n    void scc_build() {\n        id = vector<int>(n, -1);\n        vis\
    \ = vector<bool>(n);\n        ord.reserve(n);\n        for (int i = 0; i < n;\
    \ i++) dfs(i);\n        reverse(ord.begin(), ord.end());\n        m = 0;\n   \
    \     for (int u : ord) {\n            if (id[u] == -1) {\n                sfd(u,\
    \ m++);\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nstruct offline_directed_reachability\
    \ {\n    offline_directed_reachability(int _n) : n(_n), q(0), g(_n), g_rev(_n),\
    \ qs(_n) {}\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        g[u].push_back(v);\n        g_rev[v].push_back(u);\n\
    \    }\n    void add_query(int u, int v) {\n        qs[u].emplace_back(v, q++);\n\
    \    }\n    vector<bool> solve() {\n        scc_build();\n        vector<vector<int>>\
    \ h(m);\n        for (int u = 0; u < n; u++) {\n            for (int v : g[u])\
    \ {\n                if (id[u] != id[v]) h[id[u]].push_back(id[v]);\n        \
    \    }\n        }\n        for (auto &e : h) {\n            sort(e.begin(), e.end());\n\
    \            e.erase(unique(e.begin(), e.end()), e.end());\n        }\n      \
    \  vector<vector<pair<int, int>>> qs2(m);\n        for (int i = 0; i < n; i++)\
    \ {\n            for (auto [j, k] : qs[i]) {\n                qs2[id[j]].emplace_back(id[i],\
    \ k);\n            }\n        }\n        vector<bool> res(q);\n        for (int\
    \ l = 0; l < m; l += w) {\n            int r = min(l + w, m);\n            vector<unsigned\
    \ long long> dp(m);\n            for (int i = m - 1; i >= 0; i--) {\n        \
    \        if (l <= i && i < r) dp[i] |= 1ULL << (i - l);\n                for (int\
    \ j : h[i]) dp[i] |= dp[j];\n            }\n            for (int i = l; i < r;\
    \ i++) {\n                for (auto [j, k] : qs2[i]) {\n                    res[k]\
    \ = dp[j] >> (i - l) & 1;\n                }\n            }\n        }\n     \
    \   return res;\n    }\nprivate:\n    static constexpr int w = 64;\n    int n,\
    \ q, m;\n    vector<vector<int>> g, g_rev;\n    vector<int> id, ord;\n    vector<bool>\
    \ vis;\n    vector<vector<pair<int, int>>> qs;\n    void dfs(int u) {\n      \
    \  if (vis[u]) return;\n        vis[u] = true;\n        for (int v : g[u]) dfs(v);\n\
    \        ord.push_back(u);\n    }\n    void sfd(int u, int k) {\n        if (id[u]\
    \ != -1) return;\n        id[u] = k;\n        for (int v : g_rev[u]) sfd(v, k);\n\
    \    }\n    void scc_build() {\n        id = vector<int>(n, -1);\n        vis\
    \ = vector<bool>(n);\n        ord.reserve(n);\n        for (int i = 0; i < n;\
    \ i++) dfs(i);\n        reverse(ord.begin(), ord.end());\n        m = 0;\n   \
    \     for (int u : ord) {\n            if (id[u] == -1) {\n                sfd(u,\
    \ m++);\n            }\n        }\n    }\n};\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/graph/offline_directed_reachability.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graph/offline_directed_reachability.hpp
layout: document
redirect_from:
- /library/src/graph/offline_directed_reachability.hpp
- /library/src/graph/offline_directed_reachability.hpp.html
title: src/graph/offline_directed_reachability.hpp
---
