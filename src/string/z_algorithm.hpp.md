---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/z_algorithm.test.cpp
    title: test/string/z_algorithm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/string/z_algorithm.hpp\"\n\n\ntemplate<typename S> \nvector<int>\
    \ z_algorithm(const vector<S> &v) {\n    const int n = v.size();\n    int p =\
    \ 0;\n    vector<int> z(n);\n    for (int i = 1; i < n; i++) {\n        int k\
    \ = i - p;\n        if (i + z[k] < p + z[p]) {\n            z[i] = z[k];\n   \
    \     } else {\n            int j = max(0, p + z[p] - i);\n            while (i\
    \ + j < n && v[j] == v[i + j]) j++;\n            z[i] = j;\n            p = i;\n\
    \        }\n    }\n    z[0] = n;\n    return z;\n}\n\ninline vector<int> z_algorithm(const\
    \ string &s) {\n    return z_algorithm(vector<char>(s.begin(), s.end()));\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n\ntemplate<typename S> \nvector<int>\
    \ z_algorithm(const vector<S> &v) {\n    const int n = v.size();\n    int p =\
    \ 0;\n    vector<int> z(n);\n    for (int i = 1; i < n; i++) {\n        int k\
    \ = i - p;\n        if (i + z[k] < p + z[p]) {\n            z[i] = z[k];\n   \
    \     } else {\n            int j = max(0, p + z[p] - i);\n            while (i\
    \ + j < n && v[j] == v[i + j]) j++;\n            z[i] = j;\n            p = i;\n\
    \        }\n    }\n    z[0] = n;\n    return z;\n}\n\ninline vector<int> z_algorithm(const\
    \ string &s) {\n    return z_algorithm(vector<char>(s.begin(), s.end()));\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/z_algorithm.test.cpp
documentation_of: src/string/z_algorithm.hpp
layout: document
redirect_from:
- /library/src/string/z_algorithm.hpp
- /library/src/string/z_algorithm.hpp.html
title: src/string/z_algorithm.hpp
---
