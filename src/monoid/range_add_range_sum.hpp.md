---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/monoid/range_add_range_sum.test.cpp
    title: test/monoid/range_add_range_sum.test.cpp
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
    \ }\n#line 3 \"src/monoid/range_add_range_sum.hpp\"\n\ntemplate<typename T1, typename\
    \ T2 = int>\nstruct range_add_range_sum {\n    struct S {\n        T1 x;\n   \
    \     T2 l;\n        S(T1 _x = 0, T2 _l = 0) : x(_x), l(_l) {}\n        T1 val()\
    \ { return x; }\n    };\n    using F = T1;\n    static S op(S a, S b) { return\
    \ S{a.x + b.x, a.l + b.l}; }\n    static S e() { return S{0, 0}; }\n    static\
    \ F comp(F f, F g) { return f + g; }\n    static F id() { return 0; }\n    static\
    \ S map(F f, S x) {\n        x.x += f * x.l;\n        return x;\n    }\n    static\
    \ S init(T2 l, T2 r) { return S{0, r - l}; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T1, typename\
    \ T2 = int>\nstruct range_add_range_sum {\n    struct S {\n        T1 x;\n   \
    \     T2 l;\n        S(T1 _x = 0, T2 _l = 0) : x(_x), l(_l) {}\n        T1 val()\
    \ { return x; }\n    };\n    using F = T1;\n    static S op(S a, S b) { return\
    \ S{a.x + b.x, a.l + b.l}; }\n    static S e() { return S{0, 0}; }\n    static\
    \ F comp(F f, F g) { return f + g; }\n    static F id() { return 0; }\n    static\
    \ S map(F f, S x) {\n        x.x += f * x.l;\n        return x;\n    }\n    static\
    \ S init(T2 l, T2 r) { return S{0, r - l}; }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/monoid/range_add_range_sum.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/monoid/range_add_range_sum.test.cpp
documentation_of: src/monoid/range_add_range_sum.hpp
layout: document
redirect_from:
- /library/src/monoid/range_add_range_sum.hpp
- /library/src/monoid/range_add_range_sum.hpp.html
title: src/monoid/range_add_range_sum.hpp
---
