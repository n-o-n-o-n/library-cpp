---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/data_structure/union_find/union_find.hpp
    title: Union Find
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/data_structure/union_find/union_find.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    template<typename T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2;\
    \ }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a\
    \ > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/data_structure/union_find/union_find.hpp\"\
    \n\nstruct union_find {\n    union_find(int n) : p(n, -1), cyc(n) {\n        iota(cyc.begin(),\
    \ cyc.end(), 0);\n    }\n    int leader(int u) {\n        assert(0 <= u && u <\
    \ ssize(p));\n        return p[u] < 0 ? u : p[u] = leader(p[u]);\n    }\n    bool\
    \ same(int u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0\
    \ <= v && v < ssize(p));\n        return leader(u) == leader(v);\n    }\n    int\
    \ merge(int u, int v) {\n        assert(0 <= u && u < ssize(p));\n        assert(0\
    \ <= v && v < ssize(p));\n        u = leader(u);\n        v = leader(v);\n   \
    \     if (u == v) return u;\n        if (p[u] > p[v]) swap(u, v);\n        p[u]\
    \ += p[v];\n        p[v] = u;\n        swap(cyc[u], cyc[v]);\n        return u;\n\
    \    }\n    int size(int u) {\n        assert(0 <= u && u < ssize(p));\n     \
    \   return -p[leader(u)];\n    }\n    vector<int> group(int u) {\n        assert(0\
    \ <= u && u < ssize(p));\n        vector<int> res = {u};\n        int v = cyc[u];\n\
    \        while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() {\n \
    \       int n = p.size();\n        vector<vector<int>> tmp(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            tmp[leader(i)].push_back(i);\n        }\n\
    \        vector<vector<int>> res;\n        for (auto v : tmp) {\n            if\
    \ (v.size()) res.push_back(v);\n        }\n        return res;\n    }\nprivate:\n\
    \    vector<int> p, cyc;\n};\n#line 5 \"test/data_structure/union_find/union_find.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N, Q;\n    cin >> N >> Q;\n    union_find uf(N);\n    for (int t, u, v;\
    \ Q--; ) {\n        cin >> t >> u >> v;\n        if (t == 0) {\n            uf.merge(u,\
    \ v);\n        } else {\n            cout << uf.same(u, v) << '\\n';\n       \
    \ }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../src/template.hpp\"\n#include \"../../../src/data_structure/union_find/union_find.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N, Q;\n    cin >> N >> Q;\n    union_find uf(N);\n    for (int t, u, v;\
    \ Q--; ) {\n        cin >> t >> u >> v;\n        if (t == 0) {\n            uf.merge(u,\
    \ v);\n        } else {\n            cout << uf.same(u, v) << '\\n';\n       \
    \ }\n    }\n}"
  dependsOn:
  - src/template.hpp
  - src/data_structure/union_find/union_find.hpp
  isVerificationFile: true
  path: test/data_structure/union_find/union_find.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/union_find/union_find.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/union_find/union_find.test.cpp
- /verify/test/data_structure/union_find/union_find.test.cpp.html
title: test/data_structure/union_find/union_find.test.cpp
---
