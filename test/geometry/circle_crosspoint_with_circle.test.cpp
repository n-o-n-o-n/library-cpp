#define ERROR 0.000001

#include "../../src/geometry/circle.hpp"

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"

#include <iomanip>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    geometry::Point<double> P1, P2;
    double R1, R2;
    cin >> P1.x >> P1.y >> R1;
    cin >> P2.x >> P2.y >> R2;
    geometry::Circle<double> C1(P1, R1), C2(P2, R2);
    array<geometry::Point<double>, 2> cp = geometry::crosspoint(C1, C2);
    if (cp[0] > cp[1]) swap(cp[0], cp[1]);
    cout << fixed << setprecision(16) << cp[0].x << ' ' << cp[0].y << ' ' << cp[1].x << ' ' << cp[1].y << '\n';
}