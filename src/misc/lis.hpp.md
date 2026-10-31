---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"src/misc/lis.hpp\"\n#include <algorithm>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename T>\nvector<int> longest_increasing_subsequence(const\
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
  code: "#pragma once\n#include <algorithm>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nvector<int> longest_increasing_subsequence(const vector<T>\
    \ &v, bool strict = true) {\n    if (v.empty()) return {};\n    int n = v.size();\n\
    \    vector<T> dp;\n    vector<int> idx(n, -1);\n    for (int i = 0; i < n; i++)\
    \ {\n        int j;\n        if (strict) {\n            j = lower_bound(dp.begin(),\
    \ dp.end(), v[i]) - dp.begin();\n        } else {\n            j = upper_bound(dp.begin(),\
    \ dp.end(), v[i]) - dp.begin();\n        }\n        if (j == ssize(dp)) dp.push_back(v[i]);\n\
    \        else dp[j] = v[i];\n        idx[i] = j;\n    }\n    int m = *max_element(idx.begin(),\
    \ idx.end());\n    vector<int> res(m + 1);\n    for (int i = n - 1; i >= 0; i--)\
    \ {\n        if (idx[i] == m) {\n            res[m] = i;\n            m--;\n \
    \       }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/lis.hpp
  requiredBy: []
  timestamp: '2026-10-31 09:19:34+09:00'
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
