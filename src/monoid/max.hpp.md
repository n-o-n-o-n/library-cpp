---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/weighted_functional_graph.test.cpp
    title: test/graph/weighted_functional_graph.test.cpp
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
    \ }\n#line 3 \"src/monoid/max.hpp\"\n\ntemplate<typename T, T E = (is_signed_v<T>\
    \ ? -inf<T>() : T(0))>\nstruct max_monoid {\n    using S = T;\n    static S op(S\
    \ a, S b) { return max(a, b); }\n    static S e() { return E; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T, T E =\
    \ (is_signed_v<T> ? -inf<T>() : T(0))>\nstruct max_monoid {\n    using S = T;\n\
    \    static S op(S a, S b) { return max(a, b); }\n    static S e() { return E;\
    \ }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/monoid/max.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/weighted_functional_graph.test.cpp
documentation_of: src/monoid/max.hpp
layout: document
redirect_from:
- /library/src/monoid/max.hpp
- /library/src/monoid/max.hpp.html
title: src/monoid/max.hpp
---
