---
title: Circle
documentation_of: //src/geometry/circle.hpp
---

円を扱う.
中心は `p`, 半径は `r`.
交点や接点が存在しない場合は `Point<T>::inf_point()` を返す.

## Constructor

```
Circle<T> c(Point<T> p, T r)
```

- 中心が $p$, 半径が $r$ の円を作る

## count_common_tangents

```
int count_common_tangents(Circle<T> c1, Circle<T> c2)
```

- `c1` と `c2` の共通接線の本数を返す
- 二円が一致する場合は $-1$ を返す

## crosspoint

```
array<Point<T>, 2> crosspoint(Circle<T> c, Line<T> l)
array<Point<T>, 2> crosspoint(Line<T> l, Circle<T> c)
array<Point<T>, 2> crosspoint(Circle<T> c1, Circle<T> c2)
```

- 交点を返す
- 接する場合は同じ点を 2 つ返す
- `T` は浮動小数点型

## tangent_points

```
array<Point<T>, 2> tangent_points(Circle<T> c, Point<T> q)
array<Point<T>, 2> tangent_points(Point<T> q, Circle<T> c)
```

- 点 $q$ から引いた接線と円の接点を返す
- 接線が 1 本の場合は同じ点を 2 つ返す
- `T` は浮動小数点型

## common_tangents

```
array<Line<T>, 4> common_tangents(Circle<T> c1, Circle<T> c2)
```

- `c1` と `c2` の共通接線を返す
- $K$ を `count_common_tangents(c1, c2)` として, $[0,K)$ 番目に答えが入る
- $K$ 以降の要素は未定義
- 二円が一致する場合の動作は未定義
- `T` は浮動小数点型
