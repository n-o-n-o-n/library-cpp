#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include "../../../src/template.hpp"
#include "../../../src/modint/modint.hpp"
#include "../../../src/math/enumerative_combinatorics/partition.hpp"


using mint = modint998244353;

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