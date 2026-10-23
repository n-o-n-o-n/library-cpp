#define PROBLEM "https://yukicoder.me/problems/no/2786"

#include "../../src/data_structure/union_find/union_find.hpp"
#include "../../src/misc/parallel_binary_search.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (auto &E : A) for (auto &e : E) cin >> e;
    int Q;
    cin >> Q;
    vector<tuple<int, int, int, int>> qs(Q);
    for (auto &[sr, sc, tr, tc] : qs) {
        cin >> sr >> sc >> tr >> tc;
        sr--, sc--, tr--, tc--;
    }
    vector<pair<int, int>> ord;
    ord.reserve(H * W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) ord.emplace_back(i, j);
    }
    sort(ord.begin(), ord.end(), [&] (pair<int, int> p, pair<int, int> q) {
        return A[p.first][p.second] < A[q.first][q.second];
    });
    union_find uf(H * W);
    vector<vector<bool>> alive(H, vector<bool>(W, false));
    const int D[5] = {0, 1, 0, -1, 0};
    auto reset = [&] () {
        uf = union_find(H * W);
        alive = vector<vector<bool>>(H, vector<bool>(W, false));
    };
    auto act = [&] (int i) {
        auto [r, c] = ord[i];
        alive[r][c] = true;
        for (int d = 0; d < 4; d++) {
            int nr = r + D[d], nc = c + D[d + 1];
            if (0 <= nr && nr < H && 0 <= nc && nc < W && alive[nr][nc]) {
                uf.merge(r * W + c, nr * W + nc);
            }
        }
    };
    auto query = [&](int j) {
        auto [sr, sc, tr, tc] = qs[j];
        return alive[sr][sc] && alive[tr][tc] && uf.same(sr * W + sc, tr * W + tc);
    };
    auto ans = parallel_binary_search(H * W, Q, act, query, reset);
    for (int i : ans) cout << A[ord[i].first][ord[i].second] << '\n';
}
