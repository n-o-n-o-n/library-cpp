---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/misc/merge_and_unique.hpp
    title: Merge And Unique
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/misc/inversion_number.hpp
    title: src/misc/inversion_number.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/persistent_ds/persistent_segtree.test.cpp
    title: test/data_structure/persistent_ds/persistent_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/misc/mo_static_range_count_distinct.test.cpp
    title: test/misc/mo_static_range_count_distinct.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/misc/compress.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#line 4 \"src/misc/merge_and_unique.hpp\"\nusing namespace std;\n\n\
    template<typename T, typename... Ts>\nvector<T> merge_and_unique(const vector<T>\
    \ &a, const Ts &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(), z.begin(),\
    \ z.end()), ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 5 \"src/misc/compress.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nvector<int> compress(const vector<T>\
    \ &v) {\n    auto zip = merge_and_unique(v);\n    vector<int> res;\n    res.reserve(v.size());\n\
    \    for (const T &e : v) {\n        res.push_back(lower_bound(zip.begin(), zip.end(),\
    \ e) - zip.begin());\n    }\n    return res;\n}\n\ntemplate<typename T, typename...\
    \ Ts>\nauto compress(const vector<T> &a, const Ts &...z) {\n    auto zip = merge_and_unique(a,\
    \ z...);\n    auto f = [&] (const vector<T> &v) -> vector<int> {\n        vector<int>\
    \ res;\n        res.reserve(v.size());\n        for (const T &e : v) {\n     \
    \       res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());\n\
    \        }\n        return res;\n    };\n    return make_tuple(f(a), f(z)...);\n\
    }\n\ntemplate<typename T, typename... Ts>\nint compress_inplace(vector<T> &a,\
    \ Ts &...z) {\n    auto zip = merge_and_unique(a, z...);\n    auto f = [&] (vector<T>\
    \ &v) -> void {\n        for (T &e : v) {\n            e = lower_bound(zip.begin(),\
    \ zip.end(), e) - zip.begin();\n        }\n    };\n    (f(a), ..., f(z));\n  \
    \  return (int)zip.size();\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"merge_and_unique.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nvector<int> compress(const vector<T>\
    \ &v) {\n    auto zip = merge_and_unique(v);\n    vector<int> res;\n    res.reserve(v.size());\n\
    \    for (const T &e : v) {\n        res.push_back(lower_bound(zip.begin(), zip.end(),\
    \ e) - zip.begin());\n    }\n    return res;\n}\n\ntemplate<typename T, typename...\
    \ Ts>\nauto compress(const vector<T> &a, const Ts &...z) {\n    auto zip = merge_and_unique(a,\
    \ z...);\n    auto f = [&] (const vector<T> &v) -> vector<int> {\n        vector<int>\
    \ res;\n        res.reserve(v.size());\n        for (const T &e : v) {\n     \
    \       res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());\n\
    \        }\n        return res;\n    };\n    return make_tuple(f(a), f(z)...);\n\
    }\n\ntemplate<typename T, typename... Ts>\nint compress_inplace(vector<T> &a,\
    \ Ts &...z) {\n    auto zip = merge_and_unique(a, z...);\n    auto f = [&] (vector<T>\
    \ &v) -> void {\n        for (T &e : v) {\n            e = lower_bound(zip.begin(),\
    \ zip.end(), e) - zip.begin();\n        }\n    };\n    (f(a), ..., f(z));\n  \
    \  return (int)zip.size();\n}"
  dependsOn:
  - src/misc/merge_and_unique.hpp
  isVerificationFile: false
  path: src/misc/compress.hpp
  requiredBy:
  - src/misc/inversion_number.hpp
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/mo_static_range_count_distinct.test.cpp
  - test/data_structure/persistent_ds/persistent_segtree.test.cpp
documentation_of: src/misc/compress.hpp
layout: document
title: Compress
---

座圧.

## compress

```
vector<int> compress(vector<T> v)
auto compress(vector<T> a, Ts ...z)
```

- 1 つの列を渡すと, 各値を順位に置き換えた `vector<int>` を返す
- 複数の列を渡すと, 全列に共通の順位で置き換えた結果を入力順の `tuple` で返す
- 入力の列は変更しない
- 全列の要素数の合計を $n$ として $O(n\log n)$

## compress_inplace

```
int compress_inplace(vector<T> &a, Ts &...z)
```

- 全列に共通の順位で各要素を置き換える
- `T` は順位を代入できる型とする
- 返り値は集合としてのサイズ
- 全列の要素数の合計を $n$ として $O(n\log n)$
