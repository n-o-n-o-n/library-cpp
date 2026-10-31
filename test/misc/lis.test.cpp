#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "../../src/misc/lis.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    auto lis = longest_increasing_subsequence(A);
    cout << ssize(lis) << '\n';
    for (int i = 0; i < ssize(lis); i++) cout << lis[i] << " \n"[i + 1 == ssize(lis)];
}