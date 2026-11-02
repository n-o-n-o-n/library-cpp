#define PROBLEM "https://yukicoder.me/problems/no/2242"

#include "../../src/template.hpp"
#include "../../src/graph/weighted_functional_graph.hpp"
#include "../../src/misc/compress.hpp"
#include "../../src/monoid/max.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> H(N), T(N);
    for (auto &e : H) cin >> e;
    for (auto &e : T) cin >> e;
    int M = compress_inplace(H, T);
    vector<int> to(M);
    iota(to.begin(), to.end(), 0);
    for (int i = 0; i < N; i++) to[H[i]] = max(to[H[i]], T[i]);
    for (int i = 1; i < M; i++) to[i] = max(to[i], to[i - 1]);
    weighted_functional_graph<max_monoid<int>, true> E(M);
    weighted_functional_graph<max_monoid<int>, false> V(M);
    for (int i = 0; i < M; i++) {
        E.add_edge(i, to[i], to[i]);
        V.add_edge(i, to[i]);
        V.set_weight(i, i);
    }
    int Q;
    cin >> Q;
    for (int a, b; Q--; ) {
        cin >> a >> b;
        a--, b--;
        if (H[b] <= T[a]) {
            cout << 1 << '\n';
        } else {
            auto check = [&] (int x) { return x < H[b]; };
            long long r = E.binary_search(T[a], M, check).first;
            long long s = V.binary_search(T[a], M, check).first;
            assert(r == s);
            cout << (r == M ? -1 : r + 2) << '\n';
        }
    }
}
