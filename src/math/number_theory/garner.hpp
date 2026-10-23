#pragma once
#include <type_traits>
#include <vector>
#include "ext_gcd.hpp"
using namespace std;

template<typename T>
T garner(const vector<T> &rems, vector<T> mods, T mod) {
    assert(rems.size() == mods.size());
    using W = conditional_t<(sizeof(T) <= 4), long long, __int128_t>;
    mods.push_back(mod);
    int n = mods.size();
    vector<T> c1(n, 1), c2(n, 0);
    for (int i = 0; i < n - 1; i++) {
        T m = mods[i], a = c1[i], b = (rems[i] - c2[i]) % m;
        if (b < 0) b += m;
        T x, y;
        T g = ext_gcd(a, m, x, y);
        if (b % g != 0) return -1;
        m /= g, b /= g;
        x %= m;
        if (x < 0) x += m;
        T t = (W)x * b % m;
        for (int j = i + 1; j < n; j++) {
            c2[j] = ((W)t * c1[j] + c2[j]) % mods[j];
            c1[j] = (W)c1[j] * m % mods[j];
        }
    }
    return c2.back();
}
