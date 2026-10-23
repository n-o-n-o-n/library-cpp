---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/binary_fenwick_tree.test.cpp
    title: test/data_structure/range_query/binary_fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/range_query/binary_fenwick_tree.hpp\"\
    \n#include <cassert>\n#include <numeric>\n#include <vector>\nusing namespace std;\n\
    \nstruct binary_fenwick_tree {\n    binary_fenwick_tree() : binary_fenwick_tree(0)\
    \ {}\n    binary_fenwick_tree(int _n) : binary_fenwick_tree(vector<int>(_n, 0))\
    \ {}\n    template<typename T>\n    binary_fenwick_tree(const vector<T> &_v) :\
    \ n(_v.size()) {\n        sz = (n + 63) >> 6;\n        bit = vector<unsigned long\
    \ long>(sz, 0);\n        d = v = vector<int>(sz, 0);\n        for (int p = 0;\
    \ p < n; p++) {\n            if (_v[p]) {\n                int i = p >> 6, j =\
    \ p & 63;\n                bit[i] |= 1ULL << j;\n            }\n        }\n  \
    \      for (int i = 1; i <= sz; i++) {\n            v[i - 1] = __builtin_popcountll(bit[i\
    \ - 1]);\n            d[i - 1] += v[i - 1];\n            int j = i + (i & -i);\n\
    \            if (j <= sz) d[j - 1] += d[i - 1];\n        }\n    }\n    void set(int\
    \ p) {\n        assert(0 <= p && p < n);\n        int i = p >> 6, j = p & 63;\n\
    \        if ((bit[i] >> j & 1) == 0) {\n            bit[i] |= 1ULL << j;\n   \
    \         fw_update(i);\n        }\n    }\n    void reset(int p) {\n        assert(0\
    \ <= p && p < n);\n        int i = p >> 6, j = p & 63;\n        if (bit[i] >>\
    \ j & 1) {\n            bit[i] &= ~(1uLL << j);\n            fw_update(i);\n \
    \       }\n    }\n    void flip(int p) {\n        assert(0 <= p && p < n);\n \
    \       int i = p >> 6, j = p & 63;\n        bit[i] ^= 1ULL << j;\n        fw_update(i);\n\
    \    }\n    bool test(int p) const {\n        assert(0 <= p && p < n);\n     \
    \   return bit[p >> 6] >> (p & 63) & 1;\n    }\n    int count(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return 0;\n\
    \        int il = l >> 6, jl = l & 63;\n        int ir = r >> 6, jr = r & 63;\n\
    \        if (il == ir) {\n            return __builtin_popcountll((bit[il] >>\
    \ jl) & mask(jr - jl));\n        }\n        int res = fw_sum(ir) - fw_sum(il);\n\
    \        res -= __builtin_popcountll(bit[il] & mask(jl));\n        if (jr) res\
    \ += __builtin_popcountll(bit[ir] & mask(jr));\n        return res;\n    }\n \
    \   bool all(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        return count(l, r) == r - l;\n    }\n    bool any(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        return count(l, r) >\
    \ 0;\n    }\n    bool none(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        return count(l, r) == 0;\n    }\n    int kth_element(int\
    \ k) const {\n        assert(k >= 0);\n        if (k >= n) return -1;\n      \
    \  int x = k + 1;\n        int p = fw_lower_bound(x);\n        if (p == sz) return\
    \ -1;\n        int l = 0, r = 64;\n        while (r - l > 1) {\n            int\
    \ m = (l + r) >> 1;\n            (__builtin_popcountll(bit[p] & mask(m)) < x ?\
    \ l : r) = m;\n        }\n        return (p << 6) ^ l;\n    }\n    int next_element(int\
    \ p) const {\n        assert(0 <= p && p < n);\n        return kth_element(count(0,\
    \ p));\n    }\n    int prev_element(int p) const {\n        assert(0 <= p && p\
    \ < n);\n        int x = count(0, p + 1);\n        return x == 0 ? -1 : kth_element(x\
    \ - 1);\n    }\nprivate:\n    int n, sz;\n    vector<unsigned long long> bit;\n\
    \    vector<int> d, v;\n    static constexpr unsigned long long mask(int m) {\n\
    \        return (1ULL << m) - 1;\n    }\n    void fw_update(int p) {\n       \
    \ int x = __builtin_popcountll(bit[p]) - v[p];\n        v[p] += x;\n        for\
    \ (p++; p <= sz; p += p & -p) {\n            d[p - 1] += x;\n        }\n    }\n\
    \    int fw_sum(int p) const {\n        int res = 0;\n        while (p > 0) {\n\
    \            res += d[p - 1];\n            p -= p & -p;\n        }\n        return\
    \ res;\n    }\n    int fw_lower_bound(int &x) const {\n        int r = 0, p =\
    \ 1;\n        while ((p << 1) <= sz) p <<= 1;\n        while (p > 0) {\n     \
    \       if (r + p <= sz && d[r + p - 1] < x) {\n                r += p;\n    \
    \            x -= d[r - 1];\n            }\n            p >>= 1;\n        }\n\
    \        return r;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    using namespace std;\n\nstruct binary_fenwick_tree {\n    binary_fenwick_tree()\
    \ : binary_fenwick_tree(0) {}\n    binary_fenwick_tree(int _n) : binary_fenwick_tree(vector<int>(_n,\
    \ 0)) {}\n    template<typename T>\n    binary_fenwick_tree(const vector<T> &_v)\
    \ : n(_v.size()) {\n        sz = (n + 63) >> 6;\n        bit = vector<unsigned\
    \ long long>(sz, 0);\n        d = v = vector<int>(sz, 0);\n        for (int p\
    \ = 0; p < n; p++) {\n            if (_v[p]) {\n                int i = p >> 6,\
    \ j = p & 63;\n                bit[i] |= 1ULL << j;\n            }\n        }\n\
    \        for (int i = 1; i <= sz; i++) {\n            v[i - 1] = __builtin_popcountll(bit[i\
    \ - 1]);\n            d[i - 1] += v[i - 1];\n            int j = i + (i & -i);\n\
    \            if (j <= sz) d[j - 1] += d[i - 1];\n        }\n    }\n    void set(int\
    \ p) {\n        assert(0 <= p && p < n);\n        int i = p >> 6, j = p & 63;\n\
    \        if ((bit[i] >> j & 1) == 0) {\n            bit[i] |= 1ULL << j;\n   \
    \         fw_update(i);\n        }\n    }\n    void reset(int p) {\n        assert(0\
    \ <= p && p < n);\n        int i = p >> 6, j = p & 63;\n        if (bit[i] >>\
    \ j & 1) {\n            bit[i] &= ~(1uLL << j);\n            fw_update(i);\n \
    \       }\n    }\n    void flip(int p) {\n        assert(0 <= p && p < n);\n \
    \       int i = p >> 6, j = p & 63;\n        bit[i] ^= 1ULL << j;\n        fw_update(i);\n\
    \    }\n    bool test(int p) const {\n        assert(0 <= p && p < n);\n     \
    \   return bit[p >> 6] >> (p & 63) & 1;\n    }\n    int count(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return 0;\n\
    \        int il = l >> 6, jl = l & 63;\n        int ir = r >> 6, jr = r & 63;\n\
    \        if (il == ir) {\n            return __builtin_popcountll((bit[il] >>\
    \ jl) & mask(jr - jl));\n        }\n        int res = fw_sum(ir) - fw_sum(il);\n\
    \        res -= __builtin_popcountll(bit[il] & mask(jl));\n        if (jr) res\
    \ += __builtin_popcountll(bit[ir] & mask(jr));\n        return res;\n    }\n \
    \   bool all(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        return count(l, r) == r - l;\n    }\n    bool any(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        return count(l, r) >\
    \ 0;\n    }\n    bool none(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        return count(l, r) == 0;\n    }\n    int kth_element(int\
    \ k) const {\n        assert(k >= 0);\n        if (k >= n) return -1;\n      \
    \  int x = k + 1;\n        int p = fw_lower_bound(x);\n        if (p == sz) return\
    \ -1;\n        int l = 0, r = 64;\n        while (r - l > 1) {\n            int\
    \ m = (l + r) >> 1;\n            (__builtin_popcountll(bit[p] & mask(m)) < x ?\
    \ l : r) = m;\n        }\n        return (p << 6) ^ l;\n    }\n    int next_element(int\
    \ p) const {\n        assert(0 <= p && p < n);\n        return kth_element(count(0,\
    \ p));\n    }\n    int prev_element(int p) const {\n        assert(0 <= p && p\
    \ < n);\n        int x = count(0, p + 1);\n        return x == 0 ? -1 : kth_element(x\
    \ - 1);\n    }\nprivate:\n    int n, sz;\n    vector<unsigned long long> bit;\n\
    \    vector<int> d, v;\n    static constexpr unsigned long long mask(int m) {\n\
    \        return (1ULL << m) - 1;\n    }\n    void fw_update(int p) {\n       \
    \ int x = __builtin_popcountll(bit[p]) - v[p];\n        v[p] += x;\n        for\
    \ (p++; p <= sz; p += p & -p) {\n            d[p - 1] += x;\n        }\n    }\n\
    \    int fw_sum(int p) const {\n        int res = 0;\n        while (p > 0) {\n\
    \            res += d[p - 1];\n            p -= p & -p;\n        }\n        return\
    \ res;\n    }\n    int fw_lower_bound(int &x) const {\n        int r = 0, p =\
    \ 1;\n        while ((p << 1) <= sz) p <<= 1;\n        while (p > 0) {\n     \
    \       if (r + p <= sz && d[r + p - 1] < x) {\n                r += p;\n    \
    \            x -= d[r - 1];\n            }\n            p >>= 1;\n        }\n\
    \        return r;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/range_query/binary_fenwick_tree.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/range_query/binary_fenwick_tree.test.cpp
