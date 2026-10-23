#pragma once
#include <cassert>
#include <limits>
#include <type_traits>
#include <vector>
#include "../modint/modint.hpp"
#include "convolution.hpp"
using namespace std;

template<typename T, int K = 3>
vector<T> convolution_ll(const vector<T> &f, const vector<T> &g) {
    static_assert(1 <= K && K <= 3);
    int n = f.size(), m = g.size();
    if (n == 0 || m == 0) return {};
    if (n <= 63 || m <= 63) {
        vector<T> h(n + m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) h[i + j] += f[i] * g[j];
        }
        return h;
    }
    using i128 = __int128_t;
    constexpr int m1 = 167772161, m2 = 469762049, m3 = 754974721;
    using mint1 = modint<m1>;
    vector<mint1> f1(n), g1(m);
    for (int i = 0; i < n; i++) f1[i] = f[i];
    for (int i = 0; i < m; i++) g1[i] = g[i];
    auto h1 = convolution(f1, g1);
    vector<T> h(n + m - 1);
    if constexpr (K == 1) {
        for (int i = 0; i < n + m - 1; i++) {
            long long x = h1[i].val();
            if (x > m1 / 2) x -= m1;
            h[i] = x;
        }
    } else {
        using mint2 = modint<m2>;
        const mint2 inv_m1 = mint2(m1).inv();
        constexpr i128 m12 = (i128)m1 * m2;
        vector<mint2> f2(n), g2(m);
        for (int i = 0; i < n; i++) f2[i] = f[i];
        for (int i = 0; i < m; i++) g2[i] = g[i];
        auto h2 = convolution(f2, g2);
        if constexpr (K == 2) {
            for (int i = 0; i < n + m - 1; i++) {
                i128 x = h1[i].val();
                x += (i128)m1 * ((h2[i] - x) * inv_m1).val();
                if (x > m12 / 2) x -= m12;
                h[i] = x;
            }
        } else {
            using mint3 = modint<m3>;
            const mint3 inv_m12 = mint3(1LL * m1 * m2).inv();
            constexpr i128 mod = m12 * m3;
            vector<mint3> f3(n), g3(m);
            for (int i = 0; i < n; i++) f3[i] = f[i];
            for (int i = 0; i < m; i++) g3[i] = g[i];
            auto h3 = convolution(f3, g3);
            for (int i = 0; i < n + m - 1; i++) {
                i128 x = h1[i].val();
                x += (i128)m1 * ((h2[i] - x) * inv_m1).val();
                x += m12 * ((h3[i].val() - x) * inv_m12).val();
                if (x > mod / 2) x -= mod;
                h[i] = x;
            }
        }
    }
    return h;
}
