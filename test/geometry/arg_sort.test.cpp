#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include "../../src/geometry/arg_sort.hpp"

#include <algorithm>
#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<geometry::Point<int>> Ps(N);
    for (int i = 0; i < N; i++) cin >> Ps[i].x >> Ps[i].y;
    auto ord = geometry::arg_sort<int>(Ps);
    auto it = find_if(ord.begin(), ord.end(), [&] (int i) { return Ps[i].y < 0; });
    rotate(ord.begin(), it, ord.end());
    for (int i = 0; i < N; i++) {
        cout << Ps[ord[i]].x << ' ' << Ps[ord[i]].y << '\n';
    }
}
