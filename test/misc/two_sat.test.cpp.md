---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/scc.hpp
    title: src/graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/two_sat.hpp
    title: src/misc/two_sat.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/misc/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return numeric_limits<T>::max()\
    \ / 2; }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return\
    \ a > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/graph/scc.hpp\"\
    \n\nstruct scc_graph {\n    scc_graph(int _n = 0) : n(_n), g(_n), g_rev(_n) {}\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        g[u].push_back(v);\n        g_rev[v].push_back(u);\n\
    \    }\n    vector<vector<int>> scc() {\n        id = vector<int>(n, -1);\n  \
    \      vis = vector<bool>(n);\n        ord.reserve(n);\n        for (int i = 0;\
    \ i < n; i++) dfs(i);\n        reverse(ord.begin(), ord.end());\n        int k\
    \ = 0;\n        for (int u : ord) {\n            if (id[u] == -1) {\n        \
    \        sfd(u, k++);\n            }\n        }\n        vector<vector<int>> res(k);\n\
    \        for (int i = 0; i < n; i++) {\n            res[id[i]].push_back(i);\n\
    \        }\n        return res;\n    }\nprivate:\n    int n;\n    vector<vector<int>>\
    \ g, g_rev;\n    vector<int> id, ord;\n    vector<bool> vis;\n    void dfs(int\
    \ u) {\n        if (vis[u]) return;\n        vis[u] = true;\n        for (int\
    \ v : g[u]) dfs(v);\n        ord.push_back(u);\n    }\n    void sfd(int u, int\
    \ k) {\n        if (id[u] != -1) return;\n        id[u] = k;\n        for (int\
    \ v : g_rev[u]) sfd(v, k);\n    }\n};\n#line 4 \"src/misc/two_sat.hpp\"\n\nstruct\
    \ two_sat {\n    two_sat() : two_sat(0) {}\n    two_sat(int _n) : n(_n), scc(2\
    \ * _n) {}\n    void add_clause(int i, bool f, int j, bool g) {\n        scc.add_edge((!f)\
    \ * n + i, g * n + j);\n        scc.add_edge((!g) * n + j, f * n + i);\n    }\n\
    \    vector<bool> solve() {\n        auto comp = scc.scc();\n        vector<int>\
    \ id(2 * n);\n        for (int i = 0; i < ssize(comp); i++) {\n            for\
    \ (int j : comp[i]) id[j] = i;\n        }\n        vector<bool> res(n);\n    \
    \    for (int i = 0; i < n; i++) {\n            if (id[i] == id[i + n]) return\
    \ {};\n            res[i] = id[i] < id[i + n];\n        }\n        return res;\n\
    \    }\nprivate:\n    int n;\n    scc_graph scc;\n};\n#line 5 \"test/misc/two_sat.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  string p, cnf;\n    cin >> p >> cnf;\n    int N, M;\n    cin >> N >> M;\n \
    \   two_sat ts(N);\n    for (int s, t, zero; M--; ) {\n        cin >> s >> t >>\
    \ zero;\n        ts.add_clause(abs(s) - 1, s > 0, abs(t) - 1, t > 0);\n    }\n\
    \    auto ans = ts.solve();\n    if (ans.empty()) {\n        cout << \"s UNSATISFIABLE\"\
    \ << '\\n';\n        return 0;\n    }\n    cout << \"s SATISFIABLE\" << '\\n';\n\
    \    cout << \"v\";\n    for (int i = 0; i < N; i++) {\n        cout << ' ' <<\
    \ (ans[i] ? 1 : -1) * (i + 1);\n    }\n    cout << \" 0\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../../src/template.hpp\"\n#include \"../../src/misc/two_sat.hpp\"\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    string p, cnf;\n\
    \    cin >> p >> cnf;\n    int N, M;\n    cin >> N >> M;\n    two_sat ts(N);\n\
    \    for (int s, t, zero; M--; ) {\n        cin >> s >> t >> zero;\n        ts.add_clause(abs(s)\
    \ - 1, s > 0, abs(t) - 1, t > 0);\n    }\n    auto ans = ts.solve();\n    if (ans.empty())\
    \ {\n        cout << \"s UNSATISFIABLE\" << '\\n';\n        return 0;\n    }\n\
    \    cout << \"s SATISFIABLE\" << '\\n';\n    cout << \"v\";\n    for (int i =\
    \ 0; i < N; i++) {\n        cout << ' ' << (ans[i] ? 1 : -1) * (i + 1);\n    }\n\
    \    cout << \" 0\\n\";\n}"
  dependsOn:
  - src/template.hpp
  - src/misc/two_sat.hpp
  - src/graph/scc.hpp
  isVerificationFile: true
  path: test/misc/two_sat.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/misc/two_sat.test.cpp
- /verify/test/misc/two_sat.test.cpp.html
title: test/misc/two_sat.test.cpp
---
