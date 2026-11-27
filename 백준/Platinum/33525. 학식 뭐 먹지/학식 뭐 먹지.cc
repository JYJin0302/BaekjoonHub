#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 1e15;
ll dp[101][1010]; // dp[a][b] : a가지 종류로 n 개 채움 => 최소 비용

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> A(m);
    for (auto& [a, b] : A) cin >> a >> b;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (int i = 0; i < m; i++) {
        auto [a, b] = A[i];

        deque<pair<ll, ll>> dq;

        for (int u = m - 1; u >= 0; u--) {
            dq.push_back(mp(dp[u][0], 0));
            for (int v = 1; v <= n; v++) {
                while (!dq.empty() && dq.front().y < v - b) dq.pop_front();
                if (!dq.empty()) dp[u + 1][v] = min(dp[u + 1][v], dq.front().x + v * a);
                dp[u + 1][v] = min(dp[u + 1][v], dp[u][v]);

                while (!dq.empty() && dq.back().x >= dp[u][v] - v * a) dq.pop_back();
                dq.push_back(mp(dp[u][v] - v * a, v));
            }

            while (!dq.empty()) dq.pop_back();
        }

        /*cout << "Done: " << a << ' ' << b << '\n';
        for (int u = 1; u <= m; u++) {
            for (int v = 0; v <= n; v++) {
                cout << dp[u][v] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';*/
    }

    ll ans = INF;
    for (int i = 1; i <= m; i++) {
        if (dp[i][n] != INF) ans = min(ans, dp[i][n] * i);
    }
    cout << ans << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}