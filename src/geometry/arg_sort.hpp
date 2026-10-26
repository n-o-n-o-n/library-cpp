#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
#include "common.hpp"
using namespace std;

namespace geometry {

template<typename T>
vector<int> arg_sort(const vector<Point<T>> &ps) {
    vector<int> ord(ps.size());
    iota(ord.begin(), ord.end(), 0);
    auto half = [&] (const Point<T> &p) {
        return p.y > 0 || (p.y == 0 && p.x >= 0) ? 0 : 1;
    };
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        int a = half(ps[i]), b = half(ps[j]);
        if (a != b) return a < b;
        W<T> cr = cross(ps[i], ps[j]);
        if (cr != 0) return cr > 0;
        W<T> ni = norm(ps[i]), nj = norm(ps[j]);
        if (ni != nj) return ni < nj;
        return i < j;
    });
    return ord;
}

}  // namespace geometry
