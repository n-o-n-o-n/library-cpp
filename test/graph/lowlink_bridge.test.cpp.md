---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/lowlink.hpp
    title: src/graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
  bundledCode: "#line 1 \"test/graph/lowlink_bridge.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B\"\n\n#line 2\
    \ \"src/graph/lowlink.hpp\"\n#include <algorithm>\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\nusing namespace std;\n\nstruct lowlink {\n   \
    \ lowlink(int _n = 0, int m = 0) : n(_n), g(_n), built(false) {\n        edges.reserve(m);\n\
    \    }\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        g[u].emplace_back(v, edges.size());\n\
    \        g[v].emplace_back(u, edges.size());\n        edges.emplace_back(u, v);\n\
    \        built = false;\n    }\n    vector<int> operator[](int p) const {\n  \
    \      vector<int> res;\n        res.reserve(g[p].size());\n        for (auto\
    \ [v, _] : g[p]) res.emplace_back(v);\n        return res;\n    }\n    vector<int>\
    \ articulation_point() {\n        build();\n        return ap;\n    }\n    vector<pair<int,\
    \ int>> bridge() {\n        build();\n        return bg;\n    }\n    bool is_bridge(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        build();\n        if (ord[u] > ord[v]) swap(u, v);\n        return\
    \ ord[u] < low[v];\n    }\n    vector<vector<int>> biconnected_components() {\n\
    \        build();\n        vector<bool> used(n, false);\n        vector<int> memo;\n\
    \        vector<vector<int>> bccs;\n        auto decompose = [&] (const auto &decompose,\
    \ int u, int p) -> void {\n            used[u] = true;\n            bool flag\
    \ = false;\n            for (auto [v, i] : g[u]) {\n                if (v == p\
    \ && !exchange(flag, true)) continue;\n                if (!used[v] || ord[v]\
    \ < ord[u]) memo.push_back(i);\n                if (!used[v]) {\n            \
    \        decompose(decompose, v, u);\n                    if (ord[u] <= low[v])\
    \ {\n                        bccs.emplace_back();\n                        while\
    \ (memo.size()) {\n                            auto j = memo.back();\n       \
    \                     memo.pop_back();\n                            bccs.back().push_back(j);\n\
    \                            if (i == j) break;\n                        }\n \
    \                   }\n                }\n            }\n        };\n        for\
    \ (int i = 0; i < n; i++) {\n            if (!used[i]) decompose(decompose, i,\
    \ - 1);\n        }\n        vector<vector<int>> res;\n        vector<bool> check(n,\
    \ false), seen(n, false);\n        auto insert = [&] (int u) -> void {\n     \
    \       if (!check[u]) {\n                check[u] = true;\n                seen[u]\
    \ = true;\n                res.back().push_back(u);\n            }\n        };\n\
    \        for (auto bcc : bccs) {\n            res.emplace_back();\n          \
    \  for (int i : bcc) {\n                auto [u, v] = edges[i];\n            \
    \    insert(u);\n                insert(v);\n            }\n            for (int\
    \ u : res.back()) check[u] = false;\n        }\n        for (int i = 0; i < n;\
    \ i++) {\n            if (!seen[i]) res.emplace_back(1, i);\n        }\n     \
    \   return res;\n    }\n    vector<vector<int>> two_edge_connected_components()\
    \ {\n        build();\n        int k = 0;\n        vector<int> tecc(n, -1);\n\
    \        auto decompose = [&] (const auto &decompose, int u) -> void {\n     \
    \       tecc[u] = k;\n            for (auto [v, _] : g[u]) {\n               \
    \ if (tecc[v] == -1 && !is_bridge(u, v)) decompose(decompose, v);\n          \
    \  }\n        };\n        for (int i = 0; i < n; i++) {\n            if (tecc[i]\
    \ == -1) {\n                decompose(decompose, i);\n                k++;\n \
    \           }\n        }\n        vector<vector<int>> res(k);\n        for (int\
    \ i = 0; i < n; i++) {\n            res[tecc[i]].push_back(i);\n        }\n  \
    \      return res;\n    }\nprivate:\n    int n;\n    vector<vector<pair<int, int>>>\
    \ g;\n    vector<pair<int, int>> edges;\n    bool built;\n    vector<int> ord,\
    \ low, ap;\n    vector<pair<int, int>> bg;\n    int dfs(int u, int k, int p) {\n\
    \        low[u] = (ord[u] = k++);\n        int c = 0;\n        bool art = false,\
    \ sec = false;\n        for (auto [v, _] : g[u]) {\n            if (ord[v] ==\
    \ -1) {\n                c++;\n                k = dfs(v, k, u);\n           \
    \     low[u] = min(low[u], low[v]);\n                art |= (p != -1) && (low[v]\
    \ >= ord[u]);\n                if (ord[u] < low[v]) {\n                    bg.push_back(minmax(u,\
    \ v));\n                }\n            } else if (v != p || sec) {\n         \
    \       low[u] = min(low[u], ord[v]);\n            } else {\n                sec\
    \ = true;\n            }\n        }\n        art |= (p == -1) && (c > 1);\n  \
    \      if (art) ap.push_back(u);\n        return k;\n    }\n    void build() {\n\
    \        if (built) return;\n        int k = 0;\n        ord = vector<int>(n,\
    \ -1);\n        low = vector<int>(n, -1);\n        for (int i = 0; i < n; i++)\
    \ {\n            if (ord[i] == -1) {\n                k = dfs(i, k, -1);\n   \
    \         }\n        }\n        built = true;\n    }\n};\n#line 4 \"test/graph/lowlink_bridge.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, M;\n    cin >> N >> M;\n    lowlink G(N, M);\n\
    \    for (int u, v; M--; ) {\n        cin >> u >> v;\n        G.add_edge(u, v);\n\
    \    }\n    auto bridge = G.bridge();\n    for (auto &[u, v] : bridge) if (u >\
    \ v) swap(u, v);\n    sort(bridge.begin(), bridge.end());\n    for (auto [u, v]\
    \ : bridge) cout << u << ' ' << v << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B\"\
    \n\n#include \"../../src/graph/lowlink.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, M;\n\
    \    cin >> N >> M;\n    lowlink G(N, M);\n    for (int u, v; M--; ) {\n     \
    \   cin >> u >> v;\n        G.add_edge(u, v);\n    }\n    auto bridge = G.bridge();\n\
    \    for (auto &[u, v] : bridge) if (u > v) swap(u, v);\n    sort(bridge.begin(),\
    \ bridge.end());\n    for (auto [u, v] : bridge) cout << u << ' ' << v << '\\\
    n';\n}"
  dependsOn:
  - src/graph/lowlink.hpp
  isVerificationFile: true
  path: test/graph/lowlink_bridge.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lowlink_bridge.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lowlink_bridge.test.cpp
- /verify/test/graph/lowlink_bridge.test.cpp.html
title: test/graph/lowlink_bridge.test.cpp
---
