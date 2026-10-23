---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/hungarian.hpp
    title: Hungarian
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/graph/hungarian.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\
    \n\n#line 2 \"src/graph/hungarian.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <limits>\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \ntemplate<typename T>\nvector<pair<int, int>> hungarian(const vector<vector<T>>\
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
    \    return res;\n}\n#line 4 \"test/graph/hungarian.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    vector<vector<long long>> A(N, vector<long long>(N));\n\
    \    for (auto &E : A) for (auto &e : E) cin >> e;\n    auto ans = hungarian(A);\n\
    \    long long X = 0;\n    for (auto [i, j] : ans) X += A[i][j];\n    cout <<\
    \ X << '\\n';\n    for (auto [i, j] : ans) {\n        if (i) cout << ' ';\n  \
    \      cout << j;\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ \"../../src/graph/hungarian.hpp\"\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin >>\
    \ N;\n    vector<vector<long long>> A(N, vector<long long>(N));\n    for (auto\
    \ &E : A) for (auto &e : E) cin >> e;\n    auto ans = hungarian(A);\n    long\
    \ long X = 0;\n    for (auto [i, j] : ans) X += A[i][j];\n    cout << X << '\\\
    n';\n    for (auto [i, j] : ans) {\n        if (i) cout << ' ';\n        cout\
    \ << j;\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - src/graph/hungarian.hpp
  isVerificationFile: true
  path: test/graph/hungarian.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/hungarian.test.cpp
layout: document
redirect_from:
- /verify/test/graph/hungarian.test.cpp
- /verify/test/graph/hungarian.test.cpp.html
title: test/graph/hungarian.test.cpp
---
