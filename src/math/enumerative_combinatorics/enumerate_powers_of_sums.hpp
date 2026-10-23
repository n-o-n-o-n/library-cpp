#pragma once
#include <vector>
#include "../../fps/fps_log.hpp"
using namespace std;

// for k=0,...,K calculate sum[x in a] x^k 
template<typename mint>
vector<mint> enumerate_powers_of_sums(const vector<int> &a, int k) {
    auto rec = [&](const auto &rec, int l, int r) -> fps<mint> {
        if (l + 1 == r) return fps<mint>{1, -a[l]};
        int m = (l + r) / 2;
        return rec(rec, l, m) * rec(rec, m, r);
    };
    auto f = rec(rec, 0, a.size());
    f.resize(k + 1);
    f = -f.log().diff();
    f.insert(f.begin(), a.size());
    return f;
}