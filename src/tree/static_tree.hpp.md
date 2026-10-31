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
    path: src/monoid/min.hpp
    title: src/monoid/min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/static_tree.jump.test.cpp
    title: test/tree/static_tree.jump.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/static_tree.lca.test.cpp
    title: test/tree/static_tree.lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/static_tree.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iostream>\n#include <stack>\n#include <vector>\nusing namespace\
    \ std;\n#line 3 \"src/data_structure/range_query/static_rmq.hpp\"\n#include <limits>\n\
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
    \    built = true;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n\
    #include <stack>\n#include <vector>\nusing namespace std;\n#include \"../data_structure/range_query/static_rmq.hpp\"\
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
    \    built = true;\n    }\n};"
  dependsOn:
  - src/data_structure/range_query/static_rmq.hpp
  - src/data_structure/range_query/sparse_table.hpp
  - src/monoid/min.hpp
  isVerificationFile: false
  path: src/tree/static_tree.hpp
  requiredBy: []
  timestamp: '2026-10-31 13:28:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/static_tree.lca.test.cpp
  - test/tree/static_tree.jump.test.cpp
documentation_of: src/tree/static_tree.hpp
layout: document
title: Static Tree
---

静的な木の LCA, 距離, パス, 部分木などを扱う.
辺は単位重みを持つとする.

## Constructor

```
static_tree G(int n, int r = 0)
```

- $n$ 頂点の木を根 $r$ で初期化する
- $O(n)$

## add_edge

```
void add_edge(int u, int v)
```

- 頂点 $u$ と $v$ を辺で結ぶ
- ちょうど $n-1$ 回呼ばれる必要がある
- 通常は $O(1)$, 最後の追加時は $O(n)$

## read_edges

```
void read_edges(bool idx = 1)
```

- 標準入力から $n-1$ 本の辺を読み込み, 前処理を行う
- `idx = 1` なら入力を $1$-indexed, `idx = 0` なら $0$-indexed として扱う
- $O(n)$

## set_root

```
void set_root(int r)
```

- $n-1$ 本の辺を追加した後, 根を $r$ に変更して前処理をやり直す
- $O(n)$

## operator[]

```
vector<int> operator[](int u)
```

- 元の木で頂点 $u$ に隣接する頂点のリストを返す
- $O(1)$

## depth

```
int depth(int u)
```

- 現在の根から頂点 $u$ までの辺数を返す
- $O(1)$

## lca

```
int lca(int u, int v, int r = -1)
```

- 頂点 $u$ と $v$ の LCA を返す
- $r$ を指定した場合は, 木の根を $r$ とみなしたときの LCA を返す
- $r = -1$ の場合は現在の根を使う
- $O(1)$

## dist

```
int dist(int u, int v)
```

- 頂点 $u$ と $v$ の距離を辺数で返す
- $O(1)$

## jump

```
int jump(int u, int v, int k)
```

- $k \ge 0$ とし, パス $u$ から $v$ に沿って $u$ から $k$ 辺進んだ頂点を返す
- $k = 0$ なら $u$ を返し, $k$ が距離を超えると $-1$ を返す
- $O(\log n)$

## is_on_path

```
bool is_on_path(int w, int u, int v)
```

- 頂点 $w$ がパス $u$ から $v$ 上にあるかを返す
- 両端点もパス上に含む
- $O(1)$

## sub_size

```
int sub_size(int u, int r = -1)
```

- 木の根を $r$ とみなしたときの頂点 $u$ の部分木の頂点数を返す
- $r = -1$ の場合は現在の根を使う
- $O(1)$

## path

```
vector<int> path(int u, int v)
```

- パス $u$ から $v$ 上の頂点を順に返す
- 返り値には $u$ と $v$ も含む
- パスの頂点数を $k$ として $O(k)$

## auxiliary_tree

```
vector<pair<int, int>> auxiliary_tree(vector<int> vs)
```

- `vs` の頂点と必要な LCA からなる補助木の辺を返す
- 返り値は, 元の木の頂点番号で子と親を組にしたもの
- `vs` に含まれる頂点数を $k$ として $O(k\log k)$
