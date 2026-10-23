#pragma once
#include <cassert>
#include <vector>
#include "../graph/scc.hpp"
using namespace std;

struct two_sat {
    two_sat() : two_sat(0) {}
    two_sat(int _n) : n(_n), scc(2 * _n) {}
    void add_clause(int i, bool f, int j, bool g) {
        scc.add_edge((!f) * n + i, g * n + j);
        scc.add_edge((!g) * n + j, f * n + i);
    }
    vector<bool> solve() {
        auto comp = scc.scc();
        vector<int> id(2 * n);
        for (int i = 0; i < ssize(comp); i++) {
            for (int j : comp[i]) id[j] = i;
        }
        vector<bool> res(n);
        for (int i = 0; i < n; i++) {
            if (id[i] == id[i + n]) return {};
            res[i] = id[i] < id[i + n];
        }
        return res;
    }
private:
    int n;
    scc_graph scc;
};