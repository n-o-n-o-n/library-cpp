---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/number_theory/discrete_logarithm.hpp
    title: src/math/number_theory/discrete_logarithm.hpp
  - icon: ':question:'
    path: src/math/number_theory/prime.hpp
    title: Prime
  - icon: ':heavy_check_mark:'
    path: src/modint/dynamic_modint.hpp
    title: src/modint/dynamic_modint.hpp
  - icon: ':question:'
    path: src/random/utility.hpp
    title: Random Utility
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc270/submissions/62690414
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/math/number_theory/discrete_logarithm.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"src/random/utility.hpp\"\
    \n#include <cassert>\n#include <concepts>\n#include <random>\nusing namespace\
    \ std;\n\nnamespace rng {\n\ninline random_device seed;\ninline mt19937 eng(seed());\n\
    \ntemplate<typename T>\nvoid set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\n\
    template<integral T>\ninline T randint(T lo, T hi) {\n    assert(lo <= hi);\n\
    \    uniform_int_distribution<T> dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral\
    \ T>\ninline pair<T, T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo\
    \ + strict <= hi);\n    T l = randint(lo, hi - strict);\n    T r = randint(l +\
    \ strict, hi);\n    return make_pair(l, r);\n}\n\n} // namespace rng\n#line 2\
    \ \"src/math/number_theory/prime.hpp\"\n#include <algorithm>\n#include <array>\n\
    #line 5 \"src/math/number_theory/prime.hpp\"\n#include <cstdint>\n#include <iterator>\n\
    #include <numeric>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
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
    \ prime\n#line 4 \"src/modint/dynamic_modint.hpp\"\nusing namespace std;\n\nstruct\
    \ modint {\n    modint() : x(0) {}\n    modint(long long v) {\n        long long\
    \ y = v % m();\n        if (y < 0) y += m();\n        x = (unsigned int)(y);\n\
    \    }\n    static void set_mod(int _m) { MOD = _m; }\n    static modint raw(int\
    \ v) {\n        modint a;\n        a.x = v;\n        return a;\n    }\n    static\
    \ int mod() { return m(); }\n    unsigned int val() const { return x; }\n    modint&\
    \ operator++() {\n        x++;\n        if (x == m()) x = 0;\n        return *this;\n\
    \    }\n    modint& operator--() {\n        if (x == 0) x = m();\n        x--;\n\
    \        return *this;\n    }\n    modint operator++(int) {\n        modint res\
    \ = *this;\n        ++*this;\n        return res;\n    }\n    modint operator--(int)\
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
    \    static unsigned int m() { return MOD; }\n};\n#line 2 \"src/math/affine.hpp\"\
    \n\ntemplate<typename mint>\nstruct affine {\n    mint a, b;\n    affine() : a(1),\
    \ b(0) {}\n    affine(const mint &_a, const mint &_b) : a(_a), b(_b) {}\n    mint\
    \ operator()(const mint &x) const {\n        return a * x + b;\n    }\n    affine\
    \ operator()(const affine &f) const {\n        mint c = a * f.a;\n        mint\
    \ d = a * f.b + b;\n        return affine(c, d);\n    }\n};\n#line 2 \"src/math/number_theory/discrete_logarithm.hpp\"\
    \n#include <unordered_set>\nusing namespace std;\n\ntemplate<typename ActSet>\n\
    struct discrete_logarithm {\n    using S = typename ActSet::S;\n    using F =\
    \ typename ActSet::F;\n    template<typename H>\n    static long long solve(F\
    \ f, S s, S t, long long p, const H &h) {\n        long long ht = h(t);\n    \
    \    long long m = 1;\n        do {\n            m++;\n        } while (m * m\
    \ <= p);\n        unordered_set<long long> a;\n        a.reserve(m);\n       \
    \ for (int k = 0; k < m; k++) {\n            t = ActSet::mapping(f, t);\n    \
    \        a.insert(h(t));\n        }\n        F g = ActSet::id();\n        {\n\
    \            long long mm = m;\n            F ff = f;\n            while (m >\
    \ 0) {\n                if (m & 1) g = ActSet::comp(g, f);\n                f\
    \ = ActSet::comp(f, f);\n                m >>= 1;\n            }\n           \
    \ m = mm;\n            f = ff;\n        }\n        for (int k = 0, flag = 0; k\
    \ <= m; k++) {\n            t = ActSet::mapping(g, s);\n            if (a.count(h(t)))\
    \ {\n                for (int i = 0; i < m; i++) {\n                    if (h(s)\
    \ == ht) {\n                        return m * k + i;\n                    }\n\
    \                    s = ActSet::mapping(f, s);\n                }\n         \
    \       if (flag) return -1;\n                flag = 1;\n            }\n     \
    \       s = t;\n        }\n        return -1;\n    }\n};\n#line 8 \"test/math/number_theory/discrete_logarithm.test.cpp\"\
    \n\nusing mint = modint;\n\n#include <iostream>\n\n// https://atcoder.jp/contests/abc270/submissions/62690414\n\
    namespace AC {\n\ntemplate<typename mint>\nstruct affine {\n    mint a, b;\n \
    \   affine() : a(1), b(0) {}\n    affine(const mint &_a, const mint &_b) : a(_a),\
    \ b(_b) {}\n    mint operator()(const mint &x) const {\n        return a * x +\
    \ b;\n    }\n    affine operator()(const affine &f) const {\n        mint c =\
    \ a * f.a;\n        mint d = a * f.b + b;\n        return affine(c, d);\n    }\n\
    };\n\ntemplate<typename ActSet>\nstruct discrete_logarithm {\n    using S = typename\
    \ ActSet::S;\n    using F = typename ActSet::F;\n    template<typename H>\n  \
    \  static long long solve(F f, S s, S t, long long p, const H &h) {\n        long\
    \ long ht = h(t);\n        long long m = 1;\n        do {\n            m++;\n\
    \        } while (m * m <= p);\n        unordered_set<long long> a;\n        a.reserve(m);\n\
    \        for (int k = 0; k < m; k++) {\n            t = ActSet::mapping(f, t);\n\
    \            a.insert(h(t));\n        }\n        F g = ActSet::id();\n       \
    \ {\n            long long mm = m;\n            F ff = f;\n            while (m\
    \ > 0) {\n                if (m & 1) g = ActSet::comp(g, f);\n               \
    \ f = ActSet::comp(f, f);\n                m >>= 1;\n            }\n         \
    \   m = mm;\n            f = ff;\n        }\n        for (int k = 0, flag = 0;\
    \ k <= m; k++) {\n            t = ActSet::mapping(g, s);\n            if (a.count(h(t)))\
    \ {\n                for (int i = 0; i < m; i++) {\n                    if (h(s)\
    \ == ht) {\n                        return m * k + i;\n                    }\n\
    \                    s = ActSet::mapping(f, s);\n                }\n         \
    \       if (flag) return -1;\n                flag = 1;\n            }\n     \
    \       s = t;\n        }\n        return -1;\n    }\n};\n\nstruct ActSet {\n\
    \    using S = mint;\n    using F = affine<mint>;\n    static F comp(F f, F g)\
    \ {\n        return f(g);\n    }\n    static F id() {\n        return F();\n \
    \   }\n    static S mapping(F f, S x) {\n        return f(x);\n    }\n};\n\nlong\
    \ long solve(int P, int A, int B, int S, int T) {\n    mint::set_mod(P);\n   \
    \ return discrete_logarithm<ActSet>::solve(affine<mint>(A, B), S, T, P, [&](mint\
    \ x){ return x.val(); });\n}\n\n} // namespace AC\n\nstruct ActSet {\n    using\
    \ S = mint;\n    using F = affine<mint>;\n    static F comp(F f, F g) {\n    \
    \    return f(g);\n    }\n    static F id() {\n        return F();\n    }\n  \
    \  static S mapping(F f, S x) {\n        return f(x);\n    }\n};\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    {\n        int\
    \ A, B;\n        cin >> A >> B;\n        cout << A + B << '\\n';\n    }\n    for\
    \ (int t = 0; t < 200; t++) {\n        int P = rng::randint(2, (int)1e9);\n  \
    \      while (!prime::is_prime(P)) P = rng::randint(2, (int)1e9);\n        int\
    \ A = rng::randint(0, P - 1);\n        int B = rng::randint(0, P - 1);\n     \
    \   int S = rng::randint(0, P - 1);\n        int T = rng::randint(0, P - 1);\n\
    \        mint::set_mod(P);\n        auto ans = discrete_logarithm<ActSet>::solve(affine<mint>(A,\
    \ B), S, T, P, [&](mint x){ return x.val(); });\n        assert(ans == AC::solve(P,\
    \ A, B, S, T));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../src/random/utility.hpp\"\n#include \"../../../src/math/number_theory/prime.hpp\"\
    \n#include \"../../../src/modint/dynamic_modint.hpp\"\n#include \"../../../src/math/affine.hpp\"\
    \n#include \"../../../src/math/number_theory/discrete_logarithm.hpp\"\n\nusing\
    \ mint = modint;\n\n#include <iostream>\n\n// https://atcoder.jp/contests/abc270/submissions/62690414\n\
    namespace AC {\n\ntemplate<typename mint>\nstruct affine {\n    mint a, b;\n \
    \   affine() : a(1), b(0) {}\n    affine(const mint &_a, const mint &_b) : a(_a),\
    \ b(_b) {}\n    mint operator()(const mint &x) const {\n        return a * x +\
    \ b;\n    }\n    affine operator()(const affine &f) const {\n        mint c =\
    \ a * f.a;\n        mint d = a * f.b + b;\n        return affine(c, d);\n    }\n\
    };\n\ntemplate<typename ActSet>\nstruct discrete_logarithm {\n    using S = typename\
    \ ActSet::S;\n    using F = typename ActSet::F;\n    template<typename H>\n  \
    \  static long long solve(F f, S s, S t, long long p, const H &h) {\n        long\
    \ long ht = h(t);\n        long long m = 1;\n        do {\n            m++;\n\
    \        } while (m * m <= p);\n        unordered_set<long long> a;\n        a.reserve(m);\n\
    \        for (int k = 0; k < m; k++) {\n            t = ActSet::mapping(f, t);\n\
    \            a.insert(h(t));\n        }\n        F g = ActSet::id();\n       \
    \ {\n            long long mm = m;\n            F ff = f;\n            while (m\
    \ > 0) {\n                if (m & 1) g = ActSet::comp(g, f);\n               \
    \ f = ActSet::comp(f, f);\n                m >>= 1;\n            }\n         \
    \   m = mm;\n            f = ff;\n        }\n        for (int k = 0, flag = 0;\
    \ k <= m; k++) {\n            t = ActSet::mapping(g, s);\n            if (a.count(h(t)))\
    \ {\n                for (int i = 0; i < m; i++) {\n                    if (h(s)\
    \ == ht) {\n                        return m * k + i;\n                    }\n\
    \                    s = ActSet::mapping(f, s);\n                }\n         \
    \       if (flag) return -1;\n                flag = 1;\n            }\n     \
    \       s = t;\n        }\n        return -1;\n    }\n};\n\nstruct ActSet {\n\
    \    using S = mint;\n    using F = affine<mint>;\n    static F comp(F f, F g)\
    \ {\n        return f(g);\n    }\n    static F id() {\n        return F();\n \
    \   }\n    static S mapping(F f, S x) {\n        return f(x);\n    }\n};\n\nlong\
    \ long solve(int P, int A, int B, int S, int T) {\n    mint::set_mod(P);\n   \
    \ return discrete_logarithm<ActSet>::solve(affine<mint>(A, B), S, T, P, [&](mint\
    \ x){ return x.val(); });\n}\n\n} // namespace AC\n\nstruct ActSet {\n    using\
    \ S = mint;\n    using F = affine<mint>;\n    static F comp(F f, F g) {\n    \
    \    return f(g);\n    }\n    static F id() {\n        return F();\n    }\n  \
    \  static S mapping(F f, S x) {\n        return f(x);\n    }\n};\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    {\n        int\
    \ A, B;\n        cin >> A >> B;\n        cout << A + B << '\\n';\n    }\n    for\
    \ (int t = 0; t < 200; t++) {\n        int P = rng::randint(2, (int)1e9);\n  \
    \      while (!prime::is_prime(P)) P = rng::randint(2, (int)1e9);\n        int\
    \ A = rng::randint(0, P - 1);\n        int B = rng::randint(0, P - 1);\n     \
    \   int S = rng::randint(0, P - 1);\n        int T = rng::randint(0, P - 1);\n\
    \        mint::set_mod(P);\n        auto ans = discrete_logarithm<ActSet>::solve(affine<mint>(A,\
    \ B), S, T, P, [&](mint x){ return x.val(); });\n        assert(ans == AC::solve(P,\
    \ A, B, S, T));\n    }\n}"
  dependsOn:
  - src/random/utility.hpp
  - src/math/number_theory/prime.hpp
  - src/random/xor_shift.hpp
  - src/modint/dynamic_modint.hpp
  - src/math/affine.hpp
  - src/math/number_theory/discrete_logarithm.hpp
  isVerificationFile: true
  path: test/math/number_theory/discrete_logarithm.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/math/number_theory/discrete_logarithm.test.cpp
layout: document
redirect_from:
- /verify/test/math/number_theory/discrete_logarithm.test.cpp
- /verify/test/math/number_theory/discrete_logarithm.test.cpp.html
title: test/math/number_theory/discrete_logarithm.test.cpp
---
