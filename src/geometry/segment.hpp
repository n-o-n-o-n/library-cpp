#pragma once
#include "line.hpp"

namespace geometry {

template<typename T>
struct Segment {
    constexpr Segment() = default;
    constexpr Segment(const Point<T> &_a, const Point<T> &_b) : l(_a, _b), a(_a), b(_b) {}
    bool intersect(const Segment &s) const {
        bool f1 = ccw(a, b, s.a) * ccw(a, b, s.b) <= 0;
        bool f2 = ccw(s.a, s.b, a) * ccw(s.a, s.b, b) <= 0;
        return f1 && f2;
    }
    bool on_segment(const Point<T> &p) const {
        Point<T> ab = b - a, ap = p - a, bp = p - b;
        if (!eq<W<T>>(cross(ab, ap), 0)) return false;
        return dot(ab, ap) >= -eps<T>() && dot(ab, bp) <= eps<T>();
    }
    Point<T> crosspoint(const Segment &s) const {
        static_assert(is_floating_point_v<T>);
        if (!intersect(s)) return Point<T>::inf_point();
        if (!l.is_parallel(s.l)) return l.crossppoint(s.l);
        auto less = [] (const Point<T> &p, const Point<T> &q) {
            return p.x < q.x || (p.x == q.x && p.y < q.y);
        };
        Point<T> p = less(a, b) ? a : b;
        Point<T> q = less(s.a, s.b) ? s.a : s.b;
        return less(p, q) ? q : p;
    }
    T dist(const Point<T> &p) const {
        static_assert(is_floating_point_v<T>);
        if (dot(b - a, p - a) < eps<T>()) return (p - a).dist();
        if (dot(a - b, p - b) < eps<T>()) return (p - b).dist();
        return l.dist(p);
    }
    T dist(const Segment &s) const {
        static_assert(is_floating_point_v<T>);
        if (intersect(s)) return 0;
        T res = inf<T>();
        res = min(res, dist(s.a));
        res = min(res, dist(s.b));
        res = min(res, s.dist(a));
        res = min(res, s.dist(b));
        return res;
    }
private:
    Line<T> l;
    Point<T> a, b;
};

template<typename T>
inline bool intersect(const Segment<T> &s1, const Segment<T> &s2) { return s1.intersect(s2); }
template<typename T>
inline Point<T> crosspoint(const Segment<T> &s1, const Segment<T> &s2) { return s1.crosspoint(s2); }
template<typename T>
inline T dist(const Segment<T> &s, const Point<T> &p) { return s.dist(p); }
template<typename T>
inline T dist(const Point<T> &p, const Segment<T> &s) { return s.dist(p); }
template<typename T>
inline T dist(const Segment<T> &s1, const Segment<T> &s2) { return s1.dist(s2); }

} // namespace geometry