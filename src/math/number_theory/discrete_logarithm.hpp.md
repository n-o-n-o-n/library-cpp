---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: src/math/number_theory/mod_log.hpp
    title: src/math/number_theory/mod_log.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/math/number_theory/discrete_logarithm.test.cpp
    title: test/math/number_theory/discrete_logarithm.test.cpp
  - icon: ':x:'
    path: test/math/number_theory/mod_log.test.cpp
    title: test/math/number_theory/mod_log.test.cpp
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
    \ }\n#line 3 \"src/math/number_theory/discrete_logarithm.hpp\"\n\ntemplate<typename\
    \ ActSet>\nstruct discrete_logarithm {\n    using S = typename ActSet::S;\n  \
    \  using F = typename ActSet::F;\n    template<typename H>\n    static long long\
    \ solve(F f, S s, S t, long long p, const H &h) {\n        long long ht = h(t);\n\
    \        long long m = 1;\n        do {\n            m++;\n        } while (m\
    \ * m <= p);\n        unordered_set<long long> a;\n        a.reserve(m);\n   \
    \     for (int k = 0; k < m; k++) {\n            t = ActSet::mapping(f, t);\n\
    \            a.insert(h(t));\n        }\n        F g = ActSet::id();\n       \
    \ {\n            long long mm = m;\n            F ff = f;\n            while (m\
    \ > 0) {\n                if (m & 1) g = ActSet::comp(g, f);\n               \
    \ f = ActSet::comp(f, f);\n                m >>= 1;\n            }\n         \
    \   m = mm;\n            f = ff;\n        }\n        for (int k = 0, flag = 0;\
    \ k <= m; k++) {\n            t = ActSet::mapping(g, s);\n            if (a.count(h(t)))\
    \ {\n                for (int i = 0; i < m; i++) {\n                    if (h(s)\
    \ == ht) {\n                        return m * k + i;\n                    }\n\
    \                    s = ActSet::mapping(f, s);\n                }\n         \
    \       if (flag) return -1;\n                flag = 1;\n            }\n     \
    \       s = t;\n        }\n        return -1;\n    }\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\ntemplate<typename ActSet>\n\
    struct discrete_logarithm {\n    using S = typename ActSet::S;\n    using F =\
    \ typename ActSet::F;\n    template<typename H>\n    static long long solve(F\
    \ f, S s, S t, long long p, const H &h) {\n        long long ht = h(t);\n    \
    \    long long m = 1;\n        do {\n            m++;\n        } while (m * m\
    \ <= p);\n        unordered_set<long long> a;\n        a.reserve(m);\n       \
    \ for (int k = 0; k < m; k++) {\n            t = ActSet::mapping(f, t);\n    \
    \        a.insert(h(t));\n        }\n        F g = ActSet::id();\n        {\n\
    \            long long mm = m;\n            F ff = f;\n            while (m >\
    \ 0) {\n                if (m & 1) g = ActSet::comp(g, f);\n                f\
    \ = ActSet::comp(f, f);\n                m >>= 1;\n            }\n           \
    \ m = mm;\n            f = ff;\n        }\n        for (int k = 0, flag = 0; k\
    \ <= m; k++) {\n            t = ActSet::mapping(g, s);\n            if (a.count(h(t)))\
    \ {\n                for (int i = 0; i < m; i++) {\n                    if (h(s)\
    \ == ht) {\n                        return m * k + i;\n                    }\n\
    \                    s = ActSet::mapping(f, s);\n                }\n         \
    \       if (flag) return -1;\n                flag = 1;\n            }\n     \
    \       s = t;\n        }\n        return -1;\n    }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/math/number_theory/discrete_logarithm.hpp
  requiredBy:
  - src/math/number_theory/mod_log.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/math/number_theory/mod_log.test.cpp
  - test/math/number_theory/discrete_logarithm.test.cpp
documentation_of: src/math/number_theory/discrete_logarithm.hpp
layout: document
redirect_from:
- /library/src/math/number_theory/discrete_logarithm.hpp
- /library/src/math/number_theory/discrete_logarithm.hpp.html
title: src/math/number_theory/discrete_logarithm.hpp
---
