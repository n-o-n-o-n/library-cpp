---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data_structure/range_query/sparse_table.hpp
    title: src/data_structure/range_query/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: src/monoid/min.hpp
    title: src/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/data_structure/range_query/sparse_table.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 2 \"src/data_structure/range_query/sparse_table.hpp\"\
    \n#include <bit>\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct sparse_table {\n    using M = Monoid;\n  \
    \  using S = typename M::S;\n    sparse_table() = default;\n    sparse_table(const\
    \ vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }\n    S prod(int l, int\
    \ r) const {\n        assert(0 <= l && l <= r && r <=n);\n        if (l == r)\
    \ return M::e();\n        int i = bit_width(unsigned(r - l)) - 1;\n        return\
    \ M::op(d[i][l], d[i][r - (1 << i)]);\n    }\nprivate:\n    int n, b, e;\n   \
    \ vector<vector<S>> d;\n    void build() {\n        b = bit_width(unsigned(n));\n\
    \        d.resize(b, vector<S>(n, M::e()));\n        for (int i = 1; i < b; i++)\
    \ {\n            for (int j = 0; j + (1 << i) <=n; j++) {\n                d[i][j]\
    \ = M::op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);\n            }\n       \
    \ }\n    }\n};\n#line 2 \"src/monoid/min.hpp\"\n#include <numeric>\nusing namespace\
    \ std;\n\ntemplate<typename T, T E = numeric_limits<T>::max()>\nstruct min_monoid\
    \ {\n    using S = T;\n    static S op(S a, S b) { return min(a, b); }\n    static\
    \ S e() { return E; }\n};\n#line 5 \"test/data_structure/range_query/sparse_table.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n\
    \    for (auto &e : A) cin >> e;\n    sparse_table<min_monoid<int>> st(A);\n \
    \   for (int l, r; Q--; ) {\n        cin >> l >> r;\n        cout << st.prod(l,\
    \ r) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../../src/data_structure/range_query/sparse_table.hpp\"\n#include \"../../../src/monoid/min.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n\
    \    for (auto &e : A) cin >> e;\n    sparse_table<min_monoid<int>> st(A);\n \
    \   for (int l, r; Q--; ) {\n        cin >> l >> r;\n        cout << st.prod(l,\
    \ r) << '\\n';\n    }\n}"
  dependsOn:
  - src/data_structure/range_query/sparse_table.hpp
  - src/monoid/min.hpp
  isVerificationFile: true
  path: test/data_structure/range_query/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_query/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_query/sparse_table.test.cpp
- /verify/test/data_structure/range_query/sparse_table.test.cpp.html
title: test/data_structure/range_query/sparse_table.test.cpp
---
