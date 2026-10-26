#define ERROR 0.000001

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B"

#include "../../src/geometry/polygon.hpp"

#include <iomanip>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    geometry::Polygon<double> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].x >> V[i].y;
    auto [i, j] = geometry::diam(V);
    cout << fixed << setprecision(16) << geometry::dist(V[i], V[j]) << '\n';
}