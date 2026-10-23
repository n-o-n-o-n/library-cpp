---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/ext_gcd.hpp
    title: Extended GCD
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/number_theory/mod_inv.test.cpp
    title: test/math/number_theory/mod_inv.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/mod_inv.hpp\"\n#include <cassert>\n\
    #include <type_traits>\n#line 2 \"src/math/number_theory/ext_gcd.hpp\"\n#include\
    \ <utility>\nusing namespace std;\n\n// find x, y s.t. ax + by = gcd(a, b) and\
    \ return gcd(a, b)\ntemplate<typename T>\nT ext_gcd(T a, T b, T &x, T &y) {\n\
    \    T g = a;\n    if (b != 0) {\n        g = ext_gcd(b, a % b, y, x);\n     \
    \   y -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n \
    \   return g;\n}\n#line 5 \"src/math/number_theory/mod_inv.hpp\"\nusing namespace\
    \ std;\n\ntemplate<typename T>\ninline T mod_inv(T a, T mod) {\n    assert(mod\
    \ > 1);\n    using W = conditional_t<(sizeof(T) <= 4), long long, __int128_t>;\n\
    \    W m = W(mod);\n    W b = W(a) % m;\n    if (b < 0) b += m;\n    W inv, y;\n\
    \    W g = ext_gcd(b, m, inv, y);\n    assert(g == 1);\n    inv %= m;\n    return\
    \ T(inv < 0 ? inv + m : inv);\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <type_traits>\n#include \"ext_gcd.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\ninline T mod_inv(T a, T mod) {\n\
    \    assert(mod > 1);\n    using W = conditional_t<(sizeof(T) <= 4), long long,\
    \ __int128_t>;\n    W m = W(mod);\n    W b = W(a) % m;\n    if (b < 0) b += m;\n\
    \    W inv, y;\n    W g = ext_gcd(b, m, inv, y);\n    assert(g == 1);\n    inv\
    \ %= m;\n    return T(inv < 0 ? inv + m : inv);\n}\n"
  dependsOn:
  - src/math/number_theory/ext_gcd.hpp
  isVerificationFile: false
  path: src/math/number_theory/mod_inv.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/number_theory/mod_inv.test.cpp
documentation_of: src/math/number_theory/mod_inv.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/mod_inv.hpp
- /library/src/math/number_theory/mod_inv.hpp.html
title: src/math/number_theory/mod_inv.hpp
---
