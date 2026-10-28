---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/wavelet_matrix_kth_smallest.test.cpp
    title: test/data_structure/range_query/wavelet_matrix_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/range_query/wavelet_matrix_range_freq.test.cpp
    title: test/data_structure/range_query/wavelet_matrix_range_freq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/range_query/wavelet_matrix.hpp\"\n#include\
    \ <cassert>\n#include <limits>\n#include <unordered_map>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename T, int LOG = numeric_limits<T>::digits>\n\
    struct wavelet_matrix {\n    wavelet_matrix() : wavelet_matrix(0) {}\n    wavelet_matrix(int\
    \ _n) : n(_n), d(_n), built(false) {}\n    wavelet_matrix(const vector<T> &v)\
    \ : n(v.size()), d(v), built(false) {}\n    void set(int p, const T &x) {\n  \
    \      assert(0 <= p && p < n);\n        d[p] = x;\n    }\n    T get(int p) {\n\
    \        assert(0 <= p && p < n);\n        build();\n        T res = 0;\n    \
    \    for (int i = LOG - 1; i >= 0; i--) {\n            bool flag = mat[i][p];\n\
    \            res |= T(flag) << i;\n            p = id(p, i, flag);\n        }\n\
    \        return res;\n    }\n    T range_kth_smallest(int l, int r, int k) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        assert(0 <= k && k < r -\
    \ l);\n        build();\n        T res = 0;\n        for (int i = LOG - 1; i >=\
    \ 0; i--) {\n            int m = mat[i].rank(r) - mat[i].rank(l);\n          \
    \  if (k < m) {\n                l = mat[i].rank(l);\n                r = mat[i].rank(r);\n\
    \            } else {\n                res += T(1) << i;\n                l =\
    \ id(l, i, true);\n                r = id(r, i, true);\n                k -= m;\n\
    \            }\n        }\n        return res;\n    }\n    T prev_val(int l, int\
    \ r, T upper) {\n        assert(0 <= l && l <= r && r <= n);\n        build();\n\
    \        int cnt = range_freq(l, r, 0, upper);\n        return cnt == 0 ? -1 :\
    \ range_kth_smallest(l, r, cnt - 1);\n    }\n    T next_val(int l, int r, T lower)\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        build();\n        int\
    \ cnt = range_freq(l, r, 0, lower);\n        return cnt == r - l ? -1 : range_kth_smallest(l,\
    \ r, cnt);\n    }\n    int count(int l, int r, T x) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        build();\n        auto f = [&](int k) -> int {\n\
    \            for (int i = LOG - 1; i >= 0; i--) {\n                bool flag =\
    \ x >> i & 1;\n                k = id(k, i, flag);\n            }\n          \
    \  return k - st[x];\n        };\n        return f(r) - f(l);\n    }\n    int\
    \ range_freq(int l, int r, T lower, T upper) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        build();\n        auto f = [&](T x) -> int {\n      \
    \      int res = 0;\n            int ll = l, rr = r;\n            for (int i =\
    \ LOG - 1; i >= 0; i--) {\n                bool flag = x >> i & 1;\n         \
    \       res += flag * (mat[i].rank(r) - mat[i].rank(l));\n                l =\
    \ id(l, i, flag);\n                r = id(r, i, flag);\n            }\n      \
    \      l = ll, r = rr;\n            return res;\n        };\n        return f(upper)\
    \ - f(lower);\n    }\nprivate:\n    struct bit_vector {\n        bit_vector()\
    \ = default;\n        bit_vector(const vector<bool> &v) {\n            int n =\
    \ v.size();\n            int m = n / b + 1;\n            d = vector<unsigned>(m);\n\
    \            sum = vector<int>(m + 1);\n            for (int i = 0; i < n; i++)\
    \ {\n                d[i / b] |= v[i] << (i % b);\n            }\n           \
    \ for (int i = 0; i < m; i++) {\n                sum[i + 1] = sum[i] + __builtin_popcount(d[i]);\n\
    \            }\n        }\n        bool operator[](int i) const { return d[i /\
    \ b] >> (i % b) & 1; }\n        int rank(int i, bool flag = false) const {\n \
    \           int mask = (1U << (i % b)) - 1;\n            int r = sum[i / b] +\
    \ __builtin_popcount(d[i / b] & mask);\n            return flag ? r : i - r;\n\
    \        }\n        int select(int i, bool flag) const {\n            int l =\
    \ 0, r = d.size();\n            while (r - l > 1) {\n                int m = (l\
    \ + r) >> 1;\n                (rank(i, flag) < i ? l : r) = m;\n            }\n\
    \            return l;\n        }\n    private:\n        static constexpr int\
    \ b = 32;\n        vector<unsigned> d;\n        vector<int> sum;\n    };\n   \
    \ int n;\n    vector<T> d;\n    vector<bit_vector> mat;\n    vector<int> cnt;\n\
    \    unordered_map<T, int> st;\n    bool built;\n    void build() {\n        if\
    \ (built) return;\n        mat = vector<bit_vector>(LOG);\n        cnt = vector<int>(LOG);\n\
    \        for (auto &x : d) assert(x >= 0);\n        for (int i = LOG - 1; i >=\
    \ 0; i--) {\n            vector<bool> bit(n);\n            for (int j = 0; j <\
    \ n; j++) {\n                bit[j] = d[j] >> i & 1;\n            }\n        \
    \    mat[i] = bit_vector(bit);\n            int c0 = 0, c1 = n;\n            for\
    \ (int j = 0; j < n; j++) {\n                if (!bit[j]) c0++;\n            }\n\
    \            cnt[i] = c0;\n            vector<T> d2(n);\n            for (int\
    \ j = n - 1; j >= 0; j--) {\n                d2[--(bit[j] ? c1 : c0)] = d[j];\n\
    \            }\n            d = d2;\n        }\n        for (int i = 0; i < n;\
    \ i++) {\n            if (st.find(d[i]) == st.end()) st[d[i]] = i;\n        }\n\
    \        built = true;\n    }\n    int id(int p, int i, bool flag) {\n       \
    \ return cnt[i] * flag + mat[i].rank(p, flag);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <unordered_map>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename T, int LOG = numeric_limits<T>::digits>\n\
    struct wavelet_matrix {\n    wavelet_matrix() : wavelet_matrix(0) {}\n    wavelet_matrix(int\
    \ _n) : n(_n), d(_n), built(false) {}\n    wavelet_matrix(const vector<T> &v)\
    \ : n(v.size()), d(v), built(false) {}\n    void set(int p, const T &x) {\n  \
    \      assert(0 <= p && p < n);\n        d[p] = x;\n    }\n    T get(int p) {\n\
    \        assert(0 <= p && p < n);\n        build();\n        T res = 0;\n    \
    \    for (int i = LOG - 1; i >= 0; i--) {\n            bool flag = mat[i][p];\n\
    \            res |= T(flag) << i;\n            p = id(p, i, flag);\n        }\n\
    \        return res;\n    }\n    T range_kth_smallest(int l, int r, int k) {\n\
    \        assert(0 <= l && l <= r && r <= n);\n        assert(0 <= k && k < r -\
    \ l);\n        build();\n        T res = 0;\n        for (int i = LOG - 1; i >=\
    \ 0; i--) {\n            int m = mat[i].rank(r) - mat[i].rank(l);\n          \
    \  if (k < m) {\n                l = mat[i].rank(l);\n                r = mat[i].rank(r);\n\
    \            } else {\n                res += T(1) << i;\n                l =\
    \ id(l, i, true);\n                r = id(r, i, true);\n                k -= m;\n\
    \            }\n        }\n        return res;\n    }\n    T prev_val(int l, int\
    \ r, T upper) {\n        assert(0 <= l && l <= r && r <= n);\n        build();\n\
    \        int cnt = range_freq(l, r, 0, upper);\n        return cnt == 0 ? -1 :\
    \ range_kth_smallest(l, r, cnt - 1);\n    }\n    T next_val(int l, int r, T lower)\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        build();\n        int\
    \ cnt = range_freq(l, r, 0, lower);\n        return cnt == r - l ? -1 : range_kth_smallest(l,\
    \ r, cnt);\n    }\n    int count(int l, int r, T x) {\n        assert(0 <= l &&\
    \ l <= r && r <= n);\n        build();\n        auto f = [&](int k) -> int {\n\
    \            for (int i = LOG - 1; i >= 0; i--) {\n                bool flag =\
    \ x >> i & 1;\n                k = id(k, i, flag);\n            }\n          \
    \  return k - st[x];\n        };\n        return f(r) - f(l);\n    }\n    int\
    \ range_freq(int l, int r, T lower, T upper) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        build();\n        auto f = [&](T x) -> int {\n      \
    \      int res = 0;\n            int ll = l, rr = r;\n            for (int i =\
    \ LOG - 1; i >= 0; i--) {\n                bool flag = x >> i & 1;\n         \
    \       res += flag * (mat[i].rank(r) - mat[i].rank(l));\n                l =\
    \ id(l, i, flag);\n                r = id(r, i, flag);\n            }\n      \
    \      l = ll, r = rr;\n            return res;\n        };\n        return f(upper)\
    \ - f(lower);\n    }\nprivate:\n    struct bit_vector {\n        bit_vector()\
    \ = default;\n        bit_vector(const vector<bool> &v) {\n            int n =\
    \ v.size();\n            int m = n / b + 1;\n            d = vector<unsigned>(m);\n\
    \            sum = vector<int>(m + 1);\n            for (int i = 0; i < n; i++)\
    \ {\n                d[i / b] |= v[i] << (i % b);\n            }\n           \
    \ for (int i = 0; i < m; i++) {\n                sum[i + 1] = sum[i] + __builtin_popcount(d[i]);\n\
    \            }\n        }\n        bool operator[](int i) const { return d[i /\
    \ b] >> (i % b) & 1; }\n        int rank(int i, bool flag = false) const {\n \
    \           int mask = (1U << (i % b)) - 1;\n            int r = sum[i / b] +\
    \ __builtin_popcount(d[i / b] & mask);\n            return flag ? r : i - r;\n\
    \        }\n        int select(int i, bool flag) const {\n            int l =\
    \ 0, r = d.size();\n            while (r - l > 1) {\n                int m = (l\
    \ + r) >> 1;\n                (rank(i, flag) < i ? l : r) = m;\n            }\n\
    \            return l;\n        }\n    private:\n        static constexpr int\
    \ b = 32;\n        vector<unsigned> d;\n        vector<int> sum;\n    };\n   \
    \ int n;\n    vector<T> d;\n    vector<bit_vector> mat;\n    vector<int> cnt;\n\
    \    unordered_map<T, int> st;\n    bool built;\n    void build() {\n        if\
    \ (built) return;\n        mat = vector<bit_vector>(LOG);\n        cnt = vector<int>(LOG);\n\
    \        for (auto &x : d) assert(x >= 0);\n        for (int i = LOG - 1; i >=\
    \ 0; i--) {\n            vector<bool> bit(n);\n            for (int j = 0; j <\
    \ n; j++) {\n                bit[j] = d[j] >> i & 1;\n            }\n        \
    \    mat[i] = bit_vector(bit);\n            int c0 = 0, c1 = n;\n            for\
    \ (int j = 0; j < n; j++) {\n                if (!bit[j]) c0++;\n            }\n\
    \            cnt[i] = c0;\n            vector<T> d2(n);\n            for (int\
    \ j = n - 1; j >= 0; j--) {\n                d2[--(bit[j] ? c1 : c0)] = d[j];\n\
    \            }\n            d = d2;\n        }\n        for (int i = 0; i < n;\
    \ i++) {\n            if (st.find(d[i]) == st.end()) st[d[i]] = i;\n        }\n\
    \        built = true;\n    }\n    int id(int p, int i, bool flag) {\n       \
    \ return cnt[i] * flag + mat[i].rank(p, flag);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/range_query/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/range_query/wavelet_matrix_range_freq.test.cpp
  - test/data_structure/range_query/wavelet_matrix_kth_smallest.test.cpp
