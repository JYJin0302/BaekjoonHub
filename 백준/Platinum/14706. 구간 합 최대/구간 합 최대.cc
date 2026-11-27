#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 1e15;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> A(m); 
    for (auto& i : A) cin >> i.first >> i.second;
    sort(all(A));

    vector<ll> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto& [a, b] : A) {
            int tx = max(0ll, i - a);
            dp[i] = min(dp[i], dp[tx] + b);
        }
    }

    for (int i = 1; i <= n; i++) cout << dp[i] << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}