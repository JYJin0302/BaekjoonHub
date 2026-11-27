#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;

int n, m;
vector<int> adj[300001];
bool b[300001];

// child 부터
ll val[300001]; // a^2 + b^2 + ...
ll sum[300001]; // a + b + ...
ll num[300001]; // 개수

// parent 부터
ll t_val[300001];
ll t_sum[300001];


void dfs(int v, int pv = -1){
    for (auto i : adj[v]) if (i != pv){
        dfs(i, v);
        
        val[v] += val[i] + 2*sum[i] + num[i];
        val[v] %= mod;
        sum[v] += sum[i] + num[i];
        sum[v] %= mod;
        num[v] += num[i];
    }
    num[v] += b[v];
}

void dfs2(int v, int pv = -1){
    for (auto i : adj[v]) if (i != pv){
        t_sum[i] = t_sum[v] + sum[v] - (sum[i]+num[i]) + m - num[i];
        t_sum[i] = (t_sum[i] + mod*mod) % mod;
        
        t_val[i] = t_val[v] + val[v] - (val[i] + 2*sum[i] + num[i]);
        t_val[i] += 2*(t_sum[v] + sum[v] - (sum[i]+num[i])) + m - num[i];
        t_val[i] = (t_val[i] + mod*mod) % mod;
        dfs2(i, v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    cin >> m;
    
    for(int i = 0; i < m;i++){
        int x;
        cin >> x;
        b[x] = 1;
    }
    
    dfs(1);
    dfs2(1);
    
    
    for (int i =1; i <= n; i++) t_val[i] = (t_val[i] + val[i]) % mod;
    
    ll ans = 0;
    int k;
    cin >> k;
    while(k--){
        int x;
        cin >> x;
        ans = (ans + t_val[x]) % mod;
    }
    cout << ans;
}