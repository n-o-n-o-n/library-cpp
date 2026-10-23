---
title: Garner
documentation_of: //src/math/number_theory/garner.hpp
---

複数の合同式を解き, 指定した法での解を求める.
`T` は 64 bit 以下の符号付き整数型とする.

## garner

```
T garner(vector<T> rems, vector<T> mods, T mod)
```

- $r=\mathrm{rems}$ と $m=\mathrm{mods}$ は同じ長さ $k$ とし, 各 $m_i$ と $\mathrm{mod}$ は正とする
- $x \equiv r_i \pmod{m_i}$ をすべて満たす解を $0 \le x < \mathrm{mod}$ で返す
- 解がなければ $-1$ を返す
- $M$ を法の最大値として $O(k^2 + k \log M)$
