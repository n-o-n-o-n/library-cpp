---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/manacher.hpp
    title: src/string/manacher.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/string/manacher.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#line 2 \"src/string/manacher.hpp\"\n#include <string>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename S> \nvector<int> manacher(vector<S>\
    \ v, const S wildcard) {\n    {\n        vector<S> tmp = v;\n        v.clear();\n\
    \        for (const S &s : tmp) {\n            v.push_back(s);\n            v.push_back(wildcard);\n\
    \        }\n        v.pop_back();\n    }\n    const int n = v.size();\n    int\
    \ i = 0, j = 0;\n    vector<int> res(n);\n    while (i < n) {\n        while (j\
    \ <= i && i + j < n && v[i - j] == v[i + j]) j++;\n        res[i] = j;\n     \
    \   int k = 1;\n        while (k <= i && i + k < n && k + res[i - k] < j) {\n\
    \            res[i + k] = res[i - k];\n            k++;\n        }\n        i\
    \ += k;\n        j -= k;\n    }\n    for (int i = 0; i < n; i++) {\n        if\
    \ (1 ^ ((res[i] ^ i) & 1)) res[i]--;\n    }\n    return res;\n}\n\ninline vector<int>\
    \ manacher(const string &s) {\n    return manacher(vector<char>(s.begin(), s.end()),\
    \ '$');\n}\n#line 4 \"test/string/manacher.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    string\
    \ S;\n    cin >> S;\n    auto ans = manacher(S);\n    for (int i = 0; i < ssize(ans);\
    \ i++) {\n        cout << ans[i] << \" \\n\"[i + 1 == ssize(ans)];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../src/string/manacher.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    string S;\n\
    \    cin >> S;\n    auto ans = manacher(S);\n    for (int i = 0; i < ssize(ans);\
    \ i++) {\n        cout << ans[i] << \" \\n\"[i + 1 == ssize(ans)];\n    }\n}"
  dependsOn:
  - src/string/manacher.hpp
  isVerificationFile: true
  path: test/string/manacher.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/manacher.test.cpp
layout: document
redirect_from:
- /verify/test/string/manacher.test.cpp
- /verify/test/string/manacher.test.cpp.html
title: test/string/manacher.test.cpp
---
