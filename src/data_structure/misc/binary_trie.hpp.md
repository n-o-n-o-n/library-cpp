---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/misc/binary_trie.test.cpp
    title: test/data_structure/misc/binary_trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/misc/binary_trie_ordered_set.test.cpp
    title: test/data_structure/misc/binary_trie_ordered_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/misc/binary_trie.hpp\"\n#include <array>\n\
    #include <cassert>\n#include <vector>\n#include <limits>\nusing namespace std;\n\
    \ntemplate<typename T, int LOG = numeric_limits<T>::digits>\nstruct binary_trie\
    \ {\n    binary_trie() : all(0), sub(1, 0), child(1, e()) {}\n    int size() const\
    \ { return all; }\n    array<int, LOG> track(T x) const {\n        int pos = 0;\n\
    \        array<int, LOG> res;\n        res.fill(-1);\n        for (int i = LOG\
    \ - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n            int nxt =\
    \ child[pos][c];\n            if (nxt == -1) break;\n            pos = nxt;\n\
    \            res[LOG - 1 - i] = pos;\n        }\n        return res;\n    }\n\
    \    array<int, LOG> insert(T x) {\n        int pos = 0;\n        for (int i =\
    \ LOG - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n            int nxt\
    \ = child[pos][c];\n            if (nxt == -1) {\n                nxt = sub.size();\n\
    \                sub.push_back(0);\n                child.push_back(e());\n  \
    \          }\n            child[pos][c] = nxt;\n            pos = nxt;\n     \
    \   }\n        auto tr = track(x);\n        int p = tr.back();\n        if (sub[p]\
    \ == 0) {\n            for (int i : tr) sub[i]++;\n            all++;\n      \
    \  }\n        return tr;\n    }\n    void erase(T x) {\n        auto tr = track(x);\n\
    \        int p = tr.back();\n        if (p == -1 || sub[p] == 0) return;\n   \
    \     for (int i : tr) sub[i]--;\n        all--;\n    }\n    // return (x in S\
    \ ? true : false);\n    bool contains(T x) const {\n        int p = track(x).back();\n\
    \        return (p != -1) && (sub[p] > 0);\n    }\n    T kth_smallest(int k, T\
    \ xor_val = 0) const {\n        assert(0 <= k && k < size());\n        int pos\
    \ = 0;\n        T res = 0;\n        for (int i = LOG - 1; i >= 0; i--) {\n   \
    \         res *= 2;\n            int c = xor_val >> i & 1;\n            int nxt\
    \ = child[pos][c];\n            if (nxt != -1) {\n                if (0 <= k &&\
    \ k < sub[nxt]) {\n                    pos = nxt;\n                    continue;\n\
    \                }\n                k -= sub[nxt];\n            }\n          \
    \  pos = child[pos][1 - c];\n            res++;\n        }\n        return res;\n\
    \    }\n    T kth_largest(int k, T xor_val = 0) const {\n        assert(0 <= k\
    \ && k < size());\n        return kth_smallest(size() - 1 - k, xor_val);\n   \
    \ }\n    T min(T xor_val = 0) const {\n        assert(size());\n        return\
    \ kth_smallest(0, xor_val);\n    }\n    T max(T xor_val = 0) const {\n       \
    \ assert(size());\n        return kth_largest(0, xor_val);\n    }\n    T mex(T\
    \ xor_val = 0) const {\n        if (size() == 0) return T(0);\n        int pos\
    \ = 0;\n        T res = 0;\n        for (int i = LOG - 1; i >= 0; i--) {\n   \
    \         res *= 2;\n            int c = xor_val >> i & 1;\n            int nxt\
    \ = child[pos][c];\n            if (nxt == -1) return res << i;\n            if\
    \ (sub[nxt] < (T(1) << i)) {\n                pos = nxt;\n                continue;\n\
    \            }\n            res++;\n            if (child[pos][1 - c] == -1) return\
    \ res << i;\n            pos = child[pos][1 - c];\n        }\n        return res\
    \ + (sub[pos] != 0);\n    }\n    // #{s in S | s^x < k}\n    int lower_count(T\
    \ x, T xor_val = 0) const {\n        if (x <= 0) return 0;\n        if constexpr\
    \ (LOG < numeric_limits<T>::digits) {\n            if (x >= (T(1) << LOG)) return\
    \ size();\n        }\n        int pos = 0;\n        int res = 0;\n        for\
    \ (int i = LOG - 1; i >= 0; i--) {\n            if (pos == -1) break;\n      \
    \      int cx = (x >> i) & 1;\n            int cxor = (xor_val >> i) & 1;\n  \
    \          int nxt0 = child[pos][cxor];\n            int nxt1 = child[pos][1 -\
    \ cxor];\n            if (cx == 1) {\n                if (nxt0 != -1) {\n    \
    \                res += sub[nxt0];\n                }\n                pos = nxt1;\n\
    \            } else {\n                pos = nxt0;\n            }\n        }\n\
    \        return res;\n    }\n    // #{s in S | s^x > k}\n    int upper_count(T\
    \ k, T xor_val = 0) const {\n        if (k == numeric_limits<T>::max()) return\
    \ 0;\n        return size() - lower_count(k + 1, xor_val);\n    }\n    // max{s^x\
    \ | s^x < upper }\n    T prev_val(T upper, T xor_val = 0) const {\n        int\
    \ k = lower_count(upper, xor_val);\n        return k == 0 ? T(-1) : kth_smallest(k\
    \ - 1, xor_val);\n    }\n    // min{s^x | s^x > lower }\n    T next_val(T lower,\
    \ T xor_val = 0) const {\n        if (lower == numeric_limits<T>::max()) return\
    \ T(-1);\n        int k = lower_count(lower + 1, xor_val);\n        return k ==\
    \ size() ? T(-1) : kth_smallest(k, xor_val);\n    }\nprivate:\n    int all;\n\
    \    vector<int> sub;\n    vector<array<int, 2>> child;\n    constexpr array<int,\
    \ 2> e() {\n        return {-1, -1};\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\n#include\
    \ <limits>\nusing namespace std;\n\ntemplate<typename T, int LOG = numeric_limits<T>::digits>\n\
    struct binary_trie {\n    binary_trie() : all(0), sub(1, 0), child(1, e()) {}\n\
    \    int size() const { return all; }\n    array<int, LOG> track(T x) const {\n\
    \        int pos = 0;\n        array<int, LOG> res;\n        res.fill(-1);\n \
    \       for (int i = LOG - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n\
    \            int nxt = child[pos][c];\n            if (nxt == -1) break;\n   \
    \         pos = nxt;\n            res[LOG - 1 - i] = pos;\n        }\n       \
    \ return res;\n    }\n    array<int, LOG> insert(T x) {\n        int pos = 0;\n\
    \        for (int i = LOG - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n\
    \            int nxt = child[pos][c];\n            if (nxt == -1) {\n        \
    \        nxt = sub.size();\n                sub.push_back(0);\n              \
    \  child.push_back(e());\n            }\n            child[pos][c] = nxt;\n  \
    \          pos = nxt;\n        }\n        auto tr = track(x);\n        int p =\
    \ tr.back();\n        if (sub[p] == 0) {\n            for (int i : tr) sub[i]++;\n\
    \            all++;\n        }\n        return tr;\n    }\n    void erase(T x)\
    \ {\n        auto tr = track(x);\n        int p = tr.back();\n        if (p ==\
    \ -1 || sub[p] == 0) return;\n        for (int i : tr) sub[i]--;\n        all--;\n\
    \    }\n    // return (x in S ? true : false);\n    bool contains(T x) const {\n\
    \        int p = track(x).back();\n        return (p != -1) && (sub[p] > 0);\n\
    \    }\n    T kth_smallest(int k, T xor_val = 0) const {\n        assert(0 <=\
    \ k && k < size());\n        int pos = 0;\n        T res = 0;\n        for (int\
    \ i = LOG - 1; i >= 0; i--) {\n            res *= 2;\n            int c = xor_val\
    \ >> i & 1;\n            int nxt = child[pos][c];\n            if (nxt != -1)\
    \ {\n                if (0 <= k && k < sub[nxt]) {\n                    pos =\
    \ nxt;\n                    continue;\n                }\n                k -=\
    \ sub[nxt];\n            }\n            pos = child[pos][1 - c];\n           \
    \ res++;\n        }\n        return res;\n    }\n    T kth_largest(int k, T xor_val\
    \ = 0) const {\n        assert(0 <= k && k < size());\n        return kth_smallest(size()\
    \ - 1 - k, xor_val);\n    }\n    T min(T xor_val = 0) const {\n        assert(size());\n\
    \        return kth_smallest(0, xor_val);\n    }\n    T max(T xor_val = 0) const\
    \ {\n        assert(size());\n        return kth_largest(0, xor_val);\n    }\n\
    \    T mex(T xor_val = 0) const {\n        if (size() == 0) return T(0);\n   \
    \     int pos = 0;\n        T res = 0;\n        for (int i = LOG - 1; i >= 0;\
    \ i--) {\n            res *= 2;\n            int c = xor_val >> i & 1;\n     \
    \       int nxt = child[pos][c];\n            if (nxt == -1) return res << i;\n\
    \            if (sub[nxt] < (T(1) << i)) {\n                pos = nxt;\n     \
    \           continue;\n            }\n            res++;\n            if (child[pos][1\
    \ - c] == -1) return res << i;\n            pos = child[pos][1 - c];\n       \
    \ }\n        return res + (sub[pos] != 0);\n    }\n    // #{s in S | s^x < k}\n\
    \    int lower_count(T x, T xor_val = 0) const {\n        if (x <= 0) return 0;\n\
    \        if constexpr (LOG < numeric_limits<T>::digits) {\n            if (x >=\
    \ (T(1) << LOG)) return size();\n        }\n        int pos = 0;\n        int\
    \ res = 0;\n        for (int i = LOG - 1; i >= 0; i--) {\n            if (pos\
    \ == -1) break;\n            int cx = (x >> i) & 1;\n            int cxor = (xor_val\
    \ >> i) & 1;\n            int nxt0 = child[pos][cxor];\n            int nxt1 =\
    \ child[pos][1 - cxor];\n            if (cx == 1) {\n                if (nxt0\
    \ != -1) {\n                    res += sub[nxt0];\n                }\n       \
    \         pos = nxt1;\n            } else {\n                pos = nxt0;\n   \
    \         }\n        }\n        return res;\n    }\n    // #{s in S | s^x > k}\n\
    \    int upper_count(T k, T xor_val = 0) const {\n        if (k == numeric_limits<T>::max())\
    \ return 0;\n        return size() - lower_count(k + 1, xor_val);\n    }\n   \
    \ // max{s^x | s^x < upper }\n    T prev_val(T upper, T xor_val = 0) const {\n\
    \        int k = lower_count(upper, xor_val);\n        return k == 0 ? T(-1) :\
    \ kth_smallest(k - 1, xor_val);\n    }\n    // min{s^x | s^x > lower }\n    T\
    \ next_val(T lower, T xor_val = 0) const {\n        if (lower == numeric_limits<T>::max())\
    \ return T(-1);\n        int k = lower_count(lower + 1, xor_val);\n        return\
    \ k == size() ? T(-1) : kth_smallest(k, xor_val);\n    }\nprivate:\n    int all;\n\
    \    vector<int> sub;\n    vector<array<int, 2>> child;\n    constexpr array<int,\
    \ 2> e() {\n        return {-1, -1};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/misc/binary_trie.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/misc/binary_trie.test.cpp
  - test/data_structure/misc/binary_trie_ordered_set.test.cpp
