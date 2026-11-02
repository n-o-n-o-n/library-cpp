---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/hld.test.cpp
    title: test/tree/hld.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/data_structure/range_query/directed_range_query.hpp\"\n\ntemplate<typename\
    \ SegTree>\nstruct directed_range_query {\n    using M = typename SegTree::M;\n\
    \    using S = typename M::S;\n    directed_range_query() = default;\n    directed_range_query(int\
    \ _n) : n(_n), seg(_n), ges(_n) {}\n    directed_range_query(const vector<S> &v)\
    \ : n(v.size()), seg(v), ges(vector<S>(v.rbegin(), v.rend())) {}\n    void set(int\
    \ p, const S &x) {\n        assert(0 <= p && p < n);\n        seg.set(p, x);\n\
    \        ges.set(n - 1 - p, x);\n    }\n    template<typename F>\n    void apply(int\
    \ l, int r, const F &f) {\n        assert(0 <= l && l <= r && r <= n);\n     \
    \   seg.apply(l, r, f);\n        ges.apply(n - r, n - l, f);\n    }\n    S get(int\
    \ p) {\n        assert(0 <= p && p < n);\n        return seg.get(p);\n    }\n\
    \    S prod(int l, int r) {\n        return l < r ? seg.prod(l, r) : ges.prod(n\
    \ - l, n - r);\n    }\n    template<typename C>\n    int max_right(int l, bool\
    \ rev, const C &check) {\n        return rev ? n - ges.min_left(n - l, check)\
    \ : seg.max_right(l, check);\n    }\n    template<typename C>\n    int min_left(int\
    \ r, bool rev, const C &check) {\n        return rev ? n - ges.max_right(n - r,\
    \ check) : seg.min_left(r, check);\n    }\nprivate:\n    int n;\n    SegTree seg,\
    \ ges;\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\ntemplate<typename SegTree>\n\
    struct directed_range_query {\n    using M = typename SegTree::M;\n    using S\
    \ = typename M::S;\n    directed_range_query() = default;\n    directed_range_query(int\
    \ _n) : n(_n), seg(_n), ges(_n) {}\n    directed_range_query(const vector<S> &v)\
    \ : n(v.size()), seg(v), ges(vector<S>(v.rbegin(), v.rend())) {}\n    void set(int\
    \ p, const S &x) {\n        assert(0 <= p && p < n);\n        seg.set(p, x);\n\
    \        ges.set(n - 1 - p, x);\n    }\n    template<typename F>\n    void apply(int\
    \ l, int r, const F &f) {\n        assert(0 <= l && l <= r && r <= n);\n     \
    \   seg.apply(l, r, f);\n        ges.apply(n - r, n - l, f);\n    }\n    S get(int\
    \ p) {\n        assert(0 <= p && p < n);\n        return seg.get(p);\n    }\n\
    \    S prod(int l, int r) {\n        return l < r ? seg.prod(l, r) : ges.prod(n\
    \ - l, n - r);\n    }\n    template<typename C>\n    int max_right(int l, bool\
    \ rev, const C &check) {\n        return rev ? n - ges.min_left(n - l, check)\
    \ : seg.max_right(l, check);\n    }\n    template<typename C>\n    int min_left(int\
    \ r, bool rev, const C &check) {\n        return rev ? n - ges.max_right(n - r,\
    \ check) : seg.min_left(r, check);\n    }\nprivate:\n    int n;\n    SegTree seg,\
    \ ges;\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/data_structure/range_query/directed_range_query.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/hld.test.cpp
documentation_of: src/data_structure/range_query/directed_range_query.hpp
layout: document
title: Directed Range Query
---

両向きの区間積クエリを扱う.