#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../../src/data_structure/range_query/disjoint_sparse_table.hpp"
#include "../../../src/monoid/add.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (auto &e : A) cin >> e;
    disjoint_sparse_table<add_monoid<long long>> st(A);
    for (int l, r; Q--; ) {
        cin >> l >> r;
        cout << st.prod(l, r) << '\n';
    }
}