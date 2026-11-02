#define PROBLEM "https://yukicoder.me/problems/no/3164"

#include "../../../src/data_structure/union_find/foldable_union_find.hpp"
#include "../../../src/monoid/sum.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> A(N);
    foldable_union_find<sum_monoid<long long>> uf(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        uf.set(i, A[i]);
        if (i && A[i - 1] && A[i]) uf.merge(i - 1, i);
    }
    int Q;
    cin >> Q;
    while (Q--) {
        int p;
        long long b;
        cin >> p >> b;
        p--;
        uf.set(p, b);
        long long ans = uf.prod(p);
        if (A[p] == 0) {
            if (p && A[p - 1]) ans += uf.prod(p - 1);
            if (p + 1 < N && A[p + 1]) ans += uf.prod(p + 1);
        }
        cout << ans << '\n';
        uf.set(p, A[p]);
    }
}
