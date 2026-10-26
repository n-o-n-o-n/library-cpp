#define ERROR 0.000001

#include "../../src/geometry/circle.hpp"

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G"

#include <algorithm>
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
    int K = geometry::count_common_tangents(C1, C2);
    array<geometry::Line<double>, 4> ls = geometry::common_tangents(C1, C2);
    array<geometry::Point<double>, 4> tans;
    for (int i = 0; i < K; i++) tans[i] = ls[i].projection(C1.p);
    sort(tans.begin(), tans.begin() + K, [] (const geometry::Point<double> &p, const geometry::Point<double> &q) {
        return pair{roundl(p.x * 1e9L), roundl(p.y * 1e9L)} < pair{roundl(q.x * 1e9L), roundl(q.y * 1e9L)};
    });
    for (int i = 0; i < K; i++) {
        cout << fixed << setprecision(16) << tans[i].x << ' ' << tans[i].y << '\n';
    }
}
