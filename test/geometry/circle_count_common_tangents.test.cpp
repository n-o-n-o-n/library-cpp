#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A"

#include "../../src/geometry/circle.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    geometry::Point<int> P1, P2;
    int R1, R2;
    cin >> P1.x >> P1.y >> R1;
    cin >> P2.x >> P2.y >> R2;
    geometry::Circle<int> C1(P1, R1), C2(P2, R2);
    cout << geometry::count_common_tangents(C1, C2) << '\n';
}