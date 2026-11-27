#include <bits/stdc++.h>
using namespace std;

vector<int> adj[50001];
int sT[50001][17];
int dep[50001];

int dp[50001];

void dfs(int v, int pv = -1){
    for(auto i : adj[v]) if (i != pv){
        dep[i] = dep[v] + 1;
        dfs(i, v);
        sT[i][0] = v;
    }
}

void solve(int v, int pv = -1){
    for(auto i : adj[v]) if (i != pv){
        solve(i, v);
        dp[v] += dp[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    for(int i =0 ; i <n -1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dep[1] = 1;
    dfs(1);
    
    for (int i = 1; i <= 16; i++){
        for(int j = 1; j <= n; j++){
            sT[j][i] = sT[sT[j][i-1]][i-1];
        }
    }
    
    while(k--){
        int a, b;
        cin >> a >> b;
        
        if (dep[a] < dep[b]) swap(a, b);
        int diff = dep[a] - dep[b];
        int ta = a, tb = b;
        
        for (int i = 0; i <= 16; i++){
            if (diff & (1 << i)) {
                ta = sT[ta][i];
            }
        }
        
        for (int i = 16; i >= 0; i--){
            if (sT[ta][i] != sT[tb][i]) {
                ta = sT[ta][i];
                tb = sT[tb][i];
            }
        }
        if (ta != tb) ta = sT[ta][0];
        tb = sT[ta][0];
        
        dp[a]++, dp[b]++;
        dp[ta]--, dp[tb]--;
        
    }
    
    solve(1);
    
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans;
}