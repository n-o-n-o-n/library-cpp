#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../src/graph/bipartite_matching.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int L, R, M;
    cin >> L >> R >> M;
    bipartite_matching G(L, R);
    for (int u, v; M--; ) {
        cin >> u >> v;
        G.add_edge(u, v);
    }
    auto ans = G.matching();
    cout << ans.size() << '\n';
    for (auto [u, v] : ans) cout << u << ' ' << v << '\n';
}