---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/misc/lis.test.cpp
    title: test/misc/lis.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/misc/lis.hpp\"\n\ntemplate<typename T>\nvector<int> longest_increasing_subsequence(const\
    \ vector<T> &v, bool strict = true) {\n    if (v.empty()) return {};\n    int\
    \ n = v.size();\n    vector<T> dp;\n    vector<int> idx(n, -1);\n    for (int\
    \ i = 0; i < n; i++) {\n        int j;\n        if (strict) {\n            j =\
    \ lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();\n        } else {\n  \
    \          j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();\n       \
    \ }\n        if (j == ssize(dp)) dp.push_back(v[i]);\n        else dp[j] = v[i];\n\
    \        idx[i] = j;\n    }\n    int m = *max_element(idx.begin(), idx.end());\n\
    \    vector<int> res(m + 1);\n    for (int i = n - 1; i >= 0; i--) {\n       \
    \ if (idx[i] == m) {\n            res[m] = i;\n            m--;\n        }\n \
    \   }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T>\nvector<int>\
    \ longest_increasing_subsequence(const vector<T> &v, bool strict = true) {\n \
    \   if (v.empty()) return {};\n    int n = v.size();\n    vector<T> dp;\n    vector<int>\
    \ idx(n, -1);\n    for (int i = 0; i < n; i++) {\n        int j;\n        if (strict)\
    \ {\n            j = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();\n \
    \       } else {\n            j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();\n\
    \        }\n        if (j == ssize(dp)) dp.push_back(v[i]);\n        else dp[j]\
    \ = v[i];\n        idx[i] = j;\n    }\n    int m = *max_element(idx.begin(), idx.end());\n\
    \    vector<int> res(m + 1);\n    for (int i = n - 1; i >= 0; i--) {\n       \
    \ if (idx[i] == m) {\n            res[m] = i;\n            m--;\n        }\n \
    \   }\n    return res;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/misc/lis.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/misc/lis.test.cpp
documentation_of: src/misc/lis.hpp
layout: document
redirect_from:
- /library/src/misc/lis.hpp
- /library/src/misc/lis.hpp.html
title: src/misc/lis.hpp
---
