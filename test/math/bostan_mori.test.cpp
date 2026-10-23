#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include "../../src/modint/modint.hpp"
#include "../../src/math/bostan_mori.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    long long K;
    cin >> N >> K;
    vector<mint> A(N), C(N);
    for (auto &e : A) {int x; cin >> x; e = x; }
    for (auto &e : C) {int x; cin >> x; e = x; }
    cout << linear_recurrence(A, C, K).val() << endl;
}