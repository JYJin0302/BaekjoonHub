#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int lim = 2000000;
int dp[2001010];
int getVal(int x) {
    if (dp[x] != -1) return dp[x];
    if (x == 0) return 0;

    int res = 0;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res += i;
            if (i*i != x) res += x / i;
        }
    }
    res -= x;
    return dp[x] = res;
}

bool vis[2002020];

void solve() {
    memset(dp, -1, sizeof(dp));
    int l, r;
    cin >> l >> r;
    
    for (int i = l; i <= r; i++) {
        int pv = i;
        bool ok = 1;
        vector<int> res = { i };
        vis[i] = 1;
        while (1) {
            int nxt = getVal(pv);
            if (nxt < i || nxt > lim) {
                ok = 0;
                break;
            }
            if (vis[nxt]) {
                if (nxt != i) ok = 0;
                break;
            }
            pv = nxt;
            vis[pv] = 1;
            res.push_back(pv); 
        }
       // cout << '\n';

        if (ok) {
            for (auto f : res) cout << f << ' ';
            cout << '\n';
        }

        for (auto f : res) vis[f] = 0;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}