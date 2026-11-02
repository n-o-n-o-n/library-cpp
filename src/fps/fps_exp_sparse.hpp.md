---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/fps/fps_exp_sparse.test.cpp
    title: test/fps/fps_exp_sparse.test.cpp
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
    \ }\n#line 3 \"src/fps/fps_exp_sparse.hpp\"\n\ntemplate<typename mint>\nvector<mint>\
    \ fps_exp_sparse(const vector<pair<int, mint>> &f_sub, int n) {\n    vector<mint>\
    \ g(n), inv(n);\n    if (f_sub.empty()) {\n        g[0] = 1;\n        return g;\n\
    \    }\n    assert(f_sub[0].first > 0);\n    const int mod = mint::mod();\n  \
    \  g[0] = 1;\n    if (n > 1) inv[1] = mint::raw(1);\n    for (int i = 1; i < n;\
    \ i++) {\n        for (auto [a, c] : f_sub) {\n            if (a <= i) {\n   \
    \             g[i] += a * c * g[i - a];\n            }\n        }\n        if\
    \ (i >= 2) {\n            inv[i] = -inv[mod % i] * (mod / i);\n            g[i]\
    \ *= inv[i];\n        }\n    }\n    return g;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename mint>\nvector<mint>\
    \ fps_exp_sparse(const vector<pair<int, mint>> &f_sub, int n) {\n    vector<mint>\
    \ g(n), inv(n);\n    if (f_sub.empty()) {\n        g[0] = 1;\n        return g;\n\
    \    }\n    assert(f_sub[0].first > 0);\n    const int mod = mint::mod();\n  \
    \  g[0] = 1;\n    if (n > 1) inv[1] = mint::raw(1);\n    for (int i = 1; i < n;\
    \ i++) {\n        for (auto [a, c] : f_sub) {\n            if (a <= i) {\n   \
    \             g[i] += a * c * g[i - a];\n            }\n        }\n        if\
    \ (i >= 2) {\n            inv[i] = -inv[mod % i] * (mod / i);\n            g[i]\
    \ *= inv[i];\n        }\n    }\n    return g;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/fps/fps_exp_sparse.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/fps_exp_sparse.test.cpp
documentation_of: src/fps/fps_exp_sparse.hpp
layout: document
redirect_from:
- /library/src/fps/fps_exp_sparse.hpp
- /library/src/fps/fps_exp_sparse.hpp.html
title: src/fps/fps_exp_sparse.hpp
---
