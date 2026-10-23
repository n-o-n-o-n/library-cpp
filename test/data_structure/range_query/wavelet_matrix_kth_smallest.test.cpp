#define  PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "../../../src/data_structure/range_query/wavelet_matrix.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    wavelet_matrix<int> WM(A);
    for (int l, r, k; Q--; ) {
        cin >> l >> r >> k;
        cout << WM.range_kth_smallest(l, r, k) << '\n';
    }
}