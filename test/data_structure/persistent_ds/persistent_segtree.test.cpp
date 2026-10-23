#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../../src/misc/compress.hpp"
#include "../../../src/data_structure/persistent_ds/persistent_segtree.hpp"
#include "../../../src/monoid/add.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> X(N), Y(N), Z(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> Z[i];
    vector<int> L(Q), D(Q), R(Q), U(Q);
    for (int i = 0; i < Q; i++) cin >> L[i] >> D[i] >> R[i] >> U[i];
    int W = compress_inplace(X, L, R);
    int H = compress_inplace(Y, D, U);
    vector<vector<pair<int, int>>> inv(H);
    for (int i = 0; i < N; i++) inv[Y[i]].emplace_back(X[i], Z[i]);
    persistent_segtree<add_monoid<long long>> seg(W);
    vector<int> T(H);
    for (int y = 0, t = 0; y < H; y++) {
        T[y] = t;
        for (auto [x, z] : inv[y]) {
            seg.set(t, x, seg.get(t, x) + z);
            t++;
        }
    }
    for (int i = 0; i < Q; i++) {
        cout << seg.prod(T[U[i]], L[i], R[i]) - seg.prod(T[D[i]], L[i], R[i]) << '\n';
    }
}