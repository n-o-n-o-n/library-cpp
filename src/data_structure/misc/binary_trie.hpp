#pragma once
#include <array>
#include <cassert>
#include <vector>
#include <limits>
using namespace std;

template<typename T, int LOG = numeric_limits<T>::digits>
struct binary_trie {
    binary_trie() : all(0), sub(1, 0), child(1, e()) {}
    int size() const { return all; }
    array<int, LOG> track(T x) const {
        int pos = 0;
        array<int, LOG> res;
        res.fill(-1);
        for (int i = LOG - 1; i >= 0; i--) {
            int c = x >> i & 1;
            int nxt = child[pos][c];
            if (nxt == -1) break;
            pos = nxt;
            res[LOG - 1 - i] = pos;
        }
        return res;
    }
    array<int, LOG> insert(T x) {
        int pos = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            int c = x >> i & 1;
            int nxt = child[pos][c];
            if (nxt == -1) {
                nxt = sub.size();
                sub.push_back(0);
                child.push_back(e());
            }
            child[pos][c] = nxt;
            pos = nxt;
        }
        auto tr = track(x);
        int p = tr.back();
        if (sub[p] == 0) {
            for (int i : tr) sub[i]++;
            all++;
        }
        return tr;
    }
    void erase(T x) {
        auto tr = track(x);
        int p = tr.back();
        if (p == -1 || sub[p] == 0) return;
        for (int i : tr) sub[i]--;
        all--;
    }
    // return (x in S ? true : false);
    bool contains(T x) const {
        int p = track(x).back();
        return (p != -1) && (sub[p] > 0);
    }
    T kth_smallest(int k, T xor_val = 0) const {
        assert(0 <= k && k < size());
        int pos = 0;
        T res = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            res *= 2;
            int c = xor_val >> i & 1;
            int nxt = child[pos][c];
            if (nxt != -1) {
                if (0 <= k && k < sub[nxt]) {
                    pos = nxt;
                    continue;
                }
                k -= sub[nxt];
            }
            pos = child[pos][1 - c];
            res++;
        }
        return res;
    }
    T kth_largest(int k, T xor_val = 0) const {
        assert(0 <= k && k < size());
        return kth_smallest(size() - 1 - k, xor_val);
    }
    T min(T xor_val = 0) const {
        assert(size());
        return kth_smallest(0, xor_val);
    }
    T max(T xor_val = 0) const {
        assert(size());
        return kth_largest(0, xor_val);
    }
    T mex(T xor_val = 0) const {
        if (size() == 0) return T(0);
        int pos = 0;
        T res = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            res *= 2;
            int c = xor_val >> i & 1;
            int nxt = child[pos][c];
            if (nxt == -1) return res << i;
            if (sub[nxt] < (T(1) << i)) {
                pos = nxt;
                continue;
            }
            res++;
            if (child[pos][1 - c] == -1) return res << i;
            pos = child[pos][1 - c];
        }
        return res + (sub[pos] != 0);
    }
    // #{s in S | s^x < k}
    int lower_count(T x, T xor_val = 0) const {
        if (x <= 0) return 0;
        if constexpr (LOG < numeric_limits<T>::digits) {
            if (x >= (T(1) << LOG)) return size();
        }
        int pos = 0;
        int res = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            if (pos == -1) break;
            int cx = (x >> i) & 1;
            int cxor = (xor_val >> i) & 1;
            int nxt0 = child[pos][cxor];
            int nxt1 = child[pos][1 - cxor];
            if (cx == 1) {
                if (nxt0 != -1) {
                    res += sub[nxt0];
                }
                pos = nxt1;
            } else {
                pos = nxt0;
            }
        }
        return res;
    }
    // #{s in S | s^x > k}
    int upper_count(T k, T xor_val = 0) const {
        if (k == numeric_limits<T>::max()) return 0;
        return size() - lower_count(k + 1, xor_val);
    }
    // max{s^x | s^x < upper }
    T prev_val(T upper, T xor_val = 0) const {
        int k = lower_count(upper, xor_val);
        return k == 0 ? T(-1) : kth_smallest(k - 1, xor_val);
    }
    // min{s^x | s^x > lower }
    T next_val(T lower, T xor_val = 0) const {
        if (lower == numeric_limits<T>::max()) return T(-1);
        int k = lower_count(lower + 1, xor_val);
        return k == size() ? T(-1) : kth_smallest(k, xor_val);
    }
private:
    int all;
    vector<int> sub;
    vector<array<int, 2>> child;
    constexpr array<int, 2> e() {
        return {-1, -1};
    }
};
