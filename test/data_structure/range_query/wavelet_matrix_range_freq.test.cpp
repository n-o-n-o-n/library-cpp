#define  PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

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
    for (int l, r, x; Q--; ) {
        cin >> l >> r >> x;
        cout << WM.range_freq(l, r, x, x + 1) << '\n';
    }
}