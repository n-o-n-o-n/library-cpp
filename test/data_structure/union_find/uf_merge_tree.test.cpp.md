---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/sparse_table.hpp
    title: src/data_structure/range_query/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/static_rmq.hpp
    title: src/data_structure/range_query/static_rmq.hpp
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/uf_merge_tree.hpp
    title: Union Find Merge Tree
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: src/monoid/min.hpp
    title: src/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/static_tree.hpp
    title: Static Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/data_structure/union_find/uf_merge_tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"src/data_structure/union_find/uf_merge_tree.hpp\"\
    \n#include <cassert>\n#include <numeric>\n#include <vector>\n#line 3 \"src/data_structure/union_find/union_find.hpp\"\
    \n#include <iterator>\n#line 6 \"src/data_structure/union_find/union_find.hpp\"\
    \nusing namespace std;\n\nstruct union_find {\n    union_find(int n) : p(n, -1),\
    \ cyc(n) {\n        iota(cyc.begin(), cyc.end(), 0);\n    }\n    int leader(int\
    \ u) {\n        assert(0 <= u && u < ssize(p));\n        return p[u] < 0 ? u :\
    \ p[u] = leader(p[u]);\n    }\n    bool same(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        return\
    \ leader(u) == leader(v);\n    }\n    int merge(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        u =\
    \ leader(u);\n        v = leader(v);\n        if (u == v) return u;\n        if\
    \ (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n        p[v] = u;\n      \
    \  swap(cyc[u], cyc[v]);\n        return u;\n    }\n    int size(int u) {\n  \
    \      assert(0 <= u && u < ssize(p));\n        return -p[leader(u)];\n    }\n\
    \    vector<int> group(int u) {\n        assert(0 <= u && u < ssize(p));\n   \
    \     vector<int> res = {u};\n        int v = cyc[u];\n        while (v != u)\
    \ {\n            res.push_back(v);\n            v = cyc[v];\n        }\n     \
    \   return res;\n    }\n    vector<vector<int>> groups() {\n        int n = p.size();\n\
    \        vector<vector<int>> tmp(n);\n        for (int i = 0; i < n; i++) {\n\
    \            tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n\
    \        }\n        return res;\n    }\nprivate:\n    vector<int> p, cyc;\n};\n\
    #line 6 \"src/data_structure/union_find/uf_merge_tree.hpp\"\nusing namespace std;\n\
    \nstruct uf_merge_tree {\n    uf_merge_tree(int _n = 0) : n(_n), c(_n), par(2\
    \ * _n, -1), top(_n), uf(_n) {\n        iota(top.begin(), top.end(), 0);\n   \
    \ }\n    int merge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        u = uf.leader(u);\n        v = uf.leader(v);\n\
    \        if (u == v) return top[u];\n        int tu = top[u];\n        int tv\
    \ = top[v];\n        par[tu] = c;\n        par[tv] = c;\n        top[uf.merge(u,\
    \ v)] = c;\n        return c++;\n    }\n    vector<int> parents() const {\n  \
    \      return vector<int>(par.begin(), par.begin() + c);\n    }\nprivate:\n  \
    \  int n, c;\n    vector<int> par, top;\n    union_find uf;\n};\n#line 2 \"src/tree/static_tree.hpp\"\
    \n#include <algorithm>\n#line 4 \"src/tree/static_tree.hpp\"\n#include <iostream>\n\
    #include <stack>\n#line 7 \"src/tree/static_tree.hpp\"\nusing namespace std;\n\
    #line 3 \"src/data_structure/range_query/static_rmq.hpp\"\n#include <limits>\n\
    #include <type_traits>\n#line 2 \"src/data_structure/range_query/sparse_table.hpp\"\
    \n#include <bit>\n#line 5 \"src/data_structure/range_query/sparse_table.hpp\"\n\
    using namespace std;\n\ntemplate<typename Monoid>\nstruct sparse_table {\n   \
    \ using M = Monoid;\n    using S = typename M::S;\n    sparse_table() = default;\n\
    \    sparse_table(const vector<S> &v) : n(v.size()), b(0), d(1, v) { build();\
    \ }\n    S prod(int l, int r) const {\n        assert(0 <= l && l <= r && r <=n);\n\
    \        if (l == r) return M::e();\n        int i = bit_width(unsigned(r - l))\
    \ - 1;\n        return M::op(d[i][l], d[i][r - (1 << i)]);\n    }\nprivate:\n\
    \    int n, b, e;\n    vector<vector<S>> d;\n    void build() {\n        b = bit_width(unsigned(n));\n\
    \        d.resize(b);\n        for (int i = 1; i < b; i++) {\n            int\
    \ width = 1 << i;\n            d[i].assign(n - width + 1, M::e());\n         \
    \   for (int j = 0; j + width <= n; j++) {\n                d[i][j] = M::op(d[i\
    \ - 1][j], d[i - 1][j + (width >> 1)]);\n            }\n        }\n    }\n};\n\
    #line 4 \"src/monoid/min.hpp\"\nusing namespace std;\n\ntemplate<typename T, T\
    \ E = numeric_limits<T>::max()>\nstruct min_monoid {\n    using S = T;\n    static\
    \ S op(S a, S b) { return min(a, b); }\n    static S e() { return E; }\n};\n#line\
    \ 8 \"src/data_structure/range_query/static_rmq.hpp\"\nusing namespace std;\n\n\
    template<typename T, T inf = numeric_limits<T>::max()>\nstruct static_rmq {\n\
    \    static_assert(is_integral_v<T>);\n    static_rmq() = default;\n    static_rmq(const\
    \ vector<T> &_v) : n(_v.size()), v(_v), pref(n), suff(n) { build(); }\n    T prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        if (l\
    \ == r) return inf;\n        r--;\n        int bl = l >> log, br = r >> log;\n\
    \        if (bl < br) {\n            if (bl + 1 == br) return min(pref[r], suff[l]);\n\
    \            return min(min(pref[r], suff[l]), st.prod(bl + 1, br));\n       \
    \ }\n        T res = v[l];\n        for (int i = l + 1; i <= r; i++) res = min(res,\
    \ v[i]);\n        return res;\n    }\nprivate:\n    int n;\n    static constexpr\
    \ int log = 4, mask = 15;\n    vector<T> v, pref, suff;\n    sparse_table<min_monoid<T,\
    \ inf>> st;\n    void build() {\n        if (n == 0) return;\n        pref[0]\
    \ = v[0];\n        suff[n - 1] = v[n - 1];\n        for (int i = 1; i < n; i++)\
    \ {\n            pref[i] = i & mask ? min(pref[i - 1], v[i]) : v[i];\n       \
    \ }\n        for (int i = n - 2; i >= 0; i--) {\n            suff[i] = (i & mask)\
    \ == mask ? v[i] : min(v[i], suff[i + 1]);\n        }\n        st = sparse_table<min_monoid<T,\
    \ inf>>([&] {\n            vector<T> a(n >> log);\n            for (int i = 0;\
    \ i < (n >> log); i++) {\n                a[i] = suff[i << log];\n           \
    \ }\n            return move(a);\n        } ());\n    }\n};\n#line 9 \"src/tree/static_tree.hpp\"\
    \n\nstruct static_tree {\n    static_tree() = default;\n    static_tree(int _n,\
    \ int r = 0) : n(_n), e(0), root(r), g(_n), built(false) {\n        if (n <= 1)\
    \ build();\n    }\n    void set_root(int r) {\n        assert(0 <= r && r < n);\n\
    \        root = r;\n        built = false;\n        build();\n    }\n    void\
    \ add_edge(int u, int v) {\n        assert(!built);\n        assert(e < n - 1);\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        g[u].push_back(v);\n\
    \        g[v].push_back(u);\n        if (++e == n - 1) build();\n    }\n    void\
    \ read_edges(bool idx = 1) {\n        for (int i = 1, u, v; i < n; i++) {\n  \
    \          cin >> u >> v;\n            u -= idx;\n            v -= idx;\n    \
    \        g[u].push_back(v);\n            g[v].push_back(u);\n        }\n     \
    \   build();\n    }\n    vector<int> &operator[](int u) {\n        assert(0 <=\
    \ u && u < n);\n        return g[u];\n    }\n    int depth(int u) const {\n  \
    \      assert(built);\n        assert(0 <= u && u < n);\n        return d[u];\n\
    \    }\n    int lca(int u, int v, int r = -1) const {\n        assert(built);\n\
    \        assert(0 <= u && u < n);\n        if (r == -1) {\n            auto [kl,\
    \ kr] = minmax(in[u], in[v]);\n            return ord[id(kl, kr + 1)];\n     \
    \   }\n        assert(0 <= r && r < n);\n        return lca(u, v) ^ lca(v, r)\
    \ ^ lca(r, u);\n    }\n    int dist(int u, int v) const {\n        assert(built);\n\
    \        int w = lca(u, v);\n        return d[u] + d[v] - 2 * d[w];\n    }\n \
    \   int jump(int u, int v, int k) const {\n        assert(built);\n        int\
    \ w = lca(u, v);\n        if (d[u] + d[v] - 2 * d[w] < k) return -1;\n       \
    \ if (d[u] - d[w] < k) {\n            swap(u, v);\n            k = d[u] + d[v]\
    \ - 2 * d[w] - k;\n        }\n        k = d[u] - k;\n        return *prev(upper_bound(list[k].begin(),\
    \ list[k].end(), u, [&] (int i, int j) {\n            return in[i] < in[j];\n\
    \        }));\n    }\n    bool is_on_path(int w, int u, int v) const {\n     \
    \   assert(built);\n        assert(0 <= w && w < n);\n        assert(0 <= u &&\
    \ u < n);\n        assert(0 <= v && v < n);\n        return lca(u, v, w) == w;\n\
    \    }\n    int sub_size(int u, int r = -1) const {\n        assert(built);\n\
    \        assert(0 <= u && u < n);\n        if (r == -1) r = root;\n        assert(0\
    \ <= r && r < n);\n        if (r == u) return n;\n        if (lca(u, r) != u)\
    \ return sz[u];\n        auto [kl, kr] = minmax(in[u], in[r]);\n        return\
    \ n - sz[ord[1 + id(kl, kr + 1)]];\n    }\n    vector<int> path(int u, int v)\
    \ const {\n        assert(built);\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n        int w = lca(u, v);\n        vector<int> pu, pv;\n \
    \       while (u != w) {\n            pu.push_back(u);\n            u = ord[in[u]\
    \ - 1];\n        }\n        while (v != w) {\n            pv.push_back(v);\n \
    \           v = ord[in[v] - 1];\n        }\n        reverse(pv.begin(), pv.end());\n\
    \        pu.push_back(w);\n        pu.insert(pu.end(), pv.begin(), pv.end());\n\
    \        return pu;\n    }\n    vector<pair<int, int>> auxiliary_tree(vector<int>\
    \ vs) const {\n        if (vs.empty()) return {};\n        sort(vs.begin(), vs.end(),\
    \ [&] (int u, int v) {\n            return in[u] < in[v];\n        });\n     \
    \   vs.erase(unique(vs.begin(), vs.end()), vs.end());\n        vector<pair<int,\
    \ int>> res;\n        stack<int> st;\n        st.push(vs[0]);\n        for (int\
    \ i = 1; i < ssize(vs); i++) {\n            int w = lca(vs[i - 1], vs[i]);\n \
    \           if (w != vs[i - 1]) {\n                int u = st.top();\n       \
    \         st.pop();\n                while (st.size() && d[w] < d[st.top()]) {\n\
    \                    res.emplace_back(u, st.top());\n                    u = st.top();\n\
    \                    st.pop();\n                }\n                res.emplace_back(u,\
    \ w);\n                if (st.empty() || st.top() != w) st.push(w);\n        \
    \    }\n            st.push(vs[i]);\n        }\n        while (st.size() > 1)\
    \ {\n            int u = st.top();\n            st.pop();\n            res.emplace_back(u,\
    \ st.top());\n        }\n        return res;\n    }\nprivate:\n    int n, e, root;\n\
    \    vector<vector<int>> g, list;\n    bool built;\n    vector<int> d, ord, in,\
    \ sz;\n    static constexpr long long mask = (1LL << 32) - 1;\n    static_rmq<long\
    \ long> st;\n    int id(int l, int r) const {\n        return int(mask ^ (st.prod(l,\
    \ r) & mask));\n    }\n    int dfs(int u, int p) {\n        ord.push_back(u);\n\
    \        list[d[u]].push_back(u);\n        for (int v : g[u]) {\n            if\
    \ (v != p) {\n                d[v] = d[u] + 1;\n                sz[u] += dfs(v,\
    \ u);\n                ord.push_back(u);\n            }\n        }\n        return\
    \ ++sz[u];\n    }\n    void build() {\n        if (built) return;\n        d =\
    \ vector<int>(n, 0);\n        sz = vector<int>(n, 0);\n        ord.clear();\n\
    \        ord.reserve(2 * n);\n        list = vector<vector<int>>(n);\n       \
    \ dfs(root, root);\n        in = vector<int>(n, -1);\n        st = static_rmq<long\
    \ long>([&] {\n            vector<long long> a(ord.size());\n            for (int\
    \ i = 0; i < ssize(ord); i++) {\n                int u = ord[i];\n           \
    \     if (in[u] == -1) in[u] = i;\n                a[i] = ((long long)d[u] <<\
    \ 32) ^ mask ^ i;\n            }\n            return a;\n        } ());\n    \
    \    built = true;\n    }\n};\n#line 5 \"test/data_structure/union_find/uf_merge_tree.test.cpp\"\
    \n\n#line 7 \"test/data_structure/union_find/uf_merge_tree.test.cpp\"\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<int> T(Q), U(Q), V(Q), time(2 * N, Q);\n    fill(time.begin(),\
    \ time.begin() + N, -1);\n    uf_merge_tree umt(N);\n    for (int i = 0; i < Q;\
    \ i++) {\n        cin >> T[i] >> U[i] >> V[i];\n        if (T[i] == 0) {\n   \
    \         int k = umt.merge(U[i], V[i]);\n            time[k] = min(time[k], i);\n\
    \        }\n    }\n    for (int i = 0; i < N - 1; i++) umt.merge(i, i + 1);\n\
    \    auto P = umt.parents();\n    static_tree G(P.size());\n    int rt = -1;\n\
    \    for (int i = 0; i < ssize(P); i++) {\n        if (P[i] != -1) {\n       \
    \     G.add_edge(i, P[i]);\n        } else {\n            rt = i;\n        }\n\
    \    }\n    for (int i = 0; i < Q; i++) {\n        if (T[i] == 1) {\n        \
    \    cout << (time[G.lca(U[i], V[i], rt)] < i) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../src/data_structure/union_find/uf_merge_tree.hpp\"\n#include \"../../../src/tree/static_tree.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> T(Q),\
    \ U(Q), V(Q), time(2 * N, Q);\n    fill(time.begin(), time.begin() + N, -1);\n\
    \    uf_merge_tree umt(N);\n    for (int i = 0; i < Q; i++) {\n        cin >>\
    \ T[i] >> U[i] >> V[i];\n        if (T[i] == 0) {\n            int k = umt.merge(U[i],\
    \ V[i]);\n            time[k] = min(time[k], i);\n        }\n    }\n    for (int\
    \ i = 0; i < N - 1; i++) umt.merge(i, i + 1);\n    auto P = umt.parents();\n \
    \   static_tree G(P.size());\n    int rt = -1;\n    for (int i = 0; i < ssize(P);\
    \ i++) {\n        if (P[i] != -1) {\n            G.add_edge(i, P[i]);\n      \
    \  } else {\n            rt = i;\n        }\n    }\n    for (int i = 0; i < Q;\
    \ i++) {\n        if (T[i] == 1) {\n            cout << (time[G.lca(U[i], V[i],\
    \ rt)] < i) << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - src/data_structure/union_find/uf_merge_tree.hpp
  - src/data_structure/union_find/union_find.hpp
  - src/tree/static_tree.hpp
  - src/data_structure/range_query/static_rmq.hpp
  - src/data_structure/range_query/sparse_table.hpp
  - src/monoid/min.hpp
  isVerificationFile: true
  path: test/data_structure/union_find/uf_merge_tree.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 19:54:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union_find/uf_merge_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union_find/uf_merge_tree.test.cpp
- /verify/test/data_structure/union_find/uf_merge_tree.test.cpp.html
title: test/data_structure/union_find/uf_merge_tree.test.cpp
---
