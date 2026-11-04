#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include "../../../src/template.hpp"
#include "../../../src/modint/modint.hpp"
#include "../../../src/math/matrix/matrix.hpp"

using mint = modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M, K;
    cin >> N >> M >> K;
    matrix<mint> A(N, M), B(M, K);
    for (auto &E : A) for (auto &e : E) { int x; cin >> x; e = x; }
    for (auto &E : B) for (auto &e : E) { int x; cin >> x; e = x; }
    auto C = A * B;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) cout << C[i][j].val() << " \n"[j + 1 == K];
    }
}