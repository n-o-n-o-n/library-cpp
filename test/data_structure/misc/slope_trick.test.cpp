#define PROBLEM "https://yukicoder.me/problems/no/1077"

#include "../../../src/data_structure/misc/slope_trick.hpp"

#include <iostream>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    slope_trick<long long> st;
    for (int i = 0; i < N; i++) {
        long long y;
        cin >> y;
        st.add_abs_x_minus_a(y);
        st.slide_window_min(10000, 0);
    }
    cout << st.get_min() << '\n';
}
