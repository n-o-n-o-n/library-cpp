#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C"

#include "../../src/geometry/polygon.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    geometry::Polygon<int> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].x >> V[i].y;
    int Q;
    cin >> Q;
    for (geometry::Point<int> P; Q--; ) {
        cin >> P.x >> P.y;
        cout << geometry::contain(V, P) << '\n';
    }
}