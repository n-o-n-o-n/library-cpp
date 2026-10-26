---
title: Common
documentation_of: //src/geometry/common.hpp
---

二次元幾何の点と基本演算を扱う.
`W<T>` は `T` が `int` なら `long long`, `long long` なら `__int128_t`, 浮動小数点型ならその型.

## Point

```
Point<T> p(T x = 0, T y = 0)
Point<T> p(pair<T, T> xy)
Point<T> Point<T>::inf_point()
```

- 座標 $(x,y)$ の点を作る
- `inf_point()` は両座標が `numeric_limits<T>::max()` の点を返す
- 点同士の加減算, スカラー倍と除算に対応する
- `==` は `eq` による比較, `<` は座標の厳密な辞書順比較

## eps, inf, PI

```
T eps<T>()
T inf<T>()
T PI<T>()
```

- `eps<T>()` は整数型なら $0$, 浮動小数点型なら $10^{-12}$ を返す
- `inf<T>()` は `numeric_limits<T>::max()` を返す
- `PI<T>()` は `T` が浮動小数点型のときに円周率を返す

## eq, sgn

```
bool eq(T a, T b)
bool eq(Point<T> p, Point<T> q)
int sgn(T a)
```

- `eq` は整数型では一致, 浮動小数点型では差が `eps<T>()` 未満かを判定する
- 点同士は各座標を比較する
- `sgn` は負なら $-1$, 零なら $0$, 正なら $1$ を返す

## dot, cross

```
W<T> dot(Point<T> p, Point<T> q)
W<T> cross(Point<T> p, Point<T> q)
```

- `dot` は内積 $p_xq_x+p_yq_y$ を返す
- `cross` は外積 $p_xq_y-p_yq_x$ を返す

## norm, dist

```
W<T> norm(Point<T> p)
T dist(Point<T> p)
T dist(Point<T> p, Point<T> q)
```

- `norm(p)` は $p_x^2+p_y^2$ を返す
- `dist(p)` は原点からの距離, `dist(p, q)` は 2 点間の距離を返す
- `dist` の `T` は浮動小数点型

## arg, angle

```
T arg(Point<T> p)
T angle(Point<T> o, Point<T> p, Point<T> q)
```

- `arg(p)` は $p$ の偏角を返す
- `angle(o, p, q)` は $\overrightarrow{op}$ から $\overrightarrow{oq}$ への符号付き角を返す
- `T` は浮動小数点型

## unit, rotate

```
Point<T> p.unit()
Point<T> p.rotate(T rad)
```

- `unit()` は $p$ と同方向の単位ベクトルを返し, $p$ は零ベクトルでないものとする
- `rotate(rad)` は $p$ を原点の周りに `rad` ラジアン回転する
- `T` は浮動小数点型

## ccw

```
int ccw(Point<T> a, Point<T> b, Point<T> c)
```

- 有向直線 $a\to b$ に対する $c$ の位置を返す
- $1$: 反時計回り
- $-1$: 時計回り
- $2$: 直線上で $a$ の後方
- $-2$: 直線上で $b$ の前方
- $0$: 線分 $ab$ 上
