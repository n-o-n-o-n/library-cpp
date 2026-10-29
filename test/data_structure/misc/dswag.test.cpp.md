---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/misc/dswag.hpp
    title: src/data_structure/misc/dswag.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':question:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/deque_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/deque_operate_all_composite
  bundledCode: "#line 1 \"test/data_structure/misc/dswag.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\n\n#line 2 \"\
    src/modint/modint.hpp\"\n#include <algorithm>\n#include <cassert>\nusing namespace\
    \ std;\n\ntemplate<unsigned int MOD>\nstruct modint {\n    constexpr modint()\
    \ : x(0) {}\n    template<typename T>\n    constexpr modint(T v) {\n        int\
    \ y = v % (int)mod();\n        if (y < 0) y += mod();\n        x = (unsigned int)y;\n\
    \    }\n    static constexpr modint raw(int v) {\n        modint a;\n        a.x\
    \ = v;\n        return a;\n    }\n    static constexpr int mod() { return MOD;\
    \ }\n    constexpr unsigned int val() const { return x; }\n    constexpr modint&\
    \ operator++() {\n        x++;\n        if (x == mod()) x = 0;\n        return\
    \ *this;\n    }\n    constexpr modint& operator--() {\n        if (x == 0) x =\
    \ mod();\n        x--;\n        return *this;\n    }\n    constexpr modint operator++(int)\
    \ {\n        modint res = *this;\n        ++*this;\n        return res;\n    }\n\
    \    constexpr modint operator--(int) {\n        modint res = *this;\n       \
    \ --*this;\n        return res;\n    }\n    constexpr modint& operator+=(const\
    \ modint &r) {\n        x += r.x;\n        if (x >= mod()) x -= mod();\n     \
    \   return *this;\n    }\n    constexpr modint& operator-=(const modint &r) {\n\
    \        x -= r.x;\n        if (x >= mod()) x += mod();\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint &r) {\n        unsigned\
    \ long long y = x;\n        y *= r.x;\n        x = (unsigned int)(y % mod());\n\
    \        return *this;\n    }\n    constexpr modint &operator/=(const modint &r)\
    \ {\n        return *this = *this * r.inv();\n    }\n    friend constexpr modint\
    \ operator+(const modint &a, const modint &b) {\n        return modint(a) += b;\n\
    \    }\n    friend constexpr modint operator-(const modint &a, const modint &b)\
    \ {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
    \ modint &a, const modint &b) {\n        return modint(a) *= b;\n    }\n    friend\
    \ constexpr modint operator/(const modint &a, const modint &b) {\n        return\
    \ modint(a) /= b;\n    }\n    friend constexpr bool operator==(const modint &a,\
    \ const modint &b) {\n        return a.x == b.x;\n    }\n    friend constexpr\
    \ bool operator!=(const modint &a, const modint &b) {\n        return a.x != b.x;\n\
    \    }\n    constexpr modint operator+() const { return *this; }\n    constexpr\
    \ modint operator-() const { return modint() - *this; }\n    constexpr modint\
    \ pow(long long k) const {\n        assert(k >= 0);\n        modint a = *this;\n\
    \        modint res = 1;\n        while (k > 0) {\n            if (k & 1) res\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint inv() const {\n        long long a = x, b\
    \ = mod(), u = 1, v = 0;\n        while (b > 0) {\n            long long t = a\
    \ / b;\n            a -= t * b;\n            swap(a, b);\n            u -= t *\
    \ v;\n            swap(u, v);\n        }\n        return modint(u);\n    }\nprivate:\n\
    \    unsigned int x;\n};\n#line 2 \"src/math/affine.hpp\"\n\ntemplate<typename\
    \ mint>\nstruct affine {\n    mint a, b;\n    affine() : a(1), b(0) {}\n    affine(const\
    \ mint &_a, const mint &_b) : a(_a), b(_b) {}\n    mint operator()(const mint\
    \ &x) const {\n        return a * x + b;\n    }\n    affine operator()(const affine\
    \ &f) const {\n        mint c = a * f.a;\n        mint d = a * f.b + b;\n    \
    \    return affine(c, d);\n    }\n};\n#line 4 \"src/data_structure/misc/dswag.hpp\"\
    \n#include <stack>\n#include <vector>\nusing namespace std;\n\ntemplate<typename\
    \ Monoid>\nstruct dswag {\n    using S = typename Monoid::S;\n    dswag() = default;\n\
    \    size_t size() const { return f1.size() + b1.size(); }\n    bool empty() const\
    \ { return size() == 0; }\n    S get() const { return Monoid::op(get_f(), get_b());\
    \ }\n    void push_front(const S &x) { push_f(x); }\n    void push_back(const\
    \ S &x) { push_b(x); }\n    void pop_front() {\n        assert(size());\n    \
    \    if (f1.empty()) normalize();\n        pop_f();\n    }\n    void pop_back()\
    \ {\n        assert(size());\n        if (b1.empty()) normalize();\n        pop_b();\n\
    \    }\nprivate:\n    stack<S> f1, f2, b1, b2;\n    void normalize() {\n     \
    \   int n = size();\n        int m = n / 2 + (f1.size() ? 0 : n & 1);\n      \
    \  vector<S> f, b;\n        while (f1.size()) {\n            f.push_back(f1.top());\n\
    \            pop_f();\n        }\n        while (b1.size()) {\n            b.push_back(b1.top());\n\
    \            pop_b();\n        }\n        reverse(b.begin(), b.end());\n     \
    \   copy(b.begin(), b.end(), back_inserter(f));\n        for (int i = m - 1; i\
    \ >= 0; i--) push_f(f[i]);\n        for (int i = m; i < n; i++) push_b(f[i]);\n\
    \    }\n    S get_f() const { return f2.size() ? f2.top() : Monoid::e(); }\n \
    \   S get_b() const { return b2.size() ? b2.top() : Monoid::e(); }\n    void push_f(const\
    \ S &x) {\n        auto y = get_f();\n        f1.push(x);\n        f2.push(Monoid::op(x,\
    \ y));\n    }\n    void push_b(const S &x) {\n        auto y = get_b();\n    \
    \    b1.push(x);\n        b2.push(Monoid::op(y, x));\n    }\n    void pop_f()\
    \ {\n        f1.pop();\n        f2.pop();\n    }\n    void pop_b() {\n       \
    \ b1.pop();\n        b2.pop();\n    }\n};\n#line 6 \"test/data_structure/misc/dswag.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return S(); }\n\
    };\n\n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    dswag<Monoid> q;\n    int Q;\n    cin >> Q;\n    while\
    \ (Q--) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n        \
    \    int a, b;\n            cin >> a >> b;\n            q.push_front(affine<mint>(a,\
    \ b));\n        } else if (t == 1) {\n            int a, b;\n            cin >>\
    \ a >> b;\n            q.push_back(affine<mint>(a, b));\n        } else if (t\
    \ == 2) {\n            q.pop_front();\n        } else if (t == 3) {\n        \
    \    q.pop_back();\n        } else {\n            int x;\n            cin >> x;\n\
    \            auto f = q.get();\n            cout << f(x).val() << '\\n';\n   \
    \     }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/deque_operate_all_composite\"\
    \n\n#include \"../../../src/modint/modint.hpp\"\n#include \"../../../src/math/affine.hpp\"\
    \n#include \"../../../src/data_structure/misc/dswag.hpp\"\n\nusing mint = modint<998244353>;\n\
    \nstruct Monoid {\n    using S = affine<mint>;\n    static S op(S f, S g) { return\
    \ g(f); }\n    static S e() { return S(); }\n};\n\n#include <iostream>\n\nint\
    \ main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    dswag<Monoid>\
    \ q;\n    int Q;\n    cin >> Q;\n    while (Q--) {\n        int t;\n        cin\
    \ >> t;\n        if (t == 0) {\n            int a, b;\n            cin >> a >>\
    \ b;\n            q.push_front(affine<mint>(a, b));\n        } else if (t == 1)\
    \ {\n            int a, b;\n            cin >> a >> b;\n            q.push_back(affine<mint>(a,\
    \ b));\n        } else if (t == 2) {\n            q.pop_front();\n        } else\
    \ if (t == 3) {\n            q.pop_back();\n        } else {\n            int\
    \ x;\n            cin >> x;\n            auto f = q.get();\n            cout <<\
    \ f(x).val() << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/math/affine.hpp
  - src/data_structure/misc/dswag.hpp
  isVerificationFile: true
  path: test/data_structure/misc/dswag.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:38:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/misc/dswag.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/misc/dswag.test.cpp
- /verify/test/data_structure/misc/dswag.test.cpp.html
title: test/data_structure/misc/dswag.test.cpp
---
