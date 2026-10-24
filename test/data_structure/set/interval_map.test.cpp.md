---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/set/interval_map.hpp
    title: Interval Map
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/data_structure/set/interval_map.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#line 2 \"src/data_structure/set/interval_map.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <iterator>\n#include <limits>\n#include <set>\n#include\
    \ <tuple>\n#include <utility>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ T, typename S>\nstruct interval_map {\n    interval_map(const S &_e = S()) :\
    \ e(_e) {}\n    template<typename A, typename D>\n    void update(T l, T r, const\
    \ S &x, const A &add, const D &del) {\n        if (l == r) return;\n        assert(l\
    \ < r);\n        auto cur = key(l);\n        if (cur != s.end() && cur->l <= l\
    \ && r <= cur->r && cur->x == x) return;\n        auto it = s.lower_bound(node(l,\
    \ l, e));\n        if (it != s.begin() && prev(it)->r > l) it = prev(it);\n  \
    \      while (it != s.end() && it->l < r) {\n            auto [a, b, y] = *it;\n\
    \            it = s.erase(it);\n            del(a, b, y);\n            if (a <\
    \ l) {\n                add(a, l, y);\n                s.emplace_hint(it, a, l,\
    \ y);\n            }\n            if (r < b) {\n                add(r, b, y);\n\
    \                s.emplace_hint(it, r, b, y);\n                break;\n      \
    \      }\n        }\n        it = s.lower_bound(node(l, l, e));\n        if (it\
    \ != s.begin()) {\n            auto pre = prev(it);\n            if (pre->r ==\
    \ l && pre->x == x) {\n                l = pre->l;\n                del(pre->l,\
    \ pre->r, pre->x);\n                it = s.erase(pre);\n            }\n      \
    \  }\n        if (it != s.end() && it->l == r && it->x == x) {\n            r\
    \ = it->r;\n            del(it->l, it->r, it->x);\n            it = s.erase(it);\n\
    \        }\n        add(l, r, x);\n        s.emplace_hint(it, l, r, x);\n    }\n\
    \    void update(T l, T r, const S &x) {\n        update(l, r, x, [] (T, T, S)\
    \ {}, [] (T, T, S) {});\n    }\n    template<typename A, typename D>\n    void\
    \ update(T k, const S &x, const A &add, const D &del) {\n        assert(k < inf);\n\
    \        update(k, k + 1, x, add, del);\n    }\n    void update(T k, const S &x)\
    \ {\n        assert(k < inf);\n        update(k, k + 1, x);\n    }\n    tuple<T,\
    \ T, S> get(T k) const {\n        assert(k < inf);\n        auto it = key(k);\n\
    \        return it != s.end() && k < it->r ? make_tuple(it->l, it->r, it->x) :\
    \ make_tuple(k, k + 1, e);\n    }\n    S operator[](T k) const {\n        auto\
    \ it = key(k);\n        return it != s.end() && k < it->r ? it->x : e;\n    }\n\
    \    tuple<T, T, S> mex(T k) const {\n        auto it = key(k);\n        if (it\
    \ == s.end()) it = s.begin();\n        else if (it->r <= k) ++it;\n        return\
    \ it == s.end() ? make_tuple(inf, inf, e) : make_tuple(it->l, it->r, it->x);\n\
    \    }\n    T next_element(T k) const {\n        auto it = key(k);\n        if\
    \ (it == s.end()) it = s.begin();\n        else if (k < it->r) return k;\n   \
    \     else ++it;\n        return it == s.end() ? low : it->l;\n    }\n    T prev_element(T\
    \ k) const {\n        auto it = key(k);\n        if (it == s.end()) return inf;\n\
    \        return k < it->r ? k : it->r - 1;\n    }\n    bool covered(T l, T r)\
    \ const {\n        if (l == r) return true;\n        assert(l < r);\n        auto\
    \ it = key(l);\n        if (it == s.end() || it->r <= l) return false;\n     \
    \   T pos = it->r;\n        while (pos < r) {\n            ++it;\n           \
    \ if (it == s.end() || it->l != pos) return false;\n            pos = it->r;\n\
    \        }\n        return true;\n    }\n    bool covered(T k) const {\n     \
    \   assert(k < inf);\n        auto it = key(k);\n        return it != s.end()\
    \ && k < it->r;\n    }\n    bool intersects(T l, T r) const {\n        if (l ==\
    \ r) return false;\n        assert(l < r);\n        auto it = key(l);\n      \
    \  if (it == s.end()) it = s.begin();\n        else if (it->r <= l) ++it;\n  \
    \      return it != s.end() && it->l < r;\n    }\n    bool empty() const {\n \
    \       return s.empty();\n    }\n    int size() const {\n        return s.size();\n\
    \    }\n    vector<tuple<T, T, S>> intervals(T l = low, T r = inf) const {\n \
    \       assert(l <= r);\n        vector<tuple<T, T, S>> res;\n        if (l ==\
    \ r) return res;\n        auto it = key(l);\n        if (it == s.end()) it = s.begin();\n\
    \        for (; it != s.end() && it->l < r; ++it) {\n            if (l < it->r)\
    \ res.emplace_back(max(l, it->l), min(r, it->r), it->x);\n        }\n        return\
    \ res;\n    }\n    void clear() {\n        s.clear();\n    }\nprivate:\n    static\
    \ constexpr T low = numeric_limits<T>::min();\n    static constexpr T inf = numeric_limits<T>::max();\n\
    \    struct node {\n        T l, r;\n        S x;\n        node(T _l, T _r, const\
    \ S &_x) : l(_l), r(_r), x(_x) {}\n        constexpr bool operator<(const node\
    \ &a) const {\n            return l == a.l ? r < a.r : l < a.l;\n        }\n \
    \   };\n    const S e;\n    set<node> s;\n    typename set<node>::const_iterator\
    \ key(T k) const {\n        auto it = s.upper_bound(node(k, inf, e));\n      \
    \  return it == s.begin() ? s.end() : prev(it);\n    }\n};\n#line 4 \"test/data_structure/set/interval_map.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    interval_map<int,\
    \ int> mp(numeric_limits<int>::max());\n    while (Q--) {\n        int t;\n  \
    \      cin >> t;\n        if (t == 0) {\n            int l, r, x;\n          \
    \  cin >> l >> r >> x;\n            r++;\n            mp.update(l, r, x);\n  \
    \      } else {\n            int p;\n            cin >> p;\n            cout <<\
    \ mp[p] << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include \"../../../src/data_structure/set/interval_map.hpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    interval_map<int, int> mp(numeric_limits<int>::max());\n\
    \    while (Q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n\
    \            int l, r, x;\n            cin >> l >> r >> x;\n            r++;\n\
    \            mp.update(l, r, x);\n        } else {\n            int p;\n     \
    \       cin >> p;\n            cout << mp[p] << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/data_structure/set/interval_map.hpp
  isVerificationFile: true
  path: test/data_structure/set/interval_map.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 11:13:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/set/interval_map.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/set/interval_map.test.cpp
- /verify/test/data_structure/set/interval_map.test.cpp.html
title: test/data_structure/set/interval_map.test.cpp
---
