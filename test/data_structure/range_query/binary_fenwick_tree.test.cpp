#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"

#include "../../../src/data_structure/range_query/binary_fenwick_tree.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    string T;
    cin >> T;
    binary_fenwick_tree fw(N);
    for (int i = 0; i < N; i++) {
        if (T[i] == '1') fw.set(i);
    }
    while (Q--) {
        int t, k;
        cin >> t >> k;
        if (t == 0) {
            fw.set(k);
        } else if (t == 1) {
            fw.reset(k);
        } else if (t == 2) {
            cout << fw.test(k) << '\n';
        } else if (t == 3) {
            cout << fw.next_element(k) << '\n';
        } else {
            cout << fw.prev_element(k) << '\n';
        }
    }
}