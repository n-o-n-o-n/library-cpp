---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/graph/scc.test.cpp\"\n#define  PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#line 2 \"src/graph/scc.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\nstruct scc_graph {\n    scc_graph(int\
    \ _n = 0) : n(_n), g(_n), g_rev(_n) {}\n    void add_edge(int u, int v) {\n  \
    \      assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
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
    \ v : g_rev[u]) sfd(v, k);\n    }\n};\n#line 4 \"test/graph/scc.test.cpp\"\n\n\
    #include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, M;\n    cin >> N >> M;\n    scc_graph G(N);\n    for (int u, v; M--;\
    \ ) {\n        cin >> u >> v;\n        G.add_edge(u, v);\n    }\n    auto ans\
    \ = G.scc();\n    cout << ans.size() << '\\n';\n    for (auto V : ans) {\n   \
    \     cout << ssize(V);\n        for (auto v : V) cout << ' ' << v;\n        cout\
    \ << '\\n';\n    }\n}\n"
  code: "#define  PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../src/graph/scc.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, M;\n    cin >> N >> M;\n    scc_graph G(N);\n\
    \    for (int u, v; M--; ) {\n        cin >> u >> v;\n        G.add_edge(u, v);\n\
    \    }\n    auto ans = G.scc();\n    cout << ans.size() << '\\n';\n    for (auto\
    \ V : ans) {\n        cout << ssize(V);\n        for (auto v : V) cout << ' '\
    \ << v;\n        cout << '\\n';\n    }\n}"
  dependsOn:
  - src/graph/scc.hpp
  isVerificationFile: true
  path: test/graph/scc.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/test/graph/scc.test.cpp
- /verify/test/graph/scc.test.cpp.html
title: test/graph/scc.test.cpp
---
