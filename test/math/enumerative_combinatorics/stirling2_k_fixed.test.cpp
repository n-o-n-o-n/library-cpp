#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/enumerative_combinatorics/stirling2_k_fixed.hpp"

#include <iostream>

using mint = modint<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    auto S2 = stirling2<mint>(N, K);
    for (int i = K; i <= N; i++) {
        cout << S2[i].val() << " \n"[i == N];
    }
}