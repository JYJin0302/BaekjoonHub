#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool dp[505][505];
int from[505][505];

void solve() {

    int n;
    cin >> n;

    vector<int> A(2*n - 1);
    for (auto& i : A) cin >> i;

    dp[0][0] = 1;
    for (int i = 1; i <= 2* n - 1; i++) {
        int v = A[i - 1];
        for (int j = min(i - 1, n); j >= 0; j--) {
            for (int k = 0; k < n; k++) {
                if (dp[j][k]) {
                    int nk = (k + v) % n;
                    if (!dp[j + 1][nk]) {
                        dp[j + 1][nk] = 1;
                        from[j + 1][nk] = v;
                    }
                }
            }
        }
    }

    if (dp[n][0]) {

        int cur = 0;
        for (int i = n; i >= 1; i--) {
            int v = from[i][cur];
            cout << v << ' ';
            cur = (cur + n - v) % n;
        }

    }
    else cout << -1;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}