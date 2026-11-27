#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int G[404][404];

void solve() {

    int n;
    cin >> n;

    vector<int> T(n);
    for (auto& i : T) cin >> i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> G[i][j];
    }

    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        A.push_back(mp(T[i], i));
    }
    sort(all(A));
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++) {
        auto [a, b] = A[i];

        int ans = 0;
        if (G[0][b] <= T[b]) ans = 1;
        for (int j = 0; j < i; j++) {
            auto [x, y] = A[j];
            if (dp[y] != -1 && T[y] + G[y][b] <= T[b]) {
                ans = max(ans, dp[y] + 1);
            }
        }
        dp[b] = ans;
    }

    int ans = max(0, *max_element(all(dp)));
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}