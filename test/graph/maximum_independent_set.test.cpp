#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"

#include "../../src/graph/maximum_independent_set.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> E(N, vector<int>(N));
    for (int u, v; M--; ) {
        cin >> u >> v;
        E[u][v]++, E[v][u]++;
    }
    auto ans = maximum_independent_set_adjacency(E);
    cout << ssize(ans) << '\n';
    for (int i = 0; i < ssize(ans); i++) {
        cout << ans[i] << " \n"[i + 1 == ssize(ans)];
    }
}