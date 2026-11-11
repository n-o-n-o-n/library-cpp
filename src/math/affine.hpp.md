---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/monoid/range_affine_range_sum.hpp
    title: src/monoid/range_affine_range_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/misc/dswag.test.cpp
    title: test/data_structure/misc/dswag.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/misc/swag.test.cpp
    title: test/data_structure/misc/swag.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/dualsegtree.test.cpp
    title: test/data_structure/range_query/dualsegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/dynamic_lazysegtree.test.cpp
    title: test/data_structure/range_query/dynamic_lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/dynamic_segtree.test.cpp
    title: test/data_structure/range_query/dynamic_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/lazysegtree.test.cpp
    title: test/data_structure/range_query/lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/segtree.test.cpp
    title: test/data_structure/range_query/segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/discrete_logarithm.test.cpp
    title: test/math/number_theory/discrete_logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hld.test.cpp
    title: test/tree/hld.test.cpp
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
    \ }\n#line 3 \"src/math/affine.hpp\"\n\ntemplate<typename mint>\nstruct affine\
    \ {\n    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const mint &_a,\
    \ const mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint &x) const\
    \ {\n        return a * x + b;\n    }\n    affine operator()(const affine &f)\
    \ const {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n        return\
    \ affine(c, d);\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename mint>\nstruct\
    \ affine {\n    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const mint\
    \ &_a, const mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint &x) const\
    \ {\n        return a * x + b;\n    }\n    affine operator()(const affine &f)\
    \ const {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n        return\
    \ affine(c, d);\n    }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/math/affine.hpp
  requiredBy:
  - src/monoid/range_affine_range_sum.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/misc/dswag.test.cpp
  - test/data_structure/misc/swag.test.cpp
  - test/data_structure/range_query/lazysegtree.test.cpp
  - test/data_structure/range_query/dynamic_segtree.test.cpp
  - test/data_structure/range_query/dualsegtree.test.cpp
  - test/data_structure/range_query/dynamic_lazysegtree.test.cpp
  - test/data_structure/range_query/segtree.test.cpp
  - test/tree/hld.test.cpp
  - test/math/number_theory/discrete_logarithm.test.cpp
documentation_of: src/math/affine.hpp
layout: document
redirect_from:
- /library/src/math/affine.hpp
- /library/src/math/affine.hpp.html
title: src/math/affine.hpp
---
