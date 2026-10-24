---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/set/top_k_set.hpp
    title: Top K Set
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/3298
    links:
    - https://yukicoder.me/problems/no/3298
  bundledCode: "#line 1 \"test/data_structure/set/top_k_set.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/3298\"\n\n#line 2 \"src/data_structure/set/top_k_set.hpp\"\
    \n#include <cassert>\n#include <set>\nusing namespace std;\n\ntemplate<typename\
    \ T1, typename T2 = long long, typename Compare = less<T1>>\nstruct top_k_set\
    \ {\n    top_k_set(int _k) : k(_k), lower_sum(0) {}\n    void insert(T1 x) {\n\
    \        if (k > 0 && ((int)lower.size() < k || Compare()(x, *prev(lower.end()))))\
    \ {\n            lower_sum += x;\n            lower.insert(x);\n        } else\
    \ {\n            upper.insert(x);\n        }\n        normalize();\n    }\n  \
    \  void erase(T1 x) {\n        auto it = lower.find(x);\n        if (it != lower.end())\
    \ {\n            lower_sum -= *it;\n            lower.erase(it);\n        } else\
    \ {\n            it = upper.find(x);\n            assert(it != upper.end());\n\
    \            upper.erase(it);\n        }\n        normalize();\n    }\n    T1\
    \ kth_val() const {\n        assert((int)lower.size() == k);\n        return *prev(lower.end());\n\
    \    }\n    T2 sum() const {\n        return lower_sum;\n    }\nprivate:\n   \
    \ int k;\n    multiset<T1, Compare> lower, upper;\n    T2 lower_sum;\n    void\
    \ normalize() {\n        while ((int)lower.size() > k) {\n            auto it\
    \ = prev(lower.end());\n            upper.insert(*it);\n            lower_sum\
    \ -= *it;\n            lower.erase(it);\n        }\n        while ((int)lower.size()\
    \ < k && upper.size()) {\n            auto it = upper.begin();\n            lower_sum\
    \ += *it;\n            lower.insert(*it);\n            upper.erase(it);\n    \
    \    }\n    }\n};\n#line 4 \"test/data_structure/set/top_k_set.test.cpp\"\n\n\
    #include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, K, Q;\n    cin >> N >> K >> Q;\n    top_k_set<long long> S(K);\n \
    \   for (int i = 0; i < N; i++) {\n        long long a;\n        cin >> a;\n \
    \       S.insert(a);\n    }\n    while (Q--) {\n        int t;\n        cin >>\
    \ t;\n        if (t == 1) {\n            long long x;\n            cin >> x;\n\
    \            S.insert(x);\n        } else if (t == 2) {\n            long long\
    \ y;\n            cin >> y;\n            long long x = S.kth_val();\n        \
    \    S.erase(x);\n            S.insert(x + y);\n        } else {\n           \
    \ cout << S.kth_val() << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/3298\"\n\n#include \"\
    ../../../src/data_structure/set/top_k_set.hpp\"\n\n#include <iostream>\n\nint\
    \ main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N,\
    \ K, Q;\n    cin >> N >> K >> Q;\n    top_k_set<long long> S(K);\n    for (int\
    \ i = 0; i < N; i++) {\n        long long a;\n        cin >> a;\n        S.insert(a);\n\
    \    }\n    while (Q--) {\n        int t;\n        cin >> t;\n        if (t ==\
    \ 1) {\n            long long x;\n            cin >> x;\n            S.insert(x);\n\
    \        } else if (t == 2) {\n            long long y;\n            cin >> y;\n\
    \            long long x = S.kth_val();\n            S.erase(x);\n           \
    \ S.insert(x + y);\n        } else {\n            cout << S.kth_val() << '\\n';\n\
    \        }\n    }\n}"
  dependsOn:
  - src/data_structure/set/top_k_set.hpp
  isVerificationFile: true
  path: test/data_structure/set/top_k_set.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 11:13:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/set/top_k_set.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/set/top_k_set.test.cpp
- /verify/test/data_structure/set/top_k_set.test.cpp.html
title: test/data_structure/set/top_k_set.test.cpp
---
