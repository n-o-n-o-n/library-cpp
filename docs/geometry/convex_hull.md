---
title: Convex Hull
documentation_of: //src/geometry/convex_hull.hpp
---

点列の凸包を返す.
入力の点数を $n$ とする.

```
Polygon<T> convex_hull(vector<Point<T>> ps, bool exclude_collinear = true)
```

- 同じ座標の点は 1 つにまとめる
- `exclude_collinear` は
  - 真なら, 凸包の辺上にある中間の点を除く
  - 偽なら, 凸包の辺上にある点も含める
- 全点が一直線上にある場合, `exclude_collinear` に応じて次が返る
  - 真なら両端の 2 点
  - 偽なら異なる点すべて
- 返り値は $(x, y)$ の辞書順で最小の点から始まり, 一直線上の場合を除いて反時計回りに並ぶ
- 点が 0 個または 1 個なら, そのまま返す
- $O(n\log n)$
