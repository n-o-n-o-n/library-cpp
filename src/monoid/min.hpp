#pragma once
#include "../template.hpp"

template<typename T, T E = inf<T>()>
struct min_monoid {
    using S = T;
    static S op(S a, S b) { return min(a, b); }
    static S e() { return E; }
};