---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/foldable_union_find.hpp
    title: Foldable Union Find
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
    PROBLEM: https://yukicoder.me/problems/no/3164
    links:
    - https://yukicoder.me/problems/no/3164
  bundledCode: "#line 1 \"test/data_structure/union_find/foldable_union_find.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/3164\"\n\n#line 2 \"src/data_structure/union_find/foldable_union_find.hpp\"\
    \n#include <cassert>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Abelian_Monoid>\nstruct foldable_union_find {\n    using M\
    \ = Abelian_Monoid;\n    using S = M::S;\n    foldable_union_find(int n) : p(n,\
    \ -1), cyc(n), a(n, M::e()), d(n, M::e()) {\n        iota(cyc.begin(), cyc.end(),\
    \ 0);\n    }\n    int leader(int u) {\n        assert(0 <= u && u < ssize(p));\n\
    \        return p[u] < 0 ? u : p[u] = leader(p[u]);\n    }\n    bool same(int\
    \ u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v\
    \ && v < ssize(p));\n        return leader(u) == leader(v);\n    }\n    void merge(int\
    \ u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0 <= v\
    \ && v < ssize(p));\n        u = leader(u);\n        v = leader(v);\n        if\
    \ (u == v) return;\n        if (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n\
    \        d[u] = M::op(d[u], d[v]);\n        p[v] = u;\n        swap(cyc[u], cyc[v]);\n\
    \    }\n    int size(int u) {\n        assert(0 <= u && u < ssize(p));\n     \
    \   return -p[leader(u)];\n    }\n    vector<int> group(int u) {\n        assert(0\
    \ <= u && u < ssize(p));\n        vector<int> res = {u};\n        int v = cyc[u];\n\
    \        while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() {\n \
    \       int n = p.size();\n        vector<vector<int>> tmp(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            tmp[leader(i)].push_back(i);\n        }\n\
    \        vector<vector<int>> res;\n        for (auto v : tmp) {\n            if\
    \ (v.size()) res.push_back(v);\n        }\n        return res;\n    }\n    void\
    \ set(int u, const S &x) {\n        assert(0 <= u && u < ssize(p));\n        S\
    \ diff = M::op(M::inv(a[u]), x);\n        a[u] = x;\n        d[leader(u)] = M::op(d[leader(u)],\
    \ diff);\n    }\n    S prod(int u) {\n        assert(0 <=u && u < ssize(p));\n\
    \        return d[leader(u)];\n    }\nprivate:\n    vector<int> p, cyc;\n    vector<S>\
    \ a, d;\n};\n#line 2 \"src/monoid/sum.hpp\"\n\ntemplate<typename T>\nstruct sum_monoid\
    \ {\n    using S = T;\n    static S op(S a, S b) { return a + b; }\n    static\
    \ S e() { return 0; }\n    static S inv(S x) { return -x; }\n};\n#line 5 \"test/data_structure/union_find/foldable_union_find.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N;\n    cin >> N;\n    vector<long long> A(N);\n\
    \    foldable_union_find<sum_monoid<long long>> uf(N);\n    for (int i = 0; i\
    \ < N; i++) {\n        cin >> A[i];\n        uf.set(i, A[i]);\n        if (i &&\
    \ A[i - 1] && A[i]) uf.merge(i - 1, i);\n    }\n    int Q;\n    cin >> Q;\n  \
    \  while (Q--) {\n        int p;\n        long long b;\n        cin >> p >> b;\n\
    \        p--;\n        uf.set(p, b);\n        long long ans = uf.prod(p);\n  \
    \      if (A[p] == 0) {\n            if (p && A[p - 1]) ans += uf.prod(p - 1);\n\
    \            if (p + 1 < N && A[p + 1]) ans += uf.prod(p + 1);\n        }\n  \
    \      cout << ans << '\\n';\n        uf.set(p, A[p]);\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/3164\"\n\n#include \"\
    ../../../src/data_structure/union_find/foldable_union_find.hpp\"\n#include \"\
    ../../../src/monoid/sum.hpp\"\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N;\n    cin >> N;\n    vector<long long> A(N);\n\
    \    foldable_union_find<sum_monoid<long long>> uf(N);\n    for (int i = 0; i\
    \ < N; i++) {\n        cin >> A[i];\n        uf.set(i, A[i]);\n        if (i &&\
    \ A[i - 1] && A[i]) uf.merge(i - 1, i);\n    }\n    int Q;\n    cin >> Q;\n  \
    \  while (Q--) {\n        int p;\n        long long b;\n        cin >> p >> b;\n\
    \        p--;\n        uf.set(p, b);\n        long long ans = uf.prod(p);\n  \
    \      if (A[p] == 0) {\n            if (p && A[p - 1]) ans += uf.prod(p - 1);\n\
    \            if (p + 1 < N && A[p + 1]) ans += uf.prod(p + 1);\n        }\n  \
    \      cout << ans << '\\n';\n        uf.set(p, A[p]);\n    }\n}\n"
  dependsOn:
  - src/data_structure/union_find/foldable_union_find.hpp
  - src/monoid/sum.hpp
  isVerificationFile: true
  path: test/data_structure/union_find/foldable_union_find.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 19:54:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union_find/foldable_union_find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union_find/foldable_union_find.test.cpp
- /verify/test/data_structure/union_find/foldable_union_find.test.cpp.html
title: test/data_structure/union_find/foldable_union_find.test.cpp
---
