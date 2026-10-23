---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/graph/hungarian.test.cpp
    title: test/graph/hungarian.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/graph/hungarian.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <utility>\n#include <vector>\nusing namespace\
    \ std;\n\ntemplate<typename T>\nvector<pair<int, int>> hungarian(const vector<vector<T>>\
    \ &a) {\n    int h = a.size(), w = a[0].size();\n    if (h > w) {\n        vector<vector<T>>\
    \ b(w, vector<T>(h));\n        for (int i = 0; i < h; i++) {\n            for\
    \ (int j = 0; j < w; j++) b[j][i] = a[i][j];\n        }\n        auto res = hungarian<T>(b);\n\
    \        for (auto &[u, v] : res) swap(u, v);\n        sort(res.begin(), res.end());\n\
    \        return res;\n    }\n    const T inf = numeric_limits<T>::max();\n   \
    \ vector<int> p(w + 1), way(w + 1);\n    vector<T> u(h + 1), v(w + 1);\n    for\
    \ (int i = 1; i <= h; i++) {\n        p[0] = i;\n        vector<T> min_v(w + 1,\
    \ inf);\n        vector<bool> used(w + 1, false);\n        int j = 0;\n      \
    \  do {\n            used[j] = true;\n            int k = 0;\n            T d\
    \ = inf;\n            for (int c = 1; c <= w; c++) {\n                if (used[c])\
    \ continue;\n                T cur = a[p[j] - 1][c - 1] - u[p[j]] - v[c];\n  \
    \              if (cur < min_v[c]) min_v[c] = cur, way[c] = j;\n             \
    \   if (min_v[c] < d) d = min_v[c], k = c;\n            }\n            for (int\
    \ c = 0; c <= w; c++) {\n                if (used[c]) u[p[c]] += d, v[c] -= d;\n\
    \                else min_v[c] -= d;\n            }\n            j = k;\n    \
    \    } while (p[j] != 0);\n        do {\n            p[j] = p[way[j]];\n     \
    \       j = way[j];\n        } while (j != 0);\n    }\n    vector<pair<int, int>>\
    \ res;\n    res.reserve(h);\n    for (int c = 1; c <= w; c++) {\n        if (p[c]\
    \ != 0) res.emplace_back(p[c] - 1, c - 1);\n    }\n    sort(res.begin(), res.end());\n\
    \    return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T>\nvector<pair<int, int>> hungarian(const vector<vector<T>> &a) {\n    int\
    \ h = a.size(), w = a[0].size();\n    if (h > w) {\n        vector<vector<T>>\
    \ b(w, vector<T>(h));\n        for (int i = 0; i < h; i++) {\n            for\
    \ (int j = 0; j < w; j++) b[j][i] = a[i][j];\n        }\n        auto res = hungarian<T>(b);\n\
    \        for (auto &[u, v] : res) swap(u, v);\n        sort(res.begin(), res.end());\n\
    \        return res;\n    }\n    const T inf = numeric_limits<T>::max();\n   \
    \ vector<int> p(w + 1), way(w + 1);\n    vector<T> u(h + 1), v(w + 1);\n    for\
    \ (int i = 1; i <= h; i++) {\n        p[0] = i;\n        vector<T> min_v(w + 1,\
    \ inf);\n        vector<bool> used(w + 1, false);\n        int j = 0;\n      \
    \  do {\n            used[j] = true;\n            int k = 0;\n            T d\
    \ = inf;\n            for (int c = 1; c <= w; c++) {\n                if (used[c])\
    \ continue;\n                T cur = a[p[j] - 1][c - 1] - u[p[j]] - v[c];\n  \
    \              if (cur < min_v[c]) min_v[c] = cur, way[c] = j;\n             \
    \   if (min_v[c] < d) d = min_v[c], k = c;\n            }\n            for (int\
    \ c = 0; c <= w; c++) {\n                if (used[c]) u[p[c]] += d, v[c] -= d;\n\
    \                else min_v[c] -= d;\n            }\n            j = k;\n    \
    \    } while (p[j] != 0);\n        do {\n            p[j] = p[way[j]];\n     \
    \       j = way[j];\n        } while (j != 0);\n    }\n    vector<pair<int, int>>\
    \ res;\n    res.reserve(h);\n    for (int c = 1; c <= w; c++) {\n        if (p[c]\
    \ != 0) res.emplace_back(p[c] - 1, c - 1);\n    }\n    sort(res.begin(), res.end());\n\
    \    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/hungarian.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/graph/hungarian.test.cpp
documentation_of: src/graph/hungarian.hpp
layout: document
title: Hungarian
---

重み付き完全二部グラフの最小重み最大マッチングを求める.

## hungarian

```
template<typename T>
vector<pair<int, int>> hungarian(vector<vector<T>> a)
```

- $a_{i,j}$ を左頂点 $i$ と右頂点 $j$ を結ぶ辺のコストとする
- 要素数 $\min(h, w)$ の最小重みマッチングを返す
- 返り値の各組 $(i, j)$ はマッチした辺を表し, $i$ の昇順に並ぶ
- $O(\min(h, w)^2\max(h, w))$
