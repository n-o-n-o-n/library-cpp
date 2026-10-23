#pragma once
#include <numeric>
using namespace std;

template<typename T, T E = numeric_limits<T>::min()>
struct max_monoid {
    using S = T;
    static S op(S a, S b) { return max(a, b); }
    static S e() { return E; }
};