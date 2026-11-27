#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> path(n+1, vector<int>(n+1, INF));
    for(int i = 1; i <= n; i++) path[i][i] = 0;
    
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >>b;
        path[a][b] = 0;
    }
    
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        bool ok = 1;
        for (int j = 1; j <= n; j++){
            if (path[i][j] == INF && path[j][i] == INF) ok = 0;
        }
        ans += ok;
    }
    
    cout << ans;
}