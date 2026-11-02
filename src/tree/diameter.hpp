#pragma once
#include "../template.hpp"

template<typename T>
inline pair<T, vector<int>> diameter(const vector<vector<pair<int, T>>> &g) {
    int n = g.size();
    auto bfs = [&] (int root) -> vector<T> {
        vector<T> dist(n, inf<T>());
        dist[root] = 0;
        queue<int> q;
        q.push(root);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto[v, w] : g[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        }
        return dist;
    };
    vector<T> d0 = bfs(0);
    int l = max_element(d0.begin(), d0.end()) - d0.begin();
    vector<T> dl = bfs(l);
    int r = max_element(dl.begin(), dl.end()) - dl.begin();
    T diam = dl[r];
    vector<int> path = {r};
    while (r != l) {
        for (auto[v, w] : g[r]) {
            if (dl[v] + w == dl[r]) {
                r = v;
                break;
            }
        }
        path.emplace_back(r);
    }
    return make_pair(diam, path);
}

inline pair<int, vector<int>> diameter(const vector<vector<int>> &g) {
    int n = g.size();
    vector<vector<pair<int, int>>> tmp(n);
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) {
            tmp[u].emplace_back(v, 1);
        }
    }
    return diameter(tmp);
}