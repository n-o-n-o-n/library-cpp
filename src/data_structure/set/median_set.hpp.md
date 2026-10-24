---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/set/median_set.test.cpp
    title: test/data_structure/set/median_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/set/median_set.hpp\"\n#include <cassert>\n\
    #include <set>\nusing namespace std;\n\ntemplate<typename T1, typename T2 = long\
    \ long>\nstruct median_set {\n    median_set() : upper_sum(0), lower_sum(0) {}\n\
    \    void insert(T1 x) {\n        if (lower.empty() || x <= *prev(lower.end()))\
    \ {\n            lower_sum += x;\n            lower.insert(x);\n        } else\
    \ {\n            upper_sum += x;\n            upper.insert(x);\n        }\n  \
    \      normalize();\n    }\n    void erase(T1 x) {\n        auto it = lower.find(x);\n\
    \        if (it != lower.end()) {\n            lower_sum -= *it;\n           \
    \ lower.erase(it);\n        } else {\n            it = upper.find(x);\n      \
    \      assert(it != upper.end());\n            upper_sum -= *it;\n           \
    \ upper.erase(it);\n        }\n        normalize();\n    }\n    T1 median() const\
    \ {\n        assert(lower.size());\n        return *prev(lower.end());\n    }\n\
    \    T2 min_cost() const {\n        T2 med = median();\n        return (upper_sum\
    \ - med * upper.size()) + (med * lower.size() - lower_sum);\n    }\nprivate:\n\
    \    multiset<T1> upper, lower;\n    T2 upper_sum, lower_sum;\n    void normalize()\
    \ {\n        while (lower.size() > upper.size() + 1) {\n            auto it =\
    \ prev(lower.end());\n            upper_sum += *it;\n            upper.insert(*it);\n\
    \            lower_sum -= *it;\n            lower.erase(it);\n        }\n    \
    \    while (lower.size() < upper.size()) {\n            auto it = upper.begin();\n\
    \            lower_sum += *it;\n            lower.insert(*it);\n            upper_sum\
    \ -= *it;\n            upper.erase(it);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <set>\nusing namespace std;\n\n\
    template<typename T1, typename T2 = long long>\nstruct median_set {\n    median_set()\
    \ : upper_sum(0), lower_sum(0) {}\n    void insert(T1 x) {\n        if (lower.empty()\
    \ || x <= *prev(lower.end())) {\n            lower_sum += x;\n            lower.insert(x);\n\
    \        } else {\n            upper_sum += x;\n            upper.insert(x);\n\
    \        }\n        normalize();\n    }\n    void erase(T1 x) {\n        auto\
    \ it = lower.find(x);\n        if (it != lower.end()) {\n            lower_sum\
    \ -= *it;\n            lower.erase(it);\n        } else {\n            it = upper.find(x);\n\
    \            assert(it != upper.end());\n            upper_sum -= *it;\n     \
    \       upper.erase(it);\n        }\n        normalize();\n    }\n    T1 median()\
    \ const {\n        assert(lower.size());\n        return *prev(lower.end());\n\
    \    }\n    T2 min_cost() const {\n        T2 med = median();\n        return\
    \ (upper_sum - med * upper.size()) + (med * lower.size() - lower_sum);\n    }\n\
    private:\n    multiset<T1> upper, lower;\n    T2 upper_sum, lower_sum;\n    void\
    \ normalize() {\n        while (lower.size() > upper.size() + 1) {\n         \
    \   auto it = prev(lower.end());\n            upper_sum += *it;\n            upper.insert(*it);\n\
    \            lower_sum -= *it;\n            lower.erase(it);\n        }\n    \
    \    while (lower.size() < upper.size()) {\n            auto it = upper.begin();\n\
    \            lower_sum += *it;\n            lower.insert(*it);\n            upper_sum\
    \ -= *it;\n            upper.erase(it);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/set/median_set.hpp
  requiredBy: []
  timestamp: '2026-10-24 11:13:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/set/median_set.test.cpp
documentation_of: src/data_structure/set/median_set.hpp
layout: document
title: Median Set
---

中央値を管理する multiset.
要素数が偶数のときは, 中央にある二つの値のうち小さい方を中央値とする.

管理する要素数を $n$ とする.

## Constructor

```
median_set<T1, T2> s
```

- 空の集合を作る
- `T1` は値の型, `T2` は総和の型

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
- $x$ が集合に存在することが必要
- $O(\log n)$

## median

```
T1 median()
```

- 集合の中央値を返す
- $n \ge 1$ が必要
- $O(1)$

## min_cost

```
T2 min_cost()
```

- 集合の値を $a_1, \ldots, a_n$ としたとき, $\min_x \sum_{i=1}^{n} |a_i-x|$ を返す
- $n \ge 1$ が必要
- $O(1)$
