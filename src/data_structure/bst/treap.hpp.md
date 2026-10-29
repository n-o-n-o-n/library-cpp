---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: Xor Shift
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/bst/treap.hpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"src/random/xor_shift.hpp\"\n#include <cstdint>\n\
    #include <type_traits>\nusing namespace std;\n\ntemplate<typename T>\nstruct xor_shift\
    \ {\n    using U = typename make_unsigned<T>::type;\n    constexpr xor_shift(U\
    \ seed = 0) : x(seed == 0 ? 987139873 : seed) {}\n    constexpr U operator()()\
    \ {\n        if constexpr (sizeof(T) <= 4) {\n            x ^= x << 13;\n    \
    \        x ^= x >> 17;\n            x ^= x << 5;\n        } else {\n         \
    \   x ^= x << 13;\n            x ^= x >> 7;\n            x ^= x << 17;\n     \
    \   }\n        return x;\n    }\n    constexpr T operator()(T lo, T hi) {\n  \
    \      return lo + (*this)() % (hi - lo + 1);\n    }\nprivate:\n    U x;\n};\n\
    #line 5 \"src/data_structure/bst/treap.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct treap {\n    treap() : eng(19835715), root(-1) {}\n    treap(const\
    \ vector<T> &v) : eng(v.size() + 1) {\n        d.reserve(v.size());\n        root\
    \ = build(v, 0, v.size());\n    }\n    int size() const { return size(root); }\n\
    \    void insert(int p, const T &x) {\n        assert(0 <= p && p <= size(root));\n\
    \        root = insert(root, p, x);\n    }\n    void erase(int p) { erase(p, p\
    \ + 1); }\n    void erase(int l, int r) {\n        assert(0 <= l && l <= r &&\
    \ r <= size(root));\n        auto [ll, _, rr] = split(root, l, r);\n        root\
    \ = merge(ll, rr);\n    }\n    void reverse(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= size(root));\n        root = reverse(root, l, r);\n \
    \   }\n    void set(int p, const T &x) {\n        assert(0 <= p && p < size(root));\n\
    \        auto [l, m, r] = split(root, p, p + 1);\n        d[m].x = x;\n      \
    \  update(m); \n        root = merge(l, m, r);\n    }\n    // a <- (a[k], a[k+1],\
    \ ..., a[n-1], a[0], ..., a[k-1])\n    void shift(int k) {\n        int n = size(root);\n\
    \        if (n == 0) return;\n        k %= n;\n        if (k < 0) k += n;\n  \
    \      auto [l, r] = split(root, k);\n        root = merge(r, l);\n    }\n   \
    \ T get(int p) {\n        assert(0 <= p && p < size(root));\n        auto [l,\
    \ m, r] = split(root, p, p + 1);\n        T res = d[m].x;\n        root = merge(l,\
    \ m, r);\n        return res;\n    }\nprivate:\n    xor_shift<int> eng;\n    struct\
    \ node {\n        int l,  r;\n        T x;\n        int sz;\n        bool rev;\n\
    \        unsigned int pri;\n        node(const T &_x, unsigned int _pri) : l(-1),\
    \ r(-1), x(_x), sz(1), rev(false), pri(_pri) {}\n    };\n    int root;\n    vector<node>\
    \ d;\n    int make_node(const T &x) {\n        int res = d.size();\n        d.emplace_back(x,\
    \ eng());\n        return res;\n    }\n    int build(const vector<T> &v, int l,\
    \ int r) {\n        if (l == r) return -1;\n        if (l + 1 == r) return make_node(v[l]);\n\
    \        int m = (l + r) / 2;\n        return merge(build(v, l, m), build(v, m,\
    \ r));\n    }\n    int size(int p) const { return 0 <= p && p < ssize(d) ? d[p].sz\
    \ : 0; }\n    void update(int p) {\n        if (p < 0 || p >= ssize(d)) return;\n\
    \        d[p].sz = size(d[p].l) + 1 + size(d[p].r);\n    }\n    void push(int\
    \ p) {\n        if (p < 0 || p >= ssize(d)) return;\n        if (d[p].rev) {\n\
    \            swap(d[p].l, d[p].r);\n            if (d[p].l != -1) d[d[p].l].rev\
    \ ^= true;\n            if (d[p].r != -1) d[d[p].r].rev ^= true;\n           \
    \ d[p].rev = false;\n        }\n    }\n    int merge(int p, int q) {\n       \
    \ if (p == -1) return q;\n        if (q == -1) return p;\n        push(p);\n \
    \       push(q);\n        if (d[p].pri > d[q].pri) {\n            d[p].r = merge(d[p].r,\
    \ q);\n            update(p);\n            return p;\n        } else {\n     \
    \       d[q].l = merge(p, d[q].l);\n            update(q);\n            return\
    \ q;\n        }\n    }\n    int merge(int p, int q, int r) {\n        return merge(p,\
    \ merge(q, r));\n    }\n    pair<int, int> split(int p, int k) {\n        if (p\
    \ == -1) return {-1, -1};\n        push(p);\n        if (k <= size(d[p].l)) {\n\
    \            auto [ll, rr] = split(d[p].l, k);\n            d[p].l = rr;\n   \
    \         update(p);\n            return {ll, p};\n        } else {\n        \
    \    auto [ll, rr] = split(d[p].r, k - size(d[p].l) - 1);\n            d[p].r\
    \ = ll;\n            update(p);\n            return {p, rr};\n        }\n    }\n\
    \    tuple<int, int, int> split(int p, int l, int r) {\n        auto [m, rr] =\
    \ split(p, r);\n        auto [ll, mm] = split(m, l);\n        return {ll, mm,\
    \ rr};\n    }\n    int insert(int p, int k, const T &x) {\n        auto [l, r]\
    \ = split(p, k);\n        return merge(l, make_node(x), r);\n    }\n    int reverse(int\
    \ root, int l, int r) {\n        auto [pl, pm, pr] = split(root, l, r);\n    \
    \    if (pm != -1) d[pm].rev ^= true;\n        return merge(pl, pm, pr);\n   \
    \ }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"../../random/xor_shift.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nstruct treap {\n    treap() :\
    \ eng(19835715), root(-1) {}\n    treap(const vector<T> &v) : eng(v.size() + 1)\
    \ {\n        d.reserve(v.size());\n        root = build(v, 0, v.size());\n   \
    \ }\n    int size() const { return size(root); }\n    void insert(int p, const\
    \ T &x) {\n        assert(0 <= p && p <= size(root));\n        root = insert(root,\
    \ p, x);\n    }\n    void erase(int p) { erase(p, p + 1); }\n    void erase(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n        auto\
    \ [ll, _, rr] = split(root, l, r);\n        root = merge(ll, rr);\n    }\n   \
    \ void reverse(int l, int r) {\n        assert(0 <= l && l <= r && r <= size(root));\n\
    \        root = reverse(root, l, r);\n    }\n    void set(int p, const T &x) {\n\
    \        assert(0 <= p && p < size(root));\n        auto [l, m, r] = split(root,\
    \ p, p + 1);\n        d[m].x = x;\n        update(m); \n        root = merge(l,\
    \ m, r);\n    }\n    // a <- (a[k], a[k+1], ..., a[n-1], a[0], ..., a[k-1])\n\
    \    void shift(int k) {\n        int n = size(root);\n        if (n == 0) return;\n\
    \        k %= n;\n        if (k < 0) k += n;\n        auto [l, r] = split(root,\
    \ k);\n        root = merge(r, l);\n    }\n    T get(int p) {\n        assert(0\
    \ <= p && p < size(root));\n        auto [l, m, r] = split(root, p, p + 1);\n\
    \        T res = d[m].x;\n        root = merge(l, m, r);\n        return res;\n\
    \    }\nprivate:\n    xor_shift<int> eng;\n    struct node {\n        int l, \
    \ r;\n        T x;\n        int sz;\n        bool rev;\n        unsigned int pri;\n\
    \        node(const T &_x, unsigned int _pri) : l(-1), r(-1), x(_x), sz(1), rev(false),\
    \ pri(_pri) {}\n    };\n    int root;\n    vector<node> d;\n    int make_node(const\
    \ T &x) {\n        int res = d.size();\n        d.emplace_back(x, eng());\n  \
    \      return res;\n    }\n    int build(const vector<T> &v, int l, int r) {\n\
    \        if (l == r) return -1;\n        if (l + 1 == r) return make_node(v[l]);\n\
    \        int m = (l + r) / 2;\n        return merge(build(v, l, m), build(v, m,\
    \ r));\n    }\n    int size(int p) const { return 0 <= p && p < ssize(d) ? d[p].sz\
    \ : 0; }\n    void update(int p) {\n        if (p < 0 || p >= ssize(d)) return;\n\
    \        d[p].sz = size(d[p].l) + 1 + size(d[p].r);\n    }\n    void push(int\
    \ p) {\n        if (p < 0 || p >= ssize(d)) return;\n        if (d[p].rev) {\n\
    \            swap(d[p].l, d[p].r);\n            if (d[p].l != -1) d[d[p].l].rev\
    \ ^= true;\n            if (d[p].r != -1) d[d[p].r].rev ^= true;\n           \
    \ d[p].rev = false;\n        }\n    }\n    int merge(int p, int q) {\n       \
    \ if (p == -1) return q;\n        if (q == -1) return p;\n        push(p);\n \
    \       push(q);\n        if (d[p].pri > d[q].pri) {\n            d[p].r = merge(d[p].r,\
    \ q);\n            update(p);\n            return p;\n        } else {\n     \
    \       d[q].l = merge(p, d[q].l);\n            update(q);\n            return\
    \ q;\n        }\n    }\n    int merge(int p, int q, int r) {\n        return merge(p,\
    \ merge(q, r));\n    }\n    pair<int, int> split(int p, int k) {\n        if (p\
    \ == -1) return {-1, -1};\n        push(p);\n        if (k <= size(d[p].l)) {\n\
    \            auto [ll, rr] = split(d[p].l, k);\n            d[p].l = rr;\n   \
    \         update(p);\n            return {ll, p};\n        } else {\n        \
    \    auto [ll, rr] = split(d[p].r, k - size(d[p].l) - 1);\n            d[p].r\
    \ = ll;\n            update(p);\n            return {p, rr};\n        }\n    }\n\
    \    tuple<int, int, int> split(int p, int l, int r) {\n        auto [m, rr] =\
    \ split(p, r);\n        auto [ll, mm] = split(m, l);\n        return {ll, mm,\
    \ rr};\n    }\n    int insert(int p, int k, const T &x) {\n        auto [l, r]\
    \ = split(p, k);\n        return merge(l, make_node(x), r);\n    }\n    int reverse(int\
    \ root, int l, int r) {\n        auto [pl, pm, pr] = split(root, l, r);\n    \
    \    if (pm != -1) d[pm].rev ^= true;\n        return merge(pl, pm, pr);\n   \
    \ }\n};\n"
  dependsOn:
  - src/random/xor_shift.hpp
  isVerificationFile: false
  path: src/data_structure/bst/treap.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structure/bst/treap.hpp
layout: document
title: Treap
---

色々できるデータ構造.

## Constructor

```
treap<T> tr
treap<T> tr(vector<T> v)
```

- 空の列, または $v$ を初期値とする列を作る
- `T` は要素の型

## size

```
int size()
```

- 列の要素数を返す
- $O(1)$

## insert

```
void insert(int p, T x)
```

- $p$ 番目の要素の前に $x$ を挿入する
- $0 \leq p \leq n$
- expected $O(\log n)$

## erase

```
void erase(int p)
void erase(int l, int r)
```

- $p$ 番目の要素, または区間 $[l,r)$ の要素を削除する
- expected $O(\log n)$

## reverse

```
void reverse(int l, int r)
```

- 区間 $[l,r)$ の要素の順序を反転する
- expected $O(\log n)$

## set

```
void set(int p, T x)
```

- $p$ 番目の要素を $x$ に変更する
- expected $O(\log n)$

## get

```
T get(int p)
```

- $p$ 番目の要素を返す
- expected $O(\log n)$

## shift

```
void shift(int k)
```

- 長さ $n$ の列を左へ $k$ 個循環シフトする
- 負の $k$ は右へのシフトを表し, $k$ は $n$ で割った余りとして扱う
- expected $O(\log n)$
