---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/monoid/bracket.hpp\"\n\nstruct Bracket {\n    using S = pair<int,\
    \ int>;\n    static S op(S a, S b) {\n        int cumsum = a.first + b.first;\n\
    \        int cummin = min(a.second, a.first + b.second);\n        return make_pair(cumsum,\
    \ cummin);\n    }\n    static S e() { return make_pair(0, 0); }\n    static S\
    \ L() { return make_pair(1, 0); }\n    static S R() { return make_pair(-1, -1);\
    \ }\n    static S map(char c) { return c == '(' ? L() : R(); }\n    static char\
    \ flip(char c) { return c == '(' ? ')' : '('; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nstruct Bracket {\n    using\
    \ S = pair<int, int>;\n    static S op(S a, S b) {\n        int cumsum = a.first\
    \ + b.first;\n        int cummin = min(a.second, a.first + b.second);\n      \
    \  return make_pair(cumsum, cummin);\n    }\n    static S e() { return make_pair(0,\
    \ 0); }\n    static S L() { return make_pair(1, 0); }\n    static S R() { return\
    \ make_pair(-1, -1); }\n    static S map(char c) { return c == '(' ? L() : R();\
    \ }\n    static char flip(char c) { return c == '(' ? ')' : '('; }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/monoid/bracket.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/bracket.hpp
layout: document
redirect_from:
- /library/src/monoid/bracket.hpp
- /library/src/monoid/bracket.hpp.html
title: src/monoid/bracket.hpp
---
