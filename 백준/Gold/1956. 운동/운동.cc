#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

int dist[401][401];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dist[i][j] = INF;
        }
        dist[i][i] = 0;
    }
    
    for(int i = 0; i < m; i++){
        
        int a, b, c;
        cin >> a >> b >> c;
        
        dist[a][b] = c;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    
    
    int ans = INF;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            ans = min(ans, dist[i][j] + dist[j][i]);
        }
    }
    
    if (ans == INF) cout << -1;
    else cout << ans;
    
}