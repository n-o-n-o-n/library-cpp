---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/static_rmq.hpp
    title: src/data_structure/range_query/static_rmq.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/static_tree.hpp
    title: Static Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/sparse_table.test.cpp
    title: test/data_structure/range_query/sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/static_tree.jump.test.cpp
    title: test/tree/static_tree.jump.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/static_tree.lca.test.cpp
    title: test/tree/static_tree.lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/monoid/min.hpp\"\n#include <algorithm>\n#include <limits>\n\
    using namespace std;\n\ntemplate<typename T, T E = numeric_limits<T>::max()>\n\
    struct min_monoid {\n    using S = T;\n    static S op(S a, S b) { return min(a,\
    \ b); }\n    static S e() { return E; }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\nusing namespace std;\n\
    \ntemplate<typename T, T E = numeric_limits<T>::max()>\nstruct min_monoid {\n\
    \    using S = T;\n    static S op(S a, S b) { return min(a, b); }\n    static\
    \ S e() { return E; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/min.hpp
  requiredBy:
  - src/tree/static_tree.hpp
  - src/data_structure/range_query/static_rmq.hpp
  timestamp: '2026-10-29 14:11:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/static_tree.lca.test.cpp
  - test/tree/static_tree.jump.test.cpp
  - test/data_structure/range_query/sparse_table.test.cpp
documentation_of: src/monoid/min.hpp
layout: document
redirect_from:
- /library/src/monoid/min.hpp
- /library/src/monoid/min.hpp.html
title: src/monoid/min.hpp
---
