---
title: Segment
documentation_of: //src/geometry/segment.hpp
---

両端点を含む線分を扱う.
交点が存在しない場合は `Point<T>::inf_point()` を返す.

## Constructor

```
Segment<T> s(Point<T> a, Point<T> b)
```

- $a$ と $b$ を端点とする線分を作る

## on_segment

```
bool s.on_segment(Point<T> p)
```

- 点 $p$ が線分上にあるか判定する

## intersect

```
bool intersect(Segment<T> s1, Segment<T> s2)
```

- 2 線分が端点を含めて交わるか判定する

## crosspoint

```
Point<T> crosspoint(Segment<T> s1, Segment<T> s2)
```

- 2 線分の交点を返す
- 交わる部分が線分になる場合は, その中で座標が辞書順最小の点を返す
- `T` は浮動小数点型

## dist

```
T dist(Segment<T> s, Point<T> p)
T dist(Point<T> p, Segment<T> s)
T dist(Segment<T> s1, Segment<T> s2)
```

- 点と線分, または 2 線分の距離を返す
- `T` は浮動小数点型
