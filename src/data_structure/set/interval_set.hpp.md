---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/set/interval_set.test.cpp
    title: test/data_structure/set/interval_set.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/set/interval_set.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <iterator>\n#include <limits>\n#include <set>\n#include\
    \ <utility>\n#include <vector>\nusing namespace std;\n\ntemplate<typename T>\n\
    struct interval_set {\n    interval_set() = default;\n    template<typename A,\
    \ typename D>\n    void insert(T l, T r, const A &add, const D &del) {\n     \
    \   if (l == r) return;\n        assert(l < r);\n        auto cur = key(l);\n\
    \        if (cur != s.end() && cur->l <= l && r <= cur->r) return;\n        auto\
    \ it = s.lower_bound(node(l, l));\n        if (it != s.begin()) {\n          \
    \  auto pre = prev(it);\n            if (l <= pre->r) {\n                l = pre->l;\n\
    \                r = max(r, pre->r);\n                del(pre->l, pre->r);\n \
    \               it = s.erase(pre);\n            }\n        }\n        while (it\
    \ != s.end() && it->l <= r) {\n            r = max(r, it->r);\n            del(it->l,\
    \ it->r);\n            it = s.erase(it);\n        }\n        add(l, r);\n    \
    \    s.emplace_hint(it, l, r);\n    }\n    void insert(T l, T r) {\n        insert(l,\
    \ r, [] (T, T) {}, [] (T, T) {});\n    }\n    template<typename A, typename D>\n\
    \    void insert(T k, const A &add, const D &del) {\n        assert(k < inf);\n\
    \        insert(k, k + 1, add, del);\n    }\n    void insert(T k) {\n        assert(k\
    \ < inf);\n        insert(k, k + 1);\n    }\n    template<typename A, typename\
    \ D>\n    void erase(T l, T r, const A &add, const D &del) {\n        if (l ==\
    \ r) return;\n        assert(l < r);\n        auto it = s.lower_bound(node(l,\
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
    \ inf));\n        return it == s.begin() ? s.end() : prev(it);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n\
    #include <limits>\n#include <set>\n#include <utility>\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate<typename T>\nstruct interval_set {\n    interval_set()\
    \ = default;\n    template<typename A, typename D>\n    void insert(T l, T r,\
    \ const A &add, const D &del) {\n        if (l == r) return;\n        assert(l\
    \ < r);\n        auto cur = key(l);\n        if (cur != s.end() && cur->l <= l\
    \ && r <= cur->r) return;\n        auto it = s.lower_bound(node(l, l));\n    \
    \    if (it != s.begin()) {\n            auto pre = prev(it);\n            if\
    \ (l <= pre->r) {\n                l = pre->l;\n                r = max(r, pre->r);\n\
    \                del(pre->l, pre->r);\n                it = s.erase(pre);\n  \
    \          }\n        }\n        while (it != s.end() && it->l <= r) {\n     \
    \       r = max(r, it->r);\n            del(it->l, it->r);\n            it = s.erase(it);\n\
    \        }\n        add(l, r);\n        s.emplace_hint(it, l, r);\n    }\n   \
    \ void insert(T l, T r) {\n        insert(l, r, [] (T, T) {}, [] (T, T) {});\n\
    \    }\n    template<typename A, typename D>\n    void insert(T k, const A &add,\
    \ const D &del) {\n        assert(k < inf);\n        insert(k, k + 1, add, del);\n\
    \    }\n    void insert(T k) {\n        assert(k < inf);\n        insert(k, k\
    \ + 1);\n    }\n    template<typename A, typename D>\n    void erase(T l, T r,\
    \ const A &add, const D &del) {\n        if (l == r) return;\n        assert(l\
    \ < r);\n        auto it = s.lower_bound(node(l, l));\n        if (it != s.begin()\
    \ && prev(it)->r > l) it = prev(it);\n        while (it != s.end() && it->l <\
    \ r) {\n            auto [a, b] = *it;\n            it = s.erase(it);\n      \
    \      del(a, b);\n            if (a < l) {\n                add(a, l);\n    \
    \            s.emplace_hint(it, a, l);\n            }\n            if (r < b)\
    \ {\n                add(r, b);\n                s.emplace_hint(it, r, b);\n \
    \               break;\n            }\n        }\n    }\n    void erase(T l, T\
    \ r) {\n        erase(l, r, [] (T, T) {}, [] (T, T) {});\n    }\n    template<typename\
    \ A, typename D>\n    void erase(T k, const A &add, const D &del) {\n        assert(k\
    \ < inf);\n        erase(k, k + 1, add, del);\n    }\n    void erase(T k) {\n\
    \        assert(k < inf);\n        erase(k, k + 1);\n    }\n    pair<T, T> get(T\
    \ k) const {\n        auto it = key(k);\n        if (it != s.end() && it->l <=\
    \ k && k < it->r) return {it->l, it->r};\n        return {inf, inf};\n    }\n\
    \    T mex(T k = 0) const {\n        auto it = key(k);\n        return it != s.end()\
    \ && it->l <= k && k < it->r ? it->r : k;\n    }\n    T next_element(T k) const\
    \ {\n        auto it = key(k);\n        if (it == s.end()) it = s.begin();\n \
    \       else if (k < it->r) return k;\n        else ++it;\n        return it ==\
    \ s.end() ? low : it->l;\n    }\n    T prev_element(T k) const {\n        auto\
    \ it = key(k);\n        if (it == s.end()) return inf;\n        return k < it->r\
    \ ? k : it->r - 1;\n    }\n    bool covered(T l, T r) const {\n        if (l ==\
    \ r) return true;\n        assert(l < r);\n        auto it = key(l);\n       \
    \ return it != s.end() && it->l <= l && r <= it->r;\n    }\n    bool covered(T\
    \ k) const {\n        assert(k < inf);\n        return covered(k, k + 1);\n  \
    \  }\n    bool intersects(T l, T r) const {\n        if (l == r) return false;\n\
    \        assert(l < r);\n        auto it = key(l);\n        if (it == s.end())\
    \ it = s.begin();\n        else if (it->r <= l) ++it;\n        return it != s.end()\
    \ && it->l < r;\n    }\n    bool empty() const {\n        return s.empty();\n\
    \    }\n    int size() const {\n        return s.size();\n    }\n    vector<pair<T,\
    \ T>> intervals(T l = low, T r = inf) const {\n        assert(l <= r);\n     \
    \   vector<pair<T, T>> res;\n        if (l == r) return res;\n        auto it\
    \ = key(l);\n        if (it == s.end()) it = s.begin();\n        for (; it !=\
    \ s.end() && it->l < r; ++it) {\n            if (l < it->r) res.emplace_back(max(l,\
    \ it->l), min(r, it->r));\n        }\n        return res;\n    }\n    void clear()\
    \ {\n        s.clear();\n    }\nprivate:\n    static constexpr T low = numeric_limits<T>::min();\n\
    \    static constexpr T inf = numeric_limits<T>::max();\n    struct node {\n \
    \       T l, r;\n        node(T _l, T _r) : l(_l), r(_r) {}\n        constexpr\
    \ bool operator<(const node &a) const {\n            return l == a.l ? r < a.r\
    \ : l < a.l;\n        }\n    };\n    set<node> s;\n    typename set<node>::const_iterator\
    \ key(T k) const {\n        auto it = s.upper_bound(node(k, inf));\n        return\
    \ it == s.begin() ? s.end() : prev(it);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/set/interval_set.hpp
  requiredBy: []
  timestamp: '2026-10-24 11:13:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/set/interval_set.test.cpp
documentation_of: src/data_structure/set/interval_set.hpp
layout: document
title: Interval Set
---

区間を set で管理するテクのライブラリ(set ver.).

管理する区間の個数を $n$, 操作で処理する区間数を $m$ とする.

## Constructor

```
interval_set<T> s
```

- 空の集合を作る
- `T` は整数
- $O(1)$

## insert

```
void insert(T l, T r)
void insert(T l, T r, add, del)
void insert(T k)
void insert(T k, add, del)
```

- $[l,r)$ または要素 $k$ を集合に加える
- 区間の挿入は $O(\log n+m)$, 1 要素の挿入は $O(\log n)$

## erase

```
void erase(T l, T r)
void erase(T l, T r, add, del)
void erase(T k)
void erase(T k, add, del)
```

- $[l,r)$ または要素 $k$ を集合から削除する
- 区間の削除は $O(\log n+m)$, 1 要素の削除は $O(\log n)$

## get

```
pair<T, T> get(T k)
```

- $k$ を含む区間の両端を返す
- 含まれない場合は `{numeric_limits<T>::max(), numeric_limits<T>::max()}` を返す
- $O(\log n)$

## mex

```
T mex(T k = 0)
```

- $k$ 以上で集合に含まれない最小の値を返す
- $O(\log n)$

## next_element

```
T next_element(T k)
```

- $k$ 以上で集合に含まれる最小の値を返す
- 存在しない場合は `numeric_limits<T>::min()` を返す
- $O(\log n)$

## prev_element

```
T prev_element(T k)
```

- $k$ 以下で集合に含まれる最大の値を返す
- 存在しない場合は `numeric_limits<T>::max()` を返す
- $O(\log n)$

## covered

```
bool covered(T l, T r)
bool covered(T k)
```

- $[l,r)$ または要素 $k$ がすべて集合に含まれるなら `true` を返す
- $O(\log n)$

## intersects

```
bool intersects(T l, T r)
```

- $[l,r)$ に集合の要素が一つでも含まれるなら `true` を返す
- 空区間に対しては `false` を返す
- $O(\log n)$

## empty

```
bool empty()
```

- 集合が空なら `true` を返す
- $O(1)$

## size

```
int size()
```

- 管理する区間の個数を返す
- $O(1)$

## intervals

```
vector<pair<T, T>> intervals(T l = numeric_limits<T>::min(), T r = numeric_limits<T>::max())
```

- 集合と $[l,r)$ の共通部分を区間ごとに昇順で返す
- $O(\log n+m)$

## clear

```
void clear()
```

- すべての区間を削除する
- $O(n)$
