---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/common.hpp
    title: Common
  - icon: ':heavy_check_mark:'
    path: src/geometry/polygon.hpp
    title: Polygon
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/geometry/convex_hull_aoj.test.cpp
    title: test/geometry/convex_hull_aoj.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/geometry/convex_hull_yosupo.test.cpp
    title: test/geometry/convex_hull_yosupo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/convex_hull.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#line 2 \"src/geometry/common.hpp\"\n#include <cmath>\n#include <numeric>\n\
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
    \ < qn) return -2;\n    return 0;\n}\n\n}  // namespace geometry\n#line 5 \"src/geometry/polygon.hpp\"\
    \n\nnamespace geometry {\n\ntemplate<typename T>\nstruct Polygon : vector<Point<T>>\
    \ {\n    using vector<Point<T>>::vector;\n    Polygon(const vector<Point<T>> &pts)\
    \ : vector<Point<T>>(pts) {}\n    int contain(const Point<T> &p) const {\n   \
    \     int n = this->size();\n        bool in = false;\n        for (int i = 0;\
    \ i < n; i++) {\n            Point a = (*this)[i] - p;\n            Point b =\
    \ (*this)[i == n - 1 ? 0 : i + 1] - p;\n            if (a.y > b.y) swap(a, b);\n\
    \            if (sgn(a.y) <= 0 && 0 < sgn(b.y) && sgn(cross(a, b)) < 0) in = !in;\n\
    \            if (eq<W<T>>(cross(a, b), 0) && sgn(dot(a, b)) <= 0) return 1;\n\
    \        }\n        return in ? 2 : 0;\n    }\n    // return 2S\n    W<T> area()\
    \ const {\n        int n = this->size();\n        W<T> S = 0;\n        for (int\
    \ i = 0; i < n; i++) {\n            Point a = (*this)[i];\n            Point b\
    \ = (*this)[i == n - 1 ? 0 : i + 1];\n            S += cross(a, b);\n        }\n\
    \        return S;\n    }\n    void relabeling() {\n        if (this->empty())\
    \ return;\n        T x_min = inf<T>(), y_min = inf<T>();\n        int idx = 0,\
    \ n = this->size();\n        for (int i = 0; i < n; i++) {\n            T x =\
    \ (*this)[i].x, y = (*this)[i].y;\n            if (y < y_min || (eq(y, y_min)\
    \ && x < x_min)) {\n                x_min = x;\n                y_min = y;\n \
    \               idx = i;\n            }\n        }\n        Polygon tmp(n);\n\
    \        int pre = (idx + n - 1) % n, nxt = (idx + 1) % n;\n        if (ccw((*this)[idx],\
    \ (*this)[pre], (*this)[nxt]) == -1) {\n            for (int i = 0; i < n; i++)\
    \ {\n                tmp[i] = (*this)[(idx + i) % n];\n            }\n       \
    \ } else {\n            for (int i = 0; i < n; i++) {\n                tmp[i]\
    \ = (*this)[(idx + n - i) % n];\n            }\n        }\n        *this = tmp;\n\
    \    }\n    bool is_convex() const {\n        int n = this->size();\n        if\
    \ (n <= 2) return false;\n        for (int i = 0, j = 1, k = 2; i < n; i++, j++,\
    \ k++) {\n            if (j == n) j = 0;\n            if (k == n) k = 0;\n   \
    \         if (ccw((*this)[i], (*this)[j], (*this)[k]) == -1) return false;\n \
    \       }\n        return true;\n    }\n    pair<int, int> diam() const {\n  \
    \      int n = this->size();\n        if (n == 0) return {-1, -1};\n        if\
    \ (n == 1) return {0, 0};\n        if (n == 2) return {0, 1};\n        W<T> s\
    \ = area();\n        bool collinear = eq<W<T>>(s, 0);\n        if (collinear)\
    \ {\n            int l = 0, r = 0;\n            for (int i = 1; i < n; i++) {\n\
    \                if ((*this)[i].x < (*this)[l].x || ((*this)[i].x == (*this)[l].x\
    \ && (*this)[i].y < (*this)[l].y)) l = i;\n                if ((*this)[i].x >\
    \ (*this)[r].x || ((*this)[i].x == (*this)[r].x && (*this)[i].y > (*this)[r].y))\
    \ r = i;\n            }\n            return {l, r};\n        }\n        bool rev\
    \ = s < 0;\n        auto nxt = [&] (int i) { return rev ? (i == 0 ? n - 1 : i\
    \ - 1) : (i + 1 == n ? 0 : i + 1); };\n        auto comp = [] (W<T> a, W<T> b)\
    \ {\n            if constexpr (is_integral_v<T>) return (a > b) - (a < b);\n \
    \           else return sgn(a - b);\n        };\n        int j = 0;\n        Point<T>\
    \ e = (*this)[nxt(0)] - (*this)[0];\n        W<T> h = 0;\n        for (int i =\
    \ 1; i < n; i++) {\n            W<T> t = cross(e, (*this)[i] - (*this)[0]);\n\
    \            if (comp(t, h) > 0) j = i, h = t;\n        }\n        pair<int, int>\
    \ res = {0, 1};\n        W<T> best = norm((*this)[0] - (*this)[1]);\n        auto\
    \ update = [&] (int i, int j) {\n            W<T> d = norm((*this)[i] - (*this)[j]);\n\
    \            if (d > best) best = d, res = {i, j};\n        };\n        for (int\
    \ i = 0, cnt = 0; cnt < n; i = nxt(i), cnt++) {\n            int ni = nxt(i);\n\
    \            Point<T> e = (*this)[ni] - (*this)[i];\n            W<T> cur = cross(e,\
    \ (*this)[j] - (*this)[i]);\n            int nj = nxt(j);\n            while (comp(cross(e,\
    \ (*this)[nj] - (*this)[i]), cur) > 0) {\n                j = nj;\n          \
    \      cur = cross(e, (*this)[j] - (*this)[i]);\n                nj = nxt(j);\n\
    \            }\n            update(i, j);\n            update(ni, j);\n      \
    \      if (comp(cross(e, (*this)[nj] - (*this)[i]), cur) == 0) {\n           \
    \     update(i, nj);\n                update(ni, nj);\n            }\n       \
    \ }\n        return res;\n    }\n};\n\ntemplate<typename T>\ninline int contain(const\
    \ Polygon<T> &v, const Point<T> &p) { return v.contain(p); }\ntemplate<typename\
    \ T>\ninline int contain(const Point<T> &p, const Polygon<T> &v) { return v.contain(p);\
    \ }\ntemplate<typename T>\ninline W<T> area(const Polygon<T> &v) { return v.area();\
    \ }\ntemplate<typename T>\ninline bool is_convex(const Polygon<T> &v) { return\
    \ v.is_convex(); }\ntemplate<typename T>\ninline pair<int, int> diam(const Polygon<T>\
    \ &v) { return v.diam(); }\n\n} // namespace geometry\n#line 6 \"src/geometry/convex_hull.hpp\"\
    \nusing namespace std;\n\nnamespace geometry {\n\ntemplate<typename T>\nPolygon<T>\
    \ convex_hull(vector<Point<T>> pts, bool exclude_collinear = true) {\n    sort(pts.begin(),\
    \ pts.end());\n    pts.erase(unique(pts.begin(), pts.end(), [] (const Point<T>\
    \ &p, const Point<T> &q) {\n        return p.x == q.x && p.y == q.y;\n    }),\
    \ pts.end());\n    int n = pts.size();\n    if (n <= 1) return Polygon<T>(pts);\n\
    \    auto turn = [] (const Point<T> &a, const Point<T> &b, const Point<T> &c)\
    \ {\n        W<T> d = cross(b - a, c - a);\n        if constexpr (is_integral_v<T>)\
    \ return (d > 0) - (d < 0);\n        else return sgn(d);\n    };\n    bool collinear\
    \ = true;\n    for (int i = 1; i < n - 1; i++) {\n        if (turn(pts[0], pts[n\
    \ - 1], pts[i]) != 0) {\n            collinear = false;\n            break;\n\
    \        }\n    }\n    if (collinear) {\n        if (!exclude_collinear) return\
    \ Polygon<T>(pts);\n        return Polygon<T>(vector<Point<T>>{pts.front(), pts.back()});\n\
    \    }\n    auto remove = [&] (const Point<T> &a, const Point<T> &b, const Point<T>\
    \ &c) {\n        int d = turn(a, b, c);\n        return exclude_collinear ? d\
    \ <= 0 : d < 0;\n    };\n    vector<Point<T>> ch;\n    ch.reserve(2 * n);\n  \
    \  for (const Point<T> &p : pts) {\n        while (ch.size() >= 2 && remove(ch[ch.size()\
    \ - 2], ch.back(), p)) ch.pop_back();\n        ch.push_back(p);\n    }\n    int\
    \ l = ch.size();\n    for (int i = n - 2; i >= 0; i--) {\n        while ((int)ch.size()\
    \ > l && remove(ch[ch.size() - 2], ch.back(), pts[i])) ch.pop_back();\n      \
    \  ch.push_back(pts[i]);\n    }\n    ch.pop_back();\n    return Polygon<T>(ch);\n\
    }\n\n} // namespace geometry\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"common.hpp\"\
    \n#include \"polygon.hpp\"\nusing namespace std;\n\nnamespace geometry {\n\ntemplate<typename\
    \ T>\nPolygon<T> convex_hull(vector<Point<T>> pts, bool exclude_collinear = true)\
    \ {\n    sort(pts.begin(), pts.end());\n    pts.erase(unique(pts.begin(), pts.end(),\
    \ [] (const Point<T> &p, const Point<T> &q) {\n        return p.x == q.x && p.y\
    \ == q.y;\n    }), pts.end());\n    int n = pts.size();\n    if (n <= 1) return\
    \ Polygon<T>(pts);\n    auto turn = [] (const Point<T> &a, const Point<T> &b,\
    \ const Point<T> &c) {\n        W<T> d = cross(b - a, c - a);\n        if constexpr\
    \ (is_integral_v<T>) return (d > 0) - (d < 0);\n        else return sgn(d);\n\
    \    };\n    bool collinear = true;\n    for (int i = 1; i < n - 1; i++) {\n \
    \       if (turn(pts[0], pts[n - 1], pts[i]) != 0) {\n            collinear =\
    \ false;\n            break;\n        }\n    }\n    if (collinear) {\n       \
    \ if (!exclude_collinear) return Polygon<T>(pts);\n        return Polygon<T>(vector<Point<T>>{pts.front(),\
    \ pts.back()});\n    }\n    auto remove = [&] (const Point<T> &a, const Point<T>\
    \ &b, const Point<T> &c) {\n        int d = turn(a, b, c);\n        return exclude_collinear\
    \ ? d <= 0 : d < 0;\n    };\n    vector<Point<T>> ch;\n    ch.reserve(2 * n);\n\
    \    for (const Point<T> &p : pts) {\n        while (ch.size() >= 2 && remove(ch[ch.size()\
    \ - 2], ch.back(), p)) ch.pop_back();\n        ch.push_back(p);\n    }\n    int\
    \ l = ch.size();\n    for (int i = n - 2; i >= 0; i--) {\n        while ((int)ch.size()\
    \ > l && remove(ch[ch.size() - 2], ch.back(), pts[i])) ch.pop_back();\n      \
    \  ch.push_back(pts[i]);\n    }\n    ch.pop_back();\n    return Polygon<T>(ch);\n\
    }\n\n} // namespace geometry"
  dependsOn:
  - src/geometry/common.hpp
  - src/geometry/polygon.hpp
  isVerificationFile: false
  path: src/geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2026-10-26 18:50:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/geometry/convex_hull_yosupo.test.cpp
  - test/geometry/convex_hull_aoj.test.cpp
documentation_of: src/geometry/convex_hull.hpp
layout: document
title: Convex Hull
---

点列の凸包を返す.
入力の点数を $n$ とする.

```
Polygon<T> convex_hull(vector<Point<T>> ps, bool exclude_collinear = true)
```

- 同じ座標の点は 1 つにまとめる
- `exclude_collinear` は
  - 真なら, 凸包の辺上にある中間の点を除く
  - 偽なら, 凸包の辺上にある点も含める
- 全点が一直線上にある場合, `exclude_collinear` に応じて次が返る
  - 真なら両端の 2 点
  - 偽なら異なる点すべて
- 返り値は $(x, y)$ の辞書順で最小の点から始まり, 一直線上の場合を除いて反時計回りに並ぶ
- 点が 0 個または 1 個なら, そのまま返す
- $O(n\log n)$
