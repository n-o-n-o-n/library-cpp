---
title: Offline Dynamic Connectivity
documentation_of: //src/data_structure/union_find/offline_dynamic_connectivity.hpp
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
