#pragma once
#include <cassert>
#include <numeric>
#include <vector>
#include "../../misc/merge_and_unique.hpp"
#include "../range_query/segtree.hpp"
using namespace std;

template<typename Abelian_Group, typename T = int>
struct rectangle_sum {
    using M = Abelian_Group;
    using S = typename M::S;
    rectangle_sum(int n = 0, int q = 0) {
        xs.reserve(n);
        ys.reserve(n);
        ws.reserve(n);
        xls.reserve(q);
        yls.reserve(q);
        xrs.reserve(q);
        yrs.reserve(q);
    }
    void add_point(T x, T y, S w) {
        xs.emplace_back(x);
        ys.emplace_back(y);
        ws.emplace_back(w);
    }
    void add_query(T xl, T yl, T xr, T yr) {
        xls.emplace_back(xl);
        yls.emplace_back(yl);
        xrs.emplace_back(xr);
        yrs.emplace_back(yr);
    }
    vector<S> solve() {
        int n = xs.size(), q = xls.size();
        if (n == 0 || q == 0) return vector<S>(q, M::e());
        auto yb = merge_and_unique(ys);
        vector<int> yi(n);
        for (int i = 0; i < n; i++) {
            yi[i] = lower_bound(yb.begin(), yb.end(), ys[i]) - yb.begin();
        }
        vector<int> ord_pts(n), ord_query(2 * q);
        iota(ord_pts.begin(), ord_pts.end(), 0);
        iota(ord_query.begin(), ord_query.end(), 0);
        sort(ord_pts.begin(), ord_pts.end(), [&] (int i, int j) { return xs[i] < xs[j]; });
        sort(ord_query.begin(), ord_query.end(), [&] (int i, int j) {
            T xi = i < q ? xls[i] : xrs[i - q];
            T xj = j < q ? xls[j] : xrs[j - q];
            return xi < xj;
        });
        segtree<M> seg(yb.size());
        vector<S> res(q, M::e());
        int j = 0;
        for (int i : ord_query) {
            T x = (i < q ? xls[i] : xrs[i - q]);
            while (j < n && xs[ord_pts[j]] < x) {
                seg.apply(yi[ord_pts[j]], ws[ord_pts[j]]);
                j++;
            }
            if (i < q) {
                int yl = lower_bound(yb.begin(), yb.end(), yls[i]) - yb.begin();
                int yr = lower_bound(yb.begin(), yb.end(), yrs[i]) - yb.begin();
                res[i] = M::op(res[i], M::inv(seg.prod(yl, yr)));
            } else {
                i -= q;
                int yl = lower_bound(yb.begin(), yb.end(), yls[i]) - yb.begin();
                int yr = lower_bound(yb.begin(), yb.end(), yrs[i]) - yb.begin();
                res[i] = M::op(res[i], seg.prod(yl, yr));
            }
        }
        return res;
    }
private:
    vector<T> xs, ys, xls, yls, xrs, yrs;
    vector<S> ws;
};