---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/maximum_independent_set.test.cpp
    title: test/graph/maximum_independent_set.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/maximum_independent_set.hpp\"\n#include <vector>\n\
    using namespace std;\n\ninline vector<int> maximum_independent_set(const vector<vector<int>>\
    \ &g) {\n    int n = g.size();\n    vector<int> deg(n), used(n);\n    vector<bool>\
    \ vis(n), ans(n);\n    for (int i = 0; i < n; i++) deg[i] = g[i].size();\n   \
    \ int cur = 0, cnt = 0, alive = n;\n    auto dfs = [&](const auto &dfs) -> void\
    \ {\n        if (cnt + alive <= cur) return;\n        int u = -1;\n        for\
    \ (int i = 0; i < n; i++) {\n            if (!vis[i] && !used[i]) {\n        \
    \        if (deg[i] <= 1) {\n                    u = i;\n                    break;\n\
    \                }\n                if (u < 0 || deg[u] < deg[i]) u = i;\n   \
    \         }\n        }\n        if (u < 0) return;\n        if (deg[u] != 1) {\n\
    \            used[u] = 1;\n            alive--;\n            for (int v : g[u])\
    \ deg[v]--;\n            dfs(dfs);\n            used[u] = 0;\n            alive++;\n\
    \            for (int v : g[u]) deg[v]++;\n        }\n        vis[u] = true;\n\
    \        alive--;\n        for (int v : g[u]) {\n            if (!used[v]++) alive--;\n\
    \        }\n        cnt++;\n        if (cur < cnt) {\n            ans = vis;\n\
    \            cur = cnt;\n        }\n        dfs(dfs);\n        vis[u] = 0;\n \
    \       alive++;\n        for (int v : g[u]) {\n            if (!--used[v]) alive++;\n\
    \        }\n        cnt--;\n    };\n    dfs(dfs);\n    vector<int> res;\n    for\
    \ (int i = 0; i < n; i++) {\n        if (ans[i]) res.push_back(i);\n    }\n  \
    \  return res;\n}\n\ninline vector<int> maximum_independent_set_adjacency(const\
    \ vector<vector<int>> &a) {\n    int n = a.size();\n    vector<vector<int>> g(n);\n\
    \    for (int u = 0; u < n; u++) {\n        for (int v = 0; v < n; v++) {\n  \
    \          if (a[u][v]) g[u].push_back(v);\n        }\n    }\n    return maximum_independent_set(g);\n\
    }\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ninline vector<int>\
    \ maximum_independent_set(const vector<vector<int>> &g) {\n    int n = g.size();\n\
    \    vector<int> deg(n), used(n);\n    vector<bool> vis(n), ans(n);\n    for (int\
    \ i = 0; i < n; i++) deg[i] = g[i].size();\n    int cur = 0, cnt = 0, alive =\
    \ n;\n    auto dfs = [&](const auto &dfs) -> void {\n        if (cnt + alive <=\
    \ cur) return;\n        int u = -1;\n        for (int i = 0; i < n; i++) {\n \
    \           if (!vis[i] && !used[i]) {\n                if (deg[i] <= 1) {\n \
    \                   u = i;\n                    break;\n                }\n  \
    \              if (u < 0 || deg[u] < deg[i]) u = i;\n            }\n        }\n\
    \        if (u < 0) return;\n        if (deg[u] != 1) {\n            used[u] =\
    \ 1;\n            alive--;\n            for (int v : g[u]) deg[v]--;\n       \
    \     dfs(dfs);\n            used[u] = 0;\n            alive++;\n            for\
    \ (int v : g[u]) deg[v]++;\n        }\n        vis[u] = true;\n        alive--;\n\
    \        for (int v : g[u]) {\n            if (!used[v]++) alive--;\n        }\n\
    \        cnt++;\n        if (cur < cnt) {\n            ans = vis;\n          \
    \  cur = cnt;\n        }\n        dfs(dfs);\n        vis[u] = 0;\n        alive++;\n\
    \        for (int v : g[u]) {\n            if (!--used[v]) alive++;\n        }\n\
    \        cnt--;\n    };\n    dfs(dfs);\n    vector<int> res;\n    for (int i =\
    \ 0; i < n; i++) {\n        if (ans[i]) res.push_back(i);\n    }\n    return res;\n\
    }\n\ninline vector<int> maximum_independent_set_adjacency(const vector<vector<int>>\
    \ &a) {\n    int n = a.size();\n    vector<vector<int>> g(n);\n    for (int u\
    \ = 0; u < n; u++) {\n        for (int v = 0; v < n; v++) {\n            if (a[u][v])\
    \ g[u].push_back(v);\n        }\n    }\n    return maximum_independent_set(g);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/maximum_independent_set.test.cpp
documentation_of: src/graph/maximum_independent_set.hpp
layout: document
redirect_from:
- /library/src/graph/maximum_independent_set.hpp
- /library/src/graph/maximum_independent_set.hpp.html
title: src/graph/maximum_independent_set.hpp
---
