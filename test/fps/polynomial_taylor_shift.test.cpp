#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"

#include "../../src/template.hpp"
#include "../../src/fps/polynomial_taylor_shift.hpp"
#include "../../src/modint/modint.hpp"

using mint = modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, c;
    cin >> N >> c;
    fps<mint> f(N);
    for (auto &e : f) { int a; cin >> a; e = a; }
    f = f.taylor_shift(c);
    for (int i = 0; i < N; i++) cout << f[i].val() << " \n"[i + 1 == N];
}