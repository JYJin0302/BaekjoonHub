#include <bits/stdc++.h>
using namespace std;

int f[301][301];
int c[301][301];

int main(){
    
    int t;
    cin >> t;
    while(t--){
        
        memset(f, 0, sizeof(f));
        memset(c, 0, sizeof(c));
        
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> adj(n+1);
        vector<pair<int, int>> edge(m);
        
        for (int i = 0; i < m; i++){        
            int a, b, k;
            cin >> a >> b >> k;
            
            adj[a].push_back(b);
            adj[b].push_back(a);
            edge[i] = {a, b};
            
            c[a][b] += k;
        }
        
        while(1){
            
            vector<int> from(n+1, -1);
            from[1] = 1;
            
            queue<int> q;
            q.push(1);
            
            while(!q.empty()){
                
                int a = q.front();
                q.pop();
                
                for (int i : adj[a]){
                    if (from[i] == -1 && c[a][i] - f[a][i] > 0){
                        from[i] = a;
                        q.push(i);
                    }
                }
            }
            
            if (from[n] == -1) break;
            
            int k = n;
            int mf = 1000;
            
            while(k != 1){
                int fk = from[k];
                mf = min(mf, c[fk][k] - f[fk][k]);
                k = fk;
            }
            
            k = n;
            while(k != 1){
                int nk = from[k];
                f[nk][k] += mf;
                f[k][nk] -= mf;
                k = nk;
            }
        }
        
        int ans = 0;
        for (auto xx : edge){
            
            int i = xx.first;
            vector<int> from(n+1, -1);
            queue<int> q;
            q.push(i);
            
            while(!q.empty()){
                int x = q.front();
                q.pop();
                for (auto k : adj[x]) if (from[k] == -1 && c[x][k] - f[x][k] > 0){
                    from[k] = x;
                    q.push(k);
                }
            }
            
            if (from[xx.second] == -1) ans++;
            
        }
        
        cout << ans << '\n';
    }
    
    
}