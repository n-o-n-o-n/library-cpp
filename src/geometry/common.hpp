#pragma once
#include <cmath>
#include <numeric>
#include <type_traits>
#include <utility>
using namespace std;

namespace geometry {

template<typename T>
using W = conditional_t<is_integral_v<T>, conditional_t<sizeof(T) <= 4, long long, __int128_t>, T>;

template<typename T>
constexpr T eps() { return is_integral_v<T> ? T(0) : T(1e-12L); }

template<typename T>
constexpr T inf() { return numeric_limits<T>::max(); }

template<typename T>
constexpr T PI() {
    static_assert(is_floating_point_v<T>);
    return (T)acosl(-1);
}

template<typename T>
inline bool eq(T a, T b) {
    if constexpr (is_integral_v<T>) {
        return a == b;
    } else {
        return abs(a - b) < eps<T>();
    }
}

template<typename T>
inline int sgn(T a) { return eq<T>(a, 0) ? 0 : a > 0 ? 1 : -1; }

template<typename T>
struct Point {
    T x, y;
    constexpr Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    constexpr Point(const pair<T, T> &pt) : x(pt.first), y(pt.second) {}
    static constexpr Point inf_point() { return Point(inf<T>(), inf<T>()); }
    Point &operator+=(const Point &p) {
        x += p.x;
        y += p.y;
        return *this;
    }
    Point &operator-=(const Point &p) {
        x -= p.x;
        y -= p.y;
        return *this;
    }
    Point &operator*=(const T &r) {
        x *= r;
        y *= r;
        return *this;
    }
    Point &operator/=(const T &r) {
        x /= r;
        y /= r;
        return *this;
    }
    Point operator+(const Point &p) const { return Point(*this) += p; }
    Point operator-(const Point &p) const { return Point(*this) -= p; }
    Point operator*(const T &r) const { return Point(*this) *= r; }
    Point operator/(const T &r) const { return Point(*this) /= r; }
    Point operator+() const { return *this; }
    Point operator-() const { return Point() - *this; }
    bool operator==(const Point &p) const { return eq(x, p.x) && eq(y, p.y); }
    bool operator!=(const Point &p) const { return !this->operator==(p); }
    bool operator<(const Point &p) const { return x == p.x ? y < p.y : x < p.x; }
    bool operator>(const Point &p) const { return x == p.x ? y > p.y : x > p.x; }
    bool operator<=(const Point &p) const { return this->operator==(p) || this->operator<(p); }
    bool operator>=(const Point &p) const { return this->operator==(p) || this->operator>(p); }
    friend Point operator*(T r, const Point &p) { return p * r; }
    W<T> norm() const { return (W<T>)x * x + (W<T>)y * y; }
    T dist() const {
        static_assert(is_floating_point_v<T>);
        return sqrtl(norm());
    }
    T arg() const {
        static_assert(is_floating_point_v<T>);
        return atan2l(y, x);
    }
    Point unit() const {
        return (*this) / dist();
    }
    Point rotate(T rad) const {
        static_assert(is_floating_point_v<T>);
        T c = cosl(rad), s = sinl(rad);
        T tx = x * c - y * s;
        T ty = x * s + y * c;
        return Point(tx, ty);
    }
};

template<typename T>
inline W<T> dot(const Point<T> &p, const Point<T> &q) { return (W<T>)p.x * q.x + (W<T>)p.y * q.y; }

template<typename T>
inline W<T> cross(const Point<T> &p, const Point<T> &q) { return (W<T>)p.x * q.y - (W<T>)p.y * q.x; }

template<typename T>
inline W<T> norm(const Point<T> &p) { return p.norm(); }

template<typename T>
inline T dist(const Point<T> &p) { return p.dist(); }

template<typename T>
inline T dist(const Point<T> &p, const Point<T> &q) { return dist(p - q); }

template<typename T>
inline T arg(const Point<T> &p) { return p.arg(); }

template<typename T>
inline T angle(Point<T> o, Point<T> p, Point<T> q) {
    static_assert(is_floating_point_v<T>);
    p -= o, q -= o;
    return atan2l(cross(p, q), dot(p, q));
}

template<typename T>
inline bool eq(const Point<T> &p, const Point<T> &q) {
    return eq<T>(p.x, q.x) && eq<T>(p.y, q.y);
}

template<typename T>
inline int ccw(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    Point<T> p = b - a, q = c - a;
    W<T> e = eps<T>();
    W<T> cr = cross(p, q);
    if (cr > e) return 1;
    if (cr < -e) return -1;
    W<T> pn = norm(p), qn = norm(q);
    if (min(pn, qn) <= e * e) return 0;
    if (dot(p, q) < e) return 2;
    if (pn < qn) return -2;
    return 0;
}

}  // namespace geometry