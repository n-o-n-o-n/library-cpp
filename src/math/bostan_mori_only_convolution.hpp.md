---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/bostan_mori_only_convolution.test.cpp
    title: test/math/bostan_mori_only_convolution.test.cpp
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
    \ }\n#line 3 \"src/math/bostan_mori_only_convolution.hpp\"\n\ntemplate<typename\
    \ mint, typename C>\nmint Bostan_Mori(vector<mint> p, vector<mint> q, long long\
    \ k, const C &conv) {\n    assert(p.size() && q.size());\n    if (k == 0) return\
    \ p[0] / q[0];\n    auto sub = [&] (const vector<mint> &f, bool odd = false) ->\
    \ vector<mint> {\n        int n = (f.size() + !odd) / 2;\n        vector<mint>\
    \ g(n);\n        for (int i = odd; i < ssize(f); i += 2) {\n            g[i /\
    \ 2] = f[i];\n        }\n        return g;\n    };\n    while (k > 0) {\n    \
    \    auto q2 = q;\n        for (int i = 1; i < ssize(q2); i += 2) {\n        \
    \    q2[i] = -q2[i];\n        }\n        p = sub(conv(p, q2), k & 1);\n      \
    \  q = sub(conv(q, q2));\n        k >>= 1;\n    }\n    return p[0];\n}\n\ntemplate<typename\
    \ mint, typename C>\nmint linear_recurrence(vector<mint> a, vector<mint> c, long\
    \ long k, const C &conv) {\n    assert(a.size() == c.size());\n    int n = a.size();\n\
    \    for (auto &e : c) e = -e;\n    c.insert(c.begin(), 1);\n    a = conv(a, c);\n\
    \    a.resize(n);\n    return Bostan_Mori<mint, C>(a, c, k, conv);\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename mint, typename\
    \ C>\nmint Bostan_Mori(vector<mint> p, vector<mint> q, long long k, const C &conv)\
    \ {\n    assert(p.size() && q.size());\n    if (k == 0) return p[0] / q[0];\n\
    \    auto sub = [&] (const vector<mint> &f, bool odd = false) -> vector<mint>\
    \ {\n        int n = (f.size() + !odd) / 2;\n        vector<mint> g(n);\n    \
    \    for (int i = odd; i < ssize(f); i += 2) {\n            g[i / 2] = f[i];\n\
    \        }\n        return g;\n    };\n    while (k > 0) {\n        auto q2 =\
    \ q;\n        for (int i = 1; i < ssize(q2); i += 2) {\n            q2[i] = -q2[i];\n\
    \        }\n        p = sub(conv(p, q2), k & 1);\n        q = sub(conv(q, q2));\n\
    \        k >>= 1;\n    }\n    return p[0];\n}\n\ntemplate<typename mint, typename\
    \ C>\nmint linear_recurrence(vector<mint> a, vector<mint> c, long long k, const\
    \ C &conv) {\n    assert(a.size() == c.size());\n    int n = a.size();\n    for\
    \ (auto &e : c) e = -e;\n    c.insert(c.begin(), 1);\n    a = conv(a, c);\n  \
    \  a.resize(n);\n    return Bostan_Mori<mint, C>(a, c, k, conv);\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/math/bostan_mori_only_convolution.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/bostan_mori_only_convolution.test.cpp
documentation_of: src/math/bostan_mori_only_convolution.hpp
layout: document
redirect_from:
- /library/src/math/bostan_mori_only_convolution.hpp
- /library/src/math/bostan_mori_only_convolution.hpp.html
title: src/math/bostan_mori_only_convolution.hpp
---
