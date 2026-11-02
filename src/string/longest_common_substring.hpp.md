---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/string/lcp_array.hpp
    title: src/string/lcp_array.hpp
  - icon: ':x:'
    path: src/string/suffix_array.hpp
    title: src/string/suffix_array.hpp
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
    \ }\n#line 3 \"src/string/suffix_array.hpp\"\n\n// S[ sa[i-1] : N] < S[ sa[i]\
    \ : N]\n// O(N log N)\ntemplate<typename S>\nvector<int> suffix_array(const vector<S>\
    \ &v) {\n    int n = v.size();\n    vector<int> sa(n);\n    for (int i = 0; i\
    \ < n; i++) sa[i] = i;\n    sort(sa.begin(), sa.end(), [&](int i, int j) {\n \
    \       return v[i] == v[j] ? i > j : v[i] < v[j];\n    });\n    vector<int> cls(n),\
    \ c(n), cnt(n);\n    for (int i = 0; i < n; i++) c[i] = v[i];\n    for (int k\
    \ = 1; k < n; k <<= 1) {\n        cls[sa[0]] = 0;\n        for (int i = 1; i <\
    \ n; i++) {\n            cls[sa[i]] = ([&] {\n                if (c[ sa[i - 1]\
    \ ] != c[ sa[i] ]) return false;\n                if (sa[i - 1] + k >= n) return\
    \ false;\n                if (c[ sa[i - 1] + k / 2 ] != c[ sa[i] + k / 2 ]) return\
    \ false;\n                return true;\n            }()) ? cls[ sa[i - 1] ] :\
    \ i;\n        }\n        for (int i = 0; i < n; i++) {\n            cnt[i] = i;\n\
    \            c[i] = sa[i];\n        }\n        for (int i = 0; i < n; i++) {\n\
    \            int j = c[i] - k;\n            if (j >= 0) sa[ cnt[ cls[j] ]++ ]\
    \ = j;\n        }\n        swap(c, cls);\n    }\n    return sa;\n}\n\ninline vector<int>\
    \ suffix_array(const string &s) {\n    return suffix_array(vector<char>(s.begin(),\
    \ s.end()));\n}\n#line 3 \"src/string/lcp_array.hpp\"\n\n\n// lcp[i] = lcp(S[\
    \ sa[i-1] : N ], S[ sa[i] : N ])\ntemplate<typename S>\nvector<int> lcp_array(const\
    \ vector<S> &v, const vector<int> &sa) {\n    int n = v.size();\n    vector<int>\
    \ lcp(n), rank(n);\n    for (int i = 0; i < n; i++) rank[ sa[i] ] = i;\n    for(int\
    \ i = 0, h = 0; i < n; i++) {\n        if(rank[i] + 1 < n) {\n            int\
    \ j = sa[ rank[i] + 1 ];\n            while (i + h < n && j + h < n && v[i + h]\
    \ == v[j + h]) h++;\n            lcp[ rank[i] + 1 ] = h;\n            if (h >\
    \ 0) h--;\n        }\n    }\n    return lcp;\n}\n\ninline vector<int> lcp_array(const\
    \ string &s, const vector<int> &sa) {\n    return lcp_array(vector<char>(s.begin(),\
    \ s.end()), sa);\n}\n#line 5 \"src/string/longest_common_substring.hpp\"\n\ntemplate<typename\
    \ T>\ntuple<int, int, int> longest_common_substring(const vector<T> &a, const\
    \ vector<T> &b) {\n    int n = a.size(), m = b.size();\n    T q = max<T>(*max_element(a.begin(),\
    \ a.end()), *max_element(b.begin(), b.end())) + 1;\n    vector<T> ab;\n    ab.reserve(n\
    \ + m + 1);\n    for (const T &e : a) ab.emplace_back(e);\n    ab.emplace_back(q);\n\
    \    for (const T &e : b) ab.emplace_back(e);\n    auto sa = suffix_array(ab);\n\
    \    auto lcp = lcp_array(ab, sa);\n    tuple<int, int, int> res = make_tuple(0,\
    \ 0, 0);\n    int len = 0;\n    for (int k = 0; k < n + m; k++) {\n        int\
    \ i = sa[k], j = sa[k + 1];\n        if (i > j) swap(i, j);\n        if (i < n\
    \ && n < j && len < lcp[k + 1]) {\n            len = lcp[k + 1];\n           \
    \ res = make_tuple(len, i, j - n - 1);\n        }\n    }\n    return res;\n}\n\
    \ninline tuple<int, int, int> longest_common_substring(const string &s, const\
    \ string &t) {\n    return longest_common_substring(vector<char>(s.begin(), s.end()),\
    \ vector<char>(t.begin(), t.end()));\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n#include \"suffix_array.hpp\"\
    \n#include \"lcp_array.hpp\"\n\ntemplate<typename T>\ntuple<int, int, int> longest_common_substring(const\
    \ vector<T> &a, const vector<T> &b) {\n    int n = a.size(), m = b.size();\n \
    \   T q = max<T>(*max_element(a.begin(), a.end()), *max_element(b.begin(), b.end()))\
    \ + 1;\n    vector<T> ab;\n    ab.reserve(n + m + 1);\n    for (const T &e : a)\
    \ ab.emplace_back(e);\n    ab.emplace_back(q);\n    for (const T &e : b) ab.emplace_back(e);\n\
    \    auto sa = suffix_array(ab);\n    auto lcp = lcp_array(ab, sa);\n    tuple<int,\
    \ int, int> res = make_tuple(0, 0, 0);\n    int len = 0;\n    for (int k = 0;\
    \ k < n + m; k++) {\n        int i = sa[k], j = sa[k + 1];\n        if (i > j)\
    \ swap(i, j);\n        if (i < n && n < j && len < lcp[k + 1]) {\n           \
    \ len = lcp[k + 1];\n            res = make_tuple(len, i, j - n - 1);\n      \
    \  }\n    }\n    return res;\n}\n\ninline tuple<int, int, int> longest_common_substring(const\
    \ string &s, const string &t) {\n    return longest_common_substring(vector<char>(s.begin(),\
    \ s.end()), vector<char>(t.begin(), t.end()));\n}"
  dependsOn:
  - src/template.hpp
  - src/string/suffix_array.hpp
  - src/string/lcp_array.hpp
  isVerificationFile: false
  path: src/string/longest_common_substring.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/longest_common_substring.hpp
layout: document
redirect_from:
- /library/src/string/longest_common_substring.hpp
- /library/src/string/longest_common_substring.hpp.html
title: src/string/longest_common_substring.hpp
---
