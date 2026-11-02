#pragma once
#include "../template.hpp"

template<typename Monoid, bool edge>
struct weighted_functional_graph {
    using M = Monoid;
    using S = typename Monoid::S;
    weighted_functional_graph(int _n) : n(_n), f(1, vector<int>(_n, -1)), d(1, vector<S>(_n, M::e())) {}
    void add_edge(int u, int v, const S &x = M::e()) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(f[0][u] == -1);
        f[0][u] = v;
        d[0][u] = x;
    }
    void set_weight(int u, const S &x) {
        assert(0 <= u && u < n);
        assert(!edge);
        d[0][u] = x;
    }
    pair<int, S> steps(int u, long long k) {
        assert(0 <= u && u < n);
        assert(k >= 0);
        doubling(k);
        S x = edge ? M::e() : d[0][u];
        for (int i = 0; k >> i; i++) {
            if (k >> i & 1) {
                int from = edge ? u : f[0][u];
                x = M::op(x, d[i][from]);
                u = f[i][u];
            }
        }
        return {u, x};
    }
    pair<vector<int>, vector<S>> table(long long k) {
        assert(k >= 0);
        doubling(k);
        vector<int> g(n);
        vector<S> w(n, M::e());
        iota(g.begin(), g.end(), 0);
        if constexpr (!edge) w = d[0];
        for (int i = 0; k >> i; i++) {
            if (k >> i & 1) {
                for (int j = 0; j < n; j++) {
                    int from = edge ? g[j] : f[0][g[j]];
                    w[j] = M::op(w[j], d[i][from]);
                    g[j] = f[i][g[j]];
                }
            }
        }
        return {g, w};
    }
    template<typename C>
    pair<long long, pair<int, S>> binary_search(int u, long long k, const C &check) {
        assert(0 <= u && u < n);
        assert(k >= 0);
        S x = edge ? M::e() : d[0][u];
        assert(check(x));
        doubling(k);
        int log = 0;
        while (k >> log) log++;
        long long r = 0;
        for (log--; log >= 0; log--) {
            long long len = 1LL << log;
            if (r > k - len) continue;
            int from = edge ? u : f[0][u];
            S y = M::op(x, d[log][from]);
            int v = f[log][u];
            if (check(y)) {
                x = y;
                u = v;
                r += len;
            }
        }
        return {r, {u, x}};
    }
private:
    int n;
    vector<vector<int>> f;
    vector<vector<S>> d;
    void doubling(long long k) {
        while (k >> int(f.size())) {
            vector<int> tf(n);
            vector<S> td(n, M::e());
            const vector<int> &g = f.back();
            const vector<S> &h = d.back();
            for (int i = 0; i < n; i++) tf[i] = g[g[i]], td[i] = M::op(h[i], h[g[i]]);
            f.push_back(tf);
            d.push_back(td);
        }
    }
};
