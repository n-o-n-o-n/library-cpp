---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/set/median_set.hpp
    title: Median Set
  - icon: ':heavy_check_mark:'
    path: src/random/sequence.hpp
    title: Random Sequence
  - icon: ':question:'
    path: src/random/utility.hpp
    title: Random Utility
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://atcoder.jp/contests/abc127/submissions/80286090
    - https://judge.yosupo.jp/problem/aplusb
    - https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8
  bundledCode: "#line 1 \"test/data_structure/set/median_set.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 2 \"src/random/sequence.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <vector>\n#line 3 \"src/random/utility.hpp\"\
    \n#include <concepts>\n#include <random>\nusing namespace std;\n\nnamespace rng\
    \ {\n\ninline random_device seed;\ninline mt19937 eng(seed());\n\ntemplate<typename\
    \ T>\nvoid set_seed(const T &sd) {\n    eng.seed(sd);\n}\n\ntemplate<integral\
    \ T>\ninline T randint(T lo, T hi) {\n    assert(lo <= hi);\n    uniform_int_distribution<T>\
    \ dist(lo, hi);\n    return dist(eng);\n}\n\ntemplate<integral T>\ninline pair<T,\
    \ T> randpair(T lo, T hi, bool strict = false) {\n    assert(lo + strict <= hi);\n\
    \    T l = randint(lo, hi - strict);\n    T r = randint(l + strict, hi);\n   \
    \ return make_pair(l, r);\n}\n\n} // namespace rng\n#line 6 \"src/random/sequence.hpp\"\
    \nusing namespace std;\n\nnamespace rng {\n\ntemplate<typename T>\nvoid shuffle(vector<T>\
    \ &v) {\n    std::shuffle(v.begin(), v.end(), eng);\n}\n\ntemplate<integral T>\n\
    inline vector<T> random_sequence(int n, T lo, T hi) {\n    assert(n >= 0);\n \
    \   vector<T> res(n);\n    for (int i = 0; i < n; i++) res[i] = randint(lo, hi);\n\
    \    return res;\n}\n\ntemplate<integral T>\ninline vector<T> random_increasing_sequence(int\
    \ n, T lo, T hi, bool strict = false) {\n    assert(n >= 0);\n    if (n == 0)\
    \ return {};\n    assert(lo + (n - 1) * strict <= hi);\n    vector<T> res = random_sequence(n,\
    \ lo, hi - (n - 1) * strict);\n    sort(res.begin(), res.end());\n    for (int\
    \ i = 0; i < n; i++) res[i] += i * strict;\n    return res;\n}\n\ntemplate<integral\
    \ T>\ninline vector<T> random_decreasing_sequence(int n, T lo, T hi, bool strict\
    \ = false) {\n    vector<T> res = random_increasing_sequence(n, lo, hi, strict);\n\
    \    reverse(res.begin(), res.end());\n    return res;\n}\n\ntemplate<integral\
    \ T = int>\ninline vector<T> random_permutation(int n, T v = 0) {\n    vector<T>\
    \ res(n);\n    iota(res.begin(), res.end(), v);\n    shuffle(res);\n    return\
    \ res;\n}\n\ninline string random_string(int n, char a, char z) {\n    assert(a\
    \ <= z);\n    string s(n, a);\n    for (auto &c : s) c = randint((int)a, (int)z);\n\
    \    return s;\n}\n\n} // namespace rng\n#line 3 \"src/data_structure/set/median_set.hpp\"\
    \n#include <set>\nusing namespace std;\n\ntemplate<typename T1, typename T2 =\
    \ long long>\nstruct median_set {\n    median_set() : upper_sum(0), lower_sum(0)\
    \ {}\n    void insert(T1 x) {\n        if (lower.empty() || x <= *prev(lower.end()))\
    \ {\n            lower_sum += x;\n            lower.insert(x);\n        } else\
    \ {\n            upper_sum += x;\n            upper.insert(x);\n        }\n  \
    \      normalize();\n    }\n    void erase(T1 x) {\n        auto it = lower.find(x);\n\
    \        if (it != lower.end()) {\n            lower_sum -= *it;\n           \
    \ lower.erase(it);\n        } else {\n            it = upper.find(x);\n      \
    \      assert(it != upper.end());\n            upper_sum -= *it;\n           \
    \ upper.erase(it);\n        }\n        normalize();\n    }\n    T1 median() const\
    \ {\n        assert(lower.size());\n        return *prev(lower.end());\n    }\n\
    \    T2 min_cost() const {\n        T2 med = median();\n        return (upper_sum\
    \ - med * upper.size()) + (med * lower.size() - lower_sum);\n    }\nprivate:\n\
    \    multiset<T1> upper, lower;\n    T2 upper_sum, lower_sum;\n    void normalize()\
    \ {\n        while (lower.size() > upper.size() + 1) {\n            auto it =\
    \ prev(lower.end());\n            upper_sum += *it;\n            upper.insert(*it);\n\
    \            lower_sum -= *it;\n            lower.erase(it);\n        }\n    \
    \    while (lower.size() < upper.size()) {\n            auto it = upper.begin();\n\
    \            lower_sum += *it;\n            lower.insert(*it);\n            upper_sum\
    \ -= *it;\n            upper.erase(it);\n        }\n    }\n};\n#line 5 \"test/data_structure/set/median_set.test.cpp\"\
    \n\n#include <bits/stdc++.h>\n\nnamespace AC {\n\n// https://atcoder.jp/contests/abc127/submissions/80286090\n\
    \nusing namespace std;\n\n// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8\n\
    \ntemplate<typename T>\nstruct slope_trick {\n    slope_trick() : min_val(0),\
    \ left_add(0), right_add(0) {\n        left.push(-inf);\n        right.push(inf);\n\
    \    }\n    T get_min() const { return min_val; }\n    pair<T, T> min_range()\
    \ const { return make_pair(left_top(), right_top()); }\n    // f(x) += a\n   \
    \ void add_all(T a) { min_val += a; }\n    // f(x) += max(0, x - a)\n    void\
    \ add_x_minus_a(T a) {\n        min_val += max<T>(0, left_top() - a);\n      \
    \  left_push(a);\n        right_push(left_pop());\n    }\n    // f(x) += max(0,\
    \ a - x)\n    void add_a_minus_x(T a) {\n        min_val += max<T>(0, a - right_top());\n\
    \        right_push(a);\n        left_push(right_pop());\n    }\n    // f(x) +=\
    \ |x - a|\n    void add_abs_x_minus_a(T a) {\n        add_x_minus_a(a);\n    \
    \    add_a_minus_x(a);\n    }\n    // f_new(x) = f(x - c)\n    void shift(T c)\
    \ {\n        left_add += c;\n        right_add += c;\n    }\n    // f_new(x) =\
    \ min_{y in [x-l, x-r]} f_cur(y)\n    void slide_window_min(T l, T r) {\n    \
    \    assert(l >= r);\n        left_add += r;\n        right_add += l;\n    }\n\
    private:\n    static constexpr T inf = numeric_limits<T>::max() / 3;\n    T min_val,\
    \ left_add, right_add;\n    priority_queue<T, vector<T>, less<T>> left;\n    priority_queue<T,\
    \ vector<T>, greater<T>> right;\n    T left_top() const {\n        assert(left.size());\n\
    \        return left.top() + left_add;\n    }\n    T right_top() const {\n   \
    \     assert(right.size());\n        return right.top() + right_add;\n    }\n\
    \    T left_pop() {\n        T res = left_top();\n        left.pop();\n      \
    \  return res;\n    }\n    T right_pop() {\n        T res = right_top();\n   \
    \     right.pop();\n        return res;\n    }\n    void left_push(T a) { left.push(a\
    \ - left_add); }\n    void right_push(T a) { right.push(a - right_add); }\n};\n\
    \nvector<pair<long long, long long>> solve(vector<int> T, vector<int> A, vector<int>\
    \ B) {\n    int Q = T.size();\n    slope_trick<long long> ST;\n    vector<pair<long\
    \ long, long long>> res;\n    for (int i = 0; i < Q; i++) {\n        if (T[i]\
    \ == 1) {\n            ST.add_abs_x_minus_a(A[i]);\n            ST.add_all(B[i]);\n\
    \        } else {\n            res.emplace_back(ST.min_range().first, ST.get_min());\n\
    \        }\n    }\n    return res;\n}\n\n} // namespace AC\n\nvector<pair<long\
    \ long, long long>> median_set_test(vector<int> T, vector<int> A, vector<int>\
    \ B) {\n    median_set<long long> S;\n    long long add = 0;\n    vector<pair<long\
    \ long, long long>> res;\n    for (int i = 0; i < (int)T.size(); i++) {\n    \
    \    if (T[i] == 1) {\n            S.insert(A[i]);\n            add += B[i];\n\
    \        } else {\n            res.emplace_back(S.median(), S.min_cost() + add);\n\
    \        }\n    }\n    return res;\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    {\n        int A, B;\n        cin >> A >> B;\n   \
    \     cout << A + B << '\\n';\n    }\n    for (int t = 0; t < 10; t++) {\n   \
    \     int Q = rng::randint<int>(1e5, 2e5);\n        auto T = rng::random_sequence<int>(Q,\
    \ 1, 2);\n        T[0] = 1;\n        auto A = rng::random_sequence<int>(Q, -1e9,\
    \ 1e9);\n        auto B = rng::random_sequence<int>(Q, -1e9, 1e9);\n        assert(AC::solve(T,\
    \ A, B) == median_set_test(T, A, B));\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../src/random/sequence.hpp\"\n#include \"../../../src/data_structure/set/median_set.hpp\"\
    \n\n#include <bits/stdc++.h>\n\nnamespace AC {\n\n// https://atcoder.jp/contests/abc127/submissions/80286090\n\
    \nusing namespace std;\n\n// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8\n\
    \ntemplate<typename T>\nstruct slope_trick {\n    slope_trick() : min_val(0),\
    \ left_add(0), right_add(0) {\n        left.push(-inf);\n        right.push(inf);\n\
    \    }\n    T get_min() const { return min_val; }\n    pair<T, T> min_range()\
    \ const { return make_pair(left_top(), right_top()); }\n    // f(x) += a\n   \
    \ void add_all(T a) { min_val += a; }\n    // f(x) += max(0, x - a)\n    void\
    \ add_x_minus_a(T a) {\n        min_val += max<T>(0, left_top() - a);\n      \
    \  left_push(a);\n        right_push(left_pop());\n    }\n    // f(x) += max(0,\
    \ a - x)\n    void add_a_minus_x(T a) {\n        min_val += max<T>(0, a - right_top());\n\
    \        right_push(a);\n        left_push(right_pop());\n    }\n    // f(x) +=\
    \ |x - a|\n    void add_abs_x_minus_a(T a) {\n        add_x_minus_a(a);\n    \
    \    add_a_minus_x(a);\n    }\n    // f_new(x) = f(x - c)\n    void shift(T c)\
    \ {\n        left_add += c;\n        right_add += c;\n    }\n    // f_new(x) =\
    \ min_{y in [x-l, x-r]} f_cur(y)\n    void slide_window_min(T l, T r) {\n    \
    \    assert(l >= r);\n        left_add += r;\n        right_add += l;\n    }\n\
    private:\n    static constexpr T inf = numeric_limits<T>::max() / 3;\n    T min_val,\
    \ left_add, right_add;\n    priority_queue<T, vector<T>, less<T>> left;\n    priority_queue<T,\
    \ vector<T>, greater<T>> right;\n    T left_top() const {\n        assert(left.size());\n\
    \        return left.top() + left_add;\n    }\n    T right_top() const {\n   \
    \     assert(right.size());\n        return right.top() + right_add;\n    }\n\
    \    T left_pop() {\n        T res = left_top();\n        left.pop();\n      \
    \  return res;\n    }\n    T right_pop() {\n        T res = right_top();\n   \
    \     right.pop();\n        return res;\n    }\n    void left_push(T a) { left.push(a\
    \ - left_add); }\n    void right_push(T a) { right.push(a - right_add); }\n};\n\
    \nvector<pair<long long, long long>> solve(vector<int> T, vector<int> A, vector<int>\
    \ B) {\n    int Q = T.size();\n    slope_trick<long long> ST;\n    vector<pair<long\
    \ long, long long>> res;\n    for (int i = 0; i < Q; i++) {\n        if (T[i]\
    \ == 1) {\n            ST.add_abs_x_minus_a(A[i]);\n            ST.add_all(B[i]);\n\
    \        } else {\n            res.emplace_back(ST.min_range().first, ST.get_min());\n\
    \        }\n    }\n    return res;\n}\n\n} // namespace AC\n\nvector<pair<long\
    \ long, long long>> median_set_test(vector<int> T, vector<int> A, vector<int>\
    \ B) {\n    median_set<long long> S;\n    long long add = 0;\n    vector<pair<long\
    \ long, long long>> res;\n    for (int i = 0; i < (int)T.size(); i++) {\n    \
    \    if (T[i] == 1) {\n            S.insert(A[i]);\n            add += B[i];\n\
    \        } else {\n            res.emplace_back(S.median(), S.min_cost() + add);\n\
    \        }\n    }\n    return res;\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    {\n        int A, B;\n        cin >> A >> B;\n   \
    \     cout << A + B << '\\n';\n    }\n    for (int t = 0; t < 10; t++) {\n   \
    \     int Q = rng::randint<int>(1e5, 2e5);\n        auto T = rng::random_sequence<int>(Q,\
    \ 1, 2);\n        T[0] = 1;\n        auto A = rng::random_sequence<int>(Q, -1e9,\
    \ 1e9);\n        auto B = rng::random_sequence<int>(Q, -1e9, 1e9);\n        assert(AC::solve(T,\
    \ A, B) == median_set_test(T, A, B));\n    }\n}"
  dependsOn:
  - src/random/sequence.hpp
  - src/random/utility.hpp
  - src/data_structure/set/median_set.hpp
  isVerificationFile: true
  path: test/data_structure/set/median_set.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 11:13:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/set/median_set.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/set/median_set.test.cpp
- /verify/test/data_structure/set/median_set.test.cpp.html
title: test/data_structure/set/median_set.test.cpp
---
