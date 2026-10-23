#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../src/string/rolling_hash_static.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    int N = S.size();
    rolling_hash::set_base(998244351);
    rolling_hash rh(S);
    for (int i = 0; i < N; i++) {
        int l = 0, r = N - i + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            auto h0 = rh.prod(0, m);
            auto hi = rh.prod(i, i + m);
            (h0 == hi ? l : r) = m;
        }
        cout << l << " \n"[i + 1 == N];
    }
}