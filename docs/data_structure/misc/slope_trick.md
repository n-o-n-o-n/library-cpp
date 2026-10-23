---
title: Slope Trick
documentation_of: //src/data_structure/misc/slope_trick.hpp
---

区分線形凸関数 $f(x)$ を管理し, 関数の更新と最小値の取得を行う.
初期状態は $f(x)=0$ である.
計算量の $n$ はこれまでに追加した折れ点の個数とする.

## Constructor

```
slope_trick<T> st
```

- 初期関数 $f(x)=0$ を作る
- `T` は座標と関数値の型
- $O(1)$

## get_min

```
T get_min()
```

- $\min_x f(x)$ を返す
- $O(1)$

## min_range

```
pair<T, T> min_range()
```

- $f(x)$ が最小値を取る区間の両端を返す
- 区間が非有界の場合, その端点には擬似的な無限大を表す値を返す
- $O(1)$

## add_all

```
void add_all(T a)
```

- $f(x) \leftarrow f(x)+a$
- $O(1)$

## add_x_minus_a

```
void add_x_minus_a(T a)
```

- $f(x) \leftarrow f(x)+\max(0,x-a)$
- $O(\log n)$

## add_a_minus_x

```
void add_a_minus_x(T a)
```

- $f(x) \leftarrow f(x)+\max(0,a-x)$
- $O(\log n)$

## add_abs_x_minus_a

```
void add_abs_x_minus_a(T a)
```

- $f(x) \leftarrow f(x)+|x-a|$
- $O(\log n)$

## shift

```
void shift(T c)
```

- $f(x) \leftarrow f(x-c)$
- $O(1)$

## slide_window_min

```
void slide_window_min(T l, T r)
```

- $l \geq r$ とする
- $f(x) \leftarrow \min_{x-l \leq y \leq x-r} f(y)$
- $O(1)$
