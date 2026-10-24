---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/utility.hpp
    title: Random Utility
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/set/median_set.test.cpp
    title: test/data_structure/set/median_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/fps/power_projection.test.cpp
    title: test/fps/power_projection.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/random/sequence.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n#line 3 \"src/random/utility.hpp\"\n#include <concepts>\n\
    #include <random>\nusing namespace std;\n\nnamespace rng {\n\ninline random_device\
    \ seed;\ninline mt19937 eng(seed());\n\ntemplate<typename T>\nvoid set_seed(const\
    \ T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral T>\ninline T randint(T lo,\
    \ T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T> dist(lo, hi);\n\
    \    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T, T> randpair(T\
    \ lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n    T l =\
    \ randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n    return make_pair(l,\
    \ r);\n}\n\n} // namespace rng\n#line 6 \"src/random/sequence.hpp\"\nusing namespace\
    \ std;\n\nnamespace rng {\n\ntemplate<typename T>\nvoid shuffle(vector<T> &v)\
    \ {\n    std::shuffle(v.begin(), v.end(), eng);\n}\n\ntemplate<integral T>\ninline\
    \ vector<T> random_sequence(int n, T lo, T hi) {\n    assert(n >= 0);\n    vector<T>\
    \ res(n);\n    for (int i = 0; i < n; i++) res[i] = randint(lo, hi);\n    return\
    \ res;\n}\n\ntemplate<integral T>\ninline vector<T> random_increasing_sequence(int\
    \ n, T lo, T hi, bool strict = false) {\n    assert(n >= 0);\n    if (n == 0)\
    \ return {};\n    assert(lo + (n - 1) * strict <= hi);\n    vector<T> res = random_sequence(n,\
    \ lo, hi - (n - 1) * strict);\n    sort(res.begin(), res.end());\n    for (int\
    \ i = 0; i < n; i++) res[i] += i * strict;\n    return res;\n}\n\ntemplate<integral\
    \ T>\ninline vector<T> random_decreasing_sequence(int n, T lo, T hi, bool strict\
    \ = false) {\n    vector<T> res = random_increasing_sequence(n, lo, hi, strict);\n\
    \    reverse(res.begin(), res.end());\n    return res;\n}\n\ntemplate<integral\
    \ T = int>\ninline vector<T> random_permutation(int n, T v = 0) {\n    vector<T>\
    \ res(n);\n    iota(res.begin(), res.end(), v);\n    shuffle(res);\n    return\
    \ res;\n}\n\ninline string random_string(int n, char a, char z) {\n    assert(a\
    \ <= z);\n    string s(n, a);\n    for (auto &c : s) c = randint((int)a, (int)z);\n\
    \    return s;\n}\n\n} // namespace rng\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    #include \"utility.hpp\"\nusing namespace std;\n\nnamespace rng {\n\ntemplate<typename\
    \ T>\nvoid shuffle(vector<T> &v) {\n    std::shuffle(v.begin(), v.end(), eng);\n\
    }\n\ntemplate<integral T>\ninline vector<T> random_sequence(int n, T lo, T hi)\
    \ {\n    assert(n >= 0);\n    vector<T> res(n);\n    for (int i = 0; i < n; i++)\
    \ res[i] = randint(lo, hi);\n    return res;\n}\n\ntemplate<integral T>\ninline\
    \ vector<T> random_increasing_sequence(int n, T lo, T hi, bool strict = false)\
    \ {\n    assert(n >= 0);\n    if (n == 0) return {};\n    assert(lo + (n - 1)\
    \ * strict <= hi);\n    vector<T> res = random_sequence(n, lo, hi - (n - 1) *\
    \ strict);\n    sort(res.begin(), res.end());\n    for (int i = 0; i < n; i++)\
    \ res[i] += i * strict;\n    return res;\n}\n\ntemplate<integral T>\ninline vector<T>\
    \ random_decreasing_sequence(int n, T lo, T hi, bool strict = false) {\n    vector<T>\
    \ res = random_increasing_sequence(n, lo, hi, strict);\n    reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\ntemplate<integral T = int>\ninline vector<T>\
    \ random_permutation(int n, T v = 0) {\n    vector<T> res(n);\n    iota(res.begin(),\
    \ res.end(), v);\n    shuffle(res);\n    return res;\n}\n\ninline string random_string(int\
    \ n, char a, char z) {\n    assert(a <= z);\n    string s(n, a);\n    for (auto\
    \ &c : s) c = randint((int)a, (int)z);\n    return s;\n}\n\n} // namespace rng"
  dependsOn:
  - src/random/utility.hpp
  isVerificationFile: false
  path: src/random/sequence.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/fps/power_projection.test.cpp
  - test/data_structure/set/median_set.test.cpp
documentation_of: src/random/sequence.hpp
layout: document
title: Random Sequence
---

`rng` 名前空間で乱数列や順列を生成する.

## shuffle

```
void rng::shuffle(vector<T> &v)
```

- $v$ の要素をシャッフルする

## random_sequence

```
vector<T> rng::random_sequence(int n, T lo, T hi)
```

- $lo$ 以上 $hi$ 以下の整数を $n$ 個生成する

## random_increasing_sequence

```
vector<T> rng::random_increasing_sequence(int n, T lo, T hi, bool strict = false)
```

- $lo$ 以上 $hi$ 以下の整数からなる長さ $n$ の非減少列を生成する
- `strict` が `true` なら狭義単調増加列を生成する

## random_decreasing_sequence

```
vector<T> rng::random_decreasing_sequence(int n, T lo, T hi, bool strict = false)
```

- $lo$ 以上 $hi$ 以下の整数からなる長さ $n$ の非増加列を生成する
- `strict` が `true` なら狭義単調減少列を生成する

## random_permutation

```
vector<T> rng::random_permutation(int n, T v = 0)
```

- $v$ から $v+n-1$ までの整数を並べ替えた列を返す

## random_string

```
string rng::random_string(int n, char a, char z)
```

- `a` 以上 `z` 以下の文字からなる長さ $n$ の文字列を生成する
