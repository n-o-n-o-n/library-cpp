#pragma once
#include <vector>
using namespace std;

#include "../../fps/fps_inv.hpp"

// for k=0,...,K calculate sum[1<=i<=n] i^k
template<typename mint>
vector<mint> power_sums(int k, long long n) {
    mint pown = n + 1;
    fps<mint> f(k + 1), g(k + 1);
    for (int i = 0; i <= k; i++) {
        f[i] = pown * combination::finv<mint>(i + 1);
        g[i] = combination::finv<mint>(i + 1);
        pown *= n + 1;
    }
    f /= g;
    vector<mint> res(k + 1);
    res[0] = n + 1;
    for (int i = 1; i <= k; i++) {
        res[i] = f[i] * combination::fac<mint>(i);
    }
    return res;
}