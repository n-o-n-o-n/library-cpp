---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/number_theory/floor_kth_root.hpp
    title: src/math/number_theory/floor_kth_root.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"test/math/number_theory/floor_kth_root.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    template<typename T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2;\
    \ }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a\
    \ > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/math/number_theory/floor_kth_root.hpp\"\
    \n\n// floor( a^(1/k) )\ntemplate<typename T>\nT floor_kth_root(T a, T k) {\n\
    \    assert(0 <= a);\n    if (a == 0 || a == 1 || k == 1) return a;\n    if (64\
    \ <= k) return 1;\n    constexpr T inf = numeric_limits<T>::max();\n    if (a\
    \ == inf) a--;\n    auto mul = [&](T x, T y) -> T {\n        return x <= inf /\
    \ y ? x * y : inf;\n    };\n    auto pw = [&](T x, T n) -> T {\n        T r =\
    \ 1;\n        while (n > 0) {\n            if (n & 1) r = mul(r, x);\n       \
    \     x = mul(x, x);\n            n >>= 1;\n        }\n        return r;\n   \
    \ };\n    T res = (k == 2 ? sqrtl(a) - 1 : k == 3 ? cbrtl(a) - 1 : pow(a, nextafter(1.0\
    \ / k, 0)));\n    while (pw(res + 1, k) <= a) res++;\n    return res;\n}\n#line\
    \ 5 \"test/math/number_theory/floor_kth_root.test.cpp\"\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int T;\n    cin >> T;\n    while (T--) {\n       \
    \ unsigned long long A;\n        int K;\n        cin >> A >> K;\n        cout\
    \ << floor_kth_root<unsigned long long>(A, K) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n\
    #include \"../../../src/template.hpp\"\n#include \"../../../src/math/number_theory/floor_kth_root.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int T;\n    cin >> T;\n    while (T--) {\n        unsigned long long A;\n \
    \       int K;\n        cin >> A >> K;\n        cout << floor_kth_root<unsigned\
    \ long long>(A, K) << '\\n';\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/math/number_theory/floor_kth_root.hpp
  isVerificationFile: true
  path: test/math/number_theory/floor_kth_root.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/math/number_theory/floor_kth_root.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/floor_kth_root.test.cpp
- /verify/test/math/number_theory/floor_kth_root.test.cpp.html
title: test/math/number_theory/floor_kth_root.test.cpp
---
