#pragma once
#include <algorithm>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>
#include "../range_query/lazysegtree.hpp"
using namespace std;

template<typename T>
struct rectangle_union {
    vector<T> xs;
    vector<tuple<T, T, T, int>> eve;
    rectangle_union(int n = 0) {
        xs.reserve(2 * n);
        eve.reserve(2 * n);
    }
    void add_rectangle(T xl, T yl, T xr, T yr) {
        if (xl == xr || yl == yr) return;
        xs.emplace_back(xl);
        xs.emplace_back(xr);
        eve.emplace_back(yl, xl, xr, 1);
        eve.emplace_back(yr, xl, xr, -1);
    }
    T solve() {
        if (eve.empty()) return 0;
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        int n = xs.size();
        sort(eve.begin(), eve.end());
        vector<pair<int, T>> init(n - 1);
        for (int i = 0; i < n - 1; i++) init[i] = {0, xs[i + 1] - xs[i]};
        lazysegtree<monoid> seg(init);
        T w = xs.back() - xs.front();
        T pre = get<0>(eve.front()), res = 0;
        for (auto [y, xl, xr, sgn] : eve) {
            auto [cnt, len] = seg.all_prod();
            res += (w - (cnt == 0 ? len : 0)) * (y - pre);
            int l = lower_bound(xs.begin(), xs.end(), xl) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), xr) - xs.begin();
            seg.apply(l, r, sgn);
            pre = y;
        }
        return res;
    }
private:
    struct monoid {
        using S = pair<int, T>;
        static S op(S a, S b) {
            if (a.first == b.first) return {a.first, a.second + b.second};
            return a.first < b.first ? a : b;
        }
        static S e() { return {numeric_limits<int>::max(), 0}; }
        using F = int;
        static F comp(F f, F g) { return f + g; }
        static F id() { return 0; }
        static S map(F f, S x) {
            if (x.first != numeric_limits<int>::max()) x.first += f;
            return x;
        }
    };
};
