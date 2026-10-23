---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/random/utility.hpp
    title: Random Utility
  - icon: ':heavy_check_mark:'
    path: src/tree/prufer_code.hpp
    title: src/tree/prufer_code.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/tree/prufer_code.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 2 \"src/tree/prufer_code.hpp\"\n#include <queue>\n#include <vector>\n\
    using namespace std;\n\nvector<int> prufer_code_compress(const vector<vector<int>>\
    \ &t) {\n    int n = t.size();\n    if (n <= 2) return {};\n    vector<int> deg(n);\n\
    \    priority_queue<int, vector<int>, greater<int>> q;\n    for (int i = 0; i\
    \ < n; i++) {\n        deg[i] = t[i].size();\n        if (deg[i] == 1) {\n   \
    \         q.push(i);\n        }\n    }\n    vector<int> p;\n    p.reserve(n -\
    \ 2);\n    while ((int)p.size() < n - 2) {\n        int u = q.top();\n       \
    \ q.pop();\n        for (int v : t[u]) {\n            if (deg[v] > 0) {\n    \
    \            p.push_back(v);\n                deg[v]--;\n                if (deg[v]\
    \ == 1) q.push(v);\n                break;\n            }\n        }\n       \
    \ deg[u]--;\n    }\n    return p;\n}\n\nvector<vector<int>> prufer_code_expansion(const\
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
    \     }\n    }\n    return t;\n}\n#line 2 \"src/random/utility.hpp\"\n#include\
    \ <cassert>\n#include <concepts>\n#include <random>\nusing namespace std;\n\n\
    namespace rng {\n\ninline random_device seed;\ninline mt19937 eng(seed());\n\n\
    template<typename T>\nvoid set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral\
    \ T>\ninline T randint(T lo, T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T>\
    \ dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T,\
    \ T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n\
    \    T l = randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n   \
    \ return make_pair(l, r);\n}\n\n} // namespace rng\n#line 5 \"test/tree/prufer_code.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    {\n        int A, B;\n        cin >> A >> B;\n     \
    \   cout << A + B << '\\n';\n    }\n    for (int t = 0; t < 20; t++) {\n     \
    \   // code -> tree -> code\n        int N = rng::randint(3, (int)2e5);\n    \
    \    vector<int> A(N - 2);\n        for (auto &e : A) e = rng::randint(0, N -\
    \ 1);\n        assert(A == prufer_code_compress(prufer_code_expansion(A)));\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../src/tree/prufer_code.hpp\"\n#include \"../../src/random/utility.hpp\"\n\n\
    #include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    {\n        int A, B;\n        cin >> A >> B;\n        cout << A + B << '\\\
    n';\n    }\n    for (int t = 0; t < 20; t++) {\n        // code -> tree -> code\n\
    \        int N = rng::randint(3, (int)2e5);\n        vector<int> A(N - 2);\n \
    \       for (auto &e : A) e = rng::randint(0, N - 1);\n        assert(A == prufer_code_compress(prufer_code_expansion(A)));\n\
    \    }\n}"
  dependsOn:
  - src/tree/prufer_code.hpp
  - src/random/utility.hpp
  isVerificationFile: true
  path: test/tree/prufer_code.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/prufer_code.test.cpp
layout: document
redirect_from:
- /verify/test/tree/prufer_code.test.cpp
- /verify/test/tree/prufer_code.test.cpp.html
title: test/tree/prufer_code.test.cpp
---
