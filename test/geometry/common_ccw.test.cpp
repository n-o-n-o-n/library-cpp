#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "../../src/geometry/common.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    geometry::Point<int> P0, P1;
    cin >> P0.x >> P0.y >> P1.x >> P1.y;
    int Q;
    cin >> Q;
    for (geometry::Point<int> P2; Q--; ) {
        cin >> P2.x >> P2.y;
        int t = geometry::ccw(P0, P1, P2);
        if (t == 1) cout << "COUNTER_CLOCKWISE\n";
        else if (t == -1) cout << "CLOCKWISE\n";
        else if (t == 2) cout << "ONLINE_BACK\n";
        else if (t == -2) cout << "ONLINE_FRONT\n";
        else cout << "ON_SEGMENT\n";
    }
}