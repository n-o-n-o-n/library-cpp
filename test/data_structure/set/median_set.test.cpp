#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../src/random/sequence.hpp"
#include "../../../src/data_structure/set/median_set.hpp"

#include <bits/stdc++.h>

namespace AC {

// https://atcoder.jp/contests/abc127/submissions/80286090

using namespace std;

// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8

template<typename T>
struct slope_trick {
    slope_trick() : min_val(0), left_add(0), right_add(0) {
        left.push(-inf);
        right.push(inf);
    }
    T get_min() const { return min_val; }
    pair<T, T> min_range() const { return make_pair(left_top(), right_top()); }
    // f(x) += a
    void add_all(T a) { min_val += a; }
    // f(x) += max(0, x - a)
    void add_x_minus_a(T a) {
        min_val += max<T>(0, left_top() - a);
        left_push(a);
        right_push(left_pop());
    }
    // f(x) += max(0, a - x)
    void add_a_minus_x(T a) {
        min_val += max<T>(0, a - right_top());
        right_push(a);
        left_push(right_pop());
    }
    // f(x) += |x - a|
    void add_abs_x_minus_a(T a) {
        add_x_minus_a(a);
        add_a_minus_x(a);
    }
    // f_new(x) = f(x - c)
    void shift(T c) {
        left_add += c;
        right_add += c;
    }
    // f_new(x) = min_{y in [x-l, x-r]} f_cur(y)
    void slide_window_min(T l, T r) {
        assert(l >= r);
        left_add += r;
        right_add += l;
    }
private:
    static constexpr T inf = numeric_limits<T>::max() / 3;
    T min_val, left_add, right_add;
    priority_queue<T, vector<T>, less<T>> left;
    priority_queue<T, vector<T>, greater<T>> right;
    T left_top() const {
        assert(left.size());
        return left.top() + left_add;
    }
    T right_top() const {
        assert(right.size());
        return right.top() + right_add;
    }
    T left_pop() {
        T res = left_top();
        left.pop();
        return res;
    }
    T right_pop() {
        T res = right_top();
        right.pop();
        return res;
    }
    void left_push(T a) { left.push(a - left_add); }
    void right_push(T a) { right.push(a - right_add); }
};

vector<pair<long long, long long>> solve(vector<int> T, vector<int> A, vector<int> B) {
    int Q = T.size();
    slope_trick<long long> ST;
    vector<pair<long long, long long>> res;
    for (int i = 0; i < Q; i++) {
        if (T[i] == 1) {
            ST.add_abs_x_minus_a(A[i]);
            ST.add_all(B[i]);
        } else {
            res.emplace_back(ST.min_range().first, ST.get_min());
        }
    }
    return res;
}

} // namespace AC

vector<pair<long long, long long>> median_set_test(vector<int> T, vector<int> A, vector<int> B) {
    median_set<long long> S;
    long long add = 0;
    vector<pair<long long, long long>> res;
    for (int i = 0; i < (int)T.size(); i++) {
        if (T[i] == 1) {
            S.insert(A[i]);
            add += B[i];
        } else {
            res.emplace_back(S.median(), S.min_cost() + add);
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    {
        int A, B;
        cin >> A >> B;
        cout << A + B << '\n';
    }
    for (int t = 0; t < 10; t++) {
        int Q = rng::randint<int>(1e5, 2e5);
        auto T = rng::random_sequence<int>(Q, 1, 2);
        T[0] = 1;
        auto A = rng::random_sequence<int>(Q, -1e9, 1e9);
        auto B = rng::random_sequence<int>(Q, -1e9, 1e9);
        assert(AC::solve(T, A, B) == median_set_test(T, A, B));
    }
}