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
  bundledCode: "#line 2 \"src/monoid/max.hpp\"\n#include <algorithm>\n#include <limits>\n\
    using namespace std;\n\ntemplate<typename T, T E = numeric_limits<T>::min()>\n\
    struct max_monoid {\n    using S = T;\n    static S op(S a, S b) { return max(a,\
    \ b); }\n    static S e() { return E; }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\nusing namespace std;\n\
    \ntemplate<typename T, T E = numeric_limits<T>::min()>\nstruct max_monoid {\n\
    \    using S = T;\n    static S op(S a, S b) { return max(a, b); }\n    static\
    \ S e() { return E; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/monoid/max.hpp
  requiredBy: []
  timestamp: '2026-10-29 14:11:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/monoid/max.hpp
layout: document
redirect_from:
- /library/src/monoid/max.hpp
- /library/src/monoid/max.hpp.html
title: src/monoid/max.hpp
---