documentation_of: src/data_structure/range_query/wavelet_matrix.hpp
layout: document
title: Wavelet Matrix
---

Wavelet Matrix.

`LOG` を $L$ とし, 登場する値は全て $0$ 以上 $2^L$ 未満とする.

`set` 以外の関数が最初に呼ばれた時とき, $O(nL)$ で構築を行う.
また, `prev_val` と `next_val` で存在しない場合の $-1$ を使うには, `T` を符号付き整数型にする必要がある.


## Constructor

```
wavelet_matrix<T, LOG> wm
wavelet_matrix<T, LOG> wm(int n)
wavelet_matrix<T, LOG> wm(vector<T> v)
```

- 空の列, 長さ $n$ の $0$ で初期化された列, または $v$ を初期値とする列を作る
- `T` は整数型, `LOG` は扱う値のビット数で, 省略時は `numeric_limits<T>::digits`

## set

```
void set(int p, T x)
```

- $p$ 番目の要素を $x$ に変更する
- 構築前に呼ぶ必要がある(`set` 以外の関数を呼ぶと自動で構築される)
- $O(1)$

## get

```
T get(int p)
```

- $p$ 番目の要素を返す
- $O(L)$

## range_kth_smallest

```
T range_kth_smallest(int l, int r, int k)
```

- $[l,r)$ の要素を昇順に並べたときの $k$ 番目 (0-indexed) の値を返す
- $0 \leq k < r-l$ が必要
- $O(L)$

## prev_val

```
T prev_val(int l, int r, T upper)
```

- $[l,r)$ に含まれる `upper` 未満の値の最大値を返す
- 存在しない場合は $-1$ を返す
- $O(L)$

## next_val

```
T next_val(int l, int r, T lower)
```

- $[l,r)$ に含まれる `lower` 以上の値の最小値を返す
- 存在しない場合は $-1$ を返す
- $O(L)$

## count

```
int count(int l, int r, T x)
```

- $[l,r)$ に含まれる $x$ の個数を返す
- $O(L)$

## range_freq

```
int range_freq(int l, int r, T lower, T upper)
```

- $[l,r)$ に含まれる `lower` 以上 `upper` 未満の値の個数を返す
- `lower` $\leq$ `upper` が必要
- $O(L)$

