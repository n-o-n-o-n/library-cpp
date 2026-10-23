---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/union_find.hpp
    title: src/data_structure/union_find/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/data_structure/union_find/union_find.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"src/data_structure/union_find/union_find.hpp\"\
    \n#include <cassert>\n#include <iterator>\n#include <vector>\nusing namespace\
    \ std;\n\nstruct union_find {\n    union_find(int n) : p(n, -1) {}\n    int leader(int\
    \ u) {\n        assert(0 <= u && u < ssize(p));\n        return p[u] < 0 ? u :\
    \ p[u] = leader(p[u]);\n    }\n    bool same(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        return\
    \ leader(u) == leader(v);\n    }\n    void merge(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        u =\
    \ leader(u);\n        v = leader(v);\n        if (u == v) return;\n        if\
    \ (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n        p[v] = u;\n    }\n\
    \    int size(int u) {\n        assert(0 <= u && u < ssize(p));\n        return\
    \ -p[leader(u)];\n    }\n    vector<vector<int>> groups() {\n        int n = p.size();\n\
    \        vector<vector<int>> tmp(n);\n        for (int i = 0; i < n; i++) {\n\
    \            tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n\
    \        }\n        return res;\n    }\nprivate:\n    vector<int> p;\n};\n#line\
    \ 4 \"test/data_structure/union_find/union_find.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    union_find uf(N);\n    for (int t, u, v; Q--;\
    \ ) {\n        cin >> t >> u >> v;\n        if (t == 0) {\n            uf.merge(u,\
    \ v);\n        } else {\n            cout << uf.same(u, v) << '\\n';\n       \
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../src/data_structure/union_find/union_find.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    union_find uf(N);\n    for (int t, u, v; Q--;\
    \ ) {\n        cin >> t >> u >> v;\n        if (t == 0) {\n            uf.merge(u,\
    \ v);\n        } else {\n            cout << uf.same(u, v) << '\\n';\n       \
    \ }\n    }\n}"
  dependsOn:
  - src/data_structure/union_find/union_find.hpp
  isVerificationFile: true
  path: test/data_structure/union_find/union_find.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union_find/union_find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union_find/union_find.test.cpp
- /verify/test/data_structure/union_find/union_find.test.cpp.html
title: test/data_structure/union_find/union_find.test.cpp
---
