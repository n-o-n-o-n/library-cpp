---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/matrix/matrix.hpp
    title: src/math/matrix/matrix.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"test/math/matrix/matrix_inv.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#line 2 \"src/modint/modint.hpp\"\
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
    \ modint(u);\n    }\nprivate:\n    unsigned int x;\n};\n#line 3 \"src/math/matrix/matrix.hpp\"\
    \n#include <vector>\nusing namespace std;\n\ntemplate<typename mint>\nstruct matrix\
    \ : vector<vector<mint>> {\n    using vector<vector<mint>>::vector;\n    matrix(int\
    \ h, int w) : vector<vector<mint>>(h, vector<mint>(w)) {}\n    matrix &operator*=(const\
    \ mint &r) {\n        for (vector<mint> &v : *this) {\n            for (mint &a\
    \ : v) a *= r;\n        }\n        return *this;\n    }\n    matrix &operator/=(const\
    \ mint &r) {\n        mint invr = r.inv();\n        return *this *= invr;\n  \
    \  }\n    matrix &operator+=(const matrix& a) {\n        assert(this->size() ==\
    \ a.size());\n        for (int i = 0; i < int(this->size()); i++) {\n        \
    \    assert((*this)[i].size() == a[i].size());\n            for (int j = 0; j\
    \ < int((*this)[i].size()); j++) {\n                (*this)[i][j] += a[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n    matrix &operator-=(const\
    \ matrix& a) {\n        assert(this->size() == a.size());\n        for (int i\
    \ = 0; i < int(this->size()); i++) {\n            assert((*this)[i].size() ==\
    \ a[i].size());\n            for (int j = 0; j < int((*this)[i].size()); j++)\
    \ {\n                (*this)[i][j] -= a[i][j];\n            }\n        }\n   \
    \     return *this;\n    }\n    matrix &operator*=(const matrix &a) {\n      \
    \  int n = this->size(), m = a.size();\n        assert(m >= 1);\n        int l\
    \ = a[0].size();\n        matrix res(n, vector<mint>(l));\n        for (int i\
    \ = 0; i < n; i++) {\n            assert(int((*this)[i].size()) == m);\n     \
    \       for (int k = 0; k < m; k++) {\n                for (int j = 0; j < l;\
    \ j++) {\n                    res[i][j] += (*this)[i][k] * a[k][j];\n        \
    \        }\n            }\n        }\n        return *this = res;\n    }\n   \
    \ matrix operator*(const mint &r) const { return matrix(*this) *= r; }\n    matrix\
    \ operator/(const mint &r) const { return matrix(*this) /= r; }\n    matrix operator+(const\
    \ matrix &a) const { return matrix(*this) += a; }\n    matrix operator-(const\
    \ matrix &a) const { return matrix(*this) -= a; }\n    matrix operator*(const\
    \ matrix &a) const { return matrix(*this) *= a; }\n    static constexpr matrix\
    \ I(int n) {\n        matrix res(n, n);\n        for (int i = 0; i < n; i++) {\n\
    \            res[i][i] = 1;\n        }\n        return res;\n    }\n    static\
    \ constexpr matrix O(int n) { return matrix(n, n); }\n    matrix pow(long long\
    \ k) const {\n        matrix res = I(this->size()), a = *this;\n        while\
    \ (k > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n         \
    \   k >>= 1;\n        }\n        return res;\n    }\n    mint det() const {\n\
    \        int n = this->size();\n        assert(n >= 1);\n        assert((*this)[0].size()\
    \ == this->size());\n        mint res = 1;\n        matrix a = *this;\n      \
    \  for (int i = 0; i < n; i++) {\n            for (int j = i; j < n; j++) {\n\
    \                if (a[j][i] != 0) {\n                    if (i != j) res = -res;\n\
    \                    swap(a[i], a[j]);\n                    break;\n         \
    \       }\n            }\n            if (a[i][i] != 0) {\n                for\
    \ (int j = i + 1; j < n; j++) {\n                    mint inv = a[j][i] * a[i][i].inv();\n\
    \                    for (int k = i + 1; k < n; k++) {\n                     \
    \   a[j][k] -= a[i][k] * inv;\n                    }\n                }\n    \
    \        }\n        }\n        for (int i = 0; i < n; i++) {\n            res\
    \ *= a[i][i];\n        }\n        return res;\n    }\n    matrix inv() const {\n\
    \        int n = this->size();\n        matrix a = *this, res = I(n);\n      \
    \  for (int i = 0; i < n; i++) {\n            if (a[i][i] == 0) {\n          \
    \      for (int j = i + 1; j < n; j++) {\n                    if (a[j][i] != 0)\
    \ {\n                        swap(a[i], a[j]);\n                        swap(res[i],\
    \ res[j]);\n                        break;\n                    }\n          \
    \      }\n            }\n            assert(a[i][i] != 0);\n            mint cef\
    \ = a[i][i].inv();\n            for (int j = 0; j < n; j++) {\n              \
    \  a[i][j] *= cef;\n                res[i][j] *= cef;\n            }\n       \
    \     for (int j = 0; j < n; j++) {\n                if (j != i) {\n         \
    \           cef = a[j][i];\n                    for (int k = 0; k < n; k++) {\n\
    \                        a[j][k] -= a[i][k] * cef;\n                        res[j][k]\
    \ -= res[i][k] * cef;\n                    }\n                }\n            }\n\
    \        }\n        return res;\n    }\n    int rank() const {\n        matrix\
    \ a = *this;\n        int h = a.size(), w = a[0].size();\n        int r = 0;\n\
    \        for (int j = 0; j < w && r < h; j++) {\n            int i = r;\n    \
    \        while (i < h && a[i][j] == 0) i++;\n            if (i == h) continue;\n\
    \            swap(a[r], a[i]);\n            mint inv = a[r][j].inv();\n      \
    \      for (i = r + 1; i < h; i++) {\n                mint cef = a[i][j] * inv;\n\
    \                for (int k = j; k < w; k++) {\n                    a[i][k] -=\
    \ a[r][k] * cef;\n                }\n            }\n            r++;\n       \
    \ }\n        return r;\n    }\n};\n#line 5 \"test/math/matrix/matrix_inv.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin >>\
    \ N;\n    matrix<mint> A(N, N);\n    for (auto &E : A) for (auto &e : E) { int\
    \ x; cin >> x; e = x; }\n    if (A.det() == 0) {\n        cout << -1 << '\\n';\n\
    \        return 0;\n    }\n    A = A.inv();\n    for (int i = 0; i < N; i++) {\n\
    \        for (int j = 0; j < N; j++) cout << A[i][j].val() << \" \\n\"[j + 1 ==\
    \  N];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include\
    \ \"../../../src/modint/modint.hpp\"\n#include \"../../../src/math/matrix/matrix.hpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin >>\
    \ N;\n    matrix<mint> A(N, N);\n    for (auto &E : A) for (auto &e : E) { int\
    \ x; cin >> x; e = x; }\n    if (A.det() == 0) {\n        cout << -1 << '\\n';\n\
    \        return 0;\n    }\n    A = A.inv();\n    for (int i = 0; i < N; i++) {\n\
    \        for (int j = 0; j < N; j++) cout << A[i][j].val() << \" \\n\"[j + 1 ==\
    \  N];\n    }\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/matrix/matrix.hpp
  isVerificationFile: true
  path: test/math/matrix/matrix_inv.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 09:27:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/matrix/matrix_inv.test.cpp
layout: document
redirect_from:
- /verify/test/math/matrix/matrix_inv.test.cpp
- /verify/test/math/matrix/matrix_inv.test.cpp.html
title: test/math/matrix/matrix_inv.test.cpp
---
