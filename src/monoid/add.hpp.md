---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/persistent_ds/persistent_segtree.test.cpp
    title: test/data_structure/persistent_ds/persistent_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/disjoint_sparse_table.test.cpp
    title: test/data_structure/range_query/disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
    title: test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/rectangle_query/rectangle_sum.test.cpp
    title: test/data_structure/rectangle_query/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/weighted_union_find.test.cpp
    title: test/data_structure/union_find/weighted_union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/range_contour_aggregator.test.cpp
    title: test/tree/range_contour_aggregator.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/monoid/add.hpp\"\n\ntemplate<typename T>\nstruct add_monoid\
    \ {\n    using S = T;\n    static S op(S a, S b) { return a + b; }\n    static\
    \ S e() { return 0; }\n    static S inv(S x) { return -x; }\n};\n"
  code: "#pragma once\n\ntemplate<typename T>\nstruct add_monoid {\n    using S =\
    \ T;\n    static S op(S a, S b) { return a + b; }\n    static S e() { return 0;\
    \ }\n    static S inv(S x) { return -x; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/add.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/range_contour_aggregator.test.cpp
  - test/data_structure/union_find/weighted_union_find.test.cpp
  - test/data_structure/range_query/disjoint_sparse_table.test.cpp
  - test/data_structure/persistent_ds/persistent_segtree.test.cpp
  - test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
  - test/data_structure/rectangle_query/rectangle_sum.test.cpp
documentation_of: src/monoid/add.hpp
layout: document
redirect_from:
- /library/src/monoid/add.hpp
- /library/src/monoid/add.hpp.html
title: src/monoid/add.hpp
---
