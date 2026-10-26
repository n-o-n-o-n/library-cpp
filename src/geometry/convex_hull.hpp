#pragma once
#include <algorithm>
#include <vector>
#include "common.hpp"
#include "polygon.hpp"
using namespace std;

namespace geometry {

template<typename T>
Polygon<T> convex_hull(vector<Point<T>> pts, bool exclude_collinear = true) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end(), [] (const Point<T> &p, const Point<T> &q) {
        return p.x == q.x && p.y == q.y;
    }), pts.end());
    int n = pts.size();
    if (n <= 1) return Polygon<T>(pts);
    auto turn = [] (const Point<T> &a, const Point<T> &b, const Point<T> &c) {
        W<T> d = cross(b - a, c - a);
        if constexpr (is_integral_v<T>) return (d > 0) - (d < 0);
        else return sgn(d);
    };
    bool collinear = true;
    for (int i = 1; i < n - 1; i++) {
        if (turn(pts[0], pts[n - 1], pts[i]) != 0) {
            collinear = false;
            break;
        }
    }
    if (collinear) {
        if (!exclude_collinear) return Polygon<T>(pts);
        return Polygon<T>(vector<Point<T>>{pts.front(), pts.back()});
    }
    auto remove = [&] (const Point<T> &a, const Point<T> &b, const Point<T> &c) {
        int d = turn(a, b, c);
        return exclude_collinear ? d <= 0 : d < 0;
    };
    vector<Point<T>> ch;
    ch.reserve(2 * n);
    for (const Point<T> &p : pts) {
        while (ch.size() >= 2 && remove(ch[ch.size() - 2], ch.back(), p)) ch.pop_back();
        ch.push_back(p);
    }
    int l = ch.size();
    for (int i = n - 2; i >= 0; i--) {
        while ((int)ch.size() > l && remove(ch[ch.size() - 2], ch.back(), pts[i])) ch.pop_back();
        ch.push_back(pts[i]);
    }
    ch.pop_back();
    return Polygon<T>(ch);
}

} // namespace geometry