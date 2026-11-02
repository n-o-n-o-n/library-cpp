#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"

#include "../../../src/template.hpp"
#include "../../../src/math/number_theory/prime.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    for (long long P; Q--; ) {
        cin >> P;
        cout << prime::primitive_root<long long>(P) << '\n';
    }
}
