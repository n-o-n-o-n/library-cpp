#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../../../src/data_structure/union_find/undoable_union_find.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q + 1), U(Q + 1), V(Q + 1);
    vector<vector<int>> G(Q + 1);
    for (int i = 1, k; i <= Q; i++) {
        cin >> T[i] >> k >> U[i] >> V[i];
        G[k + 1].push_back(i);
    }
    undoable_union_find uf(N);
    vector<int> ans(Q + 1);
    auto dfs = [&](auto dfs, int u) -> void {
        if (u > 0) {
            if (T[u] == 0) {
                uf.merge(U[u], V[u]);
            } else {
                ans[u] = uf.same(U[u], V[u]);
            }
        }
        for (int v : G[u]) dfs(dfs, v);
        if (u > 0 && T[u] == 0) uf.undo();
    };
    dfs(dfs, 0);
    for (int i = 1; i <= Q; i++) {
        if (T[i] == 1) cout << ans[i] << '\n';
    }
}
