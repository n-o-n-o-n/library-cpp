---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/functional_graph.hpp
    title: Functional Graph
  - icon: ':question:'
    path: src/misc/compress.hpp
    title: Compress
  - icon: ':question:'
    path: src/misc/merge_and_unique.hpp
    title: Merge And Unique
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2242
    links:
    - https://yukicoder.me/problems/no/2242
  bundledCode: "#line 1 \"test/graph/functional_graph.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/2242\"\n\n#line 2 \"src/template.hpp\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\ntemplate<typename\
    \ T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2; }\n\ntemplate<typename\
    \ T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a > b ? a = b, true : false;\
    \ }\ntemplate<typename T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a <\
    \ b ? a = b, true : false; }\n#line 3 \"src/misc/merge_and_unique.hpp\"\n\ntemplate<typename\
    \ T, typename... Ts>\nvector<T> merge_and_unique(const vector<T> &a, const Ts\
    \ &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(), z.begin(), z.end()),\
    \ ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 4 \"src/misc/compress.hpp\"\
    \n\ntemplate<typename T>\nvector<int> compress(const vector<T> &v) {\n    auto\
    \ zip = merge_and_unique(v);\n    vector<int> res;\n    res.reserve(v.size());\n\
    \    for (const T &e : v) {\n        res.push_back(lower_bound(zip.begin(), zip.end(),\
    \ e) - zip.begin());\n    }\n    return res;\n}\n\ntemplate<typename T, typename...\
    \ Ts>\nauto compress(const vector<T> &a, const Ts &...z) {\n    auto zip = merge_and_unique(a,\
    \ z...);\n    auto f = [&] (const vector<T> &v) -> vector<int> {\n        vector<int>\
    \ res;\n        res.reserve(v.size());\n        for (const T &e : v) {\n     \
    \       res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());\n\
    \        }\n        return res;\n    };\n    return make_tuple(f(a), f(z)...);\n\
    }\n\ntemplate<typename T, typename... Ts>\nint compress_inplace(vector<T> &a,\
    \ Ts &...z) {\n    auto zip = merge_and_unique(a, z...);\n    auto f = [&] (vector<T>\
    \ &v) -> void {\n        for (T &e : v) {\n            e = lower_bound(zip.begin(),\
    \ zip.end(), e) - zip.begin();\n        }\n    };\n    (f(a), ..., f(z));\n  \
    \  return (int)zip.size();\n}\n#line 3 \"src/graph/functional_graph.hpp\"\n\n\
    struct functional_graph {\n    functional_graph(int _n) : functional_graph(vector<int>(_n,\
    \ -1)) {}\n    functional_graph(const vector<int> &a) : n(a.size()), f(1, a) {}\n\
    \    void add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n       \
    \ assert(0 <= v && v < n);\n        assert(f[0][u] == -1);\n        f[0][u] =\
    \ v;\n    }\n    int steps(int u, long long k) {\n        assert(0 <= u && u <\
    \ n);\n        doubling(k);\n        for (int i = 0; (1LL << i) <= k; i++) {\n\
    \            if (k >> i & 1) u = f[i][u];\n        }\n        return u;\n    }\n\
    \    vector<int> table(long long k) {\n        doubling(k);\n        vector<int>\
    \ g(n);\n        iota(g.begin(), g.end(), 0);\n        for (int i = 0; (1LL <<\
    \ i) <= k; i++) {\n            if (k >> i & 1) {\n                for (int j =\
    \ 0; j < n; j++) {\n                    g[j] = f[i][g[j]];\n                }\n\
    \            }\n        }\n        return g;\n    }\n    template<typename C>\n\
    \    pair<int, int> binary_search(int u, const C &check) {\n        assert(0 <=\
    \ u && u < n);\n        assert(check(u));\n        doubling(n);\n        int log\
    \ = 0;\n        while (n >> log) log++;\n        int r = 0;\n        for (log--;\
    \ log >= 0; log--) {\n            int len = 1 << log;\n            if (r > n -\
    \ len) continue;\n            int v = f[log][u];\n            if (check(v)) u\
    \ = v, r += len;\n        }\n        if (r == n) return {-1, -1};\n        return\
    \ make_pair(r, u);\n    }\nprivate:\n    int n;\n    vector<vector<int>> f;\n\
    \    void doubling(long long k) {\n        while (1LL << int(f.size()) <= k) {\n\
    \            vector<int> tf(n);\n            const vector<int> &g = f.back();\n\
    \            for (int i = 0; i < n; i++) tf[i] = g[g[i]];\n            f.push_back(tf);\n\
    \        }\n    }\n};\n#line 6 \"test/graph/functional_graph.test.cpp\"\n\nint\
    \ main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n\
    \    cin >> N;\n    vector<int> H(N), T(N);\n    for (auto &e : H) cin >> e;\n\
    \    for (auto &e : T) cin >> e;\n    int M = compress_inplace(H, T);\n    vector<int>\
    \ to(M);\n    iota(to.begin(), to.end(), 0);\n    for (int i = 0; i < N; i++)\
    \ to[H[i]] = max(to[H[i]], T[i]);\n    for (int i = 1; i < M; i++) to[i] = max(to[i],\
    \ to[i - 1]);\n    functional_graph G(M);\n    for (int i = 0; i < M; i++) G.add_edge(i,\
    \ to[i]);\n    int Q;\n    cin >> Q;\n    for (int a, b; Q--; ) {\n        cin\
    \ >> a >> b;\n        a--, b--;\n        if (H[b] <= T[a]) {\n            cout\
    \ << 1 << '\\n';\n        } else {\n            int r = G.binary_search(T[a],\
    \ [&] (int x) { return x < H[b]; }).first;\n            cout << (r == -1 ? -1\
    \ : r + 2) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2242\"\n\n#include \"\
    ../../src/template.hpp\"\n#include \"../../src/misc/compress.hpp\"\n#include \"\
    ../../src/graph/functional_graph.hpp\"\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N;\n    cin >> N;\n    vector<int> H(N), T(N);\n\
    \    for (auto &e : H) cin >> e;\n    for (auto &e : T) cin >> e;\n    int M =\
    \ compress_inplace(H, T);\n    vector<int> to(M);\n    iota(to.begin(), to.end(),\
    \ 0);\n    for (int i = 0; i < N; i++) to[H[i]] = max(to[H[i]], T[i]);\n    for\
    \ (int i = 1; i < M; i++) to[i] = max(to[i], to[i - 1]);\n    functional_graph\
    \ G(M);\n    for (int i = 0; i < M; i++) G.add_edge(i, to[i]);\n    int Q;\n \
    \   cin >> Q;\n    for (int a, b; Q--; ) {\n        cin >> a >> b;\n        a--,\
    \ b--;\n        if (H[b] <= T[a]) {\n            cout << 1 << '\\n';\n       \
    \ } else {\n            int r = G.binary_search(T[a], [&] (int x) { return x <\
    \ H[b]; }).first;\n            cout << (r == -1 ? -1 : r + 2) << '\\n';\n    \
    \    }\n    }\n}\n"
  dependsOn:
  - src/template.hpp
  - src/misc/compress.hpp
  - src/misc/merge_and_unique.hpp
  - src/graph/functional_graph.hpp
  isVerificationFile: true
  path: test/graph/functional_graph.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/functional_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/functional_graph.test.cpp
- /verify/test/graph/functional_graph.test.cpp.html
title: test/graph/functional_graph.test.cpp
---
