#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/enumerative_combinatorics/stirling2_n_fixed.hpp"

#include <iostream>

using mint = modint<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    auto S2 = stirling2<mint>(N);
    for (int i = 0; i <= N; i++) {
        cout << S2[i].val() << " \n"[i == N];
    }
}