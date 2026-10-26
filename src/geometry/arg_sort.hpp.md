---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/common.hpp
    title: Common
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/arg_sort.test.cpp
    title: test/geometry/arg_sort.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/arg_sort.hpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <vector>\n#line 2 \"src/geometry/common.hpp\"\n#include\
    \ <cmath>\n#line 4 \"src/geometry/common.hpp\"\n#include <type_traits>\n#include\
    \ <utility>\nusing namespace std;\n\nnamespace geometry {\n\ntemplate<typename\
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
    \ < qn) return -2;\n    return 0;\n}\n\n}  // namespace geometry\n#line 6 \"src/geometry/arg_sort.hpp\"\
    \nusing namespace std;\n\nnamespace geometry {\n\ntemplate<typename T>\nvector<int>\
    \ arg_sort(const vector<Point<T>> &ps) {\n    vector<int> ord(ps.size());\n  \
    \  iota(ord.begin(), ord.end(), 0);\n    auto half = [&] (const Point<T> &p) {\n\
    \        return p.y > 0 || (p.y == 0 && p.x >= 0) ? 0 : 1;\n    };\n    sort(ord.begin(),\
    \ ord.end(), [&](int i, int j) {\n        int a = half(ps[i]), b = half(ps[j]);\n\
    \        if (a != b) return a < b;\n        W<T> cr = cross(ps[i], ps[j]);\n \
    \       if (cr != 0) return cr > 0;\n        W<T> ni = norm(ps[i]), nj = norm(ps[j]);\n\
    \        if (ni != nj) return ni < nj;\n        return i < j;\n    });\n    return\
    \ ord;\n}\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    #include \"common.hpp\"\nusing namespace std;\n\nnamespace geometry {\n\ntemplate<typename\
    \ T>\nvector<int> arg_sort(const vector<Point<T>> &ps) {\n    vector<int> ord(ps.size());\n\
    \    iota(ord.begin(), ord.end(), 0);\n    auto half = [&] (const Point<T> &p)\
    \ {\n        return p.y > 0 || (p.y == 0 && p.x >= 0) ? 0 : 1;\n    };\n    sort(ord.begin(),\
    \ ord.end(), [&](int i, int j) {\n        int a = half(ps[i]), b = half(ps[j]);\n\
    \        if (a != b) return a < b;\n        W<T> cr = cross(ps[i], ps[j]);\n \
    \       if (cr != 0) return cr > 0;\n        W<T> ni = norm(ps[i]), nj = norm(ps[j]);\n\
    \        if (ni != nj) return ni < nj;\n        return i < j;\n    });\n    return\
    \ ord;\n}\n\n}  // namespace geometry\n"
  dependsOn:
  - src/geometry/common.hpp
  isVerificationFile: false
  path: src/geometry/arg_sort.hpp
  requiredBy: []
  timestamp: '2026-10-26 18:50:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/arg_sort.test.cpp
documentation_of: src/geometry/arg_sort.hpp
layout: document
title: Arg Sort
---

偏角ソートをする.
偏角は $[0,2\pi)$ で考え, 次の順番で並べる.

- 零ベクトル
- 続いて偏角が小さい順
- 原点からの距離が小さい順
- 元の添字が小さい順

返り値を `ord` とすると, `ps[ord[i]]` が $i$ 番目の点である.

計算量は $O(n\log n)$
