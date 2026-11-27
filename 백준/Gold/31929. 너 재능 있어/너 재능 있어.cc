#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int n, m, k;
int dp[1010][1010];
int A[1010], sA[1010];
int B[1010], sB[1010];
int getDp(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    int ret = 0;
    if (l) {
        ret = max(ret, getDp(l - 1, r));
    }
    if (r) {
        int pv = getDp(l, r - 1);
        int sc = sA[l] - sB[r-1] + pv;

        int rem = (sc + (ll)k * 1000000) % k;
        if (rem == 0) ret = max(ret, pv);
        else ret = max(ret, pv + max(0, B[r] - rem));
    }


    return dp[l][r] = ret;
}

void solve() {
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sA[i] = sA[i - 1] + A[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
        sB[i] = sB[i - 1] + B[i];
    }
    cin >> k;

    memset(dp, -1, sizeof dp);
    int res = getDp(n, m);
    cout << sA[n] - sB[m] + res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}