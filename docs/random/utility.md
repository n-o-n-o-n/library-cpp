---
title: Random Utility
documentation_of: //src/random/utility.hpp
---

`rng` 名前空間で整数乱数と整数の組を生成する.

## set_seed

```
void rng::set_seed(T sd)
```

- 乱数生成器のシードを $sd$ に設定する

## randint

```
T rng::randint(T lo, T hi)
```

- $lo$ 以上 $hi$ 以下の整数を生成する
- $lo \le hi$ とする

## randpair

```
pair<T, T> rng::randpair(T lo, T hi, bool strict = false)
```

- $lo \le l \le r \le hi$ を満たす組 $(l, r)$ を生成する
- `strict` が `true` なら $l < r$ とする
- $O(1)$
