---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/set/interval_set.hpp
    title: Interval Set
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/3017
    links:
    - https://yukicoder.me/problems/no/3017
  bundledCode: "#line 1 \"test/data_structure/set/interval_set.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/3017\"\n\n#line 2 \"src/data_structure/set/interval_set.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include <limits>\n\
    #include <set>\n#include <utility>\n#include <vector>\nusing namespace std;\n\n\
    template<typename T>\nstruct interval_set {\n    interval_set() = default;\n \
    \   template<typename A, typename D>\n    void insert(T l, T r, const A &add,\
    \ const D &del) {\n        if (l == r) return;\n        assert(l < r);\n     \
    \   auto cur = key(l);\n        if (cur != s.end() && cur->l <= l && r <= cur->r)\
    \ return;\n        auto it = s.lower_bound(node(l, l));\n        if (it != s.begin())\
    \ {\n            auto pre = prev(it);\n            if (l <= pre->r) {\n      \
    \          l = pre->l;\n                r = max(r, pre->r);\n                del(pre->l,\
    \ pre->r);\n                it = s.erase(pre);\n            }\n        }\n   \
    \     while (it != s.end() && it->l <= r) {\n            r = max(r, it->r);\n\
    \            del(it->l, it->r);\n            it = s.erase(it);\n        }\n  \
    \      add(l, r);\n        s.emplace_hint(it, l, r);\n    }\n    void insert(T\
    \ l, T r) {\n        insert(l, r, [] (T, T) {}, [] (T, T) {});\n    }\n    template<typename\
    \ A, typename D>\n    void insert(T k, const A &add, const D &del) {\n       \
    \ assert(k < inf);\n        insert(k, k + 1, add, del);\n    }\n    void insert(T\
    \ k) {\n        assert(k < inf);\n        insert(k, k + 1);\n    }\n    template<typename\
    \ A, typename D>\n    void erase(T l, T r, const A &add, const D &del) {\n   \
    \     if (l == r) return;\n        assert(l < r);\n        auto it = s.lower_bound(node(l,\
    \ l));\n        if (it != s.begin() && prev(it)->r > l) it = prev(it);\n     \
    \   while (it != s.end() && it->l < r) {\n            auto [a, b] = *it;\n   \
    \         it = s.erase(it);\n            del(a, b);\n            if (a < l) {\n\
    \                add(a, l);\n                s.emplace_hint(it, a, l);\n     \
    \       }\n            if (r < b) {\n                add(r, b);\n            \
    \    s.emplace_hint(it, r, b);\n                break;\n            }\n      \
    \  }\n    }\n    void erase(T l, T r) {\n        erase(l, r, [] (T, T) {}, []\
    \ (T, T) {});\n    }\n    template<typename A, typename D>\n    void erase(T k,\
    \ const A &add, const D &del) {\n        assert(k < inf);\n        erase(k, k\
    \ + 1, add, del);\n    }\n    void erase(T k) {\n        assert(k < inf);\n  \
    \      erase(k, k + 1);\n    }\n    pair<T, T> get(T k) const {\n        auto\
    \ it = key(k);\n        if (it != s.end() && it->l <= k && k < it->r) return {it->l,\
    \ it->r};\n        return {inf, inf};\n    }\n    T mex(T k = 0) const {\n   \
    \     auto it = key(k);\n        return it != s.end() && it->l <= k && k < it->r\
    \ ? it->r : k;\n    }\n    T next_element(T k) const {\n        auto it = key(k);\n\
    \        if (it == s.end()) it = s.begin();\n        else if (k < it->r) return\
    \ k;\n        else ++it;\n        return it == s.end() ? low : it->l;\n    }\n\
    \    T prev_element(T k) const {\n        auto it = key(k);\n        if (it ==\
    \ s.end()) return inf;\n        return k < it->r ? k : it->r - 1;\n    }\n   \
    \ bool covered(T l, T r) const {\n        if (l == r) return true;\n        assert(l\
    \ < r);\n        auto it = key(l);\n        return it != s.end() && it->l <= l\
    \ && r <= it->r;\n    }\n    bool covered(T k) const {\n        assert(k < inf);\n\
    \        return covered(k, k + 1);\n    }\n    bool intersects(T l, T r) const\
    \ {\n        if (l == r) return false;\n        assert(l < r);\n        auto it\
    \ = key(l);\n        if (it == s.end()) it = s.begin();\n        else if (it->r\
    \ <= l) ++it;\n        return it != s.end() && it->l < r;\n    }\n    bool empty()\
    \ const {\n        return s.empty();\n    }\n    int size() const {\n        return\
    \ s.size();\n    }\n    vector<pair<T, T>> intervals(T l = low, T r = inf) const\
    \ {\n        assert(l <= r);\n        vector<pair<T, T>> res;\n        if (l ==\
    \ r) return res;\n        auto it = key(l);\n        if (it == s.end()) it = s.begin();\n\
    \        for (; it != s.end() && it->l < r; ++it) {\n            if (l < it->r)\
    \ res.emplace_back(max(l, it->l), min(r, it->r));\n        }\n        return res;\n\
    \    }\n    void clear() {\n        s.clear();\n    }\nprivate:\n    static constexpr\
    \ T low = numeric_limits<T>::min();\n    static constexpr T inf = numeric_limits<T>::max();\n\
    \    struct node {\n        T l, r;\n        node(T _l, T _r) : l(_l), r(_r) {}\n\
    \        constexpr bool operator<(const node &a) const {\n            return l\
    \ == a.l ? r < a.r : l < a.l;\n        }\n    };\n    set<node> s;\n    typename\
    \ set<node>::const_iterator key(T k) const {\n        auto it = s.upper_bound(node(k,\
    \ inf));\n        return it == s.begin() ? s.end() : prev(it);\n    }\n};\n#line\
    \ 4 \"test/data_structure/set/interval_set.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    interval_set<int> S;\n    int ans = 0;\n    auto add\
    \ = [&] (int l, int r) -> void { ans += r - l; };\n    auto del = [&] (int l,\
    \ int r) -> void { ans -= r - l; };\n    for (int i = 0; i < N; i++) {\n     \
    \   int H;\n        cin >> H;\n        if (i % 2 == 0) {\n            S.insert(0,\
    \ H, add, del);\n        } else {\n            S.erase(0, H, add, del);\n    \
    \    }\n        cout << ans << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/3017\"\n\n#include \"\
    ../../../src/data_structure/set/interval_set.hpp\"\n\n#include <iostream>\n\n\
    int main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N;\n    cin >> N;\n    interval_set<int> S;\n    int ans = 0;\n    auto add\
    \ = [&] (int l, int r) -> void { ans += r - l; };\n    auto del = [&] (int l,\
    \ int r) -> void { ans -= r - l; };\n    for (int i = 0; i < N; i++) {\n     \
    \   int H;\n        cin >> H;\n        if (i % 2 == 0) {\n            S.insert(0,\
    \ H, add, del);\n        } else {\n            S.erase(0, H, add, del);\n    \
    \    }\n        cout << ans << '\\n';\n    }\n}"
  dependsOn:
  - src/data_structure/set/interval_set.hpp
  isVerificationFile: true
  path: test/data_structure/set/interval_set.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 11:13:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/set/interval_set.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/set/interval_set.test.cpp
- /verify/test/data_structure/set/interval_set.test.cpp.html
title: test/data_structure/set/interval_set.test.cpp
---
