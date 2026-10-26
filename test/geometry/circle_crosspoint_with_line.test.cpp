#define ERROR 0.000001

#include "../../src/geometry/circle.hpp"

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D"

#include <iomanip>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    geometry::Point<double> P;
    double R;
    cin >> P.x >> P.y >> R;
    geometry::Circle<double> C(P, R);
    int Q;
    cin >> Q;
    for (geometry::Point<double> P1, P2; Q--; ) {
        cin >> P1.x >> P1.y >> P2.x >> P2.y;
        geometry::Line<double> L(P1, P2);
        array<geometry::Point<double>, 2> cp = geometry::crosspoint(C, L);
        if (cp[0] > cp[1]) swap(cp[0], cp[1]);
        cout << fixed << setprecision(16) << cp[0].x << ' ' << cp[0].y << ' ' << cp[1].x << ' ' << cp[1].y << '\n';
    }
}