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
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
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
    \n\n#line 2 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\n#include\
    \ <numeric>\n#include <vector>\n#line 3 \"src/misc/monotone_minima.hpp\"\nusing\
    \ namespace std;\n\ntemplate<typename F, typename C>\nvector<int> monotone_minima(int\
    \ h, int w, const F &f, const C &comp) {\n    vector<int> id(h, -1);\n    auto\
    \ rec = [&](const auto &rec, int il, int jl, int ir, int jr) -> void {\n     \
    \   if (il > ir) return;\n        int im = (il + ir) / 2;\n        auto min_val\
    \ = f(im, jl);\n        id[im] = jl;\n        for (int j = jl + 1; j <= jr; j++)\
    \ {\n            auto v = f(im, j);\n            if (comp(v, min_val)) {\n   \
    \             min_val = v;\n                id[im] = j;\n            }\n     \
    \   }\n        rec(rec, il, jl, im - 1, id[im]);\n        rec(rec, im + 1, id[im],\
    \ ir, jr);\n    };\n    rec(rec, 0, 0, h - 1, w - 1);\n    return id;\n}\n#line\
    \ 5 \"src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\nusing namespace\
    \ std;\n\n// a must be convex\ntemplate<typename T>\nvector<T> min_plus_convolution(const\
    \ vector<T> &a, const vector<T> &b) {\n    static constexpr T inf = numeric_limits<T>::max();\n\
    \    auto f = [&](int i, int j) -> T {\n        return i < j || (int)a.size()\
    \ <= i - j ? inf : a[i - j] + b[j];\n    };\n    auto comp = [&](T x, T y) ->\
    \ bool {\n        return x < y;\n    };\n    int n = a.size() + b.size() - 1;\n\
    \    auto id = monotone_minima(n, b.size(), f, comp);\n    vector<T> res(n);\n\
    \    for (int i = 0; i < n; i++) res[i] = f(i, id[i]);\n    return res;\n}\n#line\
    \ 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n#include <cassert>\nusing\
    \ namespace std;\n\ntemplate<unsigned int MOD>\nstruct modint {\n    constexpr\
    \ modint() : x(0) {}\n    template<typename T>\n    constexpr modint(T v) {\n\
    \        int y = v % (int)mod();\n        if (y < 0) y += mod();\n        x =\
    \ (unsigned int)y;\n    }\n    static constexpr modint raw(int v) {\n        modint\
    \ a;\n        a.x = v;\n        return a;\n    }\n    static constexpr int mod()\
    \ { return MOD; }\n    constexpr unsigned int val() const { return x; }\n    constexpr\
    \ modint& operator++() {\n        x++;\n        if (x == mod()) x = 0;\n     \
    \   return *this;\n    }\n    constexpr modint& operator--() {\n        if (x\
    \ == 0) x = mod();\n        x--;\n        return *this;\n    }\n    constexpr\
    \ modint operator++(int) {\n        modint res = *this;\n        ++*this;\n  \
    \      return res;\n    }\n    constexpr modint operator--(int) {\n        modint\
    \ res = *this;\n        --*this;\n        return res;\n    }\n    constexpr modint&\
    \ operator+=(const modint &r) {\n        x += r.x;\n        if (x >= mod()) x\
    \ -= mod();\n        return *this;\n    }\n    constexpr modint& operator-=(const\
    \ modint &r) {\n        x -= r.x;\n        if (x >= mod()) x += mod();\n     \
    \   return *this;\n    }\n    constexpr modint& operator*=(const modint &r) {\n\
    \        unsigned long long y = x;\n        y *= r.x;\n        x = (unsigned int)(y\
    \ % mod());\n        return *this;\n    }\n    constexpr modint &operator/=(const\
    \ modint &r) {\n        return *this = *this * r.inv();\n    }\n    friend constexpr\
    \ modint operator+(const modint &a, const modint &b) {\n        return modint(a)\
    \ += b;\n    }\n    friend constexpr modint operator-(const modint &a, const modint\
    \ &b) {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
    \ modint &a, const modint &b) {\n        return modint(a) *= b;\n    }\n    friend\
    \ constexpr modint operator/(const modint &a, const modint &b) {\n        return\
    \ modint(a) /= b;\n    }\n    friend constexpr bool operator==(const modint &a,\
    \ const modint &b) {\n        return a.x == b.x;\n    }\n    friend constexpr\
    \ bool operator!=(const modint &a, const modint &b) {\n        return a.x != b.x;\n\
    \    }\n    constexpr modint operator+() const { return *this; }\n    constexpr\
    \ modint operator-() const { return modint() - *this; }\n    constexpr modint\
    \ pow(long long k) const {\n        assert(k >= 0);\n        modint a = *this;\n\
    \        modint res = 1;\n        while (k > 0) {\n            if (k & 1) res\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint inv() const {\n        long long a = x, b\
    \ = mod(), u = 1, v = 0;\n        while (b > 0) {\n            long long t = a\
    \ / b;\n            a -= t * b;\n            swap(a, b);\n            u -= t *\
    \ v;\n            swap(u, v);\n        }\n        return modint(u);\n    }\nprivate:\n\
    \    unsigned int x;\n};\n#line 5 \"test/convolution/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, M;\n    cin >> N >> M;\n    vector<int> A(N),\
    \ B(M);\n    for (auto &e : A) cin >> e;\n    for (auto &e : B) cin >> e;\n  \
    \  auto C = min_plus_convolution(A, B);\n    for (int i = 0; i < ssize(C); i++)\
    \ cout << C[i] << \" \\n\"[i + 1 == ssize(C)];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n\n#include \"../../src/convolution/min_plus_convolution_convex_arbitrary.hpp\"\
    \n#include \"../../src/modint/modint.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, M;\n\
    \    cin >> N >> M;\n    vector<int> A(N), B(M);\n    for (auto &e : A) cin >>\
    \ e;\n    for (auto &e : B) cin >> e;\n    auto C = min_plus_convolution(A, B);\n\
    \    for (int i = 0; i < ssize(C); i++) cout << C[i] << \" \\n\"[i + 1 == ssize(C)];\n\
    }"
  dependsOn:
  - src/convolution/min_plus_convolution_convex_arbitrary.hpp
  - src/misc/monotone_minima.hpp
  - src/modint/modint.hpp
  isVerificationFile: true
  path: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 09:28:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
layout: document
redirect_from:
- /verify/test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
- /verify/test/convolution/min_plus_convolution_convex_arbitrary.test.cpp.html
title: test/convolution/min_plus_convolution_convex_arbitrary.test.cpp
---
