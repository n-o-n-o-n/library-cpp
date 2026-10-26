#pragma once
#include <algorithm>
#include <vector>
#include "common.hpp"

namespace geometry {

template<typename T>
struct Polygon : vector<Point<T>> {
    using vector<Point<T>>::vector;
    Polygon(const vector<Point<T>> &pts) : vector<Point<T>>(pts) {}
    int contain(const Point<T> &p) const {
        int n = this->size();
        bool in = false;
        for (int i = 0; i < n; i++) {
            Point a = (*this)[i] - p;
            Point b = (*this)[i == n - 1 ? 0 : i + 1] - p;
            if (a.y > b.y) swap(a, b);
            if (sgn(a.y) <= 0 && 0 < sgn(b.y) && sgn(cross(a, b)) < 0) in = !in;
            if (eq<W<T>>(cross(a, b), 0) && sgn(dot(a, b)) <= 0) return 1;
        }
        return in ? 2 : 0;
    }
    // return 2S
    W<T> area() const {
        int n = this->size();
        W<T> S = 0;
        for (int i = 0; i < n; i++) {
            Point a = (*this)[i];
            Point b = (*this)[i == n - 1 ? 0 : i + 1];
            S += cross(a, b);
        }
        return S;
    }
    void relabeling() {
        if (this->empty()) return;
        T x_min = inf<T>(), y_min = inf<T>();
        int idx = 0, n = this->size();
        for (int i = 0; i < n; i++) {
            T x = (*this)[i].x, y = (*this)[i].y;
            if (y < y_min || (eq(y, y_min) && x < x_min)) {
                x_min = x;
                y_min = y;
                idx = i;
            }
        }
        Polygon tmp(n);
        int pre = (idx + n - 1) % n, nxt = (idx + 1) % n;
        if (ccw((*this)[idx], (*this)[pre], (*this)[nxt]) == -1) {
            for (int i = 0; i < n; i++) {
                tmp[i] = (*this)[(idx + i) % n];
            }
        } else {
            for (int i = 0; i < n; i++) {
                tmp[i] = (*this)[(idx + n - i) % n];
            }
        }
        *this = tmp;
    }
    bool is_convex() const {
        int n = this->size();
        if (n <= 2) return false;
        for (int i = 0, j = 1, k = 2; i < n; i++, j++, k++) {
            if (j == n) j = 0;
            if (k == n) k = 0;
            if (ccw((*this)[i], (*this)[j], (*this)[k]) == -1) return false;
        }
        return true;
    }
    pair<int, int> diam() const {
        int n = this->size();
        if (n == 0) return {-1, -1};
        if (n == 1) return {0, 0};
        if (n == 2) return {0, 1};
        W<T> s = area();
        bool collinear = eq<W<T>>(s, 0);
        if (collinear) {
            int l = 0, r = 0;
            for (int i = 1; i < n; i++) {
                if ((*this)[i].x < (*this)[l].x || ((*this)[i].x == (*this)[l].x && (*this)[i].y < (*this)[l].y)) l = i;
                if ((*this)[i].x > (*this)[r].x || ((*this)[i].x == (*this)[r].x && (*this)[i].y > (*this)[r].y)) r = i;
            }
            return {l, r};
        }
        bool rev = s < 0;
        auto nxt = [&] (int i) { return rev ? (i == 0 ? n - 1 : i - 1) : (i + 1 == n ? 0 : i + 1); };
        auto comp = [] (W<T> a, W<T> b) {
            if constexpr (is_integral_v<T>) return (a > b) - (a < b);
            else return sgn(a - b);
        };
        int j = 0;
        Point<T> e = (*this)[nxt(0)] - (*this)[0];
        W<T> h = 0;
        for (int i = 1; i < n; i++) {
            W<T> t = cross(e, (*this)[i] - (*this)[0]);
            if (comp(t, h) > 0) j = i, h = t;
        }
        pair<int, int> res = {0, 1};
        W<T> best = norm((*this)[0] - (*this)[1]);
        auto update = [&] (int i, int j) {
            W<T> d = norm((*this)[i] - (*this)[j]);
            if (d > best) best = d, res = {i, j};
        };
        for (int i = 0, cnt = 0; cnt < n; i = nxt(i), cnt++) {
            int ni = nxt(i);
            Point<T> e = (*this)[ni] - (*this)[i];
            W<T> cur = cross(e, (*this)[j] - (*this)[i]);
            int nj = nxt(j);
            while (comp(cross(e, (*this)[nj] - (*this)[i]), cur) > 0) {
                j = nj;
                cur = cross(e, (*this)[j] - (*this)[i]);
                nj = nxt(j);
            }
            update(i, j);
            update(ni, j);
            if (comp(cross(e, (*this)[nj] - (*this)[i]), cur) == 0) {
                update(i, nj);
                update(ni, nj);
            }
        }
        return res;
    }
};

template<typename T>
inline int contain(const Polygon<T> &v, const Point<T> &p) { return v.contain(p); }
template<typename T>
inline int contain(const Point<T> &p, const Polygon<T> &v) { return v.contain(p); }
template<typename T>
inline W<T> area(const Polygon<T> &v) { return v.area(); }
template<typename T>
inline bool is_convex(const Polygon<T> &v) { return v.is_convex(); }
template<typename T>
inline pair<int, int> diam(const Polygon<T> &v) { return v.diam(); }

} // namespace geometry