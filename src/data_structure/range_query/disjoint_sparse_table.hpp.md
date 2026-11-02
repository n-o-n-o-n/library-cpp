---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/disjoint_sparse_table.test.cpp
    title: test/data_structure/range_query/disjoint_sparse_table.test.cpp
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
    \ }\n#line 3 \"src/data_structure/range_query/disjoint_sparse_table.hpp\"\n\n\
    template<typename Monoid>\nstruct disjoint_sparse_table {\n    using M = Monoid;\n\
    \    using S = typename M::S;\n    disjoint_sparse_table() = default;\n    disjoint_sparse_table(int\
    \ _n) : n(_n), b(0), d(1, vector<S>(_n, M::e())) {}\n    disjoint_sparse_table(const\
    \ vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }\n    void set(int p,\
    \ S x) {\n        assert(0 <= p && p < n);\n        assert(b == 0);\n        d[0][p]\
    \ = x;\n    }\n    S get(int p) {\n        assert(0 <= p && p < n);\n        return\
    \ d[0][p];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r\
    \ && r <=n);\n        build();\n        if (l == r) return M::e();\n        if\
    \ (l + 1 == r) return d[0][l];\n        int i = bit_width(unsigned(l ^ (r - 1)));\n\
    \        return M::op(d[i][l], d[i][r - 1]);\n    }\nprivate:\n    int n, b;\n\
    \    vector<vector<S>> d;\n    void build() {\n        if (b > 0) return;\n  \
    \      b = bit_width((unsigned)n);\n        d.resize(b + 1, vector<S>(n, M::e()));\n\
    \        for (int i = 1; i <= b; i++) {\n            int len = 1 << i;\n     \
    \       int l = len >> 1;\n            for (int k = 0; l < n; k += len, l += len)\
    \ {\n                d[i][l - 1] = d[0][l - 1];\n                for (int j =\
    \ l - 2; j >= k; j--) {\n                    d[i][j] = M::op(d[0][j], d[i][j +\
    \ 1]);\n                }\n                d[i][l] = d[0][l];\n              \
    \  for (int j = l + 1; j < n && j < k + len; j++) {\n                    d[i][j]\
    \ = M::op(d[i][j - 1], d[0][j]);\n                }\n            }\n        }\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\ntemplate<typename Monoid>\n\
    struct disjoint_sparse_table {\n    using M = Monoid;\n    using S = typename\
    \ M::S;\n    disjoint_sparse_table() = default;\n    disjoint_sparse_table(int\
    \ _n) : n(_n), b(0), d(1, vector<S>(_n, M::e())) {}\n    disjoint_sparse_table(const\
    \ vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }\n    void set(int p,\
    \ S x) {\n        assert(0 <= p && p < n);\n        assert(b == 0);\n        d[0][p]\
    \ = x;\n    }\n    S get(int p) {\n        assert(0 <= p && p < n);\n        return\
    \ d[0][p];\n    }\n    S prod(int l, int r) {\n        assert(0 <= l && l <= r\
    \ && r <=n);\n        build();\n        if (l == r) return M::e();\n        if\
    \ (l + 1 == r) return d[0][l];\n        int i = bit_width(unsigned(l ^ (r - 1)));\n\
    \        return M::op(d[i][l], d[i][r - 1]);\n    }\nprivate:\n    int n, b;\n\
    \    vector<vector<S>> d;\n    void build() {\n        if (b > 0) return;\n  \
    \      b = bit_width((unsigned)n);\n        d.resize(b + 1, vector<S>(n, M::e()));\n\
    \        for (int i = 1; i <= b; i++) {\n            int len = 1 << i;\n     \
    \       int l = len >> 1;\n            for (int k = 0; l < n; k += len, l += len)\
    \ {\n                d[i][l - 1] = d[0][l - 1];\n                for (int j =\
    \ l - 2; j >= k; j--) {\n                    d[i][j] = M::op(d[0][j], d[i][j +\
    \ 1]);\n                }\n                d[i][l] = d[0][l];\n              \
    \  for (int j = l + 1; j < n && j < k + len; j++) {\n                    d[i][j]\
    \ = M::op(d[i][j - 1], d[0][j]);\n                }\n            }\n        }\n\
    \    }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/data_structure/range_query/disjoint_sparse_table.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/range_query/disjoint_sparse_table.test.cpp
documentation_of: src/data_structure/range_query/disjoint_sparse_table.hpp
layout: document
redirect_from:
- /library/src/data_structure/range_query/disjoint_sparse_table.hpp
- /library/src/data_structure/range_query/disjoint_sparse_table.hpp.html
title: src/data_structure/range_query/disjoint_sparse_table.hpp
---
