---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/union_find/undoable_foldable_union_find.hpp
    title: Undoable Foldable Union Find
  - icon: ':heavy_check_mark:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/union_find/offline_dynamic_connectivity.test.cpp
    title: test/data_structure/union_find/offline_dynamic_connectivity.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/data_structure/union_find/undoable_foldable_union_find.hpp\"\
    \n\ntemplate<typename Abelian_Monoid>\nstruct undoable_foldable_union_find {\n\
    \    using M = Abelian_Monoid;\n    using S = M::S;\n    undoable_foldable_union_find(int\
    \ n) : p(n, -1), cyc(n), a(n, M::e()), d(n, M::e()) {\n        iota(cyc.begin(),\
    \ cyc.end(), 0);\n    }\n    int leader(int u) const {\n        assert(0 <= u\
    \ && u < ssize(p));\n        return p[u] < 0 ? u : leader(p[u]);\n    }\n    bool\
    \ same(int u, int v) const {\n        assert(0 <= u && u < ssize(p));\n      \
    \  assert(0 <= v && v < ssize(p));\n        return leader(u) == leader(v);\n \
    \   }\n    void merge(int u, int v) {\n        assert(0 <= u && u < ssize(p));\n\
    \        assert(0 <= v && v < ssize(p));\n        u = leader(u);\n        v =\
    \ leader(v);\n        if (p[u] > p[v]) swap(u, v);\n        his_type.push_back(false);\n\
    \        his_merge.emplace_back(u, v, p[u], p[v], cyc[u], cyc[v], d[u]);\n   \
    \     if (u == v) return;\n        p[u] += p[v];\n        d[u] = M::op(d[u], d[v]);\n\
    \        p[v] = u;\n        swap(cyc[u], cyc[v]);\n    }\n    int size(int u)\
    \ const {\n        assert(0 <= u && u < ssize(p));\n        return -p[leader(u)];\n\
    \    }\n    void set(int u, const S &x) {\n        assert(0 <= u && u < ssize(p));\n\
    \        int r = leader(u);\n        his_type.push_back(true);\n        his_set.emplace_back(u,\
    \ r, a[u], d[r]);\n        d[r] = M::op(d[r], M::op(M::inv(a[u]), x));\n     \
    \   a[u] = x;\n    }\n    S prod(int u) const {\n        assert(0 <= u && u <\
    \ ssize(p));\n        return d[leader(u)];\n    }\n    void undo() {\n       \
    \ assert(!his_type.empty());\n        bool is_set = his_type.back();\n       \
    \ his_type.pop_back();\n        if (is_set) {\n            auto [u, r, val, fld]\
    \ = his_set.back();\n            his_set.pop_back();\n            a[u] = val;\n\
    \            d[r] = fld;\n        } else {\n            auto [u, v, pu, pv, cu,\
    \ cv, fld] = his_merge.back();\n            his_merge.pop_back();\n          \
    \  if (u == v) return;\n            p[u] = pu;\n            p[v] = pv;\n     \
    \       cyc[u] = cu;\n            cyc[v] = cv;\n            d[u] = fld;\n    \
    \    }\n    }\n    vector<int> group(int u) const {\n        assert(0 <= u &&\
    \ u < ssize(p));\n        vector<int> res = {u};\n        int v = cyc[u];\n  \
    \      while (v != u) {\n            res.push_back(v);\n            v = cyc[v];\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> groups() const\
    \ {\n        int n = p.size();\n        vector<vector<int>> tmp(n);\n        for\
    \ (int i = 0; i < n; i++) tmp[leader(i)].push_back(i);\n        vector<vector<int>>\
    \ res;\n        for (auto v : tmp) if (v.size()) res.push_back(v);\n        return\
    \ res;\n    }\nprivate:\n    vector<int> p, cyc;\n    vector<S> a, d;\n    vector<bool>\
    \ his_type;\n    vector<tuple<int, int, S, S>> his_set;\n    vector<tuple<int,\
    \ int, int, int, int, int, S>> his_merge;\n};\n#line 4 \"src/data_structure/union_find/offline_dynamic_connectivity.hpp\"\
    \n\ntemplate<typename Abelian_Monoid>\nstruct offline_dynamic_connectivity {\n\
    \    using M = Abelian_Monoid;\n    using S = M::S;\n    offline_dynamic_connectivity(int\
    \ _n = 0) : n(_n), t(0), lst(_n, -1), d(_n, M::e()) {}\n    void merge(int u,\
    \ int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        act[key(u, v)].push_back(t++);\n    }\n    void erase(int u, int v) {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        auto\
    \ it = act.find(key(u, v));\n        assert(it != act.end() && !it->second.empty());\n\
    \        int l = it->second.back();\n        it->second.pop_back();\n        if\
    \ (it->second.empty()) act.erase(it);\n        his_e.emplace_back(l, t++, u, v);\n\
    \    }\n    void set(int u, const S &x) {\n        assert(0 <= u && u < n);\n\
    \        if (lst[u] != -1) his_v.emplace_back(lst[u], t, u, d[u]);\n        lst[u]\
    \ = t++;\n        d[u] = x;\n    }\n    void prod(int u) {\n        assert(0 <=\
    \ u && u < n);\n        qs.emplace_back(t++, u, -1);\n    }\n    void same(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        qs.emplace_back(t++, u, v);\n    }\n    vector<pair<S, bool>> solve()\
    \ const {\n        vector<pair<S, bool>> ans(qs.size(), {M::e(), false});\n  \
    \      if (t == 0) return ans;\n        int sz = 1;\n        while (sz < t) sz\
    \ <<= 1;\n        vector<vector<int>> seg(2 * sz);\n        vector<pair<int, int>>\
    \ es;\n        vector<pair<int, S>> vs;\n        auto upd = [&] (int l, int r,\
    \ int e) -> void {\n            l += sz;\n            r += sz;\n            while\
    \ (l < r) {\n                if (l & 1) seg[l++].push_back(e);\n             \
    \   if (r & 1) seg[--r].push_back(e);\n                l >>= 1;\n            \
    \    r >>= 1;\n            }\n        };\n        for (auto [l, r, u, v] : his_e)\
    \ {\n            int id = es.size();\n            es.emplace_back(u, v);\n   \
    \         upd(l, r, id);\n        }\n        for (const auto &[e, st] : act) {\n\
    \            int u = e / w, v = e % w;\n            for (int l : st) {\n     \
    \           int id = es.size();\n                es.emplace_back(u, v);\n    \
    \            upd(l, t, id);\n            }\n        }\n        for (const auto\
    \ &[l, r, u, x] : his_v) {\n            int id = vs.size();\n            vs.emplace_back(u,\
    \ x);\n            upd(l, r, -id - 1);\n        }\n        for (int u = 0; u <\
    \ n; u++) {\n            if (lst[u] == -1) continue;\n            int id = vs.size();\n\
    \            vs.emplace_back(u, d[u]);\n            upd(lst[u], t, -id - 1);\n\
    \        }\n        vector<int> q(t, -1);\n        for (int i = 0; i < ssize(qs);\
    \ i++) q[get<0>(qs[i])] = i;\n        undoable_foldable_union_find<M> uf(n);\n\
    \        auto dfs = [&] (const auto &dfs, int k) -> void {\n            for (int\
    \ id : seg[k]) {\n                if (id >= 0) {\n                    auto [u,\
    \ v] = es[id];\n                    uf.merge(u, v);\n                } else {\n\
    \                    const auto &[u, x] = vs[-id - 1];\n                    uf.set(u,\
    \ x);\n                }\n            }\n            if (k >= sz) {\n        \
    \        int cur = k - sz;\n                if (cur < t && q[cur] != -1) {\n \
    \                   int i = q[cur];\n                    auto [_, u, v] = qs[i];\n\
    \                    if (v == -1) ans[i].first = uf.prod(u);\n               \
    \     else ans[i].second = uf.same(u, v);\n                }\n            } else\
    \ {\n                dfs(dfs, 2 * k);\n                dfs(dfs, 2 * k + 1);\n\
    \            }\n            for (int i = 0; i < ssize(seg[k]); i++) uf.undo();\n\
    \        };\n        dfs(dfs, 1);\n        return ans;\n    }\nprivate:\n    int\
    \ n, t;\n    vector<int> lst;\n    vector<tuple<int, int, int>> qs;\n    vector<S>\
    \ d;\n    unordered_map<long long, vector<int>> act;\n    vector<tuple<int, int,\
    \ int, int>> his_e;\n    vector<tuple<int, int, int, S>> his_v;\n    static constexpr\
    \ long long w = 1LL << 32;\n    static long long key(int &u, int &v) {\n     \
    \   if (u > v) swap(u, v);\n        return u * w + v;\n    }\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n#include \"undoable_foldable_union_find.hpp\"\
    \n\ntemplate<typename Abelian_Monoid>\nstruct offline_dynamic_connectivity {\n\
    \    using M = Abelian_Monoid;\n    using S = M::S;\n    offline_dynamic_connectivity(int\
    \ _n = 0) : n(_n), t(0), lst(_n, -1), d(_n, M::e()) {}\n    void merge(int u,\
    \ int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        act[key(u, v)].push_back(t++);\n    }\n    void erase(int u, int v) {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        auto\
    \ it = act.find(key(u, v));\n        assert(it != act.end() && !it->second.empty());\n\
    \        int l = it->second.back();\n        it->second.pop_back();\n        if\
    \ (it->second.empty()) act.erase(it);\n        his_e.emplace_back(l, t++, u, v);\n\
    \    }\n    void set(int u, const S &x) {\n        assert(0 <= u && u < n);\n\
    \        if (lst[u] != -1) his_v.emplace_back(lst[u], t, u, d[u]);\n        lst[u]\
    \ = t++;\n        d[u] = x;\n    }\n    void prod(int u) {\n        assert(0 <=\
    \ u && u < n);\n        qs.emplace_back(t++, u, -1);\n    }\n    void same(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        qs.emplace_back(t++, u, v);\n    }\n    vector<pair<S, bool>> solve()\
    \ const {\n        vector<pair<S, bool>> ans(qs.size(), {M::e(), false});\n  \
    \      if (t == 0) return ans;\n        int sz = 1;\n        while (sz < t) sz\
    \ <<= 1;\n        vector<vector<int>> seg(2 * sz);\n        vector<pair<int, int>>\
    \ es;\n        vector<pair<int, S>> vs;\n        auto upd = [&] (int l, int r,\
    \ int e) -> void {\n            l += sz;\n            r += sz;\n            while\
    \ (l < r) {\n                if (l & 1) seg[l++].push_back(e);\n             \
    \   if (r & 1) seg[--r].push_back(e);\n                l >>= 1;\n            \
    \    r >>= 1;\n            }\n        };\n        for (auto [l, r, u, v] : his_e)\
    \ {\n            int id = es.size();\n            es.emplace_back(u, v);\n   \
    \         upd(l, r, id);\n        }\n        for (const auto &[e, st] : act) {\n\
    \            int u = e / w, v = e % w;\n            for (int l : st) {\n     \
    \           int id = es.size();\n                es.emplace_back(u, v);\n    \
    \            upd(l, t, id);\n            }\n        }\n        for (const auto\
    \ &[l, r, u, x] : his_v) {\n            int id = vs.size();\n            vs.emplace_back(u,\
    \ x);\n            upd(l, r, -id - 1);\n        }\n        for (int u = 0; u <\
    \ n; u++) {\n            if (lst[u] == -1) continue;\n            int id = vs.size();\n\
    \            vs.emplace_back(u, d[u]);\n            upd(lst[u], t, -id - 1);\n\
    \        }\n        vector<int> q(t, -1);\n        for (int i = 0; i < ssize(qs);\
    \ i++) q[get<0>(qs[i])] = i;\n        undoable_foldable_union_find<M> uf(n);\n\
    \        auto dfs = [&] (const auto &dfs, int k) -> void {\n            for (int\
    \ id : seg[k]) {\n                if (id >= 0) {\n                    auto [u,\
    \ v] = es[id];\n                    uf.merge(u, v);\n                } else {\n\
    \                    const auto &[u, x] = vs[-id - 1];\n                    uf.set(u,\
    \ x);\n                }\n            }\n            if (k >= sz) {\n        \
    \        int cur = k - sz;\n                if (cur < t && q[cur] != -1) {\n \
    \                   int i = q[cur];\n                    auto [_, u, v] = qs[i];\n\
    \                    if (v == -1) ans[i].first = uf.prod(u);\n               \
    \     else ans[i].second = uf.same(u, v);\n                }\n            } else\
    \ {\n                dfs(dfs, 2 * k);\n                dfs(dfs, 2 * k + 1);\n\
    \            }\n            for (int i = 0; i < ssize(seg[k]); i++) uf.undo();\n\
    \        };\n        dfs(dfs, 1);\n        return ans;\n    }\nprivate:\n    int\
    \ n, t;\n    vector<int> lst;\n    vector<tuple<int, int, int>> qs;\n    vector<S>\
    \ d;\n    unordered_map<long long, vector<int>> act;\n    vector<tuple<int, int,\
    \ int, int>> his_e;\n    vector<tuple<int, int, int, S>> his_v;\n    static constexpr\
    \ long long w = 1LL << 32;\n    static long long key(int &u, int &v) {\n     \
    \   if (u > v) swap(u, v);\n        return u * w + v;\n    }\n};\n"
  dependsOn:
  - src/template.hpp
  - src/data_structure/union_find/undoable_foldable_union_find.hpp
  isVerificationFile: false
  path: src/data_structure/union_find/offline_dynamic_connectivity.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/union_find/offline_dynamic_connectivity.test.cpp
