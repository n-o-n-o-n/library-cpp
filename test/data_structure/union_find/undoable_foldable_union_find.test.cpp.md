---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/undoable_foldable_union_find.hpp
    title: Undoable Foldable Union Find
  - icon: ':question:'
    path: src/monoid/sum.hpp
    title: src/monoid/sum.hpp
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/3164
    links:
    - https://yukicoder.me/problems/no/3164
  bundledCode: "#line 1 \"test/data_structure/union_find/undoable_foldable_union_find.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/3164\"\n\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    template<typename T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2;\
    \ }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a\
    \ > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/data_structure/union_find/undoable_foldable_union_find.hpp\"\
    \n\ntemplate<typename Abelian_Monoid>\nstruct undoable_foldable_union_find {\n\
    \    using M = Abelian_Monoid;\n    using S = M::S;\n    undoable_foldable_union_find(int\
    \ n) : p(n, -1), cyc(n), a(n, M::e()), d(n, M::e()) {\n        iota(cyc.begin(),\
    \ cyc.end(), 0);\n    }\n    int leader(int u) const {\n        assert(0 <= u\
    \ && u < ssize(p));\n        return p[u] < 0 ? u : leader(p[u]);\n    }\n    bool\
    \ same(int u, int v) const {\n        assert(0 <= u && u < ssize(p));\n      \
    \  assert(0 <= v && v < ssize(p));\n        return leader(u) == leader(v);\n \
    \   }\n    void merge(int u, int v) {\n        assert(0 <= u && u < ssize(p));\n\
    \        assert(0 <= v && v < ssize(p));\n        u = leader(u);\n        v =\
    \ leader(v);\n        if (p[u] > p[v]) swap(u, v);\n        his_type.push_back(false);\n\
    \        his_merge.emplace_back(u, v, p[u], p[v], cyc[u], cyc[v], d[u]);\n   \
    \     if (u == v) return;\n        p[u] += p[v];\n        d[u] = M::op(d[u], d[v]);\n\
    \        p[v] = u;\n        swap(cyc[u], cyc[v]);\n    }\n    int size(int u)\
    \ const {\n        assert(0 <= u && u < ssize(p));\n        return -p[leader(u)];\n\
    \    }\n    void set(int u, const S &x) {\n        assert(0 <= u && u < ssize(p));\n\
    \        int r = leader(u);\n        his_type.push_back(true);\n        his_set.emplace_back(u,\
    \ r, a[u], d[r]);\n        d[r] = M::op(d[r], M::op(M::inv(a[u]), x));\n     \
    \   a[u] = x;\n    }\n    S prod(int u) const {\n        assert(0 <= u && u <\
    \ ssize(p));\n        return d[leader(u)];\n    }\n    void undo() {\n       \
    \ assert(!his_type.empty());\n        bool is_set = his_type.back();\n       \
    \ his_type.pop_back();\n        if (is_set) {\n            auto [u, r, val, fld]\
    \ = his_set.back();\n            his_set.pop_back();\n            a[u] = val;\n\
    \            d[r] = fld;\n        } else {\n            auto [u, v, pu, pv, cu,\
    \ cv, fld] = his_merge.back();\n            his_merge.pop_back();\n          \
    \  if (u == v) return;\n            p[u] = pu;\n            p[v] = pv;\n     \
    \       cyc[u] = cu;\n            cyc[v] = cv;\n            d[u] = fld;\n    \
    \    }\n    }\n    vector<int> group(int u) const {\n        assert(0 <= u &&\
    \ u < ssize(p));\n        vector<int> res = {u};\n        int v = cyc[u];\n  \
    \      while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() const\
    \ {\n        int n = p.size();\n        vector<vector<int>> tmp(n);\n        for\
    \ (int i = 0; i < n; i++) tmp[leader(i)].push_back(i);\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) if (v.size()) res.push_back(v);\n        return\
    \ res;\n    }\nprivate:\n    vector<int> p, cyc;\n    vector<S> a, d;\n    vector<bool>\
    \ his_type;\n    vector<tuple<int, int, S, S>> his_set;\n    vector<tuple<int,\
    \ int, int, int, int, int, S>> his_merge;\n};\n#line 3 \"src/monoid/sum.hpp\"\n\
    \ntemplate<typename T>\nstruct sum_monoid {\n    using S = T;\n    static S op(S\
    \ a, S b) { return a + b; }\n    static S e() { return 0; }\n    static S inv(S\
    \ x) { return -x; }\n};\n#line 6 \"test/data_structure/union_find/undoable_foldable_union_find.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N;\n    cin >> N;\n    vector<long long> A(N);\n    undoable_foldable_union_find<sum_monoid<long\
    \ long>> uf(N);\n    for (int i = 0; i < N; i++) {\n        cin >> A[i];\n   \
    \     uf.set(i, A[i]);\n        if (i && A[i - 1] && A[i]) uf.merge(i - 1, i);\n\
    \    }\n    int Q;\n    cin >> Q;\n    while (Q--) {\n        int p;\n       \
    \ long long b;\n        cin >> p >> b;\n        p--;\n        uf.set(p, b);\n\
    \        int k = 0;\n        if (A[p] == 0) {\n            if (p && A[p - 1])\
    \ {\n                uf.merge(p - 1, p);\n                k++;\n            }\n\
    \            if (p + 1 < N && A[p + 1]) {\n                uf.merge(p, p + 1);\n\
    \                k++;\n            }\n        }\n        cout << uf.prod(p) <<\
    \ '\\n';\n        while (k--) uf.undo();\n        uf.undo();\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/3164\"\n\n#include \"\
    ../../../src/template.hpp\"\n#include \"../../../src/data_structure/union_find/undoable_foldable_union_find.hpp\"\
    \n#include \"../../../src/monoid/sum.hpp\"\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N;\n    cin >> N;\n    vector<long long> A(N);\n\
    \    undoable_foldable_union_find<sum_monoid<long long>> uf(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> A[i];\n        uf.set(i, A[i]);\n     \
    \   if (i && A[i - 1] && A[i]) uf.merge(i - 1, i);\n    }\n    int Q;\n    cin\
    \ >> Q;\n    while (Q--) {\n        int p;\n        long long b;\n        cin\
    \ >> p >> b;\n        p--;\n        uf.set(p, b);\n        int k = 0;\n      \
    \  if (A[p] == 0) {\n            if (p && A[p - 1]) {\n                uf.merge(p\
    \ - 1, p);\n                k++;\n            }\n            if (p + 1 < N &&\
    \ A[p + 1]) {\n                uf.merge(p, p + 1);\n                k++;\n   \
    \         }\n        }\n        cout << uf.prod(p) << '\\n';\n        while (k--)\
    \ uf.undo();\n        uf.undo();\n    }\n}\n"
  dependsOn:
  - src/template.hpp
  - src/data_structure/union_find/undoable_foldable_union_find.hpp
  - src/monoid/sum.hpp
  isVerificationFile: true
  path: test/data_structure/union_find/undoable_foldable_union_find.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union_find/undoable_foldable_union_find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union_find/undoable_foldable_union_find.test.cpp
- /verify/test/data_structure/union_find/undoable_foldable_union_find.test.cpp.html
title: test/data_structure/union_find/undoable_foldable_union_find.test.cpp
---
