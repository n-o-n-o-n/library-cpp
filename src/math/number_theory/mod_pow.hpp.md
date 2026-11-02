---
data:
  _extendedDependsOn:
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
    \ }\n#line 3 \"src/math/number_theory/mod_pow.hpp\"\n\ntemplate<typename T1, typename\
    \ T2 = long long>\ninline T1 mod_pow(T1 a, T2 n, T1 mod) {\n    assert(mod > 0);\n\
    \    assert(n >= 0);\n    using W = conditional_t<(sizeof(T1) <= 4), long long,\
    \ __int128_t>;\n    a %= mod;\n    if (a < 0) a += mod;\n    T1 res = 1 % mod;\n\
    \    while (n > 0) {\n        if (n & 1) res = W(res) * a % mod;\n        a =\
    \ W(a) * a % mod;\n        n >>= 1;\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\ntemplate<typename T1, typename\
    \ T2 = long long>\ninline T1 mod_pow(T1 a, T2 n, T1 mod) {\n    assert(mod > 0);\n\
    \    assert(n >= 0);\n    using W = conditional_t<(sizeof(T1) <= 4), long long,\
    \ __int128_t>;\n    a %= mod;\n    if (a < 0) a += mod;\n    T1 res = 1 % mod;\n\
    \    while (n > 0) {\n        if (n & 1) res = W(res) * a % mod;\n        a =\
    \ W(a) * a % mod;\n        n >>= 1;\n    }\n    return res;\n}\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/math/number_theory/mod_pow.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/number_theory/mod_pow.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/mod_pow.hpp
- /library/src/math/number_theory/mod_pow.hpp.html
title: src/math/number_theory/mod_pow.hpp
---
