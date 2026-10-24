---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/weighted_union_find.hpp
    title: Weighted Union Find
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/monoid/add.hpp
    title: src/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind_with_potential
    links:
    - https://judge.yosupo.jp/problem/unionfind_with_potential
  bundledCode: "#line 1 \"test/data_structure/union_find/weighted_union_find.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#line 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate<int MOD>\nstruct modint {\n    constexpr modint()\
    \ : x(0) {}\n    constexpr modint(long long v) {\n        long long y = v % m();\n\
    \        if (y < 0) y += m();\n        x = (unsigned int)(y);\n    }\n    static\
    \ constexpr modint raw(int v) {\n        modint a;\n        a.x = v;\n       \
    \ return a;\n    }\n    static constexpr int mod() { return m(); }\n    constexpr\
    \ unsigned int val() const { return x; }\n    constexpr modint& operator++() {\n\
    \        x++;\n        if (x == m()) x = 0;\n        return *this;\n    }\n  \
    \  constexpr modint& operator--() {\n        if (x == 0) x = m();\n        x--;\n\
    \        return *this;\n    }\n    constexpr modint operator++(int) {\n      \
    \  modint res = *this;\n        ++*this;\n        return res;\n    }\n    constexpr\
    \ modint operator--(int) {\n        modint res = *this;\n        --*this;\n  \
    \      return res;\n    }\n    constexpr modint& operator+=(const modint &r) {\n\
    \        x += r.x;\n        if (x >= m()) x -= m();\n        return *this;\n \
    \   }\n    constexpr modint& operator-=(const modint &r) {\n        x -= r.x;\n\
    \        if (x >= m()) x += m();\n        return *this;\n    }\n    constexpr\
    \ modint& operator*=(const modint &r) {\n        unsigned long long y = x;\n \
    \       y *= r.x;\n        x = (unsigned int)(y % m());\n        return *this;\n\
    \    }\n    constexpr modint &operator/=(const modint &r) {\n        return *this\
    \ = *this * r.inv();\n    }\n    friend constexpr modint operator+(const modint\
    \ &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend constexpr\
    \ modint operator-(const modint &a, const modint &b) {\n        return modint(a)\
    \ -= b;\n    }\n    friend constexpr modint operator*(const modint &a, const modint\
    \ &b) {\n        return modint(a) *= b;\n    }\n    friend constexpr modint operator/(const\
    \ modint &a, const modint &b) {\n        return modint(a) /= b;\n    }\n    friend\
    \ constexpr bool operator==(const modint &a, const modint &b) {\n        return\
    \ a.x == b.x;\n    }\n    friend constexpr bool operator!=(const modint &a, const\
    \ modint &b) {\n        return a.x != b.x;\n    }\n    constexpr modint operator+()\
    \ const { return *this; }\n    constexpr modint operator-() const { return modint()\
    \ - *this; }\n    constexpr modint pow(long long k) const {\n        assert(k\
    \ >= 0);\n        modint a = *this;\n        modint res = 1;\n        while (k\
    \ > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n            k\
    \ >>= 1;\n        }\n        return res;\n    }\n    constexpr modint inv() const\
    \ {\n        long long a = x, b = m(), u = 1, v = 0;\n        while (b > 0) {\n\
    \            long long t = a / b;\n            a -= t * b;\n            swap(a,\
    \ b);\n            u -= t * v;\n            swap(u, v);\n        }\n        return\
    \ modint(u);\n    }\nprivate:\n    unsigned int x;\n    static constexpr unsigned\
    \ int m() { return MOD; }\n};\n#line 3 \"src/data_structure/union_find/weighted_union_find.hpp\"\
    \n#include <numeric>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Abelian_Group>\nstruct weighted_union_find {\n    using S = Abelian_Group::S;\n\
    \    weighted_union_find(int _n) : n(_n), p(n, -1), cyc(n), d(n, Abelian_Group::e())\
    \ {\n        iota(cyc.begin(), cyc.end(), 0);\n    }\n    int leader(int u) {\n\
    \        assert(0 <= u && u < n);\n        if (p[u] < 0) return u;\n        int\
    \ r = leader(p[u]);\n        d[u] = Abelian_Group::op(d[u], d[p[u]]);\n      \
    \  return p[u] = r;\n    }\n    S weight(int u) {\n        assert(0 <= u && u\
    \ < n);\n        leader(u);\n        return d[u];\n    }\n    bool same(int u,\
    \ int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        return leader(u) == leader(v);\n    }\n    bool merge(int u, int v, S\
    \ w) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n \
    \       if (same(u, v)) {\n            return diff(u, v) == w;\n        }\n  \
    \      w = Abelian_Group::op(w, weight(u));\n        w = Abelian_Group::op(w,\
    \ Abelian_Group::inv(weight(v)));\n        u = leader(u);\n        v = leader(v);\n\
    \        assert(u != v);\n        if (p[u] > p[v]) {\n            swap(u, v);\n\
    \            w = Abelian_Group::inv(w);\n        }\n        p[u] += p[v];\n  \
    \      p[v] = u;\n        d[v] = w;\n        swap(cyc[u], cyc[v]);\n        return\
    \ true;\n    }\n    S diff(int u, int v) {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        return Abelian_Group::op(Abelian_Group::inv(weight(u)),\
    \ weight(v));\n    }\n    int size(int u) {\n        assert(0 <= u && u < n);\n\
    \        return -p[leader(u)];\n    }\n    vector<int> group(int u) {\n      \
    \  assert(0 <= u && u < n);\n        vector<int> res = {u};\n        int v = cyc[u];\n\
    \        while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() {\n \
    \       vector<vector<int>> tmp(n);\n        for (int i = 0; i < n; i++) {\n \
    \           tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n\
    \        }\n        return res;\n    }\nprivate:\n    int n;\n    vector<int>\
    \ p, cyc;\n    vector<S> d;\n};\n#line 2 \"src/monoid/add.hpp\"\n\ntemplate<typename\
    \ T>\nstruct add_monoid {\n    using S = T;\n    static S op(S a, S b) { return\
    \ a + b; }\n    static S e() { return 0; }\n    static S inv(S x) { return -x;\
    \ }\n};\n#line 6 \"test/data_structure/union_find/weighted_union_find.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, Q;\n    cin\
    \ >> N >> Q;\n    weighted_union_find<add_monoid<mint>> wuf(N);\n    while (Q--)\
    \ {\n        int t, u, v;\n        cin >> t >> u >> v;\n        if (t == 0) {\n\
    \            int x;\n            cin >> x;\n            cout << wuf.merge(v, u,\
    \ x) << '\\n';\n        } else {\n            if (wuf.same(u, v)) {\n        \
    \        cout << wuf.diff(v, u).val() << '\\n';\n            } else {\n      \
    \          cout << -1 << '\\n';\n            }\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind_with_potential\"\
    \n\n#include \"../../../src/modint/modint.hpp\"\n#include \"../../../src/data_structure/union_find/weighted_union_find.hpp\"\
    \n#include \"../../../src/monoid/add.hpp\"\n\nusing mint = modint<998244353>;\n\
    \n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    weighted_union_find<add_monoid<mint>>\
    \ wuf(N);\n    while (Q--) {\n        int t, u, v;\n        cin >> t >> u >> v;\n\
    \        if (t == 0) {\n            int x;\n            cin >> x;\n          \
    \  cout << wuf.merge(v, u, x) << '\\n';\n        } else {\n            if (wuf.same(u,\
    \ v)) {\n                cout << wuf.diff(v, u).val() << '\\n';\n            }\
    \ else {\n                cout << -1 << '\\n';\n            }\n        }\n   \
    \ }\n}\n"
  dependsOn:
  - src/modint/modint.hpp
  - src/data_structure/union_find/weighted_union_find.hpp
  - src/monoid/add.hpp
  isVerificationFile: true
  path: test/data_structure/union_find/weighted_union_find.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 16:40:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union_find/weighted_union_find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union_find/weighted_union_find.test.cpp
- /verify/test/data_structure/union_find/weighted_union_find.test.cpp.html
title: test/data_structure/union_find/weighted_union_find.test.cpp
---
