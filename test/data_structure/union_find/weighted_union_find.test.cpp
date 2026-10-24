#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include "../../../src/modint/modint.hpp"
#include "../../../src/data_structure/union_find/weighted_union_find.hpp"
#include "../../../src/monoid/add.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    weighted_union_find<add_monoid<mint>> wuf(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            int x;
            cin >> x;
            cout << wuf.merge(v, u, x) << '\n';
        } else {
            if (wuf.same(u, v)) {
                cout << wuf.diff(v, u).val() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}
