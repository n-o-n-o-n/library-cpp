#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include "../../../src/data_structure/set/interval_map.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    interval_map<int, int> mp(numeric_limits<int>::max());
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, x;
            cin >> l >> r >> x;
            r++;
            mp.update(l, r, x);
        } else {
            int p;
            cin >> p;
            cout << mp[p] << '\n';
        }
    }
}