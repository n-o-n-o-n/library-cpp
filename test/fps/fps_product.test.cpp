#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include "../../src/modint/modint.hpp"
#include "../../src/fps/fps_product.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    fps_product<mint> F;
    while (N--) {
        int K;
        cin >> K;
        fps<mint> f(K + 1);
        for (auto &e : f) { int x; cin >> x; e = x; }
        F.push_back(f);
    }
    auto ans = F.prod();
    for (int i = 0; i < ssize(ans); i++) {
        cout << ans[i].val() << " \n"[i + 1 == ssize(ans)];
    }
}