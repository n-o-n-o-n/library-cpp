---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/misc/enumerate_brackets.hpp\"\n#include <vector>\nusing\
    \ namespace std;\n\n// n <= 15 \u304C\u9650\u754C\u304B\u306A\nvector<string>\
    \ enumerate_brackets(int n) {\n    vector<string> res;\n    auto dfs = [&] (const\
    \ auto &dfs, int x, int y, string s) -> void {\n        if (x == n && y == n)\
    \ {\n            res.push_back(s);\n            return;\n        }\n        if\
    \ (x < n) dfs(dfs, x + 1, y, s + \"(\");\n        if (y < x) dfs(dfs, x, y + 1,\
    \ s + \")\");\n    };\n    dfs(dfs, 0, 0, \"\");\n    return res;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\n// n <= 15 \u304C\
    \u9650\u754C\u304B\u306A\nvector<string> enumerate_brackets(int n) {\n    vector<string>\
    \ res;\n    auto dfs = [&] (const auto &dfs, int x, int y, string s) -> void {\n\
    \        if (x == n && y == n) {\n            res.push_back(s);\n            return;\n\
    \        }\n        if (x < n) dfs(dfs, x + 1, y, s + \"(\");\n        if (y <\
    \ x) dfs(dfs, x, y + 1, s + \")\");\n    };\n    dfs(dfs, 0, 0, \"\");\n    return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/enumerate_brackets.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/misc/enumerate_brackets.hpp
layout: document
redirect_from:
- /library/src/misc/enumerate_brackets.hpp
- /library/src/misc/enumerate_brackets.hpp.html
title: src/misc/enumerate_brackets.hpp
---
