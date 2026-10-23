#pragma once
#include <cassert>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

template<typename T, int LOG = numeric_limits<T>::digits>
struct wavelet_matrix {
    wavelet_matrix() : wavelet_matrix(0) {}
    wavelet_matrix(int _n) : n(_n), d(_n), built(false) {}
    wavelet_matrix(const vector<T> &v) : n(v.size()), d(v), built(false) {}
    void set(int p, const T &x) {
        assert(0 <= p && p < n);
        d[p] = x;
    }
    T get(int p) {
        assert(0 <= p && p < n);
        build();
        T res = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            bool flag = mat[i][p];
            res |= T(flag) << i;
            p = id(p, i, flag);
        }
        return res;
    }
    T range_kth_smallest(int l, int r, int k) {
        assert(0 <= l && l <= r && r <= n);
        assert(0 <= k && k < r - l);
        build();
        T res = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            int m = mat[i].rank(r) - mat[i].rank(l);
            if (k < m) {
                l = mat[i].rank(l);
                r = mat[i].rank(r);
            } else {
                res += T(1) << i;
                l = id(l, i, true);
                r = id(r, i, true);
                k -= m;
            }
        }
        return res;
    }
    T prev_val(int l, int r, T upper) {
        assert(0 <= l && l <= r && r <= n);
        build();
        int cnt = range_freq(l, r, 0, upper);
        return cnt == 0 ? -1 : range_kth_smallest(l, r, cnt - 1);
    }
    T next_val(int l, int r, T lower) {
        assert(0 <= l && l <= r && r <= n);
        build();
        int cnt = range_freq(l, r, 0, lower);
        return cnt == r - l ? -1 : range_kth_smallest(l, r, cnt);
    }
    int count(int l, int r, T x) {
        assert(0 <= l && l <= r && r <= n);
        build();
        auto f = [&](int k) -> int {
            for (int i = LOG - 1; i >= 0; i--) {
                bool flag = x >> i & 1;
                k = id(k, i, flag);
            }
            return k - st[x];
        };
        return f(r) - f(l);
    }
    int range_freq(int l, int r, T lower, T upper) {
        assert(0 <= l && l <= r && r <= n);
        build();
        auto f = [&](T x) -> int {
            int res = 0;
            int ll = l, rr = r;
            for (int i = LOG - 1; i >= 0; i--) {
                bool flag = x >> i & 1;
                res += flag * (mat[i].rank(r) - mat[i].rank(l));
                l = id(l, i, flag);
                r = id(r, i, flag);
            }
            l = ll, r = rr;
            return res;
        };
        return f(upper) - f(lower);
    }
private:
    struct bit_vector {
        bit_vector() = default;
        bit_vector(const vector<bool> &v) {
            int n = v.size();
            int m = n / b + 1;
            d = vector<unsigned>(m);
            sum = vector<int>(m + 1);
            for (int i = 0; i < n; i++) {
                d[i / b] |= v[i] << (i % b);
            }
            for (int i = 0; i < m; i++) {
                sum[i + 1] = sum[i] + __builtin_popcount(d[i]);
            }
        }
        bool operator[](int i) const { return d[i / b] >> (i % b) & 1; }
        int rank(int i, bool flag = false) const {
            int mask = (1U << (i % b)) - 1;
            int r = sum[i / b] + __builtin_popcount(d[i / b] & mask);
            return flag ? r : i - r;
        }
        int select(int i, bool flag) const {
            int l = 0, r = d.size();
            while (r - l > 1) {
                int m = (l + r) >> 1;
                (rank(i, flag) < i ? l : r) = m;
            }
            return l;
        }
    private:
        static constexpr int b = 32;
        vector<unsigned> d;
        vector<int> sum;
    };
    int n;
    vector<T> d;
    vector<bit_vector> mat;
    vector<int> cnt;
    unordered_map<T, int> st;
    bool built;
    void build() {
        if (built) return;
        mat = vector<bit_vector>(LOG);
        cnt = vector<int>(LOG);
        for (auto &x : d) assert(x >= 0);
        for (int i = LOG - 1; i >= 0; i--) {
            vector<bool> bit(n);
            for (int j = 0; j < n; j++) {
                bit[j] = d[j] >> i & 1;
            }
            mat[i] = bit_vector(bit);
            int c0 = 0, c1 = n;
            for (int j = 0; j < n; j++) {
                if (!bit[j]) c0++;
            }
            cnt[i] = c0;
            vector<T> d2(n);
            for (int j = n - 1; j >= 0; j--) {
                d2[--(bit[j] ? c1 : c0)] = d[j];
            }
            d = d2;
        }
        for (int i = 0; i < n; i++) {
            if (st.find(d[i]) == st.end()) st[d[i]] = i;
        }
        built = true;
    }
    int id(int p, int i, bool flag) {
        return cnt[i] * flag + mat[i].rank(p, flag);
    }
};
