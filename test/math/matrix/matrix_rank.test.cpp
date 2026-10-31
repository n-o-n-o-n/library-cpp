#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/matrix/matrix.hpp"

using mint = modint<998244353>;

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    matrix<mint> A(N, M);
    for (auto &E : A) for (auto &e : E) { int x; cin >> x; e = x; }
    cout << A.rank() << '\n';
}