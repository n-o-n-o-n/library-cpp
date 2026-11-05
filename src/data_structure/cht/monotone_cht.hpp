#pragma once
#include "../../template.hpp"

template<typename T, bool query_dec = false>
struct monotone_cht {
    using W = conditional_t<sizeof(T) <= 4, long long, __int128_t>;
    monotone_cht() = default;
    void add_line(T a, T b) {
        line l(a, b);
        if (q.empty()) {
            pa = a;
            q.push_back(l);
            return;
        }
        if (!dir && a != pa) dir = a > pa ? 1 : -1;
        if (q[q.size() - 1].a == a) {
            if (q[q.size() - 1].b <= b) return;
            q.pop_back();
        }
        while (q.size() >= 2 && check(
            q[q.size() - 2],
            q[q.size() - 1],
            l,
            dir > 0
        )) q.pop_back();
        q.push_back(l);
        pa = a;
    }
    T get(T x) {
        if (q.empty()) return inf<T>();
        if ((dir > 0) == query_dec) {
            while (q.size() >= 2 && q[0].get(x) > q[1].get(x)) q.pop_front();
            return q[0].get(x);
        } else {
            while (q.size() >= 2 && q[q.size() - 1].get(x) > q[q.size() - 2].get(x)) q.pop_back();
            return q[q.size() - 1].get(x);
        }
    }
private:
    struct line {
        T a, b;
        line(T _a, T _b) : a(_a), b(_b) {}
        T get(T x) const { return a * x + b; }
    };
    deque<line> q;
    T pa;
    int dir = 0;
    static bool check(line l1, line l2, line l3, bool f) {
        W l = W(l2.b - l1.b) * (l3.a - l2.a);
        W r = W(l3.b - l2.b) * (l2.a - l1.a);
        return f ? l >= r : l <= r;
    }
};