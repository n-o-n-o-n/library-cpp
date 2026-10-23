---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/number_theory/mod_pow.hpp\"\n#include <cassert>\n\
    #include <type_traits>\nusing namespace std;\n\ntemplate<typename T1, typename\
    \ T2 = long long>\ninline T1 mod_pow(T1 a, T2 n, T1 mod) {\n    assert(mod > 0);\n\
    \    assert(n >= 0);\n    using W = conditional_t<(sizeof(T1) <= 4), long long,\
    \ __int128_t>;\n    a %= mod;\n    if (a < 0) a += mod;\n    T1 res = 1 % mod;\n\
    \    while (n > 0) {\n        if (n & 1) res = W(res) * a % mod;\n        a =\
    \ W(a) * a % mod;\n        n >>= 1;\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <type_traits>\nusing namespace\
    \ std;\n\ntemplate<typename T1, typename T2 = long long>\ninline T1 mod_pow(T1\
    \ a, T2 n, T1 mod) {\n    assert(mod > 0);\n    assert(n >= 0);\n    using W =\
    \ conditional_t<(sizeof(T1) <= 4), long long, __int128_t>;\n    a %= mod;\n  \
    \  if (a < 0) a += mod;\n    T1 res = 1 % mod;\n    while (n > 0) {\n        if\
    \ (n & 1) res = W(res) * a % mod;\n        a = W(a) * a % mod;\n        n >>=\
    \ 1;\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/number_theory/mod_pow.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/math/number_theory/mod_pow.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/mod_pow.hpp
- /library/src/math/number_theory/mod_pow.hpp.html
title: src/math/number_theory/mod_pow.hpp
---
