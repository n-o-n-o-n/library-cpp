#pragma once
#include <vector>
using namespace std;
#include "combination.hpp"

namespace combination {

template<typename mint, int N>
struct prefix_binomial_sum {
    using i128 = unsigned __int128;
    prefix_binomial_sum() {
        container<mint>::init(s);
        mint one = 1, inv2 = mint(2).inv();
        const auto &fac = container<mint>::fac;
        const auto &finv = container<mint>::finv;
        p2.resize(s + 1);
        g.resize(s + 1);
        p2[0] = 1;
        for (int i = 1; i <= s; i++) p2[i] = p2[i - 1] + p2[i - 1];
        mint invpow = p2[s].inv() * inv2;
        for (int i = s; i >= 0; i--) {
            g[i] = fac[i] * invpow;
            invpow += invpow;
        }
        table.resize(w * w);
        const mint i2b = inv2.pow(b);
        mint invp2 = 1;
        for (int i = 0; i < w; i++) {
            mint f = fac[i * b] * invp2, sum = invp2;
            for (int j = 0; j <= i / 2; j++) {
                int k = j * b;
                table[id(i, j)] = sum;
                if (j != i - j) {
                    table[id(i, i - j)] = one - sum + f * finv[j * b] * finv[(i - j) * b];
                }
                if (j < i / 2) {
                    i128 bs = 0;
                    for (int x = j * b + 1; x <= j * b + b; x++) {
                        bs += (i128)finv[x].val() * finv[i * b - x].val();
                    }
                    sum += f * bs;
                }
            }
            invp2 *= i2b;
        }
    }
    mint get(int n, int k) const {
        assert(0 <= k && k <= n && n <= N);
        int tn = (n + b / 2) / b;
        int tk = (k + b / 2) / b;
        mint res = table[id(tn, tk)];
        tn *= b;
        tk *= b;
        const auto &finv = container<mint>::finv;
        int l = max(min(tn, n), tk);
        int r = max(tn, n);
        mint cur = [&] {
            i128 res = 0;
            for (int i = l; i < r; i++) res += (i128)g[i].val() * finv[i - tk].val();
            return res;
        } ();
        cur *= finv[tk];
        res += tn < n ? -cur : cur;
        res *= p2[n];
        res += tk < k ? sub(n, tk + 1, k + 1) : -sub(n, k + 1, min(tk, n) + 1);
        return res;
    }
private:
    static constexpr int b = [] {
        if constexpr (N <= 1) return 3;
        int l = 1, r = N;
        while (r - l > 1) {
            int m = (l + r) / 2;
            (m <= N / m ? l : r) = m;
        }
        return r;
    }();
    static constexpr int w = (N + b - 1) / b + 1;
    static constexpr int s = (w - 1) * b;
    vector<mint> table, p2, g;
    static mint sub(int n, int l, int r) {
        if (l >= r) return 0;
        const auto &finv = container<mint>::finv;
        i128 sum = 0;
        for (int i = l; i < r; i++) sum += (i128)finv[i].val() * finv[n - i].val();
        return container<mint>::fac[n] * sum;
    }
    static constexpr int id(int i, int j) { return i * w + j; }
};

} // namespace combination