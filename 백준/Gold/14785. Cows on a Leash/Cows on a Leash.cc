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

    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        A.push_back(mp(a, i + 1));
        A.push_back(mp(a + b, -(i + 1)));
    }
    sort(all(A));

    int ans = 0;
    vector<bool> used(n + 1);
    stack<int> st;

    for (auto [a, b] : A) {
        if (b > 0) {
            st.push(b);
        }
        else {
            b *= -1;
            if (used[b]) continue;
            ans++;
            while (!st.empty()) {
                int x = st.top(); st.pop();
                used[x] = 1;
            }
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