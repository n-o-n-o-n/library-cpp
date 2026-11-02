#pragma once
#include "../template.hpp"

template<typename T, T E = (is_signed_v<T> ? -inf<T>() : T(0))>
struct range_update_range_max {
    using S = T;
    using F = T;
    static S op(S a, S b) { return max(a, b); }
    static S e() { return E; }
    static F comp(F f, F g) { return f == E ? g : f; }
    static F id() { return E; }
    static S map(F f, S x) { return f == E ? x : f; }
    template<typename T2>
    static S init(T2, T2) { return E; }
};