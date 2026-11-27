#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

int n, m;
int S[55];

vector<int> lst[1 << 18];
int dp[55][1 << 18];
int getDp(int ix, int msk) {

    if (dp[ix][msk] != -1) return dp[ix][msk];
    dp[ix][msk] = 1000;

    int rx = ix;
    while (rx < lst[msk].size() && lst[msk][rx] == lst[msk][ix]) rx++;

    int len = rx - ix;
    if (len == 1) return dp[ix][msk] = 0;

    int ret = 1000;
    int curS = lst[msk][ix];
    for (int i = 0; i < n; i++) {
        if (msk & (1 << i)) continue;
        int nmsk = msk | (1 << i);

        int ix1 = lower_bound(all(lst[nmsk]), curS) - lst[nmsk].begin();
        if (ix1 < lst[nmsk].size() && lst[nmsk][ix1] == curS) {}
        else continue;

        int ix2 = lower_bound(all(lst[nmsk]), curS | (1 << i)) - lst[nmsk].begin();
        if (ix2 < lst[nmsk].size() && lst[nmsk][ix2] == (curS | (1 << i))) {}
        else continue;

        ret = min(ret, getDp(ix1, nmsk) + getDp(ix2, nmsk));
    }
    return dp[ix][msk] = ret + len;

}


void solve() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            S[i] |= 1 << x;
        }
    }

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < m; j++) {
            lst[i].push_back(i & S[j]);
        }
        sort(all(lst[i]));
    }

    memset(dp, -1, sizeof dp);

    cout << fixed << setprecision(10);
    int res = getDp(0, 0);
    if (res > 900) cout << "not possible\n";
    else {
        cout << 1.0 * res / m << '\n';
    }


}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}