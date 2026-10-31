#pragma once
#include <bit>
#include <cassert>
#include <vector>
using namespace std;

template<typename Monoid>
struct sparse_table {
    using M = Monoid;
    using S = typename M::S;
    sparse_table() = default;
    sparse_table(const vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <=n);
        if (l == r) return M::e();
        int i = bit_width(unsigned(r - l)) - 1;
        return M::op(d[i][l], d[i][r - (1 << i)]);
    }
private:
    int n, b, e;
    vector<vector<S>> d;
    void build() {
        b = bit_width(unsigned(n));
        d.resize(b);
        for (int i = 1; i < b; i++) {
            int width = 1 << i;
            d[i].assign(n - width + 1, M::e());
            for (int j = 0; j + width <= n; j++) {
                d[i][j] = M::op(d[i - 1][j], d[i - 1][j + (width >> 1)]);
            }
        }
    }
};