---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/segtree.hpp
    title: Segtree
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp
    title: Dynamic Rectangle Sum
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rectangle_query/rectangle_sum.hpp
    title: src/data_structure/rectangle_query/rectangle_sum.hpp
  - icon: ':question:'
    path: src/misc/merge_and_unique.hpp
    title: Merge And Unique
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#line 2 \"src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp\"\n#include\
    \ <cassert>\n#include <vector>\n#line 3 \"src/data_structure/rectangle_query/rectangle_sum.hpp\"\
    \n#include <numeric>\n#line 2 \"src/misc/merge_and_unique.hpp\"\n#include <algorithm>\n\
    #line 4 \"src/misc/merge_and_unique.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T, typename... Ts>\nvector<T> merge_and_unique(const vector<T> &a, const Ts\
    \ &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(), z.begin(), z.end()),\
    \ ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 4 \"src/data_structure/range_query/segtree.hpp\"\
    \nusing namespace std;\n\ntemplate <typename Monoid>\nstruct segtree {\n    using\
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
    \ {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n};\n#line 7 \"src/data_structure/rectangle_query/rectangle_sum.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Abelian_Group, typename T = int>\n\
    struct rectangle_sum {\n    using M = Abelian_Group;\n    using S = typename M::S;\n\
    \    rectangle_sum(int n = 0, int q = 0) {\n        xs.reserve(n);\n        ys.reserve(n);\n\
    \        ws.reserve(n);\n        xls.reserve(q);\n        yls.reserve(q);\n  \
    \      xrs.reserve(q);\n        yrs.reserve(q);\n    }\n    void add_point(T x,\
    \ T y, S w) {\n        xs.emplace_back(x);\n        ys.emplace_back(y);\n    \
    \    ws.emplace_back(w);\n    }\n    void add_query(T xl, T yl, T xr, T yr) {\n\
    \        xls.emplace_back(xl);\n        yls.emplace_back(yl);\n        xrs.emplace_back(xr);\n\
    \        yrs.emplace_back(yr);\n    }\n    vector<S> solve() {\n        int n\
    \ = xs.size(), q = xls.size();\n        if (n == 0 || q == 0) return vector<S>(q,\
    \ M::e());\n        auto yb = merge_and_unique(ys);\n        vector<int> yi(n);\n\
    \        for (int i = 0; i < n; i++) {\n            yi[i] = lower_bound(yb.begin(),\
    \ yb.end(), ys[i]) - yb.begin();\n        }\n        vector<int> ord_pts(n), ord_query(2\
    \ * q);\n        iota(ord_pts.begin(), ord_pts.end(), 0);\n        iota(ord_query.begin(),\
    \ ord_query.end(), 0);\n        sort(ord_pts.begin(), ord_pts.end(), [&] (int\
    \ i, int j) { return xs[i] < xs[j]; });\n        sort(ord_query.begin(), ord_query.end(),\
    \ [&] (int i, int j) {\n            T xi = i < q ? xls[i] : xrs[i - q];\n    \
    \        T xj = j < q ? xls[j] : xrs[j - q];\n            return xi < xj;\n  \
    \      });\n        segtree<M> seg(yb.size());\n        vector<S> res(q, M::e());\n\
    \        int j = 0;\n        for (int i : ord_query) {\n            T x = (i <\
    \ q ? xls[i] : xrs[i - q]);\n            while (j < n && xs[ord_pts[j]] < x) {\n\
    \                seg.apply(yi[ord_pts[j]], ws[ord_pts[j]]);\n                j++;\n\
    \            }\n            if (i < q) {\n                int yl = lower_bound(yb.begin(),\
    \ yb.end(), yls[i]) - yb.begin();\n                int yr = lower_bound(yb.begin(),\
    \ yb.end(), yrs[i]) - yb.begin();\n                res[i] = M::op(res[i], M::inv(seg.prod(yl,\
    \ yr)));\n            } else {\n                i -= q;\n                int yl\
    \ = lower_bound(yb.begin(), yb.end(), yls[i]) - yb.begin();\n                int\
    \ yr = lower_bound(yb.begin(), yb.end(), yrs[i]) - yb.begin();\n             \
    \   res[i] = M::op(res[i], seg.prod(yl, yr));\n            }\n        }\n    \
    \    return res;\n    }\nprivate:\n    vector<T> xs, ys, xls, yls, xrs, yrs;\n\
    \    vector<S> ws;\n};\n#line 5 \"src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp\"\
    \n\ntemplate<typename Abelian_Group, typename T = int>\nstruct dynamic_point_add_rectangle_sum\
    \ {\n    using M = Abelian_Group;\n    using S = typename M::S;\n    dynamic_point_add_rectangle_sum(int\
    \ n = 0, int q = 0) {\n        types.reserve(n + q);\n        update_querys.reserve(n);\n\
    \        sum_querys.reserve(q);\n    }\n    void add_update_query(T x, T y, const\
    \ S &w) {\n        types.emplace_back(false);\n        update_querys.emplace_back(x,\
    \ y, w);\n    }\n    void add_sum_query(T xl, T yl, T xr, T yr) {\n        assert(xl\
    \ <= xr);\n        assert(yl <= yr);\n        types.emplace_back(true);\n    \
    \    sum_querys.emplace_back(xl, yl, xr, yr);\n    }\n    vector<S> solve() {\n\
    \        int sz = types.size(), n = 0, q = 0;\n        vector<int> inv(sz, -1);\n\
    \        for (int i = 0; i < sz; i++) {\n            inv[i] = (types[i] ? q++\
    \ : n++);\n        }\n        vector<S> res(q, M::e());\n        auto rec = [&]\
    \ (const auto &rec, int l, int r) -> void {\n            if (l + 1 >= r) return;\n\
    \            int m = (l + r) / 2;\n            rec(rec, l, m);\n            rec(rec,\
    \ m, r);\n            int tn = 0, tq = 0;\n            for (int i = l; i < r;\
    \ i++) {\n                (types[i] ? tq : tn)++;\n            }\n           \
    \ rectangle_sum<Abelian_Group, T> rs(tn, tq);\n            for (int i = l; i <\
    \ m; i++) {\n                if (!types[i]) {\n                    auto [x, y,\
    \ w] = update_querys[inv[i]];\n                    rs.add_point(x, y, w);\n  \
    \              }\n            }\n            for (int i = m; i < r; i++) {\n \
    \               if (types[i]) {\n                    auto [xl, yl, xr, yr] = sum_querys[inv[i]];\n\
    \                    rs.add_query(xl, yl, xr, yr);\n                }\n      \
    \      }\n            auto sub = rs.solve();\n            for (int i = m, j =\
    \ 0; i < r; i++) {\n                if (types[i]) {\n                    res[inv[i]]\
    \ = M::op(res[inv[i]], sub[j++]);\n                }\n            }\n        };\n\
    \        rec(rec, 0, sz);\n        return res;\n    }\nprivate:\n    int n, q;\n\
    \    vector<bool> types;\n    vector<tuple<T, T, S>> update_querys;\n    vector<tuple<T,\
    \ T, T, T>> sum_querys;\n};\n#line 2 \"src/monoid/add.hpp\"\n\ntemplate<typename\
    \ T>\nstruct add_monoid {\n    using S = T;\n    static S op(S a, S b) { return\
    \ a + b; }\n    static S e() { return 0; }\n    static S inv(S x) { return -x;\
    \ }\n};\n#line 5 \"test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    dynamic_point_add_rectangle_sum<add_monoid<long\
    \ long >> rs(N, Q);\n    for (int i = 0; i < N; i++) {\n        int x, y, w;\n\
    \        cin >> x >> y >> w;\n        rs.add_update_query(x, y, w);\n    }\n \
    \   for (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n       \
    \ if (t == 0) {\n            int x, y, w;\n            cin >> x >> y >> w;\n \
    \           rs.add_update_query(x, y, w);\n        } else {\n            int xl,\
    \ yl, xr, yr;\n            cin >> xl >> yl >> xr >> yr;\n            rs.add_sum_query(xl,\
    \ yl, xr, yr);\n        }\n    }\n    for (auto e : rs.solve()) cout << e << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../../src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp\"\
    \n#include \"../../../src/monoid/add.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, Q;\n\
    \    cin >> N >> Q;\n    dynamic_point_add_rectangle_sum<add_monoid<long long\
    \ >> rs(N, Q);\n    for (int i = 0; i < N; i++) {\n        int x, y, w;\n    \
    \    cin >> x >> y >> w;\n        rs.add_update_query(x, y, w);\n    }\n    for\
    \ (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n        if (t\
    \ == 0) {\n            int x, y, w;\n            cin >> x >> y >> w;\n       \
    \     rs.add_update_query(x, y, w);\n        } else {\n            int xl, yl,\
    \ xr, yr;\n            cin >> xl >> yl >> xr >> yr;\n            rs.add_sum_query(xl,\
    \ yl, xr, yr);\n        }\n    }\n    for (auto e : rs.solve()) cout << e << '\\\
    n';\n}"
  dependsOn:
  - src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp
  - src/data_structure/rectangle_query/rectangle_sum.hpp
  - src/misc/merge_and_unique.hpp
  - src/data_structure/range_query/segtree.hpp
  - src/monoid/add.hpp
  isVerificationFile: true
  path: test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
- /verify/test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp.html
title: test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
---
