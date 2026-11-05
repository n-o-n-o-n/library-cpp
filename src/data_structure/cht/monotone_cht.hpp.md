---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/cht/monotone_cht.test.cpp
    title: test/data_structure/cht/monotone_cht.test.cpp
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
    \ }\n#line 3 \"src/data_structure/cht/monotone_cht.hpp\"\n\ntemplate<typename\
    \ T, bool query_dec = false>\nstruct monotone_cht {\n    using W = conditional_t<sizeof(T)\
    \ <= 4, long long, __int128_t>;\n    monotone_cht() = default;\n    void add_line(T\
    \ a, T b) {\n        line l(a, b);\n        if (q.empty()) {\n            pa =\
    \ a;\n            q.push_back(l);\n            return;\n        }\n        if\
    \ (!dir && a != pa) dir = a > pa ? 1 : -1;\n        if (q[q.size() - 1].a == a)\
    \ {\n            if (q[q.size() - 1].b <= b) return;\n            q.pop_back();\n\
    \        }\n        while (q.size() >= 2 && check(\n            q[q.size() - 2],\n\
    \            q[q.size() - 1],\n            l,\n            dir > 0\n        ))\
    \ q.pop_back();\n        q.push_back(l);\n        pa = a;\n    }\n    T get(T\
    \ x) {\n        if (q.empty()) return inf<T>();\n        if ((dir > 0) == query_dec)\
    \ {\n            while (q.size() >= 2 && q[0].get(x) > q[1].get(x)) q.pop_front();\n\
    \            return q[0].get(x);\n        } else {\n            while (q.size()\
    \ >= 2 && q[q.size() - 1].get(x) > q[q.size() - 2].get(x)) q.pop_back();\n   \
    \         return q[q.size() - 1].get(x);\n        }\n    }\nprivate:\n    struct\
    \ line {\n        T a, b;\n        line(T _a, T _b) : a(_a), b(_b) {}\n      \
    \  T get(T x) const { return a * x + b; }\n    };\n    deque<line> q;\n    T pa;\n\
    \    int dir = 0;\n    static bool check(line l1, line l2, line l3, bool f) {\n\
    \        W l = W(l2.b - l1.b) * (l3.a - l2.a);\n        W r = W(l3.b - l2.b) *\
    \ (l2.a - l1.a);\n        return f ? l >= r : l <= r;\n    }\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\ntemplate<typename T, bool\
    \ query_dec = false>\nstruct monotone_cht {\n    using W = conditional_t<sizeof(T)\
    \ <= 4, long long, __int128_t>;\n    monotone_cht() = default;\n    void add_line(T\
    \ a, T b) {\n        line l(a, b);\n        if (q.empty()) {\n            pa =\
    \ a;\n            q.push_back(l);\n            return;\n        }\n        if\
    \ (!dir && a != pa) dir = a > pa ? 1 : -1;\n        if (q[q.size() - 1].a == a)\
    \ {\n            if (q[q.size() - 1].b <= b) return;\n            q.pop_back();\n\
    \        }\n        while (q.size() >= 2 && check(\n            q[q.size() - 2],\n\
    \            q[q.size() - 1],\n            l,\n            dir > 0\n        ))\
    \ q.pop_back();\n        q.push_back(l);\n        pa = a;\n    }\n    T get(T\
    \ x) {\n        if (q.empty()) return inf<T>();\n        if ((dir > 0) == query_dec)\
    \ {\n            while (q.size() >= 2 && q[0].get(x) > q[1].get(x)) q.pop_front();\n\
    \            return q[0].get(x);\n        } else {\n            while (q.size()\
    \ >= 2 && q[q.size() - 1].get(x) > q[q.size() - 2].get(x)) q.pop_back();\n   \
    \         return q[q.size() - 1].get(x);\n        }\n    }\nprivate:\n    struct\
    \ line {\n        T a, b;\n        line(T _a, T _b) : a(_a), b(_b) {}\n      \
    \  T get(T x) const { return a * x + b; }\n    };\n    deque<line> q;\n    T pa;\n\
    \    int dir = 0;\n    static bool check(line l1, line l2, line l3, bool f) {\n\
    \        W l = W(l2.b - l1.b) * (l3.a - l2.a);\n        W r = W(l3.b - l2.b) *\
    \ (l2.a - l1.a);\n        return f ? l >= r : l <= r;\n    }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/data_structure/cht/monotone_cht.hpp
  requiredBy: []
  timestamp: '2026-11-05 23:32:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/cht/monotone_cht.test.cpp
documentation_of: src/data_structure/cht/monotone_cht.hpp
layout: document
title: Monotone Convex Hull Trick
---

傾きとクエリ点がそれぞれ単調な直線集合に対し, 値の最小値を求める CHT.

## Constructor

```
monotone_cht<T, query_dec> cht
```

- `T` は座標と直線の値の整数型
- `query_dec = false` ならクエリ点は単調非減少, `true` なら単調非増加. 省略時は `false`
- 追加する直線の傾きは単調非増加または単調非減少. 向きは自動で判定する

## add_line

```
void add_line(T a, T b)
```

- 直線 $y=ax+b$ を追加する
- ならし $O(1)$

## get

```
T get(T x)
```

- $x$ における直線の値の最小値を返す
- 直線がない場合は `inf<T>()` を返す
- ならし $O(1)$
