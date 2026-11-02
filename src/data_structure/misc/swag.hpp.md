---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/template.hpp
    title: src/template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/data_structure/misc/swag.test.cpp
    title: test/data_structure/misc/swag.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/template.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nusing ll = long long;\n\ntemplate<typename T>\nconstexpr T inf() { return\
    \ numeric_limits<T>::max() / 2; }\n\ntemplate<typename T1, typename T2>\nbool\
    \ chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }\ntemplate<typename\
    \ T1, typename T2>\nbool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false;\
    \ }\n#line 3 \"src/data_structure/misc/swag.hpp\"\n\ntemplate<typename Monoid>\n\
    struct swag {\n    using S = typename Monoid::S;\n    swag() = default;\n    size_t\
    \ size() const { return f1.size() + b1.size(); }\n    bool empty() const { return\
    \ size() == 0; }\n    S get() const { return Monoid::op(get_f(), get_b()); }\n\
    \    void push(const S &x) { push_b(x); }\n    void pop() {\n        assert(size());\n\
    \        if (f1.empty()) normalize();\n        pop_f();\n    }\nprivate:\n   \
    \ stack<S> f1, f2, b1, b2;\n    void normalize() {\n        while (b1.size())\
    \ {\n            push_f(b1.top());\n            pop_b();\n        }\n    }\n \
    \   S get_f() const { return f2.size() ? f2.top() : Monoid::e(); }\n    S get_b()\
    \ const { return b2.size() ? b2.top() : Monoid::e(); }\n    void push_f(const\
    \ S &x) {\n        auto y = get_f();\n        f1.push(x);\n        f2.push(Monoid::op(x,\
    \ y));\n    }\n    void push_b(const S &x) {\n        auto y = get_b();\n    \
    \    b1.push(x);\n        b2.push(Monoid::op(y, x));\n    }\n    void pop_f()\
    \ {\n        f1.pop();\n        f2.pop();\n    }\n    void pop_b() {\n       \
    \ b1.pop();\n        b2.pop();\n    }\n};\n"
  code: "#pragma once\n#include \"../../template.hpp\"\n\ntemplate<typename Monoid>\n\
    struct swag {\n    using S = typename Monoid::S;\n    swag() = default;\n    size_t\
    \ size() const { return f1.size() + b1.size(); }\n    bool empty() const { return\
    \ size() == 0; }\n    S get() const { return Monoid::op(get_f(), get_b()); }\n\
    \    void push(const S &x) { push_b(x); }\n    void pop() {\n        assert(size());\n\
    \        if (f1.empty()) normalize();\n        pop_f();\n    }\nprivate:\n   \
    \ stack<S> f1, f2, b1, b2;\n    void normalize() {\n        while (b1.size())\
    \ {\n            push_f(b1.top());\n            pop_b();\n        }\n    }\n \
    \   S get_f() const { return f2.size() ? f2.top() : Monoid::e(); }\n    S get_b()\
    \ const { return b2.size() ? b2.top() : Monoid::e(); }\n    void push_f(const\
    \ S &x) {\n        auto y = get_f();\n        f1.push(x);\n        f2.push(Monoid::op(x,\
    \ y));\n    }\n    void push_b(const S &x) {\n        auto y = get_b();\n    \
    \    b1.push(x);\n        b2.push(Monoid::op(y, x));\n    }\n    void pop_f()\
    \ {\n        f1.pop();\n        f2.pop();\n    }\n    void pop_b() {\n       \
    \ b1.pop();\n        b2.pop();\n    }\n};"
  dependsOn:
  - src/template.hpp
  isVerificationFile: false
  path: src/data_structure/misc/swag.hpp
  requiredBy: []
  timestamp: '2026-11-02 21:52:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/data_structure/misc/swag.test.cpp
documentation_of: src/data_structure/misc/swag.hpp
layout: document
redirect_from:
- /library/src/data_structure/misc/swag.hpp
- /library/src/data_structure/misc/swag.hpp.html
title: src/data_structure/misc/swag.hpp
---
