#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"

#include "../../../src/modint/modint.hpp"
#include "../../../src/monoid/range_affine_range_sum.hpp"
#include "../../../src/data_structure/range_query/dynamic_lazysegtree.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    dynamic_lazysegtree<range_affine_range_sum<mint>> seg(N, Q);
    while (Q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            seg.apply(l, r, affine<mint>(a, b));
        } else {
            cout << seg.prod(l, r).val() << '\n';
        }
    }
}