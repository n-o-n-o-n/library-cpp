#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "../../src/string/lcp_array.hpp"
#include "../../src/string/suffix_array.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    int N = S.size();
    auto sa = suffix_array(S);
    long long ans = (long long)N * (N + 1) / 2;
    for (auto e : lcp_array(S, sa)) ans -= e;
    cout << ans << endl;
}