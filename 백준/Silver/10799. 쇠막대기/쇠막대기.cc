#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    string s;
    cin >> s;

    ll ans = 0;
    stack<int> st;
    for (auto f : s) {
        if (f == '(') {
            st.push(-1);
        }
        else {
            int res = 0;

            while (st.top() != -1) {
                res += st.top();
                st.pop();
            }
            st.pop();

            if (res != 0) {
                ans += res + 1;
            }
            st.push(max(1, res));
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}