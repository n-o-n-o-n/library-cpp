#pragma once
#include <cassert>
#include <limits>
#include <type_traits>
#include <vector>
#include "sparse_table.hpp"
#include "../../monoid/min.hpp"
using namespace std;

template<typename T, T inf = numeric_limits<T>::max()>
struct static_rmq {
    static_assert(is_integral_v<T>);
    static_rmq() = default;
    static_rmq(const vector<T> &_v) : n(_v.size()), v(_v), pref(n), suff(n) { build(); }
    T prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return inf;
        r--;
        int bl = l >> log, br = r >> log;
        if (bl < br) {
            if (bl + 1 == br) return min(pref[r], suff[l]);
            return min(min(pref[r], suff[l]), st.prod(bl + 1, br));
        }
        T res = v[l];
        for (int i = l + 1; i <= r; i++) res = min(res, v[i]);
        return res;
    }
private:
    int n;
    static constexpr int log = 4, mask = 15;
    vector<T> v, pref, suff;
    sparse_table<min_monoid<T, inf>> st;
    void build() {
        if (n == 0) return;
        pref[0] = v[0];
        suff[n - 1] = v[n - 1];
        for (int i = 1; i < n; i++) {
            pref[i] = i & mask ? min(pref[i - 1], v[i]) : v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = (i & mask) == mask ? v[i] : min(v[i], suff[i + 1]);
        }
        st = sparse_table<min_monoid<T, inf>>([&] {
            vector<T> a(n >> log);
            for (int i = 0; i < (n >> log); i++) {
                a[i] = suff[i << log];
            }
            return move(a);
        } ());
    }
};