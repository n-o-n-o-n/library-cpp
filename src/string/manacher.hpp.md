---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/manacher.test.cpp
    title: test/string/manacher.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/manacher.hpp\"\n#include <string>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename S> \nvector<int> manacher(vector<S>\
    \ v, const S wildcard) {\n    {\n        vector<S> tmp = v;\n        v.clear();\n\
    \        for (const S &s : tmp) {\n            v.push_back(s);\n            v.push_back(wildcard);\n\
    \        }\n        v.pop_back();\n    }\n    const int n = v.size();\n    int\
    \ i = 0, j = 0;\n    vector<int> res(n);\n    while (i < n) {\n        while (j\
    \ <= i && i + j < n && v[i - j] == v[i + j]) j++;\n        res[i] = j;\n     \
    \   int k = 1;\n        while (k <= i && i + k < n && k + res[i - k] < j) {\n\
    \            res[i + k] = res[i - k];\n            k++;\n        }\n        i\
    \ += k;\n        j -= k;\n    }\n    for (int i = 0; i < n; i++) {\n        if\
    \ (1 ^ ((res[i] ^ i) & 1)) res[i]--;\n    }\n    return res;\n}\n\ninline vector<int>\
    \ manacher(const string &s) {\n    return manacher(vector<char>(s.begin(), s.end()),\
    \ '$');\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename S> \nvector<int> manacher(vector<S> v, const S wildcard) {\n\
    \    {\n        vector<S> tmp = v;\n        v.clear();\n        for (const S &s\
    \ : tmp) {\n            v.push_back(s);\n            v.push_back(wildcard);\n\
    \        }\n        v.pop_back();\n    }\n    const int n = v.size();\n    int\
    \ i = 0, j = 0;\n    vector<int> res(n);\n    while (i < n) {\n        while (j\
    \ <= i && i + j < n && v[i - j] == v[i + j]) j++;\n        res[i] = j;\n     \
    \   int k = 1;\n        while (k <= i && i + k < n && k + res[i - k] < j) {\n\
    \            res[i + k] = res[i - k];\n            k++;\n        }\n        i\
    \ += k;\n        j -= k;\n    }\n    for (int i = 0; i < n; i++) {\n        if\
    \ (1 ^ ((res[i] ^ i) & 1)) res[i]--;\n    }\n    return res;\n}\n\ninline vector<int>\
    \ manacher(const string &s) {\n    return manacher(vector<char>(s.begin(), s.end()),\
    \ '$');\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/string/manacher.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/manacher.test.cpp
documentation_of: src/string/manacher.hpp
layout: document
redirect_from:
- /library/src/string/manacher.hpp
- /library/src/string/manacher.hpp.html
title: src/string/manacher.hpp
---
