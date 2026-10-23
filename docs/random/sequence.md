---
title: Random Sequence
documentation_of: //src/random/sequence.hpp
---

`rng` 名前空間で乱数列や順列を生成する.

## shuffle

```
void rng::shuffle(vector<T> &v)
```

- $v$ の要素をシャッフルする

## random_sequence

```
vector<T> rng::random_sequence(int n, T lo, T hi)
```

- $lo$ 以上 $hi$ 以下の整数を $n$ 個生成する

## random_increasing_sequence

```
vector<T> rng::random_increasing_sequence(int n, T lo, T hi, bool strict = false)
```

- $lo$ 以上 $hi$ 以下の整数からなる長さ $n$ の非減少列を生成する
- `strict` が `true` なら狭義単調増加列を生成する

## random_decreasing_sequence

```
vector<T> rng::random_decreasing_sequence(int n, T lo, T hi, bool strict = false)
```

- $lo$ 以上 $hi$ 以下の整数からなる長さ $n$ の非増加列を生成する
- `strict` が `true` なら狭義単調減少列を生成する

## random_permutation

```
vector<T> rng::random_permutation(int n, T v = 0)
```

- $v$ から $v+n-1$ までの整数を並べ替えた列を返す

## random_string

```
string rng::random_string(int n, char a, char z)
```

- `a` 以上 `z` 以下の文字からなる長さ $n$ の文字列を生成する
