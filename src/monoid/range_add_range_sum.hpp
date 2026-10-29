#pragma once
using namespace std;

template<typename T1, typename T2 = int>
struct range_add_range_sum {
    struct S {
        T1 x;
        T2 l;
        S(T1 _x = 0, T2 _l = 0) : x(_x), l(_l) {}
        T1 val() { return x; }
    };
    using F = T1;
    static S op(S a, S b) { return S{a.x + b.x, a.l + b.l}; }
    static S e() { return S{0, 0}; }
    static F comp(F f, F g) { return f + g; }
    static F id() { return 0; }
    static S map(F f, S x) {
        x.x += f * x.l;
        return x;
    }
    static S init(T2 l, T2 r) { return S{0, r - l}; }
};