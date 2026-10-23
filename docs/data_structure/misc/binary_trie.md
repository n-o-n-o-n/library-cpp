---
title: Binary Trie
documentation_of: //src/data_structure/misc/binary_trie.hpp
---

非負整数の集合をビット列の Trie で管理する.

管理する集合を $S$ とし, $S\oplus x=\{x\oplus s \mid s \in S\}$ と定義する.

$x=$ `xor_val` $, L=$ `LOG` とし, 格納する値と $x$ は $0$ 以上 $2^L$ 未満とする.

## Constructor

```
binary_trie<T, LOG> bt
```

- 空の集合を作る
- `T` は整数型, `LOG` は扱う値のビット数で, 省略時は `numeric_limits<T>::digits`

## size

```
int size()
```

- $|S|$ を返す
- $O(1)$

## track

```
array<int, LOG> track(T x)
```

- $x$ の各ビットに沿って通るノードの番号を上位ビットから順に返す
- 枝が存在しない部分は $-1$ を返す
- $O(L)$

## insert

```
array<int, LOG> insert(T x)
```

- $x$ を挿入し, `track(x)` を返す
- $x$ が既に含まれる場合は集合を変更しない
- $O(L)$

## erase

```
void erase(T x)
```

- $x$ を削除する
- $x$ が含まれない場合は何もしない
- $O(L)$

## contains

```
bool contains(T x)
```

- $x$ が含まれる場合に `true` を返す
- $O(L)$

## kth_smallest

```
T kth_smallest(int k, T xor_val = 0)
```

- $S\oplus x$ を昇順に並べ, $k$ 番目 (0-indexed) の値を返す
- $k < |S|$ が必要
- $O(L)$

## kth_largest

```
T kth_largest(int k, T xor_val = 0)
```

- $S\oplus x$ を降順に並べ, $k$ 番目 (0-indexed) の値を返す
- $k < |S|$ が必要
- $O(L)$

## min

```
T min(T xor_val = 0)
```

- $S\oplus x$ の最小値を返す
- $S\ne \emptyset$ が必要
- $O(L)$

## max

```
T max(T xor_val = 0)
```

- $S\oplus x$ の最大値を返す
- $S\ne \emptyset$ が必要
- $O(L)$

## mex

```
T mex(T xor_val = 0)
```

- $S\oplus x$ の mex を返す
- $O(L)$

## lower_count

```
int lower_count(T k, T xor_val = 0)
```

- $S\oplus x$ に含まれる $k$ 未満の値の個数を返す
- $O(L)$

## upper_count

```
int upper_count(T k, T xor_val = 0)
```

- $S\oplus x$ に含まれる $k$ より大きい値の個数を返す
- $O(L)$

## prev_val

```
T prev_val(T upper, T xor_val = 0)
```

- $S\oplus x$ に含まれる `upper` 未満の値の最大値を返す
- 存在しない場合は $-1$ を返す
- $O(L)$

## next_val

```
T next_val(T lower, T xor_val = 0)
```

- $S\oplus x$ に含まれる `lower` より大きい値の最小値を返す
- 存在しない場合は $-1$ を返す
- $O(L)$
