---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/ext_gcd.hpp
    title: Extended GCD
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/arbitrary_mod_convolution.hpp
    title: src/convolution/arbitrary_mod_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/arbitrary_mod_convolution.test.cpp
    title: test/convolution/arbitrary_mod_convolution.test.cpp
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
    \ }\n#line 3 \"src/math/number_theory/ext_gcd.hpp\"\n\n// find x, y s.t. ax +\
    \ by = gcd(a, b) and return gcd(a, b)\ntemplate<typename T>\nT ext_gcd(T a, T\
    \ b, T &x, T &y) {\n    T g = a;\n    if (b != 0) {\n        g = ext_gcd(b, a\
    \ % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n     \
    \   y = 0;\n    }\n    return g;\n}\n#line 4 \"src/math/number_theory/garner.hpp\"\
    \n\ntemplate<typename T>\nT garner(const vector<T> &rems, vector<T> mods, T mod)\
    \ {\n    assert(rems.size() == mods.size());\n    using W = conditional_t<(sizeof(T)\
    \ <= 4), long long, __int128_t>;\n    mods.push_back(mod);\n    int n = mods.size();\n\
    \    vector<T> c1(n, 1), c2(n, 0);\n    for (int i = 0; i < n - 1; i++) {\n  \
    \      T m = mods[i], a = c1[i], b = (rems[i] - c2[i]) % m;\n        if (b < 0)\
    \ b += m;\n        T x, y;\n        T g = ext_gcd(a, m, x, y);\n        if (b\
    \ % g != 0) return -1;\n        m /= g, b /= g;\n        x %= m;\n        if (x\
    \ < 0) x += m;\n        T t = (W)x * b % m;\n        for (int j = i + 1; j < n;\
    \ j++) {\n            c2[j] = ((W)t * c1[j] + c2[j]) % mods[j];\n            c1[j]\
    \ = (W)c1[j] * m % mods[j];\n        }\n    }\n    return c2.back();\n}\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n#include \"ext_gcd.hpp\"\n\
    \ntemplate<typename T>\nT garner(const vector<T> &rems, vector<T> mods, T mod)\
    \ {\n    assert(rems.size() == mods.size());\n    using W = conditional_t<(sizeof(T)\
    \ <= 4), long long, __int128_t>;\n    mods.push_back(mod);\n    int n = mods.size();\n\
    \    vector<T> c1(n, 1), c2(n, 0);\n    for (int i = 0; i < n - 1; i++) {\n  \
    \      T m = mods[i], a = c1[i], b = (rems[i] - c2[i]) % m;\n        if (b < 0)\
    \ b += m;\n        T x, y;\n        T g = ext_gcd(a, m, x, y);\n        if (b\
    \ % g != 0) return -1;\n        m /= g, b /= g;\n        x %= m;\n        if (x\
    \ < 0) x += m;\n        T t = (W)x * b % m;\n        for (int j = i + 1; j < n;\
    \ j++) {\n            c2[j] = ((W)t * c1[j] + c2[j]) % mods[j];\n            c1[j]\
    \ = (W)c1[j] * m % mods[j];\n        }\n    }\n    return c2.back();\n}\n"
  dependsOn:
  - src/template.hpp
  - src/math/number_theory/ext_gcd.hpp
  isVerificationFile: false
  path: src/math/number_theory/garner.hpp
  requiredBy:
  - src/convolution/arbitrary_mod_convolution.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/arbitrary_mod_convolution.test.cpp
documentation_of: src/math/number_theory/garner.hpp
layout: document
title: Garner
---

複数の合同式を解き, 指定した法での解を求める.
`T` は 64 bit 以下の符号付き整数型とする.

## garner

```
T garner(vector<T> rems, vector<T> mods, T mod)
```

- $r=\mathrm{rems}$ と $m=\mathrm{mods}$ は同じ長さ $k$ とし, 各 $m_i$ と $\mathrm{mod}$ は正とする
- $x \equiv r_i \pmod{m_i}$ をすべて満たす解を $0 \le x < \mathrm{mod}$ で返す
- 解がなければ $-1$ を返す
- $M$ を法の最大値として $O(k^2 + k \log M)$
