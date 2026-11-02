---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/convolution/min_plus_convolution_convex_arbitrary.hpp
    title: src/convolution/min_plus_convolution_convex_arbitrary.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
    title: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/misc/monotone_minima.hpp\"\n\ntemplate<typename F, typename\
    \ C>\nvector<int> monotone_minima(int h, int w, const F &f, const C &comp) {\n\
    \    vector<int> id(h, -1);\n    auto rec = [&](const auto &rec, int il, int jl,\
    \ int ir, int jr) -> void {\n        if (il > ir) return;\n        int im = (il\
    \ + ir) / 2;\n        auto min_val = f(im, jl);\n        id[im] = jl;\n      \
    \  for (int j = jl + 1; j <= jr; j++) {\n            auto v = f(im, j);\n    \
    \        if (comp(v, min_val)) {\n                min_val = v;\n             \
    \   id[im] = j;\n            }\n        }\n        rec(rec, il, jl, im - 1, id[im]);\n\
    \        rec(rec, im + 1, id[im], ir, jr);\n    };\n    rec(rec, 0, 0, h - 1,\
    \ w - 1);\n    return id;\n}\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\ntemplate<typename F, typename\
    \ C>\nvector<int> monotone_minima(int h, int w, const F &f, const C &comp) {\n\
    \    vector<int> id(h, -1);\n    auto rec = [&](const auto &rec, int il, int jl,\
    \ int ir, int jr) -> void {\n        if (il > ir) return;\n        int im = (il\
    \ + ir) / 2;\n        auto min_val = f(im, jl);\n        id[im] = jl;\n      \
    \  for (int j = jl + 1; j <= jr; j++) {\n            auto v = f(im, j);\n    \
    \        if (comp(v, min_val)) {\n                min_val = v;\n             \
    \   id[im] = j;\n            }\n        }\n        rec(rec, il, jl, im - 1, id[im]);\n\
    \        rec(rec, im + 1, id[im], ir, jr);\n    };\n    rec(rec, 0, 0, h - 1,\
    \ w - 1);\n    return id;\n}"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/misc/monotone_minima.hpp
  requiredBy:
  - src/convolution/min_plus_convolution_convex_arbitrary.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: src/misc/monotone_minima.hpp
layout: document
redirect_from:
- /library/src/misc/monotone_minima.hpp
- /library/src/misc/monotone_minima.hpp.html
title: src/misc/monotone_minima.hpp
---
