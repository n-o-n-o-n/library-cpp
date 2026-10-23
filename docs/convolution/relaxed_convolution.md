---
title: Relaxed Convolution
documentation_of: //src/convolution/relaxed_convolution.hpp
---

オンラインで畳み込みをする.

## Constructor

```
relaxed_convolution<mint> rc(int n)
```

- 添字 $0$ から $n$ までの畳み込みを計算するための状態を作る
- $O(n)$

## get

```
mint get(mint x, mint y)
```

- $k$ 回目の呼び出しで $a_k = x, b_k = y$ として $c_k = \sum_{i+j=k}a_ib_j$ を返す
- 全 $n+1$ 回の計算量は $O(n \log^2 n)$
