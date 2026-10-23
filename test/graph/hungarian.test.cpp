#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include "../../src/graph/hungarian.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<long long>> A(N, vector<long long>(N));
    for (auto &E : A) for (auto &e : E) cin >> e;
    auto ans = hungarian(A);
    long long X = 0;
    for (auto [i, j] : ans) X += A[i][j];
    cout << X << '\n';
    for (auto [i, j] : ans) {
        if (i) cout << ' ';
        cout << j;
    }
    cout << '\n';
}