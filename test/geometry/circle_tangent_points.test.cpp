#define ERROR 0.000001

#include "../../src/geometry/circle.hpp"

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F"

#include <iomanip>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    geometry::Point<double> Q, P;
    double R;
    cin >> Q.x >> Q.y;
    cin >> P.x >> P.y >> R;
    geometry::Circle<double> C(P, R);
    array<geometry::Point<double>, 2> cp = geometry::tangent_points(C, Q);
    if (cp[0] > cp[1]) swap(cp[0], cp[1]);
    cout << fixed << setprecision(16) << cp[0].x << ' ' << cp[0].y << '\n' << cp[1].x << ' ' << cp[1].y << '\n';
}