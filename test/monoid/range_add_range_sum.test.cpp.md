---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/lazysegtree.hpp
    title: Lazysegtree
  - icon: ':heavy_check_mark:'
    path: src/monoid/range_add_range_sum.hpp
    title: src/monoid/range_add_range_sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "#line 1 \"test/monoid/range_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\n\n#line\
    \ 2 \"src/data_structure/range_query/lazysegtree.hpp\"\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename ActMonoid>\nstruct lazysegtree\
    \ {\n    using M = ActMonoid;\n    using S = typename M::S;\n    using F = typename\
    \ M::F;\n    lazysegtree() : lazysegtree(0) {}\n    lazysegtree(int _n) : lazysegtree(vector<S>(_n,\
    \ M::e())) {}\n    lazysegtree(const vector<S> &v) { init(v); }\n    void set(const\
    \ vector<S> &v) { init(v); }\n    void set(int p, const S &x) {\n        assert(0\
    \ <= p && p < n);\n        p += sz;\n        inner_push(p);\n        d[p] = x;\n\
    \        inner_update(p);\n    }\n    void apply(int p, const F &f) {\n      \
    \  assert(0 <= p && p < n);\n        p += sz;\n        inner_push(p);\n      \
    \  d[p] = M::map(f, d[p]);\n        inner_update(p);\n    }\n    void apply(int\
    \ l, int r, const F &f) {\n        assert(0 <= l && l <=r && r <= n);\n      \
    \  l += sz;\n        r += sz;\n        for (int i = log; i >= 1; i--) {\n    \
    \        if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) <<\
    \ i) != r) push((r - 1) >> i);\n        }\n        int l2 = l, r2 = r;\n     \
    \   while (l < r) {\n            if (l & 1) all_apply(l++, f);\n            if\
    \ (r & 1) all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n   \
    \     }\n        l = l2, r = r2;\n        for (int i = 1; i <= log; i++) {\n \
    \           if (((l >> i) << i) != l) update(l >> i);\n            if (((r >>\
    \ i) << i) != r) update((r - 1) >> i);\n        }\n    }\n    S get(int p) {\n\
    \        assert(0 <= p && p < n);\n        p += sz;\n        inner_push(p);\n\
    \        return d[p];\n    }\n    S prod(int l, int r) {\n        assert(0 <=\
    \ l && l <=r && r <= n);\n        l += sz;\n        r += sz;\n        for (int\
    \ i = log; i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n\
    \            if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n      \
    \  S pl = M::e(), pr = M::e();\n        while (l < r) {\n            if (l & 1)\
    \ pl = M::op(pl, d[l++]);\n            if (r & 1) pr = M::op(d[--r], pr);\n  \
    \          l >>= 1;\n            r >>= 1;\n        }\n        return M::op(pl,\
    \ pr);\n    }\n    S all_prod() const { return d[1]; }\n    template<typename\
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
    \        for (int i = log; i >= 1; i--) push(p >> i);\n    }\n};\n#line 2 \"src/monoid/range_add_range_sum.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T1, typename T2 = int>\nstruct range_add_range_sum\
    \ {\n    struct S {\n        T1 x;\n        T2 l;\n        S(T1 _x = 0, T2 _l\
    \ = 0) : x(_x), l(_l) {}\n        T1 val() { return x; }\n    };\n    using F\
    \ = T1;\n    static S op(S a, S b) { return S{a.x + b.x, a.l + b.l}; }\n    static\
    \ S e() { return S{0, 0}; }\n    static F comp(F f, F g) { return f + g; }\n \
    \   static F id() { return 0; }\n    static S map(F f, S x) {\n        x.x +=\
    \ f * x.l;\n        return x;\n    }\n    static S init(T2 l, T2 r) { return S{0,\
    \ r - l}; }\n};\n#line 5 \"test/monoid/range_add_range_sum.test.cpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    lazysegtree<range_add_range_sum<long long>>\
    \ seg(vector(N, range_add_range_sum<long long>::init(0, 1)));\n    while (Q--)\
    \ {\n        int t, l, r;\n        cin >> t >> l >> r;\n        l--;\n       \
    \ if (t == 0) {\n            int x;\n            cin >> x;\n            seg.apply(l,\
    \ r, x);\n        } else {\n            cout << seg.prod(l, r).val() << '\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include \"../../src/data_structure/range_query/lazysegtree.hpp\"\n#include\
    \ \"../../src/monoid/range_add_range_sum.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, Q;\n\
    \    cin >> N >> Q;\n    lazysegtree<range_add_range_sum<long long>> seg(vector(N,\
    \ range_add_range_sum<long long>::init(0, 1)));\n    while (Q--) {\n        int\
    \ t, l, r;\n        cin >> t >> l >> r;\n        l--;\n        if (t == 0) {\n\
    \            int x;\n            cin >> x;\n            seg.apply(l, r, x);\n\
    \        } else {\n            cout << seg.prod(l, r).val() << '\\n';\n      \
    \  }\n    }\n}"
  dependsOn:
  - src/data_structure/range_query/lazysegtree.hpp
  - src/monoid/range_add_range_sum.hpp
  isVerificationFile: true
  path: test/monoid/range_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 14:11:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/monoid/range_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/monoid/range_add_range_sum.test.cpp
- /verify/test/monoid/range_add_range_sum.test.cpp.html
title: test/monoid/range_add_range_sum.test.cpp
---
