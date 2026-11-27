#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[101010], rev[101010];

int topo[101010];
int dp[2][101010]; // 0 : 선공 차례, 1 : 후공 차례

const int INF = 1e9;

void solve(){
    
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
        topo[a]++;
    }

    queue<int> q;
    q.push(n);
    while(!q.empty()){
        int a= q.front(); q.pop();

        if (a == n){
            dp[0][n] = INF;
            dp[1][n] = 0;
        }
        else{
            // dp[0][a]
            int val = INF + 10;
            for(auto f : adj[a]){
                val = min(val, dp[1][f]);
            }
            dp[0][a] = val;

            // dp[1][a]
            vector<int> res;
            for(auto f : adj[a]){
                res.push_back(dp[0][f]);
            }
            
            sort(all(res));
            val = INF + 10;
            for(auto f: res){
                int ix = lower_bound(all(res), f + 1) - res.begin();
                ix = (int)res.size() - ix;
                val = min(val, f + ix);
            }
            dp[1][a] = val;
        }

        //cout << "RES: " << a<< " | " << dp[0][a] << ' '<< dp[1][a] << '\n';

        for(auto f: rev[a]){
            topo[f]--;
            if (topo[f] == 0) q.push(f);
        }
    }

    int ans = INF + 10;
    for(int i = 1; i <= n; i++){
        if(rev[i].empty()){
            ans = min(ans, dp[1][i]);
        }
    }
    if (ans >= INF){
        cout << -1 << '\n';
    }
    else cout << ans << '\n';
    


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
