#pragma once
#include <cassert>
#include <numeric>
#include <vector>
using namespace std;

template<typename Abelian_Monoid>
struct foldable_union_find {
    using M = Abelian_Monoid;
    using S = M::S;
    foldable_union_find(int n) : p(n, -1), cyc(n), a(n, M::e()), d(n, M::e()) {
        iota(cyc.begin(), cyc.end(), 0);
    }
    int leader(int u) {
        assert(0 <= u && u < ssize(p));
        return p[u] < 0 ? u : p[u] = leader(p[u]);
    }
    bool same(int u, int v) {
        assert(0 <= u && u < ssize(p));
        assert(0 <= v && v < ssize(p));
        return leader(u) == leader(v);
    }
    void merge(int u, int v) {
        assert(0 <= u && u < ssize(p));
        assert(0 <= v && v < ssize(p));
        u = leader(u);
        v = leader(v);
        if (u == v) return;
        if (p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        d[u] = M::op(d[u], d[v]);
        p[v] = u;
        swap(cyc[u], cyc[v]);
    }
    int size(int u) {
        assert(0 <= u && u < ssize(p));
        return -p[leader(u)];
    }
    vector<int> group(int u) {
        assert(0 <= u && u < ssize(p));
        vector<int> res = {u};
        int v = cyc[u];
        while (v != u) {
            res.push_back(v);
            v = cyc[v];
        }
        return res;
    }
    vector<vector<int>> groups() {
        int n = p.size();
        vector<vector<int>> tmp(n);
        for (int i = 0; i < n; i++) {
            tmp[leader(i)].push_back(i);
        }
        vector<vector<int>> res;
        for (auto v : tmp) {
            if (v.size()) res.push_back(v);
        }
        return res;
    }
    void set(int u, const S &x) {
        assert(0 <= u && u < ssize(p));
        S diff = M::op(M::inv(a[u]), x);
        a[u] = x;
        d[leader(u)] = M::op(d[leader(u)], diff);
    }
    S prod(int u) {
        assert(0 <=u && u < ssize(p));
        return d[leader(u)];
    }
private:
    vector<int> p, cyc;
    vector<S> a, d;
};
