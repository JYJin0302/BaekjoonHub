#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n;
ll w;

vector<int> adj[252525];
vector<ll> A[252525];
int P[252525];
ll dist[252525];

vector<ll> dp[252525];
int ans = 0;

void dfs(int v){

    for(auto f : adj[v]){
        dfs(f);

        if((int)dp[v].size() < (int)dp[f].size()) swap(dp[v], dp[f]);

        for(int i = (int)dp[f].size() - 1; i >= 0; i--){
            if (dp[f][i] - dist[v] > w) break;

            int iter = (int)dp[v].size();
            int l = 0, r = (int)dp[v].size() - 1;
            while(l <= r){
                int md = (l+r)>>1;
                if (dp[v][md] + dp[f][i] - 2 * dist[v] <= w) {
                    iter = md;
                    r = md - 1;
                }
                else l = md + 1;
            }

            ans = max(ans, (int)dp[f].size() - i + (int)dp[v].size() - iter);
        }

        for(int i = (int)dp[f].size() - 1; i >= 0; i--){
            int ix = (int)dp[f].size() - i;
            int vx = (int)dp[v].size() - ix;
            dp[v][vx] = min(dp[v][vx], dp[f][i]); 
        }
    }

    for(auto f : A[v]) dp[v].push_back(f);

    int sz = min((int)A[v].size() + 1, (int)dp[v].size());

    for(int i = 0; i < sz; i++){
        ll pre = dp[v][(int)dp[v].size() - i - 1];

        int l = 0, r = (int)dp[v].size() - i - 1;
        while(l <= r){
            int md = (l+r)>>1;
            if (dp[v][md] - pre <= w) {
                ans = max(ans, (int)dp[v].size() - i - 1 - md + 1);
                r = md - 1;
            }
            else l = md + 1;
        }
    }
    
    // cout << "Dp v : " << v << " => ";
    // for(auto f : dp[v]) cout << f << ' ';
    // cout << '\n';
}

void solve(){

    cin >> n >> w;

    for(int i = 2; i <= n; i++){
        ll l;
        int p, k;
        cin >> p >> l >> k;

        P[i] = p;
        dist[i] = dist[p] + l;
        adj[p].push_back(i);
        
        while(k--){
            ll v;
            cin >> v;
            A[i].push_back(dist[p] + v);
        }
        reverse(all(A[i]));
    }

    dfs(1);

    cout << ans << '\n';
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