#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1000000;

void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int tot = 0;
    for (auto f : A) tot += f;

    vector<int> dp(tot + 1);
    vector<bool> able(tot + 1);
    able[0] = 1;
    dp[0] = 1;
    for (auto f : A) {
        for (int j = tot; j >= f; j--) {
            (dp[j] += dp[j - f]) %= mod;
            if (able[j - f]) able[j] = 1;
        }
    }

    int md = tot;
    for (int i = 0; i <= tot; i++) {
        if (able[i]) {
            md = min(md, abs(tot - 2 * i));
        }
    }
    
    int ans1 = md;
    int ans2 = 0;
    for (int i = 0; i <= tot; i++) {
        if (able[i] && abs(tot - 2 * i) == md) {
            ans2 = dp[i];
            break;
        }
    }

    cout << ans1 << ' ' << ans2;
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