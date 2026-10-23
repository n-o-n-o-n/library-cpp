#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../../src/convolution/convolution_ll.hpp"
#include "../../src/tree/centroid_decomposition.hpp"

using ll = long long;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    centroid_decomposition G(N);
    for (int i = 1, u, v; i < N; i++) {
        cin >> u >> v;
        G.add_edge(u, v);
    }
    vector<vector<int>> C(N);
    int root = -1;
    for (int i = 0; i < N; i++) {
        int p = G.parent(i);
        if (p == -1) {
            root = i;
        } else {
            C[p].push_back(i);
        }
    }
    vector<ll> ans(N);
    auto add = [] (vector<ll> &a, const vector<ll> &b, ll sign) -> void {
        if (a.size() < b.size()) a.resize(b.size());
        for (int i = 0; i < ssize(b); i++) a[i] += sign * b[i];
    };
    auto dfs = [&] (auto dfs, int u) -> void {
        vector<ll> f(1, 1), g;
        for (int c : G[u]) {
            if (G.level(c) <= G.level(u)) continue;
            vector<ll> b;
            auto dfs2 = [&] (auto dfs2, int u2, int p2, int d) -> void {
                if (ssize(b) <= d) b.resize(d + 1);
                b[d]++;
                for (int v2 : G[u2]) {
                    if (v2 != p2 && G.level(v2) > G.level(u)) dfs2(dfs2, v2, u2, d + 1);
                }
            };
            dfs2(dfs2, c, u, 1);
            add(f, b, 1);
            add(g, convolution_ll<ll, 2>(b, b), -1);
        }
        f = convolution_ll<ll, 2>(f, f);
        for (int i = 0; i < N && i < ssize(f); i++) ans[i] += f[i];
        for (int i = 0; i < N && i < ssize(g); i++) ans[i] += g[i];
        for (int v : C[u]) dfs(dfs, v);
    };
    dfs(dfs, root);
    for (int i = 1; i < N; i++) cout << ans[i] / 2 << " \n"[i + 1 == N];
}