documentation_of: src/data_structure/range_query/binary_fenwick_tree.hpp
layout: document
title: Binary Fenwick Tree
---

`01` 列を管理する Fenwick Tree.
ワードサイズを $w=64$, ワード数を $m=\lceil n/w\rceil$ とする.

## Constructor

```
binary_fenwick_tree fw(int n)
```

- 長さ $n$ の全要素が $0$ の列を作る
- $O(n)$

```
binary_fenwick_tree fw(vector<T> v)
```

- 配列 $v$ で初期化する
- $v_i$ が真と判定されるなら $1$, それ以外なら $0$ として扱う
- $O(n)$

## set

```
void set(int p)
```

- $p$ 番目を $1$ にする
- $O(\log m)$

## reset

```
void reset(int p)
```

- $p$ 番目を $0$ にする
- $O(\log m)$

## flip

```
void flip(int p)
```

- $p$ 番目の $0$ と $1$ を反転する
- $O(\log m)$

## test

```
bool test(int p)
```

- $p$ 番目が $1$ なら `true` を返す
- $O(1)$

## count

```
int count(int l, int r)
```

- 半開区間 $[l, r)$ にある $1$ の個数を返す
- $l$ と $r-1$ が同じワード内なら $O(1)$, それ以外は $O(\log m)$

## all

```
bool all(int l, int r)
```

- 半開区間 $[l, r)$ のすべての要素が $1$ なら `true` を返す
- $O(\log m)$

## any

```
bool any(int l, int r)
```

- 半開区間 $[l, r)$ に $1$ があれば `true` を返す
- $O(\log m)$

## none

```
bool none(int l, int r)
```

- 半開区間 $[l, r)$ に $1$ がなければ `true` を返す
- $O(\log m)$

## kth_element

```
int kth_element(int k)
```

- $1$ の位置を昇順に並べたときの $k$ 番目 (0-indexed) を返す
- 存在しない場合は $-1$ を返す
- $O(\log m)$

## next_element

```
int next_element(int p)
```

- $p$ 以上で最も左にある $1$ の位置を返す
- 存在しない場合は $-1$ を返す
- $O(\log m)$

## prev_element

```
int prev_element(int p)
```

- $p$ 以下で最も右にある $1$ の位置を返す
- 存在しない場合は $-1$ を返す
- $O(\log m)$
