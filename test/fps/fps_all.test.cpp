#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

// include して正しくコンパイルできるかをテスト
// 中身は個別の test でチェック
#include "../../src/fps/fps_all.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    cin >> A >> B;
    cout << A + B << '\n';
}