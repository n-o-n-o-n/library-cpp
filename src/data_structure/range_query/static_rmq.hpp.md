---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/sparse_table.hpp
    title: src/data_structure/range_query/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: src/monoid/min.hpp
    title: src/monoid/min.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/tree/static_tree.hpp
    title: Static Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/tree/static_tree.jump.test.cpp
    title: test/tree/static_tree.jump.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/tree/static_tree.lca.test.cpp
    title: test/tree/static_tree.lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/range_query/static_rmq.hpp\"\n#include\
    \ <cassert>\n#include <limits>\n#include <type_traits>\n#include <vector>\n#line\
    \ 2 \"src/data_structure/range_query/sparse_table.hpp\"\n#include <bit>\n#line\
    \ 5 \"src/data_structure/range_query/sparse_table.hpp\"\nusing namespace std;\n\
    \ntemplate<typename Monoid>\nstruct sparse_table {\n    using M = Monoid;\n  \
    \  using S = typename M::S;\n    sparse_table() = default;\n    sparse_table(const\
    \ vector<S> &v) : n(v.size()), b(0), d(1, v) { build(); }\n    S prod(int l, int\
    \ r) const {\n        assert(0 <= l && l <= r && r <=n);\n        if (l == r)\
    \ return M::e();\n        int i = bit_width(unsigned(r - l)) - 1;\n        return\
    \ M::op(d[i][l], d[i][r - (1 << i)]);\n    }\nprivate:\n    int n, b, e;\n   \
    \ vector<vector<S>> d;\n    void build() {\n        b = bit_width(unsigned(n));\n\
    \        d.resize(b);\n        for (int i = 1; i < b; i++) {\n            int\
    \ width = 1 << i;\n            d[i].assign(n - width + 1, M::e());\n         \
    \   for (int j = 0; j + width <= n; j++) {\n                d[i][j] = M::op(d[i\
    \ - 1][j], d[i - 1][j + (width >> 1)]);\n            }\n        }\n    }\n};\n\
    #line 2 \"src/monoid/min.hpp\"\n#include <algorithm>\n#line 4 \"src/monoid/min.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T, T E = numeric_limits<T>::max()>\n\
    struct min_monoid {\n    using S = T;\n    static S op(S a, S b) { return min(a,\
    \ b); }\n    static S e() { return E; }\n};\n#line 8 \"src/data_structure/range_query/static_rmq.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T, T inf = numeric_limits<T>::max()>\n\
    struct static_rmq {\n    static_assert(is_integral_v<T>);\n    static_rmq() =\
    \ default;\n    static_rmq(const vector<T> &_v) : n(_v.size()), v(_v), pref(n),\
    \ suff(n) { build(); }\n    T prod(int l, int r) const {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        if (l == r) return inf;\n        r--;\n   \
    \     int bl = l >> log, br = r >> log;\n        if (bl < br) {\n            if\
    \ (bl + 1 == br) return min(pref[r], suff[l]);\n            return min(min(pref[r],\
    \ suff[l]), st.prod(bl + 1, br));\n        }\n        T res = v[l];\n        for\
    \ (int i = l + 1; i <= r; i++) res = min(res, v[i]);\n        return res;\n  \
    \  }\nprivate:\n    int n;\n    static constexpr int log = 4, mask = 15;\n   \
    \ vector<T> v, pref, suff;\n    sparse_table<min_monoid<T, inf>> st;\n    void\
    \ build() {\n        if (n == 0) return;\n        pref[0] = v[0];\n        suff[n\
    \ - 1] = v[n - 1];\n        for (int i = 1; i < n; i++) {\n            pref[i]\
    \ = i & mask ? min(pref[i - 1], v[i]) : v[i];\n        }\n        for (int i =\
    \ n - 2; i >= 0; i--) {\n            suff[i] = (i & mask) == mask ? v[i] : min(v[i],\
    \ suff[i + 1]);\n        }\n        st = sparse_table<min_monoid<T, inf>>([&]\
    \ {\n            vector<T> a(n >> log);\n            for (int i = 0; i < (n >>\
    \ log); i++) {\n                a[i] = suff[i << log];\n            }\n      \
    \      return move(a);\n        } ());\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <type_traits>\n\
    #include <vector>\n#include \"sparse_table.hpp\"\n#include \"../../monoid/min.hpp\"\
    \nusing namespace std;\n\ntemplate<typename T, T inf = numeric_limits<T>::max()>\n\
    struct static_rmq {\n    static_assert(is_integral_v<T>);\n    static_rmq() =\
    \ default;\n    static_rmq(const vector<T> &_v) : n(_v.size()), v(_v), pref(n),\
    \ suff(n) { build(); }\n    T prod(int l, int r) const {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        if (l == r) return inf;\n        r--;\n   \
    \     int bl = l >> log, br = r >> log;\n        if (bl < br) {\n            if\
    \ (bl + 1 == br) return min(pref[r], suff[l]);\n            return min(min(pref[r],\
    \ suff[l]), st.prod(bl + 1, br));\n        }\n        T res = v[l];\n        for\
    \ (int i = l + 1; i <= r; i++) res = min(res, v[i]);\n        return res;\n  \
    \  }\nprivate:\n    int n;\n    static constexpr int log = 4, mask = 15;\n   \
    \ vector<T> v, pref, suff;\n    sparse_table<min_monoid<T, inf>> st;\n    void\
    \ build() {\n        if (n == 0) return;\n        pref[0] = v[0];\n        suff[n\
    \ - 1] = v[n - 1];\n        for (int i = 1; i < n; i++) {\n            pref[i]\
    \ = i & mask ? min(pref[i - 1], v[i]) : v[i];\n        }\n        for (int i =\
    \ n - 2; i >= 0; i--) {\n            suff[i] = (i & mask) == mask ? v[i] : min(v[i],\
    \ suff[i + 1]);\n        }\n        st = sparse_table<min_monoid<T, inf>>([&]\
    \ {\n            vector<T> a(n >> log);\n            for (int i = 0; i < (n >>\
    \ log); i++) {\n                a[i] = suff[i << log];\n            }\n      \
    \      return move(a);\n        } ());\n    }\n};"
  dependsOn:
  - src/data_structure/range_query/sparse_table.hpp
  - src/monoid/min.hpp
  isVerificationFile: false
  path: src/data_structure/range_query/static_rmq.hpp
  requiredBy:
  - src/tree/static_tree.hpp
  timestamp: '2026-10-31 13:28:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/tree/static_tree.lca.test.cpp
  - test/tree/static_tree.jump.test.cpp
documentation_of: src/data_structure/range_query/static_rmq.hpp
layout: document
redirect_from:
- /library/src/data_structure/range_query/static_rmq.hpp
- /library/src/data_structure/range_query/static_rmq.hpp.html
title: src/data_structure/range_query/static_rmq.hpp
---
