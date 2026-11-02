---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/graph/weighted_functional_graph.hpp
    title: Weighted Functional Graph
  - icon: ':question:'
    path: src/misc/compress.hpp
    title: Compress
  - icon: ':question:'
    path: src/misc/merge_and_unique.hpp
    title: Merge And Unique
  - icon: ':x:'
    path: src/monoid/max.hpp
    title: src/monoid/max.hpp
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/2242
    links:
    - https://yukicoder.me/problems/no/2242
  bundledCode: "#line 1 \"test/graph/weighted_functional_graph.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/2242\"\n\n#line 2 \"src/template.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\n\
    template<typename T>\nconstexpr T inf() { return numeric_limits<T>::max() / 2;\
    \ }\n\ntemplate<typename T1, typename T2>\nbool chmin(T1 &a, T2 b) { return a\
    \ > b ? a = b, true : false; }\ntemplate<typename T1, typename T2>\nbool chmax(T1\
    \ &a, T2 b) { return a < b ? a = b, true : false; }\n#line 3 \"src/graph/weighted_functional_graph.hpp\"\
    \n\ntemplate<typename Monoid, bool edge>\nstruct weighted_functional_graph {\n\
    \    using M = Monoid;\n    using S = typename Monoid::S;\n    weighted_functional_graph(int\
    \ _n) : n(_n), f(1, vector<int>(_n, -1)), d(1, vector<S>(_n, M::e())) {}\n   \
    \ void add_edge(int u, int v, const S &x = M::e()) {\n        assert(0 <= u &&\
    \ u < n);\n        assert(0 <= v && v < n);\n        assert(f[0][u] == -1);\n\
    \        f[0][u] = v;\n        d[0][u] = x;\n    }\n    void set_weight(int u,\
    \ const S &x) {\n        assert(0 <= u && u < n);\n        assert(!edge);\n  \
    \      d[0][u] = x;\n    }\n    pair<int, S> steps(int u, long long k) {\n   \
    \     assert(0 <= u && u < n);\n        assert(k >= 0);\n        doubling(k);\n\
    \        S x = edge ? M::e() : d[0][u];\n        for (int i = 0; k >> i; i++)\
    \ {\n            if (k >> i & 1) {\n                int from = edge ? u : f[0][u];\n\
    \                x = M::op(x, d[i][from]);\n                u = f[i][u];\n   \
    \         }\n        }\n        return {u, x};\n    }\n    pair<vector<int>, vector<S>>\
    \ table(long long k) {\n        assert(k >= 0);\n        doubling(k);\n      \
    \  vector<int> g(n);\n        vector<S> w(n, M::e());\n        iota(g.begin(),\
    \ g.end(), 0);\n        if constexpr (!edge) w = d[0];\n        for (int i = 0;\
    \ k >> i; i++) {\n            if (k >> i & 1) {\n                for (int j =\
    \ 0; j < n; j++) {\n                    int from = edge ? g[j] : f[0][g[j]];\n\
    \                    w[j] = M::op(w[j], d[i][from]);\n                    g[j]\
    \ = f[i][g[j]];\n                }\n            }\n        }\n        return {g,\
    \ w};\n    }\n    template<typename C>\n    pair<long long, pair<int, S>> binary_search(int\
    \ u, long long k, const C &check) {\n        assert(0 <= u && u < n);\n      \
    \  assert(k >= 0);\n        S x = edge ? M::e() : d[0][u];\n        assert(check(x));\n\
    \        doubling(k);\n        int log = 0;\n        while (k >> log) log++;\n\
    \        long long r = 0;\n        for (log--; log >= 0; log--) {\n          \
    \  long long len = 1LL << log;\n            if (r > k - len) continue;\n     \
    \       int from = edge ? u : f[0][u];\n            S y = M::op(x, d[log][from]);\n\
    \            int v = f[log][u];\n            if (check(y)) {\n               \
    \ x = y;\n                u = v;\n                r += len;\n            }\n \
    \       }\n        return {r, {u, x}};\n    }\nprivate:\n    int n;\n    vector<vector<int>>\
    \ f;\n    vector<vector<S>> d;\n    void doubling(long long k) {\n        while\
    \ (k >> int(f.size())) {\n            vector<int> tf(n);\n            vector<S>\
    \ td(n, M::e());\n            const vector<int> &g = f.back();\n            const\
    \ vector<S> &h = d.back();\n            for (int i = 0; i < n; i++) tf[i] = g[g[i]],\
    \ td[i] = M::op(h[i], h[g[i]]);\n            f.push_back(tf);\n            d.push_back(td);\n\
    \        }\n    }\n};\n#line 3 \"src/misc/merge_and_unique.hpp\"\n\ntemplate<typename\
    \ T, typename... Ts>\nvector<T> merge_and_unique(const vector<T> &a, const Ts\
    \ &...z) {\n    vector<T> res = a;\n    (res.insert(res.end(), z.begin(), z.end()),\
    \ ...);\n    sort(res.begin(), res.end());\n    res.erase(unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 4 \"src/misc/compress.hpp\"\
    \n\ntemplate<typename T>\nvector<int> compress(const vector<T> &v) {\n    auto\
    \ zip = merge_and_unique(v);\n    vector<int> res;\n    res.reserve(v.size());\n\
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
    \  return (int)zip.size();\n}\n#line 3 \"src/monoid/max.hpp\"\n\ntemplate<typename\
    \ T, T E = (is_signed_v<T> ? -inf<T>() : T(0))>\nstruct max_monoid {\n    using\
    \ S = T;\n    static S op(S a, S b) { return max(a, b); }\n    static S e() {\
    \ return E; }\n};\n#line 7 \"test/graph/weighted_functional_graph.test.cpp\"\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    vector<int> H(N), T(N);\n    for (auto &e : H) cin >>\
    \ e;\n    for (auto &e : T) cin >> e;\n    int M = compress_inplace(H, T);\n \
    \   vector<int> to(M);\n    iota(to.begin(), to.end(), 0);\n    for (int i = 0;\
    \ i < N; i++) to[H[i]] = max(to[H[i]], T[i]);\n    for (int i = 1; i < M; i++)\
    \ to[i] = max(to[i], to[i - 1]);\n    weighted_functional_graph<max_monoid<int>,\
    \ true> E(M);\n    weighted_functional_graph<max_monoid<int>, false> V(M);\n \
    \   for (int i = 0; i < M; i++) {\n        E.add_edge(i, to[i], to[i]);\n    \
    \    V.add_edge(i, to[i]);\n        V.set_weight(i, i);\n    }\n    int Q;\n \
    \   cin >> Q;\n    for (int a, b; Q--; ) {\n        cin >> a >> b;\n        a--,\
    \ b--;\n        if (H[b] <= T[a]) {\n            cout << 1 << '\\n';\n       \
    \ } else {\n            auto check = [&] (int x) { return x < H[b]; };\n     \
    \       long long r = E.binary_search(T[a], M, check).first;\n            long\
    \ long s = V.binary_search(T[a], M, check).first;\n            assert(r == s);\n\
    \            cout << (r == M ? -1 : r + 2) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/2242\"\n\n#include \"\
    ../../src/template.hpp\"\n#include \"../../src/graph/weighted_functional_graph.hpp\"\
    \n#include \"../../src/misc/compress.hpp\"\n#include \"../../src/monoid/max.hpp\"\
    \n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n  \
    \  int N;\n    cin >> N;\n    vector<int> H(N), T(N);\n    for (auto &e : H) cin\
    \ >> e;\n    for (auto &e : T) cin >> e;\n    int M = compress_inplace(H, T);\n\
    \    vector<int> to(M);\n    iota(to.begin(), to.end(), 0);\n    for (int i =\
    \ 0; i < N; i++) to[H[i]] = max(to[H[i]], T[i]);\n    for (int i = 1; i < M; i++)\
    \ to[i] = max(to[i], to[i - 1]);\n    weighted_functional_graph<max_monoid<int>,\
    \ true> E(M);\n    weighted_functional_graph<max_monoid<int>, false> V(M);\n \
    \   for (int i = 0; i < M; i++) {\n        E.add_edge(i, to[i], to[i]);\n    \
    \    V.add_edge(i, to[i]);\n        V.set_weight(i, i);\n    }\n    int Q;\n \
    \   cin >> Q;\n    for (int a, b; Q--; ) {\n        cin >> a >> b;\n        a--,\
    \ b--;\n        if (H[b] <= T[a]) {\n            cout << 1 << '\\n';\n       \
    \ } else {\n            auto check = [&] (int x) { return x < H[b]; };\n     \
    \       long long r = E.binary_search(T[a], M, check).first;\n            long\
    \ long s = V.binary_search(T[a], M, check).first;\n            assert(r == s);\n\
    \            cout << (r == M ? -1 : r + 2) << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - src/template.hpp
  - src/graph/weighted_functional_graph.hpp
  - src/misc/compress.hpp
  - src/misc/merge_and_unique.hpp
  - src/monoid/max.hpp
  isVerificationFile: true
  path: test/graph/weighted_functional_graph.test.cpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/graph/weighted_functional_graph.test.cpp
layout: document
redirect_from:
- /verify/test/graph/weighted_functional_graph.test.cpp
- /verify/test/graph/weighted_functional_graph.test.cpp.html
title: test/graph/weighted_functional_graph.test.cpp
---
