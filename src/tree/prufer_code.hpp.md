---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/random/graph.hpp
    title: src/random/graph.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/prufer_code.test.cpp
    title: test/tree/prufer_code.test.cpp
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
    \ }\n#line 3 \"src/tree/prufer_code.hpp\"\n\ninline vector<int> prufer_code_compress(const\
    \ vector<vector<int>> &t) {\n    int n = t.size();\n    if (n <= 2) return {};\n\
    \    vector<int> deg(n);\n    priority_queue<int, vector<int>, greater<int>> q;\n\
    \    for (int i = 0; i < n; i++) {\n        deg[i] = t[i].size();\n        if\
    \ (deg[i] == 1) {\n            q.push(i);\n        }\n    }\n    vector<int> p;\n\
    \    p.reserve(n - 2);\n    while ((int)p.size() < n - 2) {\n        int u = q.top();\n\
    \        q.pop();\n        for (int v : t[u]) {\n            if (deg[v] > 0) {\n\
    \                p.push_back(v);\n                deg[v]--;\n                if\
    \ (deg[v] == 1) q.push(v);\n                break;\n            }\n        }\n\
    \        deg[u]--;\n    }\n    return p;\n}\n\ninline vector<vector<int>> prufer_code_expansion(const\
    \ vector<int> &p) {\n    int n = p.size() + 2;\n    vector<int> deg(n, 1);\n \
    \   for (int u : p) deg[u]++;\n    priority_queue<int, vector<int>, greater<int>>\
    \ q;\n    for (int i = 0; i < n; i++) {\n        if (deg[i] == 1) q.push(i);\n\
    \    }\n    vector<vector<int>> t(n);\n    for (int i = 0; i < n - 2; i++) {\n\
    \        int u = p[i];\n        int v = q.top();\n        q.pop();\n        t[u].push_back(v);\n\
    \        t[v].push_back(u);\n        deg[u]--, deg[v]--;\n        if (deg[u] ==\
    \ 1) q.push(u);\n    }\n    for (int i = 0; i < n; i++) {\n        if (deg[i]\
    \ == 1) {\n            for (int j = 0; j < n; j++) {\n                if (j !=\
    \ i && deg[j] == 1) {\n                    t[i].push_back(j);\n              \
    \      t[j].push_back(i);\n                    deg[i]--, deg[j]--;\n         \
    \           break;\n                }\n            }\n            break;\n   \
    \     }\n    }\n    return t;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ninline vector<int> prufer_code_compress(const\
    \ vector<vector<int>> &t) {\n    int n = t.size();\n    if (n <= 2) return {};\n\
    \    vector<int> deg(n);\n    priority_queue<int, vector<int>, greater<int>> q;\n\
    \    for (int i = 0; i < n; i++) {\n        deg[i] = t[i].size();\n        if\
    \ (deg[i] == 1) {\n            q.push(i);\n        }\n    }\n    vector<int> p;\n\
    \    p.reserve(n - 2);\n    while ((int)p.size() < n - 2) {\n        int u = q.top();\n\
    \        q.pop();\n        for (int v : t[u]) {\n            if (deg[v] > 0) {\n\
    \                p.push_back(v);\n                deg[v]--;\n                if\
    \ (deg[v] == 1) q.push(v);\n                break;\n            }\n        }\n\
    \        deg[u]--;\n    }\n    return p;\n}\n\ninline vector<vector<int>> prufer_code_expansion(const\
    \ vector<int> &p) {\n    int n = p.size() + 2;\n    vector<int> deg(n, 1);\n \
    \   for (int u : p) deg[u]++;\n    priority_queue<int, vector<int>, greater<int>>\
    \ q;\n    for (int i = 0; i < n; i++) {\n        if (deg[i] == 1) q.push(i);\n\
    \    }\n    vector<vector<int>> t(n);\n    for (int i = 0; i < n - 2; i++) {\n\
    \        int u = p[i];\n        int v = q.top();\n        q.pop();\n        t[u].push_back(v);\n\
    \        t[v].push_back(u);\n        deg[u]--, deg[v]--;\n        if (deg[u] ==\
    \ 1) q.push(u);\n    }\n    for (int i = 0; i < n; i++) {\n        if (deg[i]\
    \ == 1) {\n            for (int j = 0; j < n; j++) {\n                if (j !=\
    \ i && deg[j] == 1) {\n                    t[i].push_back(j);\n              \
    \      t[j].push_back(i);\n                    deg[i]--, deg[j]--;\n         \
    \           break;\n                }\n            }\n            break;\n   \
    \     }\n    }\n    return t;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/tree/prufer_code.hpp
  requiredBy:
  - src/random/graph.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/prufer_code.test.cpp
documentation_of: src/tree/prufer_code.hpp
layout: document
redirect_from:
- /library/src/tree/prufer_code.hpp
- /library/src/tree/prufer_code.hpp.html
title: src/tree/prufer_code.hpp
---
