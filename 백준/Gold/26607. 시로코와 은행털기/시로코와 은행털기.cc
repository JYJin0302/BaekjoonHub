#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool dp[88][20202];

void solve() {

    int n, k, x;
    cin >> n >> k >> x;
    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.x >> i.y;

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        auto [a, b] = A[i];
        for (int j = i; j >= 0; j--) {
            for (int f = k * x; f >= a; f--) {
                if (dp[j][f - a]) dp[j + 1][f] = 1;
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= k * x; i++) {
        if (dp[k][i]) {
            ans = max(ans, 1ll * i * (k * x - i));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}