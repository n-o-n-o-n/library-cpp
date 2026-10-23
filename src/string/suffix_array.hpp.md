---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/string/longest_common_substring.hpp
    title: src/string/longest_common_substring.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/string/lcp_array.test.cpp
    title: test/string/lcp_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/suffix_array.hpp\"\n#include <algorithm>\n#include\
    \ <string>\n#include <vector>\nusing namespace std;\n\n// S[ sa[i-1] : N] < S[\
    \ sa[i] : N]\n// O(N log N)\ntemplate<typename S>\nvector<int> suffix_array(const\
    \ vector<S> &v) {\n    int n = v.size();\n    vector<int> sa(n);\n    for (int\
    \ i = 0; i < n; i++) sa[i] = i;\n    sort(sa.begin(), sa.end(), [&](int i, int\
    \ j) {\n        return v[i] == v[j] ? i > j : v[i] < v[j];\n    });\n    vector<int>\
    \ cls(n), c(n), cnt(n);\n    for (int i = 0; i < n; i++) c[i] = v[i];\n    for\
    \ (int k = 1; k < n; k <<= 1) {\n        cls[sa[0]] = 0;\n        for (int i =\
    \ 1; i < n; i++) {\n            cls[sa[i]] = ([&] {\n                if (c[ sa[i\
    \ - 1] ] != c[ sa[i] ]) return false;\n                if (sa[i - 1] + k >= n)\
    \ return false;\n                if (c[ sa[i - 1] + k / 2 ] != c[ sa[i] + k /\
    \ 2 ]) return false;\n                return true;\n            }()) ? cls[ sa[i\
    \ - 1] ] : i;\n        }\n        for (int i = 0; i < n; i++) {\n            cnt[i]\
    \ = i;\n            c[i] = sa[i];\n        }\n        for (int i = 0; i < n; i++)\
    \ {\n            int j = c[i] - k;\n            if (j >= 0) sa[ cnt[ cls[j] ]++\
    \ ] = j;\n        }\n        swap(c, cls);\n    }\n    return sa;\n}\n\ninline\
    \ vector<int> suffix_array(const string &s) {\n    return suffix_array(vector<char>(s.begin(),\
    \ s.end()));\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <string>\n#include <vector>\n\
    using namespace std;\n\n// S[ sa[i-1] : N] < S[ sa[i] : N]\n// O(N log N)\ntemplate<typename\
    \ S>\nvector<int> suffix_array(const vector<S> &v) {\n    int n = v.size();\n\
    \    vector<int> sa(n);\n    for (int i = 0; i < n; i++) sa[i] = i;\n    sort(sa.begin(),\
    \ sa.end(), [&](int i, int j) {\n        return v[i] == v[j] ? i > j : v[i] <\
    \ v[j];\n    });\n    vector<int> cls(n), c(n), cnt(n);\n    for (int i = 0; i\
    \ < n; i++) c[i] = v[i];\n    for (int k = 1; k < n; k <<= 1) {\n        cls[sa[0]]\
    \ = 0;\n        for (int i = 1; i < n; i++) {\n            cls[sa[i]] = ([&] {\n\
    \                if (c[ sa[i - 1] ] != c[ sa[i] ]) return false;\n           \
    \     if (sa[i - 1] + k >= n) return false;\n                if (c[ sa[i - 1]\
    \ + k / 2 ] != c[ sa[i] + k / 2 ]) return false;\n                return true;\n\
    \            }()) ? cls[ sa[i - 1] ] : i;\n        }\n        for (int i = 0;\
    \ i < n; i++) {\n            cnt[i] = i;\n            c[i] = sa[i];\n        }\n\
    \        for (int i = 0; i < n; i++) {\n            int j = c[i] - k;\n      \
    \      if (j >= 0) sa[ cnt[ cls[j] ]++ ] = j;\n        }\n        swap(c, cls);\n\
    \    }\n    return sa;\n}\n\ninline vector<int> suffix_array(const string &s)\
    \ {\n    return suffix_array(vector<char>(s.begin(), s.end()));\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/string/suffix_array.hpp
  requiredBy:
  - src/string/longest_common_substring.hpp
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/string/lcp_array.test.cpp
documentation_of: src/string/suffix_array.hpp
layout: document
redirect_from:
- /library/src/string/suffix_array.hpp
- /library/src/string/suffix_array.hpp.html
title: src/string/suffix_array.hpp
---
