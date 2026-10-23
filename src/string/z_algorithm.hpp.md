---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/z_algorithm.test.cpp
    title: test/string/z_algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/z_algorithm.hpp\"\n#include <string>\n#include\
    \ <vector>\nusing namespace std;\n\n\ntemplate<typename S> \nvector<int> z_algorithm(const\
    \ vector<S> &v) {\n    const int n = v.size();\n    int p = 0;\n    vector<int>\
    \ z(n);\n    for (int i = 1; i < n; i++) {\n        int k = i - p;\n        if\
    \ (i + z[k] < p + z[p]) {\n            z[i] = z[k];\n        } else {\n      \
    \      int j = max(0, p + z[p] - i);\n            while (i + j < n && v[j] ==\
    \ v[i + j]) j++;\n            z[i] = j;\n            p = i;\n        }\n    }\n\
    \    z[0] = n;\n    return z;\n}\n\ninline vector<int> z_algorithm(const string\
    \ &s) {\n    return z_algorithm(vector<char>(s.begin(), s.end()));\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\nusing namespace std;\n\
    \n\ntemplate<typename S> \nvector<int> z_algorithm(const vector<S> &v) {\n   \
    \ const int n = v.size();\n    int p = 0;\n    vector<int> z(n);\n    for (int\
    \ i = 1; i < n; i++) {\n        int k = i - p;\n        if (i + z[k] < p + z[p])\
    \ {\n            z[i] = z[k];\n        } else {\n            int j = max(0, p\
    \ + z[p] - i);\n            while (i + j < n && v[j] == v[i + j]) j++;\n     \
    \       z[i] = j;\n            p = i;\n        }\n    }\n    z[0] = n;\n    return\
    \ z;\n}\n\ninline vector<int> z_algorithm(const string &s) {\n    return z_algorithm(vector<char>(s.begin(),\
    \ s.end()));\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/z_algorithm.test.cpp
documentation_of: src/string/z_algorithm.hpp
layout: document
redirect_from:
- /library/src/string/z_algorithm.hpp
- /library/src/string/z_algorithm.hpp.html
title: src/string/z_algorithm.hpp
---
