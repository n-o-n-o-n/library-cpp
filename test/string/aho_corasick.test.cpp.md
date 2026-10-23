---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/aho_corasick.hpp
    title: src/string/aho_corasick.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aho_corasick
    links:
    - https://judge.yosupo.jp/problem/aho_corasick
  bundledCode: "#line 1 \"test/string/aho_corasick.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aho_corasick\"\n\n#line 2 \"src/string/aho_corasick.hpp\"\
    \n#include <array>\n#include <cassert>\n#include <queue>\n#include <string>\n\
    #include <vector>\nusing namespace std;\n\ntemplate<int size, char base>\nstruct\
    \ aho_corasick {\n    aho_corasick() : par(1, 0), chr(1, -1), last(0), fail(1,\
    \ 0), cnt(1, 0), child(1, e()), built(false) {}\n    void insert(const string\
    \ &s) {\n        int n = s.size(), pos = 0;\n        for (int i = 0; i < n; i++)\
    \ {\n            int c = s[i] - base;\n            if (child[pos][c] == -1) {\n\
    \                child[pos][c] = par.size();\n                par.push_back(pos);\n\
    \                chr.push_back(c);\n                fail.push_back(0);\n     \
    \           cnt.push_back(0);\n                child.push_back(e());\n       \
    \     }\n            pos = child[pos][c];\n        }\n        cnt[pos]++;\n  \
    \      last.push_back(pos);\n    }\n    void build() {\n        queue<int> q;\n\
    \        for (int i = 0; i < size; i++) {\n            int &nxt = child[0][i];\n\
    \            if (nxt != -1) {\n                fail[nxt] = 0;\n              \
    \  q.push(nxt);\n            } else {\n                nxt = 0;\n            }\n\
    \        }\n        while (q.size()) {\n            int u = q.front();\n     \
    \       q.pop();\n            cnt[u] += cnt[fail[u]];\n            for (int i\
    \ = 0; i < size; i++) {\n                int &nxt = child[u][i];\n           \
    \     int p = child[fail[u]][i];\n                if (nxt != -1) {\n         \
    \           fail[nxt] = p;\n                    q.push(nxt);\n               \
    \ } else {\n                    nxt = p;\n                }\n            }\n \
    \       }\n        built = true;\n    }\n    template<typename T = int>\n    T\
    \ match(const string &s) const {\n        assert(built);\n        int n = s.size(),\
    \ pos = 0;\n        T res = 0;\n        for (int i = 0; i < n; i++) {\n      \
    \      int c = s[i] - base;\n            pos = child[pos][c];\n            res\
    \ += cnt[pos];\n        }\n        return res;\n    }\n// private:\n    vector<int>\
    \ par, chr, last, fail, cnt;\n    vector<array<int, size>> child;\n    bool built;\n\
    \    constexpr array<int, size> e() {\n        array<int, size> x;\n        x.fill(-1);\n\
    \        return x;\n    }\n};\n#line 4 \"test/string/aho_corasick.test.cpp\"\n\
    \n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N;\n    cin >> N;\n    aho_corasick<26, 'a'> ac;\n    for (int i = 0;\
    \ i < N; i++) {\n        string S;\n        cin >> S;\n        ac.insert(S);\n\
    \    }\n    ac.build();\n    int n = ac.par.size();\n    cout << n << '\\n';\n\
    \    for (int i = 1; i < n; i++) cout << ac.par[i] << ' ' << ac.fail[i] << '\\\
    n';\n    for (int i = 0; i < N; i++) cout << ac.last[i] << \" \\n\"[i + 1 == N];\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aho_corasick\"\n\n#include\
    \ \"../../src/string/aho_corasick.hpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin\
    \ >> N;\n    aho_corasick<26, 'a'> ac;\n    for (int i = 0; i < N; i++) {\n  \
    \      string S;\n        cin >> S;\n        ac.insert(S);\n    }\n    ac.build();\n\
    \    int n = ac.par.size();\n    cout << n << '\\n';\n    for (int i = 1; i <\
    \ n; i++) cout << ac.par[i] << ' ' << ac.fail[i] << '\\n';\n    for (int i = 0;\
    \ i < N; i++) cout << ac.last[i] << \" \\n\"[i + 1 == N];\n}\n"
  dependsOn:
  - src/string/aho_corasick.hpp
  isVerificationFile: true
  path: test/string/aho_corasick.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 22:15:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/aho_corasick.test.cpp
layout: document
redirect_from:
- /verify/test/string/aho_corasick.test.cpp
- /verify/test/string/aho_corasick.test.cpp.html
title: test/string/aho_corasick.test.cpp
---
