---
title: Enumerative Combinatorics
---

# 数え上げ

## 写像 12 相

$n$ 個の玉を $k$ 個の箱に入れる方法を数える($k\geq 1$).

$S(n,k)$ は第二種スターリング数, $P(n,k)$ は分割数.
$B(n,k)=\sum_{j=0}^k S(n,j)$, $P_{\le k}(n)=\sum_{j=0}^k P(n,j)$ である.

| 玉 | 箱 | 各箱に $1$ 個以下 | 制限なし | 各箱に $1$ 個以上 |
| --- | --- | ---: | ---: | ---: |
| 区別する | 区別する | $\dfrac{k!}{(k-n)!}$ | $k^n$ | $k!S(n,k)$ |
| 区別しない | 区別する | $\binom{k}{n}$ | $\binom{n+k-1}{k-1}$ | $\binom{n-1}{k-1}$ |
| 区別する | 区別しない | $[n\leq k]$ | $B(n,k)$ | $S(n,k)$ |
| 区別しない | 区別しない | $[n\leq k]$ | $P_{\le k}(n)$ | $P(n,k)$ |

右上は包除原理から $k!S(n,k)=\sum_{i=0}^k(-1)^{k-i}\binom{k}{i}i^n$ とも書ける.
$\dfrac{k!}{(k-n)!}$ は $n>k$ のとき $0$ とする.
$\binom{n-1}{k-1}$ は $n=0$ のとき $0$ とする.

