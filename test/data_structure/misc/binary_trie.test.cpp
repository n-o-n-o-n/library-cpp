#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../../src/data_structure/misc/binary_trie.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    binary_trie<int, 30> bt;
    int Q;
    cin >> Q;
    for (int t, x; Q--; ) {
        cin >> t >> x;
        if (t == 0) {
            bt.insert(x);
        } else if (t == 1) {
            bt.erase(x);
        } else {
            cout << bt.min(x) << '\n';
        }
    }
}