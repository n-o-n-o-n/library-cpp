---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/fps/fps_mul_sparse.hpp\"\n\ntemplate<typename mint>\nvector<mint>\
    \ fps_mul_sparse(const vector<mint> &f, const vector<pair<int, mint>> &g_sub)\
    \ {\n    int n = f.size(), m = 0;\n    for (auto [j, _] : g_sub) chmax(m, j);\n\
    \    vector<mint> h(n + m);\n    for (auto [j, b] : g_sub) {\n        for (int\
    \ i = 0; i < n; i++) h[i + j] += f[i] * b;\n    }\n    while (h.size() && h.back()\
    \ == 0) h.pop_back();\n    return h;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename mint>\nvector<mint>\
    \ fps_mul_sparse(const vector<mint> &f, const vector<pair<int, mint>> &g_sub)\
    \ {\n    int n = f.size(), m = 0;\n    for (auto [j, _] : g_sub) chmax(m, j);\n\
    \    vector<mint> h(n + m);\n    for (auto [j, b] : g_sub) {\n        for (int\
    \ i = 0; i < n; i++) h[i + j] += f[i] * b;\n    }\n    while (h.size() && h.back()\
    \ == 0) h.pop_back();\n    return h;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/fps/fps_mul_sparse.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/fps/fps_mul_sparse.hpp
layout: document
redirect_from:
- /library/src/fps/fps_mul_sparse.hpp
- /library/src/fps/fps_mul_sparse.hpp.html
title: src/fps/fps_mul_sparse.hpp
---