documentation_of: src/data_structure/misc/binary_trie.hpp
layout: document
title: Binary Trie
---

非負整数の集合をビット列の Trie で管理する.

管理する集合を $S$ とし, $S\oplus x=\{x\oplus s \mid s \in S\}$ と定義する.

$x=$ `xor_val` $, L=$ `LOG` とし, 格納する値と $x$ は $0$ 以上 $2^L$ 未満とする.

## Constructor

```
binary_trie<T, LOG> bt
```

- 空の集合を作る
- `T` は整数型, `LOG` は扱う値のビット数で, 省略時は `numeric_limits<T>::digits`

## size

```
int size()
```

- $|S|$ を返す
- $O(1)$

## track

```
array<int, LOG> track(T x)
```

- $x$ の各ビットに沿って通るノードの番号を上位ビットから順に返す
- 枝が存在しない部分は $-1$ を返す
- $O(L)$

## insert

```
array<int, LOG> insert(T x)
```

- $x$ を挿入し, `track(x)` を返す
- $x$ が既に含まれる場合は集合を変更しない
- $O(L)$

## erase

```
void erase(T x)
```

- $x$ を削除する
- $x$ が含まれない場合は何もしない
- $O(L)$

## contains

```
bool contains(T x)
```

- $x$ が含まれる場合に `true` を返す
- $O(L)$

