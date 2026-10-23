---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/hld.test.cpp
    title: test/tree/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/hld.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename SegTree, bool edge,\
    \ bool commutative>\nstruct heavy_light_decomposition {\n    using M = typename\
    \ SegTree::M;\n    using S = typename M::S;\n    heavy_light_decomposition() =\
    \ default;\n    heavy_light_decomposition(int _n, int _r = 0) : n(_n), r(_r),\
    \ id(0), built(false) {\n        edges.reserve(n - 1);\n        if (n <= 1) build();\n\
    \    }\n    void add_edge(int u, int v, const S &w = M::e()) {\n        assert(!built);\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(u\
    \ != v);\n        edges.emplace_back(u, v, w);\n        if (ssize(edges) + 1 ==\
    \ n) build();\n    }\n    int lca(int u, int v) {\n        assert(built);\n  \
    \      assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        while\
    \ (true) {\n            if (in[u] > in[v]) swap(u, v);\n            if (head[u]\
    \ == head[v]) return u;\n            v = par[head[v]];\n        }\n        return\
    \ -1;\n    }\n    void set(int u, const S &w) {\n        assert(built);\n    \
    \    assert(0 <= u && u < n);\n        seg.set(idx(u), w);\n    }\n    void set(int\
    \ u, int v, const S &w) {\n        assert(built);\n        assert(0 <= u && u\
    \ < n);\n        assert(0 <= v && v < n);\n        assert(u != v);\n        seg.set(idx(u,\
    \ v), w);\n    }\n    template<typename F>\n    void apply(int u, int v, const\
    \ F &f) {\n        assert(built);\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n        for (auto [l, r] : path_decompose(u, v)) {\n      \
    \      if (l > r) swap(l, r);\n            seg.apply(l, r, f);\n        }\n  \
    \  }\n    template<typename F>\n    void subtree_apply(int u, const F &f) {\n\
    \        assert(built);\n        assert(0 <= u && u < n);\n        seg.apply(in[u]\
    \ + edge, out[u], f);\n    }\n    S get(int u) {\n        assert(built);\n   \
    \     assert(0 <= u && u < n);\n        return seg.get(idx(u));\n    }\n    S\
    \ get(int u, int v) {\n        assert(built);\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        assert(u != v);\n        return seg.get(idx(u,\
    \ v));\n    }\n    S prod(int u, int v) {\n        assert(built);\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        S p = M::e();\n \
    \       for (auto [l, r] : path_decompose(u, v)) {\n            p = M::op(p, inner_prod(l,\
    \ r));\n        }\n        return p;\n    }\n    S subtree_prod(int u) {\n   \
    \     assert(built);\n        assert(0 <= u && u < n);\n        return seg.prod(in[u]\
    \ + edge, out[u]);\n    }\n    template<typename C>\n    int binary_search(int\
    \ u, int v, const C &check) {\n        assert(built);\n        assert(0 <= u &&\
    \ u < n);\n        assert(0 <= v && v < n);\n        S p = M::e();\n        for\
    \ (auto [l, r] : path_decompose(u, v)) {\n            S np = M::op(p, inner_prod(l,\
    \ r));\n            if (l < r) {\n                if (!check(np)) {\n        \
    \            return check(M::op(p, seg.get(l))) ? inv[\n                     \
    \   (commutative ? seg.max_right(l, [&](const S &x) {\n                      \
    \      return check(M::op(p, x));\n                        }) : seg.max_right(l,\
    \ false, [&](const S &x) {\n                            return check(M::op(p,\
    \ x));\n                        })) - 1\n                    ] : u;\n        \
    \        }\n                p = np;\n                u = inv[r - 1];\n       \
    \     } else {\n                swap(l, r);\n                if (!check(np)) {\n\
    \                    return check(M::op(p, seg.get(r - 1))) ? inv[\n         \
    \               commutative ? seg.min_left(r, [&](const S &x) {\n            \
    \                return check(M::op(p, x));\n                        }) : seg.min_left(r,\
    \ true, [&](const S &x) {\n                            return check(M::op(p, x));\n\
    \                        })\n                    ] : u;\n                }\n \
    \               p = np;\n                u = inv[l];\n            }\n        }\n\
    \        return v;\n    }\nprivate:\n    int n, r, id;\n    bool built;\n    SegTree\
    \ seg;\n    vector<vector<int>> g;\n    vector<int> sub, depth, par, in, out,\
    \ inv, head, heavy;\n    vector<tuple<int, int, S>> edges;\n    int idx(int u)\
    \ const {\n        assert(built);\n        return in[u];\n    }\n    int idx(int\
    \ u, int v) const {\n        assert(built);\n        return max(in[u], in[v]);\n\
    \    }\n    S inner_prod(int l, int r) {\n        if (commutative && l > r) swap(l,\
    \ r);\n        return seg.prod(l, r);\n    }\n    void dfs(int u, int p) {\n \
    \       par[u] = p;\n        sub[u] = 1;\n        int sub_max = 0;\n        for\
    \ (int v : g[u]) {\n            if (v != p) {\n                dfs(v, u);\n  \
    \              sub[u] += sub[v];\n                if (sub[v] > sub_max) {\n  \
    \                  sub_max = sub[v];\n                    heavy[u] = v;\n    \
    \            }\n            }\n        }\n    }\n    void decompose(int u, int\
    \ h) {\n        head[u] = h;\n        in[u] = id++;\n        inv[in[u]] = u;\n\
    \        if (heavy[u] != -1) decompose(heavy[u], h);\n        for (int v : g[u])\
    \ {\n            if (v != par[u] && v != heavy[u]) {\n                decompose(v,\
    \ v);\n            }\n        }\n        out[u] = id;\n    }\n    void build()\
    \ {\n        g = vector<vector<int>>(n);\n        sub = depth = in = inv = out\
    \ = head = vector<int>(n);\n        par = heavy = vector<int>(n, -1);\n      \
    \  for (const auto &[u, v, _] : edges) {\n            g[u].emplace_back(v);\n\
    \            g[v].emplace_back(u);\n        }\n        dfs(r, r);\n        decompose(r,\
    \ r);\n        built = true;\n        if (edge) {\n            vector<S> a(n,\
    \ M::e());\n            for (const auto &[u, v, w] : edges) {\n              \
    \  a[idx(u, v)] = w;\n            }\n            seg = SegTree(a);\n        }\
    \ else {\n            seg = SegTree(n);\n        }\n    }\n    vector<pair<int,\
    \ int>> path_decompose(int u, int v) const {\n        assert(built);\n       \
    \ assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        int hu =\
    \ head[u], hv = head[v];\n        vector<pair<int, int>> resl, resr;\n       \
    \ bool flip = true;\n        while (hu != hv) {\n            if (in[hu] > in[hv])\
    \ {\n                flip = !flip;\n                swap(u, v);\n            \
    \    swap(hu, hv);\n                swap(resl, resr);\n            }\n       \
    \     resl.emplace_back(in[hv], in[v] + 1);\n            v = par[hv];\n      \
    \      hu = head[u];\n            hv = head[v];\n        }\n        if (in[u]\
    \ > in[v]) {\n            flip = !flip;\n            swap(u, v);\n           \
    \ swap(resl, resr);\n        }\n        resl.emplace_back(in[u] + edge, in[v]\
    \ + 1);\n        if (flip) swap(resl, resr);\n        reverse(resr.begin(), resr.end());\n\
    \        vector<pair<int, int>> res;\n        for (auto [l, r] : resl) res.emplace_back(r,\
    \ l);\n        for (auto [l, r] : resr) res.emplace_back(l, r);\n        return\
    \ res;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename SegTree, bool edge, bool commutative>\n\
    struct heavy_light_decomposition {\n    using M = typename SegTree::M;\n    using\
    \ S = typename M::S;\n    heavy_light_decomposition() = default;\n    heavy_light_decomposition(int\
    \ _n, int _r = 0) : n(_n), r(_r), id(0), built(false) {\n        edges.reserve(n\
    \ - 1);\n        if (n <= 1) build();\n    }\n    void add_edge(int u, int v,\
    \ const S &w = M::e()) {\n        assert(!built);\n        assert(0 <= u && u\
    \ < n);\n        assert(0 <= v && v < n);\n        assert(u != v);\n        edges.emplace_back(u,\
    \ v, w);\n        if (ssize(edges) + 1 == n) build();\n    }\n    int lca(int\
    \ u, int v) {\n        assert(built);\n        assert(0 <= u && u < n);\n    \
    \    assert(0 <= v && v < n);\n        while (true) {\n            if (in[u] >\
    \ in[v]) swap(u, v);\n            if (head[u] == head[v]) return u;\n        \
    \    v = par[head[v]];\n        }\n        return -1;\n    }\n    void set(int\
    \ u, const S &w) {\n        assert(built);\n        assert(0 <= u && u < n);\n\
    \        seg.set(idx(u), w);\n    }\n    void set(int u, int v, const S &w) {\n\
    \        assert(built);\n        assert(0 <= u && u < n);\n        assert(0 <=\
    \ v && v < n);\n        assert(u != v);\n        seg.set(idx(u, v), w);\n    }\n\
    \    template<typename F>\n    void apply(int u, int v, const F &f) {\n      \
    \  assert(built);\n        assert(0 <= u && u < n);\n        assert(0 <= v &&\
    \ v < n);\n        for (auto [l, r] : path_decompose(u, v)) {\n            if\
    \ (l > r) swap(l, r);\n            seg.apply(l, r, f);\n        }\n    }\n   \
    \ template<typename F>\n    void subtree_apply(int u, const F &f) {\n        assert(built);\n\
    \        assert(0 <= u && u < n);\n        seg.apply(in[u] + edge, out[u], f);\n\
    \    }\n    S get(int u) {\n        assert(built);\n        assert(0 <= u && u\
    \ < n);\n        return seg.get(idx(u));\n    }\n    S get(int u, int v) {\n \
    \       assert(built);\n        assert(0 <= u && u < n);\n        assert(0 <=\
    \ v && v < n);\n        assert(u != v);\n        return seg.get(idx(u, v));\n\
    \    }\n    S prod(int u, int v) {\n        assert(built);\n        assert(0 <=\
    \ u && u < n);\n        assert(0 <= v && v < n);\n        S p = M::e();\n    \
    \    for (auto [l, r] : path_decompose(u, v)) {\n            p = M::op(p, inner_prod(l,\
    \ r));\n        }\n        return p;\n    }\n    S subtree_prod(int u) {\n   \
    \     assert(built);\n        assert(0 <= u && u < n);\n        return seg.prod(in[u]\
    \ + edge, out[u]);\n    }\n    template<typename C>\n    int binary_search(int\
    \ u, int v, const C &check) {\n        assert(built);\n        assert(0 <= u &&\
    \ u < n);\n        assert(0 <= v && v < n);\n        S p = M::e();\n        for\
    \ (auto [l, r] : path_decompose(u, v)) {\n            S np = M::op(p, inner_prod(l,\
    \ r));\n            if (l < r) {\n                if (!check(np)) {\n        \
    \            return check(M::op(p, seg.get(l))) ? inv[\n                     \
    \   (commutative ? seg.max_right(l, [&](const S &x) {\n                      \
    \      return check(M::op(p, x));\n                        }) : seg.max_right(l,\
    \ false, [&](const S &x) {\n                            return check(M::op(p,\
    \ x));\n                        })) - 1\n                    ] : u;\n        \
    \        }\n                p = np;\n                u = inv[r - 1];\n       \
    \     } else {\n                swap(l, r);\n                if (!check(np)) {\n\
    \                    return check(M::op(p, seg.get(r - 1))) ? inv[\n         \
    \               commutative ? seg.min_left(r, [&](const S &x) {\n            \
    \                return check(M::op(p, x));\n                        }) : seg.min_left(r,\
    \ true, [&](const S &x) {\n                            return check(M::op(p, x));\n\
    \                        })\n                    ] : u;\n                }\n \
    \               p = np;\n                u = inv[l];\n            }\n        }\n\
    \        return v;\n    }\nprivate:\n    int n, r, id;\n    bool built;\n    SegTree\
    \ seg;\n    vector<vector<int>> g;\n    vector<int> sub, depth, par, in, out,\
    \ inv, head, heavy;\n    vector<tuple<int, int, S>> edges;\n    int idx(int u)\
    \ const {\n        assert(built);\n        return in[u];\n    }\n    int idx(int\
    \ u, int v) const {\n        assert(built);\n        return max(in[u], in[v]);\n\
    \    }\n    S inner_prod(int l, int r) {\n        if (commutative && l > r) swap(l,\
    \ r);\n        return seg.prod(l, r);\n    }\n    void dfs(int u, int p) {\n \
    \       par[u] = p;\n        sub[u] = 1;\n        int sub_max = 0;\n        for\
    \ (int v : g[u]) {\n            if (v != p) {\n                dfs(v, u);\n  \
    \              sub[u] += sub[v];\n                if (sub[v] > sub_max) {\n  \
    \                  sub_max = sub[v];\n                    heavy[u] = v;\n    \
    \            }\n            }\n        }\n    }\n    void decompose(int u, int\
    \ h) {\n        head[u] = h;\n        in[u] = id++;\n        inv[in[u]] = u;\n\
    \        if (heavy[u] != -1) decompose(heavy[u], h);\n        for (int v : g[u])\
    \ {\n            if (v != par[u] && v != heavy[u]) {\n                decompose(v,\
    \ v);\n            }\n        }\n        out[u] = id;\n    }\n    void build()\
    \ {\n        g = vector<vector<int>>(n);\n        sub = depth = in = inv = out\
    \ = head = vector<int>(n);\n        par = heavy = vector<int>(n, -1);\n      \
    \  for (const auto &[u, v, _] : edges) {\n            g[u].emplace_back(v);\n\
    \            g[v].emplace_back(u);\n        }\n        dfs(r, r);\n        decompose(r,\
    \ r);\n        built = true;\n        if (edge) {\n            vector<S> a(n,\
    \ M::e());\n            for (const auto &[u, v, w] : edges) {\n              \
    \  a[idx(u, v)] = w;\n            }\n            seg = SegTree(a);\n        }\
    \ else {\n            seg = SegTree(n);\n        }\n    }\n    vector<pair<int,\
    \ int>> path_decompose(int u, int v) const {\n        assert(built);\n       \
    \ assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        int hu =\
    \ head[u], hv = head[v];\n        vector<pair<int, int>> resl, resr;\n       \
    \ bool flip = true;\n        while (hu != hv) {\n            if (in[hu] > in[hv])\
    \ {\n                flip = !flip;\n                swap(u, v);\n            \
    \    swap(hu, hv);\n                swap(resl, resr);\n            }\n       \
    \     resl.emplace_back(in[hv], in[v] + 1);\n            v = par[hv];\n      \
    \      hu = head[u];\n            hv = head[v];\n        }\n        if (in[u]\
    \ > in[v]) {\n            flip = !flip;\n            swap(u, v);\n           \
    \ swap(resl, resr);\n        }\n        resl.emplace_back(in[u] + edge, in[v]\
    \ + 1);\n        if (flip) swap(resl, resr);\n        reverse(resr.begin(), resr.end());\n\
    \        vector<pair<int, int>> res;\n        for (auto [l, r] : resl) res.emplace_back(r,\
    \ l);\n        for (auto [l, r] : resr) res.emplace_back(l, r);\n        return\
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/hld.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/hld.test.cpp
documentation_of: src/tree/hld.hpp
layout: document
title: Heavy Light Decomposition
---

木に対するパスクエリを扱う.

以下の計算量は `SegTree` 内部での計算量を無視している(例えば, 通常のセグ木で `prod` を呼ぶと $O(\log^2 n)$).

## Constructor

```
heavy_light_decomposition<SegTree, edge, commutative> G(int n, int r = 0)
```

- $n$ 頂点の木を根 $r$ で初期化する
- `SegTree` は型 `M` と点更新, 点取得, 区間積を持つセグ木とする
- `edge` $=$ `false` は頂点に値を持ち, `edge` $=$ `true` は辺に値を持つ
- `commutative` $=$ `false` では非可換クエリを扱える

## add_edge

```
void add_edge(int u, int v, S w = M::e())
```

- $u$ と $v$ の間に辺を追加する
- `edge` $=$ `true` のとき, 辺の初期値に $w$ を使う
- ちょうど $n-1$ 回呼ばれる必要がある
- 最後の辺の追加時に構築され, $O(n)$
- それ以外の追加は $O(1)$

## lca

```
int lca(int u, int v)
```

- 頂点 $u$ と $v$ の LCA を返す
- $O(\log n)$

## set

```
void set(int u, S w)
void set(int u, int v, S w)
```

- 頂点 $u$ の形式では, その頂点の位置にある値を $w$ に設定する
- 辺 $(u, v)$ の形式では, 隣接する $u, v$ を結ぶ辺の値を $w$ に設定する
- $O(1)$

## get

```
S get(int u)
S get(int u, int v)
```

- 頂点 $u$ の形式では, その頂点の位置にある値を返す
- 辺 $(u, v)$ の形式では, 隣接する $u, v$ を結ぶ辺の値を返す
- $O(1)$

## apply, subtree_apply

```
void apply(int u, int v, f)
void subtree_apply(int u, f)
```

- `apply` はパス $u$ から $v$ に `f` を適用する
- `f` には区間更新を表すラムダ式などを渡す
- `subtree_apply` は根 $r$ に関する頂点 $u$ の部分木に `f` を適用する
- `edge` $=$ `true` では, パスと部分木に含まれる辺に適用する
- `SegTree` が区間 `apply` に対応する必要がある
- `apply` は $O(\log n)$, `subtree_apply` は $O(1)$

## prod, subtree_prod

```
S prod(int u, int v)
S subtree_prod(int u)
```

- `prod` はパス $u$ から $v$ の値の積を, その向きの順序で返す
- `subtree_prod` は根 $r$ に関する頂点 $u$ の部分木の値の積を返す
- `edge` $=$ `true` では対象となる辺の値の積を返す
- `prod` は $O(\log n)$, `subtree_prod` は $O(1)$

## binary_search

```
int binary_search(int u, int v, check)
```

- パス上の二分探索を行う
- 全体が条件を満たす場合は $v$ を返す
- `check(M::e())` は `true` である必要がある
- $O(\log n)$
