---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    \ }\n#line 2 \"src/misc/timer.hpp\"\n\nstruct Timer {\n    using T = chrono::high_resolution_clock::time_point;\n\
    \    Timer() : start(chrono::high_resolution_clock::now()) {}\n    double now()\
    \ {\n        T end = chrono::high_resolution_clock::now();\n        auto duration\
    \ = chrono::duration_cast<std::chrono::milliseconds>(end - start).count();\n \
    \       return static_cast<double>(duration) / 1000;\n    }\nprivate:\n    T start;\n\
    };\n"
  code: "#include \"../template.hpp\"\n\nstruct Timer {\n    using T = chrono::high_resolution_clock::time_point;\n\
    \    Timer() : start(chrono::high_resolution_clock::now()) {}\n    double now()\
    \ {\n        T end = chrono::high_resolution_clock::now();\n        auto duration\
    \ = chrono::duration_cast<std::chrono::milliseconds>(end - start).count();\n \
    \       return static_cast<double>(duration) / 1000;\n    }\nprivate:\n    T start;\n\
    };"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/misc/timer.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/timer.hpp
layout: document
redirect_from:
- /library/src/misc/timer.hpp
- /library/src/misc/timer.hpp.html
title: src/misc/timer.hpp
---
