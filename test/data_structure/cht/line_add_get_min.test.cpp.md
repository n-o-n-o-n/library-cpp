---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/cht/li_chao_tree.hpp
    title: Li Chao Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/data_structure/cht/line_add_get_min.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#line 2 \"src/data_structure/cht/li_chao_tree.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    using namespace std;\n\ntemplate<typename T>\nstruct li_chao_tree {\n    li_chao_tree()\
    \ : built(false) {}\n    li_chao_tree(const vector<T> &_xs) : xs(_xs), built(false)\
    \ {\n        build();\n    }\n    void add_point(T x) {\n        assert(!built);\n\
    \        xs.push_back(x);\n    }\n    void add_line(T a, T b) {\n        build();\n\
    \        update(line(a, b), 1, 0, sz);\n    }\n    void add_segment(T xl, T xr,\
    \ T a, T b) {\n        build();\n        int l = lower_bound(xs.begin(), xs.begin()\
    \ + n, xl) - xs.begin();\n        int r = lower_bound(xs.begin(), xs.begin() +\
    \ n, xr) - xs.begin();\n        line f(a, b);\n        int len = 1, ll = l, rr\
    \ = r;\n        l += sz, r += sz;\n        while (l < r) {\n            if (l\
    \ & 1) {\n                update(f, l++, ll, ll + len);\n                ll +=\
    \ len;\n            }\n            if (r & 1) {\n                rr -= len;\n\
    \                update(f, --r, rr, rr + len);\n            }\n            l >>=\
    \ 1;\n            r >>= 1;\n            len <<= 1;\n        }\n    }\n    T get_min(T\
    \ x) {\n        build();\n        int p = lower_bound(xs.begin(), xs.end(), x)\
    \ - xs.begin();\n        assert(xs[p] == x);\n        p += sz;\n        T res\
    \ = inf;\n        for (int i = 0; i <= log; i++) {\n            res = min(res,\
    \ d[p >> i](x));\n        }\n        return res;\n    }\nprivate:\n    struct\
    \ line {\n        T a, b;\n        line(T _a, T _b) : a(_a), b(_b) {}\n      \
    \  T operator()(T x) const {\n            return a * x + b;\n        }\n    };\n\
    \    int n, log, sz;\n    vector<T> xs;\n    vector<line> d;\n    bool built;\n\
    \    static constexpr T inf = numeric_limits<T>::max();\n    static constexpr\
    \ line e() {\n        return line(0, inf);\n    }\n    void build() {\n      \
    \  if (built) return;\n        if (xs.empty()) xs.push_back(0);\n        sort(xs.begin(),\
    \ xs.end());\n        xs.erase(unique(xs.begin(), xs.end()), xs.end());\n    \
    \    n = xs.size();\n        log = 1;\n        while ((1 << log) < n) log++;\n\
    \        sz = 1 << log;\n        d = vector<line>(2 * sz, e());\n        while\
    \ ((int)xs.size() <= sz) xs.push_back(xs.back() + 1);\n        built = true;\n\
    \    }\n    void update(line f, int p, int l, int r) {\n        auto &g = d[p];\n\
    \        int m = (l + r) / 2;\n        bool pl = f(xs[l]) < g(xs[l]);\n      \
    \  bool pm = f(xs[m]) < g(xs[m]);\n        bool pr = f(xs[r]) < g(xs[r]);\n  \
    \      if (!pl && !pr) return;\n        if (pl && pr) {\n            g = f;\n\
    \            return;\n        }\n        if (pm) swap(f, g);\n        if (l +\
    \ 1 == r) return;\n        if (pl ^ pm) {\n            update(f, 2 * p, l, m);\n\
    \        } else {\n            update(f, 2 * p + 1, m, r);\n        }\n    }\n\
    };\n#line 4 \"test/data_structure/cht/line_add_get_min.test.cpp\"\n\n#include\
    \ <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    li_chao_tree<long long> lct;\n    vector<long\
    \ long> a(N), b(N);\n    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];\n  \
    \  vector<long long> t(Q), c(Q), d(Q), x(Q);\n    for (int i = 0; i < Q; i++)\
    \ {\n        cin >> t[i];\n        if (t[i] == 0) {\n            cin >> c[i] >>\
    \ d[i];\n        } else {\n            cin >> x[i];\n            lct.add_point(x[i]);\n\
    \        }\n    }\n    for (int i = 0; i < N; i++) {\n        lct.add_line(a[i],\
    \ b[i]);\n    }\n    for (int i = 0; i < Q; i++) {\n        if (t[i] == 0) {\n\
    \            lct.add_line(c[i], d[i]);\n        } else {\n            cout <<\
    \ lct.get_min(x[i]) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../../../src/data_structure/cht/li_chao_tree.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    li_chao_tree<long long> lct;\n    vector<long\
    \ long> a(N), b(N);\n    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];\n  \
    \  vector<long long> t(Q), c(Q), d(Q), x(Q);\n    for (int i = 0; i < Q; i++)\
    \ {\n        cin >> t[i];\n        if (t[i] == 0) {\n            cin >> c[i] >>\
    \ d[i];\n        } else {\n            cin >> x[i];\n            lct.add_point(x[i]);\n\
    \        }\n    }\n    for (int i = 0; i < N; i++) {\n        lct.add_line(a[i],\
    \ b[i]);\n    }\n    for (int i = 0; i < Q; i++) {\n        if (t[i] == 0) {\n\
    \            lct.add_line(c[i], d[i]);\n        } else {\n            cout <<\
    \ lct.get_min(x[i]) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - src/data_structure/cht/li_chao_tree.hpp
  isVerificationFile: true
  path: test/data_structure/cht/line_add_get_min.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/data_structure/cht/line_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/data_structure/cht/line_add_get_min.test.cpp
- /verify/test/data_structure/cht/line_add_get_min.test.cpp.html
title: test/data_structure/cht/line_add_get_min.test.cpp
---
