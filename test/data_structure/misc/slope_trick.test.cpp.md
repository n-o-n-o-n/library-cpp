---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/misc/slope_trick.hpp
    title: Slope Trick
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1077
    links:
    - https://yukicoder.me/problems/no/1077
  bundledCode: "#line 1 \"test/data_structure/misc/slope_trick.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/1077\"\n\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    template<typename T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2;\
    \ }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a\
    \ > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/data_structure/misc/slope_trick.hpp\"\
    \n\n// https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8 \n\ntemplate<typename\
    \ T>\nstruct slope_trick {\n    slope_trick() : min_val(0), left_add(0), right_add(0)\
    \ {\n        left.push(-inf);\n        right.push(inf);\n    }\n    T get_min()\
    \ const { return min_val; }\n    pair<T, T> min_range() const { return make_pair(left_top(),\
    \ right_top()); }\n    // f(x) += a\n    void add_all(T a) { min_val += a; }\n\
    \    // f(x) += max(0, x - a)\n    void add_x_minus_a(T a) {\n        min_val\
    \ += max<T>(0, left_top() - a);\n        left_push(a);\n        right_push(left_pop());\n\
    \    }\n    // f(x) += max(0, a - x)\n    void add_a_minus_x(T a) {\n        min_val\
    \ += max<T>(0, a - right_top());\n        right_push(a);\n        left_push(right_pop());\n\
    \    }\n    // f(x) += |x - a|\n    void add_abs_x_minus_a(T a) {\n        add_x_minus_a(a);\n\
    \        add_a_minus_x(a);\n    }\n    // f_new(x) = f(x - c)\n    void shift(T\
    \ c) {\n        left_add += c;\n        right_add += c;\n    }\n    // f_new(x)\
    \ = min_{y in [x-l, x-r]} f_cur(y)\n    void slide_window_min(T l, T r) {\n  \
    \      assert(l >= r);\n        left_add += r;\n        right_add += l;\n    }\n\
    private:\n    static constexpr T inf = ::inf<T>();\n    T min_val, left_add, right_add;\n\
    \    priority_queue<T, vector<T>, less<T>> left;\n    priority_queue<T, vector<T>,\
    \ greater<T>> right;\n    T left_top() const {\n        assert(left.size());\n\
    \        return left.top() + left_add;\n    }\n    T right_top() const {\n   \
    \     assert(right.size());\n        return right.top() + right_add;\n    }\n\
    \    T left_pop() {\n        T res = left_top();\n        left.pop();\n      \
    \  return res;\n    }\n    T right_pop() {\n        T res = right_top();\n   \
    \     right.pop();\n        return res;\n    }\n    void left_push(T a) { left.push(a\
    \ - left_add); }\n    void right_push(T a) { right.push(a - right_add); }\n};\n\
    #line 5 \"test/data_structure/misc/slope_trick.test.cpp\"\n\nint main() {\n  \
    \  ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n    cin >>\
    \ N;\n    slope_trick<long long> st;\n    for (int i = 0; i < N; i++) {\n    \
    \    long long y;\n        cin >> y;\n        st.add_abs_x_minus_a(y);\n     \
    \   st.slide_window_min(10000, 0);\n    }\n    cout << st.get_min() << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1077\"\n\n#include \"\
    ../../../src/template.hpp\"\n#include \"../../../src/data_structure/misc/slope_trick.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N;\n    cin >> N;\n    slope_trick<long long> st;\n    for (int i = 0;\
    \ i < N; i++) {\n        long long y;\n        cin >> y;\n        st.add_abs_x_minus_a(y);\n\
    \        st.slide_window_min(10000, 0);\n    }\n    cout << st.get_min() << '\\\
    n';\n}\n"
  dependsOn:
  - src/template.hpp
  - src/data_structure/misc/slope_trick.hpp
  isVerificationFile: true
  path: test/data_structure/misc/slope_trick.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/misc/slope_trick.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/misc/slope_trick.test.cpp
- /verify/test/data_structure/misc/slope_trick.test.cpp.html
title: test/data_structure/misc/slope_trick.test.cpp
---
