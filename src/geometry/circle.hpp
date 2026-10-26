#pragma once
#include <array>
#include "line.hpp"
using namespace std;

namespace geometry {

template<typename T>
struct Circle {
    Point<T> p;
    T r;
    static constexpr Point<T> ip = Point<T>::inf_point();
    constexpr Circle() = default;
    constexpr Circle(const Point<T> &_p, const T &_r) : p(_p), r(_r) {}
    int count_common_tangents(const Circle<T> &other) const {
        if (eq(p, other.p) && eq(r, other.r)) return -1;
        W<T> s = r + other.r, d = abs(r - other.r);
        W<T> d2 = norm(p - other.p);
        auto comp = [d2] (W<T> x) {
            W<T> d = d2 - x * x;
            W<T> b = eps<T>() * (2 * x + eps<T>());
            return d > b ? 1 : d < -b ? -1 : 0;
        };
        int out = comp(s), in = comp(d);
        if (out > 0) return 4;
        if (out == 0) return 3;
        if (in < 0) return 0;
        if (in == 0) return 1;
        return 2;
    }
    array<Point<T>, 2> crosspoint(const Line<T> &l) const {
        static_assert(is_floating_point_v<T>);
        T d = l.dist(p);
        if (d > r + eps<T>()) return {ip, ip};
        Point<T> q = l.projection(p);
        if (eq(d, r)) return {q, q};
        Point<T> e = l.unit();
        T t = sqrtl(r * r - d * d);
        return {q - t * e, q + t * e};
    }
    array<Point<T>, 2> crosspoint(const Circle<T> &c) const {
        static_assert(is_floating_point_v<T>);
        int t = count_common_tangents(c);
        if (t == -1 || t == 0 || t == 4) return {ip, ip};
        T d = dist(p, c.p);
        if (t == 1) {
            if (c.r < r - eps<T>()) {
                Point<T> q = p + (c.p - p) * (r / d);
                return {q, q};
            } else {
                Point<T> q = c.p + (p - c.p) * (c.r / d);
                return {q, q};
            }
        } else if (t == 3) {
            T s = r / (r + c.r);
            Point<T> q = p + (c.p - p) * s;
            return {q, q};
        } else {
            T la = 2 * (p.x - c.p.x);
            T lb = 2 * (p.y - c.p.y);
            T lc = (p.x + c.p.x) * (c.p.x - p.x) + (p.y + c.p.y) * (c.p.y - p.y) + (r + c.r) * (r - c.r);
            return crosspoint(Line(la, lb, lc));
        }
    }
    array<Point<T>, 2> tangent_points(const Point<T> &q) const {
        static_assert(is_floating_point_v<T>);
        T d = dist(p, q);
        if (d < r - eps<T>()) return {ip, ip};
        if (eq(d, r)) return {q, q};
        return crosspoint(Circle<T>(q, sqrtl(d * d - r * r)));
    }
    array<Line<T>, 4> common_tangents(const Circle &c) const {
        static_assert(is_floating_point_v<T>);
        T d = dist(p, c.p);
        if (eq<T>(d, 0)) return {};
        Point<T> u = (c.p - p) / d;
        Point<T> v(-u.y, u.x);
        array<Line<T>, 4> res{};
        int k = 0;
        auto add = [&] (const Point<T> &n) {
            res[k++] = Line<T>(n.x, n.y, -dot(n, p) - r);
        };
        for (int s : {-1, 1}) {
            T h = (r + s * c.r) / d;
            if (eq<T>(h * h, 1)) {
                add(h > 0 ? u : -u);
            } else if (1 - h * h > 0) {
                Point<T> u2 = u * h, v2 = v * sqrtl(1 - h * h);
                add(u2 + v2);
                add(u2 - v2);
            }
        }
        return res;
    }
};

template<typename T>
inline int count_common_tangents(const Circle<T> &c1, const Circle<T> &c2) { return c1.count_common_tangents(c2); }
template<typename T>
inline array<Point<T>, 2> crosspoint(const Circle<T> &c, const Line<T> &l) { return c.crosspoint(l); }
template<typename T>
inline array<Point<T>, 2> crosspoint(const Line<T> &l, const Circle<T> &c) { return c.crosspoint(l); }
template<typename T>
inline array<Point<T>, 2> crosspoint(const Circle<T> &c1, const Circle<T> &c2) { return c1.crosspoint(c2); }
template<typename T>
inline array<Point<T>, 2> tangent_points(const Circle<T> &c, const Point<T> &p) { return c.tangent_points(p); }
template<typename T>
inline array<Point<T>, 2> tangent_points(const Point<T> &p, const Circle<T> &c) { return c.tangent_points(p); }
template<typename T>
inline array<Line<T>, 4> common_tangents(const Circle<T> &c1, const Circle<T> &c2) { return c1.common_tangents(c2); }

} // namespace geometry
