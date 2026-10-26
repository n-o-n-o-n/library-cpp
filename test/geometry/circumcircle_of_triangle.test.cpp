#define ERROR 0.000001

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C"

#include "../../src/geometry/circumcircle_of_triangle.hpp"

#include <iomanip>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    geometry::Point<double> P1, P2, P3;
    cin >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y;
    geometry::Circle<double> C = geometry::circumcircle_of_triangle(P1, P2, P3);
    cout << fixed << setprecision(16) << C.p.x << ' ' << C.p.y << ' ' << C.r << '\n';
}