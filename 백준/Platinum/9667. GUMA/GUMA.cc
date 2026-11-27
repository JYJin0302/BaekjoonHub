#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


ll ans = 0;
int dp[101010];

int go(int n) {
    if (dp[n] != -1) return dp[n];

    int tot = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            tot += go(i);
            if (n / i != i) tot += go(n / i);
        }
    }

    dp[n] = n - 1 - tot;
    ans += dp[n];
    return dp[n];
}


void solve() {

    memset(dp, -1, sizeof dp);

    int n;
    cin >> n; 
    vector<int> A(n + 1);
    for (auto& i : A) cin >> i;
    //sort(all(A));
    //reverse(all(A));

    for (auto f : A) {
        go(f);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}