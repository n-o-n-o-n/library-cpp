#pragma once
#include "line.hpp"
#include "circle.hpp"
using namespace std;

namespace geometry {

template<typename T>
Circle<T> incircle_of_triangle(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) {
    static_assert(is_floating_point_v<T>);
    T a1 = dist(p2, p3), a2 = dist(p3, p1), a3 = dist(p1, p2);
    Point<T> p = a1 * p1 + a2 * p2 + a3 * p3;
    p /= a1 + a2 + a3;
    T r = Line<T>(p1, p2).dist(p);
    return Circle<T>(p, r);
}

} // namespace geometry