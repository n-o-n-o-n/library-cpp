#define PROBLEM "https://yukicoder.me/problems/no/2242"

#include "../../src/template.hpp"
#include "../../src/misc/compress.hpp"
#include "../../src/graph/functional_graph.hpp"

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
    functional_graph G(M);
    for (int i = 0; i < M; i++) G.add_edge(i, to[i]);
    int Q;
    cin >> Q;
    for (int a, b; Q--; ) {
        cin >> a >> b;
        a--, b--;
        if (H[b] <= T[a]) {
            cout << 1 << '\n';
        } else {
            int r = G.binary_search(T[a], [&] (int x) { return x < H[b]; }).first;
            cout << (r == -1 ? -1 : r + 2) << '\n';
        }
    }
}
