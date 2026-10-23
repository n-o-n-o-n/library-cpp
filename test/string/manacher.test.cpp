#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include "../../src/string/manacher.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    auto ans = manacher(S);
    for (int i = 0; i < ssize(ans); i++) {
        cout << ans[i] << " \n"[i + 1 == ssize(ans)];
    }
}