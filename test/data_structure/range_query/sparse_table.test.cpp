#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../../src/data_structure/range_query/sparse_table.hpp"
#include "../../../src/monoid/min.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    sparse_table<min_monoid<int>> st(A);
    for (int l, r; Q--; ) {
        cin >> l >> r;
        cout << st.prod(l, r) << '\n';
    }
}