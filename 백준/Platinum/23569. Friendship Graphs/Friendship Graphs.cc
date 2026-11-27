#include <bits/stdc++.h>
using namespace std;

int conn[1001][1001];

vector<int> adj[1001];
int col[1001];  // 0 : not visited, 1, 2 : color

bool ok = 1;
int c1 = 0, c2 = 0;

void dfs(int v, int pv = 0){
    
    for (auto i : adj[v]) if (i != pv){
        if (col[i] == col[v]) ok = 0;
        else if (col[i] == 0){
            col[i] = 3 - col[v];
            if (col[v] == 1) c2++;
            else c1++;
            dfs(i, v);
        }
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    while(m--){
        int a, b;
        cin >> a >> b;
        
        conn[a][b] = 1;
        conn[b][a] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (conn[i][j] == 0) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    
    vector<int> A;
    for (int i = 1; i <= n; i++){
        c1 = 1, c2 = 0;
        if (col[i] == 0) {
            col[i] = 1;
            dfs(i);
            A.push_back(abs(c2 - c1));
        }
    }
    
    if (!ok) {
        cout << -1;
        return 0;
    }
    
    int dp[1001][1001];
    memset(dp, 0, sizeof(dp));
    int tn = A.size();
    
    int tot = 0;
    for(int i : A) tot += i;
    
    dp[0][0] = 1;
    for (int i = 1; i <= tn; i++){
        for (int j = 0; j <= tot; j++){
            if(dp[i-1][j] == 1) dp[i][j] = 1;
            if (j - A[i-1] >= 0 && dp[i-1][j-A[i-1]] == 1) dp[i][j] = 1;
        }
    }
    
    int ans = 1000;
    for (int i = 0; i <= 1000; i++){
        if (dp[tn][i] == 1) ans = min(ans, abs(tot - 2*i));
    }
    cout << ans;
}