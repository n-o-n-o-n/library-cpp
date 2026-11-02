#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

// include して正しくコンパイルできるかをテスト
// 中身は個別の test でチェック
#include "../../src/template.hpp"
#include "../../src/fps/fps_all.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B;
    cin >> A >> B;
    cout << A + B << '\n';
}