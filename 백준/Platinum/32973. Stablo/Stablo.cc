#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int P[505050];
ll V[505050];
vector<int> adj[505050];
ll dp[505050][2];
ll spt[20][505050];
ll sptV[20][505050];
int dep[505050];

void dfs(int v, int pv = -1){
    dp[v][1] += V[v];
    for(auto f : adj[v]) if(f != pv){
        dep[f] = dep[v] + 1;
        spt[0][f] = v;
        dfs(f, v);
        dp[v][0] += dp[f][0] + dp[f][1];
        dp[v][1] += dp[f][1];
        sptV[0][f] = V[f];
    }

    //cout << "DP: "<< v <<  ' ' << dp[v][0] << ' ' << dp[v][1] << '\n';
}

void solve(){
    
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) cin >> V[i];
    for(int i = 2; i <= n; i++){
        cin >> P[i];
        adj[P[i]].push_back(i);
    }
    
    dfs(1);

    for(int k = 1;k < 20; k++){
        for(int i = 1; i <= n;i++){
            spt[k][i] = spt[k-1][spt[k-1][i]];
            sptV[k][i] = sptV[k-1][i] + sptV[k-1][spt[k-1][i]];
        }
    }

    while(q--){
        int x, y;
        cin >> x >> y;

        if (P[x] == y){
            cout << dp[y][0] << '\n';
        }
        else{
            ll ans = dp[y][0];
            ans -= V[x] * (dep[x] - dep[y] - 1);

            int cur = P[x];
            int dif = dep[cur] - dep[y] - 1;
            for(int i = 0; i < 20 ;i++){
                if (dif & (1 << i)){
                    cur = spt[i][cur];
                }
            }
            ans += dp[cur][1] - dp[x][1];

            cout << ans << '\n';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
