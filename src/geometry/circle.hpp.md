---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/common.hpp
    title: Common
  - icon: ':heavy_check_mark:'
    path: src/geometry/line.hpp
    title: Line
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/circumcircle_of_triangle.hpp
    title: src/geometry/circumcircle_of_triangle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/incircle_of_triangle.hpp
    title: src/geometry/incircle_of_triangle.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/circle_common_tangents.test.cpp
    title: test/geometry/circle_common_tangents.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/circle_count_common_tangents.test.cpp
    title: test/geometry/circle_count_common_tangents.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/circle_crosspoint_with_circle.test.cpp
    title: test/geometry/circle_crosspoint_with_circle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/circle_crosspoint_with_line.test.cpp
    title: test/geometry/circle_crosspoint_with_line.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/circle_tangent_points.test.cpp
    title: test/geometry/circle_tangent_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/circumcircle_of_triangle.test.cpp
    title: test/geometry/circumcircle_of_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/incircle_of_triangle.test.cpp
    title: test/geometry/incircle_of_triangle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/circle.hpp\"\n#include <array>\n#line 2 \"\
    src/geometry/common.hpp\"\n#include <cmath>\n#include <numeric>\n#include <type_traits>\n\
    #include <utility>\nusing namespace std;\n\nnamespace geometry {\n\ntemplate<typename\
    \ T>\nusing W = conditional_t<is_integral_v<T>, conditional_t<sizeof(T) <= 4,\
    \ long long, __int128_t>, T>;\n\ntemplate<typename T>\nconstexpr T eps() { return\
    \ is_integral_v<T> ? T(0) : T(1e-12L); }\n\ntemplate<typename T>\nconstexpr T\
    \ inf() { return numeric_limits<T>::max(); }\n\ntemplate<typename T>\nconstexpr\
    \ T PI() {\n    static_assert(is_floating_point_v<T>);\n    return (T)acosl(-1);\n\
    }\n\ntemplate<typename T>\ninline bool eq(T a, T b) {\n    if constexpr (is_integral_v<T>)\
    \ {\n        return a == b;\n    } else {\n        return abs(a - b) < eps<T>();\n\
    \    }\n}\n\ntemplate<typename T>\ninline int sgn(T a) { return eq<T>(a, 0) ?\
    \ 0 : a > 0 ? 1 : -1; }\n\ntemplate<typename T>\nstruct Point {\n    T x, y;\n\
    \    constexpr Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}\n    constexpr Point(const\
    \ pair<T, T> &pt) : x(pt.first), y(pt.second) {}\n    static constexpr Point inf_point()\
    \ { return Point(inf<T>(), inf<T>()); }\n    Point &operator+=(const Point &p)\
    \ {\n        x += p.x;\n        y += p.y;\n        return *this;\n    }\n    Point\
    \ &operator-=(const Point &p) {\n        x -= p.x;\n        y -= p.y;\n      \
    \  return *this;\n    }\n    Point &operator*=(const T &r) {\n        x *= r;\n\
    \        y *= r;\n        return *this;\n    }\n    Point &operator/=(const T\
    \ &r) {\n        x /= r;\n        y /= r;\n        return *this;\n    }\n    Point\
    \ operator+(const Point &p) const { return Point(*this) += p; }\n    Point operator-(const\
    \ Point &p) const { return Point(*this) -= p; }\n    Point operator*(const T &r)\
    \ const { return Point(*this) *= r; }\n    Point operator/(const T &r) const {\
    \ return Point(*this) /= r; }\n    Point operator+() const { return *this; }\n\
    \    Point operator-() const { return Point() - *this; }\n    bool operator==(const\
    \ Point &p) const { return eq(x, p.x) && eq(y, p.y); }\n    bool operator!=(const\
    \ Point &p) const { return !this->operator==(p); }\n    bool operator<(const Point\
    \ &p) const { return x == p.x ? y < p.y : x < p.x; }\n    bool operator>(const\
    \ Point &p) const { return x == p.x ? y > p.y : x > p.x; }\n    bool operator<=(const\
    \ Point &p) const { return this->operator==(p) || this->operator<(p); }\n    bool\
    \ operator>=(const Point &p) const { return this->operator==(p) || this->operator>(p);\
    \ }\n    friend Point operator*(T r, const Point &p) { return p * r; }\n    W<T>\
    \ norm() const { return (W<T>)x * x + (W<T>)y * y; }\n    T dist() const {\n \
    \       static_assert(is_floating_point_v<T>);\n        return sqrtl(norm());\n\
    \    }\n    T arg() const {\n        static_assert(is_floating_point_v<T>);\n\
    \        return atan2l(y, x);\n    }\n    Point unit() const {\n        return\
    \ (*this) / dist();\n    }\n    Point rotate(T rad) const {\n        static_assert(is_floating_point_v<T>);\n\
    \        T c = cosl(rad), s = sinl(rad);\n        T tx = x * c - y * s;\n    \
    \    T ty = x * s + y * c;\n        return Point(tx, ty);\n    }\n};\n\ntemplate<typename\
    \ T>\ninline W<T> dot(const Point<T> &p, const Point<T> &q) { return (W<T>)p.x\
    \ * q.x + (W<T>)p.y * q.y; }\n\ntemplate<typename T>\ninline W<T> cross(const\
    \ Point<T> &p, const Point<T> &q) { return (W<T>)p.x * q.y - (W<T>)p.y * q.x;\
    \ }\n\ntemplate<typename T>\ninline W<T> norm(const Point<T> &p) { return p.norm();\
    \ }\n\ntemplate<typename T>\ninline T dist(const Point<T> &p) { return p.dist();\
    \ }\n\ntemplate<typename T>\ninline T dist(const Point<T> &p, const Point<T> &q)\
    \ { return dist(p - q); }\n\ntemplate<typename T>\ninline T arg(const Point<T>\
    \ &p) { return p.arg(); }\n\ntemplate<typename T>\ninline T angle(Point<T> o,\
    \ Point<T> p, Point<T> q) {\n    static_assert(is_floating_point_v<T>);\n    p\
    \ -= o, q -= o;\n    return atan2l(cross(p, q), dot(p, q));\n}\n\ntemplate<typename\
    \ T>\ninline bool eq(const Point<T> &p, const Point<T> &q) {\n    return eq<T>(p.x,\
    \ q.x) && eq<T>(p.y, q.y);\n}\n\ntemplate<typename T>\ninline int ccw(const Point<T>\
    \ &a, const Point<T> &b, const Point<T> &c) {\n    Point<T> p = b - a, q = c -\
    \ a;\n    W<T> e = eps<T>();\n    W<T> cr = cross(p, q);\n    if (cr > e) return\
    \ 1;\n    if (cr < -e) return -1;\n    W<T> pn = norm(p), qn = norm(q);\n    if\
    \ (min(pn, qn) <= e * e) return 0;\n    if (dot(p, q) < e) return 2;\n    if (pn\
    \ < qn) return -2;\n    return 0;\n}\n\n}  // namespace geometry\n#line 3 \"src/geometry/line.hpp\"\
    \n\nnamespace geometry {\n\ntemplate<typename T>\nstruct Line {\n    constexpr\
    \ Line() = default;\n    constexpr Line(T _a, T _b, T _c) : a(_a), b(_b), c(_c)\
    \ {}\n    constexpr Line(const Point<T> &p, const Point<T> &q) : a(q.y - p.y),\
    \ b(p.x - q.x), c((W<T>)p.y * q.x - (W<T>)p.x * q.y) {}\n    constexpr Line(T\
    \ _a, const Point<T> &p) : a(_a), b(-1), c(p.y - (W<T>)_a * p.x) {}\n    bool\
    \ online(const Point<T> &p) const { return eq<W<T>>((W<T>)a * p.x + (W<T>)b *\
    \ p.y + c, 0); }\n    W<T> get_x(T y) const { return eq<T>(a, 0) ? inf<T>() :\
    \ (- c - (W<T>)b * y) / a; }\n    W<T> get_y(T x) const { return eq<T>(b, 0) ?\
    \ inf<T>() : (- c - (W<T>)a * x) / b; }\n    Line perpendicular(const Point<T>\
    \ &p) const {\n        static_assert(is_floating_point_v<T>);\n        if (eq<T>(a,\
    \ 0)) return Line(1, 0, - p.x);\n        if (eq<T>(0, b)) return Line(0, 1, -\
    \ p.y);\n        return Line(b / a, p);\n    }\n    Point<T> crossppoint(const\
    \ Line &l) const {\n        static_assert(is_floating_point_v<T>);\n        if\
    \ (eq<T>(a * l.b, l.a * b)) return Point<T>::inf_point();\n        T d = a * l.b\
    \ - l.a * b;\n        return Point<T>(b * l.c - c * l.b, c * l.a - a * l.c) /\
    \ d;\n    }\n    Point<T> projection(const Point<T> &p) const {\n        static_assert(is_floating_point_v<T>);\n\
    \        return crossppoint(perpendicular(p));\n    }\n    Point<T> reflection(const\
    \ Point<T> &p) const {\n        static_assert(is_floating_point_v<T>);\n     \
    \   Point q = projection(p);\n        return 2 * q - p;\n    }\n    Point<T> unit()\
    \ const {\n        static_assert(is_floating_point_v<T>);\n        if (eq<T>(b,\
    \ 0)) return Point<T>(0, 1);\n        Point<T> p(0, get_y(0)), q(1, get_y(1));\n\
    \        return (p - q) / (p - q).dist();\n    }\n    bool is_orthogonal(const\
    \ Line &l) const { return eq<W<T>>((W<T>)a * l.a + (W<T>)b * l.b, 0); }\n    bool\
    \ is_parallel(const Line &l) const { return eq<W<T>>((W<T>)a * l.b, (W<T>)b *\
    \ l.a); }\n    T dist(const Point<T> &p) const {\n        static_assert(is_floating_point_v<T>);\n\
    \        Point q = projection(p);\n        return (p - q).dist();\n    }\nprivate:\n\
    \    T a, b, c; // ax+by+c=0\n};\n\ntemplate<typename T>\ninline bool is_orthogonal(const\
    \ Line<T> &l1, const Line<T> &l2) { return l1.is_orthogonal(l2); }\ntemplate<typename\
    \ T>\ninline bool is_parallel(const Line<T> &l1, const Line<T> &l2) { return l1.is_parallel(l2);\
    \ }\ntemplate<typename T>\ninline Point<T> crosspoint(const Line<T> &l1, const\
    \ Line<T> &l2) { return l1.crossppoint(l2); }\ntemplate<typename T>\ninline T\
    \ dist(const Line<T> &l, const Point<T> &p) { return l.dist(p); }\ntemplate<typename\
    \ T>\ninline T dist(const Point<T> &p, const Line<T> &l) { return l.dist(p); }\n\
    \n\n} // namespace geometry\n#line 4 \"src/geometry/circle.hpp\"\nusing namespace\
    \ std;\n\nnamespace geometry {\n\ntemplate<typename T>\nstruct Circle {\n    Point<T>\
    \ p;\n    T r;\n    static constexpr Point<T> ip = Point<T>::inf_point();\n  \
    \  constexpr Circle() = default;\n    constexpr Circle(const Point<T> &_p, const\
    \ T &_r) : p(_p), r(_r) {}\n    int count_common_tangents(const Circle<T> &other)\
    \ const {\n        if (eq(p, other.p) && eq(r, other.r)) return -1;\n        W<T>\
    \ s = r + other.r, d = abs(r - other.r);\n        W<T> d2 = norm(p - other.p);\n\
    \        auto comp = [d2] (W<T> x) {\n            W<T> d = d2 - x * x;\n     \
    \       W<T> b = eps<T>() * (2 * x + eps<T>());\n            return d > b ? 1\
    \ : d < -b ? -1 : 0;\n        };\n        int out = comp(s), in = comp(d);\n \
    \       if (out > 0) return 4;\n        if (out == 0) return 3;\n        if (in\
    \ < 0) return 0;\n        if (in == 0) return 1;\n        return 2;\n    }\n \
    \   array<Point<T>, 2> crosspoint(const Line<T> &l) const {\n        static_assert(is_floating_point_v<T>);\n\
    \        T d = l.dist(p);\n        if (d > r + eps<T>()) return {ip, ip};\n  \
    \      Point<T> q = l.projection(p);\n        if (eq(d, r)) return {q, q};\n \
    \       Point<T> e = l.unit();\n        T t = sqrtl(r * r - d * d);\n        return\
    \ {q - t * e, q + t * e};\n    }\n    array<Point<T>, 2> crosspoint(const Circle<T>\
    \ &c) const {\n        static_assert(is_floating_point_v<T>);\n        int t =\
    \ count_common_tangents(c);\n        if (t == -1 || t == 0 || t == 4) return {ip,\
    \ ip};\n        T d = dist(p, c.p);\n        if (t == 1) {\n            if (c.r\
    \ < r - eps<T>()) {\n                Point<T> q = p + (c.p - p) * (r / d);\n \
    \               return {q, q};\n            } else {\n                Point<T>\
    \ q = c.p + (p - c.p) * (c.r / d);\n                return {q, q};\n         \
    \   }\n        } else if (t == 3) {\n            T s = r / (r + c.r);\n      \
    \      Point<T> q = p + (c.p - p) * s;\n            return {q, q};\n        }\
    \ else {\n            T la = 2 * (p.x - c.p.x);\n            T lb = 2 * (p.y -\
    \ c.p.y);\n            T lc = (p.x + c.p.x) * (c.p.x - p.x) + (p.y + c.p.y) *\
    \ (c.p.y - p.y) + (r + c.r) * (r - c.r);\n            return crosspoint(Line(la,\
    \ lb, lc));\n        }\n    }\n    array<Point<T>, 2> tangent_points(const Point<T>\
    \ &q) const {\n        static_assert(is_floating_point_v<T>);\n        T d = dist(p,\
    \ q);\n        if (d < r - eps<T>()) return {ip, ip};\n        if (eq(d, r)) return\
    \ {q, q};\n        return crosspoint(Circle<T>(q, sqrtl(d * d - r * r)));\n  \
    \  }\n    array<Line<T>, 4> common_tangents(const Circle &c) const {\n       \
    \ static_assert(is_floating_point_v<T>);\n        T d = dist(p, c.p);\n      \
    \  if (eq<T>(d, 0)) return {};\n        Point<T> u = (c.p - p) / d;\n        Point<T>\
    \ v(-u.y, u.x);\n        array<Line<T>, 4> res{};\n        int k = 0;\n      \
    \  auto add = [&] (const Point<T> &n) {\n            res[k++] = Line<T>(n.x, n.y,\
    \ -dot(n, p) - r);\n        };\n        for (int s : {-1, 1}) {\n            T\
    \ h = (r + s * c.r) / d;\n            if (eq<T>(h * h, 1)) {\n               \
    \ add(h > 0 ? u : -u);\n            } else if (1 - h * h > 0) {\n            \
    \    Point<T> u2 = u * h, v2 = v * sqrtl(1 - h * h);\n                add(u2 +\
    \ v2);\n                add(u2 - v2);\n            }\n        }\n        return\
    \ res;\n    }\n};\n\ntemplate<typename T>\ninline int count_common_tangents(const\
    \ Circle<T> &c1, const Circle<T> &c2) { return c1.count_common_tangents(c2); }\n\
    template<typename T>\ninline array<Point<T>, 2> crosspoint(const Circle<T> &c,\
    \ const Line<T> &l) { return c.crosspoint(l); }\ntemplate<typename T>\ninline\
    \ array<Point<T>, 2> crosspoint(const Line<T> &l, const Circle<T> &c) { return\
    \ c.crosspoint(l); }\ntemplate<typename T>\ninline array<Point<T>, 2> crosspoint(const\
    \ Circle<T> &c1, const Circle<T> &c2) { return c1.crosspoint(c2); }\ntemplate<typename\
    \ T>\ninline array<Point<T>, 2> tangent_points(const Circle<T> &c, const Point<T>\
    \ &p) { return c.tangent_points(p); }\ntemplate<typename T>\ninline array<Point<T>,\
    \ 2> tangent_points(const Point<T> &p, const Circle<T> &c) { return c.tangent_points(p);\
    \ }\ntemplate<typename T>\ninline array<Line<T>, 4> common_tangents(const Circle<T>\
    \ &c1, const Circle<T> &c2) { return c1.common_tangents(c2); }\n\n} // namespace\
    \ geometry\n"
  code: "#pragma once\n#include <array>\n#include \"line.hpp\"\nusing namespace std;\n\
    \nnamespace geometry {\n\ntemplate<typename T>\nstruct Circle {\n    Point<T>\
    \ p;\n    T r;\n    static constexpr Point<T> ip = Point<T>::inf_point();\n  \
    \  constexpr Circle() = default;\n    constexpr Circle(const Point<T> &_p, const\
    \ T &_r) : p(_p), r(_r) {}\n    int count_common_tangents(const Circle<T> &other)\
    \ const {\n        if (eq(p, other.p) && eq(r, other.r)) return -1;\n        W<T>\
    \ s = r + other.r, d = abs(r - other.r);\n        W<T> d2 = norm(p - other.p);\n\
    \        auto comp = [d2] (W<T> x) {\n            W<T> d = d2 - x * x;\n     \
    \       W<T> b = eps<T>() * (2 * x + eps<T>());\n            return d > b ? 1\
    \ : d < -b ? -1 : 0;\n        };\n        int out = comp(s), in = comp(d);\n \
    \       if (out > 0) return 4;\n        if (out == 0) return 3;\n        if (in\
    \ < 0) return 0;\n        if (in == 0) return 1;\n        return 2;\n    }\n \
    \   array<Point<T>, 2> crosspoint(const Line<T> &l) const {\n        static_assert(is_floating_point_v<T>);\n\
    \        T d = l.dist(p);\n        if (d > r + eps<T>()) return {ip, ip};\n  \
    \      Point<T> q = l.projection(p);\n        if (eq(d, r)) return {q, q};\n \
    \       Point<T> e = l.unit();\n        T t = sqrtl(r * r - d * d);\n        return\
    \ {q - t * e, q + t * e};\n    }\n    array<Point<T>, 2> crosspoint(const Circle<T>\
    \ &c) const {\n        static_assert(is_floating_point_v<T>);\n        int t =\
    \ count_common_tangents(c);\n        if (t == -1 || t == 0 || t == 4) return {ip,\
    \ ip};\n        T d = dist(p, c.p);\n        if (t == 1) {\n            if (c.r\
    \ < r - eps<T>()) {\n                Point<T> q = p + (c.p - p) * (r / d);\n \
    \               return {q, q};\n            } else {\n                Point<T>\
    \ q = c.p + (p - c.p) * (c.r / d);\n                return {q, q};\n         \
    \   }\n        } else if (t == 3) {\n            T s = r / (r + c.r);\n      \
    \      Point<T> q = p + (c.p - p) * s;\n            return {q, q};\n        }\
    \ else {\n            T la = 2 * (p.x - c.p.x);\n            T lb = 2 * (p.y -\
    \ c.p.y);\n            T lc = (p.x + c.p.x) * (c.p.x - p.x) + (p.y + c.p.y) *\
    \ (c.p.y - p.y) + (r + c.r) * (r - c.r);\n            return crosspoint(Line(la,\
    \ lb, lc));\n        }\n    }\n    array<Point<T>, 2> tangent_points(const Point<T>\
    \ &q) const {\n        static_assert(is_floating_point_v<T>);\n        T d = dist(p,\
    \ q);\n        if (d < r - eps<T>()) return {ip, ip};\n        if (eq(d, r)) return\
    \ {q, q};\n        return crosspoint(Circle<T>(q, sqrtl(d * d - r * r)));\n  \
    \  }\n    array<Line<T>, 4> common_tangents(const Circle &c) const {\n       \
    \ static_assert(is_floating_point_v<T>);\n        T d = dist(p, c.p);\n      \
    \  if (eq<T>(d, 0)) return {};\n        Point<T> u = (c.p - p) / d;\n        Point<T>\
    \ v(-u.y, u.x);\n        array<Line<T>, 4> res{};\n        int k = 0;\n      \
    \  auto add = [&] (const Point<T> &n) {\n            res[k++] = Line<T>(n.x, n.y,\
    \ -dot(n, p) - r);\n        };\n        for (int s : {-1, 1}) {\n            T\
    \ h = (r + s * c.r) / d;\n            if (eq<T>(h * h, 1)) {\n               \
    \ add(h > 0 ? u : -u);\n            } else if (1 - h * h > 0) {\n            \
    \    Point<T> u2 = u * h, v2 = v * sqrtl(1 - h * h);\n                add(u2 +\
    \ v2);\n                add(u2 - v2);\n            }\n        }\n        return\
    \ res;\n    }\n};\n\ntemplate<typename T>\ninline int count_common_tangents(const\
    \ Circle<T> &c1, const Circle<T> &c2) { return c1.count_common_tangents(c2); }\n\
    template<typename T>\ninline array<Point<T>, 2> crosspoint(const Circle<T> &c,\
    \ const Line<T> &l) { return c.crosspoint(l); }\ntemplate<typename T>\ninline\
    \ array<Point<T>, 2> crosspoint(const Line<T> &l, const Circle<T> &c) { return\
    \ c.crosspoint(l); }\ntemplate<typename T>\ninline array<Point<T>, 2> crosspoint(const\
    \ Circle<T> &c1, const Circle<T> &c2) { return c1.crosspoint(c2); }\ntemplate<typename\
    \ T>\ninline array<Point<T>, 2> tangent_points(const Circle<T> &c, const Point<T>\
    \ &p) { return c.tangent_points(p); }\ntemplate<typename T>\ninline array<Point<T>,\
    \ 2> tangent_points(const Point<T> &p, const Circle<T> &c) { return c.tangent_points(p);\
    \ }\ntemplate<typename T>\ninline array<Line<T>, 4> common_tangents(const Circle<T>\
    \ &c1, const Circle<T> &c2) { return c1.common_tangents(c2); }\n\n} // namespace\
    \ geometry\n"
  dependsOn:
  - src/geometry/line.hpp
  - src/geometry/common.hpp
  isVerificationFile: false
  path: src/geometry/circle.hpp
  requiredBy:
  - src/geometry/incircle_of_triangle.hpp
  - src/geometry/circumcircle_of_triangle.hpp
  timestamp: '2026-10-26 18:50:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/circle_crosspoint_with_circle.test.cpp
  - test/geometry/circle_crosspoint_with_line.test.cpp
  - test/geometry/circumcircle_of_triangle.test.cpp
  - test/geometry/incircle_of_triangle.test.cpp
  - test/geometry/circle_common_tangents.test.cpp
  - test/geometry/circle_count_common_tangents.test.cpp
  - test/geometry/circle_tangent_points.test.cpp
