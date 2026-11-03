#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../src/template.hpp"
#include "../../src/graph/shortest_path.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    shortest_path<long long> G(N);
    for (int u, v, w; M--; ) {
        cin >> u >> v >> w;
        G.add_edge(u, v, w);
    }
    auto P = G.path(s, t);
    if (P.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    cout << G.dist(s, t) << ' ' << ssize(P) - 1 << '\n';
    for (int i = 1; i < ssize(P); i++) cout << P[i - 1] << ' ' << P[i] << '\n';
}