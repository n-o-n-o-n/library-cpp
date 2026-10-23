---
title: Xor Shift
documentation_of: //src/random/xor_shift.hpp
---

`T` は `int` または `long long`.
`U` は `T` に対応する符号なし整数型.

## Constructor

```
xor_shift<T> rng(U seed = 0)
```

- 疑似乱数生成器を作る
- $seed$ は省略できる
- $O(1)$

## operator()

```
U operator()()
```

- 次の疑似乱数を返す
- $O(1)$

## operator()(lo, hi)

```
T operator()(T lo, T hi)
```

- $lo$ 以上 $hi$ 以下の整数を返す
- $lo \le hi$ かつ $hi - lo + 1$ が `T` で表せることを前提とする
- $O(1)$