documentation_of: src/data_structure/union_find/offline_dynamic_connectivity.hpp
layout: document
title: Offline Dynamic Connectivity
---

辺の追加・削除と頂点の値の変更を記録し, 連結成分の総積と連結判定をまとめて求める.

`Abelian_Monoid` には型 `S`, 可換な二項演算 `op`, 単位元 `e`, 逆元 `inv` が必要. 各頂点の初期値は `e()`.

## Constructor

```
offline_dynamic_connectivity<Abelian_Monoid> dc(int n)
```

- $n$ 頂点で初期化する

## merge

```
void merge(int u, int v)
```

- 辺 $(u,v)$ を追加する. 同じ辺を複数回追加できる

## erase

```
void erase(int u, int v)
```

- 辺 $(u,v)$ の追加を 1 回分取り消す
- 対応する未削除の `merge` が必要

## set

```
void set(int u, const S &x)
```

- 頂点 $u$ の値を $x$ に変更する

## prod

```
void prod(int u)
```

- $u$ が属する連結成分の頂点の値を `op` でまとめた結果を求めるクエリを追加する

## same

```
void same(int u, int v)
```

- $u$ と $v$ が同じ連結成分に属するかを判定するクエリを追加する

## solve

```
vector<pair<S, bool>> solve()
```

- 登録した `prod`, `same` の結果を呼び出し順に返す
- `prod` の結果は `first`, `same` の結果は `second` に入る
    - 使わない側はそれぞれ `e()`, `false`
- 操作回数を $q$ として, 計算量は expected $O(q\log q\log n)$, メモリは $O(n + q\log q)$ (expected は `unordered_map` 由来)
