#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"

#include "../../src/geometry/line.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    for (geometry::Point<int> P0, P1, P2, P3; Q--; ) {
        cin >> P0.x >> P0.y >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y;
        geometry::Line<int> S1(P0, P1), S2(P2, P3);
        if (geometry::is_parallel(S1, S2)) {
            cout << 2 << '\n';
        } else if (geometry::is_orthogonal(S1, S2)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}