---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest_path.hpp
    title: Shortest Path
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/graph/shortest_path.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/shortest_path\"\n\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    template<typename T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2;\
    \ }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a\
    \ > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/graph/shortest_path.hpp\"\
    \n\ntemplate<typename T = int>\nstruct shortest_path {\n    shortest_path(int\
    \ _n) : n(_n), r(-1), g(_n), wt(false) {}\n    shortest_path(const vector<vector<int>>\
    \ &_g) : n(_g.size()), r(-1), g(n), wt(false) {\n        for (int u = 0; u < n;\
    \ u++) {\n            g[u].reserve(_g[u].size());\n            for (int v : _g[u])\
    \ {\n                assert(0 <= v && v < n);\n                g[u].emplace_back(v,\
    \ 1);\n            }\n        }\n    }\n    template<typename T2>\n    shortest_path(const\
    \ vector<vector<pair<int, T2>>> &_g) : n(_g.size()), r(-1), g(n), wt(true) {\n\
    \        for (int u = 0; u < n; u++) {\n            g[u].reserve(_g[u].size());\n\
    \            for (auto [v, w] : _g[u]) {\n                assert(0 <= v && v <\
    \ n);\n                assert(w >= 0);\n                g[u].emplace_back(v, w);\n\
    \            }\n        }\n    }\n    void add_edge(int u, int v, T w = 1) {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(w\
    \ >= 0);\n        g[u].emplace_back(v, w);\n        wt = wt || (w != 1);\n   \
    \     r = -1;\n    }\n    vector<T> table(int s) {\n        assert(0 <= s && s\
    \ < n);\n        build(s);\n        return d;\n    }\n    vector<int> path(int\
    \ s, int t) {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t <\
    \ n);\n        build(s);\n        if (d[t] == -1) return {};\n        vector<int>\
    \ res = {t};\n        while (p[t] != -1) res.push_back(t = p[t]);\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n    T dist(int s, int t) {\n      \
    \  assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n        build(s);\n\
    \        return d[t];\n    }\nprivate:\n    int n, r;\n    vector<vector<pair<int,\
    \ T>>> g;\n    bool wt;\n    vector<T> d;\n    vector<int> p;\n    template<class\
    \ P>\n    void upd(int u, T cur, P push) {\n        for (auto [v, w] : g[u]) {\n\
    \            if (chmin(d[v], cur + w)) {\n                p[v] = u;\n        \
    \        push(v);\n            }\n        }\n    }\n    void build(int s) {\n\
    \        if (r == s) return;\n        r = s;\n        d = vector<T>(n, inf<T>());\n\
    \        p = vector<int>(n, -1);\n        d[s] = 0;\n        if (!wt) {\n    \
    \        queue<int> q;\n            q.push(s);\n            while (!q.empty())\
    \ {\n                int u = q.front();\n                q.pop();\n          \
    \      upd(u, d[u], [&] (int v) { q.push(v); });\n            }\n        } else\
    \ {\n            priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>>\
    \ q;\n            q.emplace(0, s);\n            while (!q.empty()) {\n       \
    \         auto [cur, u] = q.top();\n                q.pop();\n               \
    \ if (cur > d[u]) continue;\n                upd(u, cur, [&] (int v) { q.emplace(d[v],\
    \ v); });\n            }\n        }\n        for (auto &e : d) {\n           \
    \ if (e == inf<T>()) e = -1;\n        }\n    }\n};\n#line 5 \"test/graph/shortest_path.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N, M, s, t;\n    cin >> N >> M >> s >> t;\n    shortest_path<long long>\
    \ G(N);\n    for (int u, v, w; M--; ) {\n        cin >> u >> v >> w;\n       \
    \ G.add_edge(u, v, w);\n    }\n    auto P = G.path(s, t);\n    if (P.empty())\
    \ {\n        cout << -1 << '\\n';\n        return 0;\n    }\n    cout << G.dist(s,\
    \ t) << ' ' << ssize(P) - 1 << '\\n';\n    for (int i = 1; i < ssize(P); i++)\
    \ cout << P[i - 1] << ' ' << P[i] << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../../src/template.hpp\"\n#include \"../../src/graph/shortest_path.hpp\"\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, M, s, t;\n    cin >> N >> M >> s >> t;\n    shortest_path<long long> G(N);\n\
    \    for (int u, v, w; M--; ) {\n        cin >> u >> v >> w;\n        G.add_edge(u,\
    \ v, w);\n    }\n    auto P = G.path(s, t);\n    if (P.empty()) {\n        cout\
    \ << -1 << '\\n';\n        return 0;\n    }\n    cout << G.dist(s, t) << ' ' <<\
    \ ssize(P) - 1 << '\\n';\n    for (int i = 1; i < ssize(P); i++) cout << P[i -\
    \ 1] << ' ' << P[i] << '\\n';\n}"
  dependsOn:
  - src/template.hpp
  - src/graph/shortest_path.hpp
  isVerificationFile: true
  path: test/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2026-11-03 09:50:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path.test.cpp
- /verify/test/graph/shortest_path.test.cpp.html
title: test/graph/shortest_path.test.cpp
---
