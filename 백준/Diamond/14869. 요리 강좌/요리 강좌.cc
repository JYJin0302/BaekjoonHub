#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 0x3f3f3f3f3f3f3f3f;

ll G[3030][3030];
ll dp[3030][3030];
vector<pair<ll, ll>> res[3030];

deque<pair<ll, ll>> dp2[3030];

void solve() {
    int n, m, s, e, t;
    cin >> n >> m >> s >> e >> t;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
            G[i][j] += G[i][j - 1];
        }
    }

    vector<int> no(n + 1);
    for (int i = 1; i <= n; i++) cin >> no[i];

    for (int i = 1; i <= n; i++) {
        dp2[i].push_back(mp(0, 0));
    }

    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= n; i++) dp[i][0] = 0;

    for (int i = s; i < m; i++) {
        for (int j = 1; j <= n; j++) {
            while (!dp2[j].empty() && dp2[j].front().second < i - e) dp2[j].pop_front();
            if (!dp2[j].empty()) dp[j][i] = G[j][i] + dp2[j].front().x;
        }

        vector<pair<ll, ll>> tmp;
        for (int f = 1; f <= n; f++) {
            tmp.push_back(mp(dp[f][i - s + 1], f));
        }
        sort(all(tmp));

        for (int k = 1; k <= n; k++) {            
            int ix = 0;
            while (tmp[ix].y == k || tmp[ix].y == no[k]) ix++;
            auto [a, b] = tmp[ix];
            a += t;
            // update with a - G[k][i-s+1]
            while (!dp2[k].empty() && dp2[k].back().first >= a - G[k][i - s + 1]) {
                dp2[k].pop_back();
            }
            dp2[k].push_back(mp(a - G[k][i - s + 1], i - s + 1));
        }
    }

    for (int i = m - s + 1; i < m; i++) {
        vector<pair<ll, ll>> tmp;
        for (int f = 1; f <= n; f++) {
            tmp.push_back(mp(dp[f][i], f));
        }
        sort(all(tmp));
        for (int k = 1; k <= n; k++) {
            int ix = 0;
            while (tmp[ix].y == k || tmp[ix].y == no[k]) ix++;
            auto [a, b] = tmp[ix];
            a += t;
            // update with a - G[k][i]
            while (!dp2[k].empty() && dp2[k].back().first >= a - G[k][i]) {
                dp2[k].pop_back();
            }
            dp2[k].push_back(mp(a - G[k][i], i));
        }
    }

    


    ll ans = INF;
    for (int i = 1; i <= n; i++) {
        while (!dp2[i].empty() && dp2[i].front().y < m - e) dp2[i].pop_front();
        if (!dp2[i].empty()) {
            ans = min(ans, dp2[i].front().x + G[i][m]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}