documentation_of: src/geometry/circle.hpp
layout: document
title: Circle
---

円を扱う.
中心は `p`, 半径は `r`.
交点や接点が存在しない場合は `Point<T>::inf_point()` を返す.

## Constructor

```
Circle<T> c(Point<T> p, T r)
```

- 中心が $p$, 半径が $r$ の円を作る

## count_common_tangents

```
int count_common_tangents(Circle<T> c1, Circle<T> c2)
```

- `c1` と `c2` の共通接線の本数を返す
- 二円が一致する場合は $-1$ を返す

## crosspoint

```
array<Point<T>, 2> crosspoint(Circle<T> c, Line<T> l)
array<Point<T>, 2> crosspoint(Line<T> l, Circle<T> c)
array<Point<T>, 2> crosspoint(Circle<T> c1, Circle<T> c2)
```

- 交点を返す
- 接する場合は同じ点を 2 つ返す
- `T` は浮動小数点型

## tangent_points

```
array<Point<T>, 2> tangent_points(Circle<T> c, Point<T> q)
array<Point<T>, 2> tangent_points(Point<T> q, Circle<T> c)
```

- 点 $q$ から引いた接線と円の接点を返す
- 接線が 1 本の場合は同じ点を 2 つ返す
- `T` は浮動小数点型

## common_tangents

```
array<Line<T>, 4> common_tangents(Circle<T> c1, Circle<T> c2)
```

- `c1` と `c2` の共通接線を返す
- $K$ を `count_common_tangents(c1, c2)` として, $[0,K)$ 番目に答えが入る
- $K$ 以降の要素は未定義
- 二円が一致する場合の動作は未定義
- `T` は浮動小数点型
