---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/dualsegtree.hpp
    title: Dualsegtree
  - icon: ':heavy_check_mark:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/monoid/range_affine_range_sum.hpp
    title: src/monoid/range_affine_range_sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"test/data_structure/range_query/dualsegtree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\n\
    #line 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n#include <cassert>\n\
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
    \ int m() { return MOD; }\n};\n#line 3 \"src/data_structure/range_query/dualsegtree.hpp\"\
    \n#include <vector>\nusing namespace std;\n\ntemplate<typename ActSet>\nstruct\
    \ dualsegtree {\n    using M = ActSet;\n    using S = typename M::S;\n    using\
    \ F = typename M::F;\n    dualsegtree() : dualsegtree(0) {}\n    dualsegtree(int\
    \ _n) : dualsegtree(vector<S>(_n, M::e())) {}\n    dualsegtree(const vector<S>\
    \ &v) { init(v); }\n    void init(const vector<S> &v) {\n        n = v.size();\n\
    \        log = 0;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n\
    \        d = vector<S>(sz, M::e());\n        for (int i = 0; i < n; i++) d[i]\
    \ = v[i];\n        lz = vector<F>(sz, M::id());\n    }\n    void set(int p, const\
    \ S &x) {\n        assert(0 <= p && p < n);\n        inner_push(p + sz);\n   \
    \     d[p] = x;\n    }\n    void apply(int p, const F &f) {\n        assert(0\
    \ <= p && p < n);\n        p += sz;\n        inner_push(p);\n        all_apply(p,\
    \ f);\n    }\n    void apply(int l, int r, const F &f) {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        if (l == r) return;\n        l += sz, r +=\
    \ sz;\n        inner_push(l);\n        inner_push(r - 1);\n        while (l <\
    \ r) {\n            if (l & 1) all_apply(l++, f);\n            if (r & 1) all_apply(--r,\
    \ f);\n            l >>= 1;\n            r >>= 1;\n        }\n    }\n    S get(int\
    \ p) {\n        assert(0 <= p && p < n);\n        inner_push(p + sz);\n      \
    \  return d[p];\n    }\nprivate:\n    int n, log, sz;\n    vector<S> d;\n    vector<F>\
    \ lz;\n    void all_apply(int p, const F &f) {\n        if (p < sz) {\n      \
    \      lz[p] = M::comp(f, lz[p]);\n        } else {\n            d[p - sz] = M::map(f,\
    \ d[p - sz]);\n        }\n    }\n    void push(int p) {\n        all_apply(2 *\
    \ p, lz[p]);\n        all_apply(2 * p + 1, lz[p]);\n        lz[p] = M::id();\n\
    \    }\n    void inner_push(int p) {\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n    }\n};\n#line 2 \"src/monoid/range_affine_range_sum.hpp\"\n#include\
    \ <utility>\n#line 2 \"src/math/affine.hpp\"\n\ntemplate<typename mint>\nstruct\
    \ affine {\n    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const mint\
    \ &_a, const mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint &x) const\
    \ {\n        return a * x + b;\n    }\n    affine operator()(const affine &f)\
    \ const {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n        return\
    \ affine(c, d);\n    }\n};\n#line 4 \"src/monoid/range_affine_range_sum.hpp\"\n\
    \nusing namespace std;\n\ntemplate<typename mint, typename T = int>\nstruct range_affine_range_sum\
    \ {\n    struct S {\n        mint x;\n        T l;\n        S(mint _x = 0, T _l\
    \ = 0) : x(_x), l(_l) {}\n        int val() { return x.val(); }\n    };\n    static\
    \ S op(S a, S b) {\n        return {a.x + b.x, a.l + b.l};\n    }\n    static\
    \ S e() {\n        return {0, 0};\n    }\n    using F = affine<mint>;\n    static\
    \ F comp(F f, F g) { return f(g); }\n    static F id() { return F(); }\n    static\
    \ S map(F f, S x) {\n        x.x = f.a * x.x + f.b * x.l;\n        return x;\n\
    \    }\n    static S init(T l, T r) {\n        return S(0, r - l);\n    }\n};\n\
    #line 6 \"test/data_structure/range_query/dualsegtree.test.cpp\"\n\nusing mint\
    \ = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<range_affine_range_sum<mint>::S>\
    \ init(N);\n    for (int i = 0, a; i < N; i++) {\n        cin >> a;\n        init[i]\
    \ = range_affine_range_sum<mint>::S(a, 1);\n    }\n    dualsegtree<range_affine_range_sum<mint>>\
    \ seg(init);\n    while (Q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int l, r, a, b;\n            cin >> l >> r >> a >> b;\n\
    \            seg.apply(l, r, affine<mint>(a, b));\n        } else {\n        \
    \    int p;\n            cin >> p;\n            cout << seg.get(p).val() << '\\\
    n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include \"../../../src/modint/modint.hpp\"\n#include \"../../../src/data_structure/range_query/dualsegtree.hpp\"\
    \n#include \"../../../src/monoid/range_affine_range_sum.hpp\"\n\nusing mint =\
    \ modint<998244353>;\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<range_affine_range_sum<mint>::S>\
    \ init(N);\n    for (int i = 0, a; i < N; i++) {\n        cin >> a;\n        init[i]\
    \ = range_affine_range_sum<mint>::S(a, 1);\n    }\n    dualsegtree<range_affine_range_sum<mint>>\
    \ seg(init);\n    while (Q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int l, r, a, b;\n            cin >> l >> r >> a >> b;\n\
    \            seg.apply(l, r, affine<mint>(a, b));\n        } else {\n        \
    \    int p;\n            cin >> p;\n            cout << seg.get(p).val() << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/data_structure/range_query/dualsegtree.hpp
  - src/monoid/range_affine_range_sum.hpp
  - src/math/affine.hpp
  isVerificationFile: true
  path: test/data_structure/range_query/dualsegtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_query/dualsegtree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_query/dualsegtree.test.cpp
- /verify/test/data_structure/range_query/dualsegtree.test.cpp.html
title: test/data_structure/range_query/dualsegtree.test.cpp
---
