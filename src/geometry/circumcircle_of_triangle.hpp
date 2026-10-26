#pragma once
#include "line.hpp"
#include "circle.hpp"
using namespace std;

namespace geometry {

template<typename T>
Circle<T> circumcircle_of_triangle(const Point<T> &p1, const Point<T> &p2, const Point<T> &p3) {
    static_assert(is_floating_point_v<T>);
    Point<T> p12 = p1 - p2, p23 = p2 - p3;
    T d = 2 * cross(p12, p23);
    T t12 = norm(p1) - norm(p2), t23 = norm(p2) - norm(p3);
    Point<T> p = (t12 * p23 - t23 * p12) / d;
    swap(p.x, p.y);
    p.y = -p.y;
    T r = dist(p, p1);
    return Circle<T>(p, r);
}

} // namespace geometry