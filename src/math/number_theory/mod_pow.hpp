#pragma once
#include <cassert>
#include <type_traits>
using namespace std;

template<typename T1, typename T2 = long long>
inline T1 mod_pow(T1 a, T2 n, T1 mod) {
    assert(mod > 0);
    assert(n >= 0);
    using W = conditional_t<(sizeof(T1) <= 4), long long, __int128_t>;
    a %= mod;
    if (a < 0) a += mod;
    T1 res = 1 % mod;
    while (n > 0) {
        if (n & 1) res = W(res) * a % mod;
        a = W(a) * a % mod;
        n >>= 1;
    }
    return res;
}
