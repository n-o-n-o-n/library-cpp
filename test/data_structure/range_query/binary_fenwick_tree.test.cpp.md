---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/binary_fenwick_tree.hpp
    title: Binary Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/data_structure/range_query/binary_fenwick_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\n\
    #line 2 \"src/data_structure/range_query/binary_fenwick_tree.hpp\"\n#include <cassert>\n\
    #include <numeric>\n#include <vector>\nusing namespace std;\n\nstruct binary_fenwick_tree\
    \ {\n    binary_fenwick_tree() : binary_fenwick_tree(0) {}\n    binary_fenwick_tree(int\
    \ _n) : binary_fenwick_tree(vector<int>(_n, 0)) {}\n    template<typename T>\n\
    \    binary_fenwick_tree(const vector<T> &_v) : n(_v.size()) {\n        sz = (n\
    \ + 63) >> 6;\n        bit = vector<unsigned long long>(sz, 0);\n        d = v\
    \ = vector<int>(sz, 0);\n        for (int p = 0; p < n; p++) {\n            if\
    \ (_v[p]) {\n                int i = p >> 6, j = p & 63;\n                bit[i]\
    \ |= 1ULL << j;\n            }\n        }\n        for (int i = 1; i <= sz; i++)\
    \ {\n            v[i - 1] = __builtin_popcountll(bit[i - 1]);\n            d[i\
    \ - 1] += v[i - 1];\n            int j = i + (i & -i);\n            if (j <= sz)\
    \ d[j - 1] += d[i - 1];\n        }\n    }\n    void set(int p) {\n        assert(0\
    \ <= p && p < n);\n        int i = p >> 6, j = p & 63;\n        if ((bit[i] >>\
    \ j & 1) == 0) {\n            bit[i] |= 1ULL << j;\n            fw_update(i);\n\
    \        }\n    }\n    void reset(int p) {\n        assert(0 <= p && p < n);\n\
    \        int i = p >> 6, j = p & 63;\n        if (bit[i] >> j & 1) {\n       \
    \     bit[i] &= ~(1uLL << j);\n            fw_update(i);\n        }\n    }\n \
    \   void flip(int p) {\n        assert(0 <= p && p < n);\n        int i = p >>\
    \ 6, j = p & 63;\n        bit[i] ^= 1ULL << j;\n        fw_update(i);\n    }\n\
    \    bool test(int p) const {\n        assert(0 <= p && p < n);\n        return\
    \ bit[p >> 6] >> (p & 63) & 1;\n    }\n    int count(int l, int r) const {\n \
    \       assert(0 <= l && l <= r && r <= n);\n        if (l == r) return 0;\n \
    \       int il = l >> 6, jl = l & 63;\n        int ir = r >> 6, jr = r & 63;\n\
    \        if (il == ir) {\n            return __builtin_popcountll((bit[il] >>\
    \ jl) & mask(jr - jl));\n        }\n        int res = fw_sum(ir) - fw_sum(il);\n\
    \        res -= __builtin_popcountll(bit[il] & mask(jl));\n        if (jr) res\
    \ += __builtin_popcountll(bit[ir] & mask(jr));\n        return res;\n    }\n \
    \   bool all(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        return count(l, r) == r - l;\n    }\n    bool any(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        return count(l, r) >\
    \ 0;\n    }\n    bool none(int l, int r) const {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        return count(l, r) == 0;\n    }\n    int kth_element(int\
    \ k) const {\n        assert(k >= 0);\n        if (k >= n) return -1;\n      \
    \  int x = k + 1;\n        int p = fw_lower_bound(x);\n        if (p == sz) return\
    \ -1;\n        int l = 0, r = 64;\n        while (r - l > 1) {\n            int\
    \ m = (l + r) >> 1;\n            (__builtin_popcountll(bit[p] & mask(m)) < x ?\
    \ l : r) = m;\n        }\n        return (p << 6) ^ l;\n    }\n    int next_element(int\
    \ p) const {\n        assert(0 <= p && p < n);\n        return kth_element(count(0,\
    \ p));\n    }\n    int prev_element(int p) const {\n        assert(0 <= p && p\
    \ < n);\n        int x = count(0, p + 1);\n        return x == 0 ? -1 : kth_element(x\
    \ - 1);\n    }\nprivate:\n    int n, sz;\n    vector<unsigned long long> bit;\n\
    \    vector<int> d, v;\n    static constexpr unsigned long long mask(int m) {\n\
    \        return (1ULL << m) - 1;\n    }\n    void fw_update(int p) {\n       \
    \ int x = __builtin_popcountll(bit[p]) - v[p];\n        v[p] += x;\n        for\
    \ (p++; p <= sz; p += p & -p) {\n            d[p - 1] += x;\n        }\n    }\n\
    \    int fw_sum(int p) const {\n        int res = 0;\n        while (p > 0) {\n\
    \            res += d[p - 1];\n            p -= p & -p;\n        }\n        return\
    \ res;\n    }\n    int fw_lower_bound(int &x) const {\n        int r = 0, p =\
    \ 1;\n        while ((p << 1) <= sz) p <<= 1;\n        while (p > 0) {\n     \
    \       if (r + p <= sz && d[r + p - 1] < x) {\n                r += p;\n    \
    \            x -= d[r - 1];\n            }\n            p >>= 1;\n        }\n\
    \        return r;\n    }\n};\n#line 4 \"test/data_structure/range_query/binary_fenwick_tree.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    string T;\n    cin\
    \ >> T;\n    binary_fenwick_tree fw(N);\n    for (int i = 0; i < N; i++) {\n \
    \       if (T[i] == '1') fw.set(i);\n    }\n    while (Q--) {\n        int t,\
    \ k;\n        cin >> t >> k;\n        if (t == 0) {\n            fw.set(k);\n\
    \        } else if (t == 1) {\n            fw.reset(k);\n        } else if (t\
    \ == 2) {\n            cout << fw.test(k) << '\\n';\n        } else if (t == 3)\
    \ {\n            cout << fw.next_element(k) << '\\n';\n        } else {\n    \
    \        cout << fw.prev_element(k) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    \n#include \"../../../src/data_structure/range_query/binary_fenwick_tree.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n  \
    \  cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    string T;\n    cin\
    \ >> T;\n    binary_fenwick_tree fw(N);\n    for (int i = 0; i < N; i++) {\n \
    \       if (T[i] == '1') fw.set(i);\n    }\n    while (Q--) {\n        int t,\
    \ k;\n        cin >> t >> k;\n        if (t == 0) {\n            fw.set(k);\n\
    \        } else if (t == 1) {\n            fw.reset(k);\n        } else if (t\
    \ == 2) {\n            cout << fw.test(k) << '\\n';\n        } else if (t == 3)\
    \ {\n            cout << fw.next_element(k) << '\\n';\n        } else {\n    \
    \        cout << fw.prev_element(k) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/data_structure/range_query/binary_fenwick_tree.hpp
  isVerificationFile: true
  path: test/data_structure/range_query/binary_fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/range_query/binary_fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/range_query/binary_fenwick_tree.test.cpp
- /verify/test/data_structure/range_query/binary_fenwick_tree.test.cpp.html
title: test/data_structure/range_query/binary_fenwick_tree.test.cpp
---
