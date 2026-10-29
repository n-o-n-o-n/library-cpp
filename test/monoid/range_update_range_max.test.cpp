#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../../src/data_structure/range_query/lazysegtree.hpp"
#include "../../src/monoid/range_update_range_max.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    lazysegtree<range_update_range_max<int, -numeric_limits<int>::max()>> seg(N);
    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        r++;
        if (t == 0) {
            int x;
            cin >> x;
            seg.apply(l, r, -x);
        } else {
            cout << -seg.prod(l, r) << '\n';
        }
    }
}