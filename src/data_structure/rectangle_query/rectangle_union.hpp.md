---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data_structure/range_query/lazysegtree.hpp
    title: Lazysegtree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/data_structure/rectangle_query/rectangle_union.test.cpp
    title: test/data_structure/rectangle_query/rectangle_union.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/rectangle_query/rectangle_union.hpp\"\
    \n#include <algorithm>\n#include <limits>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n#line 2 \"src/data_structure/range_query/lazysegtree.hpp\"\n\
    #include <cassert>\n#line 4 \"src/data_structure/range_query/lazysegtree.hpp\"\
    \nusing namespace std;\n\ntemplate<typename ActMonoid>\nstruct lazysegtree {\n\
    \    using M = ActMonoid;\n    using S = typename M::S;\n    using F = typename\
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
    \        for (int i = log; i >= 1; i--) push(p >> i);\n    }\n};\n#line 8 \"src/data_structure/rectangle_query/rectangle_union.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nstruct rectangle_union {\n   \
    \ vector<T> xs;\n    vector<tuple<T, T, T, int>> eve;\n    rectangle_union(int\
    \ n = 0) {\n        xs.reserve(2 * n);\n        eve.reserve(2 * n);\n    }\n \
    \   void add_rectangle(T xl, T yl, T xr, T yr) {\n        if (xl == xr || yl ==\
    \ yr) return;\n        xs.emplace_back(xl);\n        xs.emplace_back(xr);\n  \
    \      eve.emplace_back(yl, xl, xr, 1);\n        eve.emplace_back(yr, xl, xr,\
    \ -1);\n    }\n    T solve() {\n        if (eve.empty()) return 0;\n        sort(xs.begin(),\
    \ xs.end());\n        xs.erase(unique(xs.begin(), xs.end()), xs.end());\n    \
    \    int n = xs.size();\n        sort(eve.begin(), eve.end());\n        vector<pair<int,\
    \ T>> init(n - 1);\n        for (int i = 0; i < n - 1; i++) init[i] = {0, xs[i\
    \ + 1] - xs[i]};\n        lazysegtree<monoid> seg(init);\n        T w = xs.back()\
    \ - xs.front();\n        T pre = get<0>(eve.front()), res = 0;\n        for (auto\
    \ [y, xl, xr, sgn] : eve) {\n            auto [cnt, len] = seg.all_prod();\n \
    \           res += (w - (cnt == 0 ? len : 0)) * (y - pre);\n            int l\
    \ = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n            int r = lower_bound(xs.begin(),\
    \ xs.end(), xr) - xs.begin();\n            seg.apply(l, r, sgn);\n           \
    \ pre = y;\n        }\n        return res;\n    }\nprivate:\n    struct monoid\
    \ {\n        using S = pair<int, T>;\n        static S op(S a, S b) {\n      \
    \      if (a.first == b.first) return {a.first, a.second + b.second};\n      \
    \      return a.first < b.first ? a : b;\n        }\n        static S e() { return\
    \ {numeric_limits<int>::max(), 0}; }\n        using F = int;\n        static F\
    \ comp(F f, F g) { return f + g; }\n        static F id() { return 0; }\n    \
    \    static S map(F f, S x) {\n            if (x.first != numeric_limits<int>::max())\
    \ x.first += f;\n            return x;\n        }\n    };\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n#include \"../range_query/lazysegtree.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nstruct rectangle_union {\n   \
    \ vector<T> xs;\n    vector<tuple<T, T, T, int>> eve;\n    rectangle_union(int\
    \ n = 0) {\n        xs.reserve(2 * n);\n        eve.reserve(2 * n);\n    }\n \
    \   void add_rectangle(T xl, T yl, T xr, T yr) {\n        if (xl == xr || yl ==\
    \ yr) return;\n        xs.emplace_back(xl);\n        xs.emplace_back(xr);\n  \
    \      eve.emplace_back(yl, xl, xr, 1);\n        eve.emplace_back(yr, xl, xr,\
    \ -1);\n    }\n    T solve() {\n        if (eve.empty()) return 0;\n        sort(xs.begin(),\
    \ xs.end());\n        xs.erase(unique(xs.begin(), xs.end()), xs.end());\n    \
    \    int n = xs.size();\n        sort(eve.begin(), eve.end());\n        vector<pair<int,\
    \ T>> init(n - 1);\n        for (int i = 0; i < n - 1; i++) init[i] = {0, xs[i\
    \ + 1] - xs[i]};\n        lazysegtree<monoid> seg(init);\n        T w = xs.back()\
    \ - xs.front();\n        T pre = get<0>(eve.front()), res = 0;\n        for (auto\
    \ [y, xl, xr, sgn] : eve) {\n            auto [cnt, len] = seg.all_prod();\n \
    \           res += (w - (cnt == 0 ? len : 0)) * (y - pre);\n            int l\
    \ = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();\n            int r = lower_bound(xs.begin(),\
    \ xs.end(), xr) - xs.begin();\n            seg.apply(l, r, sgn);\n           \
    \ pre = y;\n        }\n        return res;\n    }\nprivate:\n    struct monoid\
    \ {\n        using S = pair<int, T>;\n        static S op(S a, S b) {\n      \
    \      if (a.first == b.first) return {a.first, a.second + b.second};\n      \
    \      return a.first < b.first ? a : b;\n        }\n        static S e() { return\
    \ {numeric_limits<int>::max(), 0}; }\n        using F = int;\n        static F\
    \ comp(F f, F g) { return f + g; }\n        static F id() { return 0; }\n    \
    \    static S map(F f, S x) {\n            if (x.first != numeric_limits<int>::max())\
    \ x.first += f;\n            return x;\n        }\n    };\n};\n"
  dependsOn:
  - src/data_structure/range_query/lazysegtree.hpp
  isVerificationFile: false
  path: src/data_structure/rectangle_query/rectangle_union.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/data_structure/rectangle_query/rectangle_union.test.cpp
documentation_of: src/data_structure/rectangle_query/rectangle_union.hpp
layout: document
redirect_from:
- /library/src/data_structure/rectangle_query/rectangle_union.hpp
- /library/src/data_structure/rectangle_query/rectangle_union.hpp.html
title: src/data_structure/rectangle_query/rectangle_union.hpp
---
