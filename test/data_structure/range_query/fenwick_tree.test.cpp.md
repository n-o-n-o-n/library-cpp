---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/fenwick_tree.hpp
    title: src/data_structure/range_query/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/data_structure/range_query/fenwick_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line\
    \ 2 \"src/data_structure/range_query/fenwick_tree.hpp\"\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename T>\nstruct fenwick_tree\
    \ {\n    fenwick_tree() = default;\n    fenwick_tree(int _n) : fenwick_tree(vector<T>(_n,\
    \ 0)) {}\n    fenwick_tree(const vector<T> &_v) : n(_v.size()) {\n        d =\
    \ vector<T>(n, 0);\n        v = vector<T>(n, 0);\n        for (int i = 1; i <=\
    \ n; i++) {\n            v[i - 1] = _v[i - 1];\n            d[i - 1] += v[i -\
    \ 1];\n            int j = i + (i & -i);\n            if (j <= n) d[j - 1] +=\
    \ d[i - 1];\n        }\n    }\n    void add(int p, T x) {\n        assert(0 <=\
    \ p && p < n);\n        v[p] += x;\n        for (p++; p <= n; p += p & -p) {\n\
    \            d[p - 1] += x;\n        }\n    }\n    void update(int p, T x) {\n\
    \        assert(0 <= p && p < n);\n        add(p, x - v[p]);\n    }\n    T get(int\
    \ p) const {\n        assert(0 <= p && p < n);\n        return v[p];\n    }\n\
    \    T sum(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        return sum(r) - sum(l);\n    }\n    // max{ r | sum(r) < x }\n    int\
    \ lower_bound(T x) const {\n        int r = 0, p = 1;\n        while ((p << 1)\
    \ <= n) p <<= 1;\n        while (p > 0) {\n            if (r + p <= n && d[r +\
    \ p - 1] < x) {\n                r += p;\n                x -= d[r - 1];\n   \
    \         }\n            p >>= 1;\n        }\n        return r;\n    }\nprivate:\n\
    \    int n;\n    vector<T> d, v;\n    T sum(int p) const {\n        T res = 0;\n\
    \        for (; p > 0; p -= p & -p) {\n            res += d[p - 1];\n        }\n\
    \        return res;\n    }\n};\n#line 4 \"test/data_structure/range_query/fenwick_tree.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<long long>\
    \ A(N);\n    for (auto &e : A) cin >> e;\n    fenwick_tree<long long> fw(A);\n\
    \    while (Q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n\
    \            int p, x;\n            cin >> p >> x;\n            fw.add(p, x);\n\
    \        } else {\n            int l, r;\n            cin >> l >> r;\n       \
    \     cout << fw.sum(l, r) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../../src/data_structure/range_query/fenwick_tree.hpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<long long> A(N);\n    for (auto\
    \ &e : A) cin >> e;\n    fenwick_tree<long long> fw(A);\n    while (Q--) {\n \
    \       int t;\n        cin >> t;\n        if (t == 0) {\n            int p, x;\n\
    \            cin >> p >> x;\n            fw.add(p, x);\n        } else {\n   \
    \         int l, r;\n            cin >> l >> r;\n            cout << fw.sum(l,\
    \ r) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/data_structure/range_query/fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/range_query/fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_query/fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_query/fenwick_tree.test.cpp
- /verify/test/data_structure/range_query/fenwick_tree.test.cpp.html
title: test/data_structure/range_query/fenwick_tree.test.cpp
---
