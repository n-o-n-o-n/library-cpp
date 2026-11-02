---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/misc/two_sat.test.cpp
    title: test/misc/two_sat.test.cpp
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
    \ }\n#line 3 \"src/graph/scc.hpp\"\n\nstruct scc_graph {\n    scc_graph(int _n\
    \ = 0) : n(_n), g(_n), g_rev(_n) {}\n    void add_edge(int u, int v) {\n     \
    \   assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
    \        g_rev[v].push_back(u);\n    }\n    vector<vector<int>> scc() {\n    \
    \    id = vector<int>(n, -1);\n        vis = vector<bool>(n);\n        ord.reserve(n);\n\
    \        for (int i = 0; i < n; i++) dfs(i);\n        reverse(ord.begin(), ord.end());\n\
    \        int k = 0;\n        for (int u : ord) {\n            if (id[u] == -1)\
    \ {\n                sfd(u, k++);\n            }\n        }\n        vector<vector<int>>\
    \ res(k);\n        for (int i = 0; i < n; i++) {\n            res[id[i]].push_back(i);\n\
    \        }\n        return res;\n    }\nprivate:\n    int n;\n    vector<vector<int>>\
    \ g, g_rev;\n    vector<int> id, ord;\n    vector<bool> vis;\n    void dfs(int\
    \ u) {\n        if (vis[u]) return;\n        vis[u] = true;\n        for (int\
    \ v : g[u]) dfs(v);\n        ord.push_back(u);\n    }\n    void sfd(int u, int\
    \ k) {\n        if (id[u] != -1) return;\n        id[u] = k;\n        for (int\
    \ v : g_rev[u]) sfd(v, k);\n    }\n};\n#line 4 \"src/misc/two_sat.hpp\"\n\nstruct\
    \ two_sat {\n    two_sat() : two_sat(0) {}\n    two_sat(int _n) : n(_n), scc(2\
    \ * _n) {}\n    void add_clause(int i, bool f, int j, bool g) {\n        scc.add_edge((!f)\
    \ * n + i, g * n + j);\n        scc.add_edge((!g) * n + j, f * n + i);\n    }\n\
    \    vector<bool> solve() {\n        auto comp = scc.scc();\n        vector<int>\
    \ id(2 * n);\n        for (int i = 0; i < ssize(comp); i++) {\n            for\
    \ (int j : comp[i]) id[j] = i;\n        }\n        vector<bool> res(n);\n    \
    \    for (int i = 0; i < n; i++) {\n            if (id[i] == id[i + n]) return\
    \ {};\n            res[i] = id[i] < id[i + n];\n        }\n        return res;\n\
    \    }\nprivate:\n    int n;\n    scc_graph scc;\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../graph/scc.hpp\"\
    \n\nstruct two_sat {\n    two_sat() : two_sat(0) {}\n    two_sat(int _n) : n(_n),\
    \ scc(2 * _n) {}\n    void add_clause(int i, bool f, int j, bool g) {\n      \
    \  scc.add_edge((!f) * n + i, g * n + j);\n        scc.add_edge((!g) * n + j,\
    \ f * n + i);\n    }\n    vector<bool> solve() {\n        auto comp = scc.scc();\n\
    \        vector<int> id(2 * n);\n        for (int i = 0; i < ssize(comp); i++)\
    \ {\n            for (int j : comp[i]) id[j] = i;\n        }\n        vector<bool>\
    \ res(n);\n        for (int i = 0; i < n; i++) {\n            if (id[i] == id[i\
    \ + n]) return {};\n            res[i] = id[i] < id[i + n];\n        }\n     \
    \   return res;\n    }\nprivate:\n    int n;\n    scc_graph scc;\n};"
  dependsOn:
  - src/template.hpp
  - src/graph/scc.hpp
  isVerificationFile: false
  path: src/misc/two_sat.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/misc/two_sat.test.cpp
documentation_of: src/misc/two_sat.hpp
layout: document
redirect_from:
- /library/src/misc/two_sat.hpp
- /library/src/misc/two_sat.hpp.html
title: src/misc/two_sat.hpp
---
