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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1406?year=2019
    links:
    - https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1406?year=2019
  bundledCode: "#line 1 \"test/graph/shortest_path_dial.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1406?year=2019\"\
    \n#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return numeric_limits<T>::max()\
    \ / 2; }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return\
    \ a > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/graph/shortest_path.hpp\"\
    \n\ntemplate<typename T = int>\nstruct shortest_path {\n    shortest_path(int\
    \ _n) : n(_n), r(-1), g(_n), wt(false), dial(true) {}\n    shortest_path(const\
    \ vector<vector<int>> &_g) : n(_g.size()), r(-1), g(n), wt(false), dial(true)\
    \ {\n        for (int u = 0; u < n; u++) {\n            g[u].reserve(_g[u].size());\n\
    \            for (int v : _g[u]) {\n                assert(0 <= v && v < n);\n\
    \                g[u].emplace_back(v, 1);\n            }\n        }\n    }\n \
    \   template<typename T2>\n    shortest_path(const vector<vector<pair<int, T2>>>\
    \ &_g) : n(_g.size()), r(-1), g(n), wt(true), dial(true) {\n        for (int u\
    \ = 0; u < n; u++) {\n            g[u].reserve(_g[u].size());\n            for\
    \ (auto [v, w] : _g[u]) {\n                assert(0 <= v && v < n);\n        \
    \        assert(w >= 0);\n                g[u].emplace_back(v, w);\n         \
    \       dial = dial && (w <= k);\n            }\n        }\n    }\n    void add_edge(int\
    \ u, int v, T w = 1) {\n        assert(0 <= u && u < n);\n        assert(0 <=\
    \ v && v < n);\n        assert(w >= 0);\n        g[u].emplace_back(v, w);\n  \
    \      wt = wt || (w != 1);\n        dial = dial && (w <= k);\n        r = -1;\n\
    \    }\n    vector<T> table(int s) {\n        assert(0 <= s && s < n);\n     \
    \   build(s);\n        return d;\n    }\n    vector<int> path(int s, int t) {\n\
    \        assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n        build(s);\n\
    \        if (d[t] == -1) return {};\n        vector<int> res = {t};\n        while\
    \ (p[t] != -1) res.push_back(t = p[t]);\n        reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n    T dist(int s, int t) {\n        assert(0 <= s\
    \ && s < n);\n        assert(0 <= t && t < n);\n        build(s);\n        return\
    \ d[t];\n    }\nprivate:\n    static constexpr int k = 16;\n    int n, r;\n  \
    \  vector<vector<pair<int, T>>> g;\n    bool wt, dial;\n    vector<T> d;\n   \
    \ vector<int> p;\n    template<class P>\n    void upd(int u, T cur, P push) {\n\
    \        for (auto [v, w] : g[u]) {\n            if (chmin(d[v], cur + w)) {\n\
    \                p[v] = u;\n                push(v);\n            }\n        }\n\
    \    }\n    void build(int s) {\n        if (r == s) return;\n        r = s;\n\
    \        d = vector<T>(n, inf<T>());\n        p = vector<int>(n, -1);\n      \
    \  d[s] = 0;\n        if (!wt) {\n            queue<int> q;\n            q.push(s);\n\
    \            while (!q.empty()) {\n                int u = q.front();\n      \
    \          q.pop();\n                upd(u, d[u], [&] (int v) { q.push(v); });\n\
    \            }\n        } else if (dial) {\n            array<queue<pair<T, int>>,\
    \ k + 1> qs;\n            qs[0].emplace(0, s);\n            int sz = 1;\n    \
    \        T w = 0;\n            while (sz) {\n                auto &q = qs[w %\
    \ (k + 1)];\n                if (q.empty()) {\n                    w++;\n    \
    \                continue;\n                }\n                auto [du, u] =\
    \ q.front();\n                q.pop();\n                sz--;\n              \
    \  if (du > d[u]) continue;\n                upd(u, du, [&] (int v) {\n      \
    \              qs[d[v] % (k + 1)].emplace(d[v], v);\n                    sz++;\n\
    \                });\n            }\n        } else {\n            priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<>> q;\n            q.emplace(0, s);\n  \
    \          while (!q.empty()) {\n                auto [du, u] = q.top();\n   \
    \             q.pop();\n                if (du > d[u]) continue;\n           \
    \     upd(u, du, [&] (int v) { q.emplace(d[v], v); });\n            }\n      \
    \  }\n        for (auto &e : d) {\n            if (e == inf<T>()) e = -1;\n  \
    \      }\n    }\n};\n#line 4 \"test/graph/shortest_path_dial.test.cpp\"\n\nstring\
    \ suffix(const string s, int k) {\n    assert(0 <= k && k <= ssize(s));\n    return\
    \ s.substr(ssize(s) - k, k);\n}\n\nbool pref(const string &s, const string &t)\
    \ {\n    if (s.size() > t.size()) return false;\n    for (int i = 0; i < ssize(s);\
    \ i++) {\n        if (s[i] != t[i]) return false;\n    }\n    return true;\n}\n\
    int main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    vector<string> S(N), suffs = {\"\"};\n    for (int i\
    \ = 0; i < N; i++) {\n        cin >> S[i];\n        for (int j = 1; j <= ssize(S[i]);\
    \ j++) suffs.push_back(suffix(S[i], j));\n    }\n    sort(suffs.begin(), suffs.end());\n\
    \    suffs.erase(unique(suffs.begin(), suffs.end()), suffs.end());\n    int K\
    \ = suffs.size();\n    unordered_map<string, int> mp;\n    for (int i = 0; i <\
    \ K; i++) mp[suffs[i]] = i;\n    shortest_path<int> SP(K + 1);\n    for (int i\
    \ = 0; i < K; i++) {\n        for (int j = 0; j < N; j++) {\n            if (pref(suffs[i],\
    \ S[j])) {\n                int k = ssize(S[j]) - ssize(suffs[i]);\n         \
    \       SP.add_edge(i, mp[suffix(S[j], k)], k);\n            } else if (pref(S[j],\
    \ suffs[i])) {\n                int k = ssize(suffs[i]) - ssize(S[j]);\n     \
    \           SP.add_edge(i, mp[suffix(suffs[i], k)], 0);\n            }\n     \
    \   }\n    }\n    for (int i = 0; i < N; i++) {\n        for (int j = 0; j < N;\
    \ j++) {\n            if (i != j && pref(S[i], S[j])) {\n                int k\
    \ = ssize(S[j]) - ssize(S[i]);\n                SP.add_edge(K, mp[suffix(S[j],\
    \ k)], ssize(S[j]));\n            }\n        }\n    }\n    int ans = SP.dist(K,\
    \ 0);\n    cout << (ans == -1 ? 0 : ans) << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1406?year=2019\"\
    \n#include \"../../src/template.hpp\"\n#include \"../../src/graph/shortest_path.hpp\"\
    \n\nstring suffix(const string s, int k) {\n    assert(0 <= k && k <= ssize(s));\n\
    \    return s.substr(ssize(s) - k, k);\n}\n\nbool pref(const string &s, const\
    \ string &t) {\n    if (s.size() > t.size()) return false;\n    for (int i = 0;\
    \ i < ssize(s); i++) {\n        if (s[i] != t[i]) return false;\n    }\n    return\
    \ true;\n}\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N;\n    cin >> N;\n    vector<string> S(N), suffs = {\"\"};\n    for\
    \ (int i = 0; i < N; i++) {\n        cin >> S[i];\n        for (int j = 1; j <=\
    \ ssize(S[i]); j++) suffs.push_back(suffix(S[i], j));\n    }\n    sort(suffs.begin(),\
    \ suffs.end());\n    suffs.erase(unique(suffs.begin(), suffs.end()), suffs.end());\n\
    \    int K = suffs.size();\n    unordered_map<string, int> mp;\n    for (int i\
    \ = 0; i < K; i++) mp[suffs[i]] = i;\n    shortest_path<int> SP(K + 1);\n    for\
    \ (int i = 0; i < K; i++) {\n        for (int j = 0; j < N; j++) {\n         \
    \   if (pref(suffs[i], S[j])) {\n                int k = ssize(S[j]) - ssize(suffs[i]);\n\
    \                SP.add_edge(i, mp[suffix(S[j], k)], k);\n            } else if\
    \ (pref(S[j], suffs[i])) {\n                int k = ssize(suffs[i]) - ssize(S[j]);\n\
    \                SP.add_edge(i, mp[suffix(suffs[i], k)], 0);\n            }\n\
    \        }\n    }\n    for (int i = 0; i < N; i++) {\n        for (int j = 0;\
    \ j < N; j++) {\n            if (i != j && pref(S[i], S[j])) {\n             \
    \   int k = ssize(S[j]) - ssize(S[i]);\n                SP.add_edge(K, mp[suffix(S[j],\
    \ k)], ssize(S[j]));\n            }\n        }\n    }\n    int ans = SP.dist(K,\
    \ 0);\n    cout << (ans == -1 ? 0 : ans) << endl;\n}"
  dependsOn:
  - src/template.hpp
  - src/graph/shortest_path.hpp
  isVerificationFile: true
  path: test/graph/shortest_path_dial.test.cpp
  requiredBy: []
  timestamp: '2026-11-11 23:04:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/shortest_path_dial.test.cpp
layout: document
redirect_from:
- /verify/test/graph/shortest_path_dial.test.cpp
- /verify/test/graph/shortest_path_dial.test.cpp.html
title: test/graph/shortest_path_dial.test.cpp
---
