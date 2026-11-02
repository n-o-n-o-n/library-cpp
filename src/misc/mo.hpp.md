---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/misc/mo_static_range_count_distinct.test.cpp
    title: test/misc/mo_static_range_count_distinct.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/misc/mo.hpp\"\n\nstruct MO {\n    MO(int _n, int _q = 0) :\
    \ n(_n), q(_q) { querys.reserve(q); }\n    void add_query(int l, int r) { querys.emplace_back(l,\
    \ r); }\n    template<typename EXL, typename EXR, typename SHL, typename SHR,\
    \ typename O>\n    void run(const EXL &exl, const EXR &exr, const SHL &shl, const\
    \ SHR &shr, const O &out) {\n        q = querys.size();\n        const int b =\
    \ clamp(int(sqrtl(q * 0.66)), 1, max(1, n));\n        vector<int> ord(q);\n  \
    \      iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(), ord.end(),\
    \ [&](int i, int j) {\n            auto [li, ri] = querys[i];\n            auto\
    \ [lj, rj] = querys[j];\n            int bi = li / b, bj = lj / b;\n         \
    \   return bi == bj ? bi & 1 ? ri > rj : ri < rj : bi < bj;\n        });\n   \
    \     int l = 0, r = 0;\n        for (int i : ord) {\n            auto [li, ri]\
    \ = querys[i];\n            while (l > li) exl(--l);\n            while (r < ri)\
    \ exr(r++);\n            while (l < li) shl(l++);\n            while (r > ri)\
    \ shr(--r);\n            out(i);\n        }\n    }\n    template<typename EX,\
    \ typename SH, typename O>\n    void run(const EX &ex, const SH &sh, const O &out)\
    \ {\n        run(ex, ex, sh, sh, out);\n    }\nprivate:\n    int n, q;\n    vector<pair<int,\
    \ int>> querys;\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nstruct MO {\n    MO(int _n,\
    \ int _q = 0) : n(_n), q(_q) { querys.reserve(q); }\n    void add_query(int l,\
    \ int r) { querys.emplace_back(l, r); }\n    template<typename EXL, typename EXR,\
    \ typename SHL, typename SHR, typename O>\n    void run(const EXL &exl, const\
    \ EXR &exr, const SHL &shl, const SHR &shr, const O &out) {\n        q = querys.size();\n\
    \        const int b = clamp(int(sqrtl(q * 0.66)), 1, max(1, n));\n        vector<int>\
    \ ord(q);\n        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(),\
    \ ord.end(), [&](int i, int j) {\n            auto [li, ri] = querys[i];\n   \
    \         auto [lj, rj] = querys[j];\n            int bi = li / b, bj = lj / b;\n\
    \            return bi == bj ? bi & 1 ? ri > rj : ri < rj : bi < bj;\n       \
    \ });\n        int l = 0, r = 0;\n        for (int i : ord) {\n            auto\
    \ [li, ri] = querys[i];\n            while (l > li) exl(--l);\n            while\
    \ (r < ri) exr(r++);\n            while (l < li) shl(l++);\n            while\
    \ (r > ri) shr(--r);\n            out(i);\n        }\n    }\n    template<typename\
    \ EX, typename SH, typename O>\n    void run(const EX &ex, const SH &sh, const\
    \ O &out) {\n        run(ex, ex, sh, sh, out);\n    }\nprivate:\n    int n, q;\n\
    \    vector<pair<int, int>> querys;\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/misc/mo.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/misc/mo_static_range_count_distinct.test.cpp
documentation_of: src/misc/mo.hpp
layout: document
title: Mo
---

列 $a$ に対する区間クエリをオフラインで扱う. 計算量はラムダ式内部での計算を無視している.

## Constructor

```
MO mo(int n, int q = 0)
```

- $n$ は $a$ の長さ
- $q$ はクエリ数

## add_query

```
void add_query(int l, int r)
```

- クエリ $[l,r)$ を追加する

## run

```
void run(exl, exr, shl, shr, out)
void run(ex, sh, out)
```

- クエリを処理する
- 各引数はラムダ式の関数が想定される
- `exl(i)` は左端へ $a_i$ を追加し, `exr(i)` は右端へ $a_i$ を追加する
- `shl(i)` は左端から $a_i$ を削除し, `shr(i)` は右端から $a_i$ を削除する
- `out(i)` は$i$ 番目に追加されたクエリの答えを記録する
- `exl` と `exr`, `shl` と `shr` が同じ処理をする場合は `ex`, `sh`, `out` のみで呼ぶこともできる
- $O(n\sqrt{q})$
