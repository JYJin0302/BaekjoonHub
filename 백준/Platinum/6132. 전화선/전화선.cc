#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 0x3f3f3f3f3f3f3f3f;
ll dp[30][101010];

int n, c;
ll getC(ll a, ll b) {
    return abs(a - b) * c;
}

void solve() {

    memset(dp, INF, sizeof dp);
    cin >> n >> c;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int h = 20;

    for (int i = 0; i <= h; i++) {
        dp[i][0] = i * i;
    }

    for (int i = 1; i < n; i++) {
        for (int a = 0; a <= h; a++) {
            for (int b = 0; b <= h; b++) {
                dp[a][i] = min(dp[a][i], dp[b][i - 1] + a * a + getC(A[i - 1] + b, A[i] + a));
            }
        }
    }

    ll ans = INF;
    for (int j = 0; j <= h; j++) {
        ans = min(ans, dp[j][n - 1]);
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--) solve();
}