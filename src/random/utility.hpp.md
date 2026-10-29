---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/random/graph.hpp
    title: src/random/graph.hpp
  - icon: ':heavy_check_mark:'
    path: src/random/sequence.hpp
    title: Random Sequence
  - icon: ':heavy_check_mark:'
    path: src/tree/hash_on_tree.hpp
    title: src/tree/hash_on_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/set/median_set.test.cpp
    title: test/data_structure/set/median_set.test.cpp
  - icon: ':x:'
    path: test/fps/fps_div_sparse.test.cpp
    title: test/fps/fps_div_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/power_projection.test.cpp
    title: test/fps/power_projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/discrete_logarithm.test.cpp
    title: test/math/number_theory/discrete_logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/mod_inv.test.cpp
    title: test/math/number_theory/mod_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/hash_on_tree.test.cpp
    title: test/tree/hash_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/prufer_code.test.cpp
    title: test/tree/prufer_code.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/random/utility.hpp\"\n#include <cassert>\n#include <concepts>\n\
    #include <random>\nusing namespace std;\n\nnamespace rng {\n\ninline random_device\
    \ seed;\ninline mt19937 eng(seed());\n\ntemplate<typename T>\nvoid set_seed(const\
    \ T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral T>\ninline T randint(T lo,\
    \ T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T> dist(lo, hi);\n\
    \    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T, T> randpair(T\
    \ lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n    T l =\
    \ randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n    return make_pair(l,\
    \ r);\n}\n\n} // namespace rng\n"
  code: "#pragma once\n#include <cassert>\n#include <concepts>\n#include <random>\n\
    using namespace std;\n\nnamespace rng {\n\ninline random_device seed;\ninline\
    \ mt19937 eng(seed());\n\ntemplate<typename T>\nvoid set_seed(const T &sd) {\n\
    \    eng.seed(sd);\n}\n\ntemplate<integral T>\ninline T randint(T lo, T hi) {\n\
    \    assert(lo <= hi);\n    uniform_int_distribution<T> dist(lo, hi);\n    return\
    \ dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T, T> randpair(T lo, T hi,\
    \ bool strict = false) {\n    assert(lo + strict <= hi);\n    T l = randint(lo,\
    \ hi - strict);\n    T r = randint(l + strict, hi);\n    return make_pair(l, r);\n\
    }\n\n} // namespace rng"
  dependsOn: []
  isVerificationFile: false
  path: src/random/utility.hpp
  requiredBy:
  - src/random/graph.hpp
  - src/random/sequence.hpp
  - src/tree/hash_on_tree.hpp
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/math/number_theory/mod_inv.test.cpp
  - test/math/number_theory/discrete_logarithm.test.cpp
  - test/fps/power_projection.test.cpp
  - test/fps/fps_div_sparse.test.cpp
  - test/tree/prufer_code.test.cpp
  - test/tree/hash_on_tree.test.cpp
  - test/data_structure/set/median_set.test.cpp
documentation_of: src/random/utility.hpp
layout: document
title: Random Utility
---

`rng` 名前空間で整数乱数と整数の組を生成する.

## set_seed

```
void rng::set_seed(T sd)
```

- 乱数生成器のシードを $sd$ に設定する

## randint

```
T rng::randint(T lo, T hi)
```

- $lo$ 以上 $hi$ 以下の整数を生成する
- $lo \le hi$ とする

## randpair

```
pair<T, T> rng::randpair(T lo, T hi, bool strict = false)
```

- $lo \le l \le r \le hi$ を満たす組 $(l, r)$ を生成する
- `strict` が `true` なら $l < r$ とする
- $O(1)$
