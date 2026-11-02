#pragma once
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

template<typename T>
constexpr T inf() { return numeric_limits<T>::max() / 2; }

template<typename T1, typename T2>
bool chmin(T1 &a, T2 b) { return a > b ? a = b, true : false; }
template<typename T1, typename T2>
bool chmax(T1 &a, T2 b) { return a < b ? a = b, true : false; }