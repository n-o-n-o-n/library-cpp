---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/monoid/range_add_range_min.test.cpp
    title: test/monoid/range_add_range_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/monoid/range_add_range_min.hpp\"\n#include <algorithm>\n\
    #include <limits>\nusing namespace std;\n\ntemplate<typename T, T E = numeric_limits<T>::max()>\n\
    struct range_add_range_min {\n    using S = T;\n    using F = T;\n    static S\
    \ op(S a, S b) { return min(a, b); }\n    static S e() { return E; }\n    static\
    \ F comp(F f, F g) { return f + g; }\n    static F id() { return 0; }\n    static\
    \ S map(F f, S x) { return x == E ? x : f + x; }\n    template<typename T2>\n\
    \    static S init(T2, T2) { return E; }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\nusing namespace std;\n\
    \ntemplate<typename T, T E = numeric_limits<T>::max()>\nstruct range_add_range_min\
    \ {\n    using S = T;\n    using F = T;\n    static S op(S a, S b) { return min(a,\
    \ b); }\n    static S e() { return E; }\n    static F comp(F f, F g) { return\
    \ f + g; }\n    static F id() { return 0; }\n    static S map(F f, S x) { return\
    \ x == E ? x : f + x; }\n    template<typename T2>\n    static S init(T2, T2)\
    \ { return E; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/range_add_range_min.hpp
  requiredBy: []
  timestamp: '2026-10-29 14:11:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/monoid/range_add_range_min.test.cpp
documentation_of: src/monoid/range_add_range_min.hpp
layout: document
redirect_from:
- /library/src/monoid/range_add_range_min.hpp
- /library/src/monoid/range_add_range_min.hpp.html
title: src/monoid/range_add_range_min.hpp
---
