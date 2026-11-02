#pragma once
#include "../template.hpp"

struct functional_graph {
    functional_graph(int _n) : functional_graph(vector<int>(_n, -1)) {}
    functional_graph(const vector<int> &a) : n(a.size()), f(1, a) {}
    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(f[0][u] == -1);
        f[0][u] = v;
    }
    int steps(int u, long long k) {
        assert(0 <= u && u < n);
        doubling(k);
        for (int i = 0; (1LL << i) <= k; i++) {
            if (k >> i & 1) u = f[i][u];
        }
        return u;
    }
    vector<int> table(long long k) {
        doubling(k);
        vector<int> g(n);
        iota(g.begin(), g.end(), 0);
        for (int i = 0; (1LL << i) <= k; i++) {
            if (k >> i & 1) {
                for (int j = 0; j < n; j++) {
                    g[j] = f[i][g[j]];
                }
            }
        }
        return g;
    }
    template<typename C>
    pair<int, int> binary_search(int u, const C &check) {
        assert(0 <= u && u < n);
        assert(check(u));
        doubling(n);
        int log = 0;
        while (n >> log) log++;
        int r = 0;
        for (log--; log >= 0; log--) {
            int len = 1 << log;
            if (r > n - len) continue;
            int v = f[log][u];
            if (check(v)) u = v, r += len;
        }
        if (r == n) return {-1, -1};
        return make_pair(r, u);
    }
private:
    int n;
    vector<vector<int>> f;
    void doubling(long long k) {
        while (1LL << int(f.size()) <= k) {
            vector<int> tf(n);
            const vector<int> &g = f.back();
            for (int i = 0; i < n; i++) tf[i] = g[g[i]];
            f.push_back(tf);
        }
    }
};
