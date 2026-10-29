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
    PROBLEM: https://judge.yosupo.jp/problem/prefix_sum_of_binomial_coefficient
    links:
    - https://judge.yosupo.jp/problem/prefix_sum_of_binomial_coefficient
  bundledCode: "#line 1 \"test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/prefix_sum_of_binomial_coefficient\"\
    \n\n#line 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate<unsigned int MOD>\nstruct modint {\n    constexpr\
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
    \    unsigned int x;\n};\n#line 2 \"src/math/enumerative_combinatorics/prefix_binomial_sum.hpp\"\
    \n#include <vector>\nusing namespace std;\n#line 4 \"src/math/enumerative_combinatorics/combination.hpp\"\
    \n#include <concepts>\n#line 6 \"src/math/enumerative_combinatorics/combination.hpp\"\
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
    \ res *= finv<mint>(k);\n    return res;\n}\ntemplate<typename mint>\nmint multi_C(same_as<int>\
    \ auto... ks) {\n    int n = (0 + ... + ks);\n    mint res = fac<mint>(n);\n \
    \   ((res *= finv<mint>(ks)), ...);\n    return res;\n}\ntemplate<typename mint>\n\
    mint nPk(int n, int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return\
    \ fac<mint>(n) * finv<mint>(n - k);\n}\ntemplate<typename mint>\nmint catalan(int\
    \ n) {\n    return fac<mint>(2 * n) * finv<mint>(n) * finv<mint>(n + 1);\n}\n\
    template<typename mint>\nmint grid_path(int n, int m) {\n    return nCk<mint>(n\
    \ + m, n);\n}\n\n} // namespace combination\n#line 5 \"src/math/enumerative_combinatorics/prefix_binomial_sum.hpp\"\
    \n\nnamespace combination {\n\ntemplate<typename mint, int N>\nstruct prefix_binomial_sum\
    \ {\n    using i128 = unsigned __int128;\n    prefix_binomial_sum() {\n      \
    \  container<mint>::init(s);\n        mint one = 1, inv2 = mint(2).inv();\n  \
    \      const auto &fac = container<mint>::fac;\n        const auto &finv = container<mint>::finv;\n\
    \        p2.resize(s + 1);\n        g.resize(s + 1);\n        p2[0] = 1;\n   \
    \     for (int i = 1; i <= s; i++) p2[i] = p2[i - 1] + p2[i - 1];\n        mint\
    \ invpow = p2[s].inv() * inv2;\n        for (int i = s; i >= 0; i--) {\n     \
    \       g[i] = fac[i] * invpow;\n            invpow += invpow;\n        }\n  \
    \      table.resize(w * w);\n        const mint i2b = inv2.pow(b);\n        mint\
    \ invp2 = 1;\n        for (int i = 0; i < w; i++) {\n            mint f = fac[i\
    \ * b] * invp2, sum = invp2;\n            for (int j = 0; j <= i / 2; j++) {\n\
    \                int k = j * b;\n                table[id(i, j)] = sum;\n    \
    \            if (j != i - j) {\n                    table[id(i, i - j)] = one\
    \ - sum + f * finv[j * b] * finv[(i - j) * b];\n                }\n          \
    \      if (j < i / 2) {\n                    i128 bs = 0;\n                  \
    \  for (int x = j * b + 1; x <= j * b + b; x++) {\n                        bs\
    \ += (i128)finv[x].val() * finv[i * b - x].val();\n                    }\n   \
    \                 sum += f * bs;\n                }\n            }\n         \
    \   invp2 *= i2b;\n        }\n    }\n    mint get(int n, int k) const {\n    \
    \    assert(0 <= k && k <= n && n <= N);\n        int tn = (n + b / 2) / b;\n\
    \        int tk = (k + b / 2) / b;\n        mint res = table[id(tn, tk)];\n  \
    \      tn *= b;\n        tk *= b;\n        const auto &finv = container<mint>::finv;\n\
    \        int l = max(min(tn, n), tk);\n        int r = max(tn, n);\n        mint\
    \ cur = [&] {\n            i128 res = 0;\n            for (int i = l; i < r; i++)\
    \ res += (i128)g[i].val() * finv[i - tk].val();\n            return res;\n   \
    \     } ();\n        cur *= finv[tk];\n        res += tn < n ? -cur : cur;\n \
    \       res *= p2[n];\n        res += tk < k ? sub(n, tk + 1, k + 1) : -sub(n,\
    \ k + 1, min(tk, n) + 1);\n        return res;\n    }\nprivate:\n    static constexpr\
    \ int b = [] {\n        if constexpr (N <= 1) return 3;\n        int l = 1, r\
    \ = N;\n        while (r - l > 1) {\n            int m = (l + r) / 2;\n      \
    \      (m <= N / m ? l : r) = m;\n        }\n        return r;\n    }();\n   \
    \ static constexpr int w = (N + b - 1) / b + 1;\n    static constexpr int s =\
    \ (w - 1) * b;\n    vector<mint> table, p2, g;\n    static mint sub(int n, int\
    \ l, int r) {\n        if (l >= r) return 0;\n        const auto &finv = container<mint>::finv;\n\
    \        i128 sum = 0;\n        for (int i = l; i < r; i++) sum += (i128)finv[i].val()\
    \ * finv[n - i].val();\n        return container<mint>::fac[n] * sum;\n    }\n\
    \    static constexpr int id(int i, int j) { return i * w + j; }\n};\n\n} // namespace\
    \ combination\n#line 5 \"test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int T;\n    cin >>\
    \ T;\n    combination::prefix_binomial_sum<mint, 200000> C;\n    for (int N, K;\
    \ T--; ) {\n        cin >> N >> K;\n        cout << C.get(N, K).val() << '\\n';\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/prefix_sum_of_binomial_coefficient\"\
    \n\n#include \"../../../src/modint/modint.hpp\"\n#include \"../../../src/math/enumerative_combinatorics/prefix_binomial_sum.hpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int T;\n    cin >>\
    \ T;\n    combination::prefix_binomial_sum<mint, 200000> C;\n    for (int N, K;\
    \ T--; ) {\n        cin >> N >> K;\n        cout << C.get(N, K).val() << '\\n';\n\
    \    }\n}\n"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/enumerative_combinatorics/prefix_binomial_sum.hpp
  - src/math/enumerative_combinatorics/combination.hpp
  isVerificationFile: true
  path: test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:38:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp
- /verify/test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp.html
title: test/math/enumerative_combinatorics/prefix_binomial_sum.test.cpp
---
