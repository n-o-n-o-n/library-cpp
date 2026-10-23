---
title: Extended GCD
documentation_of: //src/math/number_theory/ext_gcd.hpp
---

拡張ユークリッド互除法で最大公約数と Bézout 係数を求める.
`T` は符号付き整数型とする.

## ext_gcd

```
T ext_gcd(T a, T b, T &x, T &y)
```

- $a, b \ge 0$ とする
- $g = \gcd(a, b)$ を返し, $ax + by = g$ を満たす $x, y$ を参照引数に代入する
- $O(\log(\max(a, b)))$
