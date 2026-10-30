---
title: Formal Power Series
documentation_of: //src/fps/fps.hpp
---

形式的冪級数を扱うライブラリ.

`inv`, `log`, `exp`, `pow`, `composition`, `compositional_inverse`, `taylor_shift`, `power_projection` を使うには, 各ヘッダ, または `fps_all.hpp` を `include` する.

## Constructor

```
fps<mint> f(int n)
fps<mint> f(vector<mint> v)
```

- $n$ 個の零係数を持つ級数, または $v$ の係数を持つ級数を作る
- `vector<mint>` のコンストラクタも使える

## operator

```
fps operator+=(mint r)
fps operator-=(mint r)
fps operator+=(fps f)
fps operator-=(fps f)
fps operator*=(mint r)
fps operator/=(mint r)
fps operator*=(fps f)
fps operator/=(fps f)
fps div(fps f)
fps operator%=(fps f)
fps operator<<(int k)
fps operator>>(int k)
mint operator()(mint x)
```

- `/(fps)` は形式的冪級数での除算, `div` は多項式としての除算
- `/(fps)`, `div` を使うには `fps_inv.hpp` の `include` が必要

## diff, integral

```
fps diff()
fps integral()
```

- `diff` は $f'(x) = \sum_{i=1}^{n-1} i f_i x^{i-1}$ を返す
- `integral` は積分定数を $0$ とする $\int f(x)\,dx = \sum_{i=0}^{n-1} \frac{f_i}{i+1}x^{i+1}$ を返す
- $O(n)$

## inv

```
fps inv(int deg = -1)
```

- $[x^0]f \ne 0$ とする
- $g(x) = 1 / f$ の先頭 $n$ 個の係数を返す
- 個別に読み込む場合は `fps_inv.hpp` が必要
- $O(n\log n)$

## log

```
fps log(int deg = -1)
```

- $[x^0]f = 1$ とする
- $\log f = \sum_{i=1}^{\infty} \frac{(-1)^{i+1}}{i}(f-1)^i$ の先頭 $n$ 個の係数を返す
- 個別に読み込む場合は `fps_log.hpp` が必要
- $O(n\log n)$

## exp

```
fps exp(int deg = -1)
```

- $[x^0]f = 0$ とする
- $\exp f(x) = \sum_{i=0}^{\infty} \frac{f^i}{i!}$ の先頭 $n$ 個の係数を返す
- 個別に読み込む場合は `fps_exp.hpp` が必要
- $O(n\log n)$

## pow

```
fps pow(long long k, int deg = -1)
```

- $k \ge 0$ とする
- $f^k$ の先頭 $n$ 個の係数を返す
- 個別に読み込む場合は `fps_pow.hpp` が必要
- $O(n\log n)$

## composition

```
fps operator()(fps g, int deg = -1)
```

- $[x^0]g = 0$ とする
- $f(g(x))$ の先頭 $n$ 個の係数を返す
- 個別に読み込む場合は `fps_composition.hpp` が必要
- $O(n\log^2 n)$

## compositional_inverse

```
fps compositional_inverse(int deg = -1)
```

- $[x^0]f = 0$, $[x^1]f \ne 0$ とする
- $f(g(x)) = x$ を満たす形式的冪級数 $g$ の先頭 $n$ 個の係数を返す
- 個別に読み込む場合は `fps_compositional_inverse.hpp` が必要
- $O(n\log^2 n)$

## taylor_shift

```
fps taylor_shift(mint c)
```

- $f(x+c)$ の係数を返す
- 個別に読み込む場合は `polynomial_taylor_shift.hpp` が必要
- $O(n\log n)$
