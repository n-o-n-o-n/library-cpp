---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/chromatic_number.hpp
    title: src/graph/chromatic_number.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/graph/chromatic_number.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n#line 2 \"src/graph/chromatic_number.hpp\"\
    \n#include <vector>\nusing namespace std;\n\ninline int chromatic_number_adjacency(const\
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
    \    }\n    return chromatic_number_adjacency(a);\n}\n#line 4 \"test/graph/chromatic_number.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>>\
    \ E(N, vector<int>(N));\n    for (int u, v; M--; ) {\n        cin >> u >> v;\n\
    \        E[u][v]++, E[v][u]++;\n    }\n    cout << chromatic_number_adjacency(E)\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n\
    #include \"../../src/graph/chromatic_number.hpp\"\n\n#include <iostream>\n\nint\
    \ main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N,\
    \ M;\n    cin >> N >> M;\n    vector<vector<int>> E(N, vector<int>(N));\n    for\
    \ (int u, v; M--; ) {\n        cin >> u >> v;\n        E[u][v]++, E[v][u]++;\n\
    \    }\n    cout << chromatic_number_adjacency(E) << '\\n';\n}"
  dependsOn:
  - src/graph/chromatic_number.hpp
  isVerificationFile: true
  path: test/graph/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/graph/chromatic_number.test.cpp
- /verify/test/graph/chromatic_number.test.cpp.html
title: test/graph/chromatic_number.test.cpp
---
