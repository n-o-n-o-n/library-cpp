#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/enumerative_combinatorics/subset_sum.hpp"

#include <iostream>

using mint = modint<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> S(N);
    for (auto &e : S) cin >> e;
    auto ans = subset_sum<mint>(S, M);
    for (int i = 1; i <= M; i++) {
        cout << ans[i].val() << " \n"[i == M];
    }
}