#pragma once

template<typename T>
struct sum_monoid {
    using S = T;
    static S op(S a, S b) { return a + b; }
    static S e() { return 0; }
    static S inv(S x) { return -x; }
};