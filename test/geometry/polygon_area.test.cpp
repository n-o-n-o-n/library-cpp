#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"

#include "../../src/geometry/polygon.hpp"

#include <iomanip>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    geometry::Polygon<int> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].x >> V[i].y;
    cout << fixed << setprecision(1) << 0.5 * geometry::area(V) << endl;
}