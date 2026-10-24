#define PROBLEM "https://yukicoder.me/problems/no/3298"

#include "../../../src/data_structure/set/top_k_set.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K, Q;
    cin >> N >> K >> Q;
    top_k_set<long long> S(K);
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        S.insert(a);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            long long x;
            cin >> x;
            S.insert(x);
        } else if (t == 2) {
            long long y;
            cin >> y;
            long long x = S.kth_val();
            S.erase(x);
            S.insert(x + y);
        } else {
            cout << S.kth_val() << '\n';
        }
    }
}