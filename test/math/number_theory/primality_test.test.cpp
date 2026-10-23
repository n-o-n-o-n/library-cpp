#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include "../../../src/math/number_theory/prime.hpp"

#include <iostream>

static_assert(prime::is_prime<int>(2147483647));
static_assert(!prime::is_prime<unsigned>(3215031751U));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q;
    cin >> Q;
    for (long long N; Q--; ) {
        cin >> N;
        cout << (prime::is_prime<long long>(N) ? "Yes\n" : "No\n");
    }
}
