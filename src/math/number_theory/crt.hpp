#pragma once
#include <cassert>
#include <limits>
#include <type_traits>
#include <utility>
#include <vector>
#include "ext_gcd.hpp"
using namespace std;

template<typename T>
pair<T, T> crt(const vector<T> &rems, const vector<T> &mods) {
    assert(rems.size() == mods.size());
    using W = conditional_t<(sizeof(T) <= 4), long long, __int128_t>;
    T r = 0, m = 1;
    for (int i = 0; i < ssize(rems); i++) {
        assert(mods[i] > 0);
        T a = rems[i] % mods[i];
        if (a < 0) a += mods[i];
        W x, y;
        W g = ext_gcd(m, mods[i], x, y);
        W d = a - r;
        if (d % g != 0) return {0, 0};
        W u = (W)mods[i] / g;
        W t = (d / g * x) % u;
        if (t < 0) t += u;
        W l = (W)m * u;
        assert(l <= numeric_limits<T>::max());
        r += (W)m * t;
        m = l;
    }
    return {r, m};
}
