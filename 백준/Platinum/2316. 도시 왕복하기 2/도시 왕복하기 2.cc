#include <bits/stdc++.h>
using namespace std;
#define INF 10000000

int f[801][801];
int c[801][801];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(801);
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
              
        adj[a+400].push_back(b);
        adj[b].push_back(a+400);
        c[a+400][b] = 1000;
        
        adj[b+400].push_back(a);
        adj[a].push_back(b+400);
        c[b+400][a] = 1000;
    }
    
    for(int i = 1; i <= n; i++) {
        c[i][i+400] = 1;
        adj[i].push_back(i+400);
        adj[i+400].push_back(i);
    }
    c[1][401] = 1000;
    c[2][402] = 1000;
    
    int ans = 0;
    while(1){
        
        vector<int> from(801, -1);
        from[1] = 1;
        queue<int> q;
        q.push(1);
        while(!q.empty() && from[2] == -1){
            
            int a = q.front();
            q.pop();
            for (auto i : adj[a]){
                if (from[i] == -1 && c[a][i] - f[a][i] > 0){
                    from[i] = a;
                    q.push(i);
                }
            }
        }
        while(!q.empty()) q.pop();
        if (from[2] == -1) break;
        
        ans++;
        int k = 2;
        while(k != 1){
            int nk = from[k];
            f[nk][k]++;
            f[k][nk]--;
            k = nk;
        }
    }
    
    cout << ans;
    
}