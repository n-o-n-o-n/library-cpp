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
  bundledCode: "#line 2 \"src/misc/even_distribution_array.hpp\"\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename T>\nvector<T> even_distribution_array(const\
    \ vector<T> &v) {\n    int n = v.size();\n    long long sum = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        sum += v[i];\n    }\n    T q = sum / n, r = sum\
    \ % n;\n    vector<T> res(n, q);\n    for (int i = n - r; i < n; i++) res[i]++;\n\
    \    return res;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nvector<T> even_distribution_array(const vector<T> &v) {\n    int n = v.size();\n\
    \    long long sum = 0;\n    for (int i = 0; i < n; i++) {\n        sum += v[i];\n\
    \    }\n    T q = sum / n, r = sum % n;\n    vector<T> res(n, q);\n    for (int\
    \ i = n - r; i < n; i++) res[i]++;\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/even_distribution_array.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/even_distribution_array.hpp
layout: document
redirect_from:
- /library/src/misc/even_distribution_array.hpp
- /library/src/misc/even_distribution_array.hpp.html
title: src/misc/even_distribution_array.hpp
---
