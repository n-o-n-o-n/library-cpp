#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iterator>
#include <numeric>
#include <type_traits>
#include <utility>
#include <vector>
#include "../../random/xor_shift.hpp"

using namespace std;

namespace prime {

template<typename T>
struct montgomery_modint {
    using U = conditional_t<(sizeof(T) <= 4), uint32_t, uint64_t>;
    using W = conditional_t<(sizeof(T) <= 4), uint64_t, unsigned __int128>;
    constexpr explicit montgomery_modint(U _mod, U v = 0) {
        mod = _mod;
        inv = get_inv_mod(mod);
        r2 = get_r2(mod);
        x = reduce(W(v % mod) * r2);
    }
    constexpr U modulus() const { return mod; }
    constexpr U val() const { return reduce(x); }
    constexpr U raw() const { return x; }
    constexpr montgomery_modint make(U value) const {
        montgomery_modint res = *this;
        res.x = reduce(W(value % mod) * r2);
        return res;
    }
    constexpr montgomery_modint& operator+=(const montgomery_modint& r) {
        assert(mod == r.mod);
        x = x >= mod - r.x ? x - (mod - r.x) : x + r.x;
        return *this;
    }
    constexpr montgomery_modint& operator-=(const montgomery_modint& r) {
        assert(mod == r.mod);
        x = x >= r.x ? x - r.x : mod - (r.x - x);
        return *this;
    }
    constexpr montgomery_modint& operator*=(const montgomery_modint& r) {
        assert(mod == r.mod);
        x = reduce(W(x) * r.x);
        return *this;
    }
    friend constexpr montgomery_modint operator+(montgomery_modint l, const montgomery_modint& r) { return l += r; }
    friend constexpr montgomery_modint operator-(montgomery_modint l, const montgomery_modint& r) { return l -= r; }
    friend constexpr montgomery_modint operator*(montgomery_modint l, const montgomery_modint& r) { return l *= r; }
    friend constexpr bool operator==(const montgomery_modint& l, const montgomery_modint& r) {
        assert(l.mod == r.mod);
        return l.x == r.x;
    }
    constexpr montgomery_modint pow(U k) const {
        montgomery_modint a = *this, res = make(1);
        while (k) {
            if (k & 1) res *= a;
            a *= a;
            k >>= 1;
        }
        return res;
    }
private:
    static constexpr int bits = sizeof(U) * 8;
    U mod, inv, r2, x;
    static constexpr U get_inv_mod(U mod) {
        U inv = 1;
        for (int i = 0; i < (bits == 32 ? 5 : 6); ++i) inv *= 2 - mod * inv;
        return -inv;
    }
    static constexpr U get_r2(U mod) {
        const U r = U((W(1) << bits) % mod);
        return U(W(r) * r % mod);
    }
    constexpr U reduce(W x) const {
        const U q = U(x) * inv;
        const W sum = x + W(q) * mod;
        W res = sum >> bits;
        if constexpr (is_unsigned_v<T>) {
            if (sum < x) res += W(1) << bits;
        }
        return U(res >= mod ? res - mod : res);
    }
};

template<typename T>
constexpr bool is_prime(T n) {
    using U = typename montgomery_modint<T>::U;
    if (n <= 1) return false;
    if (n == 2) return true;
    if ((n & 1) == 0) return false;
    using mint = montgomery_modint<T>;
    mint p{U(n)};
    const mint one = p.make(1), neg1 = p.make(U(n - 1));
    auto miller_rabin = [&] (const auto& ps) constexpr -> bool {
        U d = p.modulus() - 1;
        int s = 0;
        while ((d & 1) == 0) {
            d >>= 1;
            ++s;
        }
        for (int m : ps) {
            const U a = U(m) % p.modulus();
            if (a == 0) continue;
            mint x = p.make(a);
            x = x.pow(d);
            if (x == one || x == neg1) continue;
            bool f = false;
            for (int i = 1; i < s; ++i) {
                x *= x;
                if (x == neg1) {
                    f = true;
                    break;
                }
            }
            if (!f) return false;
        }
        return true;
    };
    if constexpr (sizeof(T) <= 4) {
        return miller_rabin(array<int, 3>{2, 7, 61});
    } else {
        if (n < 4759123141LL) return miller_rabin(array<int, 3>{2, 7, 61});
        return miller_rabin(array<int, 7>{2, 325, 9375, 28178, 450775, 9780504, 1795265022});
    }
}

template<typename T>
constexpr vector<T> prime_factor(T n) {
    using U = typename montgomery_modint<T>::U;
    if (n <= 1) return {};
    if (is_prime(n)) return {n};
    auto rho = [] (T n) constexpr -> T {
        for (int p : {2, 3, 5, 7}) {
            if (n % p == 0) return T(p);
        }
        using mint = montgomery_modint<T>;
        mint p{U(n)};
        xor_shift<T> eng(n);
        while (true) {
            mint u = p.make(U(eng(2, n - 1)));
            mint v = u;
            mint c = p.make(U(eng(1, n - 1)));
            U d = 1;
            while (d == 1) {
                u = u * u - c;
                v = v * v - c;
                v = v * v - c;
                U a = u.raw(), b = v.raw();
                d = gcd(a >= b ? a - b : b - a, p.modulus());
            }
            if (d < p.modulus()) return T(d);
        }
    };
    vector<T> res;
    T d = rho(n);
    auto a = prime_factor(d);
    auto b = prime_factor(n / d);
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}

template<typename T>
constexpr vector<pair<T, int>> factorise(T n) {
    auto ps = prime_factor(n);
    vector<pair<T, int>> res;
    res.reserve(ps.size());
    for (auto p : ps) {
        res.emplace_back(p, 0);
        while (n % p == 0) {
            res.back().second++;
            n /= p;
        }
    }
    return res;
}

template<typename T>
constexpr T primitive_root(T m) {
    using U = typename montgomery_modint<T>::U;
    assert(is_prime(m));
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    if (m == 1224736769) return 3;
    auto ps = prime_factor(m - 1);
    using mint = montgomery_modint<T>;
    mint mt{U(m)};
    const mint one = mt.make(1);
    xor_shift<U> eng(m);
    U a = eng(1, mt.modulus() - 1);
    while ([&] {
        mint x = mt.make(a);
        for (auto p : ps) {
            if (x.pow((mt.modulus() - 1) / U(p)) == one) return true;
        }
        return false;
    } ()) a = eng(1, mt.modulus() - 1);
    return T(a);
}

template<typename T>
vector<T> enumerate_divisors(T m) {
    assert(m > 0);
    auto f = factorise(m);
    int n = f.size();
    vector<T> res;
    auto rec = [&] (const auto &rec, int i, T x) -> void {
        if (i == n) {
            res.push_back(x);
            return;
        }
        auto [p, k] = f[i];
        for (int j = 0; j <= k; j++) {
            rec(rec, i + 1, x);
            if (j < k) x *= p;
        }
    };
    rec(rec, 0, 1);
    sort(res.begin(), res.end());
    return res;
}


} // namespace prime
