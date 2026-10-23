#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/affine.hpp"
#include "../../../src/data_structure/misc/swag.hpp"

using mint = modint<998244353>;

struct Monoid {
    using S = affine<mint>;
    static S op(S f, S g) { return g(f); }
    static S e() { return S(); }
};

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    swag<Monoid> q;
    int Q;
    cin >> Q;
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            q.push(affine<mint>(a, b));
        } else if (t == 1) {
            q.pop();
        } else {
            int x;
            cin >> x;
            auto f = q.get();
            cout << f(x).val() << '\n';
        }
    }
}