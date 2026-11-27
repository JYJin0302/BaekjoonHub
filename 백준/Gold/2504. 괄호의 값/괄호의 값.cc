#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()



void solve() {

    string s;
    cin >> s;

    stack<int> st;
    for (auto f : s) {
        int res = 0;
        switch (f) {
        case '(':
            st.push(-1);
            break;
        case ')':
            res = 0;
            while (!st.empty() && st.top() != -1) {
                res += st.top();
                st.pop();
            }
            if (st.empty()) {
                cout << 0;
                return;
            }
            st.pop();
            if (res == 0) res = 1;
            st.push(res * 2);
            break;
        case '[':
            st.push(-2);
            break;
        case ']':
            res = 0;
            while (!st.empty() && st.top() != -2) {
                res += st.top();
                st.pop();
            }
            if (st.empty()) {
                cout << 0;
                return;
            }
            st.pop();
            if (res == 0) res = 1;
            st.push(res * 3);
            break;
        default:
            exit(-1);
        }
    }
    int res = 0;
    while (!st.empty()) {
        if (st.top() < 0) {
            cout << 0;
            return;
        }
        res += st.top();
        st.pop();
    }
    cout << res;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}