#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../../src/data_structure/union_find/union_find.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    union_find uf(N);
    for (int t, u, v; Q--; ) {
        cin >> t >> u >> v;
        if (t == 0) {
            uf.merge(u, v);
        } else {
            cout << uf.same(u, v) << '\n';
        }
    }
}