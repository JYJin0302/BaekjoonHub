#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % m;
        b = b * b % m;
        ex /= 2;
    }
    return res;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int dp[5001][5001];

void solve() {

    int n, a, l;
    cin >> n >> a >> l;
    
    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= l; j++) dp[i][j] = -1;
    }
    dp[0][l] = a;
    for (int i = 1; i <= n; i++) {
        int x, y;
        tie(x, y) = A[i - 1];
        for (int j = 1; j <= l; j++) {
            if (dp[i - 1][j] != -1) {
                if (y != -1) {
                    int nj = max(0, j - y);
                    dp[i][nj] = max(dp[i][nj], dp[i - 1][j]);
                }
                
                if (x != -1 && (y == -1 || x <= dp[i-1][j])) {
                    int ni = max(0, dp[i-1][j] - x);
                    dp[i][j] = max(dp[i][j], ni);
                }
            }
        }
    }


    int ix = -1, curr = n;
    for (int i = 1; i <= l; i++) {
        if (dp[n][i] != -1) ix = i;
    }

    if (ix == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    vector<char> ans;

    while (curr > 0) {
        int x, y;
        tie(x, y) = A[curr - 1];

        int ni = ix;
        while (ni <= l) {
            // check dp[curr-1][ni] -> dp[curr][ix] valid

            if (dp[curr - 1][ni] == -1) {
                ni++;
                continue;
            }

            if (y != -1) {
                int nj = max(0, ni - y);
                if (nj == ix && dp[curr][nj] == dp[curr - 1][ni]) {
                    ans.push_back('L');
                    break;
                }
            }

            if (x != -1 && (y == -1 || x <= dp[curr - 1][ni])) {
                int nx = max(0, dp[curr - 1][ni] - x);
                if (ix == ni && dp[curr][ix] == nx) {
                    ans.push_back('A');
                    break;
                }
            }


            ni++;
        }

        ix = ni;
        curr--;
    }

    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}