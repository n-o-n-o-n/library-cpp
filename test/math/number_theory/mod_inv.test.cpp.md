---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/ext_gcd.hpp
    title: Extended GCD
  - icon: ':x:'
    path: src/math/number_theory/mod_inv.hpp
    title: src/math/number_theory/mod_inv.hpp
  - icon: ':question:'
    path: src/random/utility.hpp
    title: Random Utility
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/math/number_theory/mod_inv.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"src/template.hpp\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\ntemplate<typename\
    \ T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2; }\n\ntemplate<typename\
    \ T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a > b ? a = b, true : false;\
    \ }\ntemplate<typename T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a <\
    \ b ? a = b, true : false; }\n#line 3 \"src/math/number_theory/ext_gcd.hpp\"\n\
    \n// find x, y s.t. ax + by = gcd(a, b) and return gcd(a, b)\ntemplate<typename\
    \ T>\nT ext_gcd(T a, T b, T &x, T &y) {\n    T g = a;\n    if (b != 0) {\n   \
    \     g = ext_gcd(b, a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n\
    \        x = 1;\n        y = 0;\n    }\n    return g;\n}\n#line 4 \"src/math/number_theory/mod_inv.hpp\"\
    \n\ntemplate<typename T>\ninline T mod_inv(T a, T mod) {\n    assert(mod > 1);\n\
    \    using W = conditional_t<(sizeof(T) <= 4), long long, __int128_t>;\n    W\
    \ m = W(mod);\n    W b = W(a) % m;\n    if (b < 0) b += m;\n    W inv, y;\n  \
    \  W g = ext_gcd(b, m, inv, y);\n    assert(g == 1);\n    inv %= m;\n    return\
    \ T(inv < 0 ? inv + m : inv);\n}\n#line 3 \"src/random/utility.hpp\"\n\nnamespace\
    \ rng {\n\ninline random_device seed;\ninline mt19937 eng(seed());\n\ntemplate<typename\
    \ T>\nvoid set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral\
    \ T>\ninline T randint(T lo, T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T>\
    \ dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T,\
    \ T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n\
    \    T l = randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n   \
    \ return make_pair(l, r);\n}\n\n} // namespace rng\n#line 6 \"test/math/number_theory/mod_inv.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  {\n        int A, B;\n        cin >> A >> B;\n        cout << A + B << '\\\
    n';\n    }\n    for (int t = 0; t < (int)1e5; t++) {\n        long long mod =\
    \ rng::randint(2, (int)1e9);\n        long long x = mod;\n        while (gcd(x,\
    \ mod) != 1) x = rng::randint(1LL, mod - 1);\n        assert(x * mod_inv(x, mod)\
    \ % mod == 1);\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../src/template.hpp\"\n#include \"../../../src/math/number_theory/mod_inv.hpp\"\
    \n#include \"../../../src/random/utility.hpp\"\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    {\n        int A, B;\n        cin >> A >> B;\n   \
    \     cout << A + B << '\\n';\n    }\n    for (int t = 0; t < (int)1e5; t++) {\n\
    \        long long mod = rng::randint(2, (int)1e9);\n        long long x = mod;\n\
    \        while (gcd(x, mod) != 1) x = rng::randint(1LL, mod - 1);\n        assert(x\
    \ * mod_inv(x, mod) % mod == 1);\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/math/number_theory/mod_inv.hpp
  - src/math/number_theory/ext_gcd.hpp
  - src/random/utility.hpp
  isVerificationFile: true
  path: test/math/number_theory/mod_inv.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/number_theory/mod_inv.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/mod_inv.test.cpp
- /verify/test/math/number_theory/mod_inv.test.cpp.html
title: test/math/number_theory/mod_inv.test.cpp
---
