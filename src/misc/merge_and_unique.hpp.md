---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp
    title: Dynamic Rectangle Sum
  - icon: ':heavy_check_mark:'
    path: src/data_structure/rectangle_query/rectangle_sum.hpp
    title: src/data_structure/rectangle_query/rectangle_sum.hpp
  - icon: ':question:'
    path: src/misc/compress.hpp
    title: Compress
  - icon: ':warning:'
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
  - icon: ':x:'
    path: test/misc/mo_static_range_count_distinct.test.cpp
    title: test/misc/mo_static_range_count_distinct.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/misc/merge_and_unique.hpp\"\n#include <algorithm>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename T, typename... Ts>\n\
    vector<T> merge_and_unique(const vector<T> &a, const Ts &...z) {\n    vector<T>\
    \ res = a;\n    (res.insert(res.end(), z.begin(), z.end()), ...);\n    sort(res.begin(),\
    \ res.end());\n    res.erase(unique(res.begin(), res.end()), res.end());\n   \
    \ return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T, typename... Ts>\nvector<T> merge_and_unique(const vector<T>\
    \ &a, const Ts &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(), z.begin(),\
    \ z.end()), ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/merge_and_unique.hpp
  requiredBy:
  - src/misc/inversion_number.hpp
  - src/misc/compress.hpp
  - src/data_structure/rectangle_query/rectangle_sum.hpp
  - src/data_structure/rectangle_query/dynamic_rectangle_sum.hpp
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/misc/mo_static_range_count_distinct.test.cpp
  - test/data_structure/rectangle_query/rectangle_sum.test.cpp
  - test/data_structure/rectangle_query/dynamic_rectangle_sum.test.cpp
  - test/data_structure/persistent_ds/persistent_segtree.test.cpp
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
