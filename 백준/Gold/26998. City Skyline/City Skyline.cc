#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int MOD = 1e6;

void solve() {

    int n, m;
    cin >> n >> m;

    int ans = 0;
    stack<int> st;
    st.push(0);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        while (st.top() > b) {
            st.pop();
            ans++;
        }
        if (st.top() < b) {
            st.push(b);
        }
    }
    while (st.top() != 0) st.pop(), ans++;
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}