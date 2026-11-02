#pragma once
#include <algorithm>
#include <cassert>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>
#include "undoable_foldable_union_find.hpp"
using namespace std;

template<typename Abelian_Monoid>
struct offline_dynamic_connectivity {
    using M = Abelian_Monoid;
    using S = M::S;
    offline_dynamic_connectivity(int _n = 0) : n(_n), t(0), lst(_n, -1), d(_n, M::e()) {}
    void merge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        act[key(u, v)].push_back(t++);
    }
    void erase(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        auto it = act.find(key(u, v));
        assert(it != act.end() && !it->second.empty());
        int l = it->second.back();
        it->second.pop_back();
        if (it->second.empty()) act.erase(it);
        his_e.emplace_back(l, t++, u, v);
    }
    void set(int u, const S &x) {
        assert(0 <= u && u < n);
        if (lst[u] != -1) his_v.emplace_back(lst[u], t, u, d[u]);
        lst[u] = t++;
        d[u] = x;
    }
    void prod(int u) {
        assert(0 <= u && u < n);
        qs.emplace_back(t++, u, -1);
    }
    void same(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        qs.emplace_back(t++, u, v);
    }
    vector<pair<S, bool>> solve() const {
        vector<pair<S, bool>> ans(qs.size(), {M::e(), false});
        if (t == 0) return ans;
        int sz = 1;
        while (sz < t) sz <<= 1;
        vector<vector<int>> seg(2 * sz);
        vector<pair<int, int>> es;
        vector<pair<int, S>> vs;
        auto upd = [&] (int l, int r, int e) -> void {
            l += sz;
            r += sz;
            while (l < r) {
                if (l & 1) seg[l++].push_back(e);
                if (r & 1) seg[--r].push_back(e);
                l >>= 1;
                r >>= 1;
            }
        };
        for (auto [l, r, u, v] : his_e) {
            int id = es.size();
            es.emplace_back(u, v);
            upd(l, r, id);
        }
        for (const auto &[e, st] : act) {
            int u = e / w, v = e % w;
            for (int l : st) {
                int id = es.size();
                es.emplace_back(u, v);
                upd(l, t, id);
            }
        }
        for (const auto &[l, r, u, x] : his_v) {
            int id = vs.size();
            vs.emplace_back(u, x);
            upd(l, r, -id - 1);
        }
        for (int u = 0; u < n; u++) {
            if (lst[u] == -1) continue;
            int id = vs.size();
            vs.emplace_back(u, d[u]);
            upd(lst[u], t, -id - 1);
        }
        vector<int> q(t, -1);
        for (int i = 0; i < ssize(qs); i++) q[get<0>(qs[i])] = i;
        undoable_foldable_union_find<M> uf(n);
        auto dfs = [&] (const auto &dfs, int k) -> void {
            for (int id : seg[k]) {
                if (id >= 0) {
                    auto [u, v] = es[id];
                    uf.merge(u, v);
                } else {
                    const auto &[u, x] = vs[-id - 1];
                    uf.set(u, x);
                }
            }
            if (k >= sz) {
                int cur = k - sz;
                if (cur < t && q[cur] != -1) {
                    int i = q[cur];
                    auto [_, u, v] = qs[i];
                    if (v == -1) ans[i].first = uf.prod(u);
                    else ans[i].second = uf.same(u, v);
                }
            } else {
                dfs(dfs, 2 * k);
                dfs(dfs, 2 * k + 1);
            }
            for (int i = 0; i < ssize(seg[k]); i++) uf.undo();
        };
        dfs(dfs, 1);
        return ans;
    }
private:
    int n, t;
    vector<int> lst;
    vector<tuple<int, int, int>> qs;
    vector<S> d;
    unordered_map<long long, vector<int>> act;
    vector<tuple<int, int, int, int>> his_e;
    vector<tuple<int, int, int, S>> his_v;
    static constexpr long long w = 1LL << 32;
    static long long key(int &u, int &v) {
        if (u > v) swap(u, v);
        return u * w + v;
    }
};
