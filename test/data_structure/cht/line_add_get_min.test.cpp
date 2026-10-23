#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include "../../../src/data_structure/cht/li_chao_tree.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    li_chao_tree<long long> lct;
    vector<long long> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    vector<long long> t(Q), c(Q), d(Q), x(Q);
    for (int i = 0; i < Q; i++) {
        cin >> t[i];
        if (t[i] == 0) {
            cin >> c[i] >> d[i];
        } else {
            cin >> x[i];
            lct.add_point(x[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        lct.add_line(a[i], b[i]);
    }
    for (int i = 0; i < Q; i++) {
        if (t[i] == 0) {
            lct.add_line(c[i], d[i]);
        } else {
            cout << lct.get_min(x[i]) << '\n';
        }
    }
}