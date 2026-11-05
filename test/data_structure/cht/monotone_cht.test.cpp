#define PROBLEM "https://yukicoder.me/problems/no/703"

#include "../../../src/template.hpp"
#include "../../../src/data_structure/cht/monotone_cht.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<ll> A(N), X(N), Y(N);
    for (auto &e : A) cin >> e;
    for (auto &e : X) cin >> e;
    for (auto &e : Y) cin >> e;
    monotone_cht<ll> cht;
    monotone_cht<ll, true> cht2;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        cht.add_line(-2 * X[i], ans + X[i] * X[i] + Y[i] * Y[i]);
        cht2.add_line(2 * X[i], ans + X[i] * X[i] + Y[i] * Y[i]);
        ll v1 = cht.get(A[i]);
        ll v2 = cht2.get(-A[i]);
        assert(v1 == v2);
        ans = v1 + A[i] * A[i];
    }
    cout << ans << endl;
}