---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/string/lcp_array.hpp
    title: src/string/lcp_array.hpp
  - icon: ':x:'
    path: src/string/suffix_array.hpp
    title: src/string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/string/lcp_array.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\
    \n\n#line 2 \"src/string/lcp_array.hpp\"\n#include <vector>\n#include <algorithm>\n\
    #include <string>\nusing namespace std;\n\n\n// lcp[i] = lcp(S[ sa[i-1] : N ],\
    \ S[ sa[i] : N ])\ntemplate<typename S>\nvector<int> lcp_array(const vector<S>\
    \ &v, const vector<int> &sa) {\n    int n = v.size();\n    vector<int> lcp(n),\
    \ rank(n);\n    for (int i = 0; i < n; i++) rank[ sa[i] ] = i;\n    for(int i\
    \ = 0, h = 0; i < n; i++) {\n        if(rank[i] + 1 < n) {\n            int j\
    \ = sa[ rank[i] + 1 ];\n            while (i + h < n && j + h < n && v[i + h]\
    \ == v[j + h]) h++;\n            lcp[ rank[i] + 1 ] = h;\n            if (h >\
    \ 0) h--;\n        }\n    }\n    return lcp;\n}\n\ninline vector<int> lcp_array(const\
    \ string &s, const vector<int> &sa) {\n    return lcp_array(vector<char>(s.begin(),\
    \ s.end()), sa);\n}\n#line 5 \"src/string/suffix_array.hpp\"\nusing namespace\
    \ std;\n\n// S[ sa[i-1] : N] < S[ sa[i] : N]\n// O(N log N)\ntemplate<typename\
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
    \ {\n    return suffix_array(vector<char>(s.begin(), s.end()));\n}\n#line 5 \"\
    test/string/lcp_array.test.cpp\"\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    string S;\n    cin >> S;\n    int N = S.size();\n\
    \    auto sa = suffix_array(S);\n    long long ans = (long long)N * (N + 1) /\
    \ 2;\n    for (auto e : lcp_array(S, sa)) ans -= e;\n    cout << ans << endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include \"../../src/string/lcp_array.hpp\"\n#include \"../../src/string/suffix_array.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    string S;\n    cin >> S;\n    int N = S.size();\n  \
    \  auto sa = suffix_array(S);\n    long long ans = (long long)N * (N + 1) / 2;\n\
    \    for (auto e : lcp_array(S, sa)) ans -= e;\n    cout << ans << endl;\n}"
  dependsOn:
  - src/string/lcp_array.hpp
  - src/string/suffix_array.hpp
  isVerificationFile: true
  path: test/string/lcp_array.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/string/lcp_array.test.cpp
layout: document
redirect_from:
- /verify/test/string/lcp_array.test.cpp
- /verify/test/string/lcp_array.test.cpp.html
title: test/string/lcp_array.test.cpp
---
