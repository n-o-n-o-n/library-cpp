#pragma once
#include <cassert>
#include <limits>
#include <type_traits>
#include "../../modint/dynamic_modint.hpp"
#include "discrete_logarithm.hpp"
using namespace std;


// O(sqrt{p})
template<typename T>
long long mod_log(T a, T b, T p) {
    assert(p > 0 && p <= numeric_limits<int>::max());
    a %= p;
    b %= p;
    if (a < 0) a += p;
    if (b < 0) b += p;
    modint::set_mod(p);
    struct Monoid {
        using S = modint;
        using F = modint;
        static F comp(F f, F g) {
            return f * g;
        }
        static F id() {
            return 1;
        }
        static S mapping(F f, S x) {
            return f * x;
        }
    };
    return discrete_logarithm<Monoid>::solve(modint(a), modint(1), modint(b), p, [&] (modint x) {
        return x.val();
    });
}
