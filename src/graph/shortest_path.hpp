#pragma once
#include "../template.hpp"

template<typename T = int>
struct shortest_path {
    shortest_path(int _n) : n(_n), r(-1), g(_n), wt(false) {}
    shortest_path(const vector<vector<int>> &_g) : n(_g.size()), r(-1), g(n), wt(false) {
        for (int u = 0; u < n; u++) {
            g[u].reserve(_g[u].size());
            for (int v : _g[u]) {
                assert(0 <= v && v < n);
                g[u].emplace_back(v, 1);
            }
        }
    }
    template<typename T2>
    shortest_path(const vector<vector<pair<int, T2>>> &_g) : n(_g.size()), r(-1), g(n), wt(true) {
        for (int u = 0; u < n; u++) {
            g[u].reserve(_g[u].size());
            for (auto [v, w] : _g[u]) {
                assert(0 <= v && v < n);
                assert(w >= 0);
                g[u].emplace_back(v, w);
            }
        }
    }
    void add_edge(int u, int v, T w = 1) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(w >= 0);
        g[u].emplace_back(v, w);
        wt = wt || (w != 1);
        r = -1;
    }
    vector<T> table(int s) {
        assert(0 <= s && s < n);
        build(s);
        return d;
    }
    vector<int> path(int s, int t) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        build(s);
        if (d[t] == -1) return {};
        vector<int> res = {t};
        while (p[t] != -1) res.push_back(t = p[t]);
        reverse(res.begin(), res.end());
        return res;
    }
    T dist(int s, int t) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        build(s);
        return d[t];
    }
private:
    int n, r;
    vector<vector<pair<int, T>>> g;
    bool wt;
    vector<T> d;
    vector<int> p;
    template<class P>
    void upd(int u, T cur, P push) {
        for (auto [v, w] : g[u]) {
            if (chmin(d[v], cur + w)) {
                p[v] = u;
                push(v);
            }
        }
    }
    void build(int s) {
        if (r == s) return;
        r = s;
        d = vector<T>(n, inf<T>());
        p = vector<int>(n, -1);
        d[s] = 0;
        if (!wt) {
            queue<int> q;
            q.push(s);
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                upd(u, d[u], [&] (int v) { q.push(v); });
            }
        } else {
            priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> q;
            q.emplace(0, s);
            while (!q.empty()) {
                auto [cur, u] = q.top();
                q.pop();
                if (cur > d[u]) continue;
                upd(u, cur, [&] (int v) { q.emplace(d[v], v); });
            }
        }
        for (auto &e : d) {
            if (e == inf<T>()) e = -1;
        }
    }
};
