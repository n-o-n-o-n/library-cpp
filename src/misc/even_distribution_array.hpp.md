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
    \ }\n#line 3 \"src/misc/even_distribution_array.hpp\"\n\ntemplate<typename T>\n\
    vector<T> even_distribution_array(const vector<T> &v) {\n    int n = v.size();\n\
    \    long long sum = 0;\n    for (int i = 0; i < n; i++) {\n        sum += v[i];\n\
    \    }\n    T q = sum / n, r = sum % n;\n    vector<T> res(n, q);\n    for (int\
    \ i = n - r; i < n; i++) res[i]++;\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T>\nvector<T>\
    \ even_distribution_array(const vector<T> &v) {\n    int n = v.size();\n    long\
    \ long sum = 0;\n    for (int i = 0; i < n; i++) {\n        sum += v[i];\n   \
    \ }\n    T q = sum / n, r = sum % n;\n    vector<T> res(n, q);\n    for (int i\
    \ = n - r; i < n; i++) res[i]++;\n    return res;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/misc/even_distribution_array.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/even_distribution_array.hpp
layout: document
redirect_from:
- /library/src/misc/even_distribution_array.hpp
- /library/src/misc/even_distribution_array.hpp.html
title: src/misc/even_distribution_array.hpp
---
