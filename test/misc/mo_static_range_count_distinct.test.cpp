#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"

#include "../../src/misc/compress.hpp"
#include "../../src/misc/mo.hpp"

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (auto &e : A) cin >> e;
    MO mo(N, Q);
    for (int i = 0, l, r; i < Q; i++) {
        cin >> l >> r;
        mo.add_query(l, r);
    }
    vector<int> cnt(compress_inplace(A));
    int cur = 0;
    vector<int> ans(Q);
    auto ex = [&] (int i) -> void { cur += cnt[A[i]]++ == 0; };
    auto sh = [&] (int i) -> void { cur -= --cnt[A[i]] == 0; };
    auto out = [&] (int i) -> void { ans[i] = cur; };
    mo.run(ex, sh, out);
    for (auto e : ans) cout << e << '\n';
}