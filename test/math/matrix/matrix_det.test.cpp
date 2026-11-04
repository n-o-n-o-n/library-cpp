#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../../src/template.hpp"
#include "../../../src/modint/modint.hpp"
#include "../../../src/math/matrix/matrix.hpp"

using mint = modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    matrix<mint> A(N, N);
    for (auto &E : A) for (auto &e : E) { int x; cin >> x; e = x; }
    cout << A.det().val() << '\n';
}