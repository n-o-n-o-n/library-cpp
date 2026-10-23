#pragma once
#include <vector>
using namespace std;

inline int chromatic_number_adjacency(const vector<vector<int>> &a) {
    int n = a.size();
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            e[i] |= a[i][j] << j;
        }
    }
    vector<int> ind(1 << n);
    ind[0] = 1;
    for (int i = 1; i < 1 << n; i++) {
        int u = __builtin_ctz(i);
        ind[i] = ind[i ^ (1 << u)] + ind[(i ^ (1 << u)) & ~e[u]];
    }
    auto ind2 = ind;
    int k = 1, l = 0;
    while (true) {
        l = 0;
        for (int i = 0; i < 1 << n; i++) {
            l += (__builtin_parity(i) ? -1 : 1) * ind2[i];
        }
        if (l != 0) break;
        for (int i = 1; i < 1 << n; i++) {
            ind2[i] *= ind[i];
        }
        k++;
    }
    return k;
}

inline int chromatic_number(const vector<vector<int>> &g) {
    int n = g.size();
    vector<vector<int>> a(n, vector<int>(n));
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) a[u][v]++, a[v][u]++;
    }
    return chromatic_number_adjacency(a);
}