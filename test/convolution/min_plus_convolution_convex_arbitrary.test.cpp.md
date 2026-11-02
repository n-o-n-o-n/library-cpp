---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/min_plus_convolution_convex_arbitrary.hpp
    title: src/convolution/min_plus_convolution_convex_arbitrary.hpp
  - icon: ':heavy_check_mark:'
    path: src/misc/monotone_minima.hpp
    title: src/misc/monotone_minima.hpp
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
  bundledCode: "#line 1 \"test/convolution/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n\n#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return numeric_limits<T>::max()\
    \ / 2; }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return\
    \ a > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/misc/monotone_minima.hpp\"\
    \n\ntemplate<typename F, typename C>\nvector<int> monotone_minima(int h, int w,\
    \ const F &f, const C &comp) {\n    vector<int> id(h, -1);\n    auto rec = [&](const\
    \ auto &rec, int il, int jl, int ir, int jr) -> void {\n        if (il > ir) return;\n\
    \        int im = (il + ir) / 2;\n        auto min_val = f(im, jl);\n        id[im]\
    \ = jl;\n        for (int j = jl + 1; j <= jr; j++) {\n            auto v = f(im,\
    \ j);\n            if (comp(v, min_val)) {\n                min_val = v;\n   \
    \             id[im] = j;\n            }\n        }\n        rec(rec, il, jl,\
    \ im - 1, id[im]);\n        rec(rec, im + 1, id[im], ir, jr);\n    };\n    rec(rec,\
    \ 0, 0, h - 1, w - 1);\n    return id;\n}\n#line 4 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \n\n// a must be convex\ntemplate<typename T>\nvector<T> min_plus_convolution(const\
    \ vector<T> &a, const vector<T> &b) {\n    auto f = [&](int i, int j) -> T {\n\
    \        return i < j || (int)a.size() <= i - j ? numeric_limits<T>::max() : a[i\
    \ - j] + b[j];\n    };\n    auto comp = [&](T x, T y) -> bool {\n        return\
    \ x < y;\n    };\n    int n = a.size() + b.size() - 1;\n    auto id = monotone_minima(n,\
    \ b.size(), f, comp);\n    vector<T> res(n);\n    for (int i = 0; i < n; i++)\
    \ res[i] = f(i, id[i]);\n    return res;\n}\n#line 5 \"test/convolution/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N, M;\n    cin >> N >> M;\n    vector<int> A(N), B(M);\n    for (auto &e\
    \ : A) cin >> e;\n    for (auto &e : B) cin >> e;\n    auto C = min_plus_convolution(A,\
    \ B);\n    for (int i = 0; i < ssize(C); i++) cout << C[i] << \" \\n\"[i + 1 ==\
    \ ssize(C)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n\n#include \"../../src/template.hpp\"\n#include \"../../src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N, M;\n    cin >> N >> M;\n    vector<int> A(N), B(M);\n    for (auto &e\
    \ : A) cin >> e;\n    for (auto &e : B) cin >> e;\n    auto C = min_plus_convolution(A,\
    \ B);\n    for (int i = 0; i < ssize(C); i++) cout << C[i] << \" \\n\"[i + 1 ==\
    \ ssize(C)];\n}"
  dependsOn:
  - src/template.hpp
  - src/convolution/min_plus_convolution_convex_arbitrary.hpp
  - src/misc/monotone_minima.hpp
  isVerificationFile: true
  path: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
- /verify/test/convolution/min_plus_convolution_convex_arbitrary.test.cpp.html
title: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
---
