#include <bits/stdc++.h>
using namespace std;
#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define FOR(i, n) for (int i = 0; i < n; i++)

int V, Q, K;
vvi adj;
vector<vvi> dp; // 노드, RGB, %k

void dfs(int v, int pv = 0) {

    for (int i : adj[v]) if (i != pv) {
        dfs(i, v);

        vvi tt(3, vi(K));
        // red
        FOR(k, K) {
            FOR(kk, K) {
                tt[0][(k + kk) % K] += dp[i][0][k] * dp[v][0][kk];
                tt[0][(k + kk) % K] += dp[i][1][k] * dp[v][0][kk];
                tt[0][(k + kk) % K] %= Q;
            }
        }

        // green
        FOR(k, K) {
            FOR(kk, K) {
                tt[1][(k + kk) % K] += dp[i][0][k] * dp[v][1][kk];
                tt[1][(k + kk) % K] += dp[i][2][k] * dp[v][1][kk];
                tt[1][(k + kk) % K] %= Q;
            }
        }

        // blue
        FOR(k, K) {
            FOR(kk, K) {
                tt[2][(k + kk)%K] += dp[i][1][k] * dp[v][2][kk];
                tt[2][(k + kk)%K] %= Q;
            }
        }

        dp[v] = tt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
   
    cin >> V >> Q >> K;

    adj = vvi(V + 1);
    dp = vector<vvi>(V + 1, vvi(3, vi(K)));

    FOR(i, V - 1) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    FOR(i, V) FOR(j, 3) {
        int x;
        cin >> x;
        x %= K;
        dp[i+1][j][x] = 1;
    }

    dfs(1);

    int ans = 0;
    FOR(j, 3) {
        ans += dp[1][j][0];
        ans %= Q;
    }

    cout << ans;
}