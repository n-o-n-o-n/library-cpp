---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/cht/line_add_get_min.test.cpp
    title: test/data_structure/cht/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/data_structure/cht/segment_add_get_min.test.cpp
    title: test/data_structure/cht/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/cht/li_chao_tree.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct li_chao_tree {\n    li_chao_tree() : built(false)\
    \ {}\n    li_chao_tree(const vector<T> &_xs) : xs(_xs), built(false) {\n     \
    \   build();\n    }\n    void add_point(T x) {\n        assert(!built);\n    \
    \    xs.push_back(x);\n    }\n    void add_line(T a, T b) {\n        build();\n\
    \        update(line(a, b), 1, 0, sz);\n    }\n    void add_segment(T xl, T xr,\
    \ T a, T b) {\n        build();\n        int l = lower_bound(xs.begin(), xs.begin()\
    \ + n, xl) - xs.begin();\n        int r = lower_bound(xs.begin(), xs.begin() +\
    \ n, xr) - xs.begin();\n        line f(a, b);\n        int len = 1, ll = l, rr\
    \ = r;\n        l += sz, r += sz;\n        while (l < r) {\n            if (l\
    \ & 1) {\n                update(f, l++, ll, ll + len);\n                ll +=\
    \ len;\n            }\n            if (r & 1) {\n                rr -= len;\n\
    \                update(f, --r, rr, rr + len);\n            }\n            l >>=\
    \ 1;\n            r >>= 1;\n            len <<= 1;\n        }\n    }\n    T get_min(T\
    \ x) {\n        build();\n        int p = lower_bound(xs.begin(), xs.end(), x)\
    \ - xs.begin();\n        assert(xs[p] == x);\n        p += sz;\n        T res\
    \ = inf;\n        for (int i = 0; i <= log; i++) {\n            res = min(res,\
    \ d[p >> i](x));\n        }\n        return res;\n    }\nprivate:\n    struct\
    \ line {\n        T a, b;\n        line(T _a, T _b) : a(_a), b(_b) {}\n      \
    \  T operator()(T x) const {\n            return a * x + b;\n        }\n    };\n\
    \    int n, log, sz;\n    vector<T> xs;\n    vector<line> d;\n    bool built;\n\
    \    static constexpr T inf = numeric_limits<T>::max();\n    static constexpr\
    \ line e() {\n        return line(0, inf);\n    }\n    void build() {\n      \
    \  if (built) return;\n        if (xs.empty()) xs.push_back(0);\n        sort(xs.begin(),\
    \ xs.end());\n        xs.erase(unique(xs.begin(), xs.end()), xs.end());\n    \
    \    n = xs.size();\n        log = 1;\n        while ((1 << log) < n) log++;\n\
    \        sz = 1 << log;\n        d = vector<line>(2 * sz, e());\n        while\
    \ ((int)xs.size() <= sz) xs.push_back(xs.back() + 1);\n        built = true;\n\
    \    }\n    void update(line f, int p, int l, int r) {\n        auto &g = d[p];\n\
    \        int m = (l + r) / 2;\n        bool pl = f(xs[l]) < g(xs[l]);\n      \
    \  bool pm = f(xs[m]) < g(xs[m]);\n        bool pr = f(xs[r]) < g(xs[r]);\n  \
    \      if (!pl && !pr) return;\n        if (pl && pr) {\n            g = f;\n\
    \            return;\n        }\n        if (pm) swap(f, g);\n        if (l +\
    \ 1 == r) return;\n        if (pl ^ pm) {\n            update(f, 2 * p, l, m);\n\
    \        } else {\n            update(f, 2 * p + 1, m, r);\n        }\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<typename T>\nstruct li_chao_tree\
    \ {\n    li_chao_tree() : built(false) {}\n    li_chao_tree(const vector<T> &_xs)\
    \ : xs(_xs), built(false) {\n        build();\n    }\n    void add_point(T x)\
    \ {\n        assert(!built);\n        xs.push_back(x);\n    }\n    void add_line(T\
    \ a, T b) {\n        build();\n        update(line(a, b), 1, 0, sz);\n    }\n\
    \    void add_segment(T xl, T xr, T a, T b) {\n        build();\n        int l\
    \ = lower_bound(xs.begin(), xs.begin() + n, xl) - xs.begin();\n        int r =\
    \ lower_bound(xs.begin(), xs.begin() + n, xr) - xs.begin();\n        line f(a,\
    \ b);\n        int len = 1, ll = l, rr = r;\n        l += sz, r += sz;\n     \
    \   while (l < r) {\n            if (l & 1) {\n                update(f, l++,\
    \ ll, ll + len);\n                ll += len;\n            }\n            if (r\
    \ & 1) {\n                rr -= len;\n                update(f, --r, rr, rr +\
    \ len);\n            }\n            l >>= 1;\n            r >>= 1;\n         \
    \   len <<= 1;\n        }\n    }\n    T get_min(T x) {\n        build();\n   \
    \     int p = lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n        assert(xs[p]\
    \ == x);\n        p += sz;\n        T res = inf;\n        for (int i = 0; i <=\
    \ log; i++) {\n            res = min(res, d[p >> i](x));\n        }\n        return\
    \ res;\n    }\nprivate:\n    struct line {\n        T a, b;\n        line(T _a,\
    \ T _b) : a(_a), b(_b) {}\n        T operator()(T x) const {\n            return\
    \ a * x + b;\n        }\n    };\n    int n, log, sz;\n    vector<T> xs;\n    vector<line>\
    \ d;\n    bool built;\n    static constexpr T inf = numeric_limits<T>::max();\n\
    \    static constexpr line e() {\n        return line(0, inf);\n    }\n    void\
    \ build() {\n        if (built) return;\n        if (xs.empty()) xs.push_back(0);\n\
    \        sort(xs.begin(), xs.end());\n        xs.erase(unique(xs.begin(), xs.end()),\
    \ xs.end());\n        n = xs.size();\n        log = 1;\n        while ((1 << log)\
    \ < n) log++;\n        sz = 1 << log;\n        d = vector<line>(2 * sz, e());\n\
    \        while ((int)xs.size() <= sz) xs.push_back(xs.back() + 1);\n        built\
    \ = true;\n    }\n    void update(line f, int p, int l, int r) {\n        auto\
    \ &g = d[p];\n        int m = (l + r) / 2;\n        bool pl = f(xs[l]) < g(xs[l]);\n\
    \        bool pm = f(xs[m]) < g(xs[m]);\n        bool pr = f(xs[r]) < g(xs[r]);\n\
    \        if (!pl && !pr) return;\n        if (pl && pr) {\n            g = f;\n\
    \            return;\n        }\n        if (pm) swap(f, g);\n        if (l +\
    \ 1 == r) return;\n        if (pl ^ pm) {\n            update(f, 2 * p, l, m);\n\
    \        } else {\n            update(f, 2 * p + 1, m, r);\n        }\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/cht/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/cht/segment_add_get_min.test.cpp
  - test/data_structure/cht/line_add_get_min.test.cpp
documentation_of: src/data_structure/cht/li_chao_tree.hpp
layout: document
title: Li Chao Tree
---

Li Chao Tree.

最小値クエリで使われる点の個数を $n$ とする.
`add_point` 以外の関数が呼ばれたタイミング (または `xs` を渡して宣言したとき) で $O(n\log n)$ で構築を行う.

## Constructor

```
li_chao_tree<T> lct
li_chao_tree<T> lct(vector<T> xs)
```

- 空の構造を作る, または `xs` をクエリの点集合として構築する
- `T` は座標と直線の値の型

## add_point

```
void add_point(T x)
```

- クエリで用いる $x$ を追加する
- `xs` を渡して構築した場合や, `add_point` 以外の関数を呼んでからは呼べない

## add_line

```
void add_line(T a, T b)
```

- 直線 $y=ax+b$ を追加する
- $O(\log n)$

## add_segment

```
void add_segment(T xl, T xr, T a, T b)
```

- $xl\leq x<xr$ 上に線分 $y=ax+b$ を追加する
- $O(\log^2 n)$

## get_min

```
T get_min(T x)
```

- $x$ における直線の値の最小値を返す
- $x$ は `xs`, または `add_point` で追加した点に含まれる必要がある
- 対象となる直線がない場合は `numeric_limits<T>::max()` を返す
- $O(\log n)$