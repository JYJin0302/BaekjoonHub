#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200001];
int topo[200001];
int cyc[200001];
int dep[200001];
int val[200001];

int dp[18][200001];

void dfs(int v, int pv = -1){
    for (auto i : adj[v]) if (i != pv && topo[i] != 2){
        dep[i] = dep[v] + 1;
        cyc[i] = cyc[v];
        dp[0][i] = v;
        dfs(i, v);
    }
}

void dfs2(int v, int pv = -1){
    for (auto i : adj[v]) if (i != pv && topo[i] != 2){
        dfs2(i, v);
        val[v] += val[i];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> inp(n);
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        inp[i] = {a, b};
        adj[a].push_back(b);
        adj[b].push_back(a);
        topo[a]++, topo[b]++;
    }
    
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if (topo[i] == 1) q.push(i);
    }
    while(!q.empty()){
        int a = q.front();
        q.pop();
        for (auto i : adj[a]){
            topo[i]--;
            if (topo[i] == 1) q.push(i);
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (topo[i] == 2){
            cyc[i] = i;
            dfs(i);
        }
    }
    
    // sparse
    for (int i = 1; i < 18; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    
    int cyc_cnt = 0;
    while(m--){
        
        int a, b, c;
        cin >> a >> b >> c;
        
        if (cyc[a] == cyc[b]){
            
            int ta = a, tb = b;
            // least common ancestor
            if (dep[a] > dep[b]) swap(a, b);
            int diff = dep[b] - dep[a];
            for (int i = 0; i < 18; i++){
                if (diff & (1 << i)) b = dp[i][b];
            }
            
            for (int i = 17; i >= 0; i--){
                
                int na = dp[i][a], nb = dp[i][b];
                if (na != nb){
                    a = na, b = nb;
                }
            }
            if (a != b) a = dp[0][a];
            
            val[ta] += c;
            val[tb] += c;
            val[a] -= 2*c;
        }
        else {
            
            cyc_cnt += c;
            int ta = a, tb = b;
            for (int i = 17; i >= 0; i--){
                if (dp[i][a] != 0) a = dp[i][a];
                if (dp[i][b] != 0) b = dp[i][b];
            }
            
            val[ta] += c;
            val[tb] += c;
            val[a] -= c;
            val[b] -= c;
        }
    }
    
    for (int i = 1; i <= n; i++){
        if (topo[i] == 2) dfs2(i);    
    }
    
    for (int i = 0; i < n; i++){
        int a, b;
        tie(a, b) = inp[i];
        if (cyc[a] == cyc[b]){
            if (dep[a] > dep[b]) swap(a, b);
            cout << val[b] << '\n';
        }
        else{
            cout << cyc_cnt << '\n';
        }
        
    }
    
    
}