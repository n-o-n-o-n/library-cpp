---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/set/top_k_set.test.cpp
    title: test/data_structure/set/top_k_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/set/top_k_set.hpp\"\n#include <cassert>\n\
    #include <set>\nusing namespace std;\n\ntemplate<typename T1, typename T2 = long\
    \ long, typename Compare = less<T1>>\nstruct top_k_set {\n    top_k_set(int _k)\
    \ : k(_k), lower_sum(0) {}\n    void insert(T1 x) {\n        if (k > 0 && ((int)lower.size()\
    \ < k || Compare()(x, *prev(lower.end())))) {\n            lower_sum += x;\n \
    \           lower.insert(x);\n        } else {\n            upper.insert(x);\n\
    \        }\n        normalize();\n    }\n    void erase(T1 x) {\n        auto\
    \ it = lower.find(x);\n        if (it != lower.end()) {\n            lower_sum\
    \ -= *it;\n            lower.erase(it);\n        } else {\n            it = upper.find(x);\n\
    \            assert(it != upper.end());\n            upper.erase(it);\n      \
    \  }\n        normalize();\n    }\n    T1 kth_val() const {\n        assert((int)lower.size()\
    \ == k);\n        return *prev(lower.end());\n    }\n    T2 sum() const {\n  \
    \      return lower_sum;\n    }\nprivate:\n    int k;\n    multiset<T1, Compare>\
    \ lower, upper;\n    T2 lower_sum;\n    void normalize() {\n        while ((int)lower.size()\
    \ > k) {\n            auto it = prev(lower.end());\n            upper.insert(*it);\n\
    \            lower_sum -= *it;\n            lower.erase(it);\n        }\n    \
    \    while ((int)lower.size() < k && upper.size()) {\n            auto it = upper.begin();\n\
    \            lower_sum += *it;\n            lower.insert(*it);\n            upper.erase(it);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <set>\nusing namespace std;\n\n\
    template<typename T1, typename T2 = long long, typename Compare = less<T1>>\n\
    struct top_k_set {\n    top_k_set(int _k) : k(_k), lower_sum(0) {}\n    void insert(T1\
    \ x) {\n        if (k > 0 && ((int)lower.size() < k || Compare()(x, *prev(lower.end()))))\
    \ {\n            lower_sum += x;\n            lower.insert(x);\n        } else\
    \ {\n            upper.insert(x);\n        }\n        normalize();\n    }\n  \
    \  void erase(T1 x) {\n        auto it = lower.find(x);\n        if (it != lower.end())\
    \ {\n            lower_sum -= *it;\n            lower.erase(it);\n        } else\
    \ {\n            it = upper.find(x);\n            assert(it != upper.end());\n\
    \            upper.erase(it);\n        }\n        normalize();\n    }\n    T1\
    \ kth_val() const {\n        assert((int)lower.size() == k);\n        return *prev(lower.end());\n\
    \    }\n    T2 sum() const {\n        return lower_sum;\n    }\nprivate:\n   \
    \ int k;\n    multiset<T1, Compare> lower, upper;\n    T2 lower_sum;\n    void\
    \ normalize() {\n        while ((int)lower.size() > k) {\n            auto it\
    \ = prev(lower.end());\n            upper.insert(*it);\n            lower_sum\
    \ -= *it;\n            lower.erase(it);\n        }\n        while ((int)lower.size()\
    \ < k && upper.size()) {\n            auto it = upper.begin();\n            lower_sum\
    \ += *it;\n            lower.insert(*it);\n            upper.erase(it);\n    \
    \    }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/set/top_k_set.hpp
  requiredBy: []
  timestamp: '2026-10-24 11:13:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/set/top_k_set.test.cpp
documentation_of: src/data_structure/set/top_k_set.hpp
layout: document
title: Top K Set
---

多重集合の上位 $k$ 個の値とその総和を管理する.
比較関数が既定の `less<T1>` のときは小さい方から, `greater<T1>` のときは大きい方から数える.

管理する要素数を $n$ とする.

## Constructor

```
top_k_set<T1, T2, Compare> s(int k)
```

- 空の集合を作り, 管理する個数 $k$ を固定する
- `T1` は値の型, `T2` は総和の型
- `Compare` の既定は `less<T1>`

## insert

```
void insert(T1 x)
```

- 値 $x$ を一つ追加する
- $O(\log n)$

## erase

```
void erase(T1 x)
```

- 値 $x$ を一つ削除する
- $x$ が含まれない場合は何もしない
- $O(\log n)$

## kth_val

```
T1 kth_val()
```

- 比較順で $k$ 番目(1-indexed)の値を返す
- $n\geq k$ が必要
- $O(1)$

## sum

```
T2 sum()
```

- 比較順で先頭から $\min(k,n)$ 個の値の総和を返す
- $O(1)$
