#pragma once
#include <cassert>
#include <numeric>
#include <vector>
using namespace std;

struct binary_fenwick_tree {
    binary_fenwick_tree() : binary_fenwick_tree(0) {}
    binary_fenwick_tree(int _n) : binary_fenwick_tree(vector<int>(_n, 0)) {}
    template<typename T>
    binary_fenwick_tree(const vector<T> &_v) : n(_v.size()) {
        sz = (n + 63) >> 6;
        bit = vector<unsigned long long>(sz, 0);
        d = v = vector<int>(sz, 0);
        for (int p = 0; p < n; p++) {
            if (_v[p]) {
                int i = p >> 6, j = p & 63;
                bit[i] |= 1ULL << j;
            }
        }
        for (int i = 1; i <= sz; i++) {
            v[i - 1] = __builtin_popcountll(bit[i - 1]);
            d[i - 1] += v[i - 1];
            int j = i + (i & -i);
            if (j <= sz) d[j - 1] += d[i - 1];
        }
    }
    void set(int p) {
        assert(0 <= p && p < n);
        int i = p >> 6, j = p & 63;
        if ((bit[i] >> j & 1) == 0) {
            bit[i] |= 1ULL << j;
            fw_update(i);
        }
    }
    void reset(int p) {
        assert(0 <= p && p < n);
        int i = p >> 6, j = p & 63;
        if (bit[i] >> j & 1) {
            bit[i] &= ~(1uLL << j);
            fw_update(i);
        }
    }
    void flip(int p) {
        assert(0 <= p && p < n);
        int i = p >> 6, j = p & 63;
        bit[i] ^= 1ULL << j;
        fw_update(i);
    }
    bool test(int p) const {
        assert(0 <= p && p < n);
        return bit[p >> 6] >> (p & 63) & 1;
    }
    int count(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        if (l == r) return 0;
        int il = l >> 6, jl = l & 63;
        int ir = r >> 6, jr = r & 63;
        if (il == ir) {
            return __builtin_popcountll((bit[il] >> jl) & mask(jr - jl));
        }
        int res = fw_sum(ir) - fw_sum(il);
        res -= __builtin_popcountll(bit[il] & mask(jl));
        if (jr) res += __builtin_popcountll(bit[ir] & mask(jr));
        return res;
    }
    bool all(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return count(l, r) == r - l;
    }
    bool any(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return count(l, r) > 0;
    }
    bool none(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return count(l, r) == 0;
    }
    int kth_element(int k) const {
        assert(k >= 0);
        if (k >= n) return -1;
        int x = k + 1;
        int p = fw_lower_bound(x);
        if (p == sz) return -1;
        int l = 0, r = 64;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            (__builtin_popcountll(bit[p] & mask(m)) < x ? l : r) = m;
        }
        return (p << 6) ^ l;
    }
    int next_element(int p) const {
        assert(0 <= p && p < n);
        return kth_element(count(0, p));
    }
    int prev_element(int p) const {
        assert(0 <= p && p < n);
        int x = count(0, p + 1);
        return x == 0 ? -1 : kth_element(x - 1);
    }
private:
    int n, sz;
    vector<unsigned long long> bit;
    vector<int> d, v;
    static constexpr unsigned long long mask(int m) {
        return (1ULL << m) - 1;
    }
    void fw_update(int p) {
        int x = __builtin_popcountll(bit[p]) - v[p];
        v[p] += x;
        for (p++; p <= sz; p += p & -p) {
            d[p - 1] += x;
        }
    }
    int fw_sum(int p) const {
        int res = 0;
        while (p > 0) {
            res += d[p - 1];
            p -= p & -p;
        }
        return res;
    }
    int fw_lower_bound(int &x) const {
        int r = 0, p = 1;
        while ((p << 1) <= sz) p <<= 1;
        while (p > 0) {
            if (r + p <= sz && d[r + p - 1] < x) {
                r += p;
                x -= d[r - 1];
            }
            p >>= 1;
        }
        return r;
    }
};