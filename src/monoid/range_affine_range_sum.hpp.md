---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
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
  bundledCode: "#line 2 \"src/monoid/range_affine_range_sum.hpp\"\n#include <utility>\n\
    #line 2 \"src/math/affine.hpp\"\n\ntemplate<typename mint>\nstruct affine {\n\
    \    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const mint &_a, const\
    \ mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint &x) const {\n  \
    \      return a * x + b;\n    }\n    affine operator()(const affine &f) const\
    \ {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n        return\
    \ affine(c, d);\n    }\n};\n#line 4 \"src/monoid/range_affine_range_sum.hpp\"\n\
    \nusing namespace std;\n\ntemplate<typename mint, typename T = int>\nstruct range_affine_range_sum\
    \ {\n    struct S {\n        mint x;\n        T l;\n        S(mint _x = 0, T _l\
    \ = 0) : x(_x), l(_l) {}\n        int val() { return x.val(); }\n    };\n    static\
    \ S op(S a, S b) {\n        return {a.x + b.x, a.l + b.l};\n    }\n    static\
    \ S e() {\n        return {0, 0};\n    }\n    using F = affine<mint>;\n    static\
    \ F comp(F f, F g) { return f(g); }\n    static F id() { return F(); }\n    static\
    \ S map(F f, S x) {\n        x.x = f.a * x.x + f.b * x.l;\n        return x;\n\
    \    }\n    static S init(T l, T r) {\n        return S(0, r - l);\n    }\n};\n"
  code: "#pragma once\n#include <utility>\n#include \"../math/affine.hpp\"\n\nusing\
    \ namespace std;\n\ntemplate<typename mint, typename T = int>\nstruct range_affine_range_sum\
    \ {\n    struct S {\n        mint x;\n        T l;\n        S(mint _x = 0, T _l\
    \ = 0) : x(_x), l(_l) {}\n        int val() { return x.val(); }\n    };\n    static\
    \ S op(S a, S b) {\n        return {a.x + b.x, a.l + b.l};\n    }\n    static\
    \ S e() {\n        return {0, 0};\n    }\n    using F = affine<mint>;\n    static\
    \ F comp(F f, F g) { return f(g); }\n    static F id() { return F(); }\n    static\
    \ S map(F f, S x) {\n        x.x = f.a * x.x + f.b * x.l;\n        return x;\n\
    \    }\n    static S init(T l, T r) {\n        return S(0, r - l);\n    }\n};"
  dependsOn:
  - src/math/affine.hpp
  isVerificationFile: false
  path: src/monoid/range_affine_range_sum.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
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
