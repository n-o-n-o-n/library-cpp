---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/directed_range_query.hpp
    title: Directed Range Query
  - icon: ':heavy_check_mark:'
    path: src/data_structure/range_query/segtree.hpp
    title: Segtree
  - icon: ':heavy_check_mark:'
    path: src/math/affine.hpp
    title: src/math/affine.hpp
  - icon: ':heavy_check_mark:'
    path: src/modint/modint.hpp
    title: src/modint/modint.hpp
  - icon: ':heavy_check_mark:'
    path: src/tree/hld.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/tree/hld.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#line 2 \"src/tree/hld.hpp\"\n#include <algorithm>\n#include <cassert>\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate<typename SegTree, bool edge, bool\
    \ commutative>\nstruct heavy_light_decomposition {\n    using M = typename SegTree::M;\n\
    \    using S = typename M::S;\n    heavy_light_decomposition() = default;\n  \
    \  heavy_light_decomposition(int _n, int _r = 0) : n(_n), r(_r), id(0), built(false)\
    \ {\n        edges.reserve(n - 1);\n        if (n <= 1) build();\n    }\n    void\
    \ add_edge(int u, int v, const S &w = M::e()) {\n        assert(!built);\n   \
    \     assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(u\
    \ != v);\n        edges.emplace_back(u, v, w);\n        if (ssize(edges) + 1 ==\
    \ n) build();\n    }\n    int lca(int u, int v) {\n        assert(built);\n  \
    \      assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        return\
    \ inner_query(u, v, [] (int, int, bool) {});\n    }\n    void set(int u, const\
    \ S &w) {\n        assert(built);\n        assert(0 <= u && u < n);\n        seg.set(idx(u),\
    \ w);\n    }\n    void set(int u, int v, const S &w) {\n        assert(built);\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(u\
    \ != v);\n        seg.set(idx(u, v), w);\n    }\n    template<typename F>\n  \
    \  void apply(int u, int v, const F &f) {\n        assert(built);\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        inner_query(u, v,\
    \ [&] (int l, int r, bool) {\n            if (l > r) swap(l, r);\n           \
    \ seg.apply(l, r, f);\n        });\n    }\n    template<typename F>\n    void\
    \ subtree_apply(int u, const F &f) {\n        assert(built);\n        assert(0\
    \ <= u && u < n);\n        seg.apply(in[u] + edge, out[u], f);\n    }\n    S get(int\
    \ u) {\n        assert(built);\n        assert(0 <= u && u < n);\n        return\
    \ seg.get(idx(u));\n    }\n    S get(int u, int v) {\n        assert(built);\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(u\
    \ != v);\n        return seg.get(idx(u, v));\n    }\n    S prod(int u, int v)\
    \ {\n        assert(built);\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n        S pu = M::e(), pv = M::e();\n        inner_query(u,\
    \ v, [&] (int l, int r, bool up) {\n            if (up) {\n                pu\
    \ = M::op(pu, inner_prod(l, r));\n            } else {\n                pv = M::op(inner_prod(l,\
    \ r), pv);\n            }\n        });\n        return M::op(pu, pv);\n    }\n\
    \    S subtree_prod(int u) {\n        assert(built);\n        assert(0 <= u &&\
    \ u < n);\n        return seg.prod(in[u] + edge, out[u]);\n    }\n    template<typename\
    \ C>\n    int binary_search(int u, int v, const C &check) {\n        assert(built);\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        vector<pair<int,\
    \ int>> pl, pr;\n        inner_query(u, v, [&] (int l, int r, bool up) {\n   \
    \         if (l == r) return;\n            (up ? pl : pr).emplace_back(l, r);\n\
    \        });\n        reverse(pr.begin(), pr.end());\n        pl.insert(pl.end(),\
    \ pr.begin(), pr.end());\n        S p = M::e();\n        for (auto [l, r] : pl)\
    \ {\n            S np = M::op(p, inner_prod(l, r));\n            if (check(np))\
    \ {\n                p = np;\n                u = l < r ? inv[r - 1] : (edge ?\
    \ par[inv[r]] : inv[r]);\n                continue;\n            }\n         \
    \   auto c = [&] (const S &x) { return check(M::op(p, x)); };\n            if\
    \ (l < r) {\n                int k = [&] {\n                    if constexpr (commutative)\
    \ {\n                        return seg.max_right(l, c);\n                   \
    \ } else {\n                        return seg.max_right(l, false, c);\n     \
    \               }\n                } ();\n                return k == l ? u :\
    \ inv[k - 1];\n            } else {\n                int k = [&] {\n         \
    \           if constexpr (commutative) {\n                        return seg.min_left(l,\
    \ c);\n                    } else {\n                        return seg.min_left(l,\
    \ true, c);\n                    }\n                } ();\n                return\
    \ k == l ? u : (edge ? par[inv[k]] : inv[k]);\n            }\n        }\n    \
    \    return v;\n    }\n    vector<pair<int, int>> path_decompose(int u, int v)\
    \ {\n        assert(built);\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n        if (u == v) return {{u, v}};\n        int w = lca(u,\
    \ v);\n        auto climb = [&] (int x, vector<pair<int, int>> &res) {\n     \
    \       while (x != w) {\n                int y = head[x] == head[w] ? w : head[x];\n\
    \                if (x != y) res.emplace_back(x, y);\n                if (y ==\
    \ w) break;\n                res.emplace_back(y, par[y]);\n                x =\
    \ par[y];\n            }\n        };\n        vector<pair<int, int>> pu, pv;\n\
    \        climb(u, pu);\n        climb(v, pv);\n        reverse(pv.begin(), pv.end());\n\
    \        for (auto [l, r] : pv) pu.emplace_back(r, l);\n        return pu;\n \
    \   }\nprivate:\n    int n, r, id;\n    bool built;\n    SegTree seg;\n    vector<vector<int>>\
    \ g;\n    vector<int> sub, depth, par, in, out, inv, head, heavy;\n    vector<tuple<int,\
    \ int, S>> edges;\n    int idx(int u) const {\n        assert(built);\n      \
    \  return in[u];\n    }\n    int idx(int u, int v) const {\n        assert(built);\n\
    \        return max(in[u], in[v]);\n    }\n    void dfs(int u, int p) {\n    \
    \    par[u] = p;\n        sub[u] = 1;\n        int sub_max = 0;\n        for (int\
    \ v : g[u]) {\n            if (v != p) {\n                dfs(v, u);\n       \
    \         sub[u] += sub[v];\n                if (sub[v] > sub_max) {\n       \
    \             sub_max = sub[v];\n                    heavy[u] = v;\n         \
    \       }\n            }\n        }\n    }\n    void decompose(int u, int h) {\n\
    \        head[u] = h;\n        in[u] = id++;\n        inv[in[u]] = u;\n      \
    \  if (heavy[u] != -1) decompose(heavy[u], h);\n        for (int v : g[u]) {\n\
    \            if (v != par[u] && v != heavy[u]) {\n                decompose(v,\
    \ v);\n            }\n        }\n        out[u] = id;\n    }\n    void build()\
    \ {\n        g = vector<vector<int>>(n);\n        sub = depth = in = inv = out\
    \ = head = vector<int>(n);\n        par = heavy = vector<int>(n, -1);\n      \
    \  for (const auto &[u, v, _] : edges) {\n            g[u].emplace_back(v);\n\
    \            g[v].emplace_back(u);\n        }\n        dfs(r, r);\n        decompose(r,\
    \ r);\n        built = true;\n        if (edge) {\n            vector<S> a(n,\
    \ M::e());\n            for (const auto &[u, v, w] : edges) {\n              \
    \  a[idx(u, v)] = w;\n            }\n            seg = SegTree(a);\n        }\
    \ else {\n            seg = SegTree(n);\n        }\n    }\n    template<typename\
    \ F>\n    int inner_query(int u, int v, const F &f) {\n        while (head[u]\
    \ != head[v]) {\n            if (in[head[u]] > in[head[v]]) {\n              \
    \  f(in[u] + 1, in[head[u]], true);\n                u = par[head[u]];\n     \
    \       } else {\n                f(in[head[v]], in[v] + 1, false);\n        \
    \        v = par[head[v]];\n            }\n        }\n        if (in[u] >= in[v])\
    \ {\n            f(in[u] + 1, in[v] + edge, true);\n            return v;\n  \
    \      } else {\n            f(in[u] + edge, in[v] + 1, false);\n            return\
    \ u;\n        }\n    }\n    S inner_prod(int l, int r) {\n        if (commutative\
    \ && l > r) swap(l, r);\n        return seg.prod(l, r);\n    }\n};\n#line 4 \"\
    src/data_structure/range_query/segtree.hpp\"\nusing namespace std;\n\ntemplate\
    \ <typename Monoid>\nstruct segtree {\n    using M = Monoid;\n    using S = typename\
    \ M::S;\n    segtree() : segtree(0) {}\n    segtree(int _n) : segtree(vector<S>(_n,\
    \ M::e())) {}\n    segtree(const vector<S> &v) : n(v.size()) {\n        log =\
    \ 1;\n        while ((1 << log) < n) log++;\n        sz = 1 << log;\n        d\
    \ = vector<S>(2 * sz, M::e());\n        for (int i = 0; i < n; i++) d[i + sz]\
    \ = v[i];\n        for (int i = sz - 1; i >= 1; i--) update(i);\n    }\n    void\
    \ set(int p, const S &x) {\n        assert(0 <= p && p < n);\n        p += sz;\n\
    \        d[p] = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n \
    \   }\n    void apply(int p, const S &x) {\n        assert(0 <= p && p < n);\n\
    \        set(p, M::op(x, d[p + sz]));\n    }\n    S get(int p) const {\n     \
    \   assert(0 <= p && p < n);\n        return d[p + sz];\n    }\n    S prod(int\
    \ l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n        l +=\
    \ sz;\n        r += sz;\n        S pl = M::e(), pr = M::e();\n        while (l\
    \ < r) {\n            if (l & 1) pl = M::op(pl, d[l++]);\n            if (r &\
    \ 1) pr = M::op(d[--r], pr);\n            l >>= 1;\n            r >>= 1;\n   \
    \     }\n        return M::op(pl, pr);\n    }\n    S all_prod() const { return\
    \ d[1]; }\n    template<typename C>\n    int max_right(int l, const C &check)\
    \ const {\n        assert(0 <= l && l <= n);\n        assert(check(M::e()));\n\
    \        if (l == n) return l;\n        l += sz;\n        S p = M::e();\n    \
    \    do {\n            while (!(l & 1)) l >>= 1;\n            S np = M::op(p,\
    \ d[l]);\n            if (!check(np)) {\n                while (l < sz) {\n  \
    \                  l <<= 1;\n                    np = M::op(p, d[l]);\n      \
    \              if (check(np)) {\n                        p = np;\n           \
    \             l++;\n                    }\n                }\n               \
    \ return l - sz;\n            }\n            p = np;\n            l++;\n     \
    \   } while ((l & -l) != l);\n        return n;\n    }\n    template<typename\
    \ C>\n    int max_right(const C &check) const {\n        return max_right(0, check);\n\
    \    }\n    template<typename C>\n    int min_left(int r, const C &check) const\
    \ {\n        assert(0 <= r && r <= n);\n        assert(check(M::e()));\n     \
    \   if (r == 0) return r;\n        r += sz;\n        S p = M::e();\n        do\
    \ {\n            r--;\n            while (r > 1 && r & 1) r >>= 1;\n         \
    \   S np = M::op(d[r], p);\n            if (!check(np)) {\n                while\
    \ (r < sz) {\n                    (r <<= 1)++;\n                    np = M::op(d[r],\
    \ p);\n                    if (check(np)) {\n                        p = np;\n\
    \                        r--;\n                    }\n                }\n    \
    \            return r + 1 - sz;\n            }\n            p = np;\n        }\
    \ while ((r & -r) != r);\n        return 0;\n    }\n    template<typename C>\n\
    \    int min_left(const C &check) const {\n        return min_left(n, check);\n\
    \    }\nprivate:\n    int n, log, sz;\n    vector<S> d;\n    void update(int p)\
    \ {\n        d[p] = M::op(d[2 * p], d[2 * p + 1]);\n    }\n};\n#line 3 \"src/data_structure/range_query/directed_range_query.hpp\"\
    \n#include <ranges>\n#line 5 \"src/data_structure/range_query/directed_range_query.hpp\"\
    \nusing namespace std;\n\ntemplate<typename SegTree>\nstruct directed_range_query\
    \ {\n    using M = typename SegTree::M;\n    using S = typename M::S;\n    directed_range_query()\
    \ = default;\n    directed_range_query(int _n) : n(_n), seg(_n), ges(_n) {}\n\
    \    directed_range_query(const vector<S> &v) : n(v.size()), seg(v), ges(vector<S>(v.rbegin(),\
    \ v.rend())) {}\n    void set(int p, const S &x) {\n        assert(0 <= p && p\
    \ < n);\n        seg.set(p, x);\n        ges.set(n - 1 - p, x);\n    }\n    template<typename\
    \ F>\n    void apply(int l, int r, const F &f) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        seg.apply(l, r, f);\n        ges.apply(n - r, n - l,\
    \ f);\n    }\n    S get(int p) {\n        assert(0 <= p && p < n);\n        return\
    \ seg.get(p);\n    }\n    S prod(int l, int r) {\n        return l < r ? seg.prod(l,\
    \ r) : ges.prod(n - l, n - r);\n    }\n    template<typename C>\n    int max_right(int\
    \ l, bool rev, const C &check) {\n        return rev ? n - ges.min_left(n - l,\
    \ check) : seg.max_right(l, check);\n    }\n    template<typename C>\n    int\
    \ min_left(int r, bool rev, const C &check) {\n        return rev ? n - ges.max_right(n\
    \ - r, check) : seg.min_left(r, check);\n    }\nprivate:\n    int n;\n    SegTree\
    \ seg, ges;\n};\n#line 4 \"src/modint/modint.hpp\"\nusing namespace std;\n\ntemplate<unsigned\
    \ int MOD>\nstruct modint {\n    constexpr modint() : x(0) {}\n    template<typename\
    \ T>\n    constexpr modint(T v) {\n        int y = v % (int)mod();\n        if\
    \ (y < 0) y += mod();\n        x = (unsigned int)y;\n    }\n    static constexpr\
    \ modint raw(int v) {\n        modint a;\n        a.x = v;\n        return a;\n\
    \    }\n    static constexpr int mod() { return MOD; }\n    constexpr unsigned\
    \ int val() const { return x; }\n    constexpr modint& operator++() {\n      \
    \  x++;\n        if (x == mod()) x = 0;\n        return *this;\n    }\n    constexpr\
    \ modint& operator--() {\n        if (x == 0) x = mod();\n        x--;\n     \
    \   return *this;\n    }\n    constexpr modint operator++(int) {\n        modint\
    \ res = *this;\n        ++*this;\n        return res;\n    }\n    constexpr modint\
    \ operator--(int) {\n        modint res = *this;\n        --*this;\n        return\
    \ res;\n    }\n    constexpr modint& operator+=(const modint &r) {\n        x\
    \ += r.x;\n        if (x >= mod()) x -= mod();\n        return *this;\n    }\n\
    \    constexpr modint& operator-=(const modint &r) {\n        x -= r.x;\n    \
    \    if (x >= mod()) x += mod();\n        return *this;\n    }\n    constexpr\
    \ modint& operator*=(const modint &r) {\n        unsigned long long y = x;\n \
    \       y *= r.x;\n        x = (unsigned int)(y % mod());\n        return *this;\n\
    \    }\n    constexpr modint &operator/=(const modint &r) {\n        return *this\
    \ = *this * r.inv();\n    }\n    friend constexpr modint operator+(const modint\
    \ &a, const modint &b) {\n        return modint(a) += b;\n    }\n    friend constexpr\
    \ modint operator-(const modint &a, const modint &b) {\n        return modint(a)\
    \ -= b;\n    }\n    friend constexpr modint operator*(const modint &a, const modint\
    \ &b) {\n        return modint(a) *= b;\n    }\n    friend constexpr modint operator/(const\
    \ modint &a, const modint &b) {\n        return modint(a) /= b;\n    }\n    friend\
    \ constexpr bool operator==(const modint &a, const modint &b) {\n        return\
    \ a.x == b.x;\n    }\n    friend constexpr bool operator!=(const modint &a, const\
    \ modint &b) {\n        return a.x != b.x;\n    }\n    constexpr modint operator+()\
    \ const { return *this; }\n    constexpr modint operator-() const { return modint()\
    \ - *this; }\n    constexpr modint pow(long long k) const {\n        assert(k\
    \ >= 0);\n        modint a = *this;\n        modint res = 1;\n        while (k\
    \ > 0) {\n            if (k & 1) res *= a;\n            a *= a;\n            k\
    \ >>= 1;\n        }\n        return res;\n    }\n    constexpr modint inv() const\
    \ {\n        long long a = x, b = mod(), u = 1, v = 0;\n        while (b > 0)\
    \ {\n            long long t = a / b;\n            a -= t * b;\n            swap(a,\
    \ b);\n            u -= t * v;\n            swap(u, v);\n        }\n        return\
    \ modint(u);\n    }\nprivate:\n    unsigned int x;\n};\n#line 2 \"src/math/affine.hpp\"\
    \n\ntemplate<typename mint>\nstruct affine {\n    mint a, b;\n    affine() : a(1),\
    \ b(0) {}\n    affine(const mint &_a, const mint &_b) : a(_a), b(_b) {}\n    mint\
    \ operator()(const mint &x) const {\n        return a * x + b;\n    }\n    affine\
    \ operator()(const affine &f) const {\n        mint c = a * f.a;\n        mint\
    \ d = a * f.b + b;\n        return affine(c, d);\n    }\n};\n#line 8 \"test/tree/hld.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return S(); }\n\
    };\n\nusing SegTree = directed_range_query<segtree<Monoid>>;\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vector<int> A(N), B(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> A[i] >> B[i];\n    heavy_light_decomposition<SegTree, false,\
    \ false> G(N);\n    for (int i = 1, u, v; i < N; i++) {\n        cin >> u >> v;\n\
    \        G.add_edge(u, v);\n    }\n    for (int i = 0; i < N; i++) {\n       \
    \ G.set(i, affine<mint>(A[i], B[i]));\n    }\n    while (Q--) {\n        int t;\n\
    \        cin >> t;\n        if (t == 0) {\n            int u, a, b;\n        \
    \    cin >> u >> a >> b;\n            G.set(u, affine<mint>(a, b));\n        }\
    \ else {\n            int u, v, x;\n            cin >> u >> v >> x;\n        \
    \    auto f = G.prod(u, v);\n            cout << f(x).val() << '\\n';\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../../src/tree/hld.hpp\"\n#include \"../../src/data_structure/range_query/segtree.hpp\"\
    \n#include \"../../src/data_structure/range_query/directed_range_query.hpp\"\n\
    #include \"../../src/modint/modint.hpp\"\n#include \"../../src/math/affine.hpp\"\
    \n\nusing mint = modint<998244353>;\n\nstruct Monoid {\n    using S = affine<mint>;\n\
    \    static S op(S f, S g) { return g(f); }\n    static S e() { return S(); }\n\
    };\n\nusing SegTree = directed_range_query<segtree<Monoid>>;\n\n#include <iostream>\n\
    \nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(nullptr);\n    int\
    \ N, Q;\n    cin >> N >> Q;\n    vector<int> A(N), B(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> A[i] >> B[i];\n    heavy_light_decomposition<SegTree, false,\
    \ false> G(N);\n    for (int i = 1, u, v; i < N; i++) {\n        cin >> u >> v;\n\
    \        G.add_edge(u, v);\n    }\n    for (int i = 0; i < N; i++) {\n       \
    \ G.set(i, affine<mint>(A[i], B[i]));\n    }\n    while (Q--) {\n        int t;\n\
    \        cin >> t;\n        if (t == 0) {\n            int u, a, b;\n        \
    \    cin >> u >> a >> b;\n            G.set(u, affine<mint>(a, b));\n        }\
    \ else {\n            int u, v, x;\n            cin >> u >> v >> x;\n        \
    \    auto f = G.prod(u, v);\n            cout << f(x).val() << '\\n';\n      \
    \  }\n    }\n}"
  dependsOn:
  - src/tree/hld.hpp
  - src/data_structure/range_query/segtree.hpp
  - src/data_structure/range_query/directed_range_query.hpp
  - src/modint/modint.hpp
  - src/math/affine.hpp
  isVerificationFile: true
  path: test/tree/hld.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 20:48:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/tree/hld.test.cpp
layout: document
redirect_from:
- /verify/test/tree/hld.test.cpp
- /verify/test/tree/hld.test.cpp.html
title: test/tree/hld.test.cpp
---
