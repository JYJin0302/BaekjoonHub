#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, m, k, t;
    cin >> n >> m >> k >> t;

    vector<int> A(n + 10);

    while (m--) {
        int a, b;
        cin >> a >> b;
        A[a]++;
        A[b]--;
    }

    for (int i = 1; i <= n; i++) A[i] += A[i - 1];

    int ans = 0;
    int ix = 1;

    vector<int> dp(k + 1);

    while (ix <= n) {

        //cout << "Go: " << ix << '\n';
        while (ix <= n && A[ix] >= t) {
            ans++;
            ix++;
        }

        if (ix > n) break;


        int nx = ix;
        while (nx <= n && A[nx] < t) nx++;

       // cout << ix << ' ' << nx << '\n';
        vector<int> cnt(t + 1);
        for (int j = ix; j < nx; j++) {
            cnt[t - A[j]]++;
        }

        for (int i = 1; i <= t; i++) cnt[i] += cnt[i - 1];

        vector<int> ndp(k + 1);
        for (int i = 1; i <= min(k, t); i++) {
            for (int j = i; j <= k; j++) {
                ndp[j] = max(ndp[j], dp[j - i] + cnt[i]);
            }
        }

        for (int i = 1; i <= k; i++) ndp[i] = max({ dp[i], ndp[i], ndp[i - 1] });
        swap(ndp, dp);

        ix = nx;
    }

    cout << ans + dp[k] << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}