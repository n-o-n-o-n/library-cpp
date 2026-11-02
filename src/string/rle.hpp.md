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
    \ }\n#line 3 \"src/string/rle.hpp\"\n\ntemplate<typename T>\nvector<pair<T, int>>\
    \ run_length_encoding(const vector<T> &v) {\n    vector<pair<T, int>> res;\n \
    \   for (const auto &x : v) {\n        if (res.empty() || res.back().first !=\
    \ x) {\n            res.emplace_back(x, 0);\n        }\n        res.back().second++;\n\
    \    }\n    return res;\n}\n\ninline vector<pair<char, int>> run_length_encoding(const\
    \ string &s) {\n    return run_length_encoding(vector<char>(s.begin(), s.end()));\n\
    }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T>\nvector<pair<T,\
    \ int>> run_length_encoding(const vector<T> &v) {\n    vector<pair<T, int>> res;\n\
    \    for (const auto &x : v) {\n        if (res.empty() || res.back().first !=\
    \ x) {\n            res.emplace_back(x, 0);\n        }\n        res.back().second++;\n\
    \    }\n    return res;\n}\n\ninline vector<pair<char, int>> run_length_encoding(const\
    \ string &s) {\n    return run_length_encoding(vector<char>(s.begin(), s.end()));\n\
    }"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/string/rle.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/rle.hpp
layout: document
redirect_from:
- /library/src/string/rle.hpp
- /library/src/string/rle.hpp.html
title: src/string/rle.hpp
---
