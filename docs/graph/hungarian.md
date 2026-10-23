---
title: Hungarian
documentation_of: //src/graph/hungarian.hpp
---

重み付き完全二部グラフの最小重み最大マッチングを求める.

## hungarian

```
template<typename T>
vector<pair<int, int>> hungarian(vector<vector<T>> a)
```

- $a_{i,j}$ を左頂点 $i$ と右頂点 $j$ を結ぶ辺のコストとする
- 要素数 $\min(h, w)$ の最小重みマッチングを返す
- 返り値の各組 $(i, j)$ はマッチした辺を表し, $i$ の昇順に並ぶ
- $O(\min(h, w)^2\max(h, w))$
