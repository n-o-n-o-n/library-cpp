#pragma once
#include "../template.hpp"
#include "subprod_tree.hpp"

template<typename mint>
vector<mint> multipoint_evaluation(const fps<mint> &f, const vector<mint> &xs) {
    return subprod_tree<mint>(xs).multipoint_evaluation(f);
}