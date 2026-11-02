#pragma once
#include "../template.hpp"

template<typename T, T E = (is_signed_v<T> ? -inf<T>() : T(0))>
struct max_monoid {
    using S = T;
    static S op(S a, S b) { return max(a, b); }
    static S e() { return E; }
};