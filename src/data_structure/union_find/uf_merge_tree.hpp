#pragma once
#include <cassert>
#include <numeric>
#include <vector>
#include "union_find.hpp"
using namespace std;

struct uf_merge_tree {
    uf_merge_tree(int _n = 0) : n(_n), c(_n), par(2 * _n, -1), top(_n), uf(_n) {
        iota(top.begin(), top.end(), 0);
    }
    int merge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        u = uf.leader(u);
        v = uf.leader(v);
        if (u == v) return top[u];
        int tu = top[u];
        int tv = top[v];
        par[tu] = c;
        par[tv] = c;
        top[uf.merge(u, v)] = c;
        return c++;
    }
    vector<int> parents() const {
        return vector<int>(par.begin(), par.begin() + c);
    }
private:
    int n, c;
    vector<int> par, top;
    union_find uf;
};
