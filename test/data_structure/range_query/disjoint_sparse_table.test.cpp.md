---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/disjoint_sparse_table.hpp
    title: src/data_structure/range_query/disjoint_sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: src/monoid/sum.hpp
    title: src/monoid/sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/data_structure/range_query/disjoint_sparse_table.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line\
    \ 2 \"src/data_structure/range_query/disjoint_sparse_table.hpp\"\n#include <bit>\n\
    #include <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct disjoint_sparse_table {\n    using M = Monoid;\n    using S\
    \ = typename M::S;\n    disjoint_sparse_table() = default;\n    disjoint_sparse_table(int\
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
    \    }\n};\n#line 2 \"src/monoid/sum.hpp\"\n\ntemplate<typename T>\nstruct sum_monoid\
    \ {\n    using S = T;\n    static S op(S a, S b) { return a + b; }\n    static\
    \ S e() { return 0; }\n    static S inv(S x) { return -x; }\n};\n#line 5 \"test/data_structure/range_query/disjoint_sparse_table.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<long long>\
    \ A(N);\n    for (auto &e : A) cin >> e;\n    disjoint_sparse_table<sum_monoid<long\
    \ long>> st(A);\n    for (int l, r; Q--; ) {\n        cin >> l >> r;\n       \
    \ cout << st.prod(l, r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../../src/data_structure/range_query/disjoint_sparse_table.hpp\"\
    \n#include \"../../../src/monoid/sum.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<long long> A(N);\n    for (auto &e : A) cin >>\
    \ e;\n    disjoint_sparse_table<sum_monoid<long long>> st(A);\n    for (int l,\
    \ r; Q--; ) {\n        cin >> l >> r;\n        cout << st.prod(l, r) << '\\n';\n\
    \    }\n}"
  dependsOn:
  - src/data_structure/range_query/disjoint_sparse_table.hpp
  - src/monoid/sum.hpp
  isVerificationFile: true
  path: test/data_structure/range_query/disjoint_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 14:11:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_query/disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_query/disjoint_sparse_table.test.cpp
- /verify/test/data_structure/range_query/disjoint_sparse_table.test.cpp.html
title: test/data_structure/range_query/disjoint_sparse_table.test.cpp
---
