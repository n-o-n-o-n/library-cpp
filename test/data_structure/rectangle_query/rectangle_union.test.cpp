#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "../../../src/data_structure/rectangle_query/rectangle_union.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    rectangle_union<long long> ru(N);
    for (int xl, yl, xr, yr; N--; ) {
        cin >> xl >> yl >> xr >> yr;
        ru.add_rectangle(xl, yl, xr, yr);
    }
    cout << ru.solve() << '\n';
}