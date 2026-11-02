---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_div_sparse.test.cpp
    title: test/fps/fps_div_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/fps/fps_div_sparse.hpp\"\n\ntemplate<typename mint>\nvector<mint>\
    \ fps_div_sparse(vector<mint> f, const vector<pair<int, mint>> &g_sub) {\n   \
    \ assert(g_sub.size() && g_sub[0].first == 0 && g_sub[0].second != 0);\n    int\
    \ n = f.size();\n    mint cef = g_sub[0].second.inv();\n    for (int i = 0; i\
    \ < n; i++) {\n        f[i] *= cef;\n        for (auto [a, c] : g_sub) {\n   \
    \         if (0 < a && i + a < n) {\n                f[i + a] -= f[i] * c;\n \
    \           }\n        }\n    }\n    return f;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename mint>\nvector<mint>\
    \ fps_div_sparse(vector<mint> f, const vector<pair<int, mint>> &g_sub) {\n   \
    \ assert(g_sub.size() && g_sub[0].first == 0 && g_sub[0].second != 0);\n    int\
    \ n = f.size();\n    mint cef = g_sub[0].second.inv();\n    for (int i = 0; i\
    \ < n; i++) {\n        f[i] *= cef;\n        for (auto [a, c] : g_sub) {\n   \
    \         if (0 < a && i + a < n) {\n                f[i + a] -= f[i] * c;\n \
    \           }\n        }\n    }\n    return f;\n}\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/fps/fps_div_sparse.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/fps_div_sparse.test.cpp
documentation_of: src/fps/fps_div_sparse.hpp
layout: document
redirect_from:
- /library/src/fps/fps_div_sparse.hpp
- /library/src/fps/fps_div_sparse.hpp.html
title: src/fps/fps_div_sparse.hpp
---
