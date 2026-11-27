#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

const int INF = 0x3f3f3f3f;
vector<int> adj[3030];
int dp[3030][3030]; // dp[i][j] : subtree(i) 에서 j개를 잘라내기 위한 최소 개수

int sz[3030];
int ans[3030];

void dfs(int v, int pv = -1) {
    sz[v] = 1;

    dp[v][0] = 0;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);

        vector<int> tdp(3030, INF);

        for (int i = 0; i < sz[v]; i++) {
            for (int j = 1; j <= sz[f]; j++) {
                tdp[i + j] = min(tdp[i + j], dp[v][i] + dp[f][j] + (j == sz[f]));
            }
        }
        sz[v] += sz[f];
        for (int i = 0; i <= sz[v]; i++) dp[v][i] = min(dp[v][i], tdp[i]);
    }
    dp[v][sz[v]] = 0;
}

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dp, INF, sizeof dp);
    memset(ans, INF, sizeof ans);

    dfs(1);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sz[i]; j++) {
            ans[sz[i] - j] = min(ans[sz[i] - j], dp[i][j] + (i == 1 ? 0 : 1));
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << ans[x] << '\n';
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}