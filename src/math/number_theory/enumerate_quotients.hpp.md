---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/enumerate_quotient.test.cpp
    title: test/math/number_theory/enumerate_quotient.test.cpp
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
    \ }\n#line 3 \"src/math/number_theory/enumerate_quotients.hpp\"\n\n// for all\
    \ m in [l, r), floor(n/m) = q\ntemplate<typename T>\nvector<tuple<T, T, T>> enumerate_quotients(T\
    \ n) {\n    vector<tuple<T, T, T>> res;\n    for (T l = 1, r, q; l <= n; l = r)\
    \ {\n        q = n / l;\n        r = n / q + 1;\n        res.emplace_back(l, r,\
    \ q);\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\n// for all m in [l, r),\
    \ floor(n/m) = q\ntemplate<typename T>\nvector<tuple<T, T, T>> enumerate_quotients(T\
    \ n) {\n    vector<tuple<T, T, T>> res;\n    for (T l = 1, r, q; l <= n; l = r)\
    \ {\n        q = n / l;\n        r = n / q + 1;\n        res.emplace_back(l, r,\
    \ q);\n    }\n    return res;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/math/number_theory/enumerate_quotients.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/number_theory/enumerate_quotient.test.cpp
documentation_of: src/math/number_theory/enumerate_quotients.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/enumerate_quotients.hpp
- /library/src/math/number_theory/enumerate_quotients.hpp.html
title: src/math/number_theory/enumerate_quotients.hpp
---
