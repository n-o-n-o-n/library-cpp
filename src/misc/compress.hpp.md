---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/misc/merge_and_unique.hpp
    title: Merge And Unique
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/misc/inversion_number.hpp
    title: src/misc/inversion_number.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/persistent_ds/persistent_segtree.test.cpp
    title: test/data_structure/persistent_ds/persistent_segtree.test.cpp
  - icon: ':x:'
    path: test/graph/functional_graph.test.cpp
    title: test/graph/functional_graph.test.cpp
  - icon: ':x:'
    path: test/graph/weighted_functional_graph.test.cpp
    title: test/graph/weighted_functional_graph.test.cpp
  - icon: ':x:'
    path: test/misc/inversion_number.test.cpp
    title: test/misc/inversion_number.test.cpp
  - icon: ':x:'
    path: test/misc/mo_static_range_count_distinct.test.cpp
    title: test/misc/mo_static_range_count_distinct.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ return res;\n}\n#line 4 \"src/misc/compress.hpp\"\n\ntemplate<typename T>\n\
    vector<int> compress(const vector<T> &v) {\n    auto zip = merge_and_unique(v);\n\
    \    vector<int> res;\n    res.reserve(v.size());\n    for (const T &e : v) {\n\
    \        res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());\n\
    \    }\n    return res;\n}\n\ntemplate<typename T, typename... Ts>\nauto compress(const\
    \ vector<T> &a, const Ts &...z) {\n    auto zip = merge_and_unique(a, z...);\n\
    \    auto f = [&] (const vector<T> &v) -> vector<int> {\n        vector<int> res;\n\
    \        res.reserve(v.size());\n        for (const T &e : v) {\n            res.push_back(lower_bound(zip.begin(),\
    \ zip.end(), e) - zip.begin());\n        }\n        return res;\n    };\n    return\
    \ make_tuple(f(a), f(z)...);\n}\n\ntemplate<typename T, typename... Ts>\nint compress_inplace(vector<T>\
    \ &a, Ts &...z) {\n    auto zip = merge_and_unique(a, z...);\n    auto f = [&]\
    \ (vector<T> &v) -> void {\n        for (T &e : v) {\n            e = lower_bound(zip.begin(),\
    \ zip.end(), e) - zip.begin();\n        }\n    };\n    (f(a), ..., f(z));\n  \
    \  return (int)zip.size();\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"merge_and_unique.hpp\"\
    \n\ntemplate<typename T>\nvector<int> compress(const vector<T> &v) {\n    auto\
    \ zip = merge_and_unique(v);\n    vector<int> res;\n    res.reserve(v.size());\n\
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
  - src/template.hpp
  - src/misc/merge_and_unique.hpp
  isVerificationFile: false
  path: src/misc/compress.hpp
  requiredBy:
  - src/misc/inversion_number.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/graph/functional_graph.test.cpp
  - test/graph/weighted_functional_graph.test.cpp
  - test/data_structure/persistent_ds/persistent_segtree.test.cpp
  - test/misc/mo_static_range_count_distinct.test.cpp
  - test/misc/inversion_number.test.cpp
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
