---
title: Polygon
documentation_of: //src/geometry/polygon.hpp
---

頂点を周上の順序で保持する多角形を扱う.
`Polygon<T>` は `vector<Point<T>>` を継承する.
頂点数を $n$ とする.

## Constructor

```
Polygon<T> v(int n)
Polygon<T> v(vector<Point<T>> ps)
```

- 頂点数を指定するか, 頂点列から多角形を作る

## contain

```
int contain(Polygon<T> v, Point<T> p)
int contain(Point<T> p, Polygon<T> v)
```

- 点 $p$ が多角形の外部なら $0$, 辺上なら $1$, 内部なら $2$ を返す
- $O(n)$

## area

```
W<T> area(Polygon<T> v)
```

- 符号付き面積の 2 倍を返す
- 頂点が反時計回りなら正, 時計回りなら負になる
- $O(n)$

## relabeling

```
void v.relabeling()
```

- $y$ 座標が最小, 同値なら $x$ 座標が最小の頂点を先頭にする
- 頂点列を反時計回りに揃える
- $O(n)$

## is_convex

```
bool is_convex(Polygon<T> v)
```

- 頂点列が反時計回りの凸多角形か判定する
- 頂点数が 2 以下なら偽を返す
- $O(n)$

## diam

```
pair<int, int> diam(Polygon<T> v)
```

- 凸多角形の頂点間距離が最大になる 2 頂点の添字を返す
- 頂点がない場合は $(-1,-1)$ を返す
- $O(n)$
