---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/cartesian_tree.test.cpp
    title: test/tree/cartesian_tree.test.cpp
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
    \ }\n#line 3 \"src/tree/cartesian_tree.hpp\"\n\ntemplate<typename T>\nvector<int>\
    \ cartesian_tree(const vector<T> &a) {\n    int n = a.size();\n    vector<int>\
    \ p(n, -1);\n    stack<int> st;\n    for (int i = 0, j; i < n; i++) {\n      \
    \  j = -1;\n        while (st.size() && a[st.top()] >= a[i]) {\n            j\
    \ = st.top();\n            st.pop();\n        }\n        if (st.size()) p[i] =\
    \ st.top();\n        if (j != -1) p[j] = i;\n        st.push(i);\n    }\n    return\
    \ p;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T>\nvector<int>\
    \ cartesian_tree(const vector<T> &a) {\n    int n = a.size();\n    vector<int>\
    \ p(n, -1);\n    stack<int> st;\n    for (int i = 0, j; i < n; i++) {\n      \
    \  j = -1;\n        while (st.size() && a[st.top()] >= a[i]) {\n            j\
    \ = st.top();\n            st.pop();\n        }\n        if (st.size()) p[i] =\
    \ st.top();\n        if (j != -1) p[j] = i;\n        st.push(i);\n    }\n    return\
    \ p;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/tree/cartesian_tree.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/cartesian_tree.test.cpp
documentation_of: src/tree/cartesian_tree.hpp
layout: document
redirect_from:
- /library/src/tree/cartesian_tree.hpp
- /library/src/tree/cartesian_tree.hpp.html
title: src/tree/cartesian_tree.hpp
---
