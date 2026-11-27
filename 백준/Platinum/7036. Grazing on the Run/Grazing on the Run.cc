#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 1e15;

ll n, l, ix;
ll dp[2][1010][1010];
vector<ll> A;

ll getDp(int t, int l, int r) {
    if (dp[t][l][r] != INF) return dp[t][l][r];
    if (l > ix || r < ix) return INF;

    ll rem = n - (r - l);
    ll ret = INF;
    if (t == 0) {
        ret = min(ret, getDp(0, l + 1, r) + rem * (A[l + 1] - A[l]));
        ret = min(ret, getDp(1, l + 1, r) + rem * (A[r] - A[l]));
    }
    else {
        ret = min(ret, getDp(0, l, r - 1) + rem * (A[r] - A[l]));
        ret = min(ret, getDp(1, l, r - 1) + rem * (A[r] - A[r - 1]));
    }

    //cout << t << ' ' << l << ' ' << r << " | " << ret << '\n';
    return dp[t][l][r] = ret;
}
void solve() {

    cin >> n >> l;
    A = vector<ll> (n);
    bool isin = 0;
    for (auto& i : A) {
        cin >> i;
        if (i == l) isin = 1;
    }
    if (!isin) A.push_back(l);
    sort(all(A));
    n++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[0][i][j] = dp[1][i][j] = INF;
        }
    }

    ix = lower_bound(all(A), l) - A.begin();
    dp[0][ix][ix] = dp[1][ix][ix] = 0;

    cout << min(getDp(1, 0, n - 1), getDp(0, 0, n - 1));

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}