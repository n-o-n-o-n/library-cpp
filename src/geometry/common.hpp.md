---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/arg_sort.hpp
    title: Arg Sort
  - icon: ':heavy_check_mark:'
    path: src/geometry/circle.hpp
    title: Circle
  - icon: ':heavy_check_mark:'
    path: src/geometry/circumcircle_of_triangle.hpp
    title: src/geometry/circumcircle_of_triangle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_hull.hpp
    title: Convex Hull
  - icon: ':heavy_check_mark:'
    path: src/geometry/incircle_of_triangle.hpp
    title: src/geometry/incircle_of_triangle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/line.hpp
    title: Line
  - icon: ':heavy_check_mark:'
    path: src/geometry/polygon.hpp
    title: Polygon
  - icon: ':heavy_check_mark:'
    path: src/geometry/segment.hpp
    title: Segment
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/arg_sort.test.cpp
    title: test/geometry/arg_sort.test.cpp
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
    path: test/geometry/common_ccw.test.cpp
    title: test/geometry/common_ccw.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/convex_hull_aoj.test.cpp
    title: test/geometry/convex_hull_aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/convex_hull_yosupo.test.cpp
    title: test/geometry/convex_hull_yosupo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/incircle_of_triangle.test.cpp
    title: test/geometry/incircle_of_triangle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/line_parallel_orthogonal.test.cpp
    title: test/geometry/line_parallel_orthogonal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/line_projection.test.cpp
    title: test/geometry/line_projection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/line_reflection.test.cpp
    title: test/geometry/line_reflection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/polygon_area.test.cpp
    title: test/geometry/polygon_area.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/polygon_contain.test.cpp
    title: test/geometry/polygon_contain.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/polygon_diam.test.cpp
    title: test/geometry/polygon_diam.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/polygon_is_convex.test.cpp
    title: test/geometry/polygon_is_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/segment_crosspoint.test.cpp
    title: test/geometry/segment_crosspoint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/segment_dist.test.cpp
    title: test/geometry/segment_dist.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/segment_intersect.test.cpp
    title: test/geometry/segment_intersect.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/common.hpp\"\n#include <cmath>\n#include <numeric>\n\
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
    \ < qn) return -2;\n    return 0;\n}\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include <cmath>\n#include <numeric>\n#include <type_traits>\n\
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
    \ < qn) return -2;\n    return 0;\n}\n\n}  // namespace geometry"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/common.hpp
  requiredBy:
  - src/geometry/polygon.hpp
  - src/geometry/incircle_of_triangle.hpp
  - src/geometry/convex_hull.hpp
  - src/geometry/circumcircle_of_triangle.hpp
  - src/geometry/arg_sort.hpp
  - src/geometry/line.hpp
  - src/geometry/segment.hpp
  - src/geometry/circle.hpp
  timestamp: '2026-10-26 18:50:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/line_projection.test.cpp
  - test/geometry/polygon_area.test.cpp
  - test/geometry/circle_crosspoint_with_circle.test.cpp
  - test/geometry/line_reflection.test.cpp
  - test/geometry/circle_crosspoint_with_line.test.cpp
  - test/geometry/segment_crosspoint.test.cpp
  - test/geometry/polygon_contain.test.cpp
  - test/geometry/circumcircle_of_triangle.test.cpp
  - test/geometry/incircle_of_triangle.test.cpp
  - test/geometry/arg_sort.test.cpp
  - test/geometry/segment_intersect.test.cpp
  - test/geometry/segment_dist.test.cpp
  - test/geometry/circle_common_tangents.test.cpp
  - test/geometry/polygon_diam.test.cpp
  - test/geometry/line_parallel_orthogonal.test.cpp
  - test/geometry/circle_count_common_tangents.test.cpp
  - test/geometry/polygon_is_convex.test.cpp
  - test/geometry/circle_tangent_points.test.cpp
  - test/geometry/convex_hull_yosupo.test.cpp
  - test/geometry/convex_hull_aoj.test.cpp
  - test/geometry/common_ccw.test.cpp
documentation_of: src/geometry/common.hpp
layout: document
title: Common
---

二次元幾何の点と基本演算を扱う.
`W<T>` は `T` が `int` なら `long long`, `long long` なら `__int128_t`, 浮動小数点型ならその型.

## Point

```
Point<T> p(T x = 0, T y = 0)
Point<T> p(pair<T, T> xy)
Point<T> Point<T>::inf_point()
```

- 座標 $(x,y)$ の点を作る
- `inf_point()` は両座標が `numeric_limits<T>::max()` の点を返す
- 点同士の加減算, スカラー倍と除算に対応する
- `==` は `eq` による比較, `<` は座標の厳密な辞書順比較

## eps, inf, PI

```
T eps<T>()
T inf<T>()
T PI<T>()
```

- `eps<T>()` は整数型なら $0$, 浮動小数点型なら $10^{-12}$ を返す
- `inf<T>()` は `numeric_limits<T>::max()` を返す
- `PI<T>()` は `T` が浮動小数点型のときに円周率を返す

## eq, sgn

```
bool eq(T a, T b)
bool eq(Point<T> p, Point<T> q)
int sgn(T a)
```

- `eq` は整数型では一致, 浮動小数点型では差が `eps<T>()` 未満かを判定する
- 点同士は各座標を比較する
- `sgn` は負なら $-1$, 零なら $0$, 正なら $1$ を返す

## dot, cross

```
W<T> dot(Point<T> p, Point<T> q)
W<T> cross(Point<T> p, Point<T> q)
```

- `dot` は内積 $p_xq_x+p_yq_y$ を返す
- `cross` は外積 $p_xq_y-p_yq_x$ を返す

## norm, dist

```
W<T> norm(Point<T> p)
T dist(Point<T> p)
T dist(Point<T> p, Point<T> q)
```

- `norm(p)` は $p_x^2+p_y^2$ を返す
- `dist(p)` は原点からの距離, `dist(p, q)` は 2 点間の距離を返す
- `dist` の `T` は浮動小数点型

## arg, angle

```
T arg(Point<T> p)
T angle(Point<T> o, Point<T> p, Point<T> q)
```

- `arg(p)` は $p$ の偏角を返す
- `angle(o, p, q)` は $\overrightarrow{op}$ から $\overrightarrow{oq}$ への符号付き角を返す
- `T` は浮動小数点型

## unit, rotate

```
Point<T> p.unit()
Point<T> p.rotate(T rad)
```

- `unit()` は $p$ と同方向の単位ベクトルを返し, $p$ は零ベクトルでないものとする
- `rotate(rad)` は $p$ を原点の周りに `rad` ラジアン回転する
- `T` は浮動小数点型

## ccw

```
int ccw(Point<T> a, Point<T> b, Point<T> c)
```

- 有向直線 $a\to b$ に対する $c$ の位置を返す
- $1$: 反時計回り
- $-1$: 時計回り
- $2$: 直線上で $a$ の後方
- $-2$: 直線上で $b$ の前方
- $0$: 線分 $ab$ 上
