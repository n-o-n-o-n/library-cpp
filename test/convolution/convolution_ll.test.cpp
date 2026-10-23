#define PROBLEM "https://yukicoder.me/problems/no/1307"

#include "../../src/convolution/convolution_ll.hpp"

#include <iostream>

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N), B(N);
    for (auto &x : A) cin >> x;
    for (int r; Q--; ) {
        cin >> r;
        B[(N - r) % N]++;
    }
    auto C = convolution_ll(A, B);
    vector<ll> ans(N);
    for (int i = 0; i < ssize(C); i++) ans[i % N] += C[i];
    for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i + 1 == N];
}
