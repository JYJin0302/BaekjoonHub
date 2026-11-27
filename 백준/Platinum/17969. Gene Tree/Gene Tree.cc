#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

ll ans = 0;
vector<pair<ll, ll>> adj[100001];
ll sqr[100001];
ll sum[100001];
ll num[100001];

void dfs(int v, int pv = -1){
    
    bool isLeaf = (adj[v].size() == 1);
    
    for (auto i : adj[v]) if (i.x != pv){
        dfs(i.x, v);
        
        ll nsqr = sqr[i.x] + 2*i.y*sum[i.x] + i.y*i.y*num[i.x];
        ll nsum = sum[i.x] + num[i.x]*i.y;
        
        ans += sqr[v]*num[i.x] + nsqr*num[v] + nsum*sum[v]*2;
        
        num[v] += num[i.x];
        sum[v] += nsum;
        sqr[v] += nsqr;
    }
    if (isLeaf) {
        num[v]++;
        ans += sqr[v];
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    dfs(1);
    
    cout << ans;
}