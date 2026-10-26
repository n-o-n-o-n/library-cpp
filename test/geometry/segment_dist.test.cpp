#define ERROR 0.00000001

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_D"

#include "../../src/geometry/segment.hpp"

#include <iomanip>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    for (geometry::Point<double> P0, P1, P2, P3; Q--; ) {
        cin >> P0.x >> P0.y >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y;
        geometry::Segment<double> S1(P0, P1), S2(P2, P3);
        cout << fixed << setprecision(16) << geometry::dist(S1, S2) << '\n';
    }
}