#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../src/misc/two_sat.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string p, cnf;
    cin >> p >> cnf;
    int N, M;
    cin >> N >> M;
    two_sat ts(N);
    for (int s, t, zero; M--; ) {
        cin >> s >> t >> zero;
        ts.add_clause(abs(s) - 1, s > 0, abs(t) - 1, t > 0);
    }
    auto ans = ts.solve();
    if (ans.empty()) {
        cout << "s UNSATISFIABLE" << '\n';
        return 0;
    }
    cout << "s SATISFIABLE" << '\n';
    cout << "v";
    for (int i = 0; i < N; i++) {
        cout << ' ' << (ans[i] ? 1 : -1) * (i + 1);
    }
    cout << " 0\n";
}