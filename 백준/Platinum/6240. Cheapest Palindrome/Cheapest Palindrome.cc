#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


ll cost[26][2];
ll dp[2020][2020];
string s;

ll getDp(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l >= r) return dp[l][r] = 0;
    ll res = 1e18;
    if (s[l] == s[r]) {
        res = min(res, getDp(l + 1, r - 1));
    }
    else {
        ll c1 = min(cost[s[l] - 'a'][0], cost[s[l] - 'a'][1]);
        res = min(res, getDp(l + 1, r) + c1);
        c1 = min(cost[s[r] - 'a'][0], cost[s[r] - 'a'][1]);
        res = min(res, getDp(l, r - 1) + c1);
    }
    return dp[l][r] = res;
}

void solve() {

    memset(dp, -1, sizeof dp);
    int n, m;
    cin >> n >> m;

    cin >> s;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        cost[c - 'a'][0] = a;
        cost[c - 'a'][1] = b;
    }

    cout << getDp(0, m - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}