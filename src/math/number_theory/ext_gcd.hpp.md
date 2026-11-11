---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/arbitrary_mod_convolution.hpp
    title: src/convolution/arbitrary_mod_convolution.hpp
  - icon: ':warning:'
    path: src/math/number_theory/crt.hpp
    title: src/math/number_theory/crt.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/garner.hpp
    title: Garner
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/mod_inv.hpp
    title: src/math/number_theory/mod_inv.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/arbitrary_mod_convolution.test.cpp
    title: test/convolution/arbitrary_mod_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/mod_inv.test.cpp
    title: test/math/number_theory/mod_inv.test.cpp
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
    \ }\n#line 3 \"src/math/number_theory/ext_gcd.hpp\"\n\n// find x, y s.t. ax +\
    \ by = gcd(a, b) and return gcd(a, b)\ntemplate<typename T>\nT ext_gcd(T a, T\
    \ b, T &x, T &y) {\n    T g = a;\n    if (b != 0) {\n        g = ext_gcd(b, a\
    \ % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n     \
    \   y = 0;\n    }\n    return g;\n}\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\n// find x, y s.t. ax + by\
    \ = gcd(a, b) and return gcd(a, b)\ntemplate<typename T>\nT ext_gcd(T a, T b,\
    \ T &x, T &y) {\n    T g = a;\n    if (b != 0) {\n        g = ext_gcd(b, a % b,\
    \ y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n        y =\
    \ 0;\n    }\n    return g;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/math/number_theory/ext_gcd.hpp
  requiredBy:
  - src/convolution/arbitrary_mod_convolution.hpp
  - src/math/number_theory/mod_inv.hpp
  - src/math/number_theory/garner.hpp
  - src/math/number_theory/crt.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/arbitrary_mod_convolution.test.cpp
  - test/math/number_theory/mod_inv.test.cpp
documentation_of: src/math/number_theory/ext_gcd.hpp
layout: document
title: Extended GCD
---

拡張ユークリッド互除法で最大公約数と Bézout 係数を求める.
`T` は符号付き整数型とする.

## ext_gcd

```
T ext_gcd(T a, T b, T &x, T &y)
```

- $a, b \ge 0$ とする
- $g = \gcd(a, b)$ を返し, $ax + by = g$ を満たす $x, y$ を参照引数に代入する
- $O(\log(\max(a, b)))$
