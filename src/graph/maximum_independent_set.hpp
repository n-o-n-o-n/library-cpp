#pragma once
#include <vector>
using namespace std;

inline vector<int> maximum_independent_set(const vector<vector<int>> &g) {
    int n = g.size();
    vector<int> deg(n), used(n);
    vector<bool> vis(n), ans(n);
    for (int i = 0; i < n; i++) deg[i] = g[i].size();
    int cur = 0, cnt = 0, alive = n;
    auto dfs = [&](const auto &dfs) -> void {
        if (cnt + alive <= cur) return;
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && !used[i]) {
                if (deg[i] <= 1) {
                    u = i;
                    break;
                }
                if (u < 0 || deg[u] < deg[i]) u = i;
            }
        }
        if (u < 0) return;
        if (deg[u] != 1) {
            used[u] = 1;
            alive--;
            for (int v : g[u]) deg[v]--;
            dfs(dfs);
            used[u] = 0;
            alive++;
            for (int v : g[u]) deg[v]++;
        }
        vis[u] = true;
        alive--;
        for (int v : g[u]) {
            if (!used[v]++) alive--;
        }
        cnt++;
        if (cur < cnt) {
            ans = vis;
            cur = cnt;
        }
        dfs(dfs);
        vis[u] = 0;
        alive++;
        for (int v : g[u]) {
            if (!--used[v]) alive++;
        }
        cnt--;
    };
    dfs(dfs);
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (ans[i]) res.push_back(i);
    }
    return res;
}

inline vector<int> maximum_independent_set_adjacency(const vector<vector<int>> &a) {
    int n = a.size();
    vector<vector<int>> g(n);
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (a[u][v]) g[u].push_back(v);
        }
    }
    return maximum_independent_set(g);
}