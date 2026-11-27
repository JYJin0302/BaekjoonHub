#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    ll n, k;
    cin >> n >> k;

    vector<ll> A(n), sA(n * 2+1);
    for (auto& i : A) cin >> i;

    for (int i = 1; i <= 2 * n; i++) {
        sA[i] = sA[i - 1] + (i <= n ? A[i - 1] : 0);
    }

    ll mx = 0;
    vector<ll> dp(2 * n + 10);
    for (int i = 1; i <= 2*n; i++) {
        ll val = sA[i];
        if (i - k >= 0) {
            ll tm = dp[i - k] - sA[i - k];
            mx = max(mx, tm);
        }

        dp[i] = max(mx + sA[i], dp[i - 1]);
    }

    cout << *max_element(all(dp));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}