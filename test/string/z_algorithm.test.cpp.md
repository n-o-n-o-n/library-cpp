---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/z_algorithm.hpp
    title: src/string/z_algorithm.hpp
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/string/z_algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return numeric_limits<T>::max()\
    \ / 2; }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return\
    \ a > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/string/z_algorithm.hpp\"\
    \n\n\ntemplate<typename S> \nvector<int> z_algorithm(const vector<S> &v) {\n \
    \   const int n = v.size();\n    int p = 0;\n    vector<int> z(n);\n    for (int\
    \ i = 1; i < n; i++) {\n        int k = i - p;\n        if (i + z[k] < p + z[p])\
    \ {\n            z[i] = z[k];\n        } else {\n            int j = max(0, p\
    \ + z[p] - i);\n            while (i + j < n && v[j] == v[i + j]) j++;\n     \
    \       z[i] = j;\n            p = i;\n        }\n    }\n    z[0] = n;\n    return\
    \ z;\n}\n\ninline vector<int> z_algorithm(const string &s) {\n    return z_algorithm(vector<char>(s.begin(),\
    \ s.end()));\n}\n#line 5 \"test/string/z_algorithm.test.cpp\"\n\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    string S;\n    cin\
    \ >> S;\n    auto Z = z_algorithm(S);\n    for (int i = 0; i < ssize(Z); i++)\
    \ {\n        cout << Z[i] << \" \\n\"[i + 1 == ssize(Z)];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../../src/template.hpp\"\n#include \"../../src/string/z_algorithm.hpp\"\n\n\
    int main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    string\
    \ S;\n    cin >> S;\n    auto Z = z_algorithm(S);\n    for (int i = 0; i < ssize(Z);\
    \ i++) {\n        cout << Z[i] << \" \\n\"[i + 1 == ssize(Z)];\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/string/z_algorithm.hpp
  isVerificationFile: true
  path: test/string/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/string/z_algorithm.test.cpp
- /verify/test/string/z_algorithm.test.cpp.html
title: test/string/z_algorithm.test.cpp
---
