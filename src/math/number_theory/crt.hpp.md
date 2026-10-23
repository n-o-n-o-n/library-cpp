---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/ext_gcd.hpp
    title: Extended GCD
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/crt.hpp\"\n#include <cassert>\n#include\
    \ <limits>\n#include <type_traits>\n#include <utility>\n#include <vector>\n#line\
    \ 3 \"src/math/number_theory/ext_gcd.hpp\"\nusing namespace std;\n\n// find x,\
    \ y s.t. ax + by = gcd(a, b) and return gcd(a, b)\ntemplate<typename T>\nT ext_gcd(T\
    \ a, T b, T &x, T &y) {\n    T g = a;\n    if (b != 0) {\n        g = ext_gcd(b,\
    \ a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n   \
    \     y = 0;\n    }\n    return g;\n}\n#line 8 \"src/math/number_theory/crt.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\npair<T, T> crt(const vector<T>\
    \ &rems, const vector<T> &mods) {\n    assert(rems.size() == mods.size());\n \
    \   using W = conditional_t<(sizeof(T) <= 4), long long, __int128_t>;\n    T r\
    \ = 0, m = 1;\n    for (int i = 0; i < ssize(rems); i++) {\n        assert(mods[i]\
    \ > 0);\n        T a = rems[i] % mods[i];\n        if (a < 0) a += mods[i];\n\
    \        W x, y;\n        W g = ext_gcd(m, mods[i], x, y);\n        W d = a -\
    \ r;\n        if (d % g != 0) return {0, 0};\n        W u = (W)mods[i] / g;\n\
    \        W t = (d / g * x) % u;\n        if (t < 0) t += u;\n        W l = (W)m\
    \ * u;\n        assert(l <= numeric_limits<T>::max());\n        r += (W)m * t;\n\
    \        m = l;\n    }\n    return {r, m};\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <type_traits>\n\
    #include <utility>\n#include <vector>\n#include \"ext_gcd.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename T>\npair<T, T> crt(const vector<T> &rems, const vector<T>\
    \ &mods) {\n    assert(rems.size() == mods.size());\n    using W = conditional_t<(sizeof(T)\
    \ <= 4), long long, __int128_t>;\n    T r = 0, m = 1;\n    for (int i = 0; i <\
    \ ssize(rems); i++) {\n        assert(mods[i] > 0);\n        T a = rems[i] % mods[i];\n\
    \        if (a < 0) a += mods[i];\n        W x, y;\n        W g = ext_gcd(m, mods[i],\
    \ x, y);\n        W d = a - r;\n        if (d % g != 0) return {0, 0};\n     \
    \   W u = (W)mods[i] / g;\n        W t = (d / g * x) % u;\n        if (t < 0)\
    \ t += u;\n        W l = (W)m * u;\n        assert(l <= numeric_limits<T>::max());\n\
    \        r += (W)m * t;\n        m = l;\n    }\n    return {r, m};\n}\n"
  dependsOn:
  - src/math/number_theory/ext_gcd.hpp
  isVerificationFile: false
  path: src/math/number_theory/crt.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/number_theory/crt.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/crt.hpp
- /library/src/math/number_theory/crt.hpp.html
title: src/math/number_theory/crt.hpp
---
