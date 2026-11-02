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
    \ }\n#line 3 \"src/data_structure/range_query/sparse_table.hpp\"\n\ntemplate<typename\
    \ Monoid>\nstruct sparse_table {\n    using M = Monoid;\n    using S = typename\
    \ M::S;\n    sparse_table() = default;\n    sparse_table(const vector<S> &v) :\
    \ n(v.size()), b(0), d(1, v) { build(); }\n    S prod(int l, int r) const {\n\
    \        assert(0 <= l && l <= r && r <=n);\n        if (l == r) return M::e();\n\
    \        int i = bit_width(unsigned(r - l)) - 1;\n        return M::op(d[i][l],\
    \ d[i][r - (1 << i)]);\n    }\nprivate:\n    int n, b, e;\n    vector<vector<S>>\
    \ d;\n    void build() {\n        b = bit_width(unsigned(n));\n        d.resize(b);\n\
    \        for (int i = 1; i < b; i++) {\n            int width = 1 << i;\n    \
    \        d[i].assign(n - width + 1, M::e());\n            for (int j = 0; j +\
    \ width <= n; j++) {\n                d[i][j] = M::op(d[i - 1][j], d[i - 1][j\
    \ + (width >> 1)]);\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\ntemplate<typename Monoid>\n\
    struct sparse_table {\n    using M = Monoid;\n    using S = typename M::S;\n \
    \   sparse_table() = default;\n    sparse_table(const vector<S> &v) : n(v.size()),\
    \ b(0), d(1, v) { build(); }\n    S prod(int l, int r) const {\n        assert(0\
    \ <= l && l <= r && r <=n);\n        if (l == r) return M::e();\n        int i\
    \ = bit_width(unsigned(r - l)) - 1;\n        return M::op(d[i][l], d[i][r - (1\
    \ << i)]);\n    }\nprivate:\n    int n, b, e;\n    vector<vector<S>> d;\n    void\
    \ build() {\n        b = bit_width(unsigned(n));\n        d.resize(b);\n     \
    \   for (int i = 1; i < b; i++) {\n            int width = 1 << i;\n         \
    \   d[i].assign(n - width + 1, M::e());\n            for (int j = 0; j + width\
    \ <= n; j++) {\n                d[i][j] = M::op(d[i - 1][j], d[i - 1][j + (width\
    \ >> 1)]);\n            }\n        }\n    }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/data_structure/range_query/sparse_table.hpp
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
documentation_of: src/data_structure/range_query/sparse_table.hpp
layout: document
redirect_from:
- /library/src/data_structure/range_query/sparse_table.hpp
- /library/src/data_structure/range_query/sparse_table.hpp.html
title: src/data_structure/range_query/sparse_table.hpp
---
