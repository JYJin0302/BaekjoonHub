#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, k;
    cin >> n >> k;

    vector<__int128> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= k; i++){
        for (int j = i; j <= n; j++) {
            dp[j] += dp[j - i];
        }
    }
    
    string res;
    while(dp[n]){
        res += char('0' + dp[n] % 10);
        dp[n] /= 10;
    }
    if (res.empty()) res = "0";
    reverse(all(res));
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}