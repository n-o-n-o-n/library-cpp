---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/string/aho_corasick.test.cpp
    title: test/string/aho_corasick.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/string/aho_corasick.hpp\"\n\ntemplate<int size, char base>\n\
    struct aho_corasick {\n    aho_corasick() : par(1, 0), chr(1, -1), last(0), fail(1,\
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
    \        return x;\n    }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<int size, char base>\n\
    struct aho_corasick {\n    aho_corasick() : par(1, 0), chr(1, -1), last(0), fail(1,\
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
    \        return x;\n    }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/string/aho_corasick.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/string/aho_corasick.test.cpp
documentation_of: src/string/aho_corasick.hpp
layout: document
redirect_from:
- /library/src/string/aho_corasick.hpp
- /library/src/string/aho_corasick.hpp.html
title: src/string/aho_corasick.hpp
---
