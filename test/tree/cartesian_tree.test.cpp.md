---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  - icon: ':x:'
    path: src/tree/cartesian_tree.hpp
    title: src/tree/cartesian_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/tree/cartesian_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    template<typename T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2;\
    \ }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a\
    \ > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/tree/cartesian_tree.hpp\"\
    \n\ntemplate<typename T>\nvector<int> cartesian_tree(const vector<T> &a) {\n \
    \   int n = a.size();\n    vector<int> p(n, -1);\n    stack<int> st;\n    for\
    \ (int i = 0, j; i < n; i++) {\n        j = -1;\n        while (st.size() && a[st.top()]\
    \ >= a[i]) {\n            j = st.top();\n            st.pop();\n        }\n  \
    \      if (st.size()) p[i] = st.top();\n        if (j != -1) p[j] = i;\n     \
    \   st.push(i);\n    }\n    return p;\n}\n#line 5 \"test/tree/cartesian_tree.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N;\n    cin >> N;\n    vector<int> A(N);\n    for (auto &e : A) cin >>\
    \ e;\n    auto P = cartesian_tree(A);\n    for (int i = 0; i < N; i++) cout <<\
    \ (P[i] == -1 ? i : P[i]) << \" \\n\"[i + 1 == N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"../../src/template.hpp\"\n#include \"../../src/tree/cartesian_tree.hpp\"\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    vector<int> A(N);\n    for (auto &e : A) cin >> e;\n\
    \    auto P = cartesian_tree(A);\n    for (int i = 0; i < N; i++) cout << (P[i]\
    \ == -1 ? i : P[i]) << \" \\n\"[i + 1 == N];\n}"
  dependsOn:
  - src/template.hpp
  - src/tree/cartesian_tree.hpp
  isVerificationFile: true
  path: test/tree/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/tree/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/tree/cartesian_tree.test.cpp
- /verify/test/tree/cartesian_tree.test.cpp.html
title: test/tree/cartesian_tree.test.cpp
---
