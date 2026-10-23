#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../../src/modint/modint.hpp"
#include "../../../src/data_structure/range_query/lazysegtree.hpp"
#include "../../../src/monoid/range_affine_range_sum.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<range_affine_range_sum<mint>::S> init(N);
    for (int i = 0, a; i < N; i++) {
        cin >> a;
        init[i] = range_affine_range_sum<mint>::S(a, 1);
    }
    lazysegtree<range_affine_range_sum<mint>> seg(init);
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