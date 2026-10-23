#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include "../../../src/modint/modint.hpp"
#include "../../../src/math/enumerative_combinatorics/partition.hpp"

#include <iostream>

using mint = modint<998244353>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    auto P = partition<mint>(N);
    for (int i = 0; i <= N; i++) {
        cout << P[i].val() << " \n"[i == N];
    }
}