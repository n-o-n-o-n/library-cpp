---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/misc/binary_trie.hpp
    title: Binary Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/data_structure/misc/binary_trie.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 2 \"src/data_structure/misc/binary_trie.hpp\"\
    \n#include <array>\n#include <cassert>\n#include <vector>\n#include <limits>\n\
    using namespace std;\n\ntemplate<typename T, int LOG = numeric_limits<T>::digits>\n\
    struct binary_trie {\n    binary_trie() : all(0), sub(1, 0), child(1, e()) {}\n\
    \    int size() const { return all; }\n    array<int, LOG> track(T x) const {\n\
    \        int pos = 0;\n        array<int, LOG> res;\n        res.fill(-1);\n \
    \       for (int i = LOG - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n\
    \            int nxt = child[pos][c];\n            if (nxt == -1) break;\n   \
    \         pos = nxt;\n            res[LOG - 1 - i] = pos;\n        }\n       \
    \ return res;\n    }\n    array<int, LOG> insert(T x) {\n        int pos = 0;\n\
    \        for (int i = LOG - 1; i >= 0; i--) {\n            int c = x >> i & 1;\n\
    \            int nxt = child[pos][c];\n            if (nxt == -1) {\n        \
    \        nxt = sub.size();\n                sub.push_back(0);\n              \
    \  child.push_back(e());\n            }\n            child[pos][c] = nxt;\n  \
    \          pos = nxt;\n        }\n        auto tr = track(x);\n        int p =\
    \ tr.back();\n        if (sub[p] == 0) {\n            for (int i : tr) sub[i]++;\n\
    \            all++;\n        }\n        return tr;\n    }\n    void erase(T x)\
    \ {\n        auto tr = track(x);\n        int p = tr.back();\n        if (p ==\
    \ -1 || sub[p] == 0) return;\n        for (int i : tr) sub[i]--;\n        all--;\n\
    \    }\n    // return (x in S ? true : false);\n    bool contains(T x) const {\n\
    \        int p = track(x).back();\n        return (p != -1) && (sub[p] > 0);\n\
    \    }\n    T kth_smallest(int k, T xor_val = 0) const {\n        assert(0 <=\
    \ k && k < size());\n        int pos = 0;\n        T res = 0;\n        for (int\
    \ i = LOG - 1; i >= 0; i--) {\n            res *= 2;\n            int c = xor_val\
    \ >> i & 1;\n            int nxt = child[pos][c];\n            if (nxt != -1)\
    \ {\n                if (0 <= k && k < sub[nxt]) {\n                    pos =\
    \ nxt;\n                    continue;\n                }\n                k -=\
    \ sub[nxt];\n            }\n            pos = child[pos][1 - c];\n           \
    \ res++;\n        }\n        return res;\n    }\n    T kth_largest(int k, T xor_val\
    \ = 0) const {\n        assert(0 <= k && k < size());\n        return kth_smallest(size()\
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
    \ != -1) {\n                    res += sub[nxt0];\n                }\n       \
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
    \    vector<int> sub;\n    vector<array<int, 2>> child;\n    constexpr array<int,\
    \ 2> e() {\n        return {-1, -1};\n    }\n};\n#line 4 \"test/data_structure/misc/binary_trie.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    binary_trie<int, 30> bt;\n    int Q;\n    cin >> Q;\n\
    \    for (int t, x; Q--; ) {\n        cin >> t >> x;\n        if (t == 0) {\n\
    \            bt.insert(x);\n        } else if (t == 1) {\n            bt.erase(x);\n\
    \        } else {\n            cout << bt.min(x) << '\\n';\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../../src/data_structure/misc/binary_trie.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    binary_trie<int,\
    \ 30> bt;\n    int Q;\n    cin >> Q;\n    for (int t, x; Q--; ) {\n        cin\
    \ >> t >> x;\n        if (t == 0) {\n            bt.insert(x);\n        } else\
    \ if (t == 1) {\n            bt.erase(x);\n        } else {\n            cout\
    \ << bt.min(x) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/data_structure/misc/binary_trie.hpp
  isVerificationFile: true
  path: test/data_structure/misc/binary_trie.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/misc/binary_trie.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/misc/binary_trie.test.cpp
- /verify/test/data_structure/misc/binary_trie.test.cpp.html
title: test/data_structure/misc/binary_trie.test.cpp
---
