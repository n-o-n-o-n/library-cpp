---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/misc/compress.hpp
    title: Compress
  - icon: ':heavy_check_mark:'
    path: src/misc/merge_and_unique.hpp
    title: Merge And Unique
  - icon: ':heavy_check_mark:'
    path: src/misc/mo.hpp
    title: Mo
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_count_distinct
    links:
    - https://judge.yosupo.jp/problem/static_range_count_distinct
  bundledCode: "#line 1 \"test/misc/mo_static_range_count_distinct.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_count_distinct\"\n\n\
    #line 2 \"src/misc/compress.hpp\"\n#include <algorithm>\n#include <vector>\n#line\
    \ 4 \"src/misc/merge_and_unique.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ T, typename... Ts>\nvector<T> merge_and_unique(const vector<T> &a, const Ts\
    \ &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(), z.begin(), z.end()),\
    \ ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 5 \"src/misc/compress.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T>\nvector<int> compress(const vector<T>\
    \ &v) {\n    auto zip = merge_and_unique(v);\n    vector<int> res;\n    res.reserve(v.size());\n\
    \    for (const T &e : v) {\n        res.push_back(lower_bound(zip.begin(), zip.end(),\
    \ e) - zip.begin());\n    }\n    return res;\n}\n\ntemplate<typename T, typename...\
    \ Ts>\nauto compress(const vector<T> &a, const Ts &...z) {\n    auto zip = merge_and_unique(a,\
    \ z...);\n    auto f = [&] (const vector<T> &v) -> vector<int> {\n        vector<int>\
    \ res;\n        res.reserve(v.size());\n        for (const T &e : v) {\n     \
    \       res.push_back(lower_bound(zip.begin(), zip.end(), e) - zip.begin());\n\
    \        }\n        return res;\n    };\n    return make_tuple(f(a), f(z)...);\n\
    }\n\ntemplate<typename T, typename... Ts>\nint compress_inplace(vector<T> &a,\
    \ Ts &...z) {\n    auto zip = merge_and_unique(a, z...);\n    auto f = [&] (vector<T>\
    \ &v) -> void {\n        for (T &e : v) {\n            e = lower_bound(zip.begin(),\
    \ zip.end(), e) - zip.begin();\n        }\n    };\n    (f(a), ..., f(z));\n  \
    \  return (int)zip.size();\n}\n#line 3 \"src/misc/mo.hpp\"\n#include <cmath>\n\
    #include <numeric>\n#line 6 \"src/misc/mo.hpp\"\nusing namespace std;\n\nstruct\
    \ MO {\n    MO(int _n, int _q = 0) : n(_n), q(_q) { querys.reserve(q); }\n   \
    \ void add_query(int l, int r) { querys.emplace_back(l, r); }\n    template<typename\
    \ EXL, typename EXR, typename SHL, typename SHR, typename O>\n    void run(const\
    \ EXL &exl, const EXR &exr, const SHL &shl, const SHR &shr, const O &out) {\n\
    \        q = querys.size();\n        const int b = clamp(int(sqrtl(q * 0.66)),\
    \ 1, max(1, n));\n        vector<int> ord(q);\n        iota(ord.begin(), ord.end(),\
    \ 0);\n        sort(ord.begin(), ord.end(), [&](int i, int j) {\n            auto\
    \ [li, ri] = querys[i];\n            auto [lj, rj] = querys[j];\n            int\
    \ bi = li / b, bj = lj / b;\n            return bi == bj ? bi & 1 ? ri > rj :\
    \ ri < rj : bi < bj;\n        });\n        int l = 0, r = 0;\n        for (int\
    \ i : ord) {\n            auto [li, ri] = querys[i];\n            while (l > li)\
    \ exl(--l);\n            while (r < ri) exr(r++);\n            while (l < li)\
    \ shl(l++);\n            while (r > ri) shr(--r);\n            out(i);\n     \
    \   }\n    }\n    template<typename EX, typename SH, typename O>\n    void run(const\
    \ EX &ex, const SH &sh, const O &out) {\n        run(ex, ex, sh, sh, out);\n \
    \   }\nprivate:\n    int n, q;\n    vector<pair<int, int>> querys;\n};\n#line\
    \ 5 \"test/misc/mo_static_range_count_distinct.test.cpp\"\n\n#include <iostream>\n\
    using namespace std;\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    for (auto &e :\
    \ A) cin >> e;\n    MO mo(N, Q);\n    for (int i = 0, l, r; i < Q; i++) {\n  \
    \      cin >> l >> r;\n        mo.add_query(l, r);\n    }\n    vector<int> cnt(compress_inplace(A));\n\
    \    int cur = 0;\n    vector<int> ans(Q);\n    auto ex = [&] (int i) -> void\
    \ { cur += cnt[A[i]]++ == 0; };\n    auto sh = [&] (int i) -> void { cur -= --cnt[A[i]]\
    \ == 0; };\n    auto out = [&] (int i) -> void { ans[i] = cur; };\n    mo.run(ex,\
    \ sh, out);\n    for (auto e : ans) cout << e << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_count_distinct\"\
    \n\n#include \"../../src/misc/compress.hpp\"\n#include \"../../src/misc/mo.hpp\"\
    \n\n#include <iostream>\nusing namespace std;\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n\
    \    for (auto &e : A) cin >> e;\n    MO mo(N, Q);\n    for (int i = 0, l, r;\
    \ i < Q; i++) {\n        cin >> l >> r;\n        mo.add_query(l, r);\n    }\n\
    \    vector<int> cnt(compress_inplace(A));\n    int cur = 0;\n    vector<int>\
    \ ans(Q);\n    auto ex = [&] (int i) -> void { cur += cnt[A[i]]++ == 0; };\n \
    \   auto sh = [&] (int i) -> void { cur -= --cnt[A[i]] == 0; };\n    auto out\
    \ = [&] (int i) -> void { ans[i] = cur; };\n    mo.run(ex, sh, out);\n    for\
    \ (auto e : ans) cout << e << '\\n';\n}"
  dependsOn:
  - src/misc/compress.hpp
  - src/misc/merge_and_unique.hpp
  - src/misc/mo.hpp
  isVerificationFile: true
  path: test/misc/mo_static_range_count_distinct.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 22:15:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/misc/mo_static_range_count_distinct.test.cpp
layout: document
redirect_from:
- /verify/test/misc/mo_static_range_count_distinct.test.cpp
- /verify/test/misc/mo_static_range_count_distinct.test.cpp.html
title: test/misc/mo_static_range_count_distinct.test.cpp
---
