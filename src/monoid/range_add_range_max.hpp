#pragma once
#include <algorithm>
#include <limits>
using namespace std;

template<typename T, T E = numeric_limits<T>::min()>
struct range_add_range_max {
    using S = T;
    using F = T;
    static S op(S a, S b) { return max(a, b); }
    static S e() { return E; }
    static F comp(F f, F g) { return f + g; }
    static F id() { return 0; }
    static S map(F f, S x) { return x == E ? x : f + x; }
    template<typename T2>
    static S init(T2, T2) { return E; }
};