## kth_smallest

```
T kth_smallest(int k, T xor_val = 0)
```

- $S\oplus x$ を昇順に並べ, $k$ 番目 (0-indexed) の値を返す
- $k < |S|$ が必要
- $O(L)$

## kth_largest

```
T kth_largest(int k, T xor_val = 0)
```

- $S\oplus x$ を降順に並べ, $k$ 番目 (0-indexed) の値を返す
- $k < |S|$ が必要
- $O(L)$

## min

```
T min(T xor_val = 0)
```

- $S\oplus x$ の最小値を返す
- $S\ne \emptyset$ が必要
- $O(L)$

## max

```
T max(T xor_val = 0)
```

- $S\oplus x$ の最大値を返す
- $S\ne \emptyset$ が必要
- $O(L)$

## mex

```
T mex(T xor_val = 0)
```

- $S\oplus x$ の mex を返す
- $O(L)$

## lower_count

```
int lower_count(T k, T xor_val = 0)
```

- $S\oplus x$ に含まれる $k$ 未満の値の個数を返す
- $O(L)$

## upper_count

```
int upper_count(T k, T xor_val = 0)
```

- $S\oplus x$ に含まれる $k$ より大きい値の個数を返す
- $O(L)$

## prev_val

```
T prev_val(T upper, T xor_val = 0)
```

- $S\oplus x$ に含まれる `upper` 未満の値の最大値を返す
- 存在しない場合は $-1$ を返す
- $O(L)$

## next_val

```
T next_val(T lower, T xor_val = 0)
```

- $S\oplus x$ に含まれる `lower` より大きい値の最小値を返す
- 存在しない場合は $-1$ を返す
- $O(L)$
