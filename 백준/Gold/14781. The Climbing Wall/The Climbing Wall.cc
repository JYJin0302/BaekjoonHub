#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int INF = 1e8;
vector<pair<int, int>> pos[30303];
int dp[10101];

void solve() {

    int h, n;
    cin >> h >> n;
    for (int i = 0; i <= n; i++) {
        dp[i] = INF;
    }

    queue<int> q;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        A[i] = mp(a, b);
        pos[a].push_back(mp(b, i));

        if (b <= 1000) {
            q.push(i);
            dp[i] = 1;
        }
    }

    for (int i = 0; i <= 30000; i++) {
        sort(all(pos[i]));
    }

    while (!q.empty()) {
        int a = q.front(); q.pop();
        int cx, cy;
        tie(cx, cy) = A[a];
        int l = max(0, cx - 1000);
        int r = min(30000, cx + 1000);

        if (cy + 1000 >= h) {
            cout << dp[a];
            return;
        }

        for (int i = l; i <= r; i++) {
            int d = sqrt(1000000 - (cx - i) * (cx - i));

            auto iter = lower_bound(all(pos[i]), mp(cy - d, -1));
            while (iter != pos[i].end() && (*iter).first <= cy + d) {
                int nx = (*iter).second;
                if (dp[nx] == INF) {
                    dp[nx] = dp[a] + 1;
                    q.push(nx);
                }
                iter++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}