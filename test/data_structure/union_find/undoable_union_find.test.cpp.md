---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/undoable_union_find.hpp
    title: Undoable Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/data_structure/union_find/undoable_union_find.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n\
    #line 2 \"src/data_structure/union_find/undoable_union_find.hpp\"\n#include <cassert>\n\
    #include <numeric>\n#include <stack>\n#include <tuple>\n#include <vector>\nusing\
    \ namespace std;\n\nstruct undoable_union_find {\n    undoable_union_find() =\
    \ default;\n    undoable_union_find(int n) : p(n, -1), cyc(n) {\n        iota(cyc.begin(),\
    \ cyc.end(), 0);\n    }\n    int leader(int u) const {\n        assert(0 <= u\
    \ && u < ssize(p));\n        return p[u] < 0 ? u : leader(p[u]);\n    }\n    bool\
    \ same(int u, int v) const {\n        assert(0 <= u && u < ssize(p));\n      \
    \  assert(0 <= v && v < ssize(p));\n        return leader(u) == leader(v);\n \
    \   }\n    void merge(int u, int v) {\n        assert(0 <= u && u < ssize(p));\n\
    \        assert(0 <= v && v < ssize(p));\n        u = leader(u);\n        v =\
    \ leader(v);\n        his.emplace(u, p[u], cyc[u]);\n        his.emplace(v, p[v],\
    \ cyc[v]);\n        if (u == v) return;\n        if (p[u] > p[v]) swap(u, v);\n\
    \        p[u] += p[v];\n        p[v] = u;\n        swap(cyc[u], cyc[v]);\n   \
    \ }\n    int size(int u) const {\n        assert(0 <= u && u < ssize(p));\n  \
    \      return -p[leader(u)];\n    }\n    void undo() {\n        assert(his.size());\n\
    \        for (auto _ : {0, 1}) {\n            auto [u, pu, cu] = his.top();\n\
    \            his.pop();\n            p[u] = pu;\n            cyc[u] = cu;\n  \
    \      }\n    }\n    vector<int> group(int u) const {\n        vector<int> res\
    \ = {u};\n        int v = cyc[u];\n        while (v != u) {\n            res.push_back(v);\n\
    \            v = cyc[v];\n        }\n        return res;\n    }\n    vector<vector<int>>\
    \ groups() const {\n        int n = p.size();\n        vector<vector<int>> tmp(n);\n\
    \        for (int i = 0; i < n; i++) {\n            tmp[leader(i)].push_back(i);\n\
    \        }\n        vector<vector<int>> res;\n        for (auto v : tmp) {\n \
    \           if (v.size()) res.push_back(v);\n        }\n        return res;\n\
    \    }\nprivate:\n    vector<int> p, cyc;\n    stack<tuple<int, int, int>> his;\n\
    };\n#line 4 \"test/data_structure/union_find/undoable_union_find.test.cpp\"\n\n\
    #include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<int> T(Q + 1), U(Q + 1), V(Q +\
    \ 1);\n    vector<vector<int>> G(Q + 1);\n    for (int i = 1, k; i <= Q; i++)\
    \ {\n        cin >> T[i] >> k >> U[i] >> V[i];\n        G[k + 1].push_back(i);\n\
    \    }\n    undoable_union_find uf(N);\n    vector<int> ans(Q + 1);\n    auto\
    \ dfs = [&](auto dfs, int u) -> void {\n        if (u > 0) {\n            if (T[u]\
    \ == 0) {\n                uf.merge(U[u], V[u]);\n            } else {\n     \
    \           ans[u] = uf.same(U[u], V[u]);\n            }\n        }\n        for\
    \ (int v : G[u]) dfs(dfs, v);\n        if (u > 0 && T[u] == 0) uf.undo();\n  \
    \  };\n    dfs(dfs, 0);\n    for (int i = 1; i <= Q; i++) {\n        if (T[i]\
    \ == 1) cout << ans[i] << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../../../src/data_structure/union_find/undoable_union_find.hpp\"\n\
    \n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<int> T(Q + 1), U(Q + 1), V(Q +\
    \ 1);\n    vector<vector<int>> G(Q + 1);\n    for (int i = 1, k; i <= Q; i++)\
    \ {\n        cin >> T[i] >> k >> U[i] >> V[i];\n        G[k + 1].push_back(i);\n\
    \    }\n    undoable_union_find uf(N);\n    vector<int> ans(Q + 1);\n    auto\
    \ dfs = [&](auto dfs, int u) -> void {\n        if (u > 0) {\n            if (T[u]\
    \ == 0) {\n                uf.merge(U[u], V[u]);\n            } else {\n     \
    \           ans[u] = uf.same(U[u], V[u]);\n            }\n        }\n        for\
    \ (int v : G[u]) dfs(dfs, v);\n        if (u > 0 && T[u] == 0) uf.undo();\n  \
    \  };\n    dfs(dfs, 0);\n    for (int i = 1; i <= Q; i++) {\n        if (T[i]\
    \ == 1) cout << ans[i] << '\\n';\n    }\n}\n"
  dependsOn:
  - src/data_structure/union_find/undoable_union_find.hpp
  isVerificationFile: true
  path: test/data_structure/union_find/undoable_union_find.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 16:40:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union_find/undoable_union_find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union_find/undoable_union_find.test.cpp
- /verify/test/data_structure/union_find/undoable_union_find.test.cpp.html
title: test/data_structure/union_find/undoable_union_find.test.cpp
---
