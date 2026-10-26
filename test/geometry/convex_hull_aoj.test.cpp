#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"

#include "../../src/geometry/convex_hull.hpp"

#include <iostream>
#include <vector>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<geometry::Point<int>> P(N);
    for (int i = 0; i < N; i++) cin >> P[i].x >> P[i].y;
    auto C = geometry::convex_hull<int>(P, false);
    C.relabeling();
    cout << C.size() << '\n';
    for (auto p : C) cout << p.x << ' ' << p.y << '\n';
}