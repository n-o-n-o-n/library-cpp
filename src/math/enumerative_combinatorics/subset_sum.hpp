#pragma once
#include <vector>
#include "../../fps/fps_exp.hpp"
using namespace std;


template<typename mint>
vector<mint> subset_sum(const vector<int> &a, int m, bool neg = false) {
    const int mod = mint::mod();
    vector<int> cnt(m + 1, 0);
    for (int c : a) {
        if (c <= m) cnt[c]++;
    }
    fps<mint> f(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; i * j <= m; j++) {
            if (j & 1 && !neg) {
                f[i * j] += cnt[i] * combination::mod_inv<mint>(j);
            } else {
                f[i * j] -= cnt[i] * combination::mod_inv<mint>(j);
            }
        }
    }
    return f.exp();
}