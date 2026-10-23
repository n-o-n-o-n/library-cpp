---
title: Compress
documentation_of: //src/misc/compress.hpp
---

座圧.

## compress

```
vector<int> compress(vector<T> v)
auto compress(vector<T> a, Ts ...z)
```

- 1 つの列を渡すと, 各値を順位に置き換えた `vector<int>` を返す
- 複数の列を渡すと, 全列に共通の順位で置き換えた結果を入力順の `tuple` で返す
- 入力の列は変更しない
- 全列の要素数の合計を $n$ として $O(n\log n)$

## compress_inplace

```
int compress_inplace(vector<T> &a, Ts &...z)
```

- 全列に共通の順位で各要素を置き換える
- `T` は順位を代入できる型とする
- 返り値は集合としてのサイズ
- 全列の要素数の合計を $n$ として $O(n\log n)$
