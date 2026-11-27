#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> pos[202];
int A[404];

const int mod = 998244353;
int dp[404][404];

ll getDp(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l > r) return dp[l][r] = 1;
    if ((r - l) % 2 == 0) return dp[l][r] = 0;
   // cout << "Go :" << l << ' ' << r << '\n';
    ll res = 0;
    int val = A[l];
    if (pos[val].size() == 2) {
        if (pos[val][0] != l) return dp[l][r] = 0;
        if (pos[val][1] > r) return dp[l][r] = 0;
        res = getDp(l + 1, pos[val][1] - 1) * getDp(pos[val][1] + 1, r) % mod;
        return dp[l][r] = res;
    }

    if (pos[val].size() == 1) {
        for (int i = l + 1; i <= r; i += 2) {
            if (A[i] == 0) {
                res += getDp(l + 1, i - 1) * getDp(i + 1, r) % mod;
                res %= mod;
            }
        }
        return dp[l][r] = res;
    }

    for (int i = l + 1; i <= r; i += 2) {
        if (A[i] == 0 || pos[A[i]].size() == 1) {
            res += getDp(l + 1, i - 1) * getDp(i + 1, r) % mod;
            res %= mod;
        }
    }
    return dp[l][r] = res;

}

void solve() {

    int n;
    cin >> n;

    for(int i = 0; i < n * 2; i++){
        cin >> A[i];
        if(A[i]) pos[A[i]].push_back(i);
    }

    int cc = 0;
    for (int i = 1; i <= n; i++) {
        if (pos[i].empty()) cc++;
    }

    memset(dp, -1, sizeof dp);
    ll ans = getDp(0, 2 * n - 1);
    for (int i = 1; i <= cc; i++) ans = ans * i % mod;
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}