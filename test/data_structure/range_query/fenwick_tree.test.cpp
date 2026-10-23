#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../../src/data_structure/range_query/fenwick_tree.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (auto &e : A) cin >> e;
    fenwick_tree<long long> fw(A);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << '\n';
        }
    }
}