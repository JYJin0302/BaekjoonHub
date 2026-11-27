#include <bits/stdc++.h>
using namespace std;
#define INF 10000000

int f[401][401];
int c[401][401];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
        c[a][b] = 1;
    }
    
    int ans = 0;
    while(1){
        
        vector<int> from(n+1, -1);
        from[1] = 1;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            
            int a = q.front();
            q.pop();
            
            for (auto i : adj[a]){
                if (from[i] == -1 && c[a][i] - f[a][i] > 0){
                    from[i] = a;
                    q.push(i);
                }
            }
        }
        
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