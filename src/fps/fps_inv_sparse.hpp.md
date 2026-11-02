---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_inv_sparse.test.cpp
    title: test/fps/fps_inv_sparse.test.cpp
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
    \ }\n#line 3 \"src/fps/fps_inv_sparse.hpp\"\n\ntemplate<typename mint>\nvector<mint>\
    \ fps_inv_sparse(const vector<pair<int, mint>> &f_sub, int n) {\n    assert(f_sub.size()\
    \ && f_sub[0].first == 0 && f_sub[0].second != 0);\n    mint cef = f_sub[0].second.inv();\n\
    \    vector<mint> g(n);\n    g[0] = 1;\n    for (int i = 0; i < n; i++) {\n  \
    \      if (g[i] != 0) {\n            g[i] *= cef;\n            for (auto [a,c]\
    \ : f_sub) {\n                if (0 < a && i + a < n) {\n                    g[i\
    \ + a] -= g[i] * c;\n                }\n            }\n        }\n    }\n    return\
    \ g;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename mint>\nvector<mint>\
    \ fps_inv_sparse(const vector<pair<int, mint>> &f_sub, int n) {\n    assert(f_sub.size()\
    \ && f_sub[0].first == 0 && f_sub[0].second != 0);\n    mint cef = f_sub[0].second.inv();\n\
    \    vector<mint> g(n);\n    g[0] = 1;\n    for (int i = 0; i < n; i++) {\n  \
    \      if (g[i] != 0) {\n            g[i] *= cef;\n            for (auto [a,c]\
    \ : f_sub) {\n                if (0 < a && i + a < n) {\n                    g[i\
    \ + a] -= g[i] * c;\n                }\n            }\n        }\n    }\n    return\
    \ g;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/fps/fps_inv_sparse.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/fps_inv_sparse.test.cpp
documentation_of: src/fps/fps_inv_sparse.hpp
layout: document
redirect_from:
- /library/src/fps/fps_inv_sparse.hpp
- /library/src/fps/fps_inv_sparse.hpp.html
title: src/fps/fps_inv_sparse.hpp
---
