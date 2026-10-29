---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/best_theorem.hpp
    title: src/graph/best_theorem.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/matrix_tree_theorem.hpp
    title: src/graph/matrix_tree_theorem.hpp
  - icon: ':question:'
    path: src/math/enumerative_combinatorics/combination.hpp
    title: src/math/enumerative_combinatorics/combination.hpp
  - icon: ':heavy_check_mark:'
    path: src/math/matrix/matrix.hpp
    title: src/math/matrix/matrix.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/counting_eulerian_circuits
    links:
    - https://judge.yosupo.jp/problem/counting_eulerian_circuits
  bundledCode: "#line 1 \"test/graph/best_theorem.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/counting_eulerian_circuits\"\
    \n\n#line 2 \"src/modint/modint.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    using namespace std;\n\ntemplate<unsigned int MOD>\nstruct modint {\n    constexpr\
    \ modint() : x(0) {}\n    template<typename T>\n    constexpr modint(T v) {\n\
    \        int y = v % (int)mod();\n        if (y < 0) y += mod();\n        x =\
    \ (unsigned int)y;\n    }\n    static constexpr modint raw(int v) {\n        modint\
    \ a;\n        a.x = v;\n        return a;\n    }\n    static constexpr int mod()\
    \ { return MOD; }\n    constexpr unsigned int val() const { return x; }\n    constexpr\
    \ modint& operator++() {\n        x++;\n        if (x == mod()) x = 0;\n     \
    \   return *this;\n    }\n    constexpr modint& operator--() {\n        if (x\
    \ == 0) x = mod();\n        x--;\n        return *this;\n    }\n    constexpr\
    \ modint operator++(int) {\n        modint res = *this;\n        ++*this;\n  \
    \      return res;\n    }\n    constexpr modint operator--(int) {\n        modint\
    \ res = *this;\n        --*this;\n        return res;\n    }\n    constexpr modint&\
    \ operator+=(const modint &r) {\n        x += r.x;\n        if (x >= mod()) x\
    \ -= mod();\n        return *this;\n    }\n    constexpr modint& operator-=(const\
    \ modint &r) {\n        x -= r.x;\n        if (x >= mod()) x += mod();\n     \
    \   return *this;\n    }\n    constexpr modint& operator*=(const modint &r) {\n\
    \        unsigned long long y = x;\n        y *= r.x;\n        x = (unsigned int)(y\
    \ % mod());\n        return *this;\n    }\n    constexpr modint &operator/=(const\
    \ modint &r) {\n        return *this = *this * r.inv();\n    }\n    friend constexpr\
    \ modint operator+(const modint &a, const modint &b) {\n        return modint(a)\
    \ += b;\n    }\n    friend constexpr modint operator-(const modint &a, const modint\
    \ &b) {\n        return modint(a) -= b;\n    }\n    friend constexpr modint operator*(const\
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
    \    unsigned int x;\n};\n#line 2 \"src/graph/best_theorem.hpp\"\n#include <vector>\n\
    #line 4 \"src/math/matrix/matrix.hpp\"\nusing namespace std;\n\ntemplate<typename\
    \ mint>\nstruct matrix : vector<vector<mint>> {\n    using vector<vector<mint>>::vector;\n\
    \    matrix(int h, int w) : vector<vector<mint>>(h, vector<mint>(w)) {}\n    matrix\
    \ &operator*=(const mint &r) {\n        for (vector<mint> &v : *this) {\n    \
    \        for (mint &a : v) a *= r;\n        }\n        return *this;\n    }\n\
    \    matrix &operator/=(const mint &r) {\n        mint invr = r.inv();\n     \
    \   return *this *= invr;\n    }\n    matrix &operator+=(const matrix& a) {\n\
    \        assert(this->size() == a.size());\n        for (int i = 0; i < int(this->size());\
    \ i++) {\n            assert((*this)[i].size() == a[i].size());\n            for\
    \ (int j = 0; j < int((*this)[i].size()); j++) {\n                (*this)[i][j]\
    \ += a[i][j];\n            }\n        }\n        return *this;\n    }\n    matrix\
    \ &operator-=(const matrix& a) {\n        assert(this->size() == a.size());\n\
    \        for (int i = 0; i < int(this->size()); i++) {\n            assert((*this)[i].size()\
    \ == a[i].size());\n            for (int j = 0; j < int((*this)[i].size()); j++)\
    \ {\n                (*this)[i][j] -= a[i][j];\n            }\n        }\n   \
    \     return *this;\n    }\n    matrix &operator*=(const matrix &a) {\n      \
    \  int n = this->size(), m = a.size();\n        assert(m >= 1);\n        int l\
    \ = a[0].size();\n        matrix res(n, vector<mint>(l));\n        for (int i\
    \ = 0; i < n; i++) {\n            assert(int((*this)[i].size()) == m);\n     \
    \       for (int k = 0; k < m; k++) {\n                for (int j = 0; j < l;\
    \ j++) {\n                    res[i][j] += (*this)[i][k] * a[k][j];\n        \
    \        }\n            }\n        }\n        return *this = res;\n    }\n   \
    \ matrix operator*(const mint &r) const { return matrix(*this) *= r; }\n    matrix\
    \ operator/(const mint &r) const { return matrix(*this) /= r; }\n    matrix operator+(const\
    \ matrix &a) const { return matrix(*this) += a; }\n    matrix operator-(const\
    \ matrix &a) const { return matrix(*this) -= a; }\n    matrix operator*(const\
    \ matrix &a) const { return matrix(*this) *= a; }\n    static constexpr matrix\
    \ I(int n) {\n        matrix res(n, n);\n        for (int i = 0; i < n; i++) {\n\
    \            res[i][i] = 1;\n        }\n        return res;\n    }\n    static\
    \ constexpr matrix O(int n) { return matrix(n, n); }\n    matrix pow(long long\
    \ k) const {\n        matrix res = I(this->size()), a = *this;\n        while\
    \ (k > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n         \
    \   k >>= 1;\n        }\n        return res;\n    }\n    mint det() const {\n\
    \        int n = this->size();\n        assert(n >= 1);\n        assert((*this)[0].size()\
    \ == this->size());\n        mint res = 1;\n        matrix a = *this;\n      \
    \  for (int i = 0; i < n; i++) {\n            for (int j = i; j < n; j++) {\n\
    \                if (a[j][i] != 0) {\n                    if (i != j) res = -res;\n\
    \                    swap(a[i], a[j]);\n                    break;\n         \
    \       }\n            }\n            if (a[i][i] != 0) {\n                for\
    \ (int j = i + 1; j < n; j++) {\n                    mint inv = a[j][i] * a[i][i].inv();\n\
    \                    for (int k = i + 1; k < n; k++) {\n                     \
    \   a[j][k] -= a[i][k] * inv;\n                    }\n                }\n    \
    \        }\n        }\n        for (int i = 0; i < n; i++) {\n            res\
    \ *= a[i][i];\n        }\n        return res;\n    }\n    matrix inv() const {\n\
    \        int n = this->size();\n        matrix a = *this, res = I(n);\n      \
    \  for (int i = 0; i < n; i++) {\n            if (a[i][i] == 0) {\n          \
    \      for (int j = i + 1; j < n; j++) {\n                    if (a[j][i] != 0)\
    \ {\n                        swap(a[i], a[j]);\n                        swap(res[i],\
    \ res[j]);\n                        break;\n                    }\n          \
    \      }\n            }\n            assert(a[i][i] != 0);\n            mint cef\
    \ = a[i][i].inv();\n            for (int j = 0; j < n; j++) {\n              \
    \  a[i][j] *= cef;\n                res[i][j] *= cef;\n            }\n       \
    \     for (int j = 0; j < n; j++) {\n                if (j != i) {\n         \
    \           cef = a[j][i];\n                    for (int k = 0; k < n; k++) {\n\
    \                        a[j][k] -= a[i][k] * cef;\n                        res[j][k]\
    \ -= res[i][k] * cef;\n                    }\n                }\n            }\n\
    \        }\n        return res;\n    }\n    int rank() const {\n        matrix\
    \ a = *this;\n        int h = a.size(), w = a[0].size();\n        int r = 0;\n\
    \        for (int j = 0; j < w && r < h; j++) {\n            int i = r;\n    \
    \        while (i < h && a[i][j] == 0) i++;\n            if (i == h) continue;\n\
    \            swap(a[r], a[i]);\n            mint inv = a[r][j].inv();\n      \
    \      for (i = r + 1; i < h; i++) {\n                mint cef = a[i][j] * inv;\n\
    \                for (int k = j; k < w; k++) {\n                    a[i][k] -=\
    \ a[r][k] * cef;\n                }\n            }\n            r++;\n       \
    \ }\n        return r;\n    }\n};\n#line 4 \"src/math/enumerative_combinatorics/combination.hpp\"\
    \n#include <concepts>\n#line 6 \"src/math/enumerative_combinatorics/combination.hpp\"\
    \nusing namespace std;\n\nnamespace combination {\n\ntemplate<typename mint>\n\
    struct container {\n    static vector<mint> fac, finv;\n    static void init(int\
    \ n) {\n        int sz = fac.size();\n        if (n < sz) return;\n        n =\
    \ clamp(n, 2 * sz, min<int>(1 << 27, mint::mod() - 1));\n        fac.resize(n\
    \ + 1);\n        finv.resize(n + 1);\n        for (int i = sz; i <= n; i++) {\n\
    \            fac[i] = i * fac[i - 1];\n        }\n        finv[n] = fac[n].inv();\n\
    \        for (int i = n; i >= sz; i--) {\n            finv[i - 1] = i * finv[i];\n\
    \        }\n    }\n};\n\ntemplate<typename mint>\nvector<mint> container<mint>::fac(1,\
    \ 1);\ntemplate<typename mint>\nvector<mint> container<mint>::finv(1, 1);\ntemplate<typename\
    \ mint>\nmint fac(int n) {\n    container<mint>::init(n);\n    if (n < 0) return\
    \ 0;\n    return container<mint>::fac[n];\n}\ntemplate<typename mint>\nmint finv(int\
    \ n) {\n    container<mint>::init(n);\n    if (n < 0) return 0;\n    return container<mint>::finv[n];\n\
    }\ntemplate<typename mint>\nmint mod_inv(int n) {\n    assert(n > 0);\n    return\
    \ finv<mint>(n) * fac<mint>(n - 1);\n}\ntemplate<typename mint>\nmint nCk(int\
    \ n, int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return fac<mint>(n)\
    \ * finv<mint>(n - k) * finv<mint>(k);\n}\n// [x^k]1/(1-x)^n\ntemplate<typename\
    \ mint>\nmint neg_nCk(int n, int k) {\n    if (n < 0 || k < 0) return 0;\n   \
    \ if (n == 0) return k == 0;\n    return nCk<mint>(n + k - 1, k);\n}\ntemplate<typename\
    \ mint>\nmint multi_C(const vector<int> &v) {\n    int n = 0;\n    for (const\
    \ int &k : v) n += k;\n    mint res = fac<mint>(n);\n    for (const int &k : v)\
    \ res *= finv<mint>(k);\n    return res;\n}\ntemplate<typename mint>\nmint multi_C(same_as<int>\
    \ auto... ks) {\n    int n = (0 + ... + ks);\n    mint res = fac<mint>(n);\n \
    \   ((res *= finv<mint>(ks)), ...);\n    return res;\n}\ntemplate<typename mint>\n\
    mint nPk(int n, int k) {\n    if (n < 0 || n < k || k < 0) return 0;\n    return\
    \ fac<mint>(n) * finv<mint>(n - k);\n}\ntemplate<typename mint>\nmint catalan(int\
    \ n) {\n    return fac<mint>(2 * n) * finv<mint>(n) * finv<mint>(n + 1);\n}\n\
    template<typename mint>\nmint grid_path(int n, int m) {\n    return nCk<mint>(n\
    \ + m, n);\n}\n\n} // namespace combination\n#line 4 \"src/graph/matrix_tree_theorem.hpp\"\
    \n\ntemplate<typename mint>\ninline mint matrix_tree_theorem_adjacency(const vector<vector<int>>\
    \ &a, int r = 0) {\n    int n = a.size();\n    if (n == 1) return 1;\n    auto\
    \ p = [&](int u) -> int {\n        return u - (u > r);\n    };\n    matrix<mint>\
    \ b(n - 1, n - 1);\n    for (int u = 0; u < n; u++) {\n        if (u == r) continue;\n\
    \        for (int v = 0; v < n; v++) {\n            b[p(u)][p(u)] += a[u][v];\n\
    \            if (v != r) {\n                b[p(u)][p(v)] -= a[u][v];\n      \
    \      }\n        }\n    }\n    return b.det();\n}\n\ntemplate<typename mint>\n\
    inline mint matrix_tree_theorem(const vector<vector<int>> &g, int r = 0) {\n \
    \   int n = g.size();\n    vector<vector<int>> a(n, vector<int>(n));\n    for\
    \ (int u = 0; u < n; u++) {\n        for (int v : g[u]) a[u][v]++;\n    }\n  \
    \  return matrix_tree_theorem_adjacency<mint>(a, r);\n}\n#line 6 \"src/graph/best_theorem.hpp\"\
    \nusing namespace std;\n\ntemplate<typename mint>\ninline mint best_theorem_adjacency(const\
    \ vector<vector<int>> &a, bool edge_labeled = true) {\n    int n = a.size();\n\
    \    vector<int> idx;\n    idx.reserve(n);\n    mint res = 1;\n    for (int u\
    \ = 0; u < n; u++) {\n        int in = 0, out = 0;\n        for (int v = 0; v\
    \ < n; v++) {\n            in += a[v][u];\n            out += a[u][v];\n     \
    \       if (!edge_labeled) res *= combination::finv<mint>(a[u][v]);\n        }\n\
    \        if (in != out) return 0;\n        if (in > 0) {\n            idx.push_back(u);\n\
    \            res *= combination::fac<mint>(in - 1);\n        }\n    }\n    n =\
    \ idx.size();\n    if (n == 0) return 1;\n    vector<vector<int>> b(n, vector<int>(n));\n\
    \    for (int u = 0; u < n; u++) {\n        for (int v = 0; v < n; v++) {\n  \
    \          b[u][v] = a[idx[u]][idx[v]];\n        }\n    }\n    return res * matrix_tree_theorem_adjacency<mint>(b);\n\
    }\n\ntemplate<typename mint>\ninline mint best_theorem(const vector<vector<int>>\
    \ &g, bool edge_labeled = true) {\n    int n = g.size();\n    vector<vector<int>>\
    \ a(n, vector<int>(n));\n    for (int u = 0; u < n; u++) {\n        for (int v\
    \ : g[u]) a[u][v]++;\n    }\n    return best_theorem_adjacency<mint>(a, edge_labeled);\n\
    }\n#line 5 \"test/graph/best_theorem.test.cpp\"\n\nusing mint = modint<998244353>;\n\
    \n#include <iostream>\n\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    int N, M;\n    cin >> N >> M;\n    vector<vector<int>> E(N, vector<int>(N));\n\
    \    for (int u, v; M--; ) {\n        cin >> u >> v;\n        E[u][v]++;\n   \
    \ }\n    mint ans = best_theorem_adjacency<mint>(E);\n    cout << ans.val() <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_eulerian_circuits\"\
    \n\n#include \"../../src/modint/modint.hpp\"\n#include \"../../src/graph/best_theorem.hpp\"\
    \n\nusing mint = modint<998244353>;\n\n#include <iostream>\n\nint main() {\n \
    \   ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int N, M;\n    cin\
    \ >> N >> M;\n    vector<vector<int>> E(N, vector<int>(N));\n    for (int u, v;\
    \ M--; ) {\n        cin >> u >> v;\n        E[u][v]++;\n    }\n    mint ans =\
    \ best_theorem_adjacency<mint>(E);\n    cout << ans.val() << '\\n';\n}"
  dependsOn:
  - src/modint/modint.hpp
  - src/graph/best_theorem.hpp
  - src/math/matrix/matrix.hpp
  - src/math/enumerative_combinatorics/combination.hpp
  - src/graph/matrix_tree_theorem.hpp
  isVerificationFile: true
  path: test/graph/best_theorem.test.cpp
  requiredBy: []
  timestamp: '2026-10-29 12:38:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/best_theorem.test.cpp
layout: document
redirect_from:
- /verify/test/graph/best_theorem.test.cpp
- /verify/test/graph/best_theorem.test.cpp.html
title: test/graph/best_theorem.test.cpp
---
