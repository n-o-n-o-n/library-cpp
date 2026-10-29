#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "../../../src/data_structure/rectangle_query/rectangle_sum.hpp"
#include "../../../src/monoid/sum.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    rectangle_sum<sum_monoid<long long>> rs(N, Q);
    for (int i = 0; i < N; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        rs.add_point(x, y, w);
    }
    for (int i = 0; i < Q; i++) {
        int xl, yl, xr, yr;
        cin >> xl >> yl >> xr >> yr;
        rs.add_query(xl, yl, xr, yr);
    }
    for (auto e : rs.solve()) cout << e << '\n';
}