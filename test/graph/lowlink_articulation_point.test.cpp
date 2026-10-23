#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

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
    auto articulation_point = G.articulation_point();
    sort(articulation_point.begin(), articulation_point.end());
    for (auto e : articulation_point) cout << e << '\n';
}