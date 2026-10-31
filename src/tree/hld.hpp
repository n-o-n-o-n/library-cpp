#pragma once
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

template<typename SegTree, bool edge, bool commutative>
struct heavy_light_decomposition {
    using M = typename SegTree::M;
    using S = typename M::S;
    heavy_light_decomposition() = default;
    heavy_light_decomposition(int _n, int _r = 0) : n(_n), r(_r), id(0), built(false) {
        edges.reserve(n - 1);
        if (n <= 1) build();
    }
    void add_edge(int u, int v, const S &w = M::e()) {
        assert(!built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(u != v);
        edges.emplace_back(u, v, w);
        if (ssize(edges) + 1 == n) build();
    }
    int lca(int u, int v) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        return inner_query(u, v, [] (int, int, bool) {});
    }
    void set(int u, const S &w) {
        assert(built);
        assert(0 <= u && u < n);
        seg.set(idx(u), w);
    }
    void set(int u, int v, const S &w) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(u != v);
        seg.set(idx(u, v), w);
    }
    template<typename F>
    void apply(int u, int v, const F &f) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        inner_query(u, v, [&] (int l, int r, bool) {
            if (l > r) swap(l, r);
            seg.apply(l, r, f);
        });
    }
    template<typename F>
    void subtree_apply(int u, const F &f) {
        assert(built);
        assert(0 <= u && u < n);
        seg.apply(in[u] + edge, out[u], f);
    }
    S get(int u) {
        assert(built);
        assert(0 <= u && u < n);
        return seg.get(idx(u));
    }
    S get(int u, int v) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        assert(u != v);
        return seg.get(idx(u, v));
    }
    S prod(int u, int v) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        S pu = M::e(), pv = M::e();
        inner_query(u, v, [&] (int l, int r, bool up) {
            if (up) {
                pu = M::op(pu, inner_prod(l, r));
            } else {
                pv = M::op(inner_prod(l, r), pv);
            }
        });
        return M::op(pu, pv);
    }
    S subtree_prod(int u) {
        assert(built);
        assert(0 <= u && u < n);
        return seg.prod(in[u] + edge, out[u]);
    }
    template<typename C>
    int binary_search(int u, int v, const C &check) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        vector<pair<int, int>> pl, pr;
        inner_query(u, v, [&] (int l, int r, bool up) {
            if (l == r) return;
            (up ? pl : pr).emplace_back(l, r);
        });
        reverse(pr.begin(), pr.end());
        pl.insert(pl.end(), pr.begin(), pr.end());
        S p = M::e();
        for (auto [l, r] : pl) {
            S np = M::op(p, inner_prod(l, r));
            if (check(np)) {
                p = np;
                u = l < r ? inv[r - 1] : (edge ? par[inv[r]] : inv[r]);
                continue;
            }
            auto c = [&] (const S &x) { return check(M::op(p, x)); };
            if (l < r) {
                int k = [&] {
                    if constexpr (commutative) {
                        return seg.max_right(l, c);
                    } else {
                        return seg.max_right(l, false, c);
                    }
                } ();
                return k == l ? u : inv[k - 1];
            } else {
                int k = [&] {
                    if constexpr (commutative) {
                        return seg.min_left(l, c);
                    } else {
                        return seg.min_left(l, true, c);
                    }
                } ();
                return k == l ? u : (edge ? par[inv[k]] : inv[k]);
            }
        }
        return v;
    }
    vector<pair<int, int>> path_decompose(int u, int v) {
        assert(built);
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        if (u == v) return {{u, v}};
        int w = lca(u, v);
        auto climb = [&] (int x, vector<pair<int, int>> &res) {
            while (x != w) {
                int y = head[x] == head[w] ? w : head[x];
                if (x != y) res.emplace_back(x, y);
                if (y == w) break;
                res.emplace_back(y, par[y]);
                x = par[y];
            }
        };
        vector<pair<int, int>> pu, pv;
        climb(u, pu);
        climb(v, pv);
        reverse(pv.begin(), pv.end());
        for (auto [l, r] : pv) pu.emplace_back(r, l);
        return pu;
    }
private:
    int n, r, id;
    bool built;
    SegTree seg;
    vector<vector<int>> g;
    vector<int> sub, depth, par, in, out, inv, head, heavy;
    vector<tuple<int, int, S>> edges;
    int idx(int u) const {
        assert(built);
        return in[u];
    }
    int idx(int u, int v) const {
        assert(built);
        return max(in[u], in[v]);
    }
    void dfs(int u, int p) {
        par[u] = p;
        sub[u] = 1;
        int sub_max = 0;
        for (int v : g[u]) {
            if (v != p) {
                dfs(v, u);
                sub[u] += sub[v];
                if (sub[v] > sub_max) {
                    sub_max = sub[v];
                    heavy[u] = v;
                }
            }
        }
    }
    void decompose(int u, int h) {
        head[u] = h;
        in[u] = id++;
        inv[in[u]] = u;
        if (heavy[u] != -1) decompose(heavy[u], h);
        for (int v : g[u]) {
            if (v != par[u] && v != heavy[u]) {
                decompose(v, v);
            }
        }
        out[u] = id;
    }
    void build() {
        g = vector<vector<int>>(n);
        sub = depth = in = inv = out = head = vector<int>(n);
        par = heavy = vector<int>(n, -1);
        for (const auto &[u, v, _] : edges) {
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
        dfs(r, r);
        decompose(r, r);
        built = true;
        if (edge) {
            vector<S> a(n, M::e());
            for (const auto &[u, v, w] : edges) {
                a[idx(u, v)] = w;
            }
            seg = SegTree(a);
        } else {
            seg = SegTree(n);
        }
    }
    template<typename F>
    int inner_query(int u, int v, const F &f) {
        while (head[u] != head[v]) {
            if (in[head[u]] > in[head[v]]) {
                f(in[u] + 1, in[head[u]], true);
                u = par[head[u]];
            } else {
                f(in[head[v]], in[v] + 1, false);
                v = par[head[v]];
            }
        }
        if (in[u] >= in[v]) {
            f(in[u] + 1, in[v] + edge, true);
            return v;
        } else {
            f(in[u] + edge, in[v] + 1, false);
            return u;
        }
    }
    S inner_prod(int l, int r) {
        if (commutative && l > r) swap(l, r);
        return seg.prod(l, r);
    }
};
