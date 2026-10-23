#define  PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../src/graph/scc.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    scc_graph G(N);
    for (int u, v; M--; ) {
        cin >> u >> v;
        G.add_edge(u, v);
    }
    auto ans = G.scc();
    cout << ans.size() << '\n';
    for (auto V : ans) {
        cout << ssize(V);
        for (auto v : V) cout << ' ' << v;
        cout << '\n';
    }
}