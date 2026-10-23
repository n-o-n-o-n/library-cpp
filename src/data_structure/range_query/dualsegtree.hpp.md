---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/dualsegtree.test.cpp
    title: test/data_structure/range_query/dualsegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/range_query/dualsegtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename ActSet>\n\
    struct dualsegtree {\n    using M = ActSet;\n    using S = typename M::S;\n  \
    \  using F = typename M::F;\n    dualsegtree() : dualsegtree(0) {}\n    dualsegtree(int\
    \ _n) : dualsegtree(vector<S>(_n, M::e())) {}\n    dualsegtree(const vector<S>\
    \ &v) { init(v); }\n    void init(const vector<S> &v) {\n        n = v.size();\n\
    \        log = 0;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n\
    \        d = vector<S>(sz, M::e());\n        for (int i = 0; i < n; i++) d[i]\
    \ = v[i];\n        lz = vector<F>(sz, M::id());\n    }\n    void set(int p, const\
    \ S &x) {\n        assert(0 <= p && p < n);\n        inner_push(p + sz);\n   \
    \     d[p] = x;\n    }\n    void apply(int p, const F &f) {\n        assert(0\
    \ <= p && p < n);\n        p += sz;\n        inner_push(p);\n        all_apply(p,\
    \ f);\n    }\n    void apply(int l, int r, const F &f) {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        if (l == r) return;\n        l += sz, r +=\
    \ sz;\n        inner_push(l);\n        inner_push(r - 1);\n        while (l <\
    \ r) {\n            if (l & 1) all_apply(l++, f);\n            if (r & 1) all_apply(--r,\
    \ f);\n            l >>= 1;\n            r >>= 1;\n        }\n    }\n    S get(int\
    \ p) {\n        assert(0 <= p && p < n);\n        inner_push(p + sz);\n      \
    \  return d[p];\n    }\nprivate:\n    int n, log, sz;\n    vector<S> d;\n    vector<F>\
    \ lz;\n    void all_apply(int p, const F &f) {\n        if (p < sz) {\n      \
    \      lz[p] = M::comp(f, lz[p]);\n        } else {\n            d[p - sz] = M::map(f,\
    \ d[p - sz]);\n        }\n    }\n    void push(int p) {\n        all_apply(2 *\
    \ p, lz[p]);\n        all_apply(2 * p + 1, lz[p]);\n        lz[p] = M::id();\n\
    \    }\n    void inner_push(int p) {\n        for (int i = log; i >= 1; i--) push(p\
    \ >> i);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename ActSet>\nstruct dualsegtree {\n    using M = ActSet;\n   \
    \ using S = typename M::S;\n    using F = typename M::F;\n    dualsegtree() :\
    \ dualsegtree(0) {}\n    dualsegtree(int _n) : dualsegtree(vector<S>(_n, M::e()))\
    \ {}\n    dualsegtree(const vector<S> &v) { init(v); }\n    void init(const vector<S>\
    \ &v) {\n        n = v.size();\n        log = 0;\n        while ((1 << log) <\
    \ n) log++;\n        sz = 1 << log;\n        d = vector<S>(sz, M::e());\n    \
    \    for (int i = 0; i < n; i++) d[i] = v[i];\n        lz = vector<F>(sz, M::id());\n\
    \    }\n    void set(int p, const S &x) {\n        assert(0 <= p && p < n);\n\
    \        inner_push(p + sz);\n        d[p] = x;\n    }\n    void apply(int p,\
    \ const F &f) {\n        assert(0 <= p && p < n);\n        p += sz;\n        inner_push(p);\n\
    \        all_apply(p, f);\n    }\n    void apply(int l, int r, const F &f) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return;\n  \
    \      l += sz, r += sz;\n        inner_push(l);\n        inner_push(r - 1);\n\
    \        while (l < r) {\n            if (l & 1) all_apply(l++, f);\n        \
    \    if (r & 1) all_apply(--r, f);\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n    }\n    S get(int p) {\n        assert(0 <= p && p < n);\n    \
    \    inner_push(p + sz);\n        return d[p];\n    }\nprivate:\n    int n, log,\
    \ sz;\n    vector<S> d;\n    vector<F> lz;\n    void all_apply(int p, const F\
    \ &f) {\n        if (p < sz) {\n            lz[p] = M::comp(f, lz[p]);\n     \
    \   } else {\n            d[p - sz] = M::map(f, d[p - sz]);\n        }\n    }\n\
    \    void push(int p) {\n        all_apply(2 * p, lz[p]);\n        all_apply(2\
    \ * p + 1, lz[p]);\n        lz[p] = M::id();\n    }\n    void inner_push(int p)\
    \ {\n        for (int i = log; i >= 1; i--) push(p >> i);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/range_query/dualsegtree.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/range_query/dualsegtree.test.cpp
documentation_of: src/data_structure/range_query/dualsegtree.hpp
layout: document
title: Dualsegtree
---

双対セグ木. 

## Constructor

```
dualsegtree<ActSet> seg(int n)
```

- 長さ $n$ の双対セグ木を作る
- `ActSet` を定義する必要がある
    - 内部で型 `S`, 単位元 `e`, 作用素の型 `F`, 合成 `comp`, 恒等写像 `id`, 作用 `map` を定義する必要がある
    - `e` は `S` の元であればなんでもいい
    - $\text{comp}(f, g)$ は $f\circ g$ が期待される
- $O(n)$

```
dualsegtree<ActSet> seg(vector<S> v)
```

- 配列 $v$ で初期化セグ木を作る
- 長さで初期化して $1$ つずつ `set` するよりも速い
- $O(n)$

## set

```
void set(int p, S x)
```

- $p$ 番目の要素を $x$ に変更する
- $O(\log n)$

## apply

```
void apply(int p, F f)
void apply(int l, int r, F f)
```

- $p$ 番目の要素 or 半開区間 $[l,r)$ に $f$ を作用させる
- どちらも $O(\log n)$

## get

```
S get(int p)
```

- $p$ 番目の要素を返す
- $O(\log n)$
