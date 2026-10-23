#define PROBLEM "https://judge.yosupo.jp/problem/aho_corasick"

#include "../../src/string/aho_corasick.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    aho_corasick<26, 'a'> ac;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        ac.insert(S);
    }
    ac.build();
    int n = ac.par.size();
    cout << n << '\n';
    for (int i = 1; i < n; i++) cout << ac.par[i] << ' ' << ac.fail[i] << '\n';
    for (int i = 0; i < N; i++) cout << ac.last[i] << " \n"[i + 1 == N];
}
