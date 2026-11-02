---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp
    title: Dynamic Rectangle Sum
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rectangle_query/rectangle_sum.hpp
    title: src/data_structure/rectangle_query/rectangle_sum.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/compress.hpp
    title: Compress
  - icon: ':heavy_check_mark:'
    path: src/misc/inversion_number.hpp
    title: src/misc/inversion_number.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/persistent_ds/persistent_segtree.test.cpp
    title: test/data_structure/persistent_ds/persistent_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
    title: test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/rectangle_query/rectangle_sum.test.cpp
    title: test/data_structure/rectangle_query/rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/functional_graph.test.cpp
    title: test/graph/functional_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/weighted_functional_graph.test.cpp
    title: test/graph/weighted_functional_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/misc/inversion_number.test.cpp
    title: test/misc/inversion_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/misc/mo_static_range_count_distinct.test.cpp
    title: test/misc/mo_static_range_count_distinct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/misc/merge_and_unique.hpp\"\n\ntemplate<typename T, typename...\
    \ Ts>\nvector<T> merge_and_unique(const vector<T> &a, const Ts &...z) {\n    vector<T>\
    \ res = a;\n    (res.insert(res.end(), z.begin(), z.end()), ...);\n    sort(res.begin(),\
    \ res.end());\n    res.erase(unique(res.begin(), res.end()), res.end());\n   \
    \ return res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T, typename...\
    \ Ts>\nvector<T> merge_and_unique(const vector<T> &a, const Ts &...z) {\n    vector<T>\
    \ res = a;\n    (res.insert(res.end(), z.begin(), z.end()), ...);\n    sort(res.begin(),\
    \ res.end());\n    res.erase(unique(res.begin(), res.end()), res.end());\n   \
    \ return res;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/misc/merge_and_unique.hpp
  requiredBy:
  - src/data_structure/rectangle_query/rectangle_sum.hpp
  - src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp
  - src/misc/compress.hpp
  - src/misc/inversion_number.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/functional_graph.test.cpp
  - test/graph/weighted_functional_graph.test.cpp
  - test/data_structure/persistent_ds/persistent_segtree.test.cpp
  - test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
  - test/data_structure/rectangle_query/rectangle_sum.test.cpp
  - test/misc/mo_static_range_count_distinct.test.cpp
  - test/misc/inversion_number.test.cpp
documentation_of: src/misc/merge_and_unique.hpp
layout: document
title: Merge And Unique
---

複数の列に含まれる値をまとめ, 重複を除いた昇順の列を作る.

## merge_and_unique

```
vector<T> merge_and_unique(vector<T> a, Ts ...z)
```

- 全列の要素を集め, 重複を除いた昇順の `vector<T>` を返す
- 全列の要素数の合計を $n$ として $O(n\log n)$
