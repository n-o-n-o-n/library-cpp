---
title: Merge And Unique
documentation_of: //src/misc/merge_and_unique.hpp
---

複数の列に含まれる値をまとめ, 重複を除いた昇順の列を作る.

## merge_and_unique

```
vector<T> merge_and_unique(vector<T> a, Ts ...z)
```

- 全列の要素を集め, 重複を除いた昇順の `vector<T>` を返す
- 全列の要素数の合計を $n$ として $O(n\log n)$
