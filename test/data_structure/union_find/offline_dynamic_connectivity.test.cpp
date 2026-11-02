#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"

#include "../../../src/data_structure/union_find/offline_dynamic_connectivity.hpp"
#include "../../../src/monoid/sum.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    offline_dynamic_connectivity<sum_monoid<long long>> dc(N);
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        dc.set(i, a[i]);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v;
            cin >> u >> v;
            dc.merge(u, v);
        } else if (t == 1) {
            int u, v;
            cin >> u >> v;
            dc.erase(u, v);
        } else if (t == 2) {
            int u, x;
            cin >> u >> x;
            dc.set(u, a[u] += x);
        } else {
            int u;
            cin >> u;
            dc.prod(u);
        }
    }
    for (const auto &x : dc.solve()) cout << x.first << '\n';
}
