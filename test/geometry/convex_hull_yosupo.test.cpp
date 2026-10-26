#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include "../../src/geometry/convex_hull.hpp"

#include <iostream>
#include <vector>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<geometry::Point<int>> P(N);
        for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;
        auto C = geometry::convex_hull<int>(P, true);
        cout << C.size() << '\n';
        for (auto p : C) cout << p.x << ' ' << p.y << '\n';
    }
}