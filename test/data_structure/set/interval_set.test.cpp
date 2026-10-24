#define PROBLEM "https://yukicoder.me/problems/no/3017"

#include "../../../src/data_structure/set/interval_set.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    interval_set<int> S;
    int ans = 0;
    auto add = [&] (int l, int r) -> void { ans += r - l; };
    auto del = [&] (int l, int r) -> void { ans -= r - l; };
    for (int i = 0; i < N; i++) {
        int H;
        cin >> H;
        if (i % 2 == 0) {
            S.insert(0, H, add, del);
        } else {
            S.erase(0, H, add, del);
        }
        cout << ans << '\n';
    }
}