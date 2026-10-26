#define ERROR 0.00000001

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"

#include "../../src/geometry/line.hpp"

#include <iomanip>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    geometry::Point<double> P1, P2;
    cin >> P1.x >> P1.y >> P2.x >> P2.y;
    geometry::Line<double> L(P1, P2);
    int Q;
    cin >> Q;
    for (geometry::Point<double> P; Q--; ) {
        cin >> P.x >> P.y;
        auto X = L.projection(P);
        cout << fixed << setprecision(10) << X.x << ' ' << X.y << '\n';
    }
}