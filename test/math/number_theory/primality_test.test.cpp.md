---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/math/number_theory/prime.hpp
    title: Prime
  - icon: ':question:'
    path: src/random/xor_shift.hpp
    title: Xor Shift
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/primality_test
    links:
    - https://judge.yosupo.jp/problem/primality_test
  bundledCode: "#line 1 \"test/math/number_theory/primality_test.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#line 2 \"src/math/number_theory/prime.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <cstdint>\n\
    #include <iterator>\n#include <numeric>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n#line 4 \"src/random/xor_shift.hpp\"\nusing namespace std;\n\
    \ntemplate<typename T>\nstruct xor_shift {\n    using U = typename make_unsigned<T>::type;\n\
    \    constexpr xor_shift(U seed = 0) : x(seed == 0 ? 987139873 : seed) {}\n  \
    \  constexpr U operator()() {\n        if constexpr (sizeof(T) <= 4) {\n     \
    \       x ^= x << 13;\n            x ^= x >> 17;\n            x ^= x << 5;\n \
    \       } else {\n            x ^= x << 13;\n            x ^= x >> 7;\n      \
    \      x ^= x << 17;\n        }\n        return x;\n    }\n    constexpr T operator()(T\
    \ lo, T hi) {\n        return lo + (*this)() % (hi - lo + 1);\n    }\nprivate:\n\
    \    U x;\n};\n#line 12 \"src/math/number_theory/prime.hpp\"\n\nusing namespace\
    \ std;\n\nnamespace prime {\n\ntemplate<typename T>\nstruct montgomery_modint\
    \ {\n    using U = conditional_t<(sizeof(T) <= 4), uint32_t, uint64_t>;\n    using\
    \ W = conditional_t<(sizeof(T) <= 4), uint64_t, unsigned __int128>;\n    constexpr\
    \ explicit montgomery_modint(U _mod, U v = 0) {\n        mod = _mod;\n       \
    \ inv = get_inv_mod(mod);\n        r2 = get_r2(mod);\n        x = reduce(W(v %\
    \ mod) * r2);\n    }\n    constexpr U modulus() const { return mod; }\n    constexpr\
    \ U val() const { return reduce(x); }\n    constexpr U raw() const { return x;\
    \ }\n    constexpr montgomery_modint make(U value) const {\n        montgomery_modint\
    \ res = *this;\n        res.x = reduce(W(value % mod) * r2);\n        return res;\n\
    \    }\n    constexpr montgomery_modint& operator+=(const montgomery_modint& r)\
    \ {\n        assert(mod == r.mod);\n        x = x >= mod - r.x ? x - (mod - r.x)\
    \ : x + r.x;\n        return *this;\n    }\n    constexpr montgomery_modint& operator-=(const\
    \ montgomery_modint& r) {\n        assert(mod == r.mod);\n        x = x >= r.x\
    \ ? x - r.x : mod - (r.x - x);\n        return *this;\n    }\n    constexpr montgomery_modint&\
    \ operator*=(const montgomery_modint& r) {\n        assert(mod == r.mod);\n  \
    \      x = reduce(W(x) * r.x);\n        return *this;\n    }\n    friend constexpr\
    \ montgomery_modint operator+(montgomery_modint l, const montgomery_modint& r)\
    \ { return l += r; }\n    friend constexpr montgomery_modint operator-(montgomery_modint\
    \ l, const montgomery_modint& r) { return l -= r; }\n    friend constexpr montgomery_modint\
    \ operator*(montgomery_modint l, const montgomery_modint& r) { return l *= r;\
    \ }\n    friend constexpr bool operator==(const montgomery_modint& l, const montgomery_modint&\
    \ r) {\n        assert(l.mod == r.mod);\n        return l.x == r.x;\n    }\n \
    \   constexpr montgomery_modint pow(U k) const {\n        montgomery_modint a\
    \ = *this, res = make(1);\n        while (k) {\n            if (k & 1) res *=\
    \ a;\n            a *= a;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\nprivate:\n    static constexpr int bits = sizeof(U) * 8;\n    U mod, inv,\
    \ r2, x;\n    static constexpr U get_inv_mod(U mod) {\n        U inv = 1;\n  \
    \      for (int i = 0; i < (bits == 32 ? 5 : 6); ++i) inv *= 2 - mod * inv;\n\
    \        return -inv;\n    }\n    static constexpr U get_r2(U mod) {\n       \
    \ const U r = U((W(1) << bits) % mod);\n        return U(W(r) * r % mod);\n  \
    \  }\n    constexpr U reduce(W x) const {\n        const U q = U(x) * inv;\n \
    \       const W sum = x + W(q) * mod;\n        W res = sum >> bits;\n        if\
    \ constexpr (is_unsigned_v<T>) {\n            if (sum < x) res += W(1) << bits;\n\
    \        }\n        return U(res >= mod ? res - mod : res);\n    }\n};\n\ntemplate<typename\
    \ T>\nconstexpr bool is_prime(T n) {\n    using U = typename montgomery_modint<T>::U;\n\
    \    if (n <= 1) return false;\n    if (n == 2) return true;\n    if ((n & 1)\
    \ == 0) return false;\n    using mint = montgomery_modint<T>;\n    mint p{U(n)};\n\
    \    const mint one = p.make(1), neg1 = p.make(U(n - 1));\n    auto miller_rabin\
    \ = [&] (const auto& ps) constexpr -> bool {\n        U d = p.modulus() - 1;\n\
    \        int s = 0;\n        while ((d & 1) == 0) {\n            d >>= 1;\n  \
    \          ++s;\n        }\n        for (int m : ps) {\n            const U a\
    \ = U(m) % p.modulus();\n            if (a == 0) continue;\n            mint x\
    \ = p.make(a);\n            x = x.pow(d);\n            if (x == one || x == neg1)\
    \ continue;\n            bool f = false;\n            for (int i = 1; i < s; ++i)\
    \ {\n                x *= x;\n                if (x == neg1) {\n             \
    \       f = true;\n                    break;\n                }\n           \
    \ }\n            if (!f) return false;\n        }\n        return true;\n    };\n\
    \    if constexpr (sizeof(T) <= 4) {\n        return miller_rabin(array<int, 3>{2,\
    \ 7, 61});\n    } else {\n        if (n < 4759123141LL) return miller_rabin(array<int,\
    \ 3>{2, 7, 61});\n        return miller_rabin(array<int, 7>{2, 325, 9375, 28178,\
    \ 450775, 9780504, 1795265022});\n    }\n}\n\ntemplate<typename T>\nconstexpr\
    \ vector<T> prime_factor(T n) {\n    using U = typename montgomery_modint<T>::U;\n\
    \    if (n <= 1) return {};\n    if (is_prime(n)) return {n};\n    auto rho =\
    \ [] (T n) constexpr -> T {\n        for (int p : {2, 3, 5, 7}) {\n          \
    \  if (n % p == 0) return T(p);\n        }\n        using mint = montgomery_modint<T>;\n\
    \        mint p{U(n)};\n        xor_shift<T> eng(n);\n        while (true) {\n\
    \            mint u = p.make(U(eng(2, n - 1)));\n            mint v = u;\n   \
    \         mint c = p.make(U(eng(1, n - 1)));\n            U d = 1;\n         \
    \   while (d == 1) {\n                u = u * u - c;\n                v = v *\
    \ v - c;\n                v = v * v - c;\n                U a = u.raw(), b = v.raw();\n\
    \                d = gcd(a >= b ? a - b : b - a, p.modulus());\n            }\n\
    \            if (d < p.modulus()) return T(d);\n        }\n    };\n    vector<T>\
    \ res;\n    T d = rho(n);\n    auto a = prime_factor(d);\n    auto b = prime_factor(n\
    \ / d);\n    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));\n\
    \    res.erase(unique(res.begin(), res.end()), res.end());\n    return res;\n\
    }\n\ntemplate<typename T>\nconstexpr vector<pair<T, int>> factorise(T n) {\n \
    \   auto ps = prime_factor(n);\n    vector<pair<T, int>> res;\n    res.reserve(ps.size());\n\
    \    for (auto p : ps) {\n        res.emplace_back(p, 0);\n        while (n %\
    \ p == 0) {\n            res.back().second++;\n            n /= p;\n        }\n\
    \    }\n    return res;\n}\n\ntemplate<typename T>\nconstexpr T primitive_root(T\
    \ m) {\n    using U = typename montgomery_modint<T>::U;\n    assert(is_prime(m));\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    if (m == 1224736769) return 3;\n    auto ps = prime_factor(m - 1);\n\
    \    using mint = montgomery_modint<T>;\n    mint mt{U(m)};\n    const mint one\
    \ = mt.make(1);\n    xor_shift<U> eng(m);\n    U a = eng(1, mt.modulus() - 1);\n\
    \    while ([&] {\n        mint x = mt.make(a);\n        for (auto p : ps) {\n\
    \            if (x.pow((mt.modulus() - 1) / U(p)) == one) return true;\n     \
    \   }\n        return false;\n    } ()) a = eng(1, mt.modulus() - 1);\n    return\
    \ T(a);\n}\n\ntemplate<typename T>\nvector<T> enumerate_divisors(T m) {\n    assert(m\
    \ > 0);\n    auto f = factorise(m);\n    int n = f.size();\n    vector<T> res;\n\
    \    auto rec = [&] (const auto &rec, int i, T x) -> void {\n        if (i ==\
    \ n) {\n            res.push_back(x);\n            return;\n        }\n      \
    \  auto [p, k] = f[i];\n        for (int j = 0; j <= k; j++) {\n            rec(rec,\
    \ i + 1, x);\n            if (j < k) x *= p;\n        }\n    };\n    rec(rec,\
    \ 0, 1);\n    sort(res.begin(), res.end());\n    return res;\n}\n\n\n} // namespace\
    \ prime\n#line 4 \"test/math/number_theory/primality_test.test.cpp\"\n\n#include\
    \ <iostream>\n\nstatic_assert(prime::is_prime<int>(2147483647));\nstatic_assert(!prime::is_prime<unsigned>(3215031751U));\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ Q;\n    cin >> Q;\n    for (long long N; Q--; ) {\n        cin >> N;\n     \
    \   cout << (prime::is_prime<long long>(N) ? \"Yes\\n\" : \"No\\n\");\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/primality_test\"\n\n#include\
    \ \"../../../src/math/number_theory/prime.hpp\"\n\n#include <iostream>\n\nstatic_assert(prime::is_prime<int>(2147483647));\n\
    static_assert(!prime::is_prime<unsigned>(3215031751U));\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int Q;\n    cin >> Q;\n    for (long long N; Q--;\
    \ ) {\n        cin >> N;\n        cout << (prime::is_prime<long long>(N) ? \"\
    Yes\\n\" : \"No\\n\");\n    }\n}\n"
  dependsOn:
  - src/math/number_theory/prime.hpp
  - src/random/xor_shift.hpp
  isVerificationFile: true
  path: test/math/number_theory/primality_test.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/number_theory/primality_test.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/primality_test.test.cpp
- /verify/test/math/number_theory/primality_test.test.cpp.html
title: test/math/number_theory/primality_test.test.cpp
---
