#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[10101];

int ans = 0;
int dp[3][10101];
// 0 : 채워짐
// 1 : 안 채워짐 + 효과 있음
// 2 : 안 채워짐 + 효과 없음

void dfs(int v, int pv = -1) {

    if (adj[v].size() == 1 && pv != -1) {
        dp[0][v] = 1;
        dp[1][v] = 1;
        dp[2][v] = 0;

        return;
    }

    dp[0][v] = 1;
    int tmp = 101010;
    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);

        dp[0][v] += min({ dp[0][f], dp[1][f], dp[2][f] });
        dp[1][v] += min({ dp[0][f], dp[1][f] });
        tmp = min(tmp, dp[0][f] - min({ dp[0][f], dp[1][f] }));
        dp[2][v] += dp[1][f];
    }
    dp[1][v] += tmp;


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

    dfs(1);

    cout << min(dp[0][1], dp[1][1]);
    

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}