---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/mod_log.hpp
    title: src/math/number_theory/mod_log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/discrete_logarithm.test.cpp
    title: test/math/number_theory/discrete_logarithm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/math/number_theory/mod_log.test.cpp
    title: test/math/number_theory/mod_log.test.cpp
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
    \ }\n#line 3 \"src/modint/dynamic_modint.hpp\"\n\nstruct modint {\n    modint()\
    \ : x(0) {}\n    modint(long long v) {\n        long long y = v % m();\n     \
    \   if (y < 0) y += m();\n        x = (unsigned int)(y);\n    }\n    static void\
    \ set_mod(int _m) { MOD = _m; }\n    static modint raw(int v) {\n        modint\
    \ a;\n        a.x = v;\n        return a;\n    }\n    static int mod() { return\
    \ m(); }\n    unsigned int val() const { return x; }\n    modint& operator++()\
    \ {\n        x++;\n        if (x == m()) x = 0;\n        return *this;\n    }\n\
    \    modint& operator--() {\n        if (x == 0) x = m();\n        x--;\n    \
    \    return *this;\n    }\n    modint operator++(int) {\n        modint res =\
    \ *this;\n        ++*this;\n        return res;\n    }\n    modint operator--(int)\
    \ {\n        modint res = *this;\n        --*this;\n        return res;\n    }\n\
    \    modint& operator+=(const modint &r) {\n        x += r.x;\n        if (x >=\
    \ m()) x -= m();\n        return *this;\n    }\n    modint& operator-=(const modint\
    \ &r) {\n        x -= r.x;\n        if (x >= m()) x += m();\n        return *this;\n\
    \    }\n    modint& operator*=(const modint &r) {\n        unsigned long long\
    \ y = x;\n        y *= r.x;\n        x = (unsigned int)(y % m());\n        return\
    \ *this;\n    }\n    modint &operator/=(const modint &r) {\n        return *this\
    \ = *this * r.inv();\n    }\n    friend modint operator+(const modint &a, const\
    \ modint &b) {\n        return modint(a) += b;\n    }\n    friend modint operator-(const\
    \ modint &a, const modint &b) {\n        return modint(a) -= b;\n    }\n    friend\
    \ modint operator*(const modint &a, const modint &b) {\n        return modint(a)\
    \ *= b;\n    }\n    friend modint operator/(const modint &a, const modint &b)\
    \ {\n        return modint(a) /= b;\n    }\n    friend bool operator==(const modint\
    \ &a, const modint &b) {\n        return a.x == b.x;\n    }\n    friend bool operator!=(const\
    \ modint &a, const modint &b) {\n        return a.x != b.x;\n    }\n    modint\
    \ operator+() const { return *this; }\n    modint operator-() const { return modint()\
    \ - *this; }\n    modint pow(long long k) const {\n        assert(k >= 0);\n \
    \       modint a = *this;\n        modint res = 1;\n        while (k > 0) {\n\
    \            if (k & 1) res *= a;\n            a *= a;\n            k >>= 1;\n\
    \        }\n        return res;\n    }\n    modint inv() const {\n        long\
    \ long a = x, b = m(), u = 1, v = 0;\n        while (b > 0) {\n            long\
    \ long t = a / b;\n            a -= t * b;\n            swap(a, b);\n        \
    \    u -= t * v;\n            swap(u, v);\n        }\n        return modint(u);\n\
    \    }\nprivate:\n    unsigned int x;\n    inline static unsigned int MOD = -1;\n\
    \    static unsigned int m() { return MOD; }\n};\n"
  code: "#pragma once\n#include \"../template.hpp\"\n\nstruct modint {\n    modint()\
    \ : x(0) {}\n    modint(long long v) {\n        long long y = v % m();\n     \
    \   if (y < 0) y += m();\n        x = (unsigned int)(y);\n    }\n    static void\
    \ set_mod(int _m) { MOD = _m; }\n    static modint raw(int v) {\n        modint\
    \ a;\n        a.x = v;\n        return a;\n    }\n    static int mod() { return\
    \ m(); }\n    unsigned int val() const { return x; }\n    modint& operator++()\
    \ {\n        x++;\n        if (x == m()) x = 0;\n        return *this;\n    }\n\
    \    modint& operator--() {\n        if (x == 0) x = m();\n        x--;\n    \
    \    return *this;\n    }\n    modint operator++(int) {\n        modint res =\
    \ *this;\n        ++*this;\n        return res;\n    }\n    modint operator--(int)\
    \ {\n        modint res = *this;\n        --*this;\n        return res;\n    }\n\
    \    modint& operator+=(const modint &r) {\n        x += r.x;\n        if (x >=\
    \ m()) x -= m();\n        return *this;\n    }\n    modint& operator-=(const modint\
    \ &r) {\n        x -= r.x;\n        if (x >= m()) x += m();\n        return *this;\n\
    \    }\n    modint& operator*=(const modint &r) {\n        unsigned long long\
    \ y = x;\n        y *= r.x;\n        x = (unsigned int)(y % m());\n        return\
    \ *this;\n    }\n    modint &operator/=(const modint &r) {\n        return *this\
    \ = *this * r.inv();\n    }\n    friend modint operator+(const modint &a, const\
    \ modint &b) {\n        return modint(a) += b;\n    }\n    friend modint operator-(const\
    \ modint &a, const modint &b) {\n        return modint(a) -= b;\n    }\n    friend\
    \ modint operator*(const modint &a, const modint &b) {\n        return modint(a)\
    \ *= b;\n    }\n    friend modint operator/(const modint &a, const modint &b)\
    \ {\n        return modint(a) /= b;\n    }\n    friend bool operator==(const modint\
    \ &a, const modint &b) {\n        return a.x == b.x;\n    }\n    friend bool operator!=(const\
    \ modint &a, const modint &b) {\n        return a.x != b.x;\n    }\n    modint\
    \ operator+() const { return *this; }\n    modint operator-() const { return modint()\
    \ - *this; }\n    modint pow(long long k) const {\n        assert(k >= 0);\n \
    \       modint a = *this;\n        modint res = 1;\n        while (k > 0) {\n\
    \            if (k & 1) res *= a;\n            a *= a;\n            k >>= 1;\n\
    \        }\n        return res;\n    }\n    modint inv() const {\n        long\
    \ long a = x, b = m(), u = 1, v = 0;\n        while (b > 0) {\n            long\
    \ long t = a / b;\n            a -= t * b;\n            swap(a, b);\n        \
    \    u -= t * v;\n            swap(u, v);\n        }\n        return modint(u);\n\
    \    }\nprivate:\n    unsigned int x;\n    inline static unsigned int MOD = -1;\n\
    \    static unsigned int m() { return MOD; }\n};\n"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/modint/dynamic_modint.hpp
  requiredBy:
  - src/math/number_theory/mod_log.hpp
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/math/number_theory/mod_log.test.cpp
  - test/math/number_theory/discrete_logarithm.test.cpp
documentation_of: src/modint/dynamic_modint.hpp
layout: document
redirect_from:
- /library/src/modint/dynamic_modint.hpp
- /library/src/modint/dynamic_modint.hpp.html
title: src/modint/dynamic_modint.hpp
---
