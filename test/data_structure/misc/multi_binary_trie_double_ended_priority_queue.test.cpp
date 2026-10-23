#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include "../../../src/data_structure/misc/multi_binary_trie.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    constexpr int offset = 1000000000;
    multi_binary_trie<int> mbt;
    for (int a; N--; ) {
        cin >> a;
        mbt.insert(a + offset);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int x;
            cin >> x;
            mbt.insert(x + offset);
        } else if (t == 1) {
            int mn = mbt.min();
            cout << mn - offset << '\n';
            mbt.erase(mn);
        } else {
            int mx = mbt.max();
            cout << mx - offset << '\n';
            mbt.erase(mx);
        }
    }
}
