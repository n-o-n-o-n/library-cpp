---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/enumerative_combinatorics/combination.hpp
    title: src/math/enumerative_combinatorics/combination.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/enumerative_combinatorics/prefix_binomial_sum.hpp
    title: src/math/enumerative_combinatorics/prefix_binomial_sum.hpp
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
    PROBLEM: https://yukicoder.me/problems/no/2206
    links:
    - https://yukicoder.me/problems/no/2206
  bundledCode: "#line 1 \"test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp\"\
    \n#define PROBLEM \"https://yukicoder.me/problems/no/2206\"\n\n#line 2 \"src/modint/modint.hpp\"\
    \n#include <algorithm>\n#include <cassert>\nusing namespace std;\n\ntemplate<int\
    \ MOD>\nstruct modint {\n    constexpr modint() : x(0) {}\n    constexpr modint(long\
    \ long v) {\n        long long y = v % m();\n        if (y < 0) y += m();\n  \
    \      x = (unsigned int)(y);\n    }\n    static constexpr modint raw(int v) {\n\
    \        modint a;\n        a.x = v;\n        return a;\n    }\n    static constexpr\
    \ int mod() { return m(); }\n    constexpr unsigned int val() const { return x;\
    \ }\n    constexpr modint& operator++() {\n        x++;\n        if (x == m())\
    \ x = 0;\n        return *this;\n    }\n    constexpr modint& operator--() {\n\
    \        if (x == 0) x = m();\n        x--;\n        return *this;\n    }\n  \
    \  constexpr modint operator++(int) {\n        modint res = *this;\n        ++*this;\n\
    \        return res;\n    }\n    constexpr modint operator--(int) {\n        modint\
    \ res = *this;\n        --*this;\n        return res;\n    }\n    constexpr modint&\
    \ operator+=(const modint &r) {\n        x += r.x;\n        if (x >= m()) x -=\
    \ m();\n        return *this;\n    }\n    constexpr modint& operator-=(const modint\
    \ &r) {\n        x -= r.x;\n        if (x >= m()) x += m();\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint &r) {\n        unsigned\
    \ long long y = x;\n        y *= r.x;\n        x = (unsigned int)(y % m());\n\
    \        return *this;\n    }\n    constexpr modint &operator/=(const modint &r)\
    \ {\n        return *this = *this * r.inv();\n    }\n    friend constexpr modint\
    \ operator+(const modint &a, const modint &b) {\n        return modint(a) += b;\n\
    \    }\n    friend constexpr modint operator-(const modint &a, const modint &b)\
    \ {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
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
    \ = m(), u = 1, v = 0;\n        while (b > 0) {\n            long long t = a /\
    \ b;\n            a -= t * b;\n            swap(a, b);\n            u -= t * v;\n\
    \            swap(u, v);\n        }\n        return modint(u);\n    }\nprivate:\n\
    \    unsigned int x;\n    static constexpr unsigned int m() { return MOD; }\n\
    };\n#line 2 \"src/math/enumerative_combinatorics/prefix_binomial_sum.hpp\"\n#include\
    \ <vector>\nusing namespace std;\n#line 5 \"src/math/enumerative_combinatorics/combination.hpp\"\
    \nusing namespace std;\n\nnamespace combination {\n\ntemplate<typename mint>\n\
    struct container {\n    static vector<mint> fac, finv;\n    static void init(int\
    \ n) {\n        int sz = fac.size();\n        if (n < sz) return;\n        n =\
    \ clamp(n, 2 * sz, min<int>(1 << 27, mint::mod() - 1));\n        fac.resize(n\
    \ + 1);\n        finv.resize(n + 1);\n        for (int i = sz; i <= n; i++) {\n\
    \            fac[i] = i * fac[i - 1];\n        }\n        finv[n] = fac[n].inv();\n\
    \        for (int i = n; i >= sz; i--) {\n            finv[i - 1] = i * finv[i];\n\
    \        }\n    }\n};\n\ntemplate<typename mint>\nvector<mint> container<mint>::fac(1,\
    \ 1);\ntemplate<typename mint>\nvector<mint> container<mint>::finv(1, 1);\ntemplate<typename\
    \ mint>\nmint fac(int n) {\n    container<mint>::init(n);\n    if (n < 0) return\
    \ 0;\n    return container<mint>::fac[n];\n}\ntemplate<typename mint>\nmint finv(int\
    \ n) {\n    container<mint>::init(n);\n    if (n < 0) return 0;\n    return container<mint>::finv[n];\n\
    }\ntemplate<typename mint>\nmint mod_inv(int n) {\n    assert(n > 0);\n    return\
    \ finv<mint>(n) * fac<mint>(n - 1);\n}\ntemplate<typename mint>\nmint nCk(int\
    \ n, int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return fac<mint>(n)\
    \ * finv<mint>(n - k) * finv<mint>(k);\n}\n// [x^k]1/(1-x)^n\ntemplate<typename\
    \ mint>\nmint neg_nCk(int n, int k) {\n    if (n < 0 || k < 0) return 0;\n   \
    \ if (n == 0) return k == 0;\n    return nCk<mint>(n + k - 1, k);\n}\ntemplate<typename\
    \ mint>\nmint multi_C(const vector<int> &v) {\n    int n = 0;\n    for (const\
    \ int &k : v) n += k;\n    mint res = fac<mint>(n);\n    for (const int &k : v)\
    \ res *= finv<mint>(k);\n    return res;\n}\ntemplate<typename mint>\nmint nPk(int\
    \ n, int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return fac<mint>(n)\
    \ * finv<mint>(n - k);\n}\ntemplate<typename mint>\nmint catalan(int n) {\n  \
    \  return fac<mint>(2 * n) * finv<mint>(n) * finv<mint>(n + 1);\n}\ntemplate<typename\
    \ mint>\nmint grid_path(int n, int m) {\n    return nCk<mint>(n + m, n);\n}\n\n\
    } // namespace combination\n#line 5 \"src/math/enumerative_combinatorics/prefix_binomial_sum.hpp\"\
    \n\ntemplate<typename mint>\nstruct prefix_binomial_sum {\n    prefix_binomial_sum(int\
    \ n) : size(n), b(400) { build(); }\n    mint get(int n, int k) const {\n    \
    \    assert(0 <= n && n <= size);\n        int tn = (n + b / 2) / b;\n       \
    \ int tk = (k + b / 2) / b;\n        mint res = table[tn][tk];\n        tn *=\
    \ b;\n        tk *= b;\n        while (tk < k) res = res + combination::nCk<mint>(tn,\
    \ ++tk);\n        while (tk > k) res = res - combination::nCk<mint>(tn, tk--);\n\
    \        while (tn < n) res = 2 * res - combination::nCk<mint>(tn++, tk);\n  \
    \      while (tn > n) res = (res + combination::nCk<mint>(--tn, tk)) * inv2;\n\
    \        return res;\n    }\nprivate:\n    int size, b;\n    mint inv2;\n    vector<vector<mint>>\
    \ table;\n    void build() {\n        size += b;\n        inv2 = mint::raw(2).inv();\n\
    \        int n = (size + b - 1) / b;\n        table.resize(n + 1);\n        for\
    \ (int i = 0; i <= n; i++) {\n            table[i].resize(n + 1);\n          \
    \  table[i][0] = 1;\n            mint cur = 1;\n            for (int j = 1; j\
    \ <= n * b; j++) {\n                cur += combination::nCk<mint>(b * i, j);\n\
    \                if (j % b == 0) {\n                    table[i][j / b] = cur;\n\
    \                }\n            }\n        }\n    }\n};\n#line 5 \"test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int T;\n    cin >>\
    \ T;\n    prefix_binomial_sum<mint> C((int)2e5);\n    while (T--) {\n        int\
    \ N, M;\n        cin >> N >> M;\n        mint ans = mint(2).pow(N) - 1;\n    \
    \    ans *= C.get(N - 1, M - 1);\n        cout << ans.val() << '\\n';\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2206\"\n\n#include \"\
    ../../../src/modint/modint.hpp\"\n#include \"../../../src/math/enumerative_combinatorics/prefix_binomial_sum.hpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int T;\n    cin >>\
    \ T;\n    prefix_binomial_sum<mint> C((int)2e5);\n    while (T--) {\n        int\
    \ N, M;\n        cin >> N >> M;\n        mint ans = mint(2).pow(N) - 1;\n    \
    \    ans *= C.get(N - 1, M - 1);\n        cout << ans.val() << '\\n';\n    }\n\
    }\n"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/enumerative_combinatorics/prefix_binomial_sum.hpp
  - src/math/enumerative_combinatorics/combination.hpp
  isVerificationFile: true
  path: test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp
- /verify/test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp.html
title: test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp
---
