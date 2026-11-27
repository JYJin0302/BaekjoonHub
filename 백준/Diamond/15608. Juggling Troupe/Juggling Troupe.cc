#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    set<int> st;
    st.insert(-1);
    st.insert(n);

    for (int i = 0; i < n; i++) if (s[i] == '0') {
        st.insert(i);
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            s[i] = '1';
            int L = *(--st.lower_bound(i));
            int R = *st.lower_bound(i);

            int ni = L + R - i;
            int v = s[ni] - '0';
            s[ni] = char('0' + v - 1);

            if (s[ni] == '0') st.insert(ni);
            if (L != -1) {
                st.erase(L);
                s[L] = '1';
            }
            if (R != n) {
                st.erase(R);
                s[R] = '1';
            }
        }
    }
    cout << s;

}