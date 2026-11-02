---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/ext_gcd.hpp
    title: Extended GCD
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \   y = 0;\n    }\n    return g;\n}\n#line 4 \"src/math/number_theory/crt.hpp\"\
    \n\ntemplate<typename T>\npair<T, T> crt(const vector<T> &rems, const vector<T>\
    \ &mods) {\n    assert(rems.size() == mods.size());\n    using W = conditional_t<(sizeof(T)\
    \ <= 4), long long, __int128_t>;\n    T r = 0, m = 1;\n    for (int i = 0; i <\
    \ ssize(rems); i++) {\n        assert(mods[i] > 0);\n        T a = rems[i] % mods[i];\n\
    \        if (a < 0) a += mods[i];\n        W x, y;\n        W g = ext_gcd(m, mods[i],\
    \ x, y);\n        W d = a - r;\n        if (d % g != 0) return {0, 0};\n     \
    \   W u = (W)mods[i] / g;\n        W t = (d / g * x) % u;\n        if (t < 0)\
    \ t += u;\n        W l = (W)m * u;\n        assert(l <= numeric_limits<T>::max());\n\
    \        r += (W)m * t;\n        m = l;\n    }\n    return {r, m};\n}\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n#include \"ext_gcd.hpp\"\n\
    \ntemplate<typename T>\npair<T, T> crt(const vector<T> &rems, const vector<T>\
    \ &mods) {\n    assert(rems.size() == mods.size());\n    using W = conditional_t<(sizeof(T)\
    \ <= 4), long long, __int128_t>;\n    T r = 0, m = 1;\n    for (int i = 0; i <\
    \ ssize(rems); i++) {\n        assert(mods[i] > 0);\n        T a = rems[i] % mods[i];\n\
    \        if (a < 0) a += mods[i];\n        W x, y;\n        W g = ext_gcd(m, mods[i],\
    \ x, y);\n        W d = a - r;\n        if (d % g != 0) return {0, 0};\n     \
    \   W u = (W)mods[i] / g;\n        W t = (d / g * x) % u;\n        if (t < 0)\
    \ t += u;\n        W l = (W)m * u;\n        assert(l <= numeric_limits<T>::max());\n\
    \        r += (W)m * t;\n        m = l;\n    }\n    return {r, m};\n}\n"
  dependsOn:
  - src/template.hpp
  - src/math/number_theory/ext_gcd.hpp
  isVerificationFile: false
  path: src/math/number_theory/crt.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/number_theory/crt.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/crt.hpp
- /library/src/math/number_theory/crt.hpp.html
title: src/math/number_theory/crt.hpp
---
