---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/segtree.hpp
    title: Segtree
  - icon: ':heavy_check_mark:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':question:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/data_structure/range_query/segtree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line\
    \ 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n#include <cassert>\nusing\
    \ namespace std;\n\ntemplate<unsigned int MOD>\nstruct modint {\n    constexpr\
    \ modint() : x(0) {}\n    template<typename T>\n    constexpr modint(T v) {\n\
    \        int y = v % (int)mod();\n        if (y < 0) y += mod();\n        x =\
    \ (unsigned int)y;\n    }\n    static constexpr modint raw(int v) {\n        modint\
    \ a;\n        a.x = v;\n        return a;\n    }\n    static constexpr int mod()\
    \ { return MOD; }\n    constexpr unsigned int val() const { return x; }\n    constexpr\
    \ modint& operator++() {\n        x++;\n        if (x == mod()) x = 0;\n     \
    \   return *this;\n    }\n    constexpr modint& operator--() {\n        if (x\
    \ == 0) x = mod();\n        x--;\n        return *this;\n    }\n    constexpr\
    \ modint operator++(int) {\n        modint res = *this;\n        ++*this;\n  \
    \      return res;\n    }\n    constexpr modint operator--(int) {\n        modint\
    \ res = *this;\n        --*this;\n        return res;\n    }\n    constexpr modint&\
    \ operator+=(const modint &r) {\n        x += r.x;\n        if (x >= mod()) x\
    \ -= mod();\n        return *this;\n    }\n    constexpr modint& operator-=(const\
    \ modint &r) {\n        x -= r.x;\n        if (x >= mod()) x += mod();\n     \
    \   return *this;\n    }\n    constexpr modint& operator*=(const modint &r) {\n\
    \        unsigned long long y = x;\n        y *= r.x;\n        x = (unsigned int)(y\
    \ % mod());\n        return *this;\n    }\n    constexpr modint &operator/=(const\
    \ modint &r) {\n        return *this = *this * r.inv();\n    }\n    friend constexpr\
    \ modint operator+(const modint &a, const modint &b) {\n        return modint(a)\
    \ += b;\n    }\n    friend constexpr modint operator-(const modint &a, const modint\
    \ &b) {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
    \ modint &a, const modint &b) {\n        return modint(a) *= b;\n    }\n    friend\
    \ constexpr modint operator/(const modint &a, const modint &b) {\n        return\
    \ modint(a) /= b;\n    }\n    friend constexpr bool operator==(const modint &a,\
    \ const modint &b) {\n        return a.x == b.x;\n    }\n    friend constexpr\
    \ bool operator!=(const modint &a, const modint &b) {\n        return a.x != b.x;\n\
    \    }\n    constexpr modint operator+() const { return *this; }\n    constexpr\
    \ modint operator-() const { return modint() - *this; }\n    constexpr modint\
    \ pow(long long k) const {\n        assert(k >= 0);\n        modint a = *this;\n\
    \        modint res = 1;\n        while (k > 0) {\n            if (k & 1) res\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint inv() const {\n        long long a = x, b\
    \ = mod(), u = 1, v = 0;\n        while (b > 0) {\n            long long t = a\
    \ / b;\n            a -= t * b;\n            swap(a, b);\n            u -= t *\
    \ v;\n            swap(u, v);\n        }\n        return modint(u);\n    }\nprivate:\n\
    \    unsigned int x;\n};\n#line 2 \"src/math/affine.hpp\"\n\ntemplate<typename\
    \ mint>\nstruct affine {\n    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const\
    \ mint &_a, const mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint\
    \ &x) const {\n        return a * x + b;\n    }\n    affine operator()(const affine\
    \ &f) const {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n    \
    \    return affine(c, d);\n    }\n};\n#line 2 \"src/data_structure/range_query/segtree.hpp\"\
    \n#include <vector>\n#line 4 \"src/data_structure/range_query/segtree.hpp\"\n\
    using namespace std;\n\ntemplate <typename Monoid>\nstruct segtree {\n    using\
    \ M = Monoid;\n    using S = typename M::S;\n    segtree() : segtree(0) {}\n \
    \   segtree(int _n) : segtree(vector<S>(_n, M::e())) {}\n    segtree(const vector<S>\
    \ &v) : n(v.size()) {\n        log = 1;\n        while ((1 << log) < n) log++;\n\
    \        sz = 1 << log;\n        d = vector<S>(2 * sz, M::e());\n        for (int\
    \ i = 0; i < n; i++) d[i + sz] = v[i];\n        for (int i = sz - 1; i >= 1; i--)\
    \ update(i);\n    }\n    void set(int p, const S &x) {\n        assert(0 <= p\
    \ && p < n);\n        p += sz;\n        d[p] = x;\n        for (int i = 1; i <=\
    \ log; i++) update(p >> i);\n    }\n    void apply(int p, const S &x) {\n    \
    \    assert(0 <= p && p < n);\n        set(p, M::op(x, d[p + sz]));\n    }\n \
    \   S get(int p) const {\n        assert(0 <= p && p < n);\n        return d[p\
    \ + sz];\n    }\n    S prod(int l, int r) const {\n        assert(0 <= l && l\
    \ <= r && r <= n);\n        l += sz;\n        r += sz;\n        S pl = M::e(),\
    \ pr = M::e();\n        while (l < r) {\n            if (l & 1) pl = M::op(pl,\
    \ d[l++]);\n            if (r & 1) pr = M::op(d[--r], pr);\n            l >>=\
    \ 1;\n            r >>= 1;\n        }\n        return M::op(pl, pr);\n    }\n\
    \    S all_prod() const { return d[1]; }\n    template<typename C>\n    int max_right(int\
    \ l, const C &check) const {\n        assert(0 <= l && l <= n);\n        assert(check(M::e()));\n\
    \        if (l == n) return l;\n        l += sz;\n        S p = M::e();\n    \
    \    do {\n            while (!(l & 1)) l >>= 1;\n            S np = M::op(p,\
    \ d[l]);\n            if (!check(np)) {\n                while (l < sz) {\n  \
    \                  l <<= 1;\n                    np = M::op(p, d[l]);\n      \
    \              if (check(np)) {\n                        p = np;\n           \
    \             l++;\n                    }\n                }\n               \
    \ return l - sz;\n            }\n            p = np;\n            l++;\n     \
    \   } while ((l & -l) != l);\n        return n;\n    }\n    template<typename\
    \ C>\n    int max_right(const C &check) const {\n        return max_right(0, check);\n\
    \    }\n    template<typename C>\n    int min_left(int r, const C &check) const\
    \ {\n        assert(0 <= r && r <= n);\n        assert(check(M::e()));\n     \
    \   if (r == 0) return r;\n        r += sz;\n        S p = M::e();\n        do\
    \ {\n            r--;\n            while (r > 1 && r & 1) r >>= 1;\n         \
    \   S np = M::op(d[r], p);\n            if (!check(np)) {\n                while\
    \ (r < sz) {\n                    (r <<= 1)++;\n                    np = M::op(d[r],\
    \ p);\n                    if (check(np)) {\n                        p = np;\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - sz;\n            }\n            p = np;\n        }\
    \ while ((r & -r) != r);\n        return 0;\n    }\n    template<typename C>\n\
    \    int min_left(const C &check) const {\n        return min_left(n, check);\n\
    \    }\nprivate:\n    int n, log, sz;\n    vector<S> d;\n    void update(int p)\
    \ {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n};\n#line 6 \"test/data_structure/range_query/segtree.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return S(); }\n\
    };\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<Monoid::S>\
    \ init(N);\n    for (int i = 0; i < N; i++) {\n        int a, b;\n        cin\
    \ >> a >> b;\n        init[i] = affine<mint>(a, b);\n    }\n    segtree<Monoid>\
    \ seg(init);\n    while (Q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            int p, a, b;\n            cin >> p >> a >> b;\n    \
    \        seg.set(p, affine<mint>(a, b));\n        } else {\n            int l,\
    \ r, x;\n            cin >> l >> r >> x;\n            auto f = seg.prod(l, r);\n\
    \            cout << f(x).val() << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../../src/modint/modint.hpp\"\n#include \"../../../src/math/affine.hpp\"\
    \n#include \"../../../src/data_structure/range_query/segtree.hpp\"\n\nusing mint\
    \ = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n    static\
    \ S op(S f, S g) { return g(f); }\n    static S e() { return S(); }\n};\n\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<Monoid::S> init(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        int a, b;\n        cin >> a >> b;\n        init[i]\
    \ = affine<mint>(a, b);\n    }\n    segtree<Monoid> seg(init);\n    while (Q--)\
    \ {\n        int t;\n        cin >> t;\n        if (t == 0) {\n            int\
    \ p, a, b;\n            cin >> p >> a >> b;\n            seg.set(p, affine<mint>(a,\
    \ b));\n        } else {\n            int l, r, x;\n            cin >> l >> r\
    \ >> x;\n            auto f = seg.prod(l, r);\n            cout << f(x).val()\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/affine.hpp
  - src/data_structure/range_query/segtree.hpp
  isVerificationFile: true
  path: test/data_structure/range_query/segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:38:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_query/segtree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_query/segtree.test.cpp
- /verify/test/data_structure/range_query/segtree.test.cpp.html
title: test/data_structure/range_query/segtree.test.cpp
---
