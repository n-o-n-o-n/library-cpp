---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/tree/diameter.test.cpp
    title: test/tree/diameter.test.cpp
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
    \ }\n#line 3 \"src/tree/diameter.hpp\"\n\ntemplate<typename T>\ninline pair<T,\
    \ vector<int>> diameter(const vector<vector<pair<int, T>>> &g) {\n    int n =\
    \ g.size();\n    auto bfs = [&] (int root) -> vector<T> {\n        vector<T> dist(n,\
    \ inf<T>());\n        dist[root] = 0;\n        queue<int> q;\n        q.push(root);\n\
    \        while (q.size()) {\n            int u = q.front();\n            q.pop();\n\
    \            for (auto[v, w] : g[u]) {\n                if (dist[v] > dist[u]\
    \ + w) {\n                    dist[v] = dist[u] + w;\n                    q.push(v);\n\
    \                }\n            }\n        }\n        return dist;\n    };\n \
    \   vector<T> d0 = bfs(0);\n    int l = max_element(d0.begin(), d0.end()) - d0.begin();\n\
    \    vector<T> dl = bfs(l);\n    int r = max_element(dl.begin(), dl.end()) - dl.begin();\n\
    \    T diam = dl[r];\n    vector<int> path = {r};\n    while (r != l) {\n    \
    \    for (auto[v, w] : g[r]) {\n            if (dl[v] + w == dl[r]) {\n      \
    \          r = v;\n                break;\n            }\n        }\n        path.emplace_back(r);\n\
    \    }\n    return make_pair(diam, path);\n}\n\ninline pair<int, vector<int>>\
    \ diameter(const vector<vector<int>> &g) {\n    int n = g.size();\n    vector<vector<pair<int,\
    \ int>>> tmp(n);\n    for (int u = 0; u < n; u++) {\n        for (int v : g[u])\
    \ {\n            tmp[u].emplace_back(v, 1);\n        }\n    }\n    return diameter(tmp);\n\
    }\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename T>\ninline\
    \ pair<T, vector<int>> diameter(const vector<vector<pair<int, T>>> &g) {\n   \
    \ int n = g.size();\n    auto bfs = [&] (int root) -> vector<T> {\n        vector<T>\
    \ dist(n, inf<T>());\n        dist[root] = 0;\n        queue<int> q;\n       \
    \ q.push(root);\n        while (q.size()) {\n            int u = q.front();\n\
    \            q.pop();\n            for (auto[v, w] : g[u]) {\n               \
    \ if (dist[v] > dist[u] + w) {\n                    dist[v] = dist[u] + w;\n \
    \                   q.push(v);\n                }\n            }\n        }\n\
    \        return dist;\n    };\n    vector<T> d0 = bfs(0);\n    int l = max_element(d0.begin(),\
    \ d0.end()) - d0.begin();\n    vector<T> dl = bfs(l);\n    int r = max_element(dl.begin(),\
    \ dl.end()) - dl.begin();\n    T diam = dl[r];\n    vector<int> path = {r};\n\
    \    while (r != l) {\n        for (auto[v, w] : g[r]) {\n            if (dl[v]\
    \ + w == dl[r]) {\n                r = v;\n                break;\n          \
    \  }\n        }\n        path.emplace_back(r);\n    }\n    return make_pair(diam,\
    \ path);\n}\n\ninline pair<int, vector<int>> diameter(const vector<vector<int>>\
    \ &g) {\n    int n = g.size();\n    vector<vector<pair<int, int>>> tmp(n);\n \
    \   for (int u = 0; u < n; u++) {\n        for (int v : g[u]) {\n            tmp[u].emplace_back(v,\
    \ 1);\n        }\n    }\n    return diameter(tmp);\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/tree/diameter.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/tree/diameter.test.cpp
documentation_of: src/tree/diameter.hpp
layout: document
redirect_from:
- /library/src/tree/diameter.hpp
- /library/src/tree/diameter.hpp.html
title: src/tree/diameter.hpp
---
