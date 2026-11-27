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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {

        int mn, mx;
        mn = mx = A[i];
        for (int j = i; j > 0; j--) {
            mn = min(mn, A[j]);
            mx = max(mx, A[j]);

            dp[i] = max(dp[i], dp[j - 1] + abs(mx - mn));
        }
    }
    cout << dp[n] << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}