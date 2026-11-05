---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/cht/monotone_cht.hpp
    title: Monotone Convex Hull Trick
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/703
    links:
    - https://yukicoder.me/problems/no/703
  bundledCode: "#line 1 \"test/data_structure/cht/monotone_cht.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/703\"\n\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    template<typename T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2;\
    \ }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a\
    \ > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/data_structure/cht/monotone_cht.hpp\"\
    \n\ntemplate<typename T, bool query_dec = false>\nstruct monotone_cht {\n    using\
    \ W = conditional_t<sizeof(T) <= 4, long long, __int128_t>;\n    monotone_cht()\
    \ = default;\n    void add_line(T a, T b) {\n        line l(a, b);\n        if\
    \ (q.empty()) {\n            pa = a;\n            q.push_back(l);\n          \
    \  return;\n        }\n        if (!dir && a != pa) dir = a > pa ? 1 : -1;\n \
    \       if (q[q.size() - 1].a == a) {\n            if (q[q.size() - 1].b <= b)\
    \ return;\n            q.pop_back();\n        }\n        while (q.size() >= 2\
    \ && check(\n            q[q.size() - 2],\n            q[q.size() - 1],\n    \
    \        l,\n            dir > 0\n        )) q.pop_back();\n        q.push_back(l);\n\
    \        pa = a;\n    }\n    T get(T x) {\n        if (q.empty()) return inf<T>();\n\
    \        if ((dir > 0) == query_dec) {\n            while (q.size() >= 2 && q[0].get(x)\
    \ > q[1].get(x)) q.pop_front();\n            return q[0].get(x);\n        } else\
    \ {\n            while (q.size() >= 2 && q[q.size() - 1].get(x) > q[q.size() -\
    \ 2].get(x)) q.pop_back();\n            return q[q.size() - 1].get(x);\n     \
    \   }\n    }\nprivate:\n    struct line {\n        T a, b;\n        line(T _a,\
    \ T _b) : a(_a), b(_b) {}\n        T get(T x) const { return a * x + b; }\n  \
    \  };\n    deque<line> q;\n    T pa;\n    int dir = 0;\n    static bool check(line\
    \ l1, line l2, line l3, bool f) {\n        W l = W(l2.b - l1.b) * (l3.a - l2.a);\n\
    \        W r = W(l3.b - l2.b) * (l2.a - l1.a);\n        return f ? l >= r : l\
    \ <= r;\n    }\n};\n#line 5 \"test/data_structure/cht/monotone_cht.test.cpp\"\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    vector<ll> A(N), X(N), Y(N);\n    for (auto &e : A) cin\
    \ >> e;\n    for (auto &e : X) cin >> e;\n    for (auto &e : Y) cin >> e;\n  \
    \  monotone_cht<ll> cht;\n    monotone_cht<ll, true> cht2;\n    ll ans = 0;\n\
    \    for (int i = 0; i < N; i++) {\n        cht.add_line(-2 * X[i], ans + X[i]\
    \ * X[i] + Y[i] * Y[i]);\n        cht2.add_line(2 * X[i], ans + X[i] * X[i] +\
    \ Y[i] * Y[i]);\n        ll v1 = cht.get(A[i]);\n        ll v2 = cht2.get(-A[i]);\n\
    \        assert(v1 == v2);\n        ans = v1 + A[i] * A[i];\n    }\n    cout <<\
    \ ans << endl;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/703\"\n\n#include \"../../../src/template.hpp\"\
    \n#include \"../../../src/data_structure/cht/monotone_cht.hpp\"\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N;\n   \
    \ cin >> N;\n    vector<ll> A(N), X(N), Y(N);\n    for (auto &e : A) cin >> e;\n\
    \    for (auto &e : X) cin >> e;\n    for (auto &e : Y) cin >> e;\n    monotone_cht<ll>\
    \ cht;\n    monotone_cht<ll, true> cht2;\n    ll ans = 0;\n    for (int i = 0;\
    \ i < N; i++) {\n        cht.add_line(-2 * X[i], ans + X[i] * X[i] + Y[i] * Y[i]);\n\
    \        cht2.add_line(2 * X[i], ans + X[i] * X[i] + Y[i] * Y[i]);\n        ll\
    \ v1 = cht.get(A[i]);\n        ll v2 = cht2.get(-A[i]);\n        assert(v1 ==\
    \ v2);\n        ans = v1 + A[i] * A[i];\n    }\n    cout << ans << endl;\n}"
  dependsOn:
  - src/template.hpp
  - src/data_structure/cht/monotone_cht.hpp
  isVerificationFile: true
  path: test/data_structure/cht/monotone_cht.test.cpp
  requiredBy: []
  timestamp: '2026-11-05 23:32:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/cht/monotone_cht.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/cht/monotone_cht.test.cpp
- /verify/test/data_structure/cht/monotone_cht.test.cpp.html
title: test/data_structure/cht/monotone_cht.test.cpp
---
