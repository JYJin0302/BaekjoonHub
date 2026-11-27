#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int n, m, cnt;
ll lim;

vector<pair<ll, ll>> adj[2001];
ll dp[2001];

void dfs(int v, int pv = -1){
    
    vector<ll> tmp = {0, 0};
    
    for(auto i : adj[v]) if (i.x != pv){
        dfs(i.x, v);
        
        if (dp[i.x] + i.y > lim) cnt++;
        else tmp.push_back(dp[i.x] + i.y);
    }
    sort(tmp.rbegin(), tmp.rend());
    
    int ix = 0;
    while(ix < tmp.size()){
        if (tmp[ix] + tmp[ix+1] > lim){
            ix++;
            cnt++;
        }
        else break;
    }
    
    dp[v] = tmp[ix];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        cin >> n >> m;
        
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
            dp[i] = 0;
        }
        
        for (int i = 0; i < n-1; i++){
            ll a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        
        ll l = 1, r = 2e9, res = 0;
        
        while(l <= r){
            
            lim = (l+r)/2;
            cnt = 0;
            
            dfs(1);
            
            if(n-1 - cnt >= m){
                res = lim;
                r = lim - 1;
            }
            else l = lim + 1;
        }
        
        cout << res << '\n';
    }
    
}