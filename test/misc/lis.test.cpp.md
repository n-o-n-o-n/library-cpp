---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/misc/lis.hpp
    title: src/misc/lis.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/misc/lis.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return numeric_limits<T>::max()\
    \ / 2; }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return\
    \ a > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/misc/lis.hpp\"\
    \n\ntemplate<typename T>\nvector<int> longest_increasing_subsequence(const vector<T>\
    \ &v, bool strict = true) {\n    if (v.empty()) return {};\n    int n = v.size();\n\
    \    vector<T> dp;\n    vector<int> idx(n, -1);\n    for (int i = 0; i < n; i++)\
    \ {\n        int j;\n        if (strict) {\n            j = lower_bound(dp.begin(),\
    \ dp.end(), v[i]) - dp.begin();\n        } else {\n            j = upper_bound(dp.begin(),\
    \ dp.end(), v[i]) - dp.begin();\n        }\n        if (j == ssize(dp)) dp.push_back(v[i]);\n\
    \        else dp[j] = v[i];\n        idx[i] = j;\n    }\n    int m = *max_element(idx.begin(),\
    \ idx.end());\n    vector<int> res(m + 1);\n    for (int i = n - 1; i >= 0; i--)\
    \ {\n        if (idx[i] == m) {\n            res[m] = i;\n            m--;\n \
    \       }\n    }\n    return res;\n}\n#line 5 \"test/misc/lis.test.cpp\"\n\nint\
    \ main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n\
    \    cin >> N;\n    vector<int> A(N);\n    for (auto &e : A) cin >> e;\n    auto\
    \ lis = longest_increasing_subsequence(A);\n    cout << ssize(lis) << '\\n';\n\
    \    for (int i = 0; i < ssize(lis); i++) cout << lis[i] << \" \\n\"[i + 1 ==\
    \ ssize(lis)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"../../src/template.hpp\"\n#include \"../../src/misc/lis.hpp\"\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    vector<int> A(N);\n    for (auto &e : A) cin >> e;\n\
    \    auto lis = longest_increasing_subsequence(A);\n    cout << ssize(lis) <<\
    \ '\\n';\n    for (int i = 0; i < ssize(lis); i++) cout << lis[i] << \" \\n\"\
    [i + 1 == ssize(lis)];\n}"
  dependsOn:
  - src/template.hpp
  - src/misc/lis.hpp
  isVerificationFile: true
  path: test/misc/lis.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/lis.test.cpp
layout: document
redirect_from:
- /verify/test/misc/lis.test.cpp
- /verify/test/misc/lis.test.cpp.html
title: test/misc/lis.test.cpp
---
