---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/rolling_hash_static.hpp
    title: src/string/rolling_hash_static.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/string/rolling_hash_static.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#line 2 \"src/string/rolling_hash_static.hpp\"\
    \n#include <array>\n#include <cassert>\n#include <string>\n#include <vector>\n\
    using namespace std;\n\nstruct rolling_hash {\n    static long long base, p, q;\n\
    \    static array<long long, 3> inv;\n    static constexpr array<long long, 3>\
    \ mod = {1000274903LL, 1000274927LL, 1000274953LL};\n    static vector<array<long\
    \ long, 3>> pow, inv_pow;\n    static void set_base(int b) {\n        assert(base\
    \ == -1);\n        assert(2 <= b && b <= int(1e9));\n        base = b;\n     \
    \   p = (b + (b >> 5)) % 2749;\n        q = (b + (b >> 9)) % 274;\n        for\
    \ (int j = 0; j < 3; j++) {\n            inv[j] = mod_inv(base, mod[j]);\n   \
    \     }\n    }\n    rolling_hash(const string &s) {\n        assert(base != -1);\n\
    \        int n = s.size();\n        init(n);\n        d.resize(n + 1);\n     \
    \   d[0].fill(0);\n        for (int i = 0; i < n; i++) {\n            long long\
    \ hs = inner_hash(s[i]);\n            for (int j = 0; j < 3; j++) {\n        \
    \        d[i + 1][j] = (d[i][j] + pow[i][j] * hs) % mod[j];\n            }\n \
    \       }\n    }\n    array<long long, 3> prod(int l, int r) {\n        array<long\
    \ long, 3> res;\n        for (int j = 0; j < 3; j++) {\n            res[j] = d[r][j]\
    \ - d[l][j];\n            if (res[j] < 0) res[j] += mod[j];\n            res[j]\
    \ = (res[j] * inv_pow[l][j]) % mod[j];\n        }\n        return res;\n    }\n\
    private:\n    vector<array<long long, 3>> d;\n    static long long mod_inv(long\
    \ long x, long long m) {\n        long long a = x, r = 1, k = m - 2;\n       \
    \ while (k > 0) {\n            if (k & 1) r = (r * a) % m;\n            a = (a\
    \ * a) % m;\n            k >>= 1;\n        }\n        return r;\n    }\n    static\
    \ void init(int n) {\n        int sz = pow.size();\n        if (n + 1 < sz) return;\n\
    \        n = max(n + 1, 2 * sz);\n        pow.resize(n);\n        inv_pow.resize(n);\n\
    \        for (int i = sz; i < n; i++) {\n            for (int j = 0; j < 3; j++)\
    \ {\n                pow[i][j] = (pow[i - 1][j] * base) % mod[j];\n          \
    \      inv_pow[i][j] = (inv_pow[i - 1][j] * inv[j]) % mod[j];\n            }\n\
    \        }\n    }\n    long long inner_hash(const char &c) const {\n        int\
    \ res = static_cast<int>(c);\n        res = (res + (res << 4)) + p;\n        res\
    \ = ((res << 2) ^ (res >> 3)) * q;\n        return res;\n    }\n};\ninline long\
    \ long rolling_hash::base(-1);\ninline long long rolling_hash::p(-1);\ninline\
    \ long long rolling_hash::q(-1);\ninline array<long long, 3> rolling_hash::inv({1,\
    \ 1, 1});\ninline vector<array<long long, 3>> rolling_hash::pow(1, {1, 1, 1});\n\
    inline vector<array<long long, 3>> rolling_hash::inv_pow(1, {1, 1, 1});\n#line\
    \ 4 \"test/string/rolling_hash_static.test.cpp\"\n\n#include <iostream>\n\nint\
    \ main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    string\
    \ S;\n    cin >> S;\n    int N = S.size();\n    rolling_hash::set_base(998244351);\n\
    \    rolling_hash rh(S);\n    for (int i = 0; i < N; i++) {\n        int l = 0,\
    \ r = N - i + 1;\n        while (r - l > 1) {\n            int m = (l + r) / 2;\n\
    \            auto h0 = rh.prod(0, m);\n            auto hi = rh.prod(i, i + m);\n\
    \            (h0 == hi ? l : r) = m;\n        }\n        cout << l << \" \\n\"\
    [i + 1 == N];\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../../src/string/rolling_hash_static.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    string S;\n\
    \    cin >> S;\n    int N = S.size();\n    rolling_hash::set_base(998244351);\n\
    \    rolling_hash rh(S);\n    for (int i = 0; i < N; i++) {\n        int l = 0,\
    \ r = N - i + 1;\n        while (r - l > 1) {\n            int m = (l + r) / 2;\n\
    \            auto h0 = rh.prod(0, m);\n            auto hi = rh.prod(i, i + m);\n\
    \            (h0 == hi ? l : r) = m;\n        }\n        cout << l << \" \\n\"\
    [i + 1 == N];\n    }\n}"
  dependsOn:
  - src/string/rolling_hash_static.hpp
  isVerificationFile: true
  path: test/string/rolling_hash_static.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/string/rolling_hash_static.test.cpp
layout: document
redirect_from:
- /verify/test/string/rolling_hash_static.test.cpp
- /verify/test/string/rolling_hash_static.test.cpp.html
title: test/string/rolling_hash_static.test.cpp
---
