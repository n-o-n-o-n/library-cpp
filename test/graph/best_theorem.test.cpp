#define PROBLEM "https://judge.yosupo.jp/problem/counting_eulerian_circuits"

#include "../../src/template.hpp"
#include "../../src/modint/modint.hpp"
#include "../../src/graph/best_theorem.hpp"

using mint = modint<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> E(N, vector<int>(N));
    for (int u, v; M--; ) {
        cin >> u >> v;
        E[u][v]++;
    }
    mint ans = best_theorem_adjacency<mint>(E);
    cout << ans.val() << '\n';
}