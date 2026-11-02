#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include "../../src/template.hpp"
#include "../../src/tree/cartesian_tree.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    auto P = cartesian_tree(A);
    for (int i = 0; i < N; i++) cout << (P[i] == -1 ? i : P[i]) << " \n"[i + 1 == N];
}