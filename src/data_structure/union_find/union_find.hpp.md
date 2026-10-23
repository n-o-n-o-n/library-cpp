---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/union_find.test.cpp
    title: test/data_structure/union_find/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/misc/parallel_binary_search.test.cpp
    title: test/misc/parallel_binary_search.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/union_find/union_find.hpp\"\n#include\
    \ <cassert>\n#include <iterator>\n#include <vector>\nusing namespace std;\n\n\
    struct union_find {\n    union_find(int n) : p(n, -1) {}\n    int leader(int u)\
    \ {\n        assert(0 <= u && u < ssize(p));\n        return p[u] < 0 ? u : p[u]\
    \ = leader(p[u]);\n    }\n    bool same(int u, int v) {\n        assert(0 <= u\
    \ && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        return leader(u)\
    \ == leader(v);\n    }\n    void merge(int u, int v) {\n        assert(0 <= u\
    \ && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        u = leader(u);\n\
    \        v = leader(v);\n        if (u == v) return;\n        if (p[u] > p[v])\
    \ swap(u, v);\n        p[u] += p[v];\n        p[v] = u;\n    }\n    int size(int\
    \ u) {\n        assert(0 <= u && u < ssize(p));\n        return -p[leader(u)];\n\
    \    }\n    vector<vector<int>> groups() {\n        int n = p.size();\n      \
    \  vector<vector<int>> tmp(n);\n        for (int i = 0; i < n; i++) {\n      \
    \      tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>> res;\n\
    \        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n \
    \       }\n        return res;\n    }\nprivate:\n    vector<int> p;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <iterator>\n#include <vector>\n\
    using namespace std;\n\nstruct union_find {\n    union_find(int n) : p(n, -1)\
    \ {}\n    int leader(int u) {\n        assert(0 <= u && u < ssize(p));\n     \
    \   return p[u] < 0 ? u : p[u] = leader(p[u]);\n    }\n    bool same(int u, int\
    \ v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v && v <\
    \ ssize(p));\n        return leader(u) == leader(v);\n    }\n    void merge(int\
    \ u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v\
    \ && v < ssize(p));\n        u = leader(u);\n        v = leader(v);\n        if\
    \ (u == v) return;\n        if (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n\
    \        p[v] = u;\n    }\n    int size(int u) {\n        assert(0 <= u && u <\
    \ ssize(p));\n        return -p[leader(u)];\n    }\n    vector<vector<int>> groups()\
    \ {\n        int n = p.size();\n        vector<vector<int>> tmp(n);\n        for\
    \ (int i = 0; i < n; i++) {\n            tmp[leader(i)].push_back(i);\n      \
    \  }\n        vector<vector<int>> res;\n        for (auto v : tmp) {\n       \
    \     if (v.size()) res.push_back(v);\n        }\n        return res;\n    }\n\
    private:\n    vector<int> p;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/union_find/union_find.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/parallel_binary_search.test.cpp
  - test/data_structure/union_find/union_find.test.cpp
documentation_of: src/data_structure/union_find/union_find.hpp
layout: document
redirect_from:
- /library/src/data_structure/union_find/union_find.hpp
- /library/src/data_structure/union_find/union_find.hpp.html
title: src/data_structure/union_find/union_find.hpp
---
