---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/weighted_functional_graph.test.cpp
    title: test/graph/weighted_functional_graph.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/monoid/max.hpp\"\n#include <algorithm>\n#include <limits>\n\
    using namespace std;\n\ntemplate<typename T, T E = numeric_limits<T>::min()>\n\
    struct max_monoid {\n    using S = T;\n    static S op(S a, S b) { return max(a,\
    \ b); }\n    static S e() { return E; }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\nusing namespace std;\n\
    \ntemplate<typename T, T E = numeric_limits<T>::min()>\nstruct max_monoid {\n\
    \    using S = T;\n    static S op(S a, S b) { return max(a, b); }\n    static\
    \ S e() { return E; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/max.hpp
  requiredBy: []
  timestamp: '2026-10-29 14:11:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/weighted_functional_graph.test.cpp
documentation_of: src/monoid/max.hpp
layout: document
redirect_from:
- /library/src/monoid/max.hpp
- /library/src/monoid/max.hpp.html
title: src/monoid/max.hpp
---
