---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/persistent_ds/persistent_segtree.test.cpp
    title: test/data_structure/persistent_ds/persistent_segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/persistent_ds/persistent_segtree.hpp\"\
    \n#include <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct persistent_segtree {\n    using M = Monoid;\n    using S = typename\
    \ M::S;\n    persistent_segtree() : persistent_segtree(0) {}\n    persistent_segtree(int\
    \ _n) : persistent_segtree(vector<S>(_n, M::e())) {}\n    persistent_segtree(const\
    \ vector<S> &v) : n(v.size()), roots(1, 1) {\n        log = 0;\n        while\
    \ ((1 << log) < n) log++;\n        sz = 1 << log;\n        make_node(-1, -1);\n\
    \        make_node(-1, -1);\n        for (int i = 2; i < 2 * sz; i++) {\n    \
    \        make_node(i / 2, !(i & 1), sz <= i && i < sz + n ? v[i - sz] : M::e());\n\
    \        }\n        if (n == 1) d[1].x = v[0];\n        for (int i = sz - 1; i\
    \ > 0; i--) update(i);\n    }\n    void reserve(int q) {\n        d.reserve(q\
    \ * log);\n        roots.reserve(q);\n    }\n    int set(int k, int p, const S\
    \ &x) {\n        assert(0 <= k && k < ssize(roots));\n        assert(0 <= p &&\
    \ p < n);\n        int res = roots.size();\n        int i = make_node(-1, -1);\n\
    \        roots.emplace_back(i);\n        d[i] = d[roots[k]];\n        set(i, roots[k],\
    \ p, x, 0, sz);\n        return res;\n    }\n    S get(int k, int p) const {\n\
    \        assert(0 <= k && k < ssize(roots));\n        assert(0 <= p && p < n);\n\
    \        return get(roots[k], p, 0, sz);\n    };\n    S prod(int k, int l, int\
    \ r) const {\n        assert(0 <= k && k < ssize(roots));\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        return prod(roots[k], l, r, 0, sz);\n    }\n\
    private:\n    int n, log, sz;\n    struct node {\n        node(const S &_x = M::e(),\
    \ int p = -1) : x(_x), par(p), l(-1), r(-1) {}\n        S x;\n        int par,\
    \ l, r;\n    };\n    vector<int> roots;\n    vector<node> d;\n    S val(int p)\
    \ const { return p == -1 ? M::e() : d[p].x; }\n    int make_node(int par, bool\
    \ is_left, const S &x = M::e()) {\n        int p = d.size();\n        d.emplace_back(x,\
    \ par);\n        d[p].par = par;\n        if (par != -1) (is_left ? d[par].l :\
    \ d[par].r) = p;\n        return p;\n    }\n    void update(int p) { d[p].x =\
    \ M::op(val(d[p].l), val(d[p].r)); }\n    void set(int i, int j, int p, const\
    \ S &x, int l, int r) {\n        if (l + 1 == r) {\n            d[i].x = x;\n\
    \            return;\n        }\n        int m = (l + r) / 2;\n        if (p <\
    \ m) {\n            int ni = make_node(i, true);\n            d[i].r = d[j].r;\n\
    \            set(ni, d[j].l, p, x, l, m);\n        } else {\n            int ni\
    \ = make_node(i, false);\n            d[i].l = d[j].l;\n            set(ni, d[j].r,\
    \ p, x, m, r);\n        }\n        update(i);\n    }\n    S get(int i, int p,\
    \ int l, int r) const {\n        if (l + 1 == r) return val(i);\n        int m\
    \ = (l + r) / 2;\n        if (p < m) return get(d[i].l, p, l, m);\n        return\
    \ get(d[i].r, p, m, r);\n    }\n    S prod(int i, int ql, int qr, int l, int r)\
    \ const {\n        if (i == -1 || qr <= l || ql >= r) return M::e();\n       \
    \ if (ql <= l && r <= qr) return val(i);\n        int m = (l + r) / 2;\n     \
    \   return M::op(prod(d[i].l, ql, qr, l, m), prod(d[i].r, ql, qr, m, r));\n  \
    \  }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct persistent_segtree {\n    using M = Monoid;\n\
    \    using S = typename M::S;\n    persistent_segtree() : persistent_segtree(0)\
    \ {}\n    persistent_segtree(int _n) : persistent_segtree(vector<S>(_n, M::e()))\
    \ {}\n    persistent_segtree(const vector<S> &v) : n(v.size()), roots(1, 1) {\n\
    \        log = 0;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n\
    \        make_node(-1, -1);\n        make_node(-1, -1);\n        for (int i =\
    \ 2; i < 2 * sz; i++) {\n            make_node(i / 2, !(i & 1), sz <= i && i <\
    \ sz + n ? v[i - sz] : M::e());\n        }\n        if (n == 1) d[1].x = v[0];\n\
    \        for (int i = sz - 1; i > 0; i--) update(i);\n    }\n    void reserve(int\
    \ q) {\n        d.reserve(q * log);\n        roots.reserve(q);\n    }\n    int\
    \ set(int k, int p, const S &x) {\n        assert(0 <= k && k < ssize(roots));\n\
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
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/persistent_ds/persistent_segtree.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/persistent_ds/persistent_segtree.test.cpp
documentation_of: src/data_structure/persistent_ds/persistent_segtree.hpp
layout: document
title: Persistent Segtree
---

永続セグ木.
初期状態の列番号は $0$.

## Constructor

```
persistent_segtree<Monoid> seg
persistent_segtree<Monoid> seg(int n)
persistent_segtree<Monoid> seg(vector<S> v)
```

- 長さ $n$ の永続セグ木を作る
- `Monoid` を定義する必要がある
    - 内部で型 `S`, 二項演算 `op`, 単位元 `e` を定義する必要がある

## reserve

```
void reserve(int q)
```

- クエリ数 $q$ に応じてメモリを確保する

## set

```
int set(int k, int p, S x)
```

- $k$ 番目の列における $p$ 番目の要素を $x$ に変更した新しい列を作り, その番号を返す
- $O(\log n)$

## get

```
S get(int k, int p)
```

- $k$ 番目の列の $p$ 番目の要素を返す
- $O(\log n)$

## prod

```
S prod(int k, int l, int r)
```

- $k$ 番目の列の区間 $[l,r)$ の総積を返す
- $O(\log n)$
