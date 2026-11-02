---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/lcm_convolution.hpp
    title: src/convolution/lcm_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/lcm_convolution.test.cpp
    title: test/convolution/lcm_convolution.test.cpp
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
    \ }\n#line 3 \"src/convolution/divisor_zmt.hpp\"\n\ntemplate<typename mint>\n\
    void divisor_zmt(vector<mint> &f, bool moebius = false) {\n    int n = f.size();\n\
    \    vector<bool> sieve(n, true);\n    for (int i = 2; i < n; i++) {\n       \
    \ if (sieve[i]) {\n            if (moebius) {\n                for (int j = (n\
    \ - 1) / i; j > 0; j--) {\n                    sieve[i * j] = false;\n       \
    \             f[i * j] -= f[j];\n                }\n            } else {\n   \
    \             for (int j = 1; i * j < n; j++) {\n                    sieve[i *\
    \ j] = false;\n                    f[i * j] += f[j];\n                }\n    \
    \        }\n        }\n    }\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename mint>\nvoid\
    \ divisor_zmt(vector<mint> &f, bool moebius = false) {\n    int n = f.size();\n\
    \    vector<bool> sieve(n, true);\n    for (int i = 2; i < n; i++) {\n       \
    \ if (sieve[i]) {\n            if (moebius) {\n                for (int j = (n\
    \ - 1) / i; j > 0; j--) {\n                    sieve[i * j] = false;\n       \
    \             f[i * j] -= f[j];\n                }\n            } else {\n   \
    \             for (int j = 1; i * j < n; j++) {\n                    sieve[i *\
    \ j] = false;\n                    f[i * j] += f[j];\n                }\n    \
    \        }\n        }\n    }\n}\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/convolution/divisor_zmt.hpp
  requiredBy:
  - src/convolution/lcm_convolution.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/lcm_convolution.test.cpp
documentation_of: src/convolution/divisor_zmt.hpp
layout: document
redirect_from:
- /library/src/convolution/divisor_zmt.hpp
- /library/src/convolution/divisor_zmt.hpp.html
title: src/convolution/divisor_zmt.hpp
---
