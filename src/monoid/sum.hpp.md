---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
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
    path: test/data_structure/union_find/foldable_union_find.test.cpp
    title: test/data_structure/union_find/foldable_union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/offline_dynamic_connectivity.test.cpp
    title: test/data_structure/union_find/offline_dynamic_connectivity.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/undoable_foldable_union_find.test.cpp
    title: test/data_structure/union_find/undoable_foldable_union_find.test.cpp
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
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/monoid/sum.hpp\"\n\ntemplate<typename T>\nstruct sum_monoid\
    \ {\n    using S = T;\n    static S op(S a, S b) { return a + b; }\n    static\
    \ S e() { return 0; }\n    static S inv(S x) { return -x; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T>\nstruct\
    \ sum_monoid {\n    using S = T;\n    static S op(S a, S b) { return a + b; }\n\
    \    static S e() { return 0; }\n    static S inv(S x) { return -x; }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/monoid/sum.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
  - test/data_structure/rectangle_query/rectangle_sum.test.cpp
  - test/data_structure/union_find/offline_dynamic_connectivity.test.cpp
  - test/data_structure/union_find/weighted_union_find.test.cpp
  - test/data_structure/union_find/foldable_union_find.test.cpp
  - test/data_structure/union_find/undoable_foldable_union_find.test.cpp
  - test/data_structure/range_query/disjoint_sparse_table.test.cpp
  - test/data_structure/persistent_ds/persistent_segtree.test.cpp
  - test/tree/range_contour_aggregator.test.cpp
documentation_of: src/monoid/sum.hpp
layout: document
redirect_from:
- /library/src/monoid/sum.hpp
- /library/src/monoid/sum.hpp.html
title: src/monoid/sum.hpp
---
