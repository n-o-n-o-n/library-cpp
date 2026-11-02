---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/manacher.test.cpp
    title: test/string/manacher.test.cpp
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
    \ }\n#line 3 \"src/string/manacher.hpp\"\n\ntemplate<typename S> \nvector<int>\
    \ manacher(vector<S> v, const S wildcard) {\n    {\n        vector<S> tmp = v;\n\
    \        v.clear();\n        for (const S &s : tmp) {\n            v.push_back(s);\n\
    \            v.push_back(wildcard);\n        }\n        v.pop_back();\n    }\n\
    \    const int n = v.size();\n    int i = 0, j = 0;\n    vector<int> res(n);\n\
    \    while (i < n) {\n        while (j <= i && i + j < n && v[i - j] == v[i +\
    \ j]) j++;\n        res[i] = j;\n        int k = 1;\n        while (k <= i &&\
    \ i + k < n && k + res[i - k] < j) {\n            res[i + k] = res[i - k];\n \
    \           k++;\n        }\n        i += k;\n        j -= k;\n    }\n    for\
    \ (int i = 0; i < n; i++) {\n        if (1 ^ ((res[i] ^ i) & 1)) res[i]--;\n \
    \   }\n    return res;\n}\n\ninline vector<int> manacher(const string &s) {\n\
    \    return manacher(vector<char>(s.begin(), s.end()), '$');\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename S> \nvector<int>\
    \ manacher(vector<S> v, const S wildcard) {\n    {\n        vector<S> tmp = v;\n\
    \        v.clear();\n        for (const S &s : tmp) {\n            v.push_back(s);\n\
    \            v.push_back(wildcard);\n        }\n        v.pop_back();\n    }\n\
    \    const int n = v.size();\n    int i = 0, j = 0;\n    vector<int> res(n);\n\
    \    while (i < n) {\n        while (j <= i && i + j < n && v[i - j] == v[i +\
    \ j]) j++;\n        res[i] = j;\n        int k = 1;\n        while (k <= i &&\
    \ i + k < n && k + res[i - k] < j) {\n            res[i + k] = res[i - k];\n \
    \           k++;\n        }\n        i += k;\n        j -= k;\n    }\n    for\
    \ (int i = 0; i < n; i++) {\n        if (1 ^ ((res[i] ^ i) & 1)) res[i]--;\n \
    \   }\n    return res;\n}\n\ninline vector<int> manacher(const string &s) {\n\
    \    return manacher(vector<char>(s.begin(), s.end()), '$');\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/string/manacher.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/manacher.test.cpp
documentation_of: src/string/manacher.hpp
layout: document
redirect_from:
- /library/src/string/manacher.hpp
- /library/src/string/manacher.hpp.html
title: src/string/manacher.hpp
---
