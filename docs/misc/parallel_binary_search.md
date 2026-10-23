---
title: Parallel Binary Search
documentation_of: //src/misc/parallel_binary_search.hpp
---

並列二分探索. 計算量はラムダ式内部での計算を無視している.

## parallel_binary_search

```
vector<int> parallel_binary_search(int t, int q, act, query, reset)
```

- $t$ 個の操作と $q$ 個の条件を扱う
- `act`, `query`, `reset` はラムダ式関数が想定される
- `act` は $i$ を受け取り, $i$ 番目の操作を現在の状態に適用する
- `query` は $j$ を受け取り, 現在の状態で $j$ 番目の条件が成立するかを返す
- `reset` は操作を一つも適用していない初期状態に戻す
- 各条件は操作を追加するにつれ `false` から `true` にのみ変化するものとする
- 戻り値の $j$ 番目の値は, $j$ 番目の条件が初めて成立する操作の添字とする
- 最後まで成立しない条件には $t$ を返す
- `reset` の後, `act` は $0$ から $t-1$ の順に呼ばれる
- $O((t+q)\log t)$
- 使用領域は $O(t+q)$
