---
title: Arg Sort
documentation_of: //src/geometry/arg_sort.hpp
---

偏角ソートをする.
偏角は $[0,2\pi)$ で考え, 次の順番で並べる.

- 零ベクトル
- 続いて偏角が小さい順
- 原点からの距離が小さい順
- 元の添字が小さい順

返り値を `ord` とすると, `ps[ord[i]]` が $i$ 番目の点である.

計算量は $O(n\log n)$
