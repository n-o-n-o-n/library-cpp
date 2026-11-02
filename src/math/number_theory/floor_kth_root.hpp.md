---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/number_theory/floor_kth_root.test.cpp
    title: test/math/number_theory/floor_kth_root.test.cpp
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
    \ }\n#line 3 \"src/math/number_theory/floor_kth_root.hpp\"\n\n// floor( a^(1/k)\
    \ )\ntemplate<typename T>\nT floor_kth_root(T a, T k) {\n    assert(0 <= a);\n\
    \    if (a == 0 || a == 1 || k == 1) return a;\n    if (64 <= k) return 1;\n \
    \   constexpr T inf = numeric_limits<T>::max();\n    if (a == inf) a--;\n    auto\
    \ mul = [&](T x, T y) -> T {\n        return x <= inf / y ? x * y : inf;\n   \
    \ };\n    auto pw = [&](T x, T n) -> T {\n        T r = 1;\n        while (n >\
    \ 0) {\n            if (n & 1) r = mul(r, x);\n            x = mul(x, x);\n  \
    \          n >>= 1;\n        }\n        return r;\n    };\n    T res = (k == 2\
    \ ? sqrtl(a) - 1 : k == 3 ? cbrtl(a) - 1 : pow(a, nextafter(1.0 / k, 0)));\n \
    \   while (pw(res + 1, k) <= a) res++;\n    return res;\n}\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\n// floor( a^(1/k) )\ntemplate<typename\
    \ T>\nT floor_kth_root(T a, T k) {\n    assert(0 <= a);\n    if (a == 0 || a ==\
    \ 1 || k == 1) return a;\n    if (64 <= k) return 1;\n    constexpr T inf = numeric_limits<T>::max();\n\
    \    if (a == inf) a--;\n    auto mul = [&](T x, T y) -> T {\n        return x\
    \ <= inf / y ? x * y : inf;\n    };\n    auto pw = [&](T x, T n) -> T {\n    \
    \    T r = 1;\n        while (n > 0) {\n            if (n & 1) r = mul(r, x);\n\
    \            x = mul(x, x);\n            n >>= 1;\n        }\n        return r;\n\
    \    };\n    T res = (k == 2 ? sqrtl(a) - 1 : k == 3 ? cbrtl(a) - 1 : pow(a, nextafter(1.0\
    \ / k, 0)));\n    while (pw(res + 1, k) <= a) res++;\n    return res;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/math/number_theory/floor_kth_root.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/number_theory/floor_kth_root.test.cpp
documentation_of: src/math/number_theory/floor_kth_root.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/floor_kth_root.hpp
- /library/src/math/number_theory/floor_kth_root.hpp.html
title: src/math/number_theory/floor_kth_root.hpp
---
