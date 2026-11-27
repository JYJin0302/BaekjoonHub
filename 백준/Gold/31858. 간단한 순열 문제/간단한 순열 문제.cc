#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    stack<int> st;
    ll ans = 0;
    st.push(A[0]);
    for (int i = 1; i < n; i++) {
        int v = A[i];
        while (!st.empty() && st.top() < v) {
            ans++;
            st.pop();
        }

        if (!st.empty()) ans++;
        st.push(v);
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