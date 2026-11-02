#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"

#include "../../src/template.hpp"
#include "../../src/convolution/min_plus_convolution_convex_arbitrary.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (auto &e : A) cin >> e;
    for (auto &e : B) cin >> e;
    auto C = min_plus_convolution(A, B);
    for (int i = 0; i < ssize(C); i++) cout << C[i] << " \n"[i + 1 == ssize(C)];
}