---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/data_structure/union_find/union_find.hpp
    title: src/data_structure/union_find/union_find.hpp
  - icon: ':x:'
    path: src/misc/parallel_binary_search.hpp
    title: Parallel Binary Search
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2786
    links:
    - https://yukicoder.me/problems/no/2786
  bundledCode: "#line 1 \"test/misc/parallel_binary_search.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/2786\"\n\n#line 2 \"src/data_structure/union_find/union_find.hpp\"\
    \n#include <cassert>\n#include <iterator>\n#include <vector>\nusing namespace\
    \ std;\n\nstruct union_find {\n    union_find(int n) : p(n, -1) {}\n    int leader(int\
    \ u) {\n        assert(0 <= u && u < ssize(p));\n        return p[u] < 0 ? u :\
    \ p[u] = leader(p[u]);\n    }\n    bool same(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        return\
    \ leader(u) == leader(v);\n    }\n    void merge(int u, int v) {\n        assert(0\
    \ <= u && u < ssize(p));\n        assert(0 <= v && v < ssize(p));\n        u =\
    \ leader(u);\n        v = leader(v);\n        if (u == v) return;\n        if\
    \ (p[u] > p[v]) swap(u, v);\n        p[u] += p[v];\n        p[v] = u;\n    }\n\
    \    int size(int u) {\n        assert(0 <= u && u < ssize(p));\n        return\
    \ -p[leader(u)];\n    }\n    vector<vector<int>> groups() {\n        int n = p.size();\n\
    \        vector<vector<int>> tmp(n);\n        for (int i = 0; i < n; i++) {\n\
    \            tmp[leader(i)].push_back(i);\n        }\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) {\n            if (v.size()) res.push_back(v);\n\
    \        }\n        return res;\n    }\nprivate:\n    vector<int> p;\n};\n#line\
    \ 3 \"src/misc/parallel_binary_search.hpp\"\nusing namespace std;\n\n// \u4F7F\
    \u3044\u65B9\u306F\u3053\u308C\u3092\u53C2\u7167: https://atcoder.jp/contests/past20-open/submissions/71648427\
    \ \ntemplate<typename A, typename Q, typename R>\nvector<int> parallel_binary_search(int\
    \ t, int q, const A &act, const Q &query, const R &reset) {\n    vector<int> l(q,\
    \ -1), r(q, t);\n    for (int p = 1; p <= t; p *= 2) {\n        reset();\n   \
    \     vector<int> m(q);\n        vector<vector<int>> qs(t);\n        for (int\
    \ j = 0; j < q; j++) {\n            m[j] = (l[j] + r[j]) / 2;\n            qs[m[j]].push_back(j);\n\
    \        }\n        for (int i = 0; i < t; i++) {\n            act(i);\n     \
    \       for (int j : qs[i]) (query(j) ? r[j] : l[j]) = m[j];\n        }\n    }\n\
    \    return r;\n}\n#line 5 \"test/misc/parallel_binary_search.test.cpp\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <numeric>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int H, W;\n    cin >> H >> W;\n    vector<vector<int>>\
    \ A(H, vector<int>(W));\n    for (auto &E : A) for (auto &e : E) cin >> e;\n \
    \   int Q;\n    cin >> Q;\n    vector<tuple<int, int, int, int>> qs(Q);\n    for\
    \ (auto &[sr, sc, tr, tc] : qs) {\n        cin >> sr >> sc >> tr >> tc;\n    \
    \    sr--, sc--, tr--, tc--;\n    }\n    vector<pair<int, int>> ord;\n    ord.reserve(H\
    \ * W);\n    for (int i = 0; i < H; i++) {\n        for (int j = 0; j < W; j++)\
    \ ord.emplace_back(i, j);\n    }\n    sort(ord.begin(), ord.end(), [&] (pair<int,\
    \ int> p, pair<int, int> q) {\n        return A[p.first][p.second] < A[q.first][q.second];\n\
    \    });\n    union_find uf(H * W);\n    vector<vector<bool>> alive(H, vector<bool>(W,\
    \ false));\n    const int D[5] = {0, 1, 0, -1, 0};\n    auto reset = [&] () {\n\
    \        uf = union_find(H * W);\n        alive = vector<vector<bool>>(H, vector<bool>(W,\
    \ false));\n    };\n    auto act = [&] (int i) {\n        auto [r, c] = ord[i];\n\
    \        alive[r][c] = true;\n        for (int d = 0; d < 4; d++) {\n        \
    \    int nr = r + D[d], nc = c + D[d + 1];\n            if (0 <= nr && nr < H\
    \ && 0 <= nc && nc < W && alive[nr][nc]) {\n                uf.merge(r * W + c,\
    \ nr * W + nc);\n            }\n        }\n    };\n    auto query = [&](int j)\
    \ {\n        auto [sr, sc, tr, tc] = qs[j];\n        return alive[sr][sc] && alive[tr][tc]\
    \ && uf.same(sr * W + sc, tr * W + tc);\n    };\n    auto ans = parallel_binary_search(H\
    \ * W, Q, act, query, reset);\n    for (int i : ans) cout << A[ord[i].first][ord[i].second]\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2786\"\n\n#include \"\
    ../../src/data_structure/union_find/union_find.hpp\"\n#include \"../../src/misc/parallel_binary_search.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <numeric>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int H, W;\n\
    \    cin >> H >> W;\n    vector<vector<int>> A(H, vector<int>(W));\n    for (auto\
    \ &E : A) for (auto &e : E) cin >> e;\n    int Q;\n    cin >> Q;\n    vector<tuple<int,\
    \ int, int, int>> qs(Q);\n    for (auto &[sr, sc, tr, tc] : qs) {\n        cin\
    \ >> sr >> sc >> tr >> tc;\n        sr--, sc--, tr--, tc--;\n    }\n    vector<pair<int,\
    \ int>> ord;\n    ord.reserve(H * W);\n    for (int i = 0; i < H; i++) {\n   \
    \     for (int j = 0; j < W; j++) ord.emplace_back(i, j);\n    }\n    sort(ord.begin(),\
    \ ord.end(), [&] (pair<int, int> p, pair<int, int> q) {\n        return A[p.first][p.second]\
    \ < A[q.first][q.second];\n    });\n    union_find uf(H * W);\n    vector<vector<bool>>\
    \ alive(H, vector<bool>(W, false));\n    const int D[5] = {0, 1, 0, -1, 0};\n\
    \    auto reset = [&] () {\n        uf = union_find(H * W);\n        alive = vector<vector<bool>>(H,\
    \ vector<bool>(W, false));\n    };\n    auto act = [&] (int i) {\n        auto\
    \ [r, c] = ord[i];\n        alive[r][c] = true;\n        for (int d = 0; d < 4;\
    \ d++) {\n            int nr = r + D[d], nc = c + D[d + 1];\n            if (0\
    \ <= nr && nr < H && 0 <= nc && nc < W && alive[nr][nc]) {\n                uf.merge(r\
    \ * W + c, nr * W + nc);\n            }\n        }\n    };\n    auto query = [&](int\
    \ j) {\n        auto [sr, sc, tr, tc] = qs[j];\n        return alive[sr][sc] &&\
    \ alive[tr][tc] && uf.same(sr * W + sc, tr * W + tc);\n    };\n    auto ans =\
    \ parallel_binary_search(H * W, Q, act, query, reset);\n    for (int i : ans)\
    \ cout << A[ord[i].first][ord[i].second] << '\\n';\n}\n"
  dependsOn:
  - src/data_structure/union_find/union_find.hpp
  - src/misc/parallel_binary_search.hpp
  isVerificationFile: true
  path: test/misc/parallel_binary_search.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/misc/parallel_binary_search.test.cpp
layout: document
redirect_from:
- /verify/test/misc/parallel_binary_search.test.cpp
- /verify/test/misc/parallel_binary_search.test.cpp.html
title: test/misc/parallel_binary_search.test.cpp
---
