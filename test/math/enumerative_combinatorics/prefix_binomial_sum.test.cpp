#define PROBLEM "https://judge.yosupo.jp/problem/prefix_sum_of_binomial_coefficient"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/enumerative_combinatorics/prefix_binomial_sum.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    combination::prefix_binomial_sum<mint, 200000> C;
    for (int N, K; T--; ) {
        cin >> N >> K;
        cout << C.get(N, K).val() << '\n';
    }
}
