---
title: Monotone Convex Hull Trick
documentation_of: //src/data_structure/cht/monotone_cht.hpp
---

傾きとクエリ点がそれぞれ単調な直線集合に対し, 値の最小値を求める CHT.

## Constructor

```
monotone_cht<T, query_dec> cht
```

- `T` は座標と直線の値の整数型
- `query_dec = false` ならクエリ点は単調非減少, `true` なら単調非増加. 省略時は `false`
- 追加する直線の傾きは単調非増加または単調非減少. 向きは自動で判定する

## add_line

```
void add_line(T a, T b)
```

- 直線 $y=ax+b$ を追加する
- ならし $O(1)$

## get

```
T get(T x)
```

- $x$ における直線の値の最小値を返す
- 直線がない場合は `inf<T>()` を返す
- ならし $O(1)$
