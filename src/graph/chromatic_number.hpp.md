---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/chromatic_number.test.cpp
    title: test/graph/chromatic_number.test.cpp
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
    \ }\n#line 3 \"src/graph/chromatic_number.hpp\"\n\ninline int chromatic_number_adjacency(const\
    \ vector<vector<int>> &a) {\n    int n = a.size();\n    vector<int> e(n);\n  \
    \  for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n    \
    \        e[i] |= a[i][j] << j;\n        }\n    }\n    vector<int> ind(1 << n);\n\
    \    ind[0] = 1;\n    for (int i = 1; i < 1 << n; i++) {\n        int u = __builtin_ctz(i);\n\
    \        ind[i] = ind[i ^ (1 << u)] + ind[(i ^ (1 << u)) & ~e[u]];\n    }\n  \
    \  auto ind2 = ind;\n    int k = 1, l = 0;\n    while (true) {\n        l = 0;\n\
    \        for (int i = 0; i < 1 << n; i++) {\n            l += (__builtin_parity(i)\
    \ ? -1 : 1) * ind2[i];\n        }\n        if (l != 0) break;\n        for (int\
    \ i = 1; i < 1 << n; i++) {\n            ind2[i] *= ind[i];\n        }\n     \
    \   k++;\n    }\n    return k;\n}\n\ninline int chromatic_number(const vector<vector<int>>\
    \ &g) {\n    int n = g.size();\n    vector<vector<int>> a(n, vector<int>(n));\n\
    \    for (int u = 0; u < n; u++) {\n        for (int v : g[u]) a[u][v]++, a[v][u]++;\n\
    \    }\n    return chromatic_number_adjacency(a);\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ninline int chromatic_number_adjacency(const\
    \ vector<vector<int>> &a) {\n    int n = a.size();\n    vector<int> e(n);\n  \
    \  for (int i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n    \
    \        e[i] |= a[i][j] << j;\n        }\n    }\n    vector<int> ind(1 << n);\n\
    \    ind[0] = 1;\n    for (int i = 1; i < 1 << n; i++) {\n        int u = __builtin_ctz(i);\n\
    \        ind[i] = ind[i ^ (1 << u)] + ind[(i ^ (1 << u)) & ~e[u]];\n    }\n  \
    \  auto ind2 = ind;\n    int k = 1, l = 0;\n    while (true) {\n        l = 0;\n\
    \        for (int i = 0; i < 1 << n; i++) {\n            l += (__builtin_parity(i)\
    \ ? -1 : 1) * ind2[i];\n        }\n        if (l != 0) break;\n        for (int\
    \ i = 1; i < 1 << n; i++) {\n            ind2[i] *= ind[i];\n        }\n     \
    \   k++;\n    }\n    return k;\n}\n\ninline int chromatic_number(const vector<vector<int>>\
    \ &g) {\n    int n = g.size();\n    vector<vector<int>> a(n, vector<int>(n));\n\
    \    for (int u = 0; u < n; u++) {\n        for (int v : g[u]) a[u][v]++, a[v][u]++;\n\
    \    }\n    return chromatic_number_adjacency(a);\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/graph/chromatic_number.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/chromatic_number.test.cpp
documentation_of: src/graph/chromatic_number.hpp
layout: document
redirect_from:
- /library/src/graph/chromatic_number.hpp
- /library/src/graph/chromatic_number.hpp.html
title: src/graph/chromatic_number.hpp
---