関連: [combination.hpp](https://n-o-n-o-n.github.io/library-cpp/src/math/enumerative_combinatorics/combination.hpp)

## 二項係数

- $\binom{n}{k}=\binom{n-1}{k-1}+\binom{n-1}{k}$
- $k\binom{n}{k}=n\binom{n-1}{k-1}$
- $\sum_{i=k}^{n}\binom{i}{k}=\binom{n+1}{k+1}$ （ホッケースティック恒等式）
- $F_0=0$, $F_1=1$ とすると, $\sum_{k=0}^{\lfloor n/2\rfloor}\binom{n-k}{k}=F_{n+1}$
- $d\geq 1$ について $\dfrac{1}{(1-x)^d}=\sum_{n=0}^{\infty}\binom{n+d-1}{n}x^n$

関連: [combination.hpp](https://n-o-n-o-n.github.io/library-cpp/src/math/enumerative_combinatorics/combination.hpp), [prefix_binomial_sum.hpp](https://n-o-n-o-n.github.io/library-cpp/src/math/enumerative_combinatorics/prefix_binomial_sum.hpp)

## カタラン数

$C_n=\dfrac{1}{n+1}\binom{2n}{n}$.

| $n$ | $C_n$ |
| ---: | ---: |
| $0$ | $1$ |
| $1$ | $1$ |
| $2$ | $2$ |
| $3$ | $5$ |
| $4$ | $14$ |
| $5$ | $42$ |
| $6$ | $132$ |
| $7$ | $429$ |
| $8$ | $1430$ |

- $C_0=1$
- $C_{n+1}=\sum_{k=0}^{n}C_kC_{n-k}$
- $C(x)=\sum_{n=0}^{\infty}C_nx^n=\dfrac{1-\sqrt{1-4x}}{2x}$
- $k\geq1$ のとき $[x^n]C(x)^k=\dfrac{k}{2n+k}\binom{2n+k}{n}$

関連: [combination.hpp](https://n-o-n-o-n.github.io/library-cpp/src/math/enumerative_combinatorics/combination.hpp)

## ベル数

$B(n,k)=\sum_{j=0}^{k}S(n,j)$ は, $n$ 個の区別できる要素を $k$ 個以下の空でない集合に分割する方法の数.
$B_n=B(n,n)$ とする.

| $n \backslash k$ | $0$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| $0$ | $1$ | $1$ | $1$ | $1$ | $1$ | $1$ | $1$ | $1$ |
| $1$ | $0$ | $1$ | $1$ | $1$ | $1$ | $1$ | $1$ | $1$ |
| $2$ | $0$ | $1$ | $2$ | $2$ | $2$ | $2$ | $2$ | $2$ |
| $3$ | $0$ | $1$ | $4$ | $5$ | $5$ | $5$ | $5$ | $5$ |
| $4$ | $0$ | $1$ | $8$ | $14$ | $15$ | $15$ | $15$ | $15$ |
| $5$ | $0$ | $1$ | $16$ | $41$ | $51$ | $52$ | $52$ | $52$ |
| $6$ | $0$ | $1$ | $32$ | $122$ | $187$ | $202$ | $203$ | $203$ |
| $7$ | $0$ | $1$ | $64$ | $365$ | $715$ | $855$ | $876$ | $877$ |

- $B_{n+1}=\sum_{i=0}^{n}\binom{n}{i}B_i$
- $\exp(e^x-1)=\sum_{n=0}^{\infty}B_n\dfrac{x^n}{n!}$

## 第一種スターリング数

$c(n,k)$ は $n$ 要素の順列を $k$ 個の巡回置換に分ける方法の数.
符号なし第一種スターリング数を用いる.

| $n \backslash k$ | $0$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| $0$ | $1$ |  |  |  |  |  |  |  |
| $1$ | $0$ | $1$ |  |  |  |  |  |  |
| $2$ | $0$ | $1$ | $1$ |  |  |  |  |  |
| $3$ | $0$ | $2$ | $3$ | $1$ |  |  |  |  |
| $4$ | $0$ | $6$ | $11$ | $6$ | $1$ |  |  |  |
| $5$ | $0$ | $24$ | $50$ | $35$ | $10$ | $1$ |  |  |
| $6$ | $0$ | $120$ | $274$ | $225$ | $85$ | $15$ | $1$ |  |
| $7$ | $0$ | $720$ | $1764$ | $1624$ | $735$ | $175$ | $21$ | $1$ |

- $c(0,0)=1$, $c(n,k)=c(n-1,k-1)+(n-1)c(n-1,k)$
- $x(x+1)\cdots(x+n-1)=\sum_{k=0}^{n}c(n,k)x^k$
- $\sum_{k=0}^{n}c(n,k)=n!$
- $\sum_{k=0}^{n}2^kc(n,k)=(n+1)!$
- $n\geq2$ では $\sum_{k=0}^{n}(-1)^kc(n,k)=0$
- $\sum_{n=k}^{\infty}c(n,k)\dfrac{x^n}{n!}=\dfrac{1}{k!}\left(\log\dfrac{1}{1-x}\right)^k$

## 第二種スターリング数

$S(n,k)$ は $n$ 個の区別できる要素を $k$ 個の空でない集合に分割する方法の数.

| $n \backslash k$ | $0$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| $0$ | $1$ |  |  |  |  |  |  |  |
| $1$ | $0$ | $1$ |  |  |  |  |  |  |
| $2$ | $0$ | $1$ | $1$ |  |  |  |  |  |
| $3$ | $0$ | $1$ | $3$ | $1$ |  |  |  |  |
| $4$ | $0$ | $1$ | $7$ | $6$ | $1$ |  |  |  |
| $5$ | $0$ | $1$ | $15$ | $25$ | $10$ | $1$ |  |  |
| $6$ | $0$ | $1$ | $31$ | $90$ | $65$ | $15$ | $1$ |  |
| $7$ | $0$ | $1$ | $63$ | $301$ | $350$ | $140$ | $21$ | $1$ |

- $S(0,0)=1$, $S(n,k)=S(n-1,k-1)+kS(n-1,k)$
- $x^n=\sum_{k=0}^{n}S(n,k)x(x-1)\cdots(x-k+1)$
- $n\geq1$ では $S(n,k)=\dfrac{1}{k!}\sum_{i=0}^{k}(-1)^{k-i}\binom{k}{i}i^n$
- $\sum_{n=k}^{\infty}S(n,k)\dfrac{x^n}{n!}=\dfrac{(e^x-1)^k}{k!}$

関連: [stirling2_k_fixed.hpp](https://n-o-n-o-n.github.io/library-cpp/src/math/enumerative_combinatorics/stirling2_k_fixed.hpp), [stirling2_n_fixed.hpp](https://n-o-n-o-n.github.io/library-cpp/src/math/enumerative_combinatorics/stirling2_n_fixed.hpp)

## モンモール数

$D_n$ は長さ $n$ の攪拌順列の個数.

| $n$ | $D_n$ |
| ---: | ---: |
| $0$ | $1$ |
| $1$ | $0$ |
| $2$ | $1$ |
| $3$ | $2$ |
| $4$ | $9$ |
| $5$ | $44$ |
| $6$ | $265$ |
| $7$ | $1854$ |
| $8$ | $14833$ |

- $D_0=1$, $D_1=0$
- $D_n=(n-1)(D_{n-1}+D_{n-2})$ （$n\geq2$）
- $D_n=nD_{n-1}+(-1)^n$ （$n\geq1$）
- $D_n=n!\sum_{k=0}^{n}\dfrac{(-1)^k}{k!}$
- $\sum_{n=0}^{\infty}D_n\dfrac{x^n}{n!}=\dfrac{e^{-x}}{1-x}$

## 分割数

$P(n,k)$ は $n$ を $k$ 個の正整数の和に分割する方法の数で, 順序は区別しない.
$p(n)=\sum_{k=0}^{n}P(n,k)$ とする.

| $n \backslash k$ | $0$ | $1$ | $2$ | $3$ | $4$ | $5$ | $6$ | $7$ |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| $0$ | $1$ |  |  |  |  |  |  |  |
| $1$ | $0$ | $1$ |  |  |  |  |  |  |
| $2$ | $0$ | $1$ | $1$ |  |  |  |  |  |
| $3$ | $0$ | $1$ | $1$ | $1$ |  |  |  |  |
| $4$ | $0$ | $1$ | $2$ | $1$ | $1$ |  |  |  |
| $5$ | $0$ | $1$ | $2$ | $2$ | $1$ | $1$ |  |  |
| $6$ | $0$ | $1$ | $3$ | $3$ | $2$ | $1$ | $1$ |  |
| $7$ | $0$ | $1$ | $3$ | $4$ | $3$ | $2$ | $1$ | $1$ |

代表的な $p(n)$ の値:

| $n$ | $p(n)$ |
| ---: | ---: |
| $0$ | $1$ |
| $1$ | $1$ |
| $2$ | $2$ |
| $3$ | $3$ |
| $4$ | $5$ |
| $5$ | $7$ |
| $6$ | $11$ |
| $7$ | $15$ |
| $8$ | $22$ |
| $9$ | $30$ |
| $10$ | $42$ |
| $20$ | $627$ |
| $30$ | $5,604$ |
| $40$ | $37,338$ |
| $50$ | $204,226$ |

- $P(0,0)=1$, $P(n,k)=P(n-1,k-1)+P(n-k,k)$ （$n,k\geq1$）
- $n<0$ または $k<0$ のとき $P(n,k)=0$
- $\sum_{n=0}^{\infty}P(n,k)x^n=\dfrac{x^k}{\prod_{i=1}^{k}(1-x^i)}$
- $\sum_{n=0}^{\infty}p(n)x^n=\prod_{m=1}^{\infty}\dfrac{1}{1-x^m}$
- 五角数定理: $\prod_{m=1}^{\infty}(1-x^m)=\sum_{j=-\infty}^{\infty}(-1)^jx^{j(3j-1)/2}$

関連: [partition.hpp](https://n-o-n-o-n.github.io/library-cpp/src/math/enumerative_combinatorics/partition.hpp)

## ラグランジュ反転

$F(0)=G(0)=0$, $F'(0)\neq0$, $G(F(x))=x$ のとき,
$n\geq1$ について
$[x^n]G(x)=\dfrac{1}{n}[x^{n-1}]\left(\dfrac{x}{F(x)}\right)^n$.

関連: [fps_compositional_inverse.hpp](https://n-o-n-o-n.github.io/library-cpp/src/fps/fps_compositional_inverse.hpp)
