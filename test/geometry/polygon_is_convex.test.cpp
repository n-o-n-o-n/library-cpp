#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B"

#include "../../src/geometry/polygon.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    geometry::Polygon<int> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].x >> V[i].y;
    cout << (V.is_convex() ? 1 : 0) << endl;
}