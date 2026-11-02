---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/string/longest_common_substring.hpp
    title: src/string/longest_common_substring.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/lcp_array.test.cpp
    title: test/string/lcp_array.test.cpp
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
    \ }\n#line 3 \"src/string/lcp_array.hpp\"\n\n\n// lcp[i] = lcp(S[ sa[i-1] : N\
    \ ], S[ sa[i] : N ])\ntemplate<typename S>\nvector<int> lcp_array(const vector<S>\
    \ &v, const vector<int> &sa) {\n    int n = v.size();\n    vector<int> lcp(n),\
    \ rank(n);\n    for (int i = 0; i < n; i++) rank[ sa[i] ] = i;\n    for(int i\
    \ = 0, h = 0; i < n; i++) {\n        if(rank[i] + 1 < n) {\n            int j\
    \ = sa[ rank[i] + 1 ];\n            while (i + h < n && j + h < n && v[i + h]\
    \ == v[j + h]) h++;\n            lcp[ rank[i] + 1 ] = h;\n            if (h >\
    \ 0) h--;\n        }\n    }\n    return lcp;\n}\n\ninline vector<int> lcp_array(const\
    \ string &s, const vector<int> &sa) {\n    return lcp_array(vector<char>(s.begin(),\
    \ s.end()), sa);\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\n\n// lcp[i] = lcp(S[ sa[i-1]\
    \ : N ], S[ sa[i] : N ])\ntemplate<typename S>\nvector<int> lcp_array(const vector<S>\
    \ &v, const vector<int> &sa) {\n    int n = v.size();\n    vector<int> lcp(n),\
    \ rank(n);\n    for (int i = 0; i < n; i++) rank[ sa[i] ] = i;\n    for(int i\
    \ = 0, h = 0; i < n; i++) {\n        if(rank[i] + 1 < n) {\n            int j\
    \ = sa[ rank[i] + 1 ];\n            while (i + h < n && j + h < n && v[i + h]\
    \ == v[j + h]) h++;\n            lcp[ rank[i] + 1 ] = h;\n            if (h >\
    \ 0) h--;\n        }\n    }\n    return lcp;\n}\n\ninline vector<int> lcp_array(const\
    \ string &s, const vector<int> &sa) {\n    return lcp_array(vector<char>(s.begin(),\
    \ s.end()), sa);\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/string/lcp_array.hpp
  requiredBy:
  - src/string/longest_common_substring.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/lcp_array.test.cpp
documentation_of: src/string/lcp_array.hpp
layout: document
redirect_from:
- /library/src/string/lcp_array.hpp
- /library/src/string/lcp_array.hpp.html
title: src/string/lcp_array.hpp
---
