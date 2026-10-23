---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/dynamic_lazysegtree.test.cpp
    title: test/data_structure/range_query/dynamic_lazysegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/range_query/dynamic_lazysegtree.hpp\"\
    \n#include <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ ActMonoid, integral T = int>\nstruct dynamic_lazysegtree {\n    using M = ActMonoid;\n\
    \    using S = typename M::S;\n    using F = typename M::F;\n    dynamic_lazysegtree(T\
    \ _n = 0, int q = 0) : n(_n) {\n        int log = 1;\n        while ((T(1) <<\
    \ log) < n) log++;\n        d.reserve(1 + 2 * q * log);\n        root = new_node(0,\
    \ n);\n    }\n    void set(T p, const S &x) {\n        assert(0 <= p && p < n);\n\
    \        set(root, 0, n, p, x);\n    }\n    void apply(T l, T r, const F &f) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        apply(root, 0, n, l, r,\
    \ f);\n    }\n    S get(T p) {\n        assert(0 <= p && p < n);\n        return\
    \ get(root, 0, n, p);\n    }\n    S prod(T l, T r) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        return prod(root, 0, n, l, r);\n    }\n    S all_prod()\
    \ const {\n        return d[root].x;\n    }\nprivate:\n    struct node {\n   \
    \     S x;\n        F lz;\n        int l, r;\n        node() : node(M::e()) {}\n\
    \        node(const S &_x) : x(_x), lz(M::id()), l(-1), r(-1) {}\n    };\n   \
    \ T n;\n    int root;\n    vector<node> d;\n    int new_node(T l, T r) {\n   \
    \     int res = d.size();\n        d.emplace_back(M::init(l, r));\n        return\
    \ res;\n    }\n    void update(int t) {\n        int l = d[t].l, r = d[t].r;\n\
    \        const S pl = l == -1 ? M::e() : d[l].x;\n        const S pr = r == -1\
    \ ? M::e() : d[r].x;\n        d[t].x = M::op(pl, pr);\n    }\n    void all_apply(int\
    \ t, const F &f) {\n        if (t == -1) return;\n        d[t].x = M::map(f, d[t].x);\n\
    \        d[t].lz = M::comp(f, d[t].lz);\n    }\n    void push(int t, T l, T r)\
    \ {\n        T m = (l + r) / 2;\n        if (d[t].l == -1) d[t].l = new_node(l,\
    \ m);\n        if (d[t].r == -1) d[t].r = new_node(m, r);\n        all_apply(d[t].l,\
    \ d[t].lz);\n        all_apply(d[t].r, d[t].lz);\n        d[t].lz = M::id();\n\
    \    }\n    void set(int t, T l, T r, T p, const S &x) {\n        if (l + 1 ==\
    \ r) {\n            d[t].x = x;\n            return;\n        }\n        push(t,\
    \ l, r);\n        T m = (l + r) / 2;\n        p < m ? set(d[t].l, l, m, p, x)\
    \ : set(d[t].r, m, r, p, x);\n        update(t);\n    }\n    void apply(int t,\
    \ T l, T r, T ql, T qr, const F &f) {\n        if (r <= ql || qr <= l) return;\n\
    \        if (ql <= l && r <= qr) {\n            all_apply(t, f);\n           \
    \ return;\n        }\n        push(t, l, r);\n        T m = (l + r) / 2;\n   \
    \     apply(d[t].l, l, m, ql, qr, f);\n        apply(d[t].r, m, r, ql, qr, f);\n\
    \        update(t);\n    }\n    S get(int t, T l, T r, T p) {\n        if (t ==\
    \ -1) return M::e();\n        if (l + 1 == r) return d[t].x;\n        push(t,\
    \ l, r);\n        T m = (l + r) / 2;\n        return p < m ? get(d[t].l, l, m,\
    \ p) : get(d[t].r, m, r, p);\n    }\n    S prod(int t, T l, T r, T ql, T qr) {\n\
    \        if (t == -1 || r <= ql || qr <= l) return M::e();\n        if (ql <=\
    \ l && r <= qr) return d[t].x;\n        push(t, l, r);\n        T m = (l + r)\
    \ / 2;\n        return M::op(prod(d[t].l, l, m, ql, qr), prod(d[t].r, m, r, ql,\
    \ qr));\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename ActMonoid, integral T = int>\nstruct dynamic_lazysegtree {\n\
    \    using M = ActMonoid;\n    using S = typename M::S;\n    using F = typename\
    \ M::F;\n    dynamic_lazysegtree(T _n = 0, int q = 0) : n(_n) {\n        int log\
    \ = 1;\n        while ((T(1) << log) < n) log++;\n        d.reserve(1 + 2 * q\
    \ * log);\n        root = new_node(0, n);\n    }\n    void set(T p, const S &x)\
    \ {\n        assert(0 <= p && p < n);\n        set(root, 0, n, p, x);\n    }\n\
    \    void apply(T l, T r, const F &f) {\n        assert(0 <= l && l <= r && r\
    \ <= n);\n        apply(root, 0, n, l, r, f);\n    }\n    S get(T p) {\n     \
    \   assert(0 <= p && p < n);\n        return get(root, 0, n, p);\n    }\n    S\
    \ prod(T l, T r) {\n        assert(0 <= l && l <= r && r <= n);\n        return\
    \ prod(root, 0, n, l, r);\n    }\n    S all_prod() const {\n        return d[root].x;\n\
    \    }\nprivate:\n    struct node {\n        S x;\n        F lz;\n        int\
    \ l, r;\n        node() : node(M::e()) {}\n        node(const S &_x) : x(_x),\
    \ lz(M::id()), l(-1), r(-1) {}\n    };\n    T n;\n    int root;\n    vector<node>\
    \ d;\n    int new_node(T l, T r) {\n        int res = d.size();\n        d.emplace_back(M::init(l,\
    \ r));\n        return res;\n    }\n    void update(int t) {\n        int l =\
    \ d[t].l, r = d[t].r;\n        const S pl = l == -1 ? M::e() : d[l].x;\n     \
    \   const S pr = r == -1 ? M::e() : d[r].x;\n        d[t].x = M::op(pl, pr);\n\
    \    }\n    void all_apply(int t, const F &f) {\n        if (t == -1) return;\n\
    \        d[t].x = M::map(f, d[t].x);\n        d[t].lz = M::comp(f, d[t].lz);\n\
    \    }\n    void push(int t, T l, T r) {\n        T m = (l + r) / 2;\n       \
    \ if (d[t].l == -1) d[t].l = new_node(l, m);\n        if (d[t].r == -1) d[t].r\
    \ = new_node(m, r);\n        all_apply(d[t].l, d[t].lz);\n        all_apply(d[t].r,\
    \ d[t].lz);\n        d[t].lz = M::id();\n    }\n    void set(int t, T l, T r,\
    \ T p, const S &x) {\n        if (l + 1 == r) {\n            d[t].x = x;\n   \
    \         return;\n        }\n        push(t, l, r);\n        T m = (l + r) /\
    \ 2;\n        p < m ? set(d[t].l, l, m, p, x) : set(d[t].r, m, r, p, x);\n   \
    \     update(t);\n    }\n    void apply(int t, T l, T r, T ql, T qr, const F &f)\
    \ {\n        if (r <= ql || qr <= l) return;\n        if (ql <= l && r <= qr)\
    \ {\n            all_apply(t, f);\n            return;\n        }\n        push(t,\
    \ l, r);\n        T m = (l + r) / 2;\n        apply(d[t].l, l, m, ql, qr, f);\n\
    \        apply(d[t].r, m, r, ql, qr, f);\n        update(t);\n    }\n    S get(int\
    \ t, T l, T r, T p) {\n        if (t == -1) return M::e();\n        if (l + 1\
    \ == r) return d[t].x;\n        push(t, l, r);\n        T m = (l + r) / 2;\n \
    \       return p < m ? get(d[t].l, l, m, p) : get(d[t].r, m, r, p);\n    }\n \
    \   S prod(int t, T l, T r, T ql, T qr) {\n        if (t == -1 || r <= ql || qr\
    \ <= l) return M::e();\n        if (ql <= l && r <= qr) return d[t].x;\n     \
    \   push(t, l, r);\n        T m = (l + r) / 2;\n        return M::op(prod(d[t].l,\
    \ l, m, ql, qr), prod(d[t].r, m, r, ql, qr));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/range_query/dynamic_lazysegtree.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/range_query/dynamic_lazysegtree.test.cpp
