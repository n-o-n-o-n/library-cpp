#pragma once
#include "../../template.hpp"
#include "ext_gcd.hpp"

template<typename T>
inline T mod_inv(T a, T mod) {
    assert(mod > 1);
    using W = conditional_t<(sizeof(T) <= 4), long long, __int128_t>;
    W m = W(mod);
    W b = W(a) % m;
    if (b < 0) b += m;
    W inv, y;
    W g = ext_gcd(b, m, inv, y);
    assert(g == 1);
    inv %= m;
    return T(inv < 0 ? inv + m : inv);
}
