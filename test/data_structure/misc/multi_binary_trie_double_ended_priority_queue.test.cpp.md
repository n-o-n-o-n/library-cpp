---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/misc/multi_binary_trie.hpp
    title: Multi Binary Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/data_structure/misc/multi_binary_trie_double_ended_priority_queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#line 2 \"src/data_structure/misc/multi_binary_trie.hpp\"\n#include <array>\n\
    #include <cassert>\n#include <vector>\n#include <limits>\nusing namespace std;\n\
    \ntemplate<typename T, int LOG = numeric_limits<T>::digits>\nstruct multi_binary_trie\
    \ {\n    multi_binary_trie() : all(0), sub(1, 0), cnt(1, 0), child(1, e()) {}\n\
    \    int size() const { return all; }\n    array<int, LOG> track(T x) const {\n\
    \        int pos = 0;\n        array<int, LOG> res;\n        res.fill(-1);\n \
    \       for (int i = LOG - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n\
    \            int nxt = child[pos][c];\n            if (nxt == -1) break;\n   \
    \         pos = nxt;\n            res[LOG - 1 - i] = pos;\n        }\n       \
    \ return res;\n    }\n    array<int, LOG> insert(T x) {\n        int pos = 0;\n\
    \        for (int i = LOG - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n\
    \            int nxt = child[pos][c];\n            if (nxt == -1) {\n        \
    \        nxt = sub.size();\n                sub.push_back(0);\n              \
    \  cnt.push_back(0);\n                child.push_back(e());\n            }\n \
    \           child[pos][c] = nxt;\n            pos = nxt;\n        }\n        auto\
    \ tr = track(x);\n        int p = tr.back();\n        for (int i : tr) cnt[i]++;\n\
    \        all++;\n        if (sub[p] == 0) {\n            for (int i : tr) sub[i]++;\n\
    \        }\n        return tr;\n    }\n    void erase(T x) {\n        auto tr\
    \ = track(x);\n        int p = tr.back();\n        if (p == -1 || sub[p] == 0)\
    \ return;\n        for (int i : tr) cnt[i]--;\n        all--;\n        if (cnt[p]\
    \ == 0) {\n            for (int i : tr) sub[i]--;\n        }\n    }\n    // return\
    \ (x in S ? true : false);\n    bool contains(T x) const {\n        int p = track(x).back();\n\
    \        return (p != -1) && (sub[p] > 0);\n    }\n    int count(T x) const {\n\
    \        int p = track(x).back();\n        return p == -1 ? 0 : cnt[p];\n    }\n\
    \    T kth_smallest(int k, T xor_val = 0) const {\n        assert(0 <= k && k\
    \ < size());\n        int pos = 0;\n        T res = 0;\n        for (int i = LOG\
    \ - 1; i >= 0; i--) {\n            res *= 2;\n            int c = xor_val >> i\
    \ & 1;\n            int nxt = child[pos][c];\n            if (nxt != -1) {\n \
    \               if (0 <= k && k < cnt[nxt]) {\n                    pos = nxt;\n\
    \                    continue;\n                }\n                k -= cnt[nxt];\n\
    \            }\n            pos = child[pos][1 - c];\n            res++;\n   \
    \     }\n        return res;\n    }\n    T kth_largest(int k, T xor_val = 0) const\
    \ {\n        assert(0 <= k && k < size());\n        return kth_smallest(size()\
    \ - 1 - k, xor_val);\n    }\n    T min(T xor_val = 0) const {\n        assert(size());\n\
    \        return kth_smallest(0, xor_val);\n    }\n    T max(T xor_val = 0) const\
    \ {\n        assert(size());\n        return kth_largest(0, xor_val);\n    }\n\
    \    T mex(T xor_val = 0) const {\n        if (size() == 0) return T(0);\n   \
    \     int pos = 0;\n        T res = 0;\n        for (int i = LOG - 1; i >= 0;\
    \ i--) {\n            res *= 2;\n            int c = xor_val >> i & 1;\n     \
    \       int nxt = child[pos][c];\n            if (nxt == -1) return res << i;\n\
    \            if (sub[nxt] < (T(1) << i)) {\n                pos = nxt;\n     \
    \           continue;\n            }\n            res++;\n            if (child[pos][1\
    \ - c] == -1) return res << i;\n            pos = child[pos][1 - c];\n       \
    \ }\n        return res + (sub[pos] != 0);\n    }\n    // #{s in S | s^x < k}\n\
    \    int lower_count(T x, T xor_val = 0) const {\n        if (x <= 0) return 0;\n\
    \        if constexpr (LOG < numeric_limits<T>::digits) {\n            if (x >=\
    \ (T(1) << LOG)) return size();\n        }\n        int pos = 0;\n        int\
    \ res = 0;\n        for (int i = LOG - 1; i >= 0; i--) {\n            if (pos\
    \ == -1) break;\n            int cx = (x >> i) & 1;\n            int cxor = (xor_val\
    \ >> i) & 1;\n            int nxt0 = child[pos][cxor];\n            int nxt1 =\
    \ child[pos][1 - cxor];\n            if (cx == 1) {\n                if (nxt0\
    \ != -1) {\n                    res += cnt[nxt0];\n                }\n       \
    \         pos = nxt1;\n            } else {\n                pos = nxt0;\n   \
    \         }\n        }\n        return res;\n    }\n    // #{s in S | s^x > k}\n\
    \    int upper_count(T k, T xor_val = 0) const {\n        if (k == numeric_limits<T>::max())\
    \ return 0;\n        return size() - lower_count(k + 1, xor_val);\n    }\n   \
    \ // max{s^x | s^x < upper }\n    T prev_val(T upper, T xor_val = 0) const {\n\
    \        int k = lower_count(upper, xor_val);\n        return k == 0 ? T(-1) :\
    \ kth_smallest(k - 1, xor_val);\n    }\n    // min{s^x | s^x > lower }\n    T\
    \ next_val(T lower, T xor_val = 0) const {\n        if (lower == numeric_limits<T>::max())\
    \ return T(-1);\n        int k = lower_count(lower + 1, xor_val);\n        return\
    \ k == size() ? T(-1) : kth_smallest(k, xor_val);\n    }\nprivate:\n    int all;\n\
    \    vector<int> sub, cnt;\n    vector<array<int, 2>> child;\n    constexpr array<int,\
    \ 2> e() {\n        return {-1, -1};\n    }\n};\n#line 4 \"test/data_structure/misc/multi_binary_trie_double_ended_priority_queue.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    constexpr int offset\
    \ = 1000000000;\n    multi_binary_trie<int> mbt;\n    for (int a; N--; ) {\n \
    \       cin >> a;\n        mbt.insert(a + offset);\n    }\n    while (Q--) {\n\
    \        int t;\n        cin >> t;\n        if (t == 0) {\n            int x;\n\
    \            cin >> x;\n            mbt.insert(x + offset);\n        } else if\
    \ (t == 1) {\n            int mn = mbt.min();\n            cout << mn - offset\
    \ << '\\n';\n            mbt.erase(mn);\n        } else {\n            int mx\
    \ = mbt.max();\n            cout << mx - offset << '\\n';\n            mbt.erase(mx);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../../src/data_structure/misc/multi_binary_trie.hpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    constexpr int offset = 1000000000;\n \
    \   multi_binary_trie<int> mbt;\n    for (int a; N--; ) {\n        cin >> a;\n\
    \        mbt.insert(a + offset);\n    }\n    while (Q--) {\n        int t;\n \
    \       cin >> t;\n        if (t == 0) {\n            int x;\n            cin\
    \ >> x;\n            mbt.insert(x + offset);\n        } else if (t == 1) {\n \
    \           int mn = mbt.min();\n            cout << mn - offset << '\\n';\n \
    \           mbt.erase(mn);\n        } else {\n            int mx = mbt.max();\n\
    \            cout << mx - offset << '\\n';\n            mbt.erase(mx);\n     \
    \   }\n    }\n}\n"
  dependsOn:
  - src/data_structure/misc/multi_binary_trie.hpp
  isVerificationFile: true
  path: test/data_structure/misc/multi_binary_trie_double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/misc/multi_binary_trie_double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/misc/multi_binary_trie_double_ended_priority_queue.test.cpp
- /verify/test/data_structure/misc/multi_binary_trie_double_ended_priority_queue.test.cpp.html
title: test/data_structure/misc/multi_binary_trie_double_ended_priority_queue.test.cpp
---
