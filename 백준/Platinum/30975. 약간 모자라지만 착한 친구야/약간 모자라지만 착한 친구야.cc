#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

vector<pair<int, int>> adj[16];

int n, m;
int dp[16][1 << 16];
int P[20];

string pf(int mask) {

    string res;
    for (int i = 0; i <= n; i++) {
        bool x = mask & (1 << i);
        res += char('0' + x);
    }
    return res;
}

int getDp(int x, int mask) {

    if (dp[x][mask] != -1) return dp[x][mask];
    if (mask == 0) {
        return 1e8;
    }
    if (mask & (1 << x)) {}
    else return dp[x][mask] = 1e8;
   // cout << "Go: " << x << ' ' << pf(mask) << '\n';


    int newMask = mask ^ (1 << x);
    int res = 1e8;
    for (auto& [a, b] : adj[x]) {

        int ti = P[a];
        if (newMask & (1 << ti)) {}
        else continue;

        res = min(res, getDp(a, newMask) + b);
    }

    return dp[x][mask] = res;
}

void solve() {

    memset(dp, -1, sizeof(dp));


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> P[i];
        P[i]--;
    }
    P[n] = n;

    while (m--) {

        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        adj[b].push_back(mp(a, c));

        if (a == n) {
            if (dp[b][1 << b] == -1) dp[b][1 << b] = c;
            else dp[b][1 << b] = min(dp[b][1 << b], c);
        }
    }

    int ans = getDp(n, (1 << (n + 1)) - 1);
    if (ans == 1e8) ans = -1;
    

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
