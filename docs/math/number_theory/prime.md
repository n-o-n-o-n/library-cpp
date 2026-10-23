---
title: Prime
documentation_of: //src/math/number_theory/prime.hpp
---

素数判定, 素因数分解, 原始根の計算を行う.
`T` は `int`, `long long`, または対応する符号なし整数型を想定する.
`prime::` から呼び出せる `constexpr` 関数テンプレートで, C++20 以降で利用できる.

## is_prime

```
bool prime::is_prime<T>(T n)
```

- $n$ が素数なら `true`, そうでなければ `false` を返す
- $n \le 1$ では `false` を返す
- $O(\log n)$

## prime_factor

```
vector<T> prime::prime_factor<T>(T n)
```

- $n$ の異なる素因数を昇順に返す
- 期待 $O(n^{1/4}\log n)$ 程度
- 実行時間は入力に依存する

## factorise

```
vector<pair<T, int>> prime::factorise<T>(T n)
```

- $n$ を素因数分解し, 素因数の昇順に返す
- 計算量は `prime_factor` と同程度

## primitive_root

```
T prime::primitive_root<T>(T m)
```

- 素数 $m$ を法とする原始根を一つ返す
- 最小の原始根とは限らない
- $m - 1$ の素因数分解を除き, 候補あたり $O(r\log m)$
- $r$ は $m - 1$ の異なる素因数の個数

## enumerate_divisors

```
vector<T> prime::enumerate_divisors<T>(T m)
```

- $m$ の正の約数を昇順に返す
- 素因数分解を除き, $O(d\log d)$
- $d$ は $m$ の正の約数の個数
