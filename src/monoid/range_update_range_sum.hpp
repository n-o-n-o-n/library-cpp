#pragma once
#include <limits>
using namespace std;

template<typename T1, T1 E = numeric_limits<T1>::max(), typename T2 = int>
struct range_update_range_sum {
    struct S {
        T1 x;
        T2 l;
        S(T1 _x = 0, T2 _l = 0) : x(_x), l(_l) {}
        T1 val() { return x; }
    };
    using F = T1;
    static S op(S a, S b) { return S{a.x + b.x, a.l + b.l}; }
    static S e() { return S{0, 0}; }
    static F comp(F f, F g) { return f == E ? g : f; }
    static F id() { return E; }
    static S map(F f, S x) {
        if (f != id()) x.x = f * x.l;
        return x;
    }
    static S init(T2 l, T2 r) { return S{0, r - l}; }
};