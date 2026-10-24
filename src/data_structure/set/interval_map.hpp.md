---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/set/interval_map.test.cpp
    title: test/data_structure/set/interval_map.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/data_structure/set/interval_map.hpp\"\n#include <algorithm>\n\
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
    \  return it == s.begin() ? s.end() : prev(it);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <iterator>\n\
    #include <limits>\n#include <set>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename T, typename S>\nstruct interval_map\
    \ {\n    interval_map(const S &_e = S()) : e(_e) {}\n    template<typename A,\
    \ typename D>\n    void update(T l, T r, const S &x, const A &add, const D &del)\
    \ {\n        if (l == r) return;\n        assert(l < r);\n        auto cur = key(l);\n\
    \        if (cur != s.end() && cur->l <= l && r <= cur->r && cur->x == x) return;\n\
    \        auto it = s.lower_bound(node(l, l, e));\n        if (it != s.begin()\
    \ && prev(it)->r > l) it = prev(it);\n        while (it != s.end() && it->l <\
    \ r) {\n            auto [a, b, y] = *it;\n            it = s.erase(it);\n   \
    \         del(a, b, y);\n            if (a < l) {\n                add(a, l, y);\n\
    \                s.emplace_hint(it, a, l, y);\n            }\n            if (r\
    \ < b) {\n                add(r, b, y);\n                s.emplace_hint(it, r,\
    \ b, y);\n                break;\n            }\n        }\n        it = s.lower_bound(node(l,\
    \ l, e));\n        if (it != s.begin()) {\n            auto pre = prev(it);\n\
    \            if (pre->r == l && pre->x == x) {\n                l = pre->l;\n\
    \                del(pre->l, pre->r, pre->x);\n                it = s.erase(pre);\n\
    \            }\n        }\n        if (it != s.end() && it->l == r && it->x ==\
    \ x) {\n            r = it->r;\n            del(it->l, it->r, it->x);\n      \
    \      it = s.erase(it);\n        }\n        add(l, r, x);\n        s.emplace_hint(it,\
    \ l, r, x);\n    }\n    void update(T l, T r, const S &x) {\n        update(l,\
    \ r, x, [] (T, T, S) {}, [] (T, T, S) {});\n    }\n    template<typename A, typename\
    \ D>\n    void update(T k, const S &x, const A &add, const D &del) {\n       \
    \ assert(k < inf);\n        update(k, k + 1, x, add, del);\n    }\n    void update(T\
    \ k, const S &x) {\n        assert(k < inf);\n        update(k, k + 1, x);\n \
    \   }\n    tuple<T, T, S> get(T k) const {\n        assert(k < inf);\n       \
    \ auto it = key(k);\n        return it != s.end() && k < it->r ? make_tuple(it->l,\
    \ it->r, it->x) : make_tuple(k, k + 1, e);\n    }\n    S operator[](T k) const\
    \ {\n        auto it = key(k);\n        return it != s.end() && k < it->r ? it->x\
    \ : e;\n    }\n    tuple<T, T, S> mex(T k) const {\n        auto it = key(k);\n\
    \        if (it == s.end()) it = s.begin();\n        else if (it->r <= k) ++it;\n\
    \        return it == s.end() ? make_tuple(inf, inf, e) : make_tuple(it->l, it->r,\
    \ it->x);\n    }\n    T next_element(T k) const {\n        auto it = key(k);\n\
    \        if (it == s.end()) it = s.begin();\n        else if (k < it->r) return\
    \ k;\n        else ++it;\n        return it == s.end() ? low : it->l;\n    }\n\
    \    T prev_element(T k) const {\n        auto it = key(k);\n        if (it ==\
    \ s.end()) return inf;\n        return k < it->r ? k : it->r - 1;\n    }\n   \
    \ bool covered(T l, T r) const {\n        if (l == r) return true;\n        assert(l\
    \ < r);\n        auto it = key(l);\n        if (it == s.end() || it->r <= l) return\
    \ false;\n        T pos = it->r;\n        while (pos < r) {\n            ++it;\n\
    \            if (it == s.end() || it->l != pos) return false;\n            pos\
    \ = it->r;\n        }\n        return true;\n    }\n    bool covered(T k) const\
    \ {\n        assert(k < inf);\n        auto it = key(k);\n        return it !=\
    \ s.end() && k < it->r;\n    }\n    bool intersects(T l, T r) const {\n      \
    \  if (l == r) return false;\n        assert(l < r);\n        auto it = key(l);\n\
    \        if (it == s.end()) it = s.begin();\n        else if (it->r <= l) ++it;\n\
    \        return it != s.end() && it->l < r;\n    }\n    bool empty() const {\n\
    \        return s.empty();\n    }\n    int size() const {\n        return s.size();\n\
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
    \  return it == s.begin() ? s.end() : prev(it);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structure/set/interval_map.hpp
  requiredBy: []
  timestamp: '2026-10-24 11:13:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/set/interval_map.test.cpp
documentation_of: src/data_structure/set/interval_map.hpp
layout: document
title: Interval Map
---

区間を set で管理するテクのライブラリ(map ver.).

管理する区間の個数を $n$, 操作で処理する区間数を $m$ とする.

## Constructor

```
interval_map<T, S> mp(S e = S())
```

- 空の写像を作る
- `T` は符号付きまたは符号なしの整数型, `S` は `==` が定義された型
- $O(1)$

## update

```
void update(T l, T r, S x)
void update(T l, T r, S x, add, del)
void update(T k, S x)
void update(T k, S x, add, del)
```

- $[l,r)$ または位置 $k$ の値を $x$ にする
- 区間の更新は $O(\log n+m)$, 1 要素の更新は $O(\log n)$

## get

```
tuple<T, T, S> get(T k)
```

- $k$ を含む区間があれば, その左端, 右端, 値を返す
- $k$ がどの区間にも含まれない場合は `{k, k + 1, e}` を返す
- $O(\log n)$

## operator[]

```
S operator[](T k)
```

- 位置 $k$ の値を返す
- どの区間にも含まれない場合は $e$ を返す
- $O(\log n)$

## mex

```
tuple<T, T, S> mex(T k)
```

- 右端が $k$ より大きい最初の区間の左端, 右端, 値を返す
- 存在しない場合は `{numeric_limits<T>::max(), numeric_limits<T>::max(), e}` を返す
- $O(\log n)$

## next_element

```
T next_element(T k)
```

- $k$ 以上で管理する区間に含まれる最小の位置を返す
- 存在しない場合は `numeric_limits<T>::min()` を返す
- $O(\log n)$

## prev_element

```
T prev_element(T k)
```

- $k$ 以下で管理する区間に含まれる最大の位置を返す
- 存在しない場合は `numeric_limits<T>::max()` を返す
- $O(\log n)$

## covered

```
bool covered(T l, T r)
bool covered(T k)
```

- $[l,r)$ または位置 $k$ が管理する区間で覆われているなら `true` を返す
- 空区間に対しては `true` を返す
- 区間版は $O(\log n+m)$, 1 要素版は $O(\log n)$

## intersects

```
bool intersects(T l, T r)
```

- $[l,r)$ と管理する区間が重なるなら `true` を返す
- $O(\log n)$

## empty

```
bool empty()
```

- 管理する区間がなければ `true` を返す
- $O(1)$

## size

```
int size()
```

- 管理する区間の個数を返す
- $O(1)$

## intervals

```
vector<tuple<T, T, S>> intervals(T l = numeric_limits<T>::min(), T r = numeric_limits<T>::max())
```

- 管理する区間と $[l,r)$ の共通部分を左端の昇順で返す
- $O(\log n+m)$

## clear

```
void clear()
```

- 管理するすべての区間を削除する
- $O(n)$
