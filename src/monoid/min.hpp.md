---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
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
    path: test/data_structure/union_find/uf_merge_tree.test.cpp
    title: test/data_structure/union_find/uf_merge_tree.test.cpp
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
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/monoid/min.hpp\"\n\ntemplate<typename T, T E = inf<T>()>\n\
    struct min_monoid {\n    using S = T;\n    static S op(S a, S b) { return min(a,\
    \ b); }\n    static S e() { return E; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T, T E =\
    \ inf<T>()>\nstruct min_monoid {\n    using S = T;\n    static S op(S a, S b)\
    \ { return min(a, b); }\n    static S e() { return E; }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/monoid/min.hpp
  requiredBy:
  - src/tree/static_tree.hpp
  - src/data_structure/range_query/static_rmq.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/static_tree.lca.test.cpp
  - test/tree/static_tree.jump.test.cpp
  - test/data_structure/union_find/uf_merge_tree.test.cpp
  - test/data_structure/range_query/sparse_table.test.cpp
documentation_of: src/monoid/min.hpp
layout: document
redirect_from:
- /library/src/monoid/min.hpp
- /library/src/monoid/min.hpp.html
title: src/monoid/min.hpp
---
