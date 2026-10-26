---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/common.hpp
    title: Common
  - icon: ':heavy_check_mark:'
    path: src/geometry/line.hpp
    title: Line
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B
  bundledCode: "#line 1 \"test/geometry/line_reflection.test.cpp\"\n#define ERROR\
    \ 0.00000001\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n\n#line 2 \"src/geometry/common.hpp\"\n#include <cmath>\n#include <numeric>\n\
    #include <type_traits>\n#include <utility>\nusing namespace std;\n\nnamespace\
    \ geometry {\n\ntemplate<typename T>\nusing W = conditional_t<is_integral_v<T>,\
    \ conditional_t<sizeof(T) <= 4, long long, __int128_t>, T>;\n\ntemplate<typename\
    \ T>\nconstexpr T eps() { return is_integral_v<T> ? T(0) : T(1e-12L); }\n\ntemplate<typename\
    \ T>\nconstexpr T inf() { return numeric_limits<T>::max(); }\n\ntemplate<typename\
    \ T>\nconstexpr T PI() {\n    static_assert(is_floating_point_v<T>);\n    return\
    \ (T)acosl(-1);\n}\n\ntemplate<typename T>\ninline bool eq(T a, T b) {\n    if\
    \ constexpr (is_integral_v<T>) {\n        return a == b;\n    } else {\n     \
    \   return abs(a - b) < eps<T>();\n    }\n}\n\ntemplate<typename T>\ninline int\
    \ sgn(T a) { return eq<T>(a, 0) ? 0 : a > 0 ? 1 : -1; }\n\ntemplate<typename T>\n\
    struct Point {\n    T x, y;\n    constexpr Point(T _x = 0, T _y = 0) : x(_x),\
    \ y(_y) {}\n    constexpr Point(const pair<T, T> &pt) : x(pt.first), y(pt.second)\
    \ {}\n    static constexpr Point inf_point() { return Point(inf<T>(), inf<T>());\
    \ }\n    Point &operator+=(const Point &p) {\n        x += p.x;\n        y +=\
    \ p.y;\n        return *this;\n    }\n    Point &operator-=(const Point &p) {\n\
    \        x -= p.x;\n        y -= p.y;\n        return *this;\n    }\n    Point\
    \ &operator*=(const T &r) {\n        x *= r;\n        y *= r;\n        return\
    \ *this;\n    }\n    Point &operator/=(const T &r) {\n        x /= r;\n      \
    \  y /= r;\n        return *this;\n    }\n    Point operator+(const Point &p)\
    \ const { return Point(*this) += p; }\n    Point operator-(const Point &p) const\
    \ { return Point(*this) -= p; }\n    Point operator*(const T &r) const { return\
    \ Point(*this) *= r; }\n    Point operator/(const T &r) const { return Point(*this)\
    \ /= r; }\n    Point operator+() const { return *this; }\n    Point operator-()\
    \ const { return Point() - *this; }\n    bool operator==(const Point &p) const\
    \ { return eq(x, p.x) && eq(y, p.y); }\n    bool operator!=(const Point &p) const\
    \ { return !this->operator==(p); }\n    bool operator<(const Point &p) const {\
    \ return x == p.x ? y < p.y : x < p.x; }\n    bool operator>(const Point &p) const\
    \ { return x == p.x ? y > p.y : x > p.x; }\n    bool operator<=(const Point &p)\
    \ const { return this->operator==(p) || this->operator<(p); }\n    bool operator>=(const\
    \ Point &p) const { return this->operator==(p) || this->operator>(p); }\n    friend\
    \ Point operator*(T r, const Point &p) { return p * r; }\n    W<T> norm() const\
    \ { return (W<T>)x * x + (W<T>)y * y; }\n    T dist() const {\n        static_assert(is_floating_point_v<T>);\n\
    \        return sqrtl(norm());\n    }\n    T arg() const {\n        static_assert(is_floating_point_v<T>);\n\
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
    \n\n} // namespace geometry\n#line 6 \"test/geometry/line_reflection.test.cpp\"\
    \n\n#include <iomanip>\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    geometry::Point<double> P1, P2;\n    cin >> P1.x >>\
    \ P1.y >> P2.x >> P2.y;\n    geometry::Line<double> L(P1, P2);\n    int Q;\n \
    \   cin >> Q;\n    for (geometry::Point<double> P; Q--; ) {\n        cin >> P.x\
    \ >> P.y;\n        auto X = L.reflection(P);\n        cout << fixed << setprecision(10)\
    \ << X.x << ' ' << X.y << '\\n';\n    }\n}\n"
  code: "#define ERROR 0.00000001\n\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B\"\
    \n\n#include \"../../src/geometry/line.hpp\"\n\n#include <iomanip>\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    geometry::Point<double>\
    \ P1, P2;\n    cin >> P1.x >> P1.y >> P2.x >> P2.y;\n    geometry::Line<double>\
    \ L(P1, P2);\n    int Q;\n    cin >> Q;\n    for (geometry::Point<double> P; Q--;\
    \ ) {\n        cin >> P.x >> P.y;\n        auto X = L.reflection(P);\n       \
    \ cout << fixed << setprecision(10) << X.x << ' ' << X.y << '\\n';\n    }\n}"
  dependsOn:
  - src/geometry/line.hpp
  - src/geometry/common.hpp
  isVerificationFile: true
  path: test/geometry/line_reflection.test.cpp
  requiredBy: []
  timestamp: '2026-10-26 18:50:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/geometry/line_reflection.test.cpp
layout: document
redirect_from:
- /verify/test/geometry/line_reflection.test.cpp
- /verify/test/geometry/line_reflection.test.cpp.html
title: test/geometry/line_reflection.test.cpp
---
