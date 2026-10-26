---
title: Line
documentation_of: //src/geometry/line.hpp
---

直線 $ax+by+c=0$ を扱う.
交点が存在しない場合は `Point<T>::inf_point()` を返す.

## Constructor

```
Line<T> l(T a, T b, T c)
Line<T> l(Point<T> p, Point<T> q)
Line<T> l(T a, Point<T> p)
```

- 係数 $(a,b,c)$, 2 点 $p,q$, または傾き $a$ と通過点 $p$ から直線を作る

## online

```
bool l.online(Point<T> p)
```

- 点 $p$ が直線上にあるか判定する

## get_x, get_y

```
W<T> l.get_x(T y)
W<T> l.get_y(T x)
```

- 指定した一方の座標に対応するもう一方の座標を返す
- 一意に定まらない場合は `inf<T>()` を返す
- 整数型では割り算の結果が整数に切り捨てられる

## perpendicular

```
Line<T> l.perpendicular(Point<T> p)
```

- 点 $p$ を通り $l$ と直交する直線を返す
- `T` は浮動小数点型

## crosspoint

```
Point<T> crosspoint(Line<T> l1, Line<T> l2)
```

- 2 直線の交点を返す
- `T` は浮動小数点型

## projection, reflection

```
Point<T> l.projection(Point<T> p)
Point<T> l.reflection(Point<T> p)
```

- `projection` は $p$ の $l$ への正射影を返す
- `reflection` は $p$ の $l$ に関する対称点を返す
- `T` は浮動小数点型

## unit

```
Point<T> l.unit()
```

- $l$ に沿う単位ベクトルを返す
- `T` は浮動小数点型

## is_parallel, is_orthogonal

```
bool is_parallel(Line<T> l1, Line<T> l2)
bool is_orthogonal(Line<T> l1, Line<T> l2)
```

- 2 直線がそれぞれ平行, 直交するか判定する

## dist

```
T dist(Line<T> l, Point<T> p)
T dist(Point<T> p, Line<T> l)
```

- 点と直線の距離を返す
- `T` は浮動小数点型
