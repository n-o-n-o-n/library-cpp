#define PROBLEM "https://judge.yosupo.jp/problem/ordered_set"

#include "../../../src/data_structure/misc/binary_trie.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    binary_trie<int> bt;
    int N, Q;
    cin >> N >> Q;
    for (int a; N--; ) {
        cin >> a;
        bt.insert(a);
    }
    for (int t, x; Q--; ) {
        cin >> t >> x;
        if (t == 0) {
            bt.insert(x);
        } else if (t == 1) {
            bt.erase(x);
        } else if (t == 2) {
            cout << (x <= bt.size() ? bt.kth_smallest(x - 1) : -1) << '\n';
        } else if (t == 3) {
            cout << bt.lower_count(x + 1) << '\n';
        } else if (t == 4) {
            cout << bt.prev_val(x + 1) << '\n';
        } else {
            cout << bt.next_val(x - 1) << '\n';
        }
    }
}