#pragma once
#include <algorithm>
#include <cassert>
#include <iterator>
#include <limits>
#include <set>
#include <utility>
#include <vector>
using namespace std;

template<typename T>
struct interval_set {
    interval_set() = default;
    template<typename A, typename D>
    void insert(T l, T r, const A &add, const D &del) {
        if (l == r) return;
        assert(l < r);
        auto cur = key(l);
        if (cur != s.end() && cur->l <= l && r <= cur->r) return;
        auto it = s.lower_bound(node(l, l));
        if (it != s.begin()) {
            auto pre = prev(it);
            if (l <= pre->r) {
                l = pre->l;
                r = max(r, pre->r);
                del(pre->l, pre->r);
                it = s.erase(pre);
            }
        }
        while (it != s.end() && it->l <= r) {
            r = max(r, it->r);
            del(it->l, it->r);
            it = s.erase(it);
        }
        add(l, r);
        s.emplace_hint(it, l, r);
    }
    void insert(T l, T r) {
        insert(l, r, [] (T, T) {}, [] (T, T) {});
    }
    template<typename A, typename D>
    void insert(T k, const A &add, const D &del) {
        assert(k < inf);
        insert(k, k + 1, add, del);
    }
    void insert(T k) {
        assert(k < inf);
        insert(k, k + 1);
    }
    template<typename A, typename D>
    void erase(T l, T r, const A &add, const D &del) {
        if (l == r) return;
        assert(l < r);
        auto it = s.lower_bound(node(l, l));
        if (it != s.begin() && prev(it)->r > l) it = prev(it);
        while (it != s.end() && it->l < r) {
            auto [a, b] = *it;
            it = s.erase(it);
            del(a, b);
            if (a < l) {
                add(a, l);
                s.emplace_hint(it, a, l);
            }
            if (r < b) {
                add(r, b);
                s.emplace_hint(it, r, b);
                break;
            }
        }
    }
    void erase(T l, T r) {
        erase(l, r, [] (T, T) {}, [] (T, T) {});
    }
    template<typename A, typename D>
    void erase(T k, const A &add, const D &del) {
        assert(k < inf);
        erase(k, k + 1, add, del);
    }
    void erase(T k) {
        assert(k < inf);
        erase(k, k + 1);
    }
    pair<T, T> get(T k) const {
        auto it = key(k);
        if (it != s.end() && it->l <= k && k < it->r) return {it->l, it->r};
        return {inf, inf};
    }
    T mex(T k = 0) const {
        auto it = key(k);
        return it != s.end() && it->l <= k && k < it->r ? it->r : k;
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
        return it != s.end() && it->l <= l && r <= it->r;
    }
    bool covered(T k) const {
        assert(k < inf);
        return covered(k, k + 1);
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
    vector<pair<T, T>> intervals(T l = low, T r = inf) const {
        assert(l <= r);
        vector<pair<T, T>> res;
        if (l == r) return res;
        auto it = key(l);
        if (it == s.end()) it = s.begin();
        for (; it != s.end() && it->l < r; ++it) {
            if (l < it->r) res.emplace_back(max(l, it->l), min(r, it->r));
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
        node(T _l, T _r) : l(_l), r(_r) {}
        constexpr bool operator<(const node &a) const {
            return l == a.l ? r < a.r : l < a.l;
        }
    };
    set<node> s;
    typename set<node>::const_iterator key(T k) const {
        auto it = s.upper_bound(node(k, inf));
        return it == s.begin() ? s.end() : prev(it);
    }
};
