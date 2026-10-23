---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/misc/parallel_binary_search.test.cpp
    title: test/misc/parallel_binary_search.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/past20-open/submissions/71648427
  bundledCode: "#line 2 \"src/misc/parallel_binary_search.hpp\"\n#include <vector>\n\
    using namespace std;\n\n// \u4F7F\u3044\u65B9\u306F\u3053\u308C\u3092\u53C2\u7167\
    : https://atcoder.jp/contests/past20-open/submissions/71648427 \ntemplate<typename\
    \ A, typename Q, typename R>\nvector<int> parallel_binary_search(int t, int q,\
    \ const A &act, const Q &query, const R &reset) {\n    vector<int> l(q, -1), r(q,\
    \ t);\n    for (int p = 1; p <= t; p *= 2) {\n        reset();\n        vector<int>\
    \ m(q);\n        vector<vector<int>> qs(t);\n        for (int j = 0; j < q; j++)\
    \ {\n            m[j] = (l[j] + r[j]) / 2;\n            qs[m[j]].push_back(j);\n\
    \        }\n        for (int i = 0; i < t; i++) {\n            act(i);\n     \
    \       for (int j : qs[i]) (query(j) ? r[j] : l[j]) = m[j];\n        }\n    }\n\
    \    return r;\n}\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\n// \u4F7F\u3044\u65B9\
    \u306F\u3053\u308C\u3092\u53C2\u7167: https://atcoder.jp/contests/past20-open/submissions/71648427\
    \ \ntemplate<typename A, typename Q, typename R>\nvector<int> parallel_binary_search(int\
    \ t, int q, const A &act, const Q &query, const R &reset) {\n    vector<int> l(q,\
    \ -1), r(q, t);\n    for (int p = 1; p <= t; p *= 2) {\n        reset();\n   \
    \     vector<int> m(q);\n        vector<vector<int>> qs(t);\n        for (int\
    \ j = 0; j < q; j++) {\n            m[j] = (l[j] + r[j]) / 2;\n            qs[m[j]].push_back(j);\n\
    \        }\n        for (int i = 0; i < t; i++) {\n            act(i);\n     \
    \       for (int j : qs[i]) (query(j) ? r[j] : l[j]) = m[j];\n        }\n    }\n\
    \    return r;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/misc/parallel_binary_search.hpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/misc/parallel_binary_search.test.cpp
documentation_of: src/misc/parallel_binary_search.hpp
layout: document
title: Parallel Binary Search
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
