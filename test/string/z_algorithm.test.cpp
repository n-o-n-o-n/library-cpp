#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../src/template.hpp"
#include "../../src/string/z_algorithm.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    auto Z = z_algorithm(S);
    for (int i = 0; i < ssize(Z); i++) {
        cout << Z[i] << " \n"[i + 1 == ssize(Z)];
    }
}