---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/bmbm.hpp
    title: src/math/bmbm.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/berlekamp_massey.test.cpp
    title: test/math/berlekamp_massey.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/bmbm.test.cpp
    title: test/math/bmbm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/berlekamp_massey.hpp\"\n#include <algorithm>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename mint>\nvector<mint>\
    \ Berlekamp_Massey(const vector<mint> &a) {\n    int n = a.size();\n    vector<mint>\
    \ b = {1}, c = {1};\n    b.reserve(n + 1);\n    c.reserve(n + 1);\n    mint y\
    \ = 1;\n    for (int d = 1; d <= n; d ++) {\n        int k = b.size(), l = c.size();\n\
    \        mint x = 0;\n        for (int i = 0; i < l; i++) {\n            x +=\
    \ c[i] * a[d - l + i];\n        }\n        b.push_back(0);\n        k++;\n   \
    \     if (x == 0) continue;\n        mint buf = x / y;\n        if (l < k) {\n\
    \            auto tmp = c;\n            c.insert(c.begin(), k - l, 0);\n     \
    \       for (int i = 0; i < k; i++) {\n                c[k - 1 - i] -= buf * b[k\
    \ - 1 - i];\n            }\n            b = tmp;\n            y = x;\n       \
    \ } else {\n            for (int i = 0; i < k; i++) {\n                c[l - 1\
    \ - i] -= buf * b[k - 1 - i];\n            }\n        }\n    }\n    reverse(c.begin(),\
    \ c.end());\n    for (mint &x : c) x = -x;\n    return c;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename mint>\nvector<mint> Berlekamp_Massey(const vector<mint> &a)\
    \ {\n    int n = a.size();\n    vector<mint> b = {1}, c = {1};\n    b.reserve(n\
    \ + 1);\n    c.reserve(n + 1);\n    mint y = 1;\n    for (int d = 1; d <= n; d\
    \ ++) {\n        int k = b.size(), l = c.size();\n        mint x = 0;\n      \
    \  for (int i = 0; i < l; i++) {\n            x += c[i] * a[d - l + i];\n    \
    \    }\n        b.push_back(0);\n        k++;\n        if (x == 0) continue;\n\
    \        mint buf = x / y;\n        if (l < k) {\n            auto tmp = c;\n\
    \            c.insert(c.begin(), k - l, 0);\n            for (int i = 0; i < k;\
    \ i++) {\n                c[k - 1 - i] -= buf * b[k - 1 - i];\n            }\n\
    \            b = tmp;\n            y = x;\n        } else {\n            for (int\
    \ i = 0; i < k; i++) {\n                c[l - 1 - i] -= buf * b[k - 1 - i];\n\
    \            }\n        }\n    }\n    reverse(c.begin(), c.end());\n    for (mint\
    \ &x : c) x = -x;\n    return c;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/berlekamp_massey.hpp
  requiredBy:
  - src/math/bmbm.hpp
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/bmbm.test.cpp
  - test/math/berlekamp_massey.test.cpp
documentation_of: src/math/berlekamp_massey.hpp
layout: document
redirect_from:
- /library/src/math/berlekamp_massey.hpp
- /library/src/math/berlekamp_massey.hpp.html
title: src/math/berlekamp_massey.hpp
---
