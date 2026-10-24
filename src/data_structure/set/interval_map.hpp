#pragma once
#include <algorithm>
#include <cassert>
#include <iterator>
#include <limits>
#include <set>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

template<typename T, typename S>
struct interval_map {
    interval_map(const S &_e = S()) : e(_e) {}
    template<typename A, typename D>
    void update(T l, T r, const S &x, const A &add, const D &del) {
        if (l == r) return;
        assert(l < r);
        auto cur = key(l);
        if (cur != s.end() && cur->l <= l && r <= cur->r && cur->x == x) return;
        auto it = s.lower_bound(node(l, l, e));
        if (it != s.begin() && prev(it)->r > l) it = prev(it);
        while (it != s.end() && it->l < r) {
            auto [a, b, y] = *it;
            it = s.erase(it);
            del(a, b, y);
            if (a < l) {
                add(a, l, y);
                s.emplace_hint(it, a, l, y);
            }
            if (r < b) {
                add(r, b, y);
                s.emplace_hint(it, r, b, y);
                break;
            }
        }
        it = s.lower_bound(node(l, l, e));
        if (it != s.begin()) {
            auto pre = prev(it);
            if (pre->r == l && pre->x == x) {
                l = pre->l;
                del(pre->l, pre->r, pre->x);
                it = s.erase(pre);
            }
        }
        if (it != s.end() && it->l == r && it->x == x) {
            r = it->r;
            del(it->l, it->r, it->x);
            it = s.erase(it);
        }
        add(l, r, x);
        s.emplace_hint(it, l, r, x);
    }
    void update(T l, T r, const S &x) {
        update(l, r, x, [] (T, T, S) {}, [] (T, T, S) {});
    }
    template<typename A, typename D>
    void update(T k, const S &x, const A &add, const D &del) {
        assert(k < inf);
        update(k, k + 1, x, add, del);
    }
    void update(T k, const S &x) {
        assert(k < inf);
        update(k, k + 1, x);
    }
    tuple<T, T, S> get(T k) const {
        assert(k < inf);
        auto it = key(k);
        return it != s.end() && k < it->r ? make_tuple(it->l, it->r, it->x) : make_tuple(k, k + 1, e);
    }
    S operator[](T k) const {
        auto it = key(k);
        return it != s.end() && k < it->r ? it->x : e;
    }
    tuple<T, T, S> mex(T k) const {
        auto it = key(k);
        if (it == s.end()) it = s.begin();
        else if (it->r <= k) ++it;
        return it == s.end() ? make_tuple(inf, inf, e) : make_tuple(it->l, it->r, it->x);
    }
    T next_element(T k) const {
        auto it = key(k);
        if (it == s.end()) it = s.begin();
        else if (k < it->r) return k;
        else ++it;
        return it == s.end() ? low : it->l;
    }
    T prev_element(T k) const {
        auto it = key(k);
        if (it == s.end()) return inf;
        return k < it->r ? k : it->r - 1;
    }
    bool covered(T l, T r) const {
        if (l == r) return true;
        assert(l < r);
        auto it = key(l);
        if (it == s.end() || it->r <= l) return false;
        T pos = it->r;
        while (pos < r) {
            ++it;
            if (it == s.end() || it->l != pos) return false;
            pos = it->r;
        }
        return true;
    }
    bool covered(T k) const {
        assert(k < inf);
        auto it = key(k);
        return it != s.end() && k < it->r;
    }
    bool intersects(T l, T r) const {
        if (l == r) return false;
        assert(l < r);
        auto it = key(l);
        if (it == s.end()) it = s.begin();
        else if (it->r <= l) ++it;
        return it != s.end() && it->l < r;
    }
    bool empty() const {
        return s.empty();
    }
    int size() const {
        return s.size();
    }
    vector<tuple<T, T, S>> intervals(T l = low, T r = inf) const {
        assert(l <= r);
        vector<tuple<T, T, S>> res;
        if (l == r) return res;
        auto it = key(l);
        if (it == s.end()) it = s.begin();
        for (; it != s.end() && it->l < r; ++it) {
            if (l < it->r) res.emplace_back(max(l, it->l), min(r, it->r), it->x);
        }
        return res;
    }
    void clear() {
        s.clear();
    }
private:
    static constexpr T low = numeric_limits<T>::min();
    static constexpr T inf = numeric_limits<T>::max();
    struct node {
        T l, r;
        S x;
        node(T _l, T _r, const S &_x) : l(_l), r(_r), x(_x) {}
        constexpr bool operator<(const node &a) const {
            return l == a.l ? r < a.r : l < a.l;
        }
    };
    const S e;
    set<node> s;
    typename set<node>::const_iterator key(T k) const {
        auto it = s.upper_bound(node(k, inf, e));
        return it == s.begin() ? s.end() : prev(it);
    }
};
