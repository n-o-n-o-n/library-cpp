#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

#include "../../../src/data_structure/cht/li_chao_tree.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    li_chao_tree<long long> lct;
    vector<long long> l(N), r(N), a(N), b(N);
    for (int i = 0; i < N; i++) cin >> l[i] >> r[i] >> a[i] >> b[i];
    vector<long long> t(Q), u(Q), v(Q), c(Q), d(Q), x(Q);
    for (int i = 0; i < Q; i++) {
        cin >> t[i];
        if (t[i] == 0) {
            cin >> u[i] >> v[i] >> c[i] >> d[i];
        } else {
            cin >> x[i];
            lct.add_point(x[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        lct.add_segment(l[i], r[i], a[i], b[i]);
    }
    for (int i = 0; i < Q; i++) {
        if (t[i] == 0) {
            lct.add_segment(u[i], v[i], c[i], d[i]);
        } else {
            auto ans = lct.get_min(x[i]);
            if (ans == numeric_limits<long long>::max()) {
                cout << "INFINITY" << '\n';
            } else {
                cout << ans << '\n';
            }
        }
    }
}