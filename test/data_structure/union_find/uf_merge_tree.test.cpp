#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../../src/template.hpp"
#include "../../../src/data_structure/union_find/uf_merge_tree.hpp"
#include "../../../src/tree/static_tree.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> T(Q), U(Q), V(Q), time(2 * N, Q);
    fill(time.begin(), time.begin() + N, -1);
    uf_merge_tree umt(N);
    for (int i = 0; i < Q; i++) {
        cin >> T[i] >> U[i] >> V[i];
        if (T[i] == 0) {
            int k = umt.merge(U[i], V[i]);
            time[k] = min(time[k], i);
        }
    }
    for (int i = 0; i < N - 1; i++) umt.merge(i, i + 1);
    auto P = umt.parents();
    static_tree G(P.size());
    int rt = -1;
    for (int i = 0; i < ssize(P); i++) {
        if (P[i] != -1) {
            G.add_edge(i, P[i]);
        } else {
            rt = i;
        }
    }
    for (int i = 0; i < Q; i++) {
        if (T[i] == 1) {
            cout << (time[G.lca(U[i], V[i], rt)] < i) << '\n';
        }
    }
}
