---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/maximum_independent_set.hpp
    title: src/graph/maximum_independent_set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/graph/maximum_independent_set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\n#line 2 \"src/graph/maximum_independent_set.hpp\"\
    \n#include <vector>\nusing namespace std;\n\ninline vector<int> maximum_independent_set(const\
    \ vector<vector<int>> &g) {\n    int n = g.size();\n    vector<int> deg(n), used(n);\n\
    \    vector<bool> vis(n), ans(n);\n    for (int i = 0; i < n; i++) deg[i] = g[i].size();\n\
    \    int cur = 0, cnt = 0, alive = n;\n    auto dfs = [&](const auto &dfs) ->\
    \ void {\n        if (cnt + alive <= cur) return;\n        int u = -1;\n     \
    \   for (int i = 0; i < n; i++) {\n            if (!vis[i] && !used[i]) {\n  \
    \              if (deg[i] <= 1) {\n                    u = i;\n              \
    \      break;\n                }\n                if (u < 0 || deg[u] < deg[i])\
    \ u = i;\n            }\n        }\n        if (u < 0) return;\n        if (deg[u]\
    \ != 1) {\n            used[u] = 1;\n            alive--;\n            for (int\
    \ v : g[u]) deg[v]--;\n            dfs(dfs);\n            used[u] = 0;\n     \
    \       alive++;\n            for (int v : g[u]) deg[v]++;\n        }\n      \
    \  vis[u] = true;\n        alive--;\n        for (int v : g[u]) {\n          \
    \  if (!used[v]++) alive--;\n        }\n        cnt++;\n        if (cur < cnt)\
    \ {\n            ans = vis;\n            cur = cnt;\n        }\n        dfs(dfs);\n\
    \        vis[u] = 0;\n        alive++;\n        for (int v : g[u]) {\n       \
    \     if (!--used[v]) alive++;\n        }\n        cnt--;\n    };\n    dfs(dfs);\n\
    \    vector<int> res;\n    for (int i = 0; i < n; i++) {\n        if (ans[i])\
    \ res.push_back(i);\n    }\n    return res;\n}\n\ninline vector<int> maximum_independent_set_adjacency(const\
    \ vector<vector<int>> &a) {\n    int n = a.size();\n    vector<vector<int>> g(n);\n\
    \    for (int u = 0; u < n; u++) {\n        for (int v = 0; v < n; v++) {\n  \
    \          if (a[u][v]) g[u].push_back(v);\n        }\n    }\n    return maximum_independent_set(g);\n\
    }\n#line 4 \"test/graph/maximum_independent_set.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, M;\n    cin >> N >> M;\n    vector<vector<int>> E(N, vector<int>(N));\n \
    \   for (int u, v; M--; ) {\n        cin >> u >> v;\n        E[u][v]++, E[v][u]++;\n\
    \    }\n    auto ans = maximum_independent_set_adjacency(E);\n    cout << ssize(ans)\
    \ << '\\n';\n    for (int i = 0; i < ssize(ans); i++) {\n        cout << ans[i]\
    \ << \" \\n\"[i + 1 == ssize(ans)];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include \"../../src/graph/maximum_independent_set.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, M;\n    cin >> N >> M;\n    vector<vector<int>> E(N, vector<int>(N));\n \
    \   for (int u, v; M--; ) {\n        cin >> u >> v;\n        E[u][v]++, E[v][u]++;\n\
    \    }\n    auto ans = maximum_independent_set_adjacency(E);\n    cout << ssize(ans)\
    \ << '\\n';\n    for (int i = 0; i < ssize(ans); i++) {\n        cout << ans[i]\
    \ << \" \\n\"[i + 1 == ssize(ans)];\n    }\n}"
  dependsOn:
  - src/graph/maximum_independent_set.hpp
  isVerificationFile: true
  path: test/graph/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/graph/maximum_independent_set.test.cpp
- /verify/test/graph/maximum_independent_set.test.cpp.html
title: test/graph/maximum_independent_set.test.cpp
---
