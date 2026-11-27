#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<ll> num;
int getIdx(ll x) {
    return lower_bound(all(num), x) - num.begin();
}

ll dp[2020][2020];
void solve() {

    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    num = A;
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    int sz = num.size();
    for (int i = 0; i < sz; i++) {
        dp[0][i] = abs(A[0] - num[i]);
    }

    for (int i = 1; i < n; i++) {
        ll pv = dp[i-1][0];
        dp[i][0] = pv + abs(A[i] - num[0]);
        for (int j = 1; j < sz; j++) {
            pv = min(pv, dp[i - 1][j]);
            dp[i][j] = pv + abs(A[i] - num[j]);
        }
    }

    ll ans = 1e18;
    for (int i = 0; i < sz; i++) ans = min(ans, dp[n - 1][i]);

    for (int i = 1; i < n; i++) {
        ll pv = dp[i - 1][sz - 1];
        dp[i][sz - 1] = pv + abs(A[i] - num[sz - 1]);
        for (int j = sz -2; j >= 0; j--) {
            pv = min(pv, dp[i - 1][j]);
            dp[i][j] = pv + abs(A[i] - num[j]);
        }
    }
    for (int i = 0; i < sz; i++) ans = min(ans, dp[n - 1][i]);
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}