documentation_of: src/data_structure/range_query/dynamic_lazysegtree.hpp
layout: document
title: Lazysegtree
---

動的遅延セグ木. 

## Constructor

```
lazysegtree<ActMonoid, T = int> seg(T n, int q = 0)
```

- 長さ $n$ の遅延セグ木を作る
- `ActMonoid` を定義する必要がある
    - 内部で型 `S`, 二項演算 `op`, 単位元 `e`, 作用素の型 `F`, 合成 `comp`, 恒等写像 `id`, 作用 `map`, `init` を定義する必要がある
    - $\text{comp}(f, g)$ は $f\circ g$ が期待される
- `S init(T l, T r)` は半開区間 $[l,r)$ の初期状態での総積を返す
- $q$ を指定すると `reserve` するので少し定数倍がよくなる
- $O(1)$

## set

```
void set(T p, S x)
```

- $p$ 番目の要素を $x$ に変更する
- $O(\log n)$

## apply

```
void apply(T l, T r, F f)
```

- 半開区間 $[l,r)$ に $f$ を作用させる
- どちらも $O(\log n)$

## get

```
S get(T p)
```

- $p$ 番目の要素を返す
- $O(\log n)$

## prod

```
S prod(T l, T r)
```

- 半開区間 $[l, r)$ に対する総積を計算する
- $O(\log n)$

## all_prod

```
S all_prod()
```

- 全体の総積を返す
- $O(1)$
