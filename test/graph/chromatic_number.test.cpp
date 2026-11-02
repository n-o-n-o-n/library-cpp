#define PROBLEM "https://judge.yosupo.jp/problem/chromatic_number"

#include "../../src/template.hpp"
#include "../../src/graph/chromatic_number.hpp"

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
    cout << chromatic_number_adjacency(E) << '\n';
}