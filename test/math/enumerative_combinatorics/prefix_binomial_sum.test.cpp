#define PROBLEM "https://yukicoder.me/problems/no/2206"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/enumerative_combinatorics/prefix_binomial_sum.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    prefix_binomial_sum<mint> C((int)2e5);
    while (T--) {
        int N, M;
        cin >> N >> M;
        mint ans = mint(2).pow(N) - 1;
        ans *= C.get(N - 1, M - 1);
        cout << ans.val() << '\n';
    }
}
