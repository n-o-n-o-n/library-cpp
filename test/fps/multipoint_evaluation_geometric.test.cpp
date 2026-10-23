#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation_on_geometric_sequence"

#include "../../src/modint/modint.hpp"
#include "../../src/fps/multipoint_evaluation_geometric.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, a, r;
    cin >> N >> M >> a >> r;
    fps<mint> f(N);
    for (int i = 0; i < N; i++) {
        int c;
        cin >> c;
        f[i] = c;
    }
    vector<mint> ans = multipoint_evaluation_geometric(f, M, mint(a), mint(r));
    for (int i = 0; i < M; i++) {
        cout << ans[i].val() << " \n"[i + 1 == M];
    }
}