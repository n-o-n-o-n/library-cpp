---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/bitwise_or_convolution.hpp
    title: src/convolution/bitwise_or_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/bitwise_or_convolution.test.cpp
    title: test/convolution/bitwise_or_convolution.test.cpp
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
    \ }\n#line 3 \"src/convolution/subset_zmt.hpp\"\n\ntemplate<typename mint>\nvoid\
    \ subset_zmt(vector<mint> &f, bool moebius = false) {\n    int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for (int i = 1; i < n; i <<= 1) {\n    \
    \    for (int j = 0; j < n; j++) {\n            if (i & j) continue;\n       \
    \     f[i | j] += moebius ? -f[j] : f[j];\n        }\n    }\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename mint>\nvoid\
    \ subset_zmt(vector<mint> &f, bool moebius = false) {\n    int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for (int i = 1; i < n; i <<= 1) {\n    \
    \    for (int j = 0; j < n; j++) {\n            if (i & j) continue;\n       \
    \     f[i | j] += moebius ? -f[j] : f[j];\n        }\n    }\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/convolution/subset_zmt.hpp
  requiredBy:
  - src/convolution/bitwise_or_convolution.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/bitwise_or_convolution.test.cpp
documentation_of: src/convolution/subset_zmt.hpp
layout: document
redirect_from:
- /library/src/convolution/subset_zmt.hpp
- /library/src/convolution/subset_zmt.hpp.html
title: src/convolution/subset_zmt.hpp
---
