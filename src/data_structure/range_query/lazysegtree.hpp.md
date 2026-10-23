---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rectangle_query/rectangle_union.hpp
    title: src/data_structure/rectangle_query/rectangle_union.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/lazysegtree.test.cpp
    title: test/data_structure/range_query/lazysegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/rectangle_query/rectangle_union.test.cpp
    title: test/data_structure/rectangle_query/rectangle_union.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/range_query/lazysegtree.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nusing namespace std;\n\ntemplate<typename ActMonoid>\n\
    struct lazysegtree {\n    using M = ActMonoid;\n    using S = typename M::S;\n\
    \    using F = typename M::F;\n    lazysegtree() : lazysegtree(0) {}\n    lazysegtree(int\
    \ _n) : lazysegtree(vector<S>(_n, M::e())) {}\n    lazysegtree(const vector<S>\
    \ &v) { init(v); }\n    void set(const vector<S> &v) { init(v); }\n    void set(int\
    \ p, const S &x) {\n        assert(0 <= p && p < n);\n        p += sz;\n     \
    \   inner_push(p);\n        d[p] = x;\n        inner_update(p);\n    }\n    void\
    \ apply(int p, const F &f) {\n        assert(0 <= p && p < n);\n        p += sz;\n\
    \        inner_push(p);\n        d[p] = M::map(f, d[p]);\n        inner_update(p);\n\
    \    }\n    void apply(int l, int r, const F &f) {\n        assert(0 <= l && l\
    \ <=r && r <= n);\n        l += sz;\n        r += sz;\n        for (int i = log;\
    \ i >= 1; i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n      \
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n        int l2\
    \ = l, r2 = r;\n        while (l < r) {\n            if (l & 1) all_apply(l++,\
    \ f);\n            if (r & 1) all_apply(--r, f);\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n        l = l2, r = r2;\n        for (int i = 1;\
    \ i <= log; i++) {\n            if (((l >> i) << i) != l) update(l >> i);\n  \
    \          if (((r >> i) << i) != r) update((r - 1) >> i);\n        }\n    }\n\
    \    S get(int p) {\n        assert(0 <= p && p < n);\n        p += sz;\n    \
    \    inner_push(p);\n        return d[p];\n    }\n    S prod(int l, int r) {\n\
    \        assert(0 <= l && l <=r && r <= n);\n        l += sz;\n        r += sz;\n\
    \        for (int i = log; i >= 1; i--) {\n            if (((l >> i) << i) !=\
    \ l) push(l >> i);\n            if (((r >> i) << i) != r) push((r - 1) >> i);\n\
    \        }\n        S pl = M::e(), pr = M::e();\n        while (l < r) {\n   \
    \         if (l & 1) pl = M::op(pl, d[l++]);\n            if (r & 1) pr = M::op(d[--r],\
    \ pr);\n            l >>= 1;\n            r >>= 1;\n        }\n        return\
    \ M::op(pl, pr);\n    }\n    S all_prod() const { return d[1]; }\n    template<typename\
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
    \        for (int i = log; i >= 1; i--) push(p >> i);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename ActMonoid>\nstruct lazysegtree {\n    using M = ActMonoid;\n\
    \    using S = typename M::S;\n    using F = typename M::F;\n    lazysegtree()\
    \ : lazysegtree(0) {}\n    lazysegtree(int _n) : lazysegtree(vector<S>(_n, M::e()))\
    \ {}\n    lazysegtree(const vector<S> &v) { init(v); }\n    void set(const vector<S>\
    \ &v) { init(v); }\n    void set(int p, const S &x) {\n        assert(0 <= p &&\
    \ p < n);\n        p += sz;\n        inner_push(p);\n        d[p] = x;\n     \
    \   inner_update(p);\n    }\n    void apply(int p, const F &f) {\n        assert(0\
    \ <= p && p < n);\n        p += sz;\n        inner_push(p);\n        d[p] = M::map(f,\
    \ d[p]);\n        inner_update(p);\n    }\n    void apply(int l, int r, const\
    \ F &f) {\n        assert(0 <= l && l <=r && r <= n);\n        l += sz;\n    \
    \    r += sz;\n        for (int i = log; i >= 1; i--) {\n            if (((l >>\
    \ i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r) push((r\
    \ - 1) >> i);\n        }\n        int l2 = l, r2 = r;\n        while (l < r) {\n\
    \            if (l & 1) all_apply(l++, f);\n            if (r & 1) all_apply(--r,\
    \ f);\n            l >>= 1;\n            r >>= 1;\n        }\n        l = l2,\
    \ r = r2;\n        for (int i = 1; i <= log; i++) {\n            if (((l >> i)\
    \ << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n    S get(int p) {\n        assert(0 <= p &&\
    \ p < n);\n        p += sz;\n        inner_push(p);\n        return d[p];\n  \
    \  }\n    S prod(int l, int r) {\n        assert(0 <= l && l <=r && r <= n);\n\
    \        l += sz;\n        r += sz;\n        for (int i = log; i >= 1; i--) {\n\
    \            if (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n        }\n        S pl = M::e(), pr = M::e();\n\
    \        while (l < r) {\n            if (l & 1) pl = M::op(pl, d[l++]);\n   \
    \         if (r & 1) pr = M::op(d[--r], pr);\n            l >>= 1;\n         \
    \   r >>= 1;\n        }\n        return M::op(pl, pr);\n    }\n    S all_prod()\
    \ const { return d[1]; }\n    template<typename C>\n    int max_right(int l, const\
    \ C &check) {\n        assert(0 <= l && l <= n);\n        assert(check(M::e()));\n\
    \        if (l == n) return l;\n        l += sz;\n        inner_push(l);\n   \
    \     S p = M::e();\n        do {\n            while (!(l & 1)) l >>= 1;\n   \
    \         S np = M::op(p, d[l]);\n            if (!check(np)) {\n            \
    \    while (l < sz) {\n                    push(l);\n                    l <<=\
    \ 1;\n                    np = M::op(p, d[l]);\n                    if (check(np))\
    \ {\n                        p = np;\n                        l++;\n         \
    \           }\n                }\n                return l - sz;\n           \
    \ }\n            p = np;\n            l++;\n        } while ((l & -l) != l);\n\
    \        return n;\n    }\n    template<typename C>\n    int max_right(const C\
    \ &check) {\n        return max_right(0, check);\n    }\n    template<typename\
    \ C>\n    int min_left(int r, const C &check) {\n        assert(0 <= r && r <=\
    \ n);\n        assert(check(M::e()));\n        if (r == 0) return 0;\n       \
    \ r += sz;\n        inner_push(r - 1);\n        S p = M::e();\n        do {\n\
    \            r--;\n            while (r > 1 && r & 1) r >>= 1;\n            S\
    \ np = M::op(d[r], p);\n            if (!check(np)) {\n                while (r\
    \ < sz) {\n                    push(r);\n                    (r <<= 1)++;\n  \
    \                  np = M::op(d[r], p);\n                    if (check(np)) {\n\
    \                        p = np;\n                        r--;\n             \
    \       }\n                }\n                return r + 1 - sz;\n           \
    \ }\n            p = np;\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n    template<typename C>\n    int min_left(const C &check) {\n       \
    \ return min_left(n, check);\n    }\nprivate:\n    int n, log, sz;\n    vector<S>\
    \ d;\n    vector<F> lz;\n    void init(const vector<S> &v) {\n        n = v.size();\n\
    \        log = 1;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n\
    \        d = vector<S>(2 * sz, M::e());\n        lz = vector<F>(sz, M::id());\n\
    \        for (int i = 0; i < n; i++) d[i + sz] = v[i];\n        for (int i = sz\
    \ - 1; i >= 1; i--) update(i);\n    }\n    void update(int p) {\n        d[p]\
    \ = M::op(d[2 * p], d[2 * p + 1]);\n    }\n    void all_apply(int p, const F &f)\
    \ {\n        d[p] = M::map(f, d[p]);\n        if (p < sz) lz[p] = M::comp(f, lz[p]);\n\
    \    }\n    void push(int p) {\n        all_apply(2 * p, lz[p]);\n        all_apply(2\
    \ * p + 1, lz[p]);\n        lz[p] = M::id();\n    }\n    void inner_update(int\
    \ p) {\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n    void\
    \ inner_push(int p) {\n        for (int i = log; i >= 1; i--) push(p >> i);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/range_query/lazysegtree.hpp
  requiredBy:
  - src/data_structure/rectangle_query/rectangle_union.hpp
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/range_query/lazysegtree.test.cpp
  - test/data_structure/rectangle_query/rectangle_union.test.cpp
documentation_of: src/data_structure/range_query/lazysegtree.hpp
layout: document
title: Lazysegtree
---

遅延セグ木. 

## Constructor

```
lazysegtree<ActMonoid> seg(int n)
```

- 長さ $n$ のセグ木を作る
- `ActMonoid` を定義する必要がある
    - 内部で型 `S`, 二項演算 `op`, 単位元 `e`, 作用素の型 `F`, 合成 `comp`, 恒等写像 `id`, 作用 `map` を定義する必要がある
    - $\text{comp}(f, g)$ は $f\circ g$ が期待される
- $O(n)$

```
lazysegtree<ActMonoid> seg(vector<S> v)
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

## prod

```
S prod(int l, int r)
```

- 半開区間 $[l, r)$ に対する総積を計算する
- $O(\log n)$

## all_prod

```
S all_prod()
```

- 全体の総積を返す
- $O(1)$

## max_right

```
int max_right(int l, check)
```

- 右側への遅延セグ木上の二分探索を行う
- `check` には判定用のラムダ式を渡す
- $\text{check}(\text{prod}(l, r))$ が `true` となる $r$ の最大値が返る
- $\text{check}(e)$ が `true` である必要がある
- $O(\log n)$

## min_left

```
int min_left(int r, check)
```
- 左側への遅延セグ木上の二分探索を行う
- `check` には判定用のラムダ式を渡す
- $\text{check}(\text{prod}(l, r))$ が `true` となる $l$ の最小値が返る
- $\text{check}(e)$ が `true` である必要がある
- $O(\log n)$