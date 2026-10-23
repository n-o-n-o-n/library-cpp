#pragma once
#include <utility>
#include "../math/affine.hpp"

using namespace std;

template<typename mint, typename T = int>
struct range_affine_range_sum {
    struct S {
        mint x;
        T l;
        S(mint _x = 0, T _l = 0) : x(_x), l(_l) {}
        int val() { return x.val(); }
    };
    static S op(S a, S b) {
        return {a.x + b.x, a.l + b.l};
    }
    static S e() {
        return {0, 0};
    }
    using F = affine<mint>;
    static F comp(F f, F g) { return f(g); }
    static F id() { return F(); }
    static S map(F f, S x) {
        x.x = f.a * x.x + f.b * x.l;
        return x;
    }
    static S init(T l, T r) {
        return S(0, r - l);
    }
};