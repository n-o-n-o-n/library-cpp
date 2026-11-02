---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bipartite_matching.hpp
    title: src/graph/bipartite_matching.hpp
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/graph/bipartite_matching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    template<typename T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2;\
    \ }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a\
    \ > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/graph/bipartite_matching.hpp\"\
    \n\nstruct bipartite_matching {\n    int n, m;\n    bipartite_matching(int _n,\
    \ int _m) : n(_n), m(_m), g(_n), match(_m, -1), used(_n) {}\n    void add_edge(int\
    \ u, int v) {\n        g[u].push_back(v);\n    }\n    vector<pair<int, int>> matching()\
    \ {\n        build();\n        vector<pair<int, int>> res;\n        for (int i\
    \ = 0; i < m; i++) {\n            if (match[i] != -1) {\n                res.emplace_back(match[i],\
    \ i);\n            }\n        }\n        return res;\n    }\nprivate:\n    vector<vector<int>>\
    \ g;\n    vector<int> match, dist;\n    vector<bool> vis, used;\n    void bfs()\
    \ {\n        dist = vector<int>(n, inf<int>());\n        queue<int> q;\n     \
    \   for (int i = 0; i < n; i++) {\n            if (!used[i]) {\n             \
    \   q.push(i);\n                dist[i] = 0;\n            }\n        }\n     \
    \   while (q.size()) {\n            int u = q.front();\n            q.pop();\n\
    \            for (int v : g[u]) {\n                int w = match[v];\n       \
    \         if (0 <= w && dist[w] == inf<int>()) {\n                    dist[w]\
    \ = dist[u] + 1;\n                    q.push(w);\n                }\n        \
    \    }\n        }\n    }\n    bool dfs(int u) {\n        vis[u] = true;\n    \
    \    for (int v : g[u]) {\n            int w = match[v];\n            if (w <\
    \ 0 || (!vis[w] && dist[w] == dist[u] + 1 && dfs(w))) {\n                match[v]\
    \ = u;\n                used[u] = true;\n                return true;\n      \
    \      }\n        }\n        return false;\n    }\n    void build() {\n      \
    \  while (true) {\n            bfs();\n            vis = vector<bool>(n, false);\n\
    \            int flow = 0;\n            for (int i = 0; i < n; i++) {\n      \
    \          flow += (!used[i] && dfs(i));\n            }\n            if (flow\
    \ == 0) break;\n        }\n    }\n};\n#line 5 \"test/graph/bipartite_matching.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int L, R, M;\n    cin >> L >> R >> M;\n    bipartite_matching G(L, R);\n  \
    \  for (int u, v; M--; ) {\n        cin >> u >> v;\n        G.add_edge(u, v);\n\
    \    }\n    auto ans = G.matching();\n    cout << ans.size() << '\\n';\n    for\
    \ (auto [u, v] : ans) cout << u << ' ' << v << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../../src/template.hpp\"\n#include \"../../src/graph/bipartite_matching.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int L, R, M;\n    cin >> L >> R >> M;\n    bipartite_matching G(L, R);\n  \
    \  for (int u, v; M--; ) {\n        cin >> u >> v;\n        G.add_edge(u, v);\n\
    \    }\n    auto ans = G.matching();\n    cout << ans.size() << '\\n';\n    for\
    \ (auto [u, v] : ans) cout << u << ' ' << v << '\\n';\n}"
  dependsOn:
  - src/template.hpp
  - src/graph/bipartite_matching.hpp
  isVerificationFile: true
  path: test/graph/bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/test/graph/bipartite_matching.test.cpp
- /verify/test/graph/bipartite_matching.test.cpp.html
title: test/graph/bipartite_matching.test.cpp
---
