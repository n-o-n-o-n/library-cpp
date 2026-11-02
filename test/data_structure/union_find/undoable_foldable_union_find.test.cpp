#define PROBLEM "https://yukicoder.me/problems/no/3164"

#include "../../../src/data_structure/union_find/undoable_foldable_union_find.hpp"
#include "../../../src/monoid/sum.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> A(N);
    undoable_foldable_union_find<sum_monoid<long long>> uf(N);
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
        int k = 0;
        if (A[p] == 0) {
            if (p && A[p - 1]) {
                uf.merge(p - 1, p);
                k++;
            }
            if (p + 1 < N && A[p + 1]) {
                uf.merge(p, p + 1);
                k++;
            }
        }
        cout << uf.prod(p) << '\n';
        while (k--) uf.undo();
        uf.undo();
    }
}
