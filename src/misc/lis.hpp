#pragma once
#include <algorithm>
#include <vector>
using namespace std;

template<typename T>
vector<int> longest_increasing_subsequence(const vector<T> &v, bool strict = true) {
    if (v.empty()) return {};
    int n = v.size();
    vector<T> dp;
    vector<int> idx(n, -1);
    for (int i = 0; i < n; i++) {
        int j;
        if (strict) {
            j = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        } else {
            j = upper_bound(dp.begin(), dp.end(), v[i]) - dp.begin();
        }
        if (j == ssize(dp)) dp.push_back(v[i]);
        else dp[j] = v[i];
        idx[i] = j;
    }
    int m = *max_element(idx.begin(), idx.end());
    vector<int> res(m + 1);
    for (int i = n - 1; i >= 0; i--) {
        if (idx[i] == m) {
            res[m] = i;
            m--;
        }
    }
    return res;
}