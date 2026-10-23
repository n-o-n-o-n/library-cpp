#pragma once
#include <vector>
#include "../../fps/fps.hpp"
using namespace std;

template<typename mint>
vector<mint> stirling2(int n) {
    fps<mint> f(n + 1), g(n + 1);
    int sgn = 1;
    for (int i = 0; i <= n; i++) {
        f[i] = combination::finv<mint>(i) * sgn;
        g[i] = combination::finv<mint>(i) * mint::raw(i).pow(n);
        sgn *= -1;
    }
    return (f * g).pre(n + 1);
}