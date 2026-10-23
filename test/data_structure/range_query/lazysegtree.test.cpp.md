---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data_structure/range_query/lazysegtree.hpp
    title: Lazysegtree
  - icon: ':question:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/data_structure/range_query/lazysegtree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n\
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
    \ int m() { return MOD; }\n};\n#line 3 \"src/data_structure/range_query/lazysegtree.hpp\"\
    \n#include <vector>\nusing namespace std;\n\ntemplate<typename ActMonoid>\nstruct\
    \ lazysegtree {\n    using M = ActMonoid;\n    using S = typename M::S;\n    using\
    \ F = typename M::F;\n    lazysegtree() : lazysegtree(0) {}\n    lazysegtree(int\
    \ _n) : lazysegtree(vector<S>(_n, M::e())) {}\n    lazysegtree(const vector<S>\
    \ &v) { init(v); }\n    void set(const vector<S> &v) { init(v); }\n    void set(int\
    \ p, const S &x) {\n        assert(0 <= p && p < n);\n        p += sz;\n     \
    \   inner_push(p);\n        d[p] = x;\n        inner_update(p);\n    }\n    void\
    \ apply(int p, const F &f) {\n        assert(0 <= p && p < n);\n        p += sz;\n\
    \        inner_push(p);\n        d[p] = M::map(f, d[p]);\n        inner_update(p);\n\
    \    }\n    void apply(int l, int r, const F &f) {\n        assert(0 <= l && l\
    \ <=r && r <= n);\n        l += sz;\n        r += sz;\n        for (int i = log;\
    \ i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n      \
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n        int l2\
    \ = l, r2 = r;\n        while (l < r) {\n            if (l & 1) all_apply(l++,\
    \ f);\n            if (r & 1) all_apply(--r, f);\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n        l = l2, r = r2;\n        for (int i = 1;\
    \ i <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n  \
    \          if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \    S get(int p) {\n        assert(0 <= p && p < n);\n        p += sz;\n    \
    \    inner_push(p);\n        return d[p];\n    }\n    S prod(int l, int r) {\n\
    \        assert(0 <= l && l <=r && r <= n);\n        l += sz;\n        r += sz;\n\
    \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n        S pl = M::e(), pr = M::e();\n        while (l < r) {\n   \
    \         if (l & 1) pl = M::op(pl, d[l++]);\n            if (r & 1) pr = M::op(d[--r],\
    \ pr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ M::op(pl, pr);\n    }\n    S all_prod() const { return d[1]; }\n    template<typename\
    \ C>\n    int max_right(int l, const C &check) {\n        assert(0 <= l && l <=\
    \ n);\n        assert(check(M::e()));\n        if (l == n) return l;\n       \
    \ l += sz;\n        inner_push(l);\n        S p = M::e();\n        do {\n    \
    \        while (!(l & 1)) l >>= 1;\n            S np = M::op(p, d[l]);\n     \
    \       if (!check(np)) {\n                while (l < sz) {\n                \
    \    push(l);\n                    l <<= 1;\n                    np = M::op(p,\
    \ d[l]);\n                    if (check(np)) {\n                        p = np;\n\
    \                        l++;\n                    }\n                }\n    \
    \            return l - sz;\n            }\n            p = np;\n            l++;\n\
    \        } while ((l & -l) != l);\n        return n;\n    }\n    template<typename\
    \ C>\n    int max_right(const C &check) {\n        return max_right(0, check);\n\
    \    }\n    template<typename C>\n    int min_left(int r, const C &check) {\n\
    \        assert(0 <= r && r <= n);\n        assert(check(M::e()));\n        if\
    \ (r == 0) return 0;\n        r += sz;\n        inner_push(r - 1);\n        S\
    \ p = M::e();\n        do {\n            r--;\n            while (r > 1 && r &\
    \ 1) r >>= 1;\n            S np = M::op(d[r], p);\n            if (!check(np))\
    \ {\n                while (r < sz) {\n                    push(r);\n        \
    \            (r <<= 1)++;\n                    np = M::op(d[r], p);\n        \
    \            if (check(np)) {\n                        p = np;\n             \
    \           r--;\n                    }\n                }\n                return\
    \ r + 1 - sz;\n            }\n            p = np;\n        } while ((r & -r) !=\
    \ r);\n        return 0;\n    }\n    template<typename C>\n    int min_left(const\
    \ C &check) {\n        return min_left(n, check);\n    }\nprivate:\n    int n,\
    \ log, sz;\n    vector<S> d;\n    vector<F> lz;\n    void init(const vector<S>\
    \ &v) {\n        n = v.size();\n        log = 1;\n        while ((1 << log) <\
    \ n) log++;\n        sz = 1 << log;\n        d = vector<S>(2 * sz, M::e());\n\
    \        lz = vector<F>(sz, M::id());\n        for (int i = 0; i < n; i++) d[i\
    \ + sz] = v[i];\n        for (int i = sz - 1; i >= 1; i--) update(i);\n    }\n\
    \    void update(int p) {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n   \
    \ }\n    void all_apply(int p, const F &f) {\n        d[p] = M::map(f, d[p]);\n\
    \        if (p < sz) lz[p] = M::comp(f, lz[p]);\n    }\n    void push(int p) {\n\
    \        all_apply(2 * p, lz[p]);\n        all_apply(2 * p + 1, lz[p]);\n    \
    \    lz[p] = M::id();\n    }\n    void inner_update(int p) {\n        for (int\
    \ i = 1; i <= log; i++) update(p >> i);\n    }\n    void inner_push(int p) {\n\
    \        for (int i = log; i >= 1; i--) push(p >> i);\n    }\n};\n#line 2 \"src/monoid/range_affine_range_sum.hpp\"\
    \n#include <utility>\n#line 2 \"src/math/affine.hpp\"\n\ntemplate<typename mint>\n\
    struct affine {\n    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const\
    \ mint &_a, const mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint\
    \ &x) const {\n        return a * x + b;\n    }\n    affine operator()(const affine\
    \ &f) const {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n    \
    \    return affine(c, d);\n    }\n};\n#line 4 \"src/monoid/range_affine_range_sum.hpp\"\
    \n\nusing namespace std;\n\ntemplate<typename mint, typename T = int>\nstruct\
    \ range_affine_range_sum {\n    struct S {\n        mint x;\n        T l;\n  \
    \      S(mint _x = 0, T _l = 0) : x(_x), l(_l) {}\n        int val() { return\
    \ x.val(); }\n    };\n    static S op(S a, S b) {\n        return {a.x + b.x,\
    \ a.l + b.l};\n    }\n    static S e() {\n        return {0, 0};\n    }\n    using\
    \ F = affine<mint>;\n    static F comp(F f, F g) { return f(g); }\n    static\
    \ F id() { return F(); }\n    static S map(F f, S x) {\n        x.x = f.a * x.x\
    \ + f.b * x.l;\n        return x;\n    }\n    static S init(T l, T r) {\n    \
    \    return S(0, r - l);\n    }\n};\n#line 6 \"test/data_structure/range_query/lazysegtree.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, Q;\n    cin\
    \ >> N >> Q;\n    vector<range_affine_range_sum<mint>::S> init(N);\n    for (int\
    \ i = 0, a; i < N; i++) {\n        cin >> a;\n        init[i] = range_affine_range_sum<mint>::S(a,\
    \ 1);\n    }\n    lazysegtree<range_affine_range_sum<mint>> seg(init);\n    while\
    \ (Q--) {\n        int t, l, r;\n        cin >> t >> l >> r;\n        if (t ==\
    \ 0) {\n            int a, b;\n            cin >> a >> b;\n            seg.apply(l,\
    \ r, affine<mint>(a, b));\n        } else {\n            cout << seg.prod(l, r).val()\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../../src/modint/modint.hpp\"\n#include \"../../../src/data_structure/range_query/lazysegtree.hpp\"\
    \n#include \"../../../src/monoid/range_affine_range_sum.hpp\"\n\nusing mint =\
    \ modint<998244353>;\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<range_affine_range_sum<mint>::S>\
    \ init(N);\n    for (int i = 0, a; i < N; i++) {\n        cin >> a;\n        init[i]\
    \ = range_affine_range_sum<mint>::S(a, 1);\n    }\n    lazysegtree<range_affine_range_sum<mint>>\
    \ seg(init);\n    while (Q--) {\n        int t, l, r;\n        cin >> t >> l >>\
    \ r;\n        if (t == 0) {\n            int a, b;\n            cin >> a >> b;\n\
    \            seg.apply(l, r, affine<mint>(a, b));\n        } else {\n        \
    \    cout << seg.prod(l, r).val() << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/data_structure/range_query/lazysegtree.hpp
  - src/monoid/range_affine_range_sum.hpp
  - src/math/affine.hpp
  isVerificationFile: true
  path: test/data_structure/range_query/lazysegtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_query/lazysegtree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_query/lazysegtree.test.cpp
- /verify/test/data_structure/range_query/lazysegtree.test.cpp.html
title: test/data_structure/range_query/lazysegtree.test.cpp
---
