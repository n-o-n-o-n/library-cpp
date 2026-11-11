#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1406?year=2019"
#include "../../src/template.hpp"
#include "../../src/graph/shortest_path.hpp"

string suffix(const string s, int k) {
    assert(0 <= k && k <= ssize(s));
    return s.substr(ssize(s) - k, k);
}

bool pref(const string &s, const string &t) {
    if (s.size() > t.size()) return false;
    for (int i = 0; i < ssize(s); i++) {
        if (s[i] != t[i]) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<string> S(N), suffs = {""};
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        for (int j = 1; j <= ssize(S[i]); j++) suffs.push_back(suffix(S[i], j));
    }
    sort(suffs.begin(), suffs.end());
    suffs.erase(unique(suffs.begin(), suffs.end()), suffs.end());
    int K = suffs.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < K; i++) mp[suffs[i]] = i;
    shortest_path<int> SP(K + 1);
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            if (pref(suffs[i], S[j])) {
                int k = ssize(S[j]) - ssize(suffs[i]);
                SP.add_edge(i, mp[suffix(S[j], k)], k);
            } else if (pref(S[j], suffs[i])) {
                int k = ssize(suffs[i]) - ssize(S[j]);
                SP.add_edge(i, mp[suffix(suffs[i], k)], 0);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j && pref(S[i], S[j])) {
                int k = ssize(S[j]) - ssize(S[i]);
                SP.add_edge(K, mp[suffix(S[j], k)], ssize(S[j]));
            }
        }
    }
    int ans = SP.dist(K, 0);
    cout << (ans == -1 ? 0 : ans) << endl;
}