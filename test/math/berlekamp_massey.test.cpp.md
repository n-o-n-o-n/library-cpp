---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/berlekamp_massey.hpp
    title: src/math/berlekamp_massey.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"test/math/berlekamp_massey.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/find_linear_recurrence\"\n\n#line 2 \"src/modint/modint.hpp\"\
    \n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\ntemplate<unsigned\
    \ int MOD>\nstruct modint {\n    constexpr modint() : x(0) {}\n    template<typename\
    \ T>\n    constexpr modint(T v) {\n        int y = v % (int)mod();\n        if\
    \ (y < 0) y += mod();\n        x = (unsigned int)y;\n    }\n    static constexpr\
    \ modint raw(int v) {\n        modint a;\n        a.x = v;\n        return a;\n\
    \    }\n    static constexpr int mod() { return MOD; }\n    constexpr unsigned\
    \ int val() const { return x; }\n    constexpr modint& operator++() {\n      \
    \  x++;\n        if (x == mod()) x = 0;\n        return *this;\n    }\n    constexpr\
    \ modint& operator--() {\n        if (x == 0) x = mod();\n        x--;\n     \
    \   return *this;\n    }\n    constexpr modint operator++(int) {\n        modint\
    \ res = *this;\n        ++*this;\n        return res;\n    }\n    constexpr modint\
    \ operator--(int) {\n        modint res = *this;\n        --*this;\n        return\
    \ res;\n    }\n    constexpr modint& operator+=(const modint &r) {\n        x\
    \ += r.x;\n        if (x >= mod()) x -= mod();\n        return *this;\n    }\n\
    \    constexpr modint& operator-=(const modint &r) {\n        x -= r.x;\n    \
    \    if (x >= mod()) x += mod();\n        return *this;\n    }\n    constexpr\
    \ modint& operator*=(const modint &r) {\n        unsigned long long y = x;\n \
    \       y *= r.x;\n        x = (unsigned int)(y % mod());\n        return *this;\n\
    \    }\n    constexpr modint &operator/=(const modint &r) {\n        return *this\
    \ = *this * r.inv();\n    }\n    friend constexpr modint operator+(const modint\
    \ &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend constexpr\
    \ modint operator-(const modint &a, const modint &b) {\n        return modint(a)\
    \ -= b;\n    }\n    friend constexpr modint operator*(const modint &a, const modint\
    \ &b) {\n        return modint(a) *= b;\n    }\n    friend constexpr modint operator/(const\
    \ modint &a, const modint &b) {\n        return modint(a) /= b;\n    }\n    friend\
    \ constexpr bool operator==(const modint &a, const modint &b) {\n        return\
    \ a.x == b.x;\n    }\n    friend constexpr bool operator!=(const modint &a, const\
    \ modint &b) {\n        return a.x != b.x;\n    }\n    constexpr modint operator+()\
    \ const { return *this; }\n    constexpr modint operator-() const { return modint()\
    \ - *this; }\n    constexpr modint pow(long long k) const {\n        assert(k\
    \ >= 0);\n        modint a = *this;\n        modint res = 1;\n        while (k\
    \ > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n            k\
    \ >>= 1;\n        }\n        return res;\n    }\n    constexpr modint inv() const\
    \ {\n        long long a = x, b = mod(), u = 1, v = 0;\n        while (b > 0)\
    \ {\n            long long t = a / b;\n            a -= t * b;\n            swap(a,\
    \ b);\n            u -= t * v;\n            swap(u, v);\n        }\n        return\
    \ modint(u);\n    }\nprivate:\n    unsigned int x;\n};\n#line 3 \"src/math/berlekamp_massey.hpp\"\
    \n#include <vector>\nusing namespace std;\n\ntemplate<typename mint>\nvector<mint>\
    \ Berlekamp_Massey(const vector<mint> &a) {\n    int n = a.size();\n    vector<mint>\
    \ b = {1}, c = {1};\n    b.reserve(n + 1);\n    c.reserve(n + 1);\n    mint y\
    \ = 1;\n    for (int d = 1; d <= n; d ++) {\n        int k = b.size(), l = c.size();\n\
    \        mint x = 0;\n        for (int i = 0; i < l; i++) {\n            x +=\
    \ c[i] * a[d - l + i];\n        }\n        b.push_back(0);\n        k++;\n   \
    \     if (x == 0) continue;\n        mint buf = x / y;\n        if (l < k) {\n\
    \            auto tmp = c;\n            c.insert(c.begin(), k - l, 0);\n     \
    \       for (int i = 0; i < k; i++) {\n                c[k - 1 - i] -= buf * b[k\
    \ - 1 - i];\n            }\n            b = tmp;\n            y = x;\n       \
    \ } else {\n            for (int i = 0; i < k; i++) {\n                c[l - 1\
    \ - i] -= buf * b[k - 1 - i];\n            }\n        }\n    }\n    reverse(c.begin(),\
    \ c.end());\n    for (mint &x : c) x = -x;\n    return c;\n}\n#line 5 \"test/math/berlekamp_massey.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin >>\
    \ N;\n    vector<mint> A(N);\n    for (mint &e : A) { int x; cin >> x; e = x;\
    \ }\n    auto C = Berlekamp_Massey(A);\n    C.erase(C.begin());\n    cout << ssize(C)\
    \ << '\\n';\n    for (int i = 0; i < ssize(C); i++) {\n        cout << C[i].val()\
    \ << \" \\n\"[i + 1 == ssize(C)];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include \"../../src/modint/modint.hpp\"\n#include \"../../src/math/berlekamp_massey.hpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin >>\
    \ N;\n    vector<mint> A(N);\n    for (mint &e : A) { int x; cin >> x; e = x;\
    \ }\n    auto C = Berlekamp_Massey(A);\n    C.erase(C.begin());\n    cout << ssize(C)\
    \ << '\\n';\n    for (int i = 0; i < ssize(C); i++) {\n        cout << C[i].val()\
    \ << \" \\n\"[i + 1 == ssize(C)];\n    }\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/berlekamp_massey.hpp
  isVerificationFile: true
  path: test/math/berlekamp_massey.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:38:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/berlekamp_massey.test.cpp
layout: document
redirect_from:
- /verify/test/math/berlekamp_massey.test.cpp
- /verify/test/math/berlekamp_massey.test.cpp.html
title: test/math/berlekamp_massey.test.cpp
---
