#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/matrix/matrix.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    matrix<mint> A(N, N);
    for (auto &E : A) for (auto &e : E) { int x; cin >> x; e = x; }
    if (A.det() == 0) {
        cout << -1 << '\n';
        return 0;
    }
    A = A.inv();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cout << A[i][j].val() << " \n"[j + 1 ==  N];
    }
}