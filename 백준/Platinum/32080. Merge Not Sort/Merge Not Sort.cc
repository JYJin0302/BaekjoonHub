#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool dp[2020][2020];

void solve() {

    int n;
    cin >> n;
    vector<int> A(n * 2);
    for (auto& i : A) cin >> i;

    vector<pair<int, int>> B;
    int ix = 0;
    while (ix < n * 2) {
        int nx = ix + 1;
        while (nx < n * 2 && A[nx] < A[ix]) nx++;

        B.push_back(mp(nx - ix, ix));
        ix = nx;
    }

    int sn = B.size();

    dp[0][0] = 1;
    for (int i = 1; i <= sn; i++) {
        int len = B[i-1].x;
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - len >= 0 && dp[i - 1][j - len]) dp[i][j] = 1;
        }
    }

    if (!dp[sn][n]) {
        cout << -1;
        return;
    }

    vector<bool> chk(n * 2);


    int cx = sn, cy = n;
    while (cx > 0) {
        int len = B[cx - 1].x;
        if (cy - len >= 0 && dp[cx - 1][cy - len]) {
            cy -= len;
            for (int f = 0; f < len; f++) {
                chk[B[cx - 1].y + f] = 1;
            }
        }
        cx--;
    }

    for (int i = 0; i < n * 2; i++) if (!chk[i]) cout << A[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n * 2; i++) if (chk[i]) cout << A[i] << ' ';
    cout << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}