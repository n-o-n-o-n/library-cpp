---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/dualsegtree.test.cpp
    title: test/data_structure/range_query/dualsegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/dynamic_lazysegtree.test.cpp
    title: test/data_structure/range_query/dynamic_lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/lazysegtree.test.cpp
    title: test/data_structure/range_query/lazysegtree.test.cpp
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
    \ affine(c, d);\n    }\n};\n#line 4 \"src/monoid/range_affine_range_sum.hpp\"\n\
    \ntemplate<typename mint, typename T = int>\nstruct range_affine_range_sum {\n\
    \    struct S {\n        mint x;\n        T l;\n        S(mint _x = 0, T _l =\
    \ 0) : x(_x), l(_l) {}\n        int val() { return x.val(); }\n    };\n    using\
    \ F = affine<mint>;\n    static S op(S a, S b) { return {a.x + b.x, a.l + b.l};\
    \ }\n    static S e() { return {0, 0}; }\n    static F comp(F f, F g) { return\
    \ f(g); }\n    static F id() { return F(); }\n    static S map(F f, S x) {\n \
    \       x.x = f.a * x.x + f.b * x.l;\n        return x;\n    }\n    static S init(T\
    \ l, T r) { return S(0, r - l); }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"../math/affine.hpp\"\
    \n\ntemplate<typename mint, typename T = int>\nstruct range_affine_range_sum {\n\
    \    struct S {\n        mint x;\n        T l;\n        S(mint _x = 0, T _l =\
    \ 0) : x(_x), l(_l) {}\n        int val() { return x.val(); }\n    };\n    using\
    \ F = affine<mint>;\n    static S op(S a, S b) { return {a.x + b.x, a.l + b.l};\
    \ }\n    static S e() { return {0, 0}; }\n    static F comp(F f, F g) { return\
    \ f(g); }\n    static F id() { return F(); }\n    static S map(F f, S x) {\n \
    \       x.x = f.a * x.x + f.b * x.l;\n        return x;\n    }\n    static S init(T\
    \ l, T r) { return S(0, r - l); }\n};"
  dependsOn:
  - src/template.hpp
  - src/math/affine.hpp
  isVerificationFile: false
  path: src/monoid/range_affine_range_sum.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/range_query/lazysegtree.test.cpp
  - test/data_structure/range_query/dualsegtree.test.cpp
  - test/data_structure/range_query/dynamic_lazysegtree.test.cpp
documentation_of: src/monoid/range_affine_range_sum.hpp
layout: document
redirect_from:
- /library/src/monoid/range_affine_range_sum.hpp
- /library/src/monoid/range_affine_range_sum.hpp.html
title: src/monoid/range_affine_range_sum.hpp
---
