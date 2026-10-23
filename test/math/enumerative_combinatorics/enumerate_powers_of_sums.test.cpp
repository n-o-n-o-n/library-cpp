#define PROBLEM "https://yukicoder.me/problems/no/1145"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/enumerative_combinatorics/enumerate_powers_of_sums.hpp"

#include <iostream>

using mint = modint<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    auto ans = enumerate_powers_of_sums<mint>(A, M);
    for (int i = 1; i <= M; i++) {
        cout << ans[i].val() << " \n"[i == M];
    }
}