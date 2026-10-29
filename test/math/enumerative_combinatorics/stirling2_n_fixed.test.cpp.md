---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/convolution/ntt.hpp
    title: src/convolution/ntt.hpp
  - icon: ':question:'
    path: src/fps/fps.hpp
    title: Formal Power Series
  - icon: ':question:'
    path: src/math/enumerative_combinatorics/combination.hpp
    title: src/math/enumerative_combinatorics/combination.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/enumerative_combinatorics/stirling2_n_fixed.hpp
    title: src/math/enumerative_combinatorics/stirling2_n_fixed.hpp
  - icon: ':question:'
    path: src/math/number_theory/prime.hpp
    title: Prime
  - icon: ':question:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
  bundledCode: "#line 1 \"test/math/enumerative_combinatorics/stirling2_n_fixed.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
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
    \    unsigned int x;\n};\n#line 2 \"src/math/enumerative_combinatorics/stirling2_n_fixed.hpp\"\
    \n#include <vector>\n#line 4 \"src/math/enumerative_combinatorics/combination.hpp\"\
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
    \ + m, n);\n}\n\n} // namespace combination\n#line 3 \"src/math/number_theory/prime.hpp\"\
    \n#include <array>\n#line 5 \"src/math/number_theory/prime.hpp\"\n#include <cstdint>\n\
    #include <iterator>\n#include <numeric>\n#include <type_traits>\n#include <utility>\n\
    #line 4 \"src/random/xor_shift.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T>\nstruct xor_shift {\n    using U = typename make_unsigned<T>::type;\n   \
    \ constexpr xor_shift(U seed = 0) : x(seed == 0 ? 987139873 : seed) {}\n    constexpr\
    \ U operator()() {\n        if constexpr (sizeof(T) <= 4) {\n            x ^=\
    \ x << 13;\n            x ^= x >> 17;\n            x ^= x << 5;\n        } else\
    \ {\n            x ^= x << 13;\n            x ^= x >> 7;\n            x ^= x <<\
    \ 17;\n        }\n        return x;\n    }\n    constexpr T operator()(T lo, T\
    \ hi) {\n        return lo + (*this)() % (hi - lo + 1);\n    }\nprivate:\n   \
    \ U x;\n};\n#line 12 \"src/math/number_theory/prime.hpp\"\n\nusing namespace std;\n\
    \nnamespace prime {\n\ntemplate<typename T>\nstruct montgomery_modint {\n    using\
    \ U = conditional_t<(sizeof(T) <= 4), uint32_t, uint64_t>;\n    using W = conditional_t<(sizeof(T)\
    \ <= 4), uint64_t, unsigned __int128>;\n    constexpr explicit montgomery_modint(U\
    \ _mod, U v = 0) {\n        mod = _mod;\n        inv = get_inv_mod(mod);\n   \
    \     r2 = get_r2(mod);\n        x = reduce(W(v % mod) * r2);\n    }\n    constexpr\
    \ U modulus() const { return mod; }\n    constexpr U val() const { return reduce(x);\
    \ }\n    constexpr U raw() const { return x; }\n    constexpr montgomery_modint\
    \ make(U value) const {\n        montgomery_modint res = *this;\n        res.x\
    \ = reduce(W(value % mod) * r2);\n        return res;\n    }\n    constexpr montgomery_modint&\
    \ operator+=(const montgomery_modint& r) {\n        assert(mod == r.mod);\n  \
    \      x = x >= mod - r.x ? x - (mod - r.x) : x + r.x;\n        return *this;\n\
    \    }\n    constexpr montgomery_modint& operator-=(const montgomery_modint& r)\
    \ {\n        assert(mod == r.mod);\n        x = x >= r.x ? x - r.x : mod - (r.x\
    \ - x);\n        return *this;\n    }\n    constexpr montgomery_modint& operator*=(const\
    \ montgomery_modint& r) {\n        assert(mod == r.mod);\n        x = reduce(W(x)\
    \ * r.x);\n        return *this;\n    }\n    friend constexpr montgomery_modint\
    \ operator+(montgomery_modint l, const montgomery_modint& r) { return l += r;\
    \ }\n    friend constexpr montgomery_modint operator-(montgomery_modint l, const\
    \ montgomery_modint& r) { return l -= r; }\n    friend constexpr montgomery_modint\
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
    \ prime\n#line 4 \"src/convolution/ntt.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ mint>\nstruct Number_Theoretic_Transform {\n    static mint get_root() {\n \
    \       init();\n        return root;\n    }\n    template<typename Vector>\n\
    \    static void ntt(Vector &f) {\n        init();\n        int n = f.size();\n\
    \        assert((n & (n - 1)) == 0);\n        int h = 0;\n        while ((1 <<\
    \ h) < n) h++;\n        int len = 0;\n        while (len < h) {\n            if\
    \ (len == h - 1) {\n                int p = 1 << (h - len - 1);\n            \
    \    mint r = 1;\n                for (int s = 0; s < 1 << len; s++) {\n     \
    \               int j = s << (h - len);\n                    for (int i = 0; i\
    \ < p; i++) {\n                        mint a = f[i + j], b = f[i + j + p] * r;\n\
    \                        f[i + j] = a + b;\n                        f[i + j +\
    \ p] = a - b;\n                    }\n                    if (s + 1 != (1 << len))\
    \ {\n                        r *= rt2[__builtin_ctz(~s)];\n                  \
    \  }\n                }\n                len++;\n            } else {\n      \
    \          int p = 1 << (h - len - 2);\n                mint r = 1, imag = dw[2];\n\
    \                for (int s = 0; s < 1 << len; s++) {\n                    mint\
    \ r2 = r * r;\n                    mint r3 = r * r2;\n                    int\
    \ j = s << (h - len);\n                    for (int i = 0; i < p; i++) {\n   \
    \                     unsigned long long m2 = (unsigned long long)mod * mod;\n\
    \                        unsigned long long a0 = (unsigned long long)f[i + j].val();\n\
    \                        unsigned long long a1 = (unsigned long long)f[i + j +\
    \ p].val() * r.val();\n                        unsigned long long a2 = (unsigned\
    \ long long)f[i + j + p + p].val() * r2.val();\n                        unsigned\
    \ long long a3 = (unsigned long long)f[i + j + p + p + p].val() * r3.val();\n\
    \                        unsigned long long t0 = (unsigned long long)mint(m2 +\
    \ a1 - a3).val() * imag.val();\n                        unsigned long long t1\
    \ = m2 - a2;\n                        f[i + j] = a0 + a1 + a2 + a3;\n        \
    \                f[i + j + p] = a0 + a2 + (m2 + m2 - a1 - a3);\n             \
    \           f[i + j + p + p] = a0 + t0 + t1;\n                        f[i + j\
    \ + p + p + p] = a0 + t1 + (m2 - t0);\n                    }\n               \
    \     if (s + 1 != (1 << len)) {\n                        r *= rt3[__builtin_ctz(~s)];\n\
    \                    }\n                }\n                len += 2;\n       \
    \     }\n        }\n    }\n    template<typename Vector>\n    static void intt(Vector\
    \ &f) {\n        init();\n        int n = f.size();\n        assert((n & (n -\
    \ 1)) == 0);\n        int h = 0;\n        while ((1 << h) < n) h++;\n        int\
    \ len = h;\n        while (len > 0) {\n            if (len == 1) {\n         \
    \       len--;\n                int p = 1 << (h - len - 1);\n                mint\
    \ ir = 1;\n                for (int s = 0; s < 1 << len; s++) {\n            \
    \        int j = s << (h - len);\n                    for (int i = 0; i < p; i++)\
    \ {\n                        mint a = f[i + j], b = f[i + j + p];\n          \
    \              f[i + j] = a + b;\n                        f[i + j + p] = (a -\
    \ b) * ir;\n                    }\n                    if (s + 1 != (1 << len))\
    \ {\n                        ir *= irt2[__builtin_ctz(~s)];\n                \
    \    }\n                }\n            } else {\n                len -= 2;\n \
    \               int p = 1 << (h - len - 2);\n                mint ir = 1, iimag\
    \ = idw[2];\n                for (int s = 0; s < 1 << len; s++) {\n          \
    \          mint ir2 = ir * ir;\n                    mint ir3 = ir * ir2;\n   \
    \                 int j = s << (h - len);\n                    for (int i = 0;\
    \ i < p; i++) {\n                        unsigned long long a0 = (unsigned long\
    \ long)f[i + j].val();\n                        unsigned long long a1 = (unsigned\
    \ long long)f[i + j + p].val();\n                        unsigned long long a2\
    \ = (unsigned long long)f[i + j + p + p].val();\n                        unsigned\
    \ long long a3 = (unsigned long long)f[i + j + p + p + p].val();\n           \
    \             unsigned long long t0 = (unsigned long long)(mint(mod + a2 - a3)\
    \ * iimag).val();\n                        f[i + j] = a0 + a1 + a2 + a3;\n   \
    \                     f[i + j + p] = (mod + a0 - a1 + t0) * ir.val();\n      \
    \                  f[i + j + p + p] = (mod + mod + a0 + a1 - a2 - a3) * ir2.val();\n\
    \                        f[i + j + p + p + p] = (mod + mod + a0 - a1 - t0) * ir3.val();\n\
    \                    }\n                    if (s + 1 != (1 << len)) {\n     \
    \                   ir *= irt3[__builtin_ctz(~s)];\n                    }\n  \
    \              }\n            }\n        }\n        const mint invn = mint::raw(n).inv();\n\
    \        for (auto &e : f) e *= invn;\n    }\n    // f must be ntt-ed\n    template<typename\
    \ Vector>\n    static void doubling(Vector &f) {\n        init();\n        int\
    \ n = f.size();\n        if (n == 0) return;\n        assert((n & (n - 1)) ==\
    \ 0);\n        auto g = f;\n        intt(g);\n        mint w = root.pow((mint::mod()\
    \ - 1) / (2 * n)), pw = mint::raw(1);\n        for (int i = 0; i < n; i++) g[i]\
    \ *= pw, pw *= w;\n        ntt(g);\n        f.resize(2 * n);\n        for (int\
    \ i = 0; i < n; i++) f[i + n] = g[i];\n    }\nprivate:\n    Number_Theoretic_Transform()\
    \ = default;\n    static int log, mod;\n    static mint root;\n    static vector<mint>\
    \ dw, idw;\n    static vector<mint> rt2, irt2;\n    static vector<mint> rt3, irt3;\n\
    \    static void init() {\n        if (mod != -1) return;\n        mod = mint::mod();\n\
    \        root = prime::primitive_root<int>(mod);\n        while (!((mod - 1) >>\
    \ log & 1)) log++;\n        dw = idw = rt2 = irt2 = rt3 = irt3 = vector<mint>(log\
    \ + 1);\n        dw[log] = root.pow((mod - 1) >> log);\n        idw[log] = dw[log].inv();\n\
    \        for (int i = log - 1; i >= 0; i--) {\n            dw[i] = dw[i + 1] *\
    \ dw[i + 1];\n            idw[i] = idw[i + 1] * idw[i + 1];\n        }\n     \
    \   mint pd = 1, ipd = 1;\n        for (int i = 0; i < log - 1; i++) {\n     \
    \       rt2[i] = pd * dw[i + 2];\n            irt2[i] = ipd * idw[i + 2];\n  \
    \          pd *= idw[i + 2];\n            ipd *= dw[i + 2];\n        }\n     \
    \   pd = ipd = 1;\n        for (int i = 0; i < log - 2; i++) {\n            rt3[i]\
    \ = pd * dw[i + 3];\n            irt3[i] = ipd * idw[i + 3];\n            pd *=\
    \ idw[i + 3];\n            ipd *= dw[i + 3];\n        }\n    }\n};\ntemplate<typename\
    \ mint>\nint Number_Theoretic_Transform<mint>::log = 0;\ntemplate<typename mint>\n\
    int Number_Theoretic_Transform<mint>::mod = -1;\ntemplate<typename mint>\nmint\
    \ Number_Theoretic_Transform<mint>::root = -1;\ntemplate<typename mint>\nvector<mint>\
    \ Number_Theoretic_Transform<mint>::dw = vector<mint>();\ntemplate<typename mint>\n\
    vector<mint> Number_Theoretic_Transform<mint>::idw = vector<mint>();\ntemplate<typename\
    \ mint>\nvector<mint> Number_Theoretic_Transform<mint>::rt2 = vector<mint>();\n\
    template<typename mint>\nvector<mint> Number_Theoretic_Transform<mint>::irt2 =\
    \ vector<mint>();\ntemplate<typename mint>\nvector<mint> Number_Theoretic_Transform<mint>::rt3\
    \ = vector<mint>();\ntemplate<typename mint>\nvector<mint> Number_Theoretic_Transform<mint>::irt3\
    \ = vector<mint>();\n#line 5 \"src/fps/fps.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ mint>\nstruct fps : vector<mint> {\n    using vector<mint>::vector;\n    using\
    \ NTT = Number_Theoretic_Transform<mint>;\n    void ntt() { NTT::ntt(*this); }\n\
    \    void intt() { NTT::intt(*this); }\n    fps(const vector<mint> &v) : vector<mint>(v)\
    \ {}\n    fps &operator+=(const mint &r) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += r;\n        return *this;\n    }\n    fps &operator-=(const\
    \ mint &r) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= r;\n        return *this;\n    }\n    fps &operator*=(const mint &r) {\n\
    \        for (mint &x : *this) x *= r;\n        return *this;\n    }\n    fps\
    \ &operator/=(const mint &r) {\n        mint invr = r.inv();\n        return *this\
    \ *= invr;\n    }\n    fps &operator+=(const fps &f) {\n        int n = this->size(),\
    \ m = f.size();\n        if (n < m) this->resize(m);\n        for (int i = 0;\
    \ i < m; i++) (*this)[i] += f[i];\n        return *this;\n    }\n    fps &operator-=(const\
    \ fps &f) {\n        int n = this->size(), m = f.size();\n        if (n < m) this->resize(m);\n\
    \        for (int i = 0; i < m; i++) (*this)[i] -= f[i];\n        return *this;\n\
    \    }\n    fps &operator*=(fps f) {\n        int n = this->size(), m = f.size();\n\
    \        if (n == 0 || m == 0) {\n            this->clear();\n            return\
    \ *this;\n        }\n        if (n <= 63 || m <= 63) {\n            if (n > m)\
    \ {\n                this->swap(f);\n                swap(n, m);\n           \
    \ }\n            fps g(n + m - 1);\n            for (int i = 0; i < n; i++) {\n\
    \                for (int j = 0; j < m; j++) g[i + j] += (*this)[i] * f[j];\n\
    \            }\n            this->swap(g);\n            return *this;\n      \
    \  }\n        int sz = 1;\n        while (sz < n + m - 1) sz <<= 1;\n        this->resize(sz);\n\
    \        this->ntt();\n        f.resize(sz);\n        f.ntt();\n        for (int\
    \ i = 0; i < sz; i++) (*this)[i] *= f[i];\n        this->intt();\n        this->resize(n\
    \ + m - 1);\n        return *this;\n    }\n    fps &operator/=(const fps &f) {\n\
    \        return *this *= f.inv();\n    }\n    fps &operator%=(const fps &f) {\n\
    \        *this -= div(f) * f;\n        this->shrink();\n        return *this;\n\
    \    }\n    fps div(const fps &f) const {\n        if (this->size() < f.size())\
    \ return fps{};\n        int n = this->size() - f.size() + 1;\n        return\
    \ (rev().pre(n) * f.rev().inv(n)).pre(n).rev(n);\n    }\n    fps operator+(const\
    \ mint &r) const { return fps(*this) += r; }\n    fps operator-(const mint &r)\
    \ const { return fps(*this) -= r; }\n    fps operator*(const mint &r) const {\
    \ return fps(*this) *= r; }\n    fps operator/(const mint &r) const { return fps(*this)\
    \ /= r; }\n    friend fps operator+(const mint &r, const fps &f) { return f +\
    \ r; }\n    friend fps operator-(const mint &r, const fps &f) { return (-f) +\
    \ r; }\n    friend fps operator*(const mint &r, const fps &f) { return f * r;\
    \ }\n    fps operator+(const fps &f) const { return fps(*this) += f; }\n    fps\
    \ operator-(const fps &f) const { return fps(*this) -= f; }\n    fps operator*(const\
    \ fps &f) const { return fps(*this) *= f; }\n    fps operator/(const fps &f) const\
    \ { return fps(*this) /= f; }\n    fps operator%(const fps &f) const { return\
    \ fps(*this) %= f; }\n    fps operator-() const {\n        return fps{} - *this;\n\
    \    }\n    fps operator<<(int n) const {\n        fps res(*this);\n        res.insert(res.begin(),\
    \ n, mint());\n        return res;\n    }\n    fps operator>>(int n) const {\n\
    \        if (int(this->size()) <= n) return fps{};\n        fps res(*this);\n\
    \        res.erase(res.begin(), res.begin() + n);\n        return res;\n    }\n\
    \    fps &operator<<=(int n) {\n        return *this = (*this) << n;\n    }\n\
    \    fps &operator>>=(int n) {\n        return *this = (*this) >> n;\n    }\n\
    \    fps pre(int n) const {\n        n = min(n, int(this->size()));\n        return\
    \ fps(this->begin(), this->begin() + n);\n    }\n    fps rev(int deg = -1) const\
    \ {\n        fps res(*this);\n        if (deg != -1) res.resize(deg, 0);\n   \
    \     reverse(res.begin(), res.end());\n        return res;\n    }\n    fps dot(const\
    \ fps &f) const {\n        int n = min(this->size(), f.size());\n        fps res(n);\n\
    \        for (int i = 0; i < n; i++) res[i] = (*this)[i] * f[i];\n        return\
    \ res;\n    }\n    void shrink() {\n        while (this->size() && this->back()\
    \ == 0) {\n            this->pop_back();\n        }\n    }\n    mint operator()(const\
    \ mint &x) const {\n        mint res = 0, powx = 1;\n        for (const mint &a\
    \ : *this) {\n            res += a * powx;\n            powx *= x;\n        }\n\
    \        return res;\n    }\n    fps diff() const {\n        int n = this->size();\n\
    \        if (n == 0) return fps{};\n        fps res(n - 1);\n        for (int\
    \ i = 1; i < n; i++) {\n            res[i - 1] = i * (*this)[i];\n        }\n\
    \        return res;\n    }\n    fps integral() const {\n        int n = this->size();\n\
    \        fps res(n + 1);\n        res[0] = 0;\n        for (int i = 0; i < n;\
    \ i++) {\n            res[i + 1] = (*this)[i] * combination::mod_inv<mint>(i +\
    \ 1);\n        }\n        return res;\n    }\n    fps inv(int deg = -1) const;\n\
    \    fps exp(int deg = -1) const;\n    fps log(int deg = -1) const;\n    fps pow(long\
    \ long k, int deg = -1) const;\n    fps operator()(fps f, int deg = -1) const;\n\
    \    fps compositional_inverse(int deg = -1) const;\n    fps taylor_shift(mint\
    \ c) const;\n};\n#line 4 \"src/math/enumerative_combinatorics/stirling2_n_fixed.hpp\"\
    \nusing namespace std;\n\ntemplate<typename mint>\nvector<mint> stirling2(int\
    \ n) {\n    fps<mint> f(n + 1), g(n + 1);\n    int sgn = 1;\n    for (int i =\
    \ 0; i <= n; i++) {\n        f[i] = combination::finv<mint>(i) * sgn;\n      \
    \  g[i] = combination::finv<mint>(i) * mint::raw(i).pow(n);\n        sgn *= -1;\n\
    \    }\n    return (f * g).pre(n + 1);\n}\n#line 5 \"test/math/enumerative_combinatorics/stirling2_n_fixed.test.cpp\"\
    \n\n#include <iostream>\n\nusing mint = modint<998244353>;\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin >>\
    \ N;\n    auto S2 = stirling2<mint>(N);\n    for (int i = 0; i <= N; i++) {\n\
    \        cout << S2[i].val() << \" \\n\"[i == N];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n#include \"../../../src/modint/modint.hpp\"\n#include \"../../../src/math/enumerative_combinatorics/stirling2_n_fixed.hpp\"\
    \n\n#include <iostream>\n\nusing mint = modint<998244353>;\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin >>\
    \ N;\n    auto S2 = stirling2<mint>(N);\n    for (int i = 0; i <= N; i++) {\n\
    \        cout << S2[i].val() << \" \\n\"[i == N];\n    }\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/enumerative_combinatorics/stirling2_n_fixed.hpp
  - src/fps/fps.hpp
  - src/math/enumerative_combinatorics/combination.hpp
  - src/convolution/ntt.hpp
  - src/math/number_theory/prime.hpp
  - src/random/xor_shift.hpp
  isVerificationFile: true
  path: test/math/enumerative_combinatorics/stirling2_n_fixed.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:38:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/enumerative_combinatorics/stirling2_n_fixed.test.cpp
layout: document
redirect_from:
- /verify/test/math/enumerative_combinatorics/stirling2_n_fixed.test.cpp
- /verify/test/math/enumerative_combinatorics/stirling2_n_fixed.test.cpp.html
title: test/math/enumerative_combinatorics/stirling2_n_fixed.test.cpp
---
