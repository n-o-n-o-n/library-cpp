#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "../../src/modint/modint.hpp"
#include "../../src/math/berlekamp_massey.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<mint> A(N);
    for (mint &e : A) { int x; cin >> x; e = x; }
    auto C = Berlekamp_Massey(A);
    C.erase(C.begin());
    cout << ssize(C) << '\n';
    for (int i = 0; i < ssize(C); i++) {
        cout << C[i].val() << " \n"[i + 1 == ssize(C)];
    }
}