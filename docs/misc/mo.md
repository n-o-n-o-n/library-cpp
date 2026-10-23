---
title: Mo
documentation_of: //src/misc/mo.hpp
---

列 $a$ に対する区間クエリをオフラインで扱う. 計算量はラムダ式内部での計算を無視している.

## Constructor

```
MO mo(int n, int q = 0)
```

- $n$ は $a$ の長さ
- $q$ はクエリ数

## add_query

```
void add_query(int l, int r)
```

- クエリ $[l,r)$ を追加する

## run

```
void run(exl, exr, shl, shr, out)
void run(ex, sh, out)
```

- クエリを処理する
- 各引数はラムダ式の関数が想定される
- `exl(i)` は左端へ $a_i$ を追加し, `exr(i)` は右端へ $a_i$ を追加する
- `shl(i)` は左端から $a_i$ を削除し, `shr(i)` は右端から $a_i$ を削除する
- `out(i)` は$i$ 番目に追加されたクエリの答えを記録する
- `exl` と `exr`, `shl` と `shr` が同じ処理をする場合は `ex`, `sh`, `out` のみで呼ぶこともできる
- $O(n\sqrt{q})$
