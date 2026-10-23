#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <utility>
#include <vector>
using namespace std;

template<typename T>
vector<pair<int, int>> hungarian(const vector<vector<T>> &a) {
    int h = a.size(), w = a[0].size();
    if (h > w) {
        vector<vector<T>> b(w, vector<T>(h));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) b[j][i] = a[i][j];
        }
        auto res = hungarian<T>(b);
        for (auto &[u, v] : res) swap(u, v);
        sort(res.begin(), res.end());
        return res;
    }
    const T inf = numeric_limits<T>::max();
    vector<int> p(w + 1), way(w + 1);
    vector<T> u(h + 1), v(w + 1);
    for (int i = 1; i <= h; i++) {
        p[0] = i;
        vector<T> min_v(w + 1, inf);
        vector<bool> used(w + 1, false);
        int j = 0;
        do {
            used[j] = true;
            int k = 0;
            T d = inf;
            for (int c = 1; c <= w; c++) {
                if (used[c]) continue;
                T cur = a[p[j] - 1][c - 1] - u[p[j]] - v[c];
                if (cur < min_v[c]) min_v[c] = cur, way[c] = j;
                if (min_v[c] < d) d = min_v[c], k = c;
            }
            for (int c = 0; c <= w; c++) {
                if (used[c]) u[p[c]] += d, v[c] -= d;
                else min_v[c] -= d;
            }
            j = k;
        } while (p[j] != 0);
        do {
            p[j] = p[way[j]];
            j = way[j];
        } while (j != 0);
    }
    vector<pair<int, int>> res;
    res.reserve(h);
    for (int c = 1; c <= w; c++) {
        if (p[c] != 0) res.emplace_back(p[c] - 1, c - 1);
    }
    sort(res.begin(), res.end());
    return res;
}
