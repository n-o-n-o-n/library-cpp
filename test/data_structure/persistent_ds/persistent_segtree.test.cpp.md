---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/persistent_ds/persistent_segtree.hpp
    title: Persistent Segtree
  - icon: ':question:'
    path: src/misc/compress.hpp
    title: Compress
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
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/data_structure/persistent_ds/persistent_segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#line 2\
    \ \"src/misc/compress.hpp\"\n#include <algorithm>\n#include <vector>\n#line 4\
    \ \"src/misc/merge_and_unique.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T, typename... Ts>\nvector<T> merge_and_unique(const vector<T> &a, const Ts\
    \ &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(), z.begin(), z.end()),\
    \ ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 5 \"src/misc/compress.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nvector<int> compress(const vector<T>\
    \ &v) {\n    auto zip = merge_and_unique(v);\n    vector<int> res;\n    res.reserve(v.size());\n\
    \    for (const T &e : v) {\n        res.push_back(lower_bound(zip.begin(), zip.end(),\
    \ e) - zip.begin());\n    }\n    return res;\n}\n\ntemplate<typename T, typename...\
    \ Ts>\nauto compress(const vector<T> &a, const Ts &...z) {\n    auto zip = merge_and_unique(a,\
    \ z...);\n    auto f = [&] (const vector<T> &v) -> vector<int> {\n        vector<int>\
    \ res;\n        res.reserve(v.size());\n        for (const T &e : v) {\n     \
    \       res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());\n\
    \        }\n        return res;\n    };\n    return make_tuple(f(a), f(z)...);\n\
    }\n\ntemplate<typename T, typename... Ts>\nint compress_inplace(vector<T> &a,\
    \ Ts &...z) {\n    auto zip = merge_and_unique(a, z...);\n    auto f = [&] (vector<T>\
    \ &v) -> void {\n        for (T &e : v) {\n            e = lower_bound(zip.begin(),\
    \ zip.end(), e) - zip.begin();\n        }\n    };\n    (f(a), ..., f(z));\n  \
    \  return (int)zip.size();\n}\n#line 2 \"src/data_structure/persistent_ds/persistent_segtree.hpp\"\
    \n#include <cassert>\n#line 4 \"src/data_structure/persistent_ds/persistent_segtree.hpp\"\
    \nusing namespace std;\n\ntemplate<typename Monoid>\nstruct persistent_segtree\
    \ {\n    using M = Monoid;\n    using S = typename M::S;\n    persistent_segtree()\
    \ : persistent_segtree(0) {}\n    persistent_segtree(int _n) : persistent_segtree(vector<S>(_n,\
    \ M::e())) {}\n    persistent_segtree(const vector<S> &v) : n(v.size()), roots(1,\
    \ 1) {\n        log = 0;\n        while ((1 << log) < n) log++;\n        sz =\
    \ 1 << log;\n        make_node(-1, -1);\n        make_node(-1, -1);\n        for\
    \ (int i = 2; i < 2 * sz; i++) {\n            make_node(i / 2, !(i & 1), sz <=\
    \ i && i < sz + n ? v[i - sz] : M::e());\n        }\n        if (n == 1) d[1].x\
    \ = v[0];\n        for (int i = sz - 1; i > 0; i--) update(i);\n    }\n    void\
    \ reserve(int q) {\n        d.reserve(q * log);\n        roots.reserve(q);\n \
    \   }\n    int set(int k, int p, const S &x) {\n        assert(0 <= k && k < ssize(roots));\n\
    \        assert(0 <= p && p < n);\n        int res = roots.size();\n        int\
    \ i = make_node(-1, -1);\n        roots.emplace_back(i);\n        d[i] = d[roots[k]];\n\
    \        set(i, roots[k], p, x, 0, sz);\n        return res;\n    }\n    S get(int\
    \ k, int p) const {\n        assert(0 <= k && k < ssize(roots));\n        assert(0\
    \ <= p && p < n);\n        return get(roots[k], p, 0, sz);\n    };\n    S prod(int\
    \ k, int l, int r) const {\n        assert(0 <= k && k < ssize(roots));\n    \
    \    assert(0 <= l && l <= r && r <= n);\n        return prod(roots[k], l, r,\
    \ 0, sz);\n    }\nprivate:\n    int n, log, sz;\n    struct node {\n        node(const\
    \ S &_x = M::e(), int p = -1) : x(_x), par(p), l(-1), r(-1) {}\n        S x;\n\
    \        int par, l, r;\n    };\n    vector<int> roots;\n    vector<node> d;\n\
    \    S val(int p) const { return p == -1 ? M::e() : d[p].x; }\n    int make_node(int\
    \ par, bool is_left, const S &x = M::e()) {\n        int p = d.size();\n     \
    \   d.emplace_back(x, par);\n        d[p].par = par;\n        if (par != -1) (is_left\
    \ ? d[par].l : d[par].r) = p;\n        return p;\n    }\n    void update(int p)\
    \ { d[p].x = M::op(val(d[p].l), val(d[p].r)); }\n    void set(int i, int j, int\
    \ p, const S &x, int l, int r) {\n        if (l + 1 == r) {\n            d[i].x\
    \ = x;\n            return;\n        }\n        int m = (l + r) / 2;\n       \
    \ if (p < m) {\n            int ni = make_node(i, true);\n            d[i].r =\
    \ d[j].r;\n            set(ni, d[j].l, p, x, l, m);\n        } else {\n      \
    \      int ni = make_node(i, false);\n            d[i].l = d[j].l;\n         \
    \   set(ni, d[j].r, p, x, m, r);\n        }\n        update(i);\n    }\n    S\
    \ get(int i, int p, int l, int r) const {\n        if (l + 1 == r) return val(i);\n\
    \        int m = (l + r) / 2;\n        if (p < m) return get(d[i].l, p, l, m);\n\
    \        return get(d[i].r, p, m, r);\n    }\n    S prod(int i, int ql, int qr,\
    \ int l, int r) const {\n        if (i == -1 || qr <= l || ql >= r) return M::e();\n\
    \        if (ql <= l && r <= qr) return val(i);\n        int m = (l + r) / 2;\n\
    \        return M::op(prod(d[i].l, ql, qr, l, m), prod(d[i].r, ql, qr, m, r));\n\
    \    }\n};\n#line 2 \"src/monoid/add.hpp\"\n\ntemplate<typename T>\nstruct add_monoid\
    \ {\n    using S = T;\n    static S op(S a, S b) { return a + b; }\n    static\
    \ S e() { return 0; }\n    static S inv(S x) { return -x; }\n};\n#line 6 \"test/data_structure/persistent_ds/persistent_segtree.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> X(N),\
    \ Y(N), Z(N);\n    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> Z[i];\n\
    \    vector<int> L(Q), D(Q), R(Q), U(Q);\n    for (int i = 0; i < Q; i++) cin\
    \ >> L[i] >> D[i] >> R[i] >> U[i];\n    int W = compress_inplace(X, L, R);\n \
    \   int H = compress_inplace(Y, D, U);\n    vector<vector<pair<int, int>>> inv(H);\n\
    \    for (int i = 0; i < N; i++) inv[Y[i]].emplace_back(X[i], Z[i]);\n    persistent_segtree<add_monoid<long\
    \ long>> seg(W);\n    vector<int> T(H);\n    for (int y = 0, t = 0; y < H; y++)\
    \ {\n        T[y] = t;\n        for (auto [x, z] : inv[y]) {\n            seg.set(t,\
    \ x, seg.get(t, x) + z);\n            t++;\n        }\n    }\n    for (int i =\
    \ 0; i < Q; i++) {\n        cout << seg.prod(T[U[i]], L[i], R[i]) - seg.prod(T[D[i]],\
    \ L[i], R[i]) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"../../../src/misc/compress.hpp\"\n#include \"../../../src/data_structure/persistent_ds/persistent_segtree.hpp\"\
    \n#include \"../../../src/monoid/add.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<int> X(N), Y(N), Z(N);\n    for (int i = 0; i\
    \ < N; i++) cin >> X[i] >> Y[i] >> Z[i];\n    vector<int> L(Q), D(Q), R(Q), U(Q);\n\
    \    for (int i = 0; i < Q; i++) cin >> L[i] >> D[i] >> R[i] >> U[i];\n    int\
    \ W = compress_inplace(X, L, R);\n    int H = compress_inplace(Y, D, U);\n   \
    \ vector<vector<pair<int, int>>> inv(H);\n    for (int i = 0; i < N; i++) inv[Y[i]].emplace_back(X[i],\
    \ Z[i]);\n    persistent_segtree<add_monoid<long long>> seg(W);\n    vector<int>\
    \ T(H);\n    for (int y = 0, t = 0; y < H; y++) {\n        T[y] = t;\n       \
    \ for (auto [x, z] : inv[y]) {\n            seg.set(t, x, seg.get(t, x) + z);\n\
    \            t++;\n        }\n    }\n    for (int i = 0; i < Q; i++) {\n     \
    \   cout << seg.prod(T[U[i]], L[i], R[i]) - seg.prod(T[D[i]], L[i], R[i]) << '\\\
    n';\n    }\n}"
  dependsOn:
  - src/misc/compress.hpp
  - src/misc/merge_and_unique.hpp
  - src/data_structure/persistent_ds/persistent_segtree.hpp
  - src/monoid/add.hpp
  isVerificationFile: true
  path: test/data_structure/persistent_ds/persistent_segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/persistent_ds/persistent_segtree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/persistent_ds/persistent_segtree.test.cpp
- /verify/test/data_structure/persistent_ds/persistent_segtree.test.cpp.html
title: test/data_structure/persistent_ds/persistent_segtree.test.cpp
---
