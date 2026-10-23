#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B"

#include "../../src/graph/lowlink.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    lowlink G(N, M);
    for (int u, v; M--; ) {
        cin >> u >> v;
        G.add_edge(u, v);
    }
    auto bridge = G.bridge();
    for (auto &[u, v] : bridge) if (u > v) swap(u, v);
    sort(bridge.begin(), bridge.end());
    for (auto [u, v] : bridge) cout << u << ' ' << v << '\n';
}