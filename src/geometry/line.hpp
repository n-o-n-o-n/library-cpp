#pragma once
#include "common.hpp"

namespace geometry {

template<typename T>
struct Line {
    constexpr Line() = default;
    constexpr Line(T _a, T _b, T _c) : a(_a), b(_b), c(_c) {}
    constexpr Line(const Point<T> &p, const Point<T> &q) : a(q.y - p.y), b(p.x - q.x), c((W<T>)p.y * q.x - (W<T>)p.x * q.y) {}
    constexpr Line(T _a, const Point<T> &p) : a(_a), b(-1), c(p.y - (W<T>)_a * p.x) {}
    bool online(const Point<T> &p) const { return eq<W<T>>((W<T>)a * p.x + (W<T>)b * p.y + c, 0); }
    W<T> get_x(T y) const { return eq<T>(a, 0) ? inf<T>() : (- c - (W<T>)b * y) / a; }
    W<T> get_y(T x) const { return eq<T>(b, 0) ? inf<T>() : (- c - (W<T>)a * x) / b; }
    Line perpendicular(const Point<T> &p) const {
        static_assert(is_floating_point_v<T>);
        if (eq<T>(a, 0)) return Line(1, 0, - p.x);
        if (eq<T>(0, b)) return Line(0, 1, - p.y);
        return Line(b / a, p);
    }
    Point<T> crossppoint(const Line &l) const {
        static_assert(is_floating_point_v<T>);
        if (eq<T>(a * l.b, l.a * b)) return Point<T>::inf_point();
        T d = a * l.b - l.a * b;
        return Point<T>(b * l.c - c * l.b, c * l.a - a * l.c) / d;
    }
    Point<T> projection(const Point<T> &p) const {
        static_assert(is_floating_point_v<T>);
        return crossppoint(perpendicular(p));
    }
    Point<T> reflection(const Point<T> &p) const {
        static_assert(is_floating_point_v<T>);
        Point q = projection(p);
        return 2 * q - p;
    }
    Point<T> unit() const {
        static_assert(is_floating_point_v<T>);
        if (eq<T>(b, 0)) return Point<T>(0, 1);
        Point<T> p(0, get_y(0)), q(1, get_y(1));
        return (p - q) / (p - q).dist();
    }
    bool is_orthogonal(const Line &l) const { return eq<W<T>>((W<T>)a * l.a + (W<T>)b * l.b, 0); }
    bool is_parallel(const Line &l) const { return eq<W<T>>((W<T>)a * l.b, (W<T>)b * l.a); }
    T dist(const Point<T> &p) const {
        static_assert(is_floating_point_v<T>);
        Point q = projection(p);
        return (p - q).dist();
    }
private:
    T a, b, c; // ax+by+c=0
};

template<typename T>
inline bool is_orthogonal(const Line<T> &l1, const Line<T> &l2) { return l1.is_orthogonal(l2); }
template<typename T>
inline bool is_parallel(const Line<T> &l1, const Line<T> &l2) { return l1.is_parallel(l2); }
template<typename T>
inline Point<T> crosspoint(const Line<T> &l1, const Line<T> &l2) { return l1.crossppoint(l2); }
template<typename T>
inline T dist(const Line<T> &l, const Point<T> &p) { return l.dist(p); }
template<typename T>
inline T dist(const Point<T> &p, const Line<T> &l) { return l.dist(p); }


} // namespace geometry