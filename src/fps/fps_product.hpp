#pragma once
#include "fps.hpp"
#include <queue>
#include <utility>
#include <vector>
using namespace std;

template<typename mint>
struct fps_product {
    void push_back(const fps<mint> &f) {
        pq.push(f);
    }
    fps<mint> prod() {
        while (pq.size() > 1) {
            fps<mint> f = pq.top();
            pq.pop();
            fps<mint> g = pq.top();
            pq.pop();
            f *= move(g);
            pq.push(move(f));
        }
        if (pq.empty()) return fps<mint>(1, 1);
        return pq.top();
    }
private:
    using Compare = decltype([](const fps<mint> &f, const fps<mint> &g) {
        return f.size() > g.size();
    });
    priority_queue<fps<mint>, vector<fps<mint>>, Compare> pq;
};
