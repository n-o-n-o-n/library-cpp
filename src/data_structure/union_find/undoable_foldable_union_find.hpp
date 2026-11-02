#pragma once
#include "../../template.hpp"

template<typename Abelian_Monoid>
struct undoable_foldable_union_find {
    using M = Abelian_Monoid;
    using S = M::S;
    undoable_foldable_union_find(int n) : p(n, -1), cyc(n), a(n, M::e()), d(n, M::e()) {
        iota(cyc.begin(), cyc.end(), 0);
    }
    int leader(int u) const {
        assert(0 <= u && u < ssize(p));
        return p[u] < 0 ? u : leader(p[u]);
    }
    bool same(int u, int v) const {
        assert(0 <= u && u < ssize(p));
        assert(0 <= v && v < ssize(p));
        return leader(u) == leader(v);
    }
    void merge(int u, int v) {
        assert(0 <= u && u < ssize(p));
        assert(0 <= v && v < ssize(p));
        u = leader(u);
        v = leader(v);
        if (p[u] > p[v]) swap(u, v);
        his_type.push_back(false);
        his_merge.emplace_back(u, v, p[u], p[v], cyc[u], cyc[v], d[u]);
        if (u == v) return;
        p[u] += p[v];
        d[u] = M::op(d[u], d[v]);
        p[v] = u;
        swap(cyc[u], cyc[v]);
    }
    int size(int u) const {
        assert(0 <= u && u < ssize(p));
        return -p[leader(u)];
    }
    void set(int u, const S &x) {
        assert(0 <= u && u < ssize(p));
        int r = leader(u);
        his_type.push_back(true);
        his_set.emplace_back(u, r, a[u], d[r]);
        d[r] = M::op(d[r], M::op(M::inv(a[u]), x));
        a[u] = x;
    }
    S prod(int u) const {
        assert(0 <= u && u < ssize(p));
        return d[leader(u)];
    }
    void undo() {
        assert(!his_type.empty());
        bool is_set = his_type.back();
        his_type.pop_back();
        if (is_set) {
            auto [u, r, val, fld] = his_set.back();
            his_set.pop_back();
            a[u] = val;
            d[r] = fld;
        } else {
            auto [u, v, pu, pv, cu, cv, fld] = his_merge.back();
            his_merge.pop_back();
            if (u == v) return;
            p[u] = pu;
            p[v] = pv;
            cyc[u] = cu;
            cyc[v] = cv;
            d[u] = fld;
        }
    }
    vector<int> group(int u) const {
        assert(0 <= u && u < ssize(p));
        vector<int> res = {u};
        int v = cyc[u];
        while (v != u) {
            res.push_back(v);
            v = cyc[v];
        }
        return res;
    }
    vector<vector<int>> groups() const {
        int n = p.size();
        vector<vector<int>> tmp(n);
        for (int i = 0; i < n; i++) tmp[leader(i)].push_back(i);
        vector<vector<int>> res;
        for (auto v : tmp) if (v.size()) res.push_back(v);
        return res;
    }
private:
    vector<int> p, cyc;
    vector<S> a, d;
    vector<bool> his_type;
    vector<tuple<int, int, S, S>> his_set;
    vector<tuple<int, int, int, int, int, int, S>> his_merge